/*
* seven_segment_basic_drive.c
*
* Created: 8/8/2014 20:24:45
* Author: Muchiri john
* License GPL
*/
#ifndef F_CPU
#define F_CPU 8000000ul
#endif

#include <stdint.h>
#include <util/delay.h>

/*
* initialize port registers
*/
static inline void init_segment()
{
	DDRD = 0xFF;
	PORTD = 0x00;
}

uint8_t code[]=
{
	0b11100111, //0
	0b10000100, //1
	0b11010011, //2
	0b11010110, //3
	0b10110100, //4
	0b01110110, //5
	0b01110111, //6
	0b11000100, //7
	0b11110111, //8
	0b11110110, //9
	0b11010111, //a
	0b00110111, //b
	0b00010011, //c
	0b10010111, //d
	0b11110011, //e
	0b01110001, //f
	0b11110110, //g
	0b00110101, //h
	0b00010101, //n
	0b00010111, //o
};

static inline void write_code(uint8_t pos)
{
	PORTD = code[pos];
}

uint8_t counter= 0;


int main()
{
	init_segment();
	while(1){
		/*write to segment the relevant code*/
		write_code(counter);
		/*set the time interval for displayed characters*/
		_delay_ms(500);

		/*reset counter on overflow*/
		counter >= (sizeof(code)-1) ? counter=0 : counter++;
	}
	return 0;
}
