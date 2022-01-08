/*
 * led_chaser.c
 *
 * Created: 8/10/2014 22:42:36
 *  Author: Muchiri john
 */ 

#include <sketch.h>
#include <pin.h>

uint8_t byt = 1;
uint8_t counter = 0;

void init_code()
{
	portSet(D, 0xFF);
}

void main_code()
{
	for(byt = 0; byt<=7; byt++)
	{
		portWrite(D, (1 << byt));
		_delay_ms(250);
	}
	
	for(byt = 0; byt<=7; byt++)
	{
		portWrite(D, (0x80 >> byt));
		_delay_ms(250);
	}
	
	for(byt=0; byt<=255; byt++)
	{
		portWrite(D, byt);
		_delay_ms(250);
	}
}