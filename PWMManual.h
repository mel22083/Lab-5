/*
 * PWMManual.h
 *
 * Created: 4/20/2025 7:34:48 PM
 *  Author: willi
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>

#ifndef PWMMANUAL_H_
#define PWMMANUAL_H_


void PWMManual_INIT(void);
void PWMManual_setDuty(uint8_t duty);


#endif /* PWMMANUAL_H_ */
