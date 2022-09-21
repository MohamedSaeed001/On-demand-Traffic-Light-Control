/*
 ============================================================================
 Name        : external_interrupt.c
 Author      : Mohamed Saeed
 Description : Source File For ATmega32 External Interrupts
 ============================================================================
 */
/*******************************************************************************
 *                                  Includes								   *
 *******************************************************************************/

#include "../../utils/common_macros.h"
#include "external _interrupt.h"
#include "ex_interrupt_reg.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* Global variables to function save the address of the function For Interrupts */
static void(*g_Ptr_To_Fun_INT0)(void) = NULL_PTR;
static void(*g_Ptr_To_Fun_INT1)(void) = NULL_PTR;
static void(*g_Ptr_To_Fun_INT2)(void) = NULL_PTR;

uint8_t volatile ButtonFlag = FALSE;

/*******************************************************************************
 *                      		 INT0_ISR                           		   *
 *******************************************************************************/
ISR(INT0_vect)
{
	ButtonFlag = TRUE;
	if(g_Ptr_To_Fun_INT0 != NULL_PTR)
	{
		(*g_Ptr_To_Fun_INT0)();
	}
}

/*******************************************************************************
 *                      		 INT1_ISR                           		   *
 *******************************************************************************/
ISR(INT1_vect)
{
	if(g_Ptr_To_Fun_INT1 != NULL_PTR)
	{
		(*g_Ptr_To_Fun_INT1)();
	}
}

/*******************************************************************************
 *                      		 INT2_ISR                           		   *
 *******************************************************************************/
ISR(INT2_vect)
{
	if(g_Ptr_To_Fun_INT2 != NULL_PTR)
	{
			(*g_Ptr_To_Fun_INT2)();
	}
}

/*******************************************************************************
 *                      Implementation Functions                               *
 *******************************************************************************/

void EXT_INT_Init(void)
{
#if EX_INT0 == ENABLE
	SET_BIT(GICR,INT0);
	GPIO_setPinDirection(PORTD_ID, PIN2_ID,PIN_INPUT );
	GPIO_writePin(PORTD_ID, PIN2_ID, logic_high);
#if INT0_Sense_Selector == 	INT0_Sense_Low_Level_Mask
	MCUCR =(MCUCR & INT0_Sense_CLR_Mask);
	CLEAR_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);
#elif INT0_Sense_Selector == INT0_Sense_Any_Logical_change_Mask
	MCUCR =(MCUCR & INT0_Sense_CLR_Mask);
	SET_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);

#elif  INT0_Sense_Selector == INT0_Sense_Falling_Edge_Mask
	MCUCR =(MCUCR & INT0_Sense_CLR_Mask);
	SET_BIT(MCUCR,ISC11);
	CLEAR_BIT(MCUCR,ISC10);

#elif  INT0_Sense_Selector == INT0_Sense_Rising_Edge_Mask
	MCUCR =(MCUCR & INT0_Sense_CLR_Mask);
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#endif
#endif

#if EX_INT1 == ENABLE
	SET_BIT(GICR,INT1);
#if INT1_Sense_Selector == 	INT1_Sense_Low_Level_Mask
	MCUCR =(MCUCR & INT1_Sense_CLR_Mask);
#elif INT1_Sense_Selector == INT1_Sense_Any_Logical_change_Mask
	MCUCR =(MCUCR & INT1_Sense_CLR_Mask);
	MCUCR = (MCUCR | INT1_Sense_Any_Logical_change_Mask);

#elif  INT1_Sense_Selector == INT1_Sense_Falling_Edge_Mask
	MCUCR =(MCUCR & INT1_Sense_CLR_Mask);
	MCUCR = (MCUCR | INT1_Sense_Falling_Edge_Mask);

#elif  INT1_Sense_Selector == INT1_Sense_Rising_Edge_Mask
	MCUCR =(MCUCR & INT1_Sense_CLR_Mask);
	MCUCR =(MCUCR | INT1_Sense_Rising_Edge_Mask);
#endif
#endif

#if EX_INT2 == ENABLE
	SET_BIT(GICR,INT2);
#if INT2_Sense_Selector == INT2_Sense_Falling_Edge_Mask
	MCUCSR =(MCUCSR & INT2_Sense_CLR_Mask);

#elif INT2_Sense_Selector == INT2_Sense_Rising_Edge_Mask
	MCUCSR =(MCUCSR & INT2_Sense_CLR_Mask);
	MCUCSR =(MCUCSR | INT2_Sense_Rising_Edge_Mask);
#endif
#endif
}


void Ex_INT0_SetCallBack(void (*ptr_To_function)(void))
{
	g_Ptr_To_Fun_INT0 = (volatile void *)ptr_To_function;
}

void Ex_INT1_SetCallBack(void (*ptr_To_function)(void))
{
	g_Ptr_To_Fun_INT1 = (volatile void *)ptr_To_function;
}

void Ex_INT2_SetCallBack(void (*ptr_To_function)(void))
{
	g_Ptr_To_Fun_INT2 = (volatile void *)ptr_To_function;
}


