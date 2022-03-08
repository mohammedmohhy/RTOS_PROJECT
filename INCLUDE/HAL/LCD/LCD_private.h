/*
 * file name: LCD_private.h
 *
 * description: this file contains the macros that other drivers can't change its values
 *
 *  Created on: Jan 4, 2022
 *      Author: Mohy
 */
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_EIGHT_BIT					8
#define LCD_FOUR_BIT					4

#define LCD_1LINE						1
#define LCD_2LINES						2

#define LCD_DISPLAY_NUMBER_CONSTANT 			0x30

#define LCD_CMD_DISPLAY_ON				0b00001100
#define LCD_CMD_DISPLAY_OFF				0b00001000
#define LCD_CMD_FUNCTION_SET			0b00111000
#define LCD_CMD_DISPLAY_CLEAR			0b00000001
#define LCD_CMD_ENTRY_MODE				0b00000110
#define LCD_CMD_DISPLAY_SHIFT			0b00000111
#define LCD_CMD_RETURN_HOME				0b00000010
#define LCD_CMD_CURSOR_SHIFT 			0b00010100
#define LCD_ROW1_ADDRESS				0b10000000
#define LCD_ROW2_ADDRESS				0b11000000
#define LCD_CGRAM_CONSTANT				0b01000000



void HLCD_voidSendCmd(u8 copy_u8Cmd);

#endif /* INCLUDE_HAL_LCD_PRIVATE_H_ */
