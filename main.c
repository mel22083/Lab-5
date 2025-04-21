/*
 * Prelabo 5.c 
 */
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "PWM1/PWM1.h"
#include "PWM2/PWM2.h"
#include "PWMManual/PWMManual.h"

#ifndef MUX5
#define MUX5 3
#endif

volatile uint8_t valorADC = 0;
volatile uint8_t angulo = 0;
volatile uint8_t canalADC = 0; 

void initADC();
void seleccionarCanalADC(uint8_t canal);

int main(void)
{
	CLKPR = (1 << CLKPCE);     
	CLKPR = (1 << CLKPS0);     
	
	PWM1_INIT();
	PWM2_INIT();
	PWMManual_INIT();
	initADC();

	sei();

	while (1) 
	{
		// --- PWM1: canal A6 / ADC6 ---
		canalADC = 6;
		seleccionarCanalADC(canalADC);
		_delay_ms(5);
		angulo = (valorADC * 180) / 255;
		angulo_servo1(angulo, 1);
		_delay_ms(50);

		// --- PWM2: canal A7 / ADC7 ---
		canalADC = 7;
		seleccionarCanalADC(canalADC);
		_delay_ms(5);
		angulo = (valorADC * 180) / 255;
		angulo_servo2(angulo);
		_delay_ms(50);

		// --- PWM Manual: canal PC2 / ADC2 ---
		canalADC = 2;
		seleccionarCanalADC(canalADC);
		_delay_ms(5);
		PWMManual_setDuty(valorADC);
	}
}

void initADC()
{
	ADMUX = (1 << REFS0) | (1 << ADLAR); 
	ADCSRA = (1 << ADPS1) | (1 << ADPS0) | (1 << ADIE) | (1 << ADEN) | (1 << ADSC); 
}

void seleccionarCanalADC(uint8_t canal)
{
	ADMUX = (ADMUX & 0xF0) | (canal & 0x07);
	if (canal > 7)
	{
		canal = 0;
	}
	ADCSRB &= ~(1 << MUX5); 
	if (canal >= 6)
	{
		ADCSRB |= (1 << MUX5); 
	}
	ADMUX = (ADMUX & 0xF0) | (canal & 0x0F);
	ADCSRA |= (1 << ADSC); 
}

ISR(ADC_vect)
{
	valorADC = ADCH;
}
