/*
 * led_chaser.c
 *
 * Created: 8/10/2014 22:42:36
 *  Author: Muchiri john
 * built for atmega88, 168 and 328p
 */


#define F_CPU 8000000L

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "pin.h"

uint8_t byt = 1;
uint8_t counter = 0;


/************************************************************************
* initialization code
************************************************************************/
void init_code()
{
	portSet(D, 0xFF); //set PORTD to output
}

/************************************************************************
* main function
************************************************************************/
int main()
{
	//init
	init_code();
	//loop forever
	while(1){
		//led chaser
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
	return 0;
}