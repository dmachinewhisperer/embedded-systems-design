#include <stdint.h>
#include "peripheral_registers.h"

/*
NOTE: EACH SECTION IS COMPLETELY INDEPENDENT WITH THEIR OWN MAIN FUNCTION AND PREPROCESSOR DIRECTIVES
UNCOMMENT AND RUN ACCORDINGLY
*/


//SECTION 1: MINMAL CODE TO WRITE HIGH TO GPIOB, PIN PB2

#define RCC_BASE_ADDR      0x40023800UL
#define GPIOB_BASE_ADDR    0x40020400UL
#define RCC_AHB1ENR_ADDR   ((volatile uint32_t *)(RCC_BASE_ADDR + 0x30UL ))
#define GPIOB_MODER_ADDR   ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x00UL ))
#define GPIOB_ODR_ADDR     ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x14UL )) 		

int main(){
	//Enable CLK to GPIOB
	*RCC_AHB1ENR_ADDR |= 1UL<<1;  
	//CLR and SET PB2 output mode. 01=> General Purpose Output
	*GPIOB_MODER_ADDR &= ~(3UL<<4);
	*GPIOB_MODER_ADDR |= 1UL<<4;
	//Write HIGH to PB2 ODR
	*GPIOB_ODR_ADDR |= 1UL<<2;
	return 0;
}


/*
//SECTION 2: CODE TO WRITE HIGH TO GPIOB, PIN PB2, CONFIGURING ALL NECESSARY REGISTERS

#define RCC_BASE_ADDR      0x40023800UL
#define GPIOB_BASE_ADDR    0x40020400UL
#define RCC_AHB1ENR_ADDR   ((volatile uint32_t *)(RCC_BASE_ADDR + 0x30UL ))
#define GPIOB_MODER_ADDR   ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x00UL ))
#define GPIOB_OTYPER_ADDR  ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x04UL ))
#define GPIOB_OSPEEDR_ADDR ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x08UL ))
#define GPIOB_PUPDR_ADDR   ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x0CUL ))
#define GPIOB_ODR_ADDR     ((volatile uint32_t *)(GPIOB_BASE_ADDR + 0x14UL ))
	
int main(){
	//Enable CLK to GPIOB
	*RCC_AHB1ENR_ADDR |= 1UL<<1;
	//CLR and SET PB2 output mode. 01=> General Purpose Output
	*GPIOB_MODER_ADDR &= ~(3UL<<4);
	*GPIOB_MODER_ADDR |= 1UL<<4;
	//Written to Config O/P type, => Set push-pull(0)
	*GPIOB_OTYPER_ADDR &= ~(1UL<<2);
	//Written to Config O/P speed, => Set low speed(00)
	*GPIOB_OSPEEDR_ADDR &= ~(3UL<<4);
	//Written to Config I/O pull-up/down, => Set no pull-up, no pull down(00)
	*GPIOB_PUPDR_ADDR &= ~(3UL<<4);
	//Write HIGH or LOW to O/P => Set HIGH(1)
	*GPIOB_ODR_ADDR |= 1UL<<2;
	return 0;

}

*/

/*
//SECTION 3: ARRANGING ALL GPIO REGISTERS IN A STRUCT, AND CONFIGURING THE PORTS

int main(){
	RCC->AHB1ENR |= 1UL<<1;
	GPIOB->MODER &= ~(3UL<<4); 
	GPIOB->MODER |= 1UL<<4;
	GPIOB->ODR |= 1UL<<2;
}
*/