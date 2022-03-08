/*
 * TIMER0_private.h
 *
 *  Created on: Jan 18, 2022
 *      Author: Mohy
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_

/*****************TIMER0 registers**********************************/
#define TIM0_u8_TCCR0_REG    	*( (volatile u8*)0x53 )
#define TIM0_u8_TCNT0_REG 		*( (volatile u8*)0x52 )
#define TIM0_u8_OCR0_REG 		*( (volatile u8*)0x5C )
#define TIM0_u8_TIMSK_REG 		*( (volatile u8*)0x59 )
#define TIM0_u8_TIFR_REG 		*( (volatile u8*)0x58 )
/************************************************************/

/*****************************operating modes***********************/
#define TIMER0_NORMAL_MODE			0
#define TIMER0_PWM_MODE				1
#define TIMER0_CTC_MODE				2
#define TIMER0_FAST_PWM_MODE		3
/*******************************************************************/


/******************************OC0 modes********************************/
#define NON_PWM_OC0_DISCONNECTED				0
#define NON_PWM_OC0_TOGGLE_ON_COMPARE			1
#define NON_PWM_OC0_CLEAR_ON_COMPARE			2
#define NON_PWM_OC0_SET_ON_COMPARE				3

#define PWM_OC0_DISCONNECTED				0
#define PWM_OC0_CLEAR_ON_COMPARE			2
#define PWM_OC0_SET_ON_COMPARE				3
/**************************************************************************/


/****************************prescaller**************************************/
#define TIMER0_PRESCALLER_STOP				0
#define TIMER0_PRESCALLER_1					1
#define TIMER0_PRESCALLER_8					2
#define TIMER0_PRESCALLER_64				3
#define TIMER0_PRESCALLER_256				4
#define TIMER0_PRESCALLER_1024				5
/*********************************************************************/


#define TIMER0_INTERRUPT_ENABLE		1
#define TIMER0_INTERRUPT_DISABLE	0

/********macros for bit numbers in the TCCR0 register*********/
#define TCCR0_WGM01					3
#define TCCR0_WGM00					6
#define TCCR0_FOC0					7
/**************************************************************/

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
