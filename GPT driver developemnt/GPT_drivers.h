
/*
@ brief: Outputs square Waveform on PE9
@ return: void
@ params: 
T: period of waveform
fixed constants: 
f0 = 16MHz, f = 2KHz, PSC = 7999, CCR = 666
*/


void sqWave(uint8_t T = 1, uint16_t PSC = 0x1F3F );
	
/*
@ brief: Outputs a PWM signal on PE9
@ return: void
@ params: 
dutyCycle: duty cycle of PWM wave
f: period of waveform
fixed constants: 
f0 = 16MHz, f = 100KHz, PSC = 79
*/
analogWrite(uint8_t dutyCycle, uint16_t freq = 100);