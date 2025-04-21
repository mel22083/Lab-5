/*
 * PWM1.c
 *
 * Created: 4/6/2025 8:07:20 PM
 *  Author: willi
 */ 
#include "PWM1.h"

void PWM1_INIT(void)
{ 
	
	DDRB |= (1 << PB1) | (1 << PB2);					//OCIA y OCIB como salidas
	
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);			//
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);			   //FAST PWM y preescaler de 8
	ICR1 = 39999;
	
}
void angulo_servo1(uint8_t angulo, uint8_t servo1)
{
	uint16_t ancho_de_pulso = 0;
	switch (servo1)
	{
		case 1:
		ancho_de_pulso = 1000 + ((uint32_t)angulo * 4000) / 180;
		OCR1A = ancho_de_pulso;
		break;
		case 2:
		ancho_de_pulso = 1000 + ((uint32_t)angulo * 4000) / 180;
		OCR1B = ancho_de_pulso;
		break;
	}
	
	
}
