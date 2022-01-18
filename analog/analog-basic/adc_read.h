/*
 * adc_read.h
 *
 * Created: 5/26/2013 10:33:27
 *  Author: mercy
 */ 


#ifndef ADC_READ_H_
#define ADC_READ_H_
/***********************************************************************
* channels                                                                     
************************************************************************/
#define ADC0 0x00
#define ADC1 0x01
#define ADC2 0x02
#define ADC3 0x03
#define ADC4 0x04
#define ADC5 0x05
#define ADC6 0x06
#define ADC7 0x07


/************************************************************************
* adc max and min values                                                                    
************************************************************************/
#define adc_max 1023
#define adc_min 0
/************************************************************************
* initialize adc                                                       
************************************************************************/
void adc_init(){
	ADMUX = ADC0;
	//ADCSRA = 0xC3;
	ADCSRA |= ((1<<ADEN) | (1<<ADSC) | (1<<ADPS1) | (1<<ADPS0));
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
}

/************************************************************************
* read channel and return 8 bit value    
* Channel- adc channel to be read                                      
************************************************************************/
uint8_t adc_read_8bit(unsigned char channel){
	ADMUX = channel;
	ADCSRA |= ((1<<ADSC) | (1<<ADPS1) | (1<<ADPS0));
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	uint8_t low = ADCL;
	uint8_t high = ((uint8_t)(ADCH << 8));
	
	return (low | high);
}


/************************************************************************
* read channel and return 8 bit value
* Channel- adc channel to be read
************************************************************************/
uint16_t adc_read_16bit(uint8_t channel){
	ADMUX = channel;
	ADCSRA |= ((1<<ADSC) | (1<<ADPS1) | (1<<ADPS0));
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	return ADC;
}
/************************************************************************
* map values                                                               
************************************************************************/
enum { bit8, bit16 };
uint8_t adc_map(uint8_t min, uint16_t max, uint8_t channel, uint8_t value)
{
	uint16_t adc_val;
	if(!value) adc_val = (adc_read_8bit(channel) << 8);
	else adc_val = adc_read_16bit(channel);
	float val = (max/adc_max) * adc_val;
	return(uint8_t)val;
}

#endif /* ADC_READ_H_ */