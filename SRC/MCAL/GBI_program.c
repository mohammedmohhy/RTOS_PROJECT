/*
 * EXTERNAL_INTERRUPTS_program.c
 *
 *  Created on: Jan 11, 2022
 *      Author: Mohy
 */
#include "../../INCLUDE/LIB/std_types.h"
#include "../../INCLUDE/LIB/bit_math.h"
#include "../../INCLUDE/MCAL/DIO/DIO_interface.h"
#include "../../INCLUDE/MCAL/DIO/DIO_private.h"
#include "../../INCLUDE/MCAL/DIO/DIO_configuratios.h"

#include "../../INCLUDE/MCAL/GBI/GBI_interface.h"
#include "../../INCLUDE/MCAL/GBI/GBI_private.h"

/******************************************************************************
 * Function: GBI_voidEnable
 * I/P parms: None
 * return: None
 * DESC: this function enables the global interrupt
 * *******************************************************************************/
void GBI_voidEnable(void)
{
	/*enable the global interrupt*/
	SET_BIT(S_REG,GBI_u8_I_BIT);
}


/******************************************************************************
 * Function: GBI_voidDisable
 * I/P parms: None
 * return: None
 * DESC: this function disables the global interrupt
 * *******************************************************************************/
void GBI_voidDisable(void)
{
	/*disable the global interrupt*/
	CLEAR_BIT(S_REG,GBI_u8_I_BIT);
}
