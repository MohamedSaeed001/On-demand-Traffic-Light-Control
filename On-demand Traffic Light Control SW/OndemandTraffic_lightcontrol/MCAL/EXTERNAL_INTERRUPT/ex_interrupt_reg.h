/*
 ============================================================================
 Name        : ex_interrupt_reg.h
 Author      : Mohamed Saeed
 Description : 
 ============================================================================
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EX_INTERRUPT_REG_H_
#define MCAL_EXTERNAL_INTERRUPT_EX_INTERRUPT_REG_H_


#define INT0_Sense_CLR_Mask                0xFC
#define INT0_Sense_Low_Level_Mask          0x00
#define INT0_Sense_Any_Logical_change_Mask 0x01
#define INT0_Sense_Falling_Edge_Mask       0x02
#define INT0_Sense_Rising_Edge_Mask        0x03

/*INT1 Mask's*/
#define INT1_Sense_CLR_Mask                0xF3
#define INT1_Sense_Low_Level_Mask          0x00
#define INT1_Sense_Any_Logical_change_Mask 0x04
#define INT1_Sense_Falling_Edge_Mask       0x08
#define INT1_Sense_Rising_Edge_Mask        0x0C

/*INT2 Mask's*/
#define INT2_Sense_CLR_Mask                0xBF
#define INT2_Sense_Falling_Edge_Mask       0x00
#define INT2_Sense_Rising_Edge_Mask        0x40


#endif /* MCAL_EXTERNAL_INTERRUPT_EX_INTERRUPT_REG_H_ */
