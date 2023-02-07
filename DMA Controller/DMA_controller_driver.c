#include <stdint.h>
#include "DMA_structures_and_defines.h"

/*

int read_register();

int write_register();

int clock_enable();
*/
void initialize_DMAcontroller( Stream stream, config_table* table ){
	
	//Turn on CLK to DMA1
	RCC->AHB1ENR     |=  1UL<<DMA1_CLK_FIELD;  
	
	//Clear the previous flags
	//f(x) -> starting index of group of bits to clear
	//f(x) = 6x, x in {0,1} else 6x +4
	if(table->CHSEL <4){
		if(table->CHSEL <2)
			DMA1->LIFCR &= ~(0x3FUL)<< (6* table->CHSEL);
		else
			DMA1->LIFCR &= ~(0x3FUL)<<(6* table->CHSEL + 4);
	}
	else{
		if(table->CHSEL <6)
			DMA1->HIFCR &= ~(0x3FUL)<<(6* table->CHSEL);
		else
			DMA1->HIFCR &= ~(0x3FUL)<<(6* table->CHSEL + 4);
	}
	
	//Set flags
	
	//Transfer Error flag
	if(table->TEIF){
		if(table->CHSEL <4){
			if(table->CHSEL <2)
				DMA1->LIFCR |= (1UL<<TEIF_FIELD)<< (6* table->CHSEL);
			else
				DMA1->LIFCR |= (1UL<<TEIF_FIELD)<<(6* table->CHSEL + 4);
	}
		else{
			if(table->CHSEL <6)
				DMA1->HIFCR |= (1UL<<TEIF_FIELD)<<(6* table->CHSEL);
			else
				DMA1->HIFCR |= (1UL<<TEIF_FIELD)<<(6* table->CHSEL + 4);
	}
	}
	//Half Transfer flag
		if(table->HTIF){
		if(table->CHSEL <4){
			if(table->CHSEL <2)
				DMA1->LIFCR |= (1UL<<HTIF_FIELD)<< (6* table->CHSEL);
			else
				DMA1->LIFCR |= (1UL<<HTIF_FIELD)<<(6* table->CHSEL + 4);
	}
		else{
			if(table->CHSEL <6)
				DMA1->HIFCR |= (1UL<<HTIF_FIELD)<<(6* table->CHSEL);
			else
				DMA1->HIFCR |= (1UL<<HTIF_FIELD)<<(6* table->CHSEL + 4);
	}
	}
		
	//Transfer Complete flag
	if(table->TCIF){
		if(table->CHSEL <4){
			if(table->CHSEL <2)
				DMA1->LIFCR |= (1UL<<TCIF_FIELD)<< (6* table->CHSEL);
			else
				DMA1->LIFCR |= (1UL<<TCIF_FIELD)<<(6* table->CHSEL + 4);
	}
		else{
			if(table->CHSEL <6)
				DMA1->HIFCR |= (1UL<<TCIF_FIELD)<<(6* table->CHSEL);
			else
				DMA1->HIFCR |= (1UL<<TCIF_FIELD)<<(6* table->CHSEL + 4);
	}
	}
	DMA_Stream_TypeDef *stream_obj = (DMA_Stream_TypeDef *)stream;
	
	
	
	//Configure CR register 
	stream_obj->CR &= ~((uint32_t)table->EN    << EN_FIELD);    
	
	stream_obj->CR &= ~((uint32_t)table->CHSEL << CHSEL_FIELD); 
	stream_obj->CR |=  ((uint32_t)table->CHSEL << CHSEL_FIELD);  
	stream_obj->CR &= ~((uint32_t)table->PL    << PL_FIELD);  
	stream_obj->CR &= ~((uint32_t)table->MSIZE << MSIZE_FIELD);  
	stream_obj->CR &= ~((uint32_t)table->PSIZE << PSIZE_FIELD);  
	stream_obj->CR |=  ((uint32_t)table->MINC  << MINC_FIELD);  
	stream_obj->CR |=  ((uint32_t)table->PINC  << PINC_FIELD);   
	stream_obj->CR &= ~((uint32_t)table->DIR   << DIR_FIELD);  
	
	
	//Configure mem and periph addresses
	stream_obj->M0AR = table->M0AR;
	stream_obj->PAR  = table->PAR;
	
	//No of items to transfer
	stream_obj->NDTR = table->NDTR;

}

void enable_DMAcontroller(Stream stream){
	DMA_Stream_TypeDef *stream_obj = (DMA_Stream_TypeDef *)stream;
	stream_obj->CR &= 1<< EN_FIELD; 

}