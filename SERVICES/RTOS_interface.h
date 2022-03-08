/*
 * RTOS_interface.h
 *
 *  Created on: Feb 6, 2022
 *      Author: Mohy
 */

#ifndef SERVICES_RTOS_INTERFACE_H_
#define SERVICES_RTOS_INTERFACE_H_


/******************************************************************************
 * Function: RTOS_voidInit
 * I/P parms: None
 * return: None
 * DESC: this function initializes the RTOS
 * *******************************************************************************/
void RTOS_voidInit(void);


/******************************************************************************
 * Function: RTOS_voidScheduler
 * I/P parms: None
 * return: None
 * DESC: this function represents the scheduler
 * *******************************************************************************/
void RTOS_voidScheduler(void);


/*****************************************************************************************************************************
 * Function: RTOS_voidCreateTask
 *
 * I/P parms: 	copy_u8Priority:represents the priority of the task.
 * 				copy_u16Periodicity: represents the periodicity of the task, in another words how often does the task should be executed.
 * 				copy_u16FirstDelay: represents the first delay for the task.
 * 				void(*pf)(void): represents the task_funtion_address.
 *
 * return: None
 * DESC: this function creates a new task, transform it from dormant to the ready or waiting.
 * ***************************************************************************************************************************/
void RTOS_voidCreateTask(u8 copy_u8Priority, u16 copy_u16Periodicity, u16 copy_u16FirstDelay, void(*pf)(void) );


#endif /* SERVICES_RTOS_INTERFACE_H_ */
