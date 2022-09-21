/*
 ============================================================================
 Name        : external_interrupt.h
 Author      : Mohamed Saeed
 Description : Header File For ATmega32 External Interrupts
 ============================================================================
 */
#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL__INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL__INTERRUPT_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include <avr/io.h>
#include "../GPIO/gpio.h"
#include "../../utils/std_types.h"

/*******************************************************************************
 *                      Definitions and Configuration 				           *
 *******************************************************************************/

#define EX_INT0         			 ENABLE
#define EX_INT1        				 DISABLE
#define EX_INT2         			 DISABLE

#define INT0_Sense_Selector        	 INT0_Sense_Falling_Edge_Mask
#define INT1_Sense_Selector          INT1_Sense_Rising_Edge_Mask
#define INT2_Sense_Selector          INT2_Sense_Falling_Edge_Mask
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void EXT_INT_Init(void);
void Ex_INT0_SetCallBack(void (*ptr_To_function)(void));
void Ex_INT1_SetCallBack(void (*ptr_To_function)(void));
void Ex_INT2_SetCallBack(void (*ptr_To_function)(void));

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL__INTERRUPT_H_ */
