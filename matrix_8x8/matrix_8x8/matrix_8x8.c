/*
 * matrix_8x8.c
 *
 * Created: 7/31/2014 17:12:13
 *  Author: Muchiri John
 */ 



#include <avr/io.h>
#define F_CPU 8000000L /*CPU frequency*/
#include <util/delay.h>

#include "pin.h"
#include "font_5x7.h"


#define data_pin 14
#define clock_pin 16
#define latch_pin 15

/*Clears display*/
static inline void clear(){
	//clear all data.//////////////////////////////////////
	uint8_t bit=0;
	PORTD = 0x00;
	pinWrite(latch_pin, LOW);
	for(bit = 0; bit < 8 ; bit++){
		pinWrite(data_pin, 0);// & (1  << (7 - bit)));
		//toggle the clock pin
		pinWrite(clock_pin, HIGH);
		pinWrite(clock_pin, LOW);
	}
	pinWrite(latch_pin, HIGH);
	////////////////////////////////////////////////////////
}
/************************************************************************/
/* Display data                                                         */
/************************************************************************/
static inline void Display(unsigned char data)
{
	uint8_t index, bit = 0;
	uint16_t pos = ((uint8_t)(data - ' ') * 5); /*get array location of the char*/
	uint8_t *byte = &font_5x7[pos]; /*get the adrress where the byte of the char starts*/
	//output byte
	for(index=0; index<8; index++){
		pinWrite(latch_pin, LOW); /*receive data*/
		for(bit = 0; bit <5 ; bit++){
			pinWrite(data_pin, (*(byte+bit) & (1 << index))); /*shift out data*/
			pinWrite(clock_pin, HIGH); /*toggle the clock pin*/
			pinWrite(clock_pin, LOW);
		}
		pinWrite(latch_pin, HIGH); /*end reception*/

		PORTD = ((1<<index) & 0xFF); /*multiplex data*/
		_delay_ms(1);  /*give time to settle*/
		clear(); /*clear display*/
	}
	_delay_ms(1);
}

/*Hold char on the display*/
static inline void hold(unsigned char ch, uint16_t time){
	uint16_t x;
	for(x=0; x<time;x++)
	Display(ch);
}

static inline void init_matrix()
{
	DDRD = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x00;
	PORTD = 0x00;	
}

static inline void row_shift()
{
	uint8_t x, y, z;
	for(x=0; x<8; x++) //row
	{ 
		PORTB = (1 << x);
		for(z=0; z<15;z++){
			for(y=0; y<8; y++) //column
				{
					PORTD = ~(1 << y);
					_delay_ms(2);
				}
			//_delay_ms(10);
		}
		//_delay_ms(500);
	}
}

static inline void column_shift()
{
	uint8_t x, y, z;
	for(x=0; x<8; x++) //row
	{
		PORTD = ~(1 << x);
		for(z=0; z<15;z++){
			for(y=0; y<8; y++) //column
			{
				PORTB = (1 << y);
				_delay_ms(2);
			}
		}
		//_delay_ms(500);
	}
}

int main(void)
{

	init_matrix();
	while(1)
	{
		row_shift();
		column_shift();
	}
}