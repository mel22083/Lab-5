/*
 * PWM2.c
 *
 * Created: 4/7/2025 6:12:26 PM
 *  Author: willi
 */ 

#include "PWM2.h"

void PWM2_INIT(void)
{
	
	DDRD |= (1 << PORTD3);
	
	//Modo Fast PWM con TOP en OCR2A
	TCCR2A = (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
	TCCR2B = (1 << WGM22) | (1 << CS22) | (1 << CS21) | (1 << CS20); // Prescaler = 1024
	
	OCR2A = 255;
	OCR2B = 12; // Pulso inicial 1ms
	
}

void angulo_servo2(uint8_t angulo2)
{
	OCR2B = 8 + ((uint16_t)angulo2 * (16 - 8)) / 180;
}
