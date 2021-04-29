/**
 * @file act1.h
 * @author Namratha (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "act1.h"
#include "act2.h"
#include <util/delay.h>

int main(void){
/**
 * @brief A function to setup timer1 with channel A for pulse width modulation with wave generation mode of 10 bits fast PWM and prescaling of 64.
 * 
 */
    TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11);  //setting timer1 for PWM
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);     //8 prescalar
    DDRB|=(1<<PB1);                             //Setting PB1 as output pin

    InitADC();     //Initialise the ADC
    ports_initial();
    UARTinit(103);
    uint16_t temp;
    char data;
    while(1)
    {
    if(!(PIND&(1<<PD0)))            // Button Sensor ON
    {
            if(!(PIND&(1<<PD4)))    // Heater ON
            {
                PORTD|=(1<<PD6);    // LED is ON
                temp=ReadADC(0);
                data=PWM(temp);
                UARTwritecharacter(data);
                _delay_ms(20);
            }
             else
            {
                 _delay_ms(20);
                OCR1A = 0; //make PWM output 0 if switch is off
                PORTD&=~(1<<PD6);  // LED is OFF
            }
        }
        else
        {
            PORTD&=~(1<<PD6);  // LED is OFF
            OCR1A = 0; //make PWM output 0 if switch is off
            _delay_ms(20);
        }
    }

    return 0;
}

void ports_initial(void)
{
    /*Configure LED and Switch pins*/
    DDRD|=(1<<PD6);
    DDRD&=~(1<<PD0);
    PORTD|=(1<<PD0);
    DDRD&=~(1<<PD4);
    PORTD|=(1<<PD4);
    InitADC();

}
