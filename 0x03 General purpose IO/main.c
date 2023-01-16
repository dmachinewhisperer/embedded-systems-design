#include <stdint.h>
#include "stm32f4xx.h"
//#include "GPIO_registers.h"
//#include "RCC.h"

//void RCC_Clock_Enable(void){
//	RCC->RCC_AHB1ENR = 0x0;
	

//}

//NEW DEFINES
//#define RCC_BASE_ADDR      ((volatile uint32_t *)0x40023800 )
//#define GPIOB_BASE_ADDR    ((volatile uint32_t *)0x40020400 )
//#define RCC_AHB1ENR_ADDR   ((volatile uint32_t *)(0x40023830 + 0x00))
//#define GPIOB_MODER_ADDR   ((volatile uint32_t *)(0x40020400 + 0x00))
//#define GPIOB_ODR_ADDR     ((volatile uint32_t *)(0x40020414 + 000)) 	


/*
I will never forger this one time I tried to dereference a pointer to a pointer and was 
stuck on 3 lines of code for 3 days. FUCCCCCK!!!!

#define RCC_BASE_ADDR      ((volatile uint32_t *)0x40023800 )
#define GPIOB_BASE_ADDR    ((volatile uint32_t *)0x40020400 )
*/
#define RCC_BASE_ADDR      0x40023800
#define GPIOB_BASE_ADDR    0x40020400
//#define GPIOB_BASE_ADDR    ((volatile uint32_t *)0x40010400UL )
#define RCC_AHB1ENR_ADDR   ((volatile uint32_t *)(RCC_BASE_ADDR + 0x30 ))
	
#define GPIOB_MODER_ADDR   ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x00 ))
	
//#define GPIOB_OTYPER_ADDR  ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x04UL ))
//#define GPIOB_OSPEEDR_ADDR ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x08UL ))
//#define GPIOB_PUPDR_ADDR   ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x0CUL ))

#define GPIOB_ODR_ADDR     ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x14 )) 	

int main(void){
	/*
	volatile uint32_t * AHB1ENR = RCC_AHB1ENR_ADDR;
	volatile uint32_t * MODER = GPIOB_MODER_ADDR;
	volatile uint32_t * ODR   = GPIOB_ODR_ADDR;
	
	*AHB1ENR |= 1UL<<1;
	
	*MODER &= ~(3UL<<4);
	*MODER |= 1UL<<4;
	*ODR |= 1UL<<2;
	
	*/
	*RCC_AHB1ENR_ADDR |= 1UL<<1;
	
	*GPIOB_MODER_ADDR &= ~(3UL<<4);
	*GPIOB_MODER_ADDR |= 1UL<<4;
	//*GPIOB_OTYPER_ADDR |= ~(1UL<<2);
	//*GPIOB_OSPEEDR_ADDR &= ~(3UL<<4);
	//*GPIOB_PUPDR_ADDR &= ~(3UL<<4);
	*GPIOB_ODR_ADDR |= 1UL<<2;
	
	/*
	what to try
	follow up RCC and GPIOB addresses
	put UL in the numbers above
	*/

	//AT LEAST THIS WORKS!!!!!
	/*
	RCC->AHB1ENR |= 1UL<<1;
	GPIOB->MODER &= ~(3UL<<4); 
	GPIOB->MODER |= 1UL<<4;
	GPIOB->ODR |= 1UL<<2;
	/*
	while(1){
		for(volatile int i = 0; i<500000;i++);
	GPIOB->ODR |= 1UL<<2;
		GPIOB->ODR ^= 1UL<<2;
	}
	*/

	/*RCC->RCC_AHB1ENR |=  1UL<<1;
	GPIOB->GPIOx_MODER &= ~(3UL<<4);
	GPIOB->GPIOx_MODER |= 1UL<<4;
	GPIOB->GPIOx_OTYPER |= ~(1UL<<2);
	GPIOB->GPIOx_OSPEEDR &= ~(3UL<<4);
	GPIOB->GPIOx_PUPDR &= ~(3UL<<4);
	GPIOB->GPIOx_ODR |= 1UL<<6;
	while(1);
	*/
	
	return 0;
}