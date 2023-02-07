#include "stm32f429xx.h"
HCIF

int main(){


DMA1_Stream0_BASE

RCC->AHB1ENR |=1UL<<21;
	
	//enable bit
	DMA1_Stream0->CR &= ~(1UL);
	
	//set channel 4 in stream0
	DMA1_Stream0->CR &= ~(15UL<<25);
	DMA1_Stream0->CR |= (4UL<<25);
	
	//set priority
	DMA1_Stream0->CR &= ~(3UL<<16);
	
	//set msize and psize bits
	DMA1_Stream0->CR &= ~(3UL<<13);  //msize
	//DMA1_Stream0->CR |= (3UL<<13)
	DMA1_Stream0->CR &= ~(3UL<<11);  //psize
	//DMA1_Stream0->CR |= (3UL<<13)
	
	//set minc and pinc
	DMA1_Stream0->CR |= (1UL<<10); //minc
	DMA1_Stream0->CR |= (1UL<<9);
	
	//set dir bits
	DMA1_Stream0->CR &= ~(3UL<<6)
	//DMA1_Stream0->CR |= (1UL<<13)
	//DMA1_Stream4->
	DMA1->LISR = 0;
	
	return 0;
}