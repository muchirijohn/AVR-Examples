/*
 * digital_basic.c
 *
 * Created: 8/10/2014 22:39:23
 *  Author: Muchiri john
 */ 


#include <sketch.h>
#include <pin.h>

uint8_t on= 0xFF;
uint8_t off= 0x00;

uint8_t counter = 0;

void init_code()
{	
	portSet(D, 0xFF);
}

void main_code()
{
	portWrite(D, on);
	_delay_ms(500);
	portWrite(D, off);
	_delay_ms(500);
}