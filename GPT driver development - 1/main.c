#include <stdint.h>
#include "stm32f429xx.h"


void r(){
	

}

int main(){
	//Waveform Generaton --> Square pulse, r(t)
	
	//Enable CLK to GPIOE
	RCC->AHB1ENR |= 1UL<<4;
	//Set PE9 as output
	GPIOE->MODER &= ~(3UL<<18); 
	GPIOE->MODER |= 2UL<<18;
	//Select ALT function for TIM1
	GPIOE->AFR[1] &= ~(0xF<<4);
	GPIOE->AFR[1] |= 1UL<<4;
	//Enable clock to TIM1
	RCC->APB2ENR  |= 1UL;
		
		TIM1->PSC = 7999;
	TIM1-> ARR = 1999;
	TIM1->CCR1 = 500;
		
		 //Set the output behaviour in toggle mode, OC1M[1:0] = 011
	TIM1->CCMR1 &= ~(7UL<< 4);
	TIM1->CCMR1 |= (3UL<<4);
		
		//Enable TIM1, Channel 1N output
	//TIM1->CCER |= 1UL<<2;
	TIM1->CCER |= 1UL;
	//Set TIM1_CH1N polarity. 0 -> active high, 1 -> active low
	//TIM1->CCER &= ~(1UL<<3);

	//Enable Main Output
	TIM1->BDTR |= 1UL<<15;

	//DIR -> 0 -up, 1 - down
	//TIM1->CR1 &= ~(1UL<<4);
	
	//CEN -> Enable Counter
	TIM1->CR1 |= 1UL;


	return 0;
}