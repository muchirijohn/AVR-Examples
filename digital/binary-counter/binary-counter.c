/*
 * binary_counter.c
 *
 * Created: 8/10/2014 23:26:23
 *  Author: Muchiri John
 */ 

#include <sketch.h>
#include <pin.h>

uint8_t byt = 0;

void init_code()
{
	portSet(D, 0xFF);
}

void main_code()
{
	for(byt=0; byt<=255; byt++)
	{
		portWrite(D, byt);
		_delay_ms(250);
	}
}