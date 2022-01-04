/*
 * FreqGen.h
 *
 * Created: 10/27/2012 07:44:12
 *  Author: John Muchiri
 *	(c) 2012 John.M
 * 1 t0 50 frequency generator.
 */ 


#ifndef FREQGEN_H_
#define FREQGEN_H_

#include <avr/io.h>
#include <avr/interrupt.h>

//prescale value
#define pValue 256

class Gen{
	private:
	 uint8_t setFreq;	
	 uint16_t prescaleVal;
	 void inline timerCount();
	public:
	 Gen(uint8_t);
	 void frequency(uint8_t);
	 void initGen();
};


#endif /* FREQGEN_H_ */