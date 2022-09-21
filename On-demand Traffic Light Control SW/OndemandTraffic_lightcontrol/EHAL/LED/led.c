/*
 ============================================================================
 Name        : led.c
 Author      : Mohamed Saeed
 Created on  : Sep 5, 2022
 Description : Source File For LEDS
 ============================================================================
 */

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "led.h"

/*******************************************************************************
 *                      Implementation Functions                               *
 *******************************************************************************/
EN_LED_STATE_t Led_ON(EN_LED_TYPE_t LED_TYPE)
{
	switch(LED_TYPE)
	{
	case RED_LED_CAR:
		GPIO_setPinDirection(PORTA_ID, PIN2_ID, PIN_OUTPUT);
		GPIO_writePin(PORTA_ID, PIN2_ID, logic_high);
		break;

	case RED_LED_PEDESTRIAN:
		GPIO_setPinDirection(PORTB_ID, PIN2_ID, PIN_OUTPUT);
		GPIO_writePin(PORTB_ID, PIN2_ID, logic_high);
		break;

	case YELLOW_LED_CAR:
		GPIO_setPinDirection(PORTA_ID, PIN1_ID, PIN_OUTPUT);
		GPIO_writePin(PORTA_ID, PIN1_ID, logic_high);
		break;

	case YELLOW_LED_PEDESTRIAN:
		GPIO_setPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
		GPIO_writePin(PORTB_ID, PIN1_ID, logic_high);
		break;

	case GREEN_LED_CAR:
		GPIO_setPinDirection(PORTA_ID, PIN0_ID, PIN_OUTPUT);
		GPIO_writePin(PORTA_ID, PIN0_ID, logic_high);
		break;

	case GREEN_LED_PEDESTRIAN:
		GPIO_setPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
		GPIO_writePin(PORTB_ID, PIN0_ID, logic_high);
		break;
	}
	return LED_ON;
}


EN_LED_STATE_t Led_OFF(EN_LED_TYPE_t LED_TYPE)
{
	switch(LED_TYPE)
		{
		case RED_LED_CAR:
			GPIO_setPinDirection(PORTA_ID, PIN2_ID, PIN_OUTPUT);
			GPIO_writePin(PORTA_ID, PIN2_ID, logic_low);
			break;

		case RED_LED_PEDESTRIAN:
			GPIO_setPinDirection(PORTB_ID, PIN2_ID, PIN_OUTPUT);
			GPIO_writePin(PORTB_ID, PIN2_ID, logic_low);
			break;

		case YELLOW_LED_CAR:
			GPIO_setPinDirection(PORTA_ID, PIN1_ID, PIN_OUTPUT);
			GPIO_writePin(PORTA_ID, PIN1_ID, logic_low);
			break;

		case YELLOW_LED_PEDESTRIAN:
			GPIO_setPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
			GPIO_writePin(PORTB_ID, PIN1_ID, logic_low);
			break;

		case GREEN_LED_CAR:
			GPIO_setPinDirection(PORTA_ID, PIN0_ID, PIN_OUTPUT);
			GPIO_writePin(PORTA_ID, PIN0_ID, logic_low);
			break;

		case GREEN_LED_PEDESTRIAN:
			GPIO_setPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
			GPIO_writePin(PORTB_ID, PIN0_ID, logic_low);
			break;
		}
		return LED_OFF;
}
