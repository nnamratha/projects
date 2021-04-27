/**
 * @file blinky.h
 * @author Namratha (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "blinky.h"

int main(void)
{
DDRB|=(1<<PB0);   //SETTING PB0=1 for led
DDRD&=~(1<<PD0);  // forcefully making it 0
PORTD|=(1<<PD0);  // setting the bit
DDRD&=~(1<<PD4);  // forcefully making it 0
PORTD|=(1<<PD4);  // setting the bit

    while(1){
            if(!(PIND&(1<<PD0))) // pressing switch
            {
                if(!(PIND&(1<<PD4))){
                        PORTB|=(1<<PB0);

                }

                else{
                        PORTB&=~(1<<PB0);

                }

            }
            else{
                    PORTB&=~(1<<PB0);

            }

    }


    return 0;
}

