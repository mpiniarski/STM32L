#include "stm32l1xx.h"

#define LED1_PIN			8
#define LED2_PIN			9
#define BUTTON_PIN		0

int main()
{
	// Enable clock for GPIOC, GPIOA and TIM3
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

	// Configure LED's pins as output
	GPIOC->MODER |= (1 << (LED1_PIN<<1));
	GPIOC->MODER |= (1 << (LED2_PIN<<1));

	// Configure Button pis as input;
	GPIOA->MODER &= (-1 << (BUTTON_PIN+1));

	while(1){
		if (GPIOA->IDR & (1<<BUTTON_PIN)){
			GPIOC->BSRR |= (1<<LED1_PIN);
			GPIOC->BSRR |= (1<<(LED2_PIN+16));
		}
		else{
			GPIOC->BSRR |= (1<<LED2_PIN);
			GPIOC->BSRR |= (1<<(LED1_PIN+16));
		}
	}
}

