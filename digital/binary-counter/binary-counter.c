/*
 * binary_counter.c
 *
 * Created: 8/10/2014 23:26:23
 *  Author: Muchiri John
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "pin.h"

uint8_t byt = 0;

void init_code()
{
	portSet(D, 0xFF);
}

int main()
{
	for(byt=0; byt<=255; byt++)
	{
		portWrite(D, byt);
		_delay_ms(250);
	}
	return 0;
}