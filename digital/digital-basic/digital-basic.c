/*
 * digital_basic.c
 *
 * Created: 8/10/2014 22:39:23
 *  Author: Muchiri john
 */

#define F_CPU 8000000L

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "pin.h"

uint8_t on= 0xFF;
uint8_t off= 0x00;

uint8_t counter = 0;


/************************************************************************
* initialization code
************************************************************************/
void init_code()
{
	portSet(D, 0xFF); //set PORTD [D0--D7] as output
}


/************************************************************************
* main function
************************************************************************/
int main()
{
	//init code
	init_code();
	//loop forever
	while(1){
		portWrite(D, on); //PORTD ON
		_delay_ms(500); //delay 500ms
		portWrite(D, off); //PORTD OFF
		_delay_ms(500); //delay 500ms
	}
	return 0;
}