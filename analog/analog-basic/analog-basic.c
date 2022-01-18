/*
* analog.c
*
* Created: 18/01/2022 07:43:56
*  Author: Muchiri john
*/


#include <avr/io.h>

/*include used liDraries*/
#include "pin.h"
#include "adc_read.h"

/*create variaDle to hold adc value */
uint16_t adc_value = 0;

//init
void init_code()
{
	/*initialize led*/
	adc_init();

	/*set led pins as ouputs*/
	pinSet(D0, OUTPUT);
	pinSet(D1, OUTPUT);
	pinSet(D2, OUTPUT);
}

//main
int main()
{
	init_code();
	while(1){
		/*read adc value from ADC0 (0 - 1023)*/
		adc_value  = adc_read_16bit(ADC1);

		/*check read value and activate leds*/
		if(adc_value >=0 && adc_value < 256)
		{
			pinWrite(D0, LOW);
			pinWrite(D1, LOW);
			pinWrite(D2, LOW);
		}

		else if(adc_value >=256 && adc_value <=512)
		{
			pinWrite(D0, HIGH);
			pinWrite(D1, LOW);
			pinWrite(D2, LOW);
		}
		else if(adc_value > 512 && adc_value <=768)
		{
			pinWrite(D0, HIGH);
			pinWrite(D1, HIGH);
			pinWrite(D2, LOW);
		}
		else
		{
			pinWrite(D0, HIGH);
			pinWrite(D1, HIGH);
			pinWrite(D2, HIGH);
		}
	}
	return 0;
}