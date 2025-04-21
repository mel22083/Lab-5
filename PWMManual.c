/*
 * PWMManual.c
 *
 * Created: 4/20/2025 7:34:02 PM
 *  Author: willi
 */ 

#include "PWMManual.h"
#include <avr/interrupt.h>

volatile uint8_t pwm_duty = 128; 
volatile uint8_t pwm_counter = 0;

void PWMManual_INIT(void)
{
	
	DDRD |= (1 << PORTD2);

	
	TCCR0A = 0;
	TCCR0B = (1 << CS01) | (1 << CS00);

	
	TIMSK0 |= (1 << TOIE0);
}

void PWMManual_setDuty(uint8_t duty)
{
	pwm_duty = duty;
}

ISR(TIMER0_OVF_vect)
{
	pwm_counter++;

	if (pwm_counter == 0)
	{
		PORTD |= (1 << PORTD2); // Encender LED
	}
	else if (pwm_counter == pwm_duty)
	{
		PORTD &= ~(1 << PORTD2); // Apagar LED
	}
}
