/*
 * FreqGen.cpp
 *
 * Created: 10/27/2012 07:43:55
 *  Author: Muchiri John
 */ 
#include "FreqGen.h"
//initialize the frequency generator
//if no value supplied set the frequency to 1Hz
Gen::Gen(uint8_t freq = 10){
	this->setFreq = freq;
	timerCount();	
}

//check if the user input frequency value is within the range
//else set the frequency to 1Hz.
void Gen::frequency(uint8_t freq){
	if(freq > 0 && freq <= 50){
		this->setFreq = freq;
	}else{
		this->setFreq = 1;
	}
	cli();
	timerCount();
	initGen();
}

//set the target timer value.
//prescale of 256.
//Target Timer Count = (Input Frequency / Prescale) / Target Frequency - 1 
void inline Gen::timerCount(){
	this->prescaleVal = (F_CPU / pValue) / this->setFreq -1;
}

//initialize generator
//set timer outputs to output a 10 MHz freq
void Gen::initGen(){
	DDRB |= (1 << 0); // Set LED as output

	TCCR1B |= (1 << WGM12); // Configure timer 1 for CTC mode

	TIMSK1 |= (1 << OCIE1A); // Enable CTC interrupt

	sei(); //  Enable global interrupts

	OCR1A   = this->prescaleVal; // Set CTC compare value to 1Hz at 16MHz.

	TCCR1B |= ((1 << CS10) | (1 << CS11)); // Start timer at F_CPU/256
}

//Timer 1 interrupt 
//toggle the PORTB0 PIN.
ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PORTB0); // Toggle the LED
	
}
