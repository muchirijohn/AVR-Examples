/*
 * blinky.c
 *
 * Created: 8/11/2014 17:49:07
 *  Author: Muchiri john
 */


#define F_CPU 8000000L

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "pin.h"

/************************************************************************
* initialization code
************************************************************************/
void init_code()
{
	pinSet(D0, OUTPUT);
}

/************************************************************************
* main function
************************************************************************/
int main()
{
	//init code
	init_code();
	//loop
	while(1){
		pinWrite(D0, HIGH); //set pin PIND0 ON
		_delay_ms(1000); //delay 1000 ms
		pinWrite(D0, LOW); //set pin PIND0 OFF
		_delay_ms(1000); //delay 1000ms
	}
	return 0;
}