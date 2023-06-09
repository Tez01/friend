/*******************************************************************************
* Filename              :   main.c
* Author                :   Tej Partap Singh
* Origin Date           :   23.04.22 (yy.mm.dd)
* Version               :   1.0.0
* Target                :   STM32F411RE
*
* Description:
*	Device which perform following actions on separate threads using freeRTOS:
*	-	Get commands from the host(PC).
*		-	Turn on all channels of RGB LED
*		-	Turn off all channels of RGB LED
*
*	-	Perform actions based on the command.
*	-	Display currently running command number on LCD.
*/

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdio.h>
#include "stm32f411xe.h"

#include "d_uart.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "portmacro.h"
#include "f_full_duplex_comm_uart2.h"
/******************************************************************************
* Macros
*******************************************************************************/
#define NVIC_PRIORITYGROUP_4         0x00000003U /*!< 4 bits for pre-emption priority
                                                      0 bits for subpriority */
#define  TICK_INT_PRIORITY            0U   /*!< tick interrupt priority */

#define HAL_TICK_FREQ_1KHZ      1U

// Segger
#define DWT_CTRL	(*(volatile uint32_t *)0xE0001000)


// Tx/ Rx queues
#define MAX_CHARS_RX_QUEUE	(UBaseType_t)1000  // Max characters than Rx queue can hold
/******************************************************************************
* Type definitions (enums, structs, typedefs)
*******************************************************************************/

/******************************************************************************
* Global Variables
*******************************************************************************/
QueueHandle_t rx_queue;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void a_init(void);	// Initializes the application variables and all peripherals used

void sys_clock_config(void); //	Configures the System clock and sets the peripheral clock prescalers
static void task1_handler(void *parameters);
/******************************************************************************
* Function Definitions
*******************************************************************************/
int  main(void){
	// Initialize everything in the application
	a_init();

	TaskHandle_t task1_handle;

	BaseType_t status;
	// Queue to handle receiving of data. Data is pushed into this
	// queue by Rx interrupt handler. As soon data is available in
	// this queue, the data processing task is notified which
	//	moves this task to active state.
	rx_queue = xQueueCreate(MAX_CHARS_RX_QUEUE, sizeof(char));
	configASSERT(rx_queue != NULL);

	// Queue to handle transmit of data. Data is pushed into this
	// queue by Data processing task task which triggers Tx interrupt.

	// create a task for processing data in the queue
	status = xTaskCreate(task1_handler,  "Task-1", 200, "Hello World fom task-1", 2, &task1_handle);
	configASSERT(status == pdPASS);


	// create tasks for processing different commands

	// Start the scheduler
	vTaskStartScheduler();


	while(1){

	}

}


void a_init(void){
//=============================================================================
//	Input		:	(nothing)
//	Output		:	All peripherals initialized
//	Description	:
//		Initializes the application variables and all peripherals used
//=============================================================================

	// Initialize all global variables in this file
	rx_queue = NULL;


	// Configures the System clock and set prescalers for peripheral clock
	sys_clock_config();

	//==============================
	// FreeRTOS related Setup
	//==============================
	// Set NVIC priority for freertos. This setting was recommended in Fastbit course
	NVIC_SetPriorityGrouping((uint32_t)NVIC_PRIORITYGROUP_4);
	// Configure the SysTick to have interrupt in 1ms time basis
	SysTick_Config(SystemCoreClock / (1000U / HAL_TICK_FREQ_1KHZ));


	// Initialize full duplex communication over uart2
	f_comm_init();

	//==============================
	// Segger Related Setup
	//==============================
	// Enable ARM DWT_CNT register for timestamps of Segger
	DWT_CTRL |= (1<<0);
	vInitPrioGroupValue();	// This is normally done by StartScheduler, but it
							//	is required by SEGGER_SYSVIEW_Start, so do it
							//	 here.

	//Start recording
	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();
}



void sys_clock_config(void){
//=============================================================================
//	Input		:	(nothing)
//	Output		:	STM32 Clock set
//	Description	:
//		Aim is to get a system clock of 100MHz.
//		Configures the System clock and sets the peripheral clock prescalers
//		Reference:
//		Intro to STM32F4 Register Based Programming || Clock Setup || LED Blinking || NO HAL
//		https://www.youtube.com/watch?v=GJ_LFAlOlSk&t=834s
//=============================================================================

	#define	PLL_N	100	//	(Matched with Cube MX clock configuration to get 100MHz System Clock)
	#define PLL_M	4	//	(Matched with Cube MX clock configuration to get 100MHz System Clock)
	// enable HSE and wait for it to become ready
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));


	// Set the POWER Enable Clock
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;

	// Set the Voltage Regulator to reset value
	PWR->CR |= PWR_CR_VOS_Msk; // Set to 11: Scale 1 mode <= 100 MHz

	// Configure the Flash Prefetch and The Latency related settings
	FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_5WS;

	//	Configure the prescalers for main clock and peripheral clocks
	//	(Matched with Cube MX clock configuration)
	// AHB PS
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

	// APB1 PS
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

	// APB2 PS
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;


	// Configure the PLL Prescalers and PLL source

		// I noticed that reset value for PLLCFGR has some bits set to 1
		// So First clear first 17 bits for PPLN,PLLM,PLLP
	RCC->PLLCFGR &= ~0x0001FFFF;
	RCC->PLLCFGR |= (PLL_M << 0) | (PLL_N << 6) | RCC_PLLCFGR_PLLSRC_HSE;
	// PLLP set to 2(See datasheet)
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP_Msk;

	// Enable PLL and wait for it to become ready
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));

	// Set the clock source and wait for it to be set
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);


	SystemCoreClockUpdate();

}

static void task1_handler(void *parameters){
	uint32_t count = 49;
	while(1)
	{
		// Code should never come here with FreeRTOS
		USART2->DR = count;


	}
}


/*************** END OF FUNCTIONS ***************************************************************************/
