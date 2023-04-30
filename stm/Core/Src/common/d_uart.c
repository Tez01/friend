/******************************************************************************
* Filename              :   d_uart.c
* Author                :   Tej Partap Singh
* Origin Date           :   Apr. 23, 2023
* Version               :   1.0.0
* Target                :   STM32F411RE
*
* Description:
*
*/

/******************************************************************************
* Includes
*******************************************************************************/
#include "stm32f411xe.h"

/******************************************************************************
* Macros
*******************************************************************************/
// Bit definitions
#define UE_CR1 			(1 << 13)
#define M_CR1 			(1 << 13)
#define	STOP_CR2		(0b11 << 12)
#define OVER8_CR1		(1 << 15)
//~91.1 for baudrate 115200 at peripheral freq 84 MHz
#define USARTDIV_BRR	0x38F	// Should be less than 16 bit
#define TE_CR1			(1 << 3)
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
 * 		All peripherals initialized
 * 	Description	:
 *		Initializes the input usart for full duplex communication
 */

	// Enable the USART by writing the UE bit in USART_CR1 register to 1.
	usart->CR1 |= UE_CR1;		//	1: USART enabled

	//	Program the M bit in USART_CR1 to define the word length.
	usart->CR1 &= ~(M_CR1);		//	0: 1 Start bit, 8 Data bits, n Stop bit

	//	Program the number of stop bits in USART_CR2.
	usart->CR2 &= ~(STOP_CR1);	//	00: 1 Stop bit

	// Select oversampling by programming OVER8 bit in CR1 register
	usart->CR1 |= OVER8_CR1;	//	1: oversampling by 8

	//	 Select the desired baud rate using the USART_BRR register.
	usart->BRR |= USARTDIV_BRR;

	//	Set the TE bit in USART_CR1 to send an idle frame as first transmission.
	usart->CR1 |= TE_CR1;
	//	When TE is set, there is a 1 bit-time delay before the transmission starts

}


/*************** END OF FUNCTIONS ***************************************************************************/
