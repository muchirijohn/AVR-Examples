/*
 * usart_test.c
 *
 * Created: 9/9/2014 17:24:03
 *  Author: Muchiri Mercy
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include "usart.h"

int main(void)
{
	usart_init(9600);

    while(1)
    {
       while(usart_available() > 0) 
	   {
		   unsigned char ch= (unsigned char)usart_read();
		   usart_Transmit(ch);
		   if(ch == '\n') usart_puts("\n\r");
	   }
    }
}