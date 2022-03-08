/*
 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Mohy
 */
/*
 * this application is using self created RTOS using CTC mode of TIMER0, to organize some tasks
 * which are toggling LEDs on PA0,PA1, and PA2 every 1msec, 2msec, and 3msec respectively.
 * */


#define F_CPU 8000000UL
#include "../INCLUDE/MCAL/DIO/DIO_interface.h"
#include "../INCLUDE/HAL/LCD/LCD_interface.h"
#include "../INCLUDE/MCAL/GBI/GBI_interface.h"
#include "../SERVICES/RTOS_interface.h"

/*task to toggle LED on PA0 every 1sec*/
void LED1_task(void)
{
	static u8 LED_STATE1 = 0;
	LED_STATE1 ^= 1;
	MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,LED_STATE1);
}
/*task to toggle LED on PA1 every 2sec*/
void LED2_task(void)
{
	static u8 LED_STATE2 = 0;
	LED_STATE2 ^= 1;
	MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,LED_STATE2);
}
/*task to toggle LED on PA2 every 3sec*/
void LED3_task(void)
{
	static u8 LED_STATE3 = 0;
	LED_STATE3 ^= 1;
	MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,LED_STATE3);
}


void main(void)
{
	MDIO_voidInit();
	GBI_voidEnable();

	RTOS_voidInit();
	/*task for the LED*/
	RTOS_voidCreateTask(0,1000,0,LED1_task);
	/*task for the LED*/
	RTOS_voidCreateTask(1,2000,0,LED2_task);
	/*task for the LED*/
	RTOS_voidCreateTask(2,3000,0,LED3_task);

	while(1)
	{

	}

}



