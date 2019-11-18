// Traffic light project prototype with AVR microcontroller
// Created by Embedotronics Technologies.
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

int main()
{
	unsigned int ch[]={0x90,0x80,0xF8,0x82,0x92,0x99,0xB0,0xA4,0xF9,0xC0};
	unsigned int i;
	DDRC=0xFF;
	DDRA=0xFF;
	DDRB=0xFF;
	DDRD=0xFF;
	PORTA=(1<<5);
	PORTB=(0<<5);
	PORTD=(0<<5);

	while(1)
	{
		for(i=0;i<10;i++)
		{
			PORTC=ch[i];
			_delay_ms(1000);
		}
		PORTA=(0<<5);
		PORTB=(0<<5);
		PORTD=(1<<5);

		for(i=6;i<10;i++)
		{
			PORTC=ch[i];
			_delay_ms(1000);
		}
		PORTA=(0<<5);
		PORTB=(1<<5);
		PORTD=(0<<5);
		for(i=0;i<10;i++)
		{
			PORTC=ch[i];
			_delay_ms(1000);
		}
		
		PORTA=(0<<5);
		PORTB=(0<<5);
		PORTD=(1<<5);
		for(i=6;i<10;i++)
		{
			PORTC=ch[i];
			_delay_ms(1000);
		}
		PORTA=(1<<5);
		PORTB=(0<<5);
		PORTD=(0<<5);
	}
}
