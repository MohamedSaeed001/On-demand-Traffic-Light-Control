/*
 ============================================================================
 Name        : button.c
 Author      : Mohamed Saeed
 Created on  : Sep 5, 2022
 Description : Source File For Button
 ============================================================================
 */

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "button.h"

/*******************************************************************************
 *                      Implementation Functions                               *
 *******************************************************************************/

void buttonInit(void)
{
	GPIO_setPinDirection(BUTTON_PORT, BUTTON_PIN, PIN_INPUT);
	GPIO_writePin(BUTTON_PORT, BUTTON_PIN, logic_high);
}

Button_State_t buttonIsPressed(void)
{
	if(!(BIT_IS_SET(BUTTON_PORT, BUTTON_PIN)))
	{
		return Button_Pressed;
	}
	else
	{
		return Button_Unpressed;
	}
}
