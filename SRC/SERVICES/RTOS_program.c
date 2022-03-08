/*
 * RTOS_program.c
 *
 *  Created on: Feb 6, 2022
 *      Author: Mohy
 */
#include "../../INCLUDE/LIB/std_types.h"
#include "../../INCLUDE/LIB/bit_math.h"
#include "../../SERVICES/RTOS_private.h"
#include "../../SERVICES/RTOS_configuration.h"
#include "../../SERVICES/RTOS_interface.h"
#include "../../INCLUDE/MCAL/TIMER0/TIMER0_interface.h"

/*each element in this array represents a task*/
RTOS_TCB RTOS_ArrOfStructs_Tasks[RTOS_u8_NUMBER_OF_TASKS];

/******************************************************************************
 * Function: RTOS_voidInit
 * I/P parms: None
 * return: None
 * DESC: this function initializes the RTOS
 * *******************************************************************************/
void RTOS_voidInit(void)
{
	/*initialize all the pointers to NULL*/
	for(u8 local_counter=0;local_counter<RTOS_u8_NUMBER_OF_TASKS;local_counter++)
	{
		RTOS_ArrOfStructs_Tasks[local_counter].P2F = NULL;
	}

	/*set call back function when CTC happens*/
	TIMER0_voidSetCallBack(&RTOS_voidScheduler,1);
	/*initialize timer0*/
	TIMER0_voidInit();
}

/******************************************************************************
 * Function: RTOS_voidScheduler
 * I/P parms: None
 * return: None
 * DESC: this function represents the scheduler
 * *******************************************************************************/
void RTOS_voidScheduler(void)
{
	/*this used to loop on each task, the first task has the highest priority, the last one has the lowest priority*/
	for(u8 local_counter=0;local_counter<RTOS_u8_NUMBER_OF_TASKS;local_counter++)
	{
		/*if the tasts are not created, its pointer will be pointing to NULL, so skip this iteration if its not initialized*/
		if(RTOS_ArrOfStructs_Tasks[local_counter].P2F==NULL)
		{
			continue;
		}
		/*check if the task is ready to be run*/
		if(RTOS_ArrOfStructs_Tasks[local_counter].First_delay==0)
		{
			/*call its function*/
			RTOS_ArrOfStructs_Tasks[local_counter].P2F();
			/*load its first delay with its periodicity to know when will it be ready again*/
			RTOS_ArrOfStructs_Tasks[local_counter].First_delay = (RTOS_ArrOfStructs_Tasks[local_counter].Periodicity)-1;
		}
		else
		{
			/*if the task is not ready decrement its first delay*/
			RTOS_ArrOfStructs_Tasks[local_counter].First_delay--;
		}
	}
}

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
void RTOS_voidCreateTask(u8 copy_u8Priority, u16 copy_u16Periodicity, u16 copy_u16FirstDelay, void(*pf)(void) )
{
	/*check if passes priority is not in the range of the number of tasks reserved*/
	/*the priority represents where to save these parameters*/
	if(copy_u8Priority<RTOS_u8_NUMBER_OF_TASKS && pf!=NULL)
	{
		/*load the structure for that task with all the passed args*/
		RTOS_ArrOfStructs_Tasks[copy_u8Priority].Periodicity = copy_u16Periodicity;
		RTOS_ArrOfStructs_Tasks[copy_u8Priority].First_delay = copy_u16FirstDelay;
		RTOS_ArrOfStructs_Tasks[copy_u8Priority].P2F = pf;
	}
}
