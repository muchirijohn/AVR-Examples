/*
 * binary_counter.c
 *
 * Created: 8/10/2014 23:26:23
 * Author: Muchiri John
 * Built for ATmega88, 168 and 328p
 */

#define F_CPU 8000000L

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "pin.h"

uint8_t byt = 0;

/************************************************************************/
/* initializing code */
/************************************************************************/
void init_code()
{
	portSet(D, 0xFF);
}

/************************************************************************/
/* main function */
/************************************************************************/
int main()
{
	//init
	init_code();
	//loop forever
	while(1){
		for(byt=0; byt<=255; byt++)
		{
			portWrite(D, byt);
			_delay_ms(250);
		}
	}
	return 0;
}