#define F_CPU 16000000
#define BAUD 9600
#include <util/setbaud.h>
#include "DEF_ATMEGA328P.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"

#define set_bit(sfr, bit)	(_SFR_BYTE(sfr) |= _BV(bit))
#define clear_bit(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))

#define T_beep 220

int main(void)
{

	set_bit(DDRB, 5);	//PIN OUTPUT
    set_bit(DDRD, 2);	//PIN OUTPUT
    

	TCCR0B |= (1<<CS02);	//MODE TIMER PRE 8
	TCCR0B &= ~(1<<CS01);
	TCCR0B &= ~(1<<CS00);		
	
	
	TCNT0 = 0;
	
	//MODE CTC
	TCCR0B &= ~(1<<WGM02);
	TCCR0A |= (1<<WGM01);
	TCCR0A &= ~(0<<WGM00);


	//INTERRUP IN PIN OC0A
	clear_bit(TCCR0A, COM0A0);
	clear_bit(TCCR0A, COM0A1);
	
	
	//INTERRUP IN PIN OC0B
	clear_bit(TCCR0A, COM0B0);
	clear_bit(TCCR0A, COM0B1);
	
	TIMSK0 |= (1<<OCIE0A);
	TIMSK0 |= (1<<OCIE0B);
   
	UART_init();
    uint8_t dato=0;
	
     while (1) 
    {
		 
         dato = UART_read();
        
		
		if(dato != 0)
		{
            
			switch(dato) 
			{
             
                
				case 'Q':
                   // printf("DO\n\r");
                    set_bit(SREG, 7);
					OCR0A = 239;
                    OCR0B = 120;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
                    
				break;
				
				case 'W':
				//	printf("RE\n\r");
                    set_bit(SREG, 7);
					OCR0A = 212;
                    OCR0B = 106;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
				break;
				
				case 'E':
                   // printf("MI\n\r");
                    set_bit(SREG, 7);
					OCR0A = 188;
                    OCR0B = 94;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
				break;
				
				case 'R':
                   // printf("FA\n\r");
                    set_bit(SREG, 7);
					OCR0A = 178;
                    OCR0B = 89;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
				break;
				
				case 'T':
                    //printf("SOL\n\r");
                    set_bit(SREG, 7);
					OCR0A = 158;
                    OCR0B = 79;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
				break;
				
				case 'Y':
                   // printf("LA\n\r");
                    set_bit(SREG, 7);
					OCR0A = 140;
                    OCR0B = 70;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
                    
				break;
                
				case 'U': 
                    //printf("SI\n\r");
                    set_bit(SREG, 7);
					OCR0A = 126;
                    OCR0B = 63;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;   
				break;
                
				case 'A':
                   // printf("DO^2\n\r");
                    set_bit(SREG, 7);
					OCR0A = 118;
                    OCR0B = 59;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
				break;
                case 'S':
                   // printf("RE^2\n\r");
                    set_bit(SREG, 7);
					OCR0A = 105;
                    OCR0B = 53;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
				break;
                case 'D':
                   // printf("MI^2\n\r");
                    set_bit(SREG, 7);
					OCR0A = 94;
                    OCR0B = 47;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
				break;
                case 'F':
                   // printf("FA^2\n\r");
                    set_bit(SREG, 7);
					OCR0A = 88;
                    OCR0B = 44;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                    PORTBbits.PB5_ = 0;
				break;
                case 'G':
                   // printf("SOL^2\n\r");
                    set_bit(SREG, 7);
					OCR0A = 79;
                    OCR0B = 40;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                     PORTBbits.PB5_ = 0;
				break;
                case 'H':
                   // printf("LA^2\n\r");
                    set_bit(SREG, 7);
					OCR0A = 70;
                    OCR0B = 35;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                     PORTBbits.PB5_ = 0;
				break;
                case 'J':
                   // printf("SI^2\n\r");
                    set_bit(SREG, 7);
					OCR0A = 62;
                    OCR0B = 31;
                    _delay_ms(T_beep);
                    clear_bit(SREG,7);
                     PORTBbits.PB5_ = 0;
				break;
			}
		}
		
    }
}
ISR(TIMER0_COMPA_vect)
{
	PORTBbits.PB5_ = 1;
}

ISR(TIMER0_COMPB_vect)
{
	PORTBbits.PB5_ = 0;
}