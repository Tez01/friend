/*******************************************************************************
* Filename              :   main.c
* Author                :   Tej Partap Singh
* Origin Date           :   23.04.22 (yy.mm.dd)
* Version               :   1.0.0
* Target                :   STM32F411RE
*
* Description:
*	Slave device which perform following actions on separate threads using freeRTOS:
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
#include "stm32f411xe.h"
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

	while(1){
		// Code should never come here with FreeRTOS
	}

}


void a_init(void){
	/*	Input		:
	 * 	Output		:
	 * 	Desciption	:
	 * 		Initialize all peripherals and drivers
	 * 		used in the program.
	 */
}




/*************** END OF FUNCTIONS ***************************************************************************/
