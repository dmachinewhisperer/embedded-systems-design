#include <stdint.h>
#include "GPIO_registers.h"
typedef struct{
		volatile uint32_t GPIOx_MODER;
		volatile uint16_t GPIOx_OTYPER;
		volatile uint16_t GPIOx_OTYPER_R;
		volatile uint32_t GPIOx_OSPEEDR;
		volatile uint32_t GPIOx_PUPDR;
		volatile uint16_t GPIOx_IDR;
		volatile uint16_t GPIOx_IDR_R;
		volatile uint16_t GPIOx_ODR;
		volatile uint16_t GPIOx_ODR_R;
		volatile uint32_t GPIOx_BSRR;
		volatile uint32_t GPIOx_LCKR;
		volatile uint32_t GPIOx_AFRL;
		volatile uint32_t GPIOx_AFRH;
		
		
	}GPIO_Reg_def;

GPIO_Reg_def* Register_Structure(GPIO){
	
	GPIO_Reg_def * inst1;
	return inst1;

}