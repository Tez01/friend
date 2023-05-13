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

// Function template
void a(void){
/*	Input		:	(nothing)
 * 	Output		:
 * 	Description	:
 *
 */

}

/******************************************************************************
* Includes
*******************************************************************************/
#include "stm32f411xe.h"

#include "d_uart.h"
/******************************************************************************
* Macros
*******************************************************************************/


/******************************************************************************
* Type definitions (enums, structs, typedefs)
*******************************************************************************/

/******************************************************************************
* Global Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
void a_init(void);
/******************************************************************************
* Function Definitions
*******************************************************************************/
int  main(void){
	// Initialize everything in the application
	a_init();

	// Create a task for communication with pc

	// create a task for processing the commands

	// create a task to display current running command on LCD

	// Start the scheduler

	uint32_t count = 49;
	while(1){
		// Code should never come here with FreeRTOS
		USART2->DR = count;
		for(int i = 0; i < 3000; i++){
			;
		}

	}

}


void a_init(void){
/*	Input		:	(nothing)
* 	Output		:	All peripherals initialized
* 	Description	:
*		Initializes the application variables and all peripherals used
*/

	d_uart_init(USART2);


}






/*************** END OF FUNCTIONS ***************************************************************************/
