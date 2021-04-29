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
#include "act3.h"
#include "act4.h"
#include <util/delay.h>

int main(void){

    /**
    * @brief A function to setup timer1 with channel A for pulse width modulation with wave generation mode of 10 bits fast PWM and prescaling of 64.
    * 
    */
    TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11);  //setting timer1 for PWM
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);     //8 prescalar
    DDRB|=(1<<PB1);                             //Setting PB1 as output pin

    Buttons_LED_Init();
    InitADC();     //Initialise the ADC
    UARTinit(103);
    
    uint16_t temp;
    char data;
    
    while(1)
    {
    if(SENSOR_ON)                   // Button Sensor ON
    {
            if(HEATER_ON)           // Heater ON
            {
                 SET_LED;           // LED is ON
                temp=ReadADC(0);
                data=PWM(temp);
                UARTwritecharacter(data);
                _delay_ms(20);
            }
             else
            {
                _delay_ms(20);
                OCR1A = 0; //make PWM output 0 if switch is off
                CLEAR_LED;  // LED is OFF
            }
        }
        else
        {
            CLEAR_LED;  // LED is OFF
            OCR1A = 0; //make PWM output 0 if switch is off
            _delay_ms(20);
        }
    }

    return 0;
}

