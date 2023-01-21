#include <stdint.h>

typedef struct{
	volatile uint32_t RCC_CR;                       //0x00
	volatile uint32_t RCC_PLLCFGR;                  //0x04
	volatile uint32_t RCC_CFGR;                     //0x08
	volatile uint32_t RCC_CIR;                      //0x0C
	volatile uint32_t RCC_AHB1RSTR;                 //0X10
	volatile uint32_t RCC_AHB2RSTR;                 //0X14
	volatile uint32_t RCC_AHB3RSTR;                 //0X18
	volatile uint32_t RESERVED0;                    //0X1C
	volatile uint32_t RCC_APB1RSTR;                 //0x20
	volatile uint32_t RCC_APB2RSTR;                 //0x24
	volatile uint32_t RESERVED1;                    //0x28
	volatile uint32_t RESERVED2;                    //0x2C
	volatile uint32_t RCC_AHB1ENR;                  //0x30
	volatile uint32_t RCC_AHB2ENR;                  //0x34
	volatile uint32_t RCC_AHB3ENR;                  //0x38
	volatile uint32_t RESERVED3;                    //0x3C
	volatile uint32_t RCC_APB1ENR;                  //0x40
	volatile uint32_t RCC_APB2ENR;                  //0x44
	volatile uint32_t RESERVED4;                    //0x48
	volatile uint32_t RESERVED5;                    //0x4C
	volatile uint32_t RCC_AHB1LPENR;                //0x50
	volatile uint32_t RCC_AHB2LPENR;                //0x54
	volatile uint32_t RCC_AHB3LPENR;                //0x58
	volatile uint32_t RESERVED6;                    //0x5C
	volatile uint32_t RCC_APB1LPENR;                //0x60
	volatile uint32_t RCC_APB2LPENR;                //0x64
	volatile uint32_t RESERVED7;                    //0x68
	volatile uint32_t RESERVED8;                    //0x6C
	volatile uint32_t RCC_BDCR;                     //0x70
	volatile uint32_t RCC_CSR;                      //0x74
	volatile uint32_t RESERVED9;                    //0x78
	volatile uint32_t RESERVED10;                   //0x7C
	volatile uint32_t RCC_SSCGR;                    //0x80
	volatile uint32_t RCC_PLLI2SCFGR;               //0x84
	volatile uint32_t RCC_PLLSAICFGR;               //0x88
	volatile uint32_t RCC_DCKCFGR;	                //0x8C

}RCC_;

#define RCC ((RCC_*)0x40023800)