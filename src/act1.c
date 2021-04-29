/**
 * @file act1.c
 * @author Namratha
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>
#include "act1.h"

/**
 * @brief A function to operate the button and heater sensor
 * 
 */
void Buttons_LED_Init()
{
     /*Configure LED and Switch pins*/
    DDRD|=(1<<PD6);
    DDRD&=~(1<<PD0);
    PORTD|=(1<<PD0);
    DDRD&=~(1<<PD4);
    PORTD|=(1<<PD4);
}