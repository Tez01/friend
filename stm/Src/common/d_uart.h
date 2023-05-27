/******************************************************************************
* Filename              :   d_uart.h
* Author                :   Tej Partap Singh
* Origin Date           :   Apr. 23, 2023
* Version               :   1.0.0
* Target                :   STM32F411RE
*
* Description:
*	Contains prototypes of exposed functions and definitions of d_uart.c
*/
#ifndef COMMON_D_UART_H_
#define COMMON_D_UART_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include "stm32f411xe.h"

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Exposed Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void d_uart_init(USART_TypeDef *usart);	// Initialize usart driver for full duplex communication

void USART1_GPIO_Init(void);	//	Sets the gpio pins connected to USART1 for USART operation
void USART1_GPIO_TX_Init(void);
void USART1_GPIO_RX_Init(void);

void USART2_GPIO_Init(void);	//	Sets the gpio pins connected to USART2 for USART operation
void USART2_GPIO_TX_Init(void);
void USART2_GPIO_RX_Init(void);
#endif /* COMMON_D_UART_H_ */
