/*
 ============================================================================
 Name        : timer_reg.h
 Author      : Mohamed Saeed
 Description : Header File For ATmega32 Timer Module
 ============================================================================
 */

#ifndef MCAL_TIMER_TIMER_REG_H_
#define MCAL_TIMER_TIMER_REG_H_

/* TIMER0 Mode's */
#define TIMER0_Mode_Clr_msk                           0xB7
#define TIMER0_Mode_Ovf_msk                           0x00  /* Normal Mode */
#define TIMER0_Mode_Pwm_PhaseCorrect_msk              0x40
#define TIMER0_Mode_Ctc_msk                           0x08
#define TIMER0_Mode_FastPwm_msk                       0x48

/* TIMER2 Mode's */
#define TIMER2_Mode_Clr_msk                           0xB7
#define TIMER2_Mode_Ovf_msk                           0x00  /* Normal Mode */
#define TIMER2_Mode_Pwm_PhaseCorrect_msk              0x40
#define TIMER2_Mode_Ctc_msk                           0x08
#define TIMER2_Mode_FastPwm_msk                       0x48

/* TIMER1 Mode's */
#define TIMER1_Mode_Clr_msk                           0xF0
#define TIMER1_Mode_Ovf_msk                           0x00  /* Normal Mode */
#define TIMER1_Mode_Pwm_PhaseCorrect_8_bit_msk        0x01
#define TIMER1_Mode_Pwm_PhaseCorrect_9_bit_msk        0x02
#define TIMER1_Mode_Pwm_PhaseCorrect_10_bit_msk       0x03
#define TIMER1_Mode_Ctc_msk                           0x04
#define TIMER1_Mode_FastPwm_8_bit_msk                 0x05
#define TIMER1_Mode_FastPwm_9_bit_msk                 0x06
#define TIMER1_Mode_FastPwm_10_bit_msk                0x07
#define TIMER1_Mode_Pwm_Phase_Frequency_Correct_msk   0x09
#define TIMER1_Mode_Pwm_Phase_Correct_msk             0x0B
#define TIMER1_Mode_Fast_Pwm_msk                      0x0F



/*
 * Timer's Clock Select
 */

/* TIMER0 Clock and PreScaler */
#define TIMER0_Clk_With_PreScaler_Clr_msk              0xF8
#define TIMER0_Clk_With_No_PreScaler_msk               0x01
#define TIMER0_Clk_With_8_PreScaler_msk                0x02
#define TIMER0_Clk_With_64_PreScaler_msk               0x03
#define TIMER0_Clk_With_256_PreScaler_msk              0x04
#define TIMER0_Clk_With_1024_PreScaler_msk             0x05

#define TIMER0_External_Clk_With_Falling_Edge_msk      0x06
#define TIMER0_External_Clk_With_Rising_Edge_msk       0x07


/* TIMER2 Clock and PreScaler */
#define TIMER2_Clk_With_PreScaler_Clr_msk              0xF8
#define TIMER2_Clk_With_No_PreScaler_msk               0x01
#define TIMER2_Clk_With_8_PreScaler_msk                0x02
#define TIMER2_Clk_With_32_PreScaler_msk               0x03
#define TIMER2_Clk_With_64_PreScaler_msk               0x04
#define TIMER2_Clk_With_128_PreScaler_msk              0x05
#define TIMER2_Clk_With_256_PreScaler_msk              0x06
#define TIMER2_Clk_With_1024_PreScaler_msk             0x07


/* TIMER1 Clock and PreScaler */
#define TIMER1_Clk_With_PreScaler_Clr_msk              0xF8
#define TIMER1_Clk_With_No_PreScaler_msk               0x01
#define TIMER1_Clk_With_8_PreScaler_msk                0x02
#define TIMER1_Clk_With_64_PreScaler_msk               0x03
#define TIMER1_Clk_With_256_PreScaler_msk              0x04
#define TIMER1_Clk_With_1024_PreScaler_msk             0x05

#define TIMER1_External_Clk_With_Falling_Edge_msk      0x06
#define TIMER1_External_Clk_With_Rising_Edge_msk       0x07



#define TIMER0_OC0_clr_msk                           0xCF
#define TIMER0_OC0_TOGGLE_msk                        0x01
#define TIMER0_OC0_CLR_msk                           0x02
#define TIMER0_OC0_SET_msk                           0x03
#define TIMER0_OC0_NON_INVERTING_msk                 0x04
#define TIMER0_OC0_INVERTING_msk                     0x05

#define TIMER2_OC2_clr_msk                           0xCF
#define TIMER2_OC2_TOGGLE_msk                        0x01
#define TIMER2_OC2_CLR_msk                           0x02
#define TIMER2_OC2_SET_msk                           0x03
#define TIMER2_OC2_NON_INVERTING_msk                 0x04
#define TIMER2_OC2_INVERTING_msk                     0x05

#define TIMER1_OC1A_clr_msk                          0x3F
#define TIMER1_OC1B_clr_msk                          0xCF
#define TIMER1_OC1_TOGGLE_msk                        0x01
#define TIMER1_OC1_CLR_msk                           0x02
#define TIMER1_OC1_SET_msk                           0x03
#define TIMER1_OC1_NON_INVERTING_msk                 0x04
#define TIMER1_OC1_INVERTING_msk                     0x05

#define TIMER1_OC1_SPECIAL_TOGGLE_FastPWM_msk        0x06
#define TIMER1_OC1_SPECIAL_TOGGLE_Phase_Correct_msk  0x07


#endif /* MCAL_TIMER_TIMER_REG_H_ */
