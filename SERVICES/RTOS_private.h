/*
 * RTOS_private.h
 *
 *  Created on: Feb 6, 2022
 *      Author: Mohy
 */

#ifndef SERVICES_RTOS_PRIVATE_H_
#define SERVICES_RTOS_PRIVATE_H_


/*task structure, (task control block)*/
typedef struct RTOS_Task
{
	u16 First_delay;
	u16 Periodicity;
	void (*P2F)(void);

}RTOS_TCB;



#endif /* SERVICES_RTOS_PRIVATE_H_ */
