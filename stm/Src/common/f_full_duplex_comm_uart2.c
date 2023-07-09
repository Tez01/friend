/*******************************************************************************
* Filename              :   f_uart.c
* Author                :   Tej
* Origin Date           :   23-06-24
* Version               :   1.0.0
*
* Description:
* 	This file contains definition of functions for full duplex communication over
* 	UART2
* 	Works on top of d_uart
*	Note:
*		1.	This file is specific for communication over UART2.
*			The vision is to do communication with PC over USB connection
*			with the PC and it is assumed that for most STM32 boards
*			the USB is connected to PC via UART2. So designing the file
*			for UART2 for now. If there is a need to have communication over
*			other UART, will modify this file to make it generic.
*
*		2.	In this file, full_duplex_comm_uart2  = comm
*
*/

/******************************************************************************
* Includes
*******************************************************************************/
#include "d_uart.h"
/******************************************************************************
* Macros
*******************************************************************************/

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
void f_comm_init(void){
//=============================================================================
//	Input		:	(nothing)
//	Output		:	Initialize uart hardware
//	Description	:
//		Initialize the uart hardware
//		Initialize global variables in this file
//=============================================================================
	//Initialize uart2 hardware
	d_uart_init(USART2);


}


