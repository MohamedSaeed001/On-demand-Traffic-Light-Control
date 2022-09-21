/*
 ============================================================================
 Name        : gpio.c
 Author      : Mohamed Saeed
 Description : Source file for the Atmega32 GPIO driver
 ============================================================================
 */


/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "gpio.h"
#include "../../utils/common_macros.h"


/*******************************************************************************
 *                                Functions Implementation                                     *
 *******************************************************************************/

/*
 * This function is responsible to Setting the direction of a specific pin
 */
void GPIO_setPinDirection(uint8_t portn, uint8_t pin_num, GPIO_PinDirection dir){
	if((portn >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT)){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(portn){
		case PORTA_ID:
			if(dir == PIN_OUTPUT){
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(dir == PIN_OUTPUT){
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(dir == PIN_OUTPUT){
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(dir == PIN_OUTPUT){
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}

/*
 * This function is responsible to Write (1 or 0) on a specific pin
 */
void GPIO_writePin(uint8_t portn, uint8_t pin_num, uint8_t value){
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (portn >= NUM_OF_PORTS)){
		/* Do Nothing */
	}
	else
	{
		switch(portn){
		case PORTA_ID:
			if(value == LOGIC_HIGH){
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == LOGIC_HIGH){
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH){
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == LOGIC_HIGH){
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}

/*
 * This function is responsible to Read the value from a specific pin
 */
uint8_t GPIO_readPin(uint8_t portn, uint8_t pin_num)
{
	uint8_t data = LOGIC_LOW;

	if((portn >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT)){
		/* Do Nothing */
	}
	else
	{
		switch(portn){
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num)){
				data = LOGIC_HIGH;
			}
			else
			{
				data = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num)){
				data = LOGIC_HIGH;
			}
			else
			{
				data = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num)){
				data = LOGIC_HIGH;
			}
			else
			{
				data = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num)){
				data = LOGIC_HIGH;
			}
			else
			{
				data = LOGIC_LOW;
			}
			break;
		}
	}

	return data;
}

/*
 * This function is responsible to Setting the direction of a specific Port
 */
void GPIO_setPortDirection(uint8_t portn, uint8_t dir){
	if(portn >= NUM_OF_PORTS){
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(portn){
		case PORTA_ID:
			DDRA = dir;
			break;
		case PORTB_ID:
			DDRB = dir;
			break;
		case PORTC_ID:
			DDRC = dir;
			break;
		case PORTD_ID:
			DDRD = dir;
			break;
		}
	}
}

/*
 *This function is responsible to Write value (0...255) on a specific port
 */
void GPIO_writePort(uint8_t portn, uint8_t value){
	if(portn >= NUM_OF_PORTS){
		/* Do Nothing */
	}
	else
	{
		switch(portn){
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}

/*
 * This function is responsible to Read the value from a specific PORT
 */
uint8_t GPIO_readPort(uint8_t portn)

{
	uint8_t data = LOGIC_LOW;


	if(portn >= NUM_OF_PORTS){
		/* Do Nothing */
	}
	else
	{
		switch(portn){
		case PORTA_ID:
			data = PINA;
			break;
		case PORTB_ID:
			data = PINB;
			break;
		case PORTC_ID:
			data = PINC;
			break;
		case PORTD_ID:
			data = PIND;
			break;
		}
	}

	return data;
}
