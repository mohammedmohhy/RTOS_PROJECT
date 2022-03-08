/*
 * TIMER0_program.c
 *
 *  Created on: Jan 18, 2022
 *      Author: Mohy
 */
#include "../../INCLUDE/LIB/std_types.h"
#include "../../INCLUDE/LIB/bit_math.h"
#include "../../INCLUDE/MCAL/DIO/DIO_interface.h"

#include "../../INCLUDE/MCAL/TIMER0/TIMER0_interface.h"
#include "../../INCLUDE/MCAL/TIMER0/TIMER0_private.h"
#include "../../INCLUDE/MCAL/TIMER0/TIMER0_configuration.h"

/*my own vector table and ISRs library*/
#include "../../INCLUDE/LIB/interrupt_vector_table.h"


/******************************************************************************
 * Function: TIMER0_voidInit
 * I/P parms: takes Nothing
 * return: None
 * DESC: this function initialize timer0
 * *******************************************************************************/
void TIMER0_voidInit(void)
{
	/*define the prescaler of the timer*/
	TIM0_u8_TCCR0_REG = (TIM0_u8_TCCR0_REG&0b11111000)|TIMER0_PRESCALLER_CONF;
	/*disable force output compare feature*/
	CLEAR_BIT(TIM0_u8_TCCR0_REG,TCCR0_FOC0);
	/*define the interrupt enable/disable modes*/
	TIM0_u8_TIMSK_REG = (TIM0_u8_TIMSK_REG&0b11111100) | (OVF_INTERRUPT_MODE)|(COMPARE_MATCH_INTERRUPT_MODE<<1);

#if TIMER0_MODE == TIMER0_NORMAL_MODE
	/*operate in NORMAL mode*/
	CLEAR_BIT(TIM0_u8_TCCR0_REG,TCCR0_WGM00);
	CLEAR_BIT(TIM0_u8_TCCR0_REG,TCCR0_WGM01);
	/*define the OC0 pin mode*/
	TIM0_u8_TCCR0_REG = (TIM0_u8_TCCR0_REG&0b11001111)|NON_PWM_OC0_MODE;

#elif TIMER0_MODE == TIMER0_CTC_MODE
	/*operate in CTC mode*/
	SET_BIT(TIM0_u8_TCCR0_REG,TCCR0_WGM01);
	CLEAR_BIT(TIM0_u8_TCCR0_REG,TCCR0_WGM00);
	/*define the OC0 mode*/
	TIM0_u8_TCCR0_REG = (TIM0_u8_TCCR0_REG&0b11001111)|NON_PWM_OC0_MODE;
	/*define the compare value*/
	TIM0_u8_OCR0_REG = TIMER0_OUTPUT_COMPARE_VALUE;



#elif TIMER0_MODE == TIMER0_PWM_MODE
	/*operate in CTC mode*/
	SET_BIT(TIM0_u8_TCCR0_REG,TCCR0_WGM00);
	CLEAR_BIT(TIM0_u8_TCCR0_REG,TCCR0_WGM01);
	/*define the OC0 mode*/
	TIM0_u8_TCCR0_REG = (TIM0_u8_TCCR0_REG&0b11001111)|PWM_OC0_MODE;
	/*define the compare value*/
	TIM0_u8_OCR0_REG = TIMER0_OUTPUT_COMPARE_VALUE;



#elif 	TIMER0_MODE == TIMER0_FAST_PWM_MODE
	/*operate in CTC mode*/
	SET_BIT(TIM0_u8_TCCR0_REG,TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG,TCCR0_WGM01);
	/*define the OC0 mode*/
	TIM0_u8_TCCR0_REG = (TIM0_u8_TCCR0_REG&0b11001111)|PWM_OC0_MODE;
	/*define the compare value*/
	TIM0_u8_OCR0_REG = TIMER0_OUTPUT_COMPARE_VALUE;



#endif
}


/******************************************************************************
 * Function: TIMER0_voidLoadValue
 * I/P parms: takes the preload value
 * return: None
 * DESC: this function load the TCNT0_REG with the preload value
 * *******************************************************************************/
void TIMER0_voidLoadValue(u8 Value)
{
	TIM0_u8_TCNT0_REG = Value;

}

/*assuming ptr2func[0] is for OVF, ptr2func[1] is for COMPARE MATCH*/
void (*ptr2func[2])(void)={NULL,NULL};


/******************************************************************************
 * Function: TIMER0_voidSetCallBack
 * I/P parms: takes the address of the callback function and the index of the pointer access
 * return: None
 * DESC: this function saves the callback function address in a pointer to be used in the ISR
 * *******************************************************************************/
void TIMER0_voidSetCallBack(void (*FuncAddress)(void),u8 func_mode)
{
	ptr2func[func_mode]=FuncAddress;

}

/*TIMER0 compare match ISR*/
TIMER0_COMP_ISR()
{
	static local_counter=0;
	local_counter++;
	/*the function will be called every 1ms*/
	if(local_counter==5)
	{
		ptr2func[1]();
		local_counter=0;
	}

}

/*TIMER0 over flow ISR*/
TIMER0_OVF_ISR()
{
	ptr2func[0]();
}

