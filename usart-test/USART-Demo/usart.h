/*
 * usart.h
 *
 * Created: 12/9/2013 05:58:40
 *  Author: Mercy Muchiri
 */ 


#ifndef USART_H_
#define USART_H_



#ifdef __cplusplus
extern "C"{
#endif

#include <avr/interrupt.h>
#include "LightweightRingBuff.h"

RingBuff_t rx_buff;
RingBuff_t tx_buff;

//init usart
static inline void usart_init(double baud){
	uint16_t ubrr;
	double ub = (F_CPU/(baud * 16)) - 1;
	/*initialize buffers*/
	RingBuffer_InitBuffer(&rx_buff);
	RingBuffer_InitBuffer(&tx_buff);
	
	ubrr = (uint16_t)ub;//(F_CPU/16/baud)-1;////(F_CPU/(baud * 16)) - 1;
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr;
	
	//UCSR0A = (1 << RXC0) | (1 << TXC0);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0) | (1 << RXCIE0);// | (1 << TXCIE0);
	/* Set frame format: 8data, 1 stop bit */
	UCSR0C = (1<<UCSZ00) |(1 << UCSZ01);
	//cli();
	sei();
}

//transmit char to usart, tx
static inline void usart_Transmit(uint8_t data )
{
	RingBuffer_Insert(&tx_buff, data);
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)));
	/* Put data into buffer, sends the data */
	if(!RingBuffer_IsEmpty(&tx_buff))
		UDR0 = (uint8_t)RingBuffer_Remove(&tx_buff);//(char)data;
}

//check if there is available data
uint8_t usart_available(){
	return (!(RingBuffer_IsEmpty(&rx_buff)));
}
//store received data in the buffer
static inline void store_rx(uint8_t data){
	RingBuffer_Insert(&rx_buff, data);
}



static inline uint8_t usart_read(){
	//if(!usart_available())
	return (uint8_t)RingBuffer_Remove(&rx_buff);
}
static inline void usart_puts(char *p){	while(*p){		usart_Transmit(*p);		p++;	}}

ISR(USART_RX_vect)
{
	//while ( !(UCSR0A & (1<<RXC0)) )
	//;
	/* Get and return received data from buffer */
	store_rx((uint8_t)UDR0);
}
/*

ISR(USART_TX_vect)
{
	/ * Wait for empty transmit buffer * /
	/ *while ( !( UCSR0A & (1<<UDRE0)));* /
	/ *check if there is still data in the buffer and transmit it* /
	if(!RingBuffer_IsEmpty(&tx_buff))
		UDR0 = (uint8_t)RingBuffer_Remove(&tx_buff);//(char)data;
}*/
//#endif
#ifdef __cplusplus
}
#endif

#endif /* USART_H_ */