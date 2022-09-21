/*
 ============================================================================
 Name        : std_types.h
 Author      : Mohamed Saeed
 Description : Common - Platform Types Abstraction
 ============================================================================
 */

#ifndef UTILS_STD_TYPES_H_
#define UTILS_STD_TYPES_H_

/* Boolean Data Type */
typedef unsigned char boolean;

/*******************************************************************************
 *                                 DEFINITIONS 	      			               *
 *******************************************************************************/
/* Boolean Values */
#define FALSE       (0u)
#define TRUE        (1u)

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)

/*******************************************************************************
 *                                     DATA TYPES 				               *
 *******************************************************************************/
/* unsigned Data types */
typedef unsigned char         uint8_t;          /*           0 .. 255              */
typedef unsigned short 		  uint16;           /*           0 ..65535 		       */
typedef unsigned long         uint32_t;         /*           0 .. 4294967295       */
typedef unsigned long long    uint64_t;         /*      0 .. 18446744073709551615  */

/* Signed Data types */
typedef signed char           sint8_t;          /*        -128 .. +127             */
typedef signed short          sint16_t;         /*      -32768 .. +32767           */
typedef signed long           sint32_t;         /* -2147483648 .. +2147483647      */
typedef signed long long      sint64_t;         /* -9223372036854775808 .. 9223372036854775807 */

/* float types*/
typedef float                 float32_t;
typedef double                float64_t;

typedef enum
{
	logic_low,
	logic_high
}LevelType;
#endif /* UTILS_STD_TYPES_H_ */
