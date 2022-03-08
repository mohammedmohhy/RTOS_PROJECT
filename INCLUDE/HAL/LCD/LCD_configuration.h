/*
 * LCD_configuration.h
 *
 *  Created on: Jan 4, 2022
 *      Author: Mohy
 */

#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_



#define LCD_DATA_MODE 			LCD_EIGHT_BIT
#define LCD_NO_OF_LINES			LCD_2LINES


/*options: from DIO_u8_PORTA to DIO_u8_PORTD */
#define LCD_CONTROL_PORT 		DIO_u8_PORTC
#define LCD_DATA_PORT 			DIO_u8_PORTD
/*options: from DIO_u8_PIN0 to DIO_u8_PIN7 */
#define LCD_RS_PIN				DIO_u8_PIN2
#define LCD_RW_PIN				DIO_u8_PIN1
#define LCD_E_PIN				DIO_u8_PIN0



#endif /* INCLUDE_HAL_LCD_CONFIGURATION_H_ */
