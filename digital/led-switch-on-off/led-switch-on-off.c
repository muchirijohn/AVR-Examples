/*
 * led_switch_on_off.c
 *
 * Created: 8/10/2014 23:31:55
 *  Author: Muchiri john
 */


#define F_CPU 8000000L

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "pin.h"

uint8_t read_value = 0;


/************************************************************************
* initialization code
************************************************************************/
void init_code()
{
	//set PINC0 to input
	pinSet(C0, INPUT);
	//activate pull up on C0
	activatePullUp(C0);
	//set D0 as output
	pinSet(D0, OUTPUT);
	//set D1 as output
	pinSet(D1, OUTPUT);
}



/************************************************************************
* main function
************************************************************************/
int main()
{
	//init
	init_code();
	while(1){
		//set D0 status to C0 input state [not-state]
		pinWrite(D0, pinRead(C0));
		//set D1 status to C0 input state
		pinWrite(D1, !pinRead(C0));
	}

	return 0;
}