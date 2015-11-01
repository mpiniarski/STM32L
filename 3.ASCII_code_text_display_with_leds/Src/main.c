#include "stm32l1xx.h"
#include "ASCII_text_display.h"

#define DELAYms		2000

unsigned int counter = 0;
unsigned char text[12]=
	{'S','T','M','3','2','L','1','0','0','R','C',0}; // 0 is pause

//Define TIM3 IRQ Handler
void TIM3_IRQHandler(){
	//Check if is TIM3`s UIF flag set
	if(TIM3->SR & TIM_SR_UIF)
	{
		//Reset UIF flag
		TIM3->SR &= ~TIM_SR_UIF;
		setDisplayTo(text[(counter++)%11]);
	}
}

int main()
{
	// Enable clock for GPIOA and TIM3
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	
	initDiods();

	//Configure TIM3 to tick every second
	TIM3->PSC = 2097 - 1; 
	TIM3->ARR = DELAYms - 1;
	TIM3->CR1 = TIM_CR1_CEN;

	//Enable interrupt`s for TIM3
	NVIC_EnableIRQ(TIM3_IRQn); // function from core_m3.h
	TIM3->DIER |= TIM_DIER_UIE;

	while(1){
	}
}

