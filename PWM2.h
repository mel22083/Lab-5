/*
 * PWM2.h
 *
 * Created: 4/7/2025 6:12:43 PM
 *  Author: willi
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>


#ifndef PWM2_H_
#define PWM2_H_

void PWM2_INIT(void);
void angulo_servo2(uint8_t angulo2);



#endif /* PWM2_H_ */
