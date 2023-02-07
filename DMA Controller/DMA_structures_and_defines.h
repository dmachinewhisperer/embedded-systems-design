#include "stm32f429xx.h"


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

typedef enum{
	TEIF = 0,
	HTIF = 1,
	TCIF = 2,
} Flags;

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