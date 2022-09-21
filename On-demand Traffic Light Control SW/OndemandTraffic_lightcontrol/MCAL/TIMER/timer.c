/*
 ============================================================================
 Name        : timer.c
 Author      : Mohamed Saeed
 Description : Source File For ATmega32 Timer Module
 ============================================================================
 */

/*******************************************************************************
 *                                  Includes								   *
 *******************************************************************************/

#include "timer.h"
#include "timer_reg.h"
#include <avr/io.h>
#include "../../utils/common_macros.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function For Timers*/
static volatile void (*g_Ptr_To_Fun_Timer0)(void) = NULL_PTR;
static volatile void (*g_Ptr_To_Fun_Timer1)(void) = NULL_PTR;
static volatile void (*g_Ptr_To_Fun_Timer2)(void) = NULL_PTR;

uint8_t volatile LED_Flag = FALSE;
uint8_t volatile ledCount;
uint8_t volatile ledPedstrianFlag = FALSE;
uint8_t volatile ledPedstrianCount;

/*******************************************************************************
 *                      		 Timers ISR                           		   *
 *******************************************************************************/

/* ISR For Timer0 Normal Mode (Overflow) */
ISR(TIMER0_OVF_vect)
{
	if(LED_Flag == TRUE)
	{
		ledCount++;
		if(ledCount == 20)
		{
			LED_Flag = FALSE;
			ledCount=0;
		}
	}

	if(g_Ptr_To_Fun_Timer0 != NULL_PTR)
	{
		/* Call the Call Back function in the application after Timer0 Overflow Occurs*/
		(*g_Ptr_To_Fun_Timer0)(); /* call the function of Timer0 ISR using pointer to function g_callBackPtr0(); */
	}
}

/* ISR For Timer0 Compare Match Mode */
ISR(TIMER0_COMP_vect)
{
	if(g_Ptr_To_Fun_Timer0 != NULL_PTR)
	{

		(*g_Ptr_To_Fun_Timer0)();
	}
}

/* ISR For Timer1 Normal (Overflow) Mode */
ISR(TIMER1_OVF_vect)
{
	if(g_Ptr_To_Fun_Timer1 != NULL_PTR)
	{
		(*g_Ptr_To_Fun_Timer1)();
	}
}

/* ISR For Timer1 Compare Match Mode Channel A*/
ISR(TIMER1_COMPA_vect)
{
	if(g_Ptr_To_Fun_Timer1 != NULL_PTR)
	{

		(*g_Ptr_To_Fun_Timer1)();
	}
}

/* ISR For Timer1 Compare Match Mode Channel B*/
ISR(TIMER1_COMPB_vect)
{
	if(g_Ptr_To_Fun_Timer1 != NULL_PTR)
	{

		(*g_Ptr_To_Fun_Timer1)();
	}
}

/* ISR For Timer2 Normal Mode (Overflow) */
ISR(TIMER2_OVF_vect)
{
	if(ledPedstrianCount == TRUE)
	{
		ledPedstrianCount++;
		if(ledPedstrianCount == 20)
		{
			ledPedstrianFlag = FALSE;
			ledPedstrianCount = 0;
		}
	}
	if(g_Ptr_To_Fun_Timer2 != NULL_PTR)
	{
		(*g_Ptr_To_Fun_Timer2)();
	}
}

/* ISR For Timer1 Compare Match Mode */
ISR(TIMER2_COMP_vect)
{
	if(g_Ptr_To_Fun_Timer2 != NULL_PTR)
	{
		(*g_Ptr_To_Fun_Timer2)();
	}
}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void Timer_init(void)
{
#if TIMER0_Enable == ENABLE
	#if	(TIMER0_Mode_Selector == TIMER0_Mode_Pwm_PhaseCorrect_msk)  || (TIMER0_Mode_Selector == TIMER0_Mode_FastPwm_msk)
#if (TIMER0_Mode_Selector == TIMER0_Mode_Pwm_PhaseCorrect_msk )
	TCCR0 = (TCCR0 & TIMER0_Mode_Clr_msk);
	SET_BIT(TCCR0,WGM00);
#elif (TIMER0_Mode_Selector == TIMER0_Mode_FastPwm_msk )
	TCCR0 = (TCCR0 & TIMER0_Mode_Clr_msk);
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#endif


#if TIMER0_OC0_Behavior_Selector == TIMER0_OC0_NON_INVERTING_msk
	SET_BIT(DDRB,PB3);
	TCCR0 =(TCCR0 & TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM01);
#elif TIMER0_OC0_Behavior_Selector == TIMER0_OC0_INVERTING_msk
	SET_BIT(DDRB,PB3);
	TCCR0 =(TCCR0 & TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif
#endif

#if TIMER0_Mode_Selector == TIMER0_Mode_Ovf_msk || TIMER0_Mode_Selector == TIMER0_Mode_Ctc_msk
	SET_BIT(TCCR0,FOC0);
	TCCR0= (TCCR0 & TIMER0_Mode_Clr_msk);


#if TIMER0_Mode_Selector == TIMER0_Mode_Ctc_msk
	TCCR0 = (TCCR0 & TIMER0_Mode_Clr_msk);
	SET_BIT(TCCR0,WGM01);
#endif

#if TIMER0_OC0_Behavior_Selector == TIMER0_OC0_TOGGLE_msk
	SET_BIT(DDRB,PB3);
	TCCR0 =(TCCR0 & TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM00);
#elif TIMER0_OC0_Behavior_Selector == TIMER0_OC0_CLR_msk
	SET_BIT(DDRB,PB3);
	TCCR0 =(TCCR0 & TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM01);
#elif TIMER0_OC0_Behavior_Selector == TIMER0_OC0_SET_msk
	SET_BIT(DDRB,PB3);
	TCCR0 =(TCCR0 & TIMER0_OC0_clr_msk);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif
#endif

	switch(TIMER0_PreScaler_Selector)
	{
	case TIMER0_Clk_With_No_PreScaler_msk:
		TCCR0= (TCCR0 & TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS00);
		break;
	case TIMER0_Clk_With_8_PreScaler_msk:
		TCCR0= (TCCR0 & TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS01);
		break;
	case TIMER0_Clk_With_64_PreScaler_msk:
		TCCR0= (TCCR0 & TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		break;
	case TIMER0_Clk_With_256_PreScaler_msk:
		TCCR0= (TCCR0 & TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER0_Clk_With_1024_PreScaler_msk:
		TCCR0= (TCCR0 & TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER0_External_Clk_With_Falling_Edge_msk:
		TCCR0= (TCCR0 & TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER0_External_Clk_With_Rising_Edge_msk:
		TCCR0= (TCCR0 & TIMER0_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	}



	TCNT0 = TIMER0_Initial_Value;

	OCR0 = TIMER0_Compare_Value;
#endif


#if TIMER2_Enable == ENABLE
#if (TIMER2_Mode_Selector == TIMER2_Mode_Pwm_PhaseCorrect_msk)  || (TIMER2_Mode_Selector == TIMER2_Mode_FastPwm_msk)
#if (TIMER2_Mode_Selector == TIMER2_Mode_Pwm_PhaseCorrect_msk)
	TCCR2= (TCCR2 & TIMER2_Mode_Clr_msk);
	SET_BIT(TCCR2,WGM20);
#elif	(TIMER2_Mode_Selector == TIMER2_Mode_FastPwm_msk )
	TCCR2= (TCCR2 & TIMER2_Mode_Clr_msk);
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
#endif


#if TIMER2_OC2_Behavior_Selector == TIMER2_OC2_NON_INVERTING_msk
	TCCR2 = (TCCR2 & TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM21);
#elif TIMER2_OC2_Behavior_Selector == TIMER2_OC2_INVERTING_msk
	TCCR2 = (TCCR2 & TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
#endif
#endif

#if TIMER2_Mode_Selector == TIMER2_Mode_Ovf_msk
	SET_BIT(TCCR2,FOC2);
	TCCR2= (TCCR2 & TIMER2_Mode_Clr_msk);

#elif TIMER2_Mode_Selector == TIMER2_Mode_Ctc_msk
	SET_BIT(TCCR2,FOC2);
	TCCR2= (TCCR2 & TIMER2_Mode_Clr_msk);
	SET_BIT(TCCR2,WGM21);
#endif

#if TIMER2_OC2_Behavior_Selector == TIMER2_OC2_TOGGLE_msk
	TCCR2 = (TCCR2 & TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM20);
#elif TIMER2_OC2_Behavior_Selector == TIMER2_OC2_CLR_msk
	TCCR2 = (TCCR2 & TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM21);
#elif TIMER2_OC2_Behavior_Selector == TIMER2_OC2_SET_msk
	TCCR2 = (TCCR2 & TIMER2_OC2_clr_msk);
	SET_BIT(DDRD,PD7);
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
#endif


	switch(TIMER2_PreScaler_Selector){
	case TIMER2_Clk_With_No_PreScaler_msk:
		TCCR2=(TCCR2 & TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,CS20);
		break;
	case TIMER2_Clk_With_8_PreScaler_msk:
		TCCR2=(TCCR2 & TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,CS21);
		break;
	case TIMER2_Clk_With_32_PreScaler_msk:
		TCCR2=(TCCR2 & TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		break;
	case TIMER2_Clk_With_64_PreScaler_msk:
		TCCR2=(TCCR2 & TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,CS22);
		break;
	case TIMER2_Clk_With_128_PreScaler_msk:
		TCCR2=(TCCR2 & TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS22);
		break;
	case TIMER2_Clk_With_256_PreScaler_msk:
		TCCR2=(TCCR2 & TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
	case TIMER2_Clk_With_1024_PreScaler_msk:
		TCCR2=(TCCR2 & TIMER2_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
	}



	TCNT2 = TIMER2_Initial_Value;


	OCR2 = TIMER2_Compare_Value;
#endif



#if TIMER1_Enable == ENABLE

	switch(TIMER1_Mode_Selector){
	case TIMER1_Mode_Ovf_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
	case TIMER1_Mode_Pwm_PhaseCorrect_8_bit_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM10);
		break;
	case TIMER1_Mode_Pwm_PhaseCorrect_9_bit_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM11);
		break;
	case TIMER1_Mode_Pwm_PhaseCorrect_10_bit_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		break;
	case TIMER1_Mode_Ctc_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1B,WGM12);
		break;
	case TIMER1_Mode_FastPwm_8_bit_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1B,WGM12);
		break;
	case TIMER1_Mode_FastPwm_9_bit_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		break;
	case TIMER1_Mode_FastPwm_10_bit_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		break;
	case TIMER1_Mode_Pwm_Phase_Frequency_Correct_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1B,WGM13);
		break;
	case TIMER1_Mode_Pwm_Phase_Correct_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM13);
		break;
	case TIMER1_Mode_Fast_Pwm_msk:
		TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}


#if TIMER1_Mode_Selector == TIMER1_Mode_Ctc_msk || TIMER1_Mode_Selector == TIMER1_Mode_Ovf_msk
	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1A,FOC1B);
	TCCR1A = (TCCR1A & TIMER1_Mode_Clr_msk);

#if TIMER1_OC1A_Select == ENABLE
	SET_BIT(DDRD,PD5);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_TOGGLE_msk
	SET_BIT(TCCR1A,COM1A0);

#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_CLR_msk
	SET_BIT(TCCR1A,COM1A1);

#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SET_msk
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#endif
#endif

#if TIMER1_OC1B_Select == ENABLE
	SET_BIT(DDRD,PD4);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_TOGGLE_msk
	SET_BIT(TCCR1A,COM1B0);
#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_CLR_msk
	SET_BIT(TCCR1A,COM1B1);

#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SET_msk
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
#endif

#endif
#endif

#if (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_PhaseCorrect_8_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_PhaseCorrect_9_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_PhaseCorrect_10_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_Phase_Frequency_Correct_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Pwm_Phase_Correct_msk)

#if TIMER1_OC1A_Select == ENABLE
	SET_BIT(DDRD,PD5);

#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_NON_INVERTING_msk
	SET_BIT(TCCR1A,COM1A1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_INVERTING_msk
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SPECIAL_TOGGLE_Phase_Correct_msk
	SET_BIT(TCCR1A,COM1A0);
#endif
#endif


#if TIMER1_OC1B_Select == ENABLE
	SET_BIT(DDRD,PD4);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_NON_INVERTING_msk
	SET_BIT(TCCR1A,COM1B1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_INVERTING_msk
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SPECIAL_TOGGLE_Phase_Correct_msk
	SET_BIT(TCCR1A,COM1B0);
#endif
#endif

#endif




#if (TIMER1_Mode_Selector == TIMER1_Mode_FastPwm_8_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_FastPwm_9_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_FastPwm_10_bit_msk) || (TIMER1_Mode_Selector == TIMER1_Mode_Fast_Pwm_msk)

#if TIMER1_OC1A_Select == ENABLE
	SET_BIT(DDRD,PD5);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_NON_INVERTING_msk
	SET_BIT(TCCR1A,COM1A1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_INVERTING_msk
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SPECIAL_TOGGLE_FastPWM_msk
	SET_BIT(TCCR1A,COM1A0);
#endif

#endif




#if TIMER1_OC1B_Select == ENABLE
	SET_BIT(DDRD,PD4);
#if TIMER1_OC1_Behavior_Selector == TIMER1_OC1_NON_INVERTING_msk
	SET_BIT(TCCR1A,COM1B1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_INVERTING_msk
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);


#elif TIMER1_OC1_Behavior_Selector == TIMER1_OC1_SPECIAL_TOGGLE_FastPWM_msk
	SET_BIT(TCCR1A,COM1B0);
#endif

#endif
#endif



	switch(TIMER1_PreScaler_Selector)
	{
	case TIMER1_Clk_With_No_PreScaler_msk:
		TCCR1B = (TCCR1B & TIMER1_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR1B,CS10);
		break;
	case TIMER1_Clk_With_8_PreScaler_msk:
		TCCR1B = (TCCR1B & TIMER1_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR1B,CS11);
		break;
	case TIMER1_Clk_With_64_PreScaler_msk:
		TCCR1B = (TCCR1B & TIMER1_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		break;
	case TIMER1_Clk_With_256_PreScaler_msk:
		TCCR1B = (TCCR1B & TIMER1_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR1B,CS12);
		break;
	case TIMER1_Clk_With_1024_PreScaler_msk:
		TCCR1B = (TCCR1B & TIMER1_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS12);
		break;
	case TIMER1_External_Clk_With_Falling_Edge_msk:
		TCCR1B = (TCCR1B & TIMER1_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
	case TIMER1_External_Clk_With_Rising_Edge_msk:
		TCCR1B = (TCCR1B & TIMER1_Clk_With_PreScaler_Clr_msk);
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
	}

	TCNT1 = TIMER1_Initial_Value;

	OCR1A = TIMER1_CompareA_Value;
	OCR1B = TIMER1_CompareB_Value;
#endif

	TIMER_EnableInterrupt();
}


void TIMER_EnableInterrupt(void)
{

#if TIMER0_Enable == ENABLE

#if TIMER0_OVF_INT_EN == ENABLE
	SET_BIT(TIMSK,TOIE0);
#elif TIMER0_COMP_INT_EN  == ENABLE
	SET_BIT(TIMSK,OCIE0);
#endif
#endif

#if  TIMER2_Enable == ENABLE

#if TIMER2_OVF_INT_EN == ENABLE
	SET_BIT(TIMSK,TOIE2);
#elif TIMER2_COMP_INT_EN  == ENABLE
	SET_BIT(TIMSK,OCIE2);
#endif
#endif

#if TIMER1_Enable == ENABLE

#if   TIMER1_OVF_INT_EN   ==  ENABLE
	SET_BIT(TIMSK,TOIE1);
#elif TIMER1_COMPA_INT_EN  == ENABLE
	SET_BIT(TIMSK,OCIE1A);
#elif TIMER1_COMPB_INT_EN  == ENABLE
	SET_BIT(TIMSK,OCIE1B);
#endif
#endif


}


/*
 * This function's is responsible to set the Call Back function address
 * Every set callback function follow specific Timer
 */
void Timer0_setCallBack(void(*ptr_To_Fun)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_Ptr_To_Fun_Timer0 = (volatile void *)ptr_To_Fun;
}

void Timer1_setCallBack(void(*ptr_To_Fun)(void))
{
	g_Ptr_To_Fun_Timer1 = (volatile void *)ptr_To_Fun;
}

void Timer2_setCallBack(void(*ptr_To_Fun)(void))
{
	g_Ptr_To_Fun_Timer2 = (volatile void *)ptr_To_Fun;
}


/*
 * Function to disableTimers
 */
void Timer_DeInit(void)
{
	/* TIMER0 */
		TCCR0 = 0;
		/* TIMER2 */
		TCCR2 = 0;

		/* TIMER1 */
		TCCR1A = 0;
		TCCR1B = 0;
}
