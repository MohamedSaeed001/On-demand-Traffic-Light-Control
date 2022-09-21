/*
 ============================================================================
 Name        : common_macros.h
 Author      : Mohamed Saeed
 Description : Commonly used Macros
 ============================================================================
 */

#ifndef UTILS_COMMON_MACROS_H_
#define UTILS_COMMON_MACROS_H_

/* Write One at a specific place in any register */
#define SET_BIT(REG,BIT)			(REG |= (1<<BIT))

/* Write Zero at a specific place in any register */
#define CLEAR_BIT(REG,BIT)			(REG &= (~(1<<BIT)))

/* Change The Value at a specific place in any register */
#define TOGGLE_BIT(REG,BIT)			(REG ^= (1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,BIT)				(REG=(REG>>BIT) | (REG<<(8-BIT)))

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,BIT)				(REG=(REG<<BIT) | (REG>>(8-BIT)))

/* Check if a specific bit is One in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) 		(REG & (1<<BIT))

/* Check if a specific bit is Zero in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) 		(!(REG & (1<<BIT)))

#endif /* UTILS_COMMON_MACROS_H_ */
