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



int main(void){
    InitADC();
    ports_initial();
    uint16_t temp;
    while(1)
    //if switch 1 is ON
    if(!(PIND&(1<<PD0)))
        {
            //if switch 2 is ON
            if(!(PIND&(1<<PD4)))
            {
                PORTD|=(1<<PD6);  // LED ON
                temp=ReadADC(0);
            }
        }
        else
        {
            PORTD&=~(1<<PD6);   // LED OFF
        }

    return 0;
}

/*
Initializing the ports
*/

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

