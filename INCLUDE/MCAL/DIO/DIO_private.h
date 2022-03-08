/*
 * DIO_private.h
 *
 *  Created on: Jan 3, 2022
 *      Author: Mohy
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/****************************************************************************
 * these defines are for registers used in writing a value on an output port
 **************************************************************************** */
#define DIO_u8_PORTA_REG	*( (volatile u8*)0x3B )
#define DIO_u8_PORTB_REG 	*( (volatile u8*)0x38 )
#define DIO_u8_PORTC_REG 	*( (volatile u8*)0x35 )
#define DIO_u8_PORTD_REG 	*( (volatile u8*)0x32 )
/****************************************************************************
 * these defines are for registers used to define a direction for a port
 **************************************************************************** */
#define DIO_u8_DDRA_REG 	*( (volatile u8*)0x3A )
#define DIO_u8_DDRB_REG 	*( (volatile u8*)0x37 )
#define DIO_u8_DDRC_REG 	*( (volatile u8*)0x34 )
#define DIO_u8_DDRD_REG 	*( (volatile u8*)0x31 )
/****************************************************************************
 * these defines are for registers used in reading a value from an output port
 **************************************************************************** */
#define DIO_u8_PINA_REG		*( (volatile u8*)0x39 )
#define DIO_u8_PINB_REG		*( (volatile u8*)0x36 )
#define DIO_u8_PINC_REG		*( (volatile u8*)0x33 )
#define DIO_u8_PIND_REG		*( (volatile u8*)0x30 )

/**/
#define DIO_u8_INITIAL_OUTPUT 		1
#define DIO_u8_INITIAL_INPUT 		0

#define DIO_u8_OUTPUT_HIGH 			1
#define DIO_u8_OUTPUT_LOW 			0

#define DIO_u8_INPUT_PULUP 			1
#define DIO_u8_INPUT_FLOATING 		0

#endif /* INCLUDE_MCAL_DIO_DIO_PRIVATE_H_ */
