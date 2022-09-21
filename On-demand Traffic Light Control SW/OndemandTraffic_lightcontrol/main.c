/*
 ============================================================================
 Name        : main.c
 Author      : Mohamed Saeed
 Created on  : Sep 5, 2022
 Description : Main File
 ============================================================================
 */

#include "APP/app.h"
#include "MCAL/EXTERNAL_INTERRUPT/external _interrupt.h"
int main()
{
	Timer_init();
	EXT_INT_Init();
	sei();
	while(1)
	{
		AppStart();
	}
	return 0;
}
