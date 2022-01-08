/*
 * blinky.c
 *
 * Created: 8/11/2014 17:49:07
 *  Author: Muchiri john
 */ 


#include <sketch.h>
#include <pin.h>


void init_code()
{
	pinSet(D0, OUTPUT);
}

void main_code()
{
	
	pinWrite(D0, HIGH);
	_delay_ms(1000);
	pinWrite(D0, LOW);
	_delay_ms(1000);
}