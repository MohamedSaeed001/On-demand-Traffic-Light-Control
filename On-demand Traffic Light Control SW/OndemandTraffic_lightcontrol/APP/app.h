/*
 ============================================================================
 Name        : app.h
 Author      : Mohamed Saeed
 Created on  : Sep 5, 2022
 Description : Header File For Application
 ============================================================================
 */

#ifndef APP_APP_H_
#define APP_APP_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../utils/std_types.h"
#include "../EHAL/LED/led.h"
#include "../MCAL/TIMER/timer.h"
#include <util/delay.h>
#include <avr/interrupt.h>

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void AppStart(void);
void normalMode(void);
void pedstrianMode(void);
void firstCase(void);
void thirdCase(void);

#endif /* APP_APP_H_ */
