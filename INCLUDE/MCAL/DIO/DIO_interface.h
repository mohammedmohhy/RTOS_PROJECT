/*
 * DIO_interface.h
 *
 *  Created on: Jan 3, 2022
 *      Author: Mohy
 */
#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#include "../../LIB/std_types.h"

/****************************************************************************
 * these MACROS are for the available ports in avr_MC
 **************************************************************************** */
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/****************************************************************************
 * this ENUM is for number of pins per every ports in avr_MC
 **************************************************************************** */
enum DIO_enum_pins
{
	DIO_u8_PIN0=0,
	DIO_u8_PIN1,
	DIO_u8_PIN2,
	DIO_u8_PIN3,
	DIO_u8_PIN4,
	DIO_u8_PIN5,
	DIO_u8_PIN6,
	DIO_u8_PIN7
};
/****************************************************************************
 * this used to write logic high or low
 **************************************************************************** */
#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0
/****************************************************************************
 * this used to define the direction
 **************************************************************************** */
#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT 0

/*************************************************************************
 * this naming is stands for
 * M:  MCAL layer
 * DIO_ : in DIO driver
 * void : return type of the function
 * Init : what functions do
 *******************************************************************************/
/******************************************************************************
 * Function: MDIO_voidInit
 * I/P parms: takes nothing
 * return: None
 * DESC: this function initializes the DIO_module
 * *******************************************************************************/
void MDIO_voidInit(void);


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
void MDIO_voidSetPinDirection(u8 copy_u8PortID,u8 copy_u8PinID, u8 copy_u8Direction);

/******************************************************************************
 * Function: MDIO_voidSetPinValue
 * I/P parms: u8 port number , u8 pin number , u8 value
 * return: None
 * DESC: this function set the desired pin value to high or low
 * *******************************************************************************/
void MDIO_voidSetPinValue(u8 copy_u8PortID,u8 copy_u8PinID, u8 copy_u8Value);

/******************************************************************************
 * Function: MDIO_voidSetPinValue
 * I/P parms: u8 port number , u8 direction
 * return: None
 * DESC: this function set the desired port direction to output or input
 * *******************************************************************************/
void MDIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_u8Direction);

/******************************************************************************
 * Function: MDIO_voidSetPinValue
 * I/P parms: u8 port number , u8 value
 * return: None
 * DESC: this function set the desired port value to high or low
 * *******************************************************************************/
void MDIO_voidSetPortValue(u8 copy_u8PortID, u8 copy_u8Value);

/******************************************************************************
 * Function: MDIO_voidSetPinValue
 * I/P parms: u8 port number , u8 pin number
 * return: None
 * DESC: this function reads the desired pin value (high or low)
 * *******************************************************************************/
u8 MDIO_u8GetPinValue(u8 copy_u8PortID,u8 copy_u8PinID);



#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
