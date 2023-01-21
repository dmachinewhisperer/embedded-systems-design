#include <stdint.h>

typedef struct{
		volatile uint32_t GPIOx_MODER;                //0x00
		volatile uint32_t GPIOx_OTYPER;               //0x04
		//volatile uint16_t GPIOx_OTYPER_R;
		volatile uint32_t GPIOx_OSPEEDR;              //0x08
		volatile uint32_t GPIOx_PUPDR;                //0x0C
		volatile uint32_t GPIOx_IDR;                  //0x10
		//volatile uint16_t GPIOx_IDR_R;
		volatile uint32_t GPIOx_ODR;                  //0x14
		//volatile uint16_t GPIOx_ODR_R;                 
		volatile uint32_t GPIOx_BSRR;                 //0x18
		volatile uint32_t GPIOx_LCKR;                 //0x1C
		volatile uint32_t GPIOx_AFRL;                 //0x20
		volatile uint32_t GPIOx_AFRH;                 //0x24
		
		
	}GPIO_RegDef;

#define GPIOA ((GPIO_RegDef*) 0x40020000)
#define GPIOB ((GPIO_RegDef*) 0x40020400)
#define GPIOC ((GPIO_RegDef*) 0x40020800)
#define GPIOD ((GPIO_RegDef*) 0x40020C00)
#define GPIOE ((GPIO_RegDef*) 0x40021000)
#define GPIOF ((GPIO_RegDef*) 0x40021400)
#define GPIOG ((GPIO_RegDef*) 0x40021800)	
#define GPIOH ((GPIO_RegDef*) 0x40021C00)	
#define GPIOI ((GPIO_RegDef*) 0x40022000)
#define GPIOJ ((GPIO_RegDef*) 0x40022400)	
#define GPIOK ((GPIO_RegDef*) 0x40022800)	