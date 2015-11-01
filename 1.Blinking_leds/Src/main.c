#include "stm32l1xx.h"

int main()
{
	// Enable clock for GPIOC, GPIOA and TIM3
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	// Configure LED's pins as output
	GPIOC->MODER |= (1 << (8<<1));
	GPIOC->MODER |= (1 << (9<<1));

	//Configure TIM3 to tick every second
	TIM3->PSC = 2097 -1;
	TIM3->ARR = 1000 -1;
	TIM3->CR1 = TIM_CR1_CEN;

	while(1){
		//Check if is TIM3`s UIF flag set
		if(TIM3->SR & TIM_SR_UIF)
		{
			//Reset UIF flag
			TIM3->SR &= ~TIM_SR_UIF;
			//Toogle LEDs
			GPIOC->ODR ^= (1<<8);
			GPIOC->ODR ^= (1<<9);
		}
	}
}

