/*
 * led_switch_on_off.c
 *
 * Created: 8/10/2014 23:31:55
 *  Author: Muchiri john
 */


#include <sketch.h>
#include <pin.h>

uint8_t read_value = 0;

void init_code()
{
	pinSet(C0, INPUT);
	activatePullUp(C0);

	pinSet(D0, OUTPUT);
	pinSet(D1, OUTPUT);
}

void main_code()
{

	pinWrite(D0, pinRead(C0));
	pinWrite(D1, !pinRead(C0));
}