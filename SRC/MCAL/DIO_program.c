/*
 * DIO_program.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Mohy
 */
#include "../../INCLUDE/LIB/std_types.h"
#include "../../INCLUDE/LIB/bit_math.h"
#include "../../INCLUDE/MCAL/DIO/DIO_interface.h"
#include "../../INCLUDE/MCAL/DIO/DIO_private.h"
#include "../../INCLUDE/MCAL/DIO/DIO_configuratios.h"


/******************************************************************************
 * Function: MDIO_voidInit
 * I/P parms: takes nothing
 * return: None
 * DESC: this function initializes the DIO_module
 * *******************************************************************************/
void MDIO_voidInit(void)
{
	DIO_u8_DDRA_REG = CAT_BITS(	DIO_u8_PA7_INITIAL_DIRECTION,
							DIO_u8_PA6_INITIAL_DIRECTION,
							DIO_u8_PA5_INITIAL_DIRECTION,
							DIO_u8_PA4_INITIAL_DIRECTION,
							DIO_u8_PA3_INITIAL_DIRECTION,
							DIO_u8_PA2_INITIAL_DIRECTION,
							DIO_u8_PA1_INITIAL_DIRECTION,
							DIO_u8_PA0_INITIAL_DIRECTION);

	DIO_u8_DDRB_REG = CAT_BITS(	DIO_u8_PB7_INITIAL_DIRECTION,
							DIO_u8_PB6_INITIAL_DIRECTION,
							DIO_u8_PB5_INITIAL_DIRECTION,
							DIO_u8_PB4_INITIAL_DIRECTION,
							DIO_u8_PB3_INITIAL_DIRECTION,
							DIO_u8_PB2_INITIAL_DIRECTION,
							DIO_u8_PB1_INITIAL_DIRECTION,
							DIO_u8_PB0_INITIAL_DIRECTION);


	DIO_u8_DDRC_REG = CAT_BITS(	DIO_u8_PC7_INITIAL_DIRECTION,
							DIO_u8_PC6_INITIAL_DIRECTION,
							DIO_u8_PC5_INITIAL_DIRECTION,
							DIO_u8_PC4_INITIAL_DIRECTION,
							DIO_u8_PC3_INITIAL_DIRECTION,
							DIO_u8_PC2_INITIAL_DIRECTION,
							DIO_u8_PC1_INITIAL_DIRECTION,
							DIO_u8_PC0_INITIAL_DIRECTION);

	DIO_u8_DDRD_REG = CAT_BITS(	DIO_u8_PD7_INITIAL_DIRECTION,
							DIO_u8_PD6_INITIAL_DIRECTION,
							DIO_u8_PD5_INITIAL_DIRECTION,
							DIO_u8_PD4_INITIAL_DIRECTION,
							DIO_u8_PD3_INITIAL_DIRECTION,
							DIO_u8_PD2_INITIAL_DIRECTION,
							DIO_u8_PD1_INITIAL_DIRECTION,
							DIO_u8_PD0_INITIAL_DIRECTION);

	DIO_u8_PORTA_REG = CAT_BITS(	DIO_u8_PA7_INITIAL_VALUE,
							DIO_u8_PA6_INITIAL_VALUE,
							DIO_u8_PA5_INITIAL_VALUE,
							DIO_u8_PA4_INITIAL_VALUE,
							DIO_u8_PA3_INITIAL_VALUE,
							DIO_u8_PA2_INITIAL_VALUE,
							DIO_u8_PA1_INITIAL_VALUE,
							DIO_u8_PA0_INITIAL_VALUE);

	DIO_u8_PORTB_REG = CAT_BITS(	DIO_u8_PB7_INITIAL_VALUE,
							DIO_u8_PB6_INITIAL_VALUE,
							DIO_u8_PB5_INITIAL_VALUE,
							DIO_u8_PB4_INITIAL_VALUE,
							DIO_u8_PB3_INITIAL_VALUE,
							DIO_u8_PB2_INITIAL_VALUE,
							DIO_u8_PB1_INITIAL_VALUE,
							DIO_u8_PB0_INITIAL_VALUE);

	DIO_u8_PORTC_REG = CAT_BITS(	DIO_u8_PC7_INITIAL_VALUE,
							DIO_u8_PC6_INITIAL_VALUE,
							DIO_u8_PC5_INITIAL_VALUE,
							DIO_u8_PC4_INITIAL_VALUE,
							DIO_u8_PC3_INITIAL_VALUE,
							DIO_u8_PC2_INITIAL_VALUE,
							DIO_u8_PC1_INITIAL_VALUE,
							DIO_u8_PC0_INITIAL_VALUE);

	DIO_u8_PORTD_REG = CAT_BITS(	DIO_u8_PD7_INITIAL_VALUE,
							DIO_u8_PD6_INITIAL_VALUE,
							DIO_u8_PD5_INITIAL_VALUE,
							DIO_u8_PD4_INITIAL_VALUE,
							DIO_u8_PD3_INITIAL_VALUE,
							DIO_u8_PD2_INITIAL_VALUE,
							DIO_u8_PD1_INITIAL_VALUE,
							DIO_u8_PD0_INITIAL_VALUE);

}


/******************************************************************************
 * Function: MDIO_voidSetPinDirection
 * return: return nothing
 * DESC: this function set a pin direction in boolean expresion
 *******************************************************************************
 I/P parameters options:
	  1- copy_u8PortID:DIO_u8_PORTA, DIO_u8_PORTB , DIO_u8_PORTC, DIO_u8_PORTD
	  2- copy_u8PinID: 	DIO_u8_PIN0,
						DIO_u8_PIN1,
						DIO_u8_PIN2,
						DIO_u8_PIN3,
						DIO_u8_PIN4,
						DIO_u8_PIN5,
						DIO_u8_PIN6,
						DIO_u8_PIN7
	 3- copy_u8Direction: DIO_u8_OUTPUT, DIO_u8_INPUT
 * *******************************************************************************/
void MDIO_voidSetPinDirection(u8 copy_u8PortID,u8 copy_u8PinID, u8 copy_u8Direction)
{
	if( (copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA) ||
			(copy_u8PinID > DIO_u8_PIN7) || (copy_u8PinID < DIO_u8_PIN0)	  )
	{

	}
	else
	{
		if(copy_u8Direction==DIO_u8_OUTPUT)
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA: SET_BIT(DIO_u8_DDRA_REG,copy_u8PinID); break;
				case DIO_u8_PORTB: SET_BIT(DIO_u8_DDRB_REG,copy_u8PinID); break;
				case DIO_u8_PORTC: SET_BIT(DIO_u8_DDRC_REG,copy_u8PinID); break;
				case DIO_u8_PORTD: SET_BIT(DIO_u8_DDRD_REG,copy_u8PinID); break;
			}
		}
		else if(copy_u8Direction==DIO_u8_INPUT)
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA: CLEAR_BIT(DIO_u8_DDRA_REG,copy_u8PinID); break;
				case DIO_u8_PORTB: CLEAR_BIT(DIO_u8_DDRB_REG,copy_u8PinID); break;
				case DIO_u8_PORTC: CLEAR_BIT(DIO_u8_DDRC_REG,copy_u8PinID); break;
				case DIO_u8_PORTD: CLEAR_BIT(DIO_u8_DDRD_REG,copy_u8PinID); break;
			}
		}
	}

}


/******************************************************************************
 * Function: MDIO_voidSetPinValue
 * I/P parms: u8 port number , u8 pin number , u8 value
 * return: None
 * DESC: this function set the desired pin value to high or low
 * *******************************************************************************/
void MDIO_voidSetPinValue(u8 copy_u8PortID,u8 copy_u8PinID, u8 copy_u8Value)
{
	if( (copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA) ||
			(copy_u8PinID > DIO_u8_PIN7) || (copy_u8PinID < DIO_u8_PIN0)	  )
	{

	}
	else
	{
		if(copy_u8Value==DIO_u8_HIGH)
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA: SET_BIT(DIO_u8_PORTA_REG,copy_u8PinID); break;
				case DIO_u8_PORTB: SET_BIT(DIO_u8_PORTB_REG,copy_u8PinID); break;
				case DIO_u8_PORTC: SET_BIT(DIO_u8_PORTC_REG,copy_u8PinID); break;
				case DIO_u8_PORTD: SET_BIT(DIO_u8_PORTD_REG,copy_u8PinID); break;
			}
		}
		else if(copy_u8Value==DIO_u8_LOW)
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA: CLEAR_BIT(DIO_u8_PORTA_REG,copy_u8PinID); break;
				case DIO_u8_PORTB: CLEAR_BIT(DIO_u8_PORTB_REG,copy_u8PinID); break;
				case DIO_u8_PORTC: CLEAR_BIT(DIO_u8_PORTC_REG,copy_u8PinID); break;
				case DIO_u8_PORTD: CLEAR_BIT(DIO_u8_PORTD_REG,copy_u8PinID); break;
			}
		}
	}

}


/******************************************************************************
 * Function: MDIO_voidSetPinValue
 * I/P parms: u8 port number , u8 direction
 * return: None
 * DESC: this function set the desired port direction to output or input
 * *******************************************************************************/
void MDIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_u8Direction)
{
	if( (copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA) )
	{

	}
	else
	{
		if(copy_u8Direction==DIO_u8_OUTPUT)
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA: DIO_u8_PORTA_REG |= 0xFF ; break;
				case DIO_u8_PORTB: DIO_u8_PORTB_REG |= 0xFF ; break;
				case DIO_u8_PORTC: DIO_u8_PORTC_REG |= 0xFF ; break;
				case DIO_u8_PORTD: DIO_u8_PORTD_REG |= 0xFF ; break;
			}
		}
		else if(copy_u8Direction==DIO_u8_INPUT)
		{
			switch (copy_u8PortID)
			{
			case DIO_u8_PORTA: DIO_u8_PORTA_REG &= 0x00 ; break;
			case DIO_u8_PORTB: DIO_u8_PORTB_REG &= 0x00 ; break;
			case DIO_u8_PORTC: DIO_u8_PORTC_REG &= 0x00 ; break;
			case DIO_u8_PORTD: DIO_u8_PORTD_REG &= 0x00 ; break;
			}
		}
	}

}

/******************************************************************************
 * Function: MDIO_voidSetPinValue
 * I/P parms: u8 port number , u8 value
 * return: None
 * DESC: this function set the desired port value to high or low
 * *******************************************************************************/
void MDIO_voidSetPortValue(u8 copy_u8PortID, u8 copy_u8Value)
{
	if( (copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA) )
	{

	}
	else
	{

		switch (copy_u8PortID)
		{
			case DIO_u8_PORTA: DIO_u8_PORTA_REG = copy_u8Value ; break;
			case DIO_u8_PORTB: DIO_u8_PORTB_REG = copy_u8Value ; break;
			case DIO_u8_PORTC: DIO_u8_PORTC_REG = copy_u8Value ; break;
			case DIO_u8_PORTD: DIO_u8_PORTD_REG = copy_u8Value ; break;
		}



	}

}

/******************************************************************************
 * Function: MDIO_voidSetPinValue
 * I/P parms: u8 port number , u8 pin number
 * return: None
 * DESC: this function reads the desired pin value (high or low)
 * *******************************************************************************/
u8 MDIO_u8GetPinValue(u8 copy_u8PortID,u8 copy_u8PinID)
{
	u8 result=5;

	if( (copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA)||
			(copy_u8PinID > DIO_u8_PIN7) || (copy_u8PinID < DIO_u8_PIN0)	  )
	{

	}
	else
	{
		switch (copy_u8PortID)
		{
			case DIO_u8_PORTA: result = GET_BIT(DIO_u8_PINA_REG,copy_u8PinID); break;
			case DIO_u8_PORTB: result = GET_BIT(DIO_u8_PINB_REG,copy_u8PinID); break;
			case DIO_u8_PORTC: result = GET_BIT(DIO_u8_PINC_REG,copy_u8PinID); break;
			case DIO_u8_PORTD: result = GET_BIT(DIO_u8_PIND_REG,copy_u8PinID); break;
		}
	}
	return result;
}
