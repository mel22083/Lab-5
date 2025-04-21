/*
 * PWM1.h
 *
 * Created: 4/6/2025 8:07:44 PM
 *  Author: willi
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

#ifndef PWM1_H_
#define PWM1_H_

void PWM1_INIT(void);
void angulo_servo1(uint8_t angulo, uint8_t servo1);


#endif /* PWM1_H_ */

