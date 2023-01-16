#include "Board_LED.h"
#include <stdint.h>

//Simulate a delay
void delay(void){
	
for(volatile uint32_t i=0; i<500000;i++);
	
}

int main(void){
	
	
	LED_Initialize();
	
	//Repeatedly turn ON and OFF the two onboard LEDS	
	while(1){	
	LED_On(0U);
	delay();
	LED_Off(0U);
  delay();		
	LED_On (1U);  
	delay();
	LED_Off(1U);
	delay();
		
	}
	
	return 0;
}