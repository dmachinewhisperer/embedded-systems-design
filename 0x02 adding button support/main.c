#include "Board_LED.h"
#include <stdint.h>
#include "Board_Buttons.h"


//Simulate a delay
void delay(void){
	
for(volatile uint32_t i = 0;i<500000;i++);
	
}
int main(void){
	
	LED_Initialize();
	Buttons_Initialize();

	//Turn ON and OFF the two onboard LEDS	upon Button press
	while(1){
	if(Buttons_GetState()){	
	
	LED_On(0U);
	delay();
	LED_Off(0U);
  delay();		
	LED_On (1U);  
	delay();
	LED_Off(1U);

}
}
	return 0;
}
