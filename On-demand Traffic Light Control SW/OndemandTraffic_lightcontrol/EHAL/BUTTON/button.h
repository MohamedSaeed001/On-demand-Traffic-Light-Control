/*
 ============================================================================
 Name        : button.h
 Author      : Mohamed Saeed
 Created on  : Sep 5, 2022
 Description : Header File For Button
 ============================================================================
 */

#ifndef EHAL_BUTTON_BUTTON_H_
#define EHAL_BUTTON_BUTTON_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../../utils/common_macros.h"
#include "../../utils/std_types.h"
#include "../../MCAL/GPIO/gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUTTON_PIN			PIN2_ID
#define BUTTON_PORT			PORTD_ID

typedef enum
{
	Button_Pressed,
	Button_Unpressed
}Button_State_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void buttonInit(void);
Button_State_t buttonIsPressed(void);

#endif /* EHAL_BUTTON_BUTTON_H_ */
