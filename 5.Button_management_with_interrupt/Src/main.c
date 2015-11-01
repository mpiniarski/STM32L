#include "stm32l1xx.h"

#define LED1_PIN			8
#define LED2_PIN			9
#define BUTTON_PIN		0


void EXTI0_IRQHandler(){
//	if (EXTI->PR & EXTI_PR_PR0){
		EXTI->PR  |= EXTI_PR_PR0;
		GPIOC->ODR ^= (1<<LED1_PIN); // toogle
//	}
}

int main()
{
	// Enable clock for GPIOC and GPIOA
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

	// Configure LED's pins as output
	GPIOC->MODER |= (1 << (LED1_PIN<<1));
	GPIOC->MODER |= (1 << (LED2_PIN<<1));

	// Configure Button pis as input;
	GPIOA->MODER &= ~(1 << BUTTON_PIN);

	// Configure EXTI on line same as BUTTON_PIN
	EXTI->IMR |= (1 << BUTTON_PIN); // enabling interrupt
	EXTI->RTSR |= (1<<BUTTON_PIN); // enabling trigger on rising edge
	EXTI->FTSR &= ~(1<<BUTTON_PIN); // diabling trigger on falling edge
	// Enable EXTI's BUTTON_PIN line in NVIC
	NVIC_EnableIRQ(EXTI0_IRQn); // function from core_m3.h


	while(1){
	}
}

