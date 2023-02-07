#include "stm32f429xx.h"
#include <stdint.h>

/*RCC Register bit fields*/
#define DMA1_CLK_FIELD 21

/*CR Register bit fields*/

#define EN_FIELD       0
#define DIR_FIELD      6
#define PINC_FIELD     9
#define MINC_FIELD     10
#define PSIZE_FIELD    11
#define MSIZE_FIELD    13
#define PL_FIELD       16
#define CHSEL_FIELD    25

/*Flags bit fields*/
#define TEIF_FIELD     3    
#define HTIF_FIELD     4
#define TCIF_FIELD     5

typedef enum{
  stream0 = DMA1_Stream0_BASE,
	stream1 = DMA1_Stream1_BASE,
	stream2 = DMA1_Stream2_BASE,
	stream3 = DMA1_Stream3_BASE,
	stream4 = DMA1_Stream4_BASE,
	stream5 = DMA1_Stream5_BASE,
	stream6 = DMA1_Stream6_BASE,
	stream7 = DMA1_Stream7_BASE
} Stream;

typedef struct{
	char EN;
	char CHSEL;
	char DIR;
	char CIRC;
	char PINC;
	char MINC;
	char PSIZE;
	char MSIZE;
	char PL;
	char M0AR;
	char HTIF;
	char TCIF;
	char TEIF;
	uint32_t PAR;
	uint32_t NDTR;
}config_table;

static void initialize_DMAcontroller( Stream stream, config_table* table ){
	
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

static void enable_DMAcontroller(Stream stream){
	DMA_Stream_TypeDef *stream_obj = (DMA_Stream_TypeDef *)stream;
	stream_obj->CR &= 1<< EN_FIELD; 

}