#include "ASCII_text_display.h"
#include "stm32l1xx.h"

#define LEDS_PORT			GPIOA
#define LEDS_FIRST_PIN	0
#define LEDS_LAST_PIN	7

void initDiods(){
	int d;
	for(d=LEDS_FIRST_PIN; d<=LEDS_LAST_PIN; d++){
		initDiod(d);
	}
}

void initDiod(int pin){
	LEDS_PORT->MODER |= (1 << (pin<<1) );
}

void turnOnDiod(int pin){
	LEDS_PORT->BSRR |= (1 << pin);
}

void turnOffDiod(int pin){
	LEDS_PORT->BSRR |= (1 << (pin + 16) );
}

void toogleDiod(int pin){
	LEDS_PORT->ODR ^= (1 << (pin) );
}

void setDisplayTo(int value){
	LEDS_PORT->ODR = value;
}
