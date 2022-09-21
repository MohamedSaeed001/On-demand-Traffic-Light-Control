/*
 ============================================================================
 Name        : timer.h
 Author      : Mohamed Saeed
 Description : Header File For ATmega32 Timer Module
 ============================================================================
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

/*******************************************************************************
 *                                  Includes								   *
 *******************************************************************************/

#include "../../utils/std_types.h"

/*******************************************************************************
 *                        Definitions and Configuration                		   *
 *******************************************************************************/

#define TIMER0_Enable                            ENABLE
#define TIMER1_Enable                            ENABLE
#define TIMER2_Enable                            ENABLE

#define TIMER0_Mode_Selector              	     TIMER0_Mode_Ovf_msk
#define TIMER0_OC0_Behavior_Selector             TIMER0_OC0_INVERTING_msk
 #define TIMER0_PreScaler_Selector               TIMER0_Clk_With_1024_PreScaler_msk

#define TIMER0_OVF_INT_EN              			 ENABLE
#define TIMER0_COMP_INT_EN            		     DISABLE

#define TIMER0_Initial_Value                     0
#define TIMER0_Compare_Value                     0

#define TIMER2_Mode_Selector                     TIMER2_Mode_Ovf_msk
#define TIMER2_OC2_Behavior_Selector       		 TIMER2_OC2_NON_INVERTING_msk
#define TIMER2_PreScaler_Selector                TIMER2_Clk_With_1024_PreScaler_msk

#define TIMER2_OVF_INT_EN              			 ENABLE
#define TIMER2_COMP_INT_EN             			 DISABLE

#define TIMER2_Initial_Value                     0
#define TIMER2_Compare_Value                     0

#define TIMER1_Mode_Selector               		 TIMER1_Mode_Ovf_msk
#define TIMER1_OC1_Behavior_Selector        	 TIMER1_OC1_SET_msk
#define TIMER1_PreScaler_Selector                TIMER1_Clk_With_1024_PreScaler_msk
#define TIMER1_OC1A_Select                 		 ENABLE
#define TIMER1_OC1B_Select                 		 ENABLE

#define TIMER1_OVF_INT_EN              			 DISABLE
#define TIMER1_COMPA_INT_EN           			 ENABLE
#define TIMER1_COMPB_INT_EN            			 DISABLE

#define TIMER1_Initial_Value                     0
#define TIMER1_CompareA_Value                    0
#define TIMER1_CompareB_Value                    0
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void Timer_init(void);
void Timer_DeInit(void);
void Timer0_setCallBack(void(*ptr_To_Fun)(void));
void Timer1_setCallBack(void(*ptr_To_Fun)(void));
void Timer2_setCallBack(void(*ptr_To_Fun)(void));
void TIMER_EnableInterrupt(void);



#endif /* MCAL_TIMER_TIMER_H_ */
