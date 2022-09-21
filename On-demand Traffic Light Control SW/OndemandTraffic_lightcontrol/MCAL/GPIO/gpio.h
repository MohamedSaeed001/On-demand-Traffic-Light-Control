/*
 ============================================================================
 Name        : gpio.h
 Author      : Mohamed Saeed
 Description : Header File For ATmega32 GPIO driver
 ============================================================================
 */


#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../../utils/std_types.h"
#include <avr/io.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*******************************************************************************
 *                               Types 				                           *
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,
	PIN_OUTPUT
}GPIO_PinDirection;

typedef enum
{
	PORT_INPUT,
	PORT_OUTPUT=0xFF
}GPIO_PortDirection;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * This function is responsible to Setting the direction of a specific pin
 */
void GPIO_setPinDirection(uint8_t portn, uint8_t pin_num, GPIO_PinDirection dir);

/*
 * This function is responsible to Write (1 or 0) on a specific pin
 */
void GPIO_writePin(uint8_t portn, uint8_t pin_num, uint8_t value);

/*
 * This function is responsible to Read the value from a specific pin
 */
uint8_t GPIO_readPin(uint8_t portn, uint8_t pin_num);

/*
 * This function is responsible to Setting the direction of a specific Port
 */
void GPIO_setPortDirection(uint8_t portn, uint8_t dir);

/*
 *This function is responsible to Write value (0...255) on a specific port
 */
void GPIO_writePort(uint8_t portn, uint8_t value);

/*
 * This function is responsible to Read the value from a specific PORT
 */
uint8_t GPIO_readPort(uint8_t portn);



#endif /* MCAL_GPIO_GPIO_H_ */
