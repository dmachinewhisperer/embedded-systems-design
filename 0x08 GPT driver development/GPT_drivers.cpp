#include <stdint.h>
#include "stm32f429xx.h"

void analogWrite(uint8_t dutyCycle, uint8_t freq = 100){
	RCC->AHB1ENR  |= 1UL<<4;

	GPIOE->MODER  &= ~(3UL<<18); 
	GPIOE->MODER  |= 2UL<<18;
	
	GPIOE->AFR[1] &= ~(0xF<<4);
	GPIOE->AFR[1] |= 1UL<<4;

	RCC->APB2ENR  |= 1UL;
	
	uint32_t f = 100000;
	TIM1->PSC  = 79;
	TIM1-> ARR = f/freq - 1;
	//TIM1-> ARR = 999;
	TIM1->CCR1 = dutyCycle*TIM1->ARR/100;
		
	TIM1->CCMR1 &= ~(7UL<< 4);
	//TIM1->CCMR1 |= (3UL<<4);
	TIM1->CCMR1 |= (6UL<<4);
	TIM1->CCMR1 |= 1UL<<3;
		
	TIM1->CCER |= 1UL;
	TIM1->CCER &= ~(1UL<<2);

	TIM1->BDTR |= 1UL<<15;

	TIM1->CR1  &= ~(1UL<<4);
	
	TIM1->CR1  |= 1UL;

}

void sqWave(uint8_t T = 2){
	
	RCC->AHB1ENR  |= 1UL<<4;

	GPIOE->MODER  &= ~(3UL<<18); 
	GPIOE->MODER  |= 2UL<<18;
	
	GPIOE->AFR[1] &= ~(0xF<<4);
	GPIOE->AFR[1] |= 1UL<<4;

	RCC->APB2ENR  |= 1UL;
		
	TIM1->PSC  = 7999;
	TIM1-> ARR = 1000*T - 1;
	TIM1->CCR1 = 500;
		
	TIM1->CCMR1 &= ~(7UL<< 4);
	TIM1->CCMR1 |= (3UL<<4);
		
	TIM1->CCER |= 1UL;
	TIM1->CCER &= ~(1UL<<2);

	TIM1->BDTR |= 1UL<<15;

	TIM1->CR1  &= ~(1UL<<4);
	
	TIM1->CR1  |= 1UL;
}