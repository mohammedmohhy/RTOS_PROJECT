/*
 * DC_MOTOR_private.h
 *
 *  Created on: Jan 10, 2022
 *      Author: Mohy
 */

#ifndef GBI_PRIVATE_H
#define GBI_PRIVATE_H

#define S_REG		*(	(volatile u8*)0x5F	)
#define MCUCR_REG	*(	(volatile u8*)0x55	)
#define GICR_REG	*(	(volatile u8*)0x5B	)
#define GIFR_REG	*(	(volatile u8*)0x5A	)
#define MCUCSR_REG	*(	(volatile u8*)0x54	)

#define GBI_u8_I_BIT		7

#endif /* INCLUDE_HAL_DC_MOTOR_PRIVATE_H_ */
