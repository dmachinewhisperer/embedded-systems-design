#include "GPT_drivers.h"

void delay(){
	for(volatile int i = 0; i<50000;i++);

}
int main(){
	
	while(1){
	for(int i = 0; i<=100;i++){
		analogWrite(i); 
		delay();
	
	}
	//reverse
	for(int i = 99; i>=0;i--){
		analogWrite(i); 
		delay();
	
	}
	}
	return 0;

}