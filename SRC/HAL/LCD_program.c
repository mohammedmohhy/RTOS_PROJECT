/*
 * LCD_program.c
 *
 *  Created on: Jan 4, 2022
 *      Author: Mohy
 */
#include "../../INCLUDE/MCAL/DIO/DIO_interface.h"
#include "../../INCLUDE/MCAL/DIO/DIO_private.h"
#include "../../INCLUDE/MCAL/DIO/DIO_configuratios.h"

#include "../../INCLUDE/HAL/LCD/LCD_interface.h"
#include "../../INCLUDE/HAL/LCD/LCD_private.h"
#include "../../INCLUDE/HAL/LCD/LCD_configuration.h"

#include "../../INCLUDE/LIB/bit_math.h"

#include <util/delay.h>



/************************************************************************************
* Service Name: HLCD_voidSendCmd
* Parameters (in): u8 command to LCD
* Return value: None
* Description: Function to send a command to the LCD
************************************************************************************/
void HLCD_voidSendCmd(u8 copy_u8Cmd)
{
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);

	MDIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Cmd);

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);
}

/************************************************************************************
* Service Name: HLCD_voidInit
* Parameters (in): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the LCD module.
************************************************************************************/
void HLCD_voidInit(void)
{
	_delay_ms(30);
	HLCD_voidSendCmd(LCD_CMD_FUNCTION_SET);

	_delay_ms(1);
	HLCD_voidSendCmd(LCD_CMD_DISPLAY_ON);

	_delay_ms(1);
	HLCD_voidSendCmd(LCD_CMD_DISPLAY_CLEAR);

	_delay_ms(1);
	HLCD_voidSendCmd(LCD_CMD_ENTRY_MODE);
}

/************************************************************************************
* Service Name: HLCD_SendCharacter
* Parameters (in): u8character to display
* Parameters (out): None
* Return value: None
* Description: Function to display the a character
************************************************************************************/
void HLCD_voidSendCharacter(u8 copy_u8char)
{
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);

	MDIO_voidSetPortValue(LCD_DATA_PORT,copy_u8char);

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);
}


/************************************************************************************
* Service Name: HLCD_SendSpecialCharacter
* Parameters (in): u8 arr_of_pattern , u8 CGRAM_segment , u8 row_NO , u8 col_NO
* Return value: None
* Description: Function to display a special character
************************************************************************************/
void LCD_voidSendSpecialCharacter (u8 *copy_pu8CharArr, u8 copy_u8PatternNum,
								   u8 copy_u8LineNum,   u8 copy_ColNum)
{
	u8 local_u8CGRAMAddress, local_u8Counter;
	/* Calculate CGRAM Address = Pattern Number * 8 */
	local_u8CGRAMAddress = copy_u8PatternNum * 8;
	SET_BIT(local_u8CGRAMAddress,6);
	/* Send Command to set CGRAM Address */
	//Private_voidSendInstruction(local_u8CGRAMAddress);
	HLCD_voidSendCmd(local_u8CGRAMAddress);

	for (local_u8Counter=0; local_u8Counter < 8; local_u8Counter++)
	{
		/* Send byte from character array */
		//HLCD_voidSendData(copy_pu8CharArr[local_u8Counter]);
		HLCD_voidSendCharacter(copy_pu8CharArr[local_u8Counter]);
	}

	/* Send Command to set DDRAM Address */
	HLCD_voidGoToPos(copy_u8LineNum,copy_ColNum);
	/* Display pattern from CGRAM */
	//HLCD_voidSendData(copy_u8PatternNum);
	HLCD_voidSendCharacter(copy_u8PatternNum);
}


/************************************************************************************
* Service Name: HLCD_voidSendNumber
* Parameters (in): s32 number_to_display
* Return value: None
* Description: Function to display a a number
************************************************************************************/
void HLCD_voidSendNumber(s32 copy_u32Num)
{
	u8 i=0,length=0, inverted_arr[10];
	/*check if the number is negative to print the negative sign and make it positive*/
	if(copy_u32Num<0)
	{
		HLCD_voidSendCharacter('-');
		copy_u32Num*=-1;
	}

	do
	{
		inverted_arr[length]=copy_u32Num%10;
		//copy_u32Num/=10;
		length++;
	}
	while((copy_u32Num/=10)!=0);

	//sending copy_u32Num to the diplay_char_function element by element but invert
	 //*it again as it has been inverted once
	for(i=1; i<=length ; i++)
	{
		HLCD_voidSendCharacter((inverted_arr[length-i]+LCD_DISPLAY_NUMBER_CONSTANT));
	}
}


/************************************************************************************
* Service Name: HLCD_voidGoToPos
* Parameters (in): u8 ro_NO , u8 col_NO
* Return value: None
* Description: Function to move the cursor
************************************************************************************/
void HLCD_voidGoToPos(u8 copy_u8RowNum, u8 copy_u8ColNum)
{
	if((copy_u8ColNum>=0)&& (copy_u8ColNum<16))
	{
		switch(copy_u8RowNum)
		{
		case 0:HLCD_voidSendCmd(copy_u8ColNum+LCD_ROW1_ADDRESS);break;
		case 1:HLCD_voidSendCmd(copy_u8ColNum+LCD_ROW2_ADDRESS);break;
		}
	}
	else
	{

	}
}

/************************************************************************************
* Service Name: HLCD_voidClearDisplay
* Parameters (in): None
* Return value: None
* Description: Function to clear the display
************************************************************************************/
void HLCD_voidClearDisplay(void)
{
	HLCD_voidSendCmd(LCD_CMD_DISPLAY_CLEAR);
}


/************************************************************************************
* Service Name: HLCD_voidSendString
* Parameters (in):u8 string
* Return value: None
* Description: Function to print a string
************************************************************************************/
void HLCD_voidSendString(u8 *copy_ptru8String)
{
	u8 i=0;

	while(copy_ptru8String[i]!='\0')
	{
		HLCD_voidSendCharacter(copy_ptru8String[i]);
		i++;
	}
}
