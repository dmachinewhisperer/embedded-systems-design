#include <stm32f429xx.h>
#include <stdint.h>


void digitalWrite(int PIN, uint32_t STATE, char PORT = 'A'){
	switch(PORT){
		case 'A': GPIOA->ODR &= ~(1UL<<PIN); GPIOA->ODR |= STATE<<PIN; break;
		case 'B': GPIOB->ODR &= ~(1UL<<PIN); GPIOB->ODR |= STATE<<PIN; break;
		case 'C': GPIOC->ODR &= ~(1UL<<PIN); GPIOC->ODR |= STATE<<PIN; break;
		case 'D': GPIOD->ODR &= ~(1UL<<PIN); GPIOD->ODR |= STATE<<PIN; break;
		case 'E': GPIOE->ODR &= ~(1UL<<PIN); GPIOE->ODR |= STATE<<PIN; break;
		case 'F': GPIOF->ODR &= ~(1UL<<PIN); GPIOF->ODR |= STATE<<PIN; break;
		case 'G': GPIOG->ODR &= ~(1UL<<PIN); GPIOG->ODR |= STATE<<PIN; break;
		case 'H': GPIOH->ODR &= ~(1UL<<PIN); GPIOH->ODR |= STATE<<PIN; break;
		case 'I': GPIOI->ODR &= ~(1UL<<PIN); GPIOI->ODR |= STATE<<PIN; break;
		case 'J': GPIOJ->ODR &= ~(1UL<<PIN); GPIOJ->ODR |= STATE<<PIN; break;
		case 'K': GPIOK->ODR &= ~(1UL<<PIN); GPIOK->ODR |= STATE<<PIN; break;
		default:                                                       break;
			
	}
}

int digitalRead(int PIN, char PORT = 'A'){
	switch(PORT){
		case 'A': return ((GPIOA->IDR & 1<<PIN) >0);
		case 'B': return ((GPIOB->IDR & 1<<PIN) >0);
		case 'C': return ((GPIOC->IDR & 1<<PIN) >0);
		case 'D': return ((GPIOD->IDR & 1<<PIN) >0);
		case 'E': return ((GPIOE->IDR & 1<<PIN) >0);
		case 'F': return ((GPIOF->IDR & 1<<PIN) >0);
		case 'G': return ((GPIOG->IDR & 1<<PIN) >0);
		case 'H': return ((GPIOH->IDR & 1<<PIN) >0);
		case 'I': return ((GPIOI->IDR & 1<<PIN) >0);
		case 'J': return ((GPIOJ->IDR & 1<<PIN) >0);
		case 'K': return ((GPIOK->IDR & 1<<PIN) >0);
		default:  return 0;
			
	}

}
	
void pinMode(int PIN, uint32_t MODER, char PORT = 'A', uint32_t OTYPER = 0x00, uint32_t OSPEEDR = 0x00, uint32_t PUPDR = 0x00){
	RCC->AHB1ENR |= 1UL<<(PORT - 'A');
	switch(PORT){
		case 'A':
			GPIOA->MODER   &= ~(3UL<<(2*PIN));
			GPIOA->MODER   |= MODER<<(2*PIN);
			GPIOA->OTYPER  &= ~(1UL<<PIN);
			GPIOA->OTYPER  |= OTYPER<<PIN;
			GPIOA->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOA->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOA->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOA->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'B':
			GPIOB->MODER   &= ~(3UL<<(2*PIN));
			GPIOB->MODER   |= MODER<<(2*PIN);
			GPIOB->OTYPER  &= ~(1UL<<PIN);
			GPIOB->OTYPER  |= OTYPER<<PIN;
			GPIOB->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOB->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOB->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOB->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'C':
			GPIOC->MODER   &= ~(3UL<<(2*PIN));
			GPIOC->MODER   |= MODER<<(2*PIN);
			GPIOC->OTYPER  &= ~(1UL<<PIN);
			GPIOC->OTYPER  |= OTYPER<<PIN;
			GPIOC->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOC->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOC->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOC->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'D':
			GPIOD->MODER   &= ~(3UL<<(2*PIN));
			GPIOD->MODER   |= MODER<<(2*PIN);
			GPIOD->OTYPER  &= ~(1UL<<PIN);
			GPIOD->OTYPER  |= OTYPER<<PIN;
			GPIOD->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOD->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOD->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOD->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'E':
			GPIOE->MODER   &= ~(3UL<<(2*PIN));
			GPIOE->MODER   |= MODER<<(2*PIN);
			GPIOE->OTYPER  &= ~(1UL<<PIN);
			GPIOE->OTYPER  |= OTYPER<<PIN;
			GPIOE->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOE->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOE->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOE->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'F':
			GPIOF->MODER   &= ~(3UL<<(2*PIN));
			GPIOF->MODER   |= MODER<<(2*PIN);
			GPIOF->OTYPER  &= ~(1UL<<PIN);
			GPIOF->OTYPER  |= OTYPER<<PIN;
			GPIOF->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOF->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOF->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOF->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'G':
			GPIOG->MODER   &= ~(3UL<<(2*PIN));
			GPIOG->MODER   |= MODER<<(2*PIN);
			GPIOG->OTYPER  &= ~(1UL<<PIN);
			GPIOG->OTYPER  |= OTYPER<<PIN;
			GPIOG->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOG->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOG->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOG->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'H':
			GPIOH->MODER   &= ~(3UL<<(2*PIN));
			GPIOH->MODER   |= MODER<<(2*PIN);
			GPIOH->OTYPER  &= ~(1UL<<PIN);
			GPIOH->OTYPER  |= OTYPER<<PIN;
			GPIOH->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOH->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOH->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOH->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'I':
			GPIOI->MODER   &= ~(3UL<<(2*PIN));
			GPIOI->MODER   |= MODER<<(2*PIN);
			GPIOI->OTYPER  &= ~(1UL<<PIN);
			GPIOI->OTYPER  |= OTYPER<<PIN;
			GPIOI->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOI->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOI->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOI->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'J':
			GPIOJ->MODER   &= ~(3UL<<(2*PIN));
			GPIOJ->MODER   |= MODER<<(2*PIN);
			GPIOJ->OTYPER  &= ~(1UL<<PIN);
			GPIOJ->OTYPER  |= OTYPER<<PIN;
			GPIOJ->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOJ->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOJ->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOJ->PUPDR   |= PUPDR<<(2*PIN); break;
		case 'K':
			GPIOK->MODER   &= ~(3UL<<(2*PIN));
			GPIOK->MODER   |= MODER<<(2*PIN);
			GPIOK->OTYPER  &= ~(1UL<<PIN);
			GPIOK->OTYPER  |= OTYPER<<PIN;
			GPIOK->OSPEEDR &= ~(3UL<<(2*PIN));
			GPIOK->OSPEEDR |= OSPEEDR<<(2*PIN);
			GPIOK->PUPDR   &= ~(3UL<<(2*PIN));
			GPIOK->PUPDR   |= PUPDR<<(2*PIN); break;
		
		default: 														break;
		
	}

}