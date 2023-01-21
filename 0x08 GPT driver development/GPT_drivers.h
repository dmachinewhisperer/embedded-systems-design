#include <stdint.h>



/*
@ brief: Outputs Square waveform on PE9
@ return: void
@ params: 
T: period of waveform
*/
void sqWave(uint8_t T);

/*
@ brief: Outputs PWM waveform on PE9
@ return: void
@ params: 
dutyCycle: Duty cycle of waveform => 0 - 100%
freq: frequency of PWM
*/
void analogWrite(uint8_t dutyCycle, uint8_t freq = 100);