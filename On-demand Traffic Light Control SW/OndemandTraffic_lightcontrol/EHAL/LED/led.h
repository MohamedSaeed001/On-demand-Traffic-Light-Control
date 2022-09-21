/*
 ============================================================================
 Name        : led.h
 Author      : Mohamed Saeed
 Created on  : Sep 5, 2022
 Description : Header File For LEDS
 ============================================================================
 */

#ifndef EHAL_LED_LED_H_
#define EHAL_LED_LED_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../../MCAL/GPIO/gpio.h"
#include "../../utils/std_types.h"

/*******************************************************************************
 *                                Types                                  *
 *******************************************************************************/
typedef enum{
	RED_LED_CAR = 1,
	YELLOW_LED_CAR,
	GREEN_LED_CAR,

	RED_LED_PEDESTRIAN,
	YELLOW_LED_PEDESTRIAN,
	GREEN_LED_PEDESTRIAN
}EN_LED_TYPE_t;

typedef enum{
  LED_ON,
  LED_OFF
}EN_LED_STATE_t;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
EN_LED_STATE_t Led_ON(EN_LED_TYPE_t LED_TYPE);
EN_LED_STATE_t Led_OFF(EN_LED_TYPE_t LED_TYPE);


#endif /* EHAL_LED_LED_H_ */
