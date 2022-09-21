/*
 ============================================================================
 Name        : app.c
 Author      : Mohamed Saeed
 Created on  : Sep 5, 2022
 Description : Source File For Application
 ============================================================================
 */

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "app.h"


uint8_t volatile redLed = 0;
uint8_t volatile greenLed = 0;
uint8_t volatile Yellow_Before_Red = 0;
uint8_t volatile Yellow_Before_Green = 0;

extern uint8_t volatile LED_Flag;
extern uint8_t volatile ledCount;
extern uint8_t volatile ledPedstrianFlag;
extern uint8_t volatile ledPedstrianCount;
extern uint8_t volatile ButtonFlag;


/*******************************************************************************
 *                      Implementation Functions                               *
 *******************************************************************************/

static void yellowLed(void)
{
	if(ButtonFlag == TRUE)
	{
		_delay_ms(30);
		if(ButtonFlag == TRUE)
		{
			if(ledPedstrianFlag == FALSE)
			{
				ledCount = 0;
				ledPedstrianFlag = TRUE;
				ledPedstrianCount = 0;
			}
			if((ledPedstrianCount % 2) == 0)
			{
				Led_OFF(RED_LED_PEDESTRIAN);
				Led_OFF(GREEN_LED_PEDESTRIAN);
				Led_ON(YELLOW_LED_PEDESTRIAN);
			}
			else
			{
				Led_OFF(RED_LED_PEDESTRIAN);
				Led_OFF(GREEN_LED_PEDESTRIAN);
				Led_OFF(YELLOW_LED_PEDESTRIAN);
			}
		}
	}
	if((ledCount % 2) == 0)
	{
		Led_ON(YELLOW_LED_CAR);
		Led_OFF(RED_LED_CAR);
		Led_OFF(GREEN_LED_CAR);
	}
	else
	{
		Led_OFF(YELLOW_LED_CAR);
		Led_OFF(GREEN_LED_CAR);
		Led_OFF(RED_LED_CAR);
	}
}

static void redCarLed(void)
{
	greenLed = 0;
	LED_Flag = TRUE;
	ledCount = 0;

	while(ledCount <= 19)
	{
		Yellow_Before_Red = 1;
		yellowLed();
		if(ledCount == 19)
		{
			break;
		}
	}
	LED_Flag = TRUE;
	ledCount = 0;
	ledPedstrianFlag = TRUE;
	ledPedstrianCount = 0;

	while(LED_Flag != FALSE)
	{
		redLed = 1;
		Led_ON(RED_LED_CAR);
		Led_OFF(YELLOW_LED_CAR);
		Led_OFF(GREEN_LED_CAR);

		Led_OFF(YELLOW_LED_PEDESTRIAN);
		Led_ON(GREEN_LED_PEDESTRIAN);
		Led_OFF(RED_LED_PEDESTRIAN);
	}

	Led_OFF(RED_LED_CAR);
	Led_OFF(YELLOW_LED_CAR);
	Led_OFF(GREEN_LED_CAR);

	Led_OFF(YELLOW_LED_PEDESTRIAN);
	Led_OFF(GREEN_LED_PEDESTRIAN);
	Led_OFF(RED_LED_PEDESTRIAN);

	Yellow_Before_Green=0;
}

static void greenCarLed(void){

	Yellow_Before_Green = 1;
	Yellow_Before_Red = 0;
	redLed = 0;
	LED_Flag = TRUE;
	ledCount = 0;

	/* Blinking Yellow Led for 5sec */
	uint8_t intFlag = 0;
	while(ledCount <= 19)
	{
		yellowLed();

		if(ButtonFlag == TRUE)
		{
			intFlag = 1;
		}
		if(ledCount == 19)
		{
			break;
		}
	}

	LED_Flag = TRUE;
	ledCount = 0;
	ledPedstrianFlag = TRUE;
	ledPedstrianCount = 0;
	greenLed = 1;
	while((LED_Flag != FALSE) && (ButtonFlag == FALSE))
	{
		Yellow_Before_Green=0;
		Led_ON(GREEN_LED_CAR);
		Led_OFF(YELLOW_LED_CAR);
		Led_OFF(RED_LED_CAR);

		Led_ON(RED_LED_PEDESTRIAN);
		Led_OFF(GREEN_LED_PEDESTRIAN);
		Led_OFF(YELLOW_LED_PEDESTRIAN);
	}

	if(intFlag == 1)
	{
		Yellow_Before_Green = 1;
	}

	Led_OFF(RED_LED_CAR);
	Led_OFF(YELLOW_LED_CAR);
	Led_OFF(GREEN_LED_CAR);

	Led_OFF(YELLOW_LED_PEDESTRIAN);
	Led_OFF(GREEN_LED_PEDESTRIAN);
	Led_OFF(RED_LED_PEDESTRIAN);

}

void AppStart(void)
{
	if(ButtonFlag == FALSE)
	{
		Led_ON(RED_LED_PEDESTRIAN);

		normalMode();
	}
	else
	{
		pedstrianMode();
	}
}

void normalMode(void)
{
	if(redLed == 1)
	{
		greenCarLed();
	}
	else
	{
		redCarLed();
	}
}

void pedstrianMode(void){

	if(ButtonFlag == TRUE){
		_delay_ms(30);
		if(ButtonFlag == TRUE){
			firstCase();
			thirdCase();
			ButtonFlag = FALSE;
		}
	}
}


void firstCase(void)
{
	if(greenLed == 1)
	{
		LED_Flag = TRUE;
		ledCount = 0;
		ledPedstrianFlag = TRUE;
		ledPedstrianCount=0;

		/* Blinking Yellow Led for 5sec */
		if(Yellow_Before_Green!=1)
		{
			while((ledCount <= 19) || (ledPedstrianCount <= 19))
			{
				if(ButtonFlag == TRUE)
				{
					_delay_ms(30);
					if(ButtonFlag == TRUE)
					{
						if(ledPedstrianFlag == FALSE)
						{
							ledCount=0;
							ledPedstrianFlag =TRUE;
							ledPedstrianCount=0;
						}
						if((ledPedstrianCount % 2) == 0)
						{
							Led_ON(YELLOW_LED_PEDESTRIAN);
							Led_OFF(GREEN_LED_PEDESTRIAN);
							Led_OFF(RED_LED_PEDESTRIAN);
						}
						else
						{
							Led_OFF(YELLOW_LED_PEDESTRIAN);
							Led_OFF(GREEN_LED_PEDESTRIAN);
							Led_OFF(RED_LED_PEDESTRIAN);
						}
					}
				}
				if((ledCount % 2) == 0)
				{
					Led_ON(YELLOW_LED_CAR);
					Led_OFF(GREEN_LED_CAR);
					Led_OFF(RED_LED_CAR);
				}
				else
				{
					Led_OFF(YELLOW_LED_CAR);
					Led_OFF(GREEN_LED_CAR);
					Led_OFF(RED_LED_CAR);
				}

				if((ledCount == 19) || (ledPedstrianCount == 19))
				{
					break;
				}
			}
		}
		LED_Flag = TRUE;
		ledCount=0;
		ledPedstrianFlag = TRUE;
		ledPedstrianCount=0;

		while((LED_Flag != FALSE) && (ledPedstrianFlag != FALSE))
		{
			redLed=1;
			Led_ON(RED_LED_CAR);
			Led_OFF(YELLOW_LED_CAR);
			Led_OFF(GREEN_LED_CAR);

			Led_ON(GREEN_LED_PEDESTRIAN);
			Led_OFF(YELLOW_LED_PEDESTRIAN);
			Led_OFF(RED_LED_PEDESTRIAN);
			if((ledPedstrianCount == 19) && (ledCount == 19))
			{
				break;
			}
		}
		Led_OFF(RED_LED_CAR);
		Led_OFF(YELLOW_LED_CAR);
		Led_OFF(GREEN_LED_CAR);

		Led_OFF(RED_LED_PEDESTRIAN);
		Led_OFF(YELLOW_LED_PEDESTRIAN);
		Led_OFF(GREEN_LED_PEDESTRIAN);
		ButtonFlag = FALSE;
	}
}

void thirdCase(void)
{
	if(redLed == 1)
	{
		ButtonFlag = FALSE;
	}
}
