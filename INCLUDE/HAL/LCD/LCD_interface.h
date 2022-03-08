/*
 * LCD_interface.h
 *
 *  Created on: Jan 4, 2022
 *      Author: Mohy
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_




/************************************************************************************
* Service Name: HLCD_voidSendCmd
* Parameters (in): u8 command to LCD
* Return value: None
* Description: Function to send a command to the LCD
************************************************************************************/
void HLCD_voidSendCmd(u8 copy_u8Cmd);

/************************************************************************************
* Service Name: HLCD_voidInit
* Parameters (in): Nones
* Return value: None
* Description: Function to Initialize the LCD module.
************************************************************************************/
void HLCD_voidInit(void);

/************************************************************************************
* Service Name: HLCD_SendCharacter
* Parameters (in): u8character to display
* Return value: None
* Description: Function to display the a character
************************************************************************************/
void HLCD_voidSendCharacter(u8 copy_u8char);


/************************************************************************************
* Service Name: HLCD_SendSpecialCharacter
* Parameters (in): u8 arr_of_pattern , u8 CGRAM_segment , u8 row_NO , u8 col_NO
* Return value: None
* Description: Function to display a special character
************************************************************************************/
void LCD_voidSendSpecialCharacter (u8 *copy_pu8CharArr, u8 copy_u8PatternNum,
								   u8 copy_u8LineNum,   u8 copy_ColNum);


/************************************************************************************
* Service Name: HLCD_voidSendNumber
* Parameters (in): s32 number_to_display
* Return value: None
* Description: Function to display a a number
************************************************************************************/
void HLCD_voidSendNumber(s32 copy_u32Num);

/************************************************************************************
* Service Name: HLCD_voidGoToPos
* Parameters (in): u8 ro_NO , u8 col_NO
* Return value: None
* Description: Function to move the cursor
************************************************************************************/
void HLCD_voidGoToPos(u8 copy_u8RowNum, u8 copy_u8ColNum);

/************************************************************************************
* Service Name: HLCD_voidClearDisplay
* Parameters (in): None
* Return value: None
* Description: Function to clear the display
************************************************************************************/
void HLCD_voidClearDisplay(void);


/************************************************************************************
* Service Name: HLCD_voidSendString
* Parameters (in):u8 string
* Return value: None
* Description: Function to print a string
************************************************************************************/
void HLCD_voidSendString(u8 *copy_ptru8String);


#endif /* INCLUDE_HAL_LCD_INTERFACE_H_ */
