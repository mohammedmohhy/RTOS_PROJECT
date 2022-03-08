/*
 * TIMER0_interface.h
 *
 *  Created on: Jan 18, 2022
 *      Author: Mohy
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_


/******************************************************************************
 * Function: TIMER0_voidInit
 * I/P parms: takes Nothing
 * return: None
 * DESC: this function initialize timer0
 * *******************************************************************************/
void TIMER0_voidInit(void);


/******************************************************************************
 * Function: TIMER0_voidSetCallBack
 * I/P parms: takes the address of the callback function and the index of the pointer access
 * return: None
 * DESC: this function saves the callback function address in a pointer to be used in the ISR
 * *******************************************************************************/
void TIMER0_voidSetCallBack(void (*FuncAddress)(void),u8 func_mode);



/******************************************************************************
 * Function: TIMER0_voidLoadValue
 * I/P parms: takes the preload value
 * return: None
 * DESC: this function load the TCNT0_REG with the preload value
 * *******************************************************************************/
void TIMER0_voidLoadValue(u8 Value);


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
