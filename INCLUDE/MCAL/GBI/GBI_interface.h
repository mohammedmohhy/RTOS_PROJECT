/*
 * DC_MOTOR_interface.h
 *
 *  Created on: Jan 10, 2022
 *      Author: Mohy
 */

#ifndef GBI_INTERFACE_H
#define GBI_INTERFACE_H

/*this include to make the interrupts ISR available for all modules include the Global interrupt*/
#include "../../LIB/interrupt_vector_table.h"

/******************************************************************************
 * Function: GBI_voidEnable
 * I/P parms: None
 * return: None
 * DESC: this function enables the global interrupt
 * *******************************************************************************/
void GBI_voidEnable(void);

/******************************************************************************
 * Function: GBI_voidDisable
 * I/P parms: None
 * return: None
 * DESC: this function disables the global interrupt
 * *******************************************************************************/
void GBI_voidDisable(void);

#endif /* INCLUDE_HAL_DC_MOTOR_INTERFACE_H_ */
