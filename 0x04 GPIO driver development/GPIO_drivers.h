#include <stdint.h>

#define IN   0b00
#define OUT  0b01
#define ALT  0b10
#define ANLG 0b11
#define HIGH 0b01
#define LOW  0b00

/*
@ brief: Writes STATE to the designated PIN, in the designated PORT
@ return: void
@ params: 
PIN: pin to write.
PORT: port to write. Default is 'A'
STATE: HIGH or LOW. 
*/
void digitalWrite(int PIN, uint32_t STATE, char PORT = 'A');

/*
@ brief: Reads STATE to the designated PIN, in the designated PORT 
@ return: int denoting STATE of PIN
@ params
PIN: pin to read
PORT: port to read. Default is 'A'
*/
int digitalRead(int PIN, char PORT = 'A');
	
/*
@ brief: Configures PIN the specified PORT
@ return: void
@ params
PIN: pin to conigure
MODER: mode of PIN => OUT, IN, ALT or ANLG. 
PORT: port to configure. Default is 'A'
OTYPER: output type. Default is Output push-pull(0)
OSPEEDR: output speed. Default is low-speed(00)
PUPDR: pull-up/down: Default is no pull-up, no pull-down(00)
*/	
void pinMode(int PIN, uint32_t MODER, char PORT = 'A', uint32_t OTYPER = 0b00, uint32_t OSPEEDR = 0b00, uint32_t PUPDR = 0b00);