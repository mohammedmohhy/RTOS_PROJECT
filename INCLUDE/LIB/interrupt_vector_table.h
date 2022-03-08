/*
 * interrupt_vector_table.h
 *
 *  Created on: Jan 13, 2022
 *      Author: Mohy
 */

#ifndef INTERRUPT_VECTOR_TABLE_H_
#define INTERRUPT_VECTOR_TABLE_H_

/*external interrupt0 on PD2*/
void __vector_1(void) __attribute__((signal));
#define INT0_ISR() 						void __vector_1(void)

void __vector_2(void) __attribute__((signal));
#define INT1_ISR()  					void __vector_2(void)

void __vector_3(void) __attribute__((signal));
#define INT2_ISR() 					void __vector_3(void)

void __vector_4(void) __attribute__((signal));
#define TIMER2_COMP_ISR() 			void __vector_4(void)

void __vector_5(void) __attribute__((signal));
#define TIMER2_OVF_ISR() 			void __vector_5(void)

void __vector_6(void) __attribute__((signal));
#define TIMER1_CAPT_ISR() 			void __vector_6(void)

void __vector_7(void) __attribute__((signal));
#define TIMER1_COMPA_ISR() 			void __vector_7(void)

void __vector_8(void) __attribute__((signal));
#define TIMER1_COMPB_ISR() 			void __vector_8(void)

void __vector_9(void) __attribute__((signal));
#define TIMER1_OVF_ISR() 			void __vector_9(void)

void __vector_10(void) __attribute__((signal));
#define TIMER0_COMP_ISR() 			void __vector_10(void)

void __vector_11(void) __attribute__((signal));
#define TIMER0_OVF_ISR() 			void __vector_11(void)

void __vector_12(void) __attribute__((signal));
#define SPI_ISR() 						void __vector_12(void)

void __vector_13(void) __attribute__((signal));
#define USART_RXC_ISR() 			void __vector_13(void)

void __vector_14(void) __attribute__((signal));
#define USART_UDRE_ISR() 			void __vector_14(void)

void __vector_15(void) __attribute__((signal));
#define USART_TXC_ISR() 			void __vector_15(void)

void __vector_16(void) __attribute__((signal));
#define ADC_ISR() 						void __vector_16(void)

void __vector_17(void) __attribute__((signal));
#define EE_RDY_ISR() 					void __vector_17(void)

void __vector_18(void) __attribute__((signal));
#define ANA_COMP_ISR() 					void __vector_18(void)

void __vector_19(void) __attribute__((signal));
#define TWI_ISR() 						void __vector_19(void)

void __vector_20(void) __attribute__((signal));
#define SPM_RDY_ISR() 					void __vector_20(void)


#endif /* INCLUDE_LIB_INTERRUPT_VECTOR_TABLE_H_ */
