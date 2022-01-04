/*
 * FreqGen.cpp
 *
 * Created: 10/27/2012 07:42:57
 *  Author: mercy
 */ 


#include <avr/io.h>
#include "FreqGen.h"

int main(void)
{
	Gen Fg(20);
	Fg.frequency(30);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}