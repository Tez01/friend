/******************************************************************************
* Filename              :   d_uart.c
* Author                :   Tej Partap Singh
* Origin Date           :   Apr. 23, 2023
* Version               :   1.0.0
* Target                :   STM32F411RE
*
* Description:
* 	This file contains functions to setup usart driver for tx and rx communication
* 	The functions are specific to STM32F411RE board.
* 	Refer following sections in the reference manual for understanding the
* 	configuration:
* 	Reference Manual: https://www.st.com/resource/en/reference_manual/rm0383-stm32f411xce-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
* 		19.3.2	:	Configure transmitter of USART
* 		19.3.3	:	Configure receiver of USART
* 		19.6 	: 	USART registers description
* 		6.3.12	:	For enabling clock for USART1
* 		8.4 	:	GPIO registers description
*
* 	Refer following sections in the datasheet
* 	Datasheet:	https://www.st.com/resource/en/datasheet/stm32f411re.pdf
* 		5		:	Finding bus connected to USART
* 		Table 9	:	Alternate function mapping for USART
*		Figure 3:	STM32F411xC/xE block diagram
*
*/

/******************************************************************************
* Includes
*******************************************************************************/
#include "../../../Src/common/d_uart.h"

#include "stm32f411xe.h"
/******************************************************************************
* Macros
*******************************************************************************/
// Bit definitions
#define APB2ENR_USART1EN		(1<<4)
#define APB1ENR_USART2EN		(1<<17)
#define CR1_UE 			(1 << 13)
#define CR1_M 			(1 << 12)
#define	CR2_STOP		(0b11 << 12)
#define CR1_OVER8		(1 << 15)


#define BRR_USARTDIV	0x113	// Should be less than 16 bit, this is for default peripheral
								//	freq 16MHz and over8 = 1
								// Using formula (Fck / ((8 * (2 - OVER8)) * BAUDRATE)
								// DIV_FRAC = 8 * (2 - OVER8) * Fractional part of above result
#define CR1_TE			(1 << 3)


// GPIO for USART1
#define AHB1ENR_GPIOAEN			(1<<0)
#define MODER_MODER9_0			(1<<18)	// bit 0 (LSB) of MODER9
#define MODER_MODER9_1			(1<<19)	// bit 1 of MODER9
#define	AFRH_9_0				(1<<4)	// bit 0 of AFRH9
#define	AFRH_9_1				(1<<5)	// bit 1 of AFRH9
#define	AFRH_9_2				(1<<6)	// bit 2 of AFRH9
#define	AFRH_9_3				(1<<7)	// bit 3 of AFRH9

#define MODER_MODER10_0			(1<<20)	// bit 0 (LSB) of MODER10
#define MODER_MODER10_1			(1<<21)	// bit 1 of MODER10
#define	AFRH_10_0				(1<<8)	// bit 0 of AFRH10
#define	AFRH_10_1				(1<<9)	// bit 1 of AFRH10
#define	AFRH_10_2				(1<<10)	// bit 2 of AFRH10
#define	AFRH_10_3				(1<<11)	// bit 3 of AFRH10


// GPIO for USART2
#define AHB1ENR_GPIOAEN			(1<<0)
#define MODER_MODER2_0			(1<<4)	// bit 0 (LSB) of MODER2
#define MODER_MODER2_1			(1<<5)	// bit 1 of MODER2
#define	AFRL_2_0				(1<<8)	// bit 0 of AFRL2
#define	AFRL_2_1				(1<<9)	// bit 1 of AFRL2
#define	AFRL_2_2				(1<<10)	// bit 2 of AFRL2
#define	AFRL_2_3				(1<<11)	// bit 3 of AFRL2

#define MODER_MODER3_0			(1<<6)	// bit 0 (LSB) of MODER3
#define MODER_MODER3_1			(1<<7)	// bit 1 of MODER3
#define	AFRL_3_0				(1<<12)	// bit 0 of AFRL3
#define	AFRL_3_1				(1<<13)	// bit 1 of AFRL3
#define	AFRL_3_2				(1<<14)	// bit 2 of AFRL3
#define	AFRL_3_3				(1<<15)	// bit 3 of AFRL3

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Global Variables
*******************************************************************************/

/******************************************************************************
* Static  Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/




/******************************************************************************
* Function Definitions
*******************************************************************************/
void d_uart_init(USART_TypeDef *usart){
/*	Input
 * 		usart	:	pointer to the usart that need to be initialized
 * 	Output
 * 		usart initialized and gpio pins configured as required for usart operation
 * 	Description	:
 * 		Initialize usart driver for full duplex communication
 * 		Configures related gpios for usart communication
 *		Initializes usart parameters for full duplex communication
 */

	// GPIO configuration
	if(usart == USART1){

		// Configure GPIO
		USART1_GPIO_Init();
		// Enable clock access to USART1
		RCC->APB2ENR	|= APB2ENR_USART1EN;
	}

	// GPIO configuration
	if(usart == USART2){

		// Configure GPIO
		USART2_GPIO_Init();
		// Enable clock access to USART2
		RCC->APB1ENR	|= APB1ENR_USART2EN;
	}

	// TODO: Write gpio configurations for other usarts
//	if(usart == USART2){
//
//		USART2_GPIO_Init();
//	}
//
//	if(usart == USART3){
//		USART3_GPIO_Init();
//	}
//
//	if(usart == USART4){
//		USART4_GPIO_Init();
//	}
//
//	if(usart == USART5){
//		USART5_GPIO_Init();
//	}
//
//	if(usart == USART6){
//		USART6_GPIO_Init();
//	}

	// Enable the USART by writing the UE bit in USART_CR1 register to 1.
	usart->CR1 |= CR1_UE;		//	1: USART enabled

	//	Program the M bit in USART_CR1 to define the word length.
	usart->CR1 &= ~(CR1_M);		//	0: 1 Start bit, 8 Data bits, n Stop bit

	//	Program the number of stop bits in USART_CR2.
	usart->CR2 &= ~(CR2_STOP);	//	00: 1 Stop bit

	// Select oversampling by programming OVER8 bit in CR1 register
	usart->CR1 |= CR1_OVER8;	//	1: oversampling by 8

	//	 Select the desired baud rate using the USART_BRR register.
	usart->BRR |= BRR_USARTDIV;

	//	Set the TE bit in USART_CR1 to send an idle frame as first transmission.
	usart->CR1 |= CR1_TE;
	//	When TE is set, there is a 1 bit-time delay before the transmission starts

}

void USART1_GPIO_Init(void){
/*	Input		:	(nothing)
 * 	Output		:	Sets the gpio pins connected to USART1
 * 	Description	:	Sets the gpio pins connected to USART1 for USART operation
 * 					PA9 	-> 	USART1_TX
 * 					PA10	->	USART1_RX
 */

	USART1_GPIO_TX_Init();

	USART1_GPIO_RX_Init();



}


void USART1_GPIO_TX_Init(void){
/*	Input		:	(nothing)
 * 	Output		:	Initializes PA9 for USART TX operation
 * 	Description	:
 * 				-	Enable clock to GPIOA
 * 				-	Set PA9 mode as alternate function
 * 				-	Set alternate function type
 *
 */

	// Enable clock access to GPIOA
	RCC->AHB1ENR |= AHB1ENR_GPIOAEN;

	// Set PA9  as alternate function
	GPIOA->MODER &= ~MODER_MODER9_0;
	GPIOA->MODER |=	 MODER_MODER9_1;

	// Set alternate function type as AF07 = 0b0111 using AFRH register(See datasheet)
	(GPIOA->AFR)[1] |=	AFRH_9_0;
	(GPIOA->AFR)[1] |=	AFRH_9_1;
	(GPIOA->AFR)[1] |=	AFRH_9_2;
	(GPIOA->AFR)[1] &=	~AFRH_9_3;
}


void USART1_GPIO_RX_Init(void){
/*	Input		:	(nothing)
 * 	Output		:	Initializes PA10 for USART RX operation
 * 	Description	:
 * 				-	Enable clock to GPIOA
 * 				-	Set PA10 mode as alternate function
 * 				-	Set alternate function type
 *
 */

	// Enable clock access to GPIOA
	RCC->AHB1ENR |= AHB1ENR_GPIOAEN;

	//	Set PA10 mode as alternate function
	GPIOA->MODER &= ~MODER_MODER10_0;
	GPIOA->MODER |=	 MODER_MODER10_1;

	// Set alternate function type as AF07 = 0b0111 using AFRH register(See datasheet)
	(GPIOA->AFR)[1] |=	AFRH_10_0;
	(GPIOA->AFR)[1] |=	AFRH_10_1;
	(GPIOA->AFR)[1] |=	AFRH_10_2;
	(GPIOA->AFR)[1] &=	~AFRH_10_3;
}


void USART2_GPIO_Init(void){
/*	Input		:	(nothing)
 * 	Output		:	Sets the gpio pins connected to USART2
 * 	Description	:	Sets the gpio pins connected to USART2 for USART operation
 * 					PA2 	-> 	USART2_TX
 * 					PA3		->	USART2_RX
 */

	USART2_GPIO_TX_Init();

	USART2_GPIO_RX_Init();



}

void USART2_GPIO_TX_Init(void){
/*	Input		:	(nothing)
 * 	Output		:	Initializes PA2 for USART TX operation
 * 	Description	:
 * 				-	Enable clock to GPIOA
 * 				-	Set PA2 mode as alternate function
 * 				-	Set alternate function type
 *
 */

	// Enable clock access to GPIOA
	RCC->AHB1ENR |= AHB1ENR_GPIOAEN;

	// Set PA2  as alternate function
	GPIOA->MODER &= ~MODER_MODER2_0;
	GPIOA->MODER |=	 MODER_MODER2_1;

	// Set alternate function type as AF07 = 0b0111 using AFRH register(See datasheet)
	(GPIOA->AFR)[0] |=	AFRL_2_0;
	(GPIOA->AFR)[0] |=	AFRL_2_1;
	(GPIOA->AFR)[0] |=	AFRL_2_2;
	(GPIOA->AFR)[0] &=	~AFRL_2_3;
}


void USART2_GPIO_RX_Init(void){
/*	Input		:	(nothing)
 * 	Output		:	Initializes PA3 for USART RX operation
 * 	Description	:
 * 				-	Enable clock to GPIOA
 * 				-	Set PA3 mode as alternate function
 * 				-	Set alternate function type
 *
 */

	// Enable clock access to GPIOA
	RCC->AHB1ENR |= AHB1ENR_GPIOAEN;

	//	Set PA3 mode as alternate function
	GPIOA->MODER &= ~MODER_MODER3_0;
	GPIOA->MODER |=	 MODER_MODER3_1;

	// Set alternate function type as AF07 = 0b0111 using AFRH register(See datasheet)
	(GPIOA->AFR)[0] |=	AFRL_3_0;
	(GPIOA->AFR)[0] |=	AFRL_3_1;
	(GPIOA->AFR)[0] |=	AFRL_3_2;
	(GPIOA->AFR)[0] &=	~AFRL_3_3;
}


/*************** END OF FUNCTIONS ***************************************************************************/
