/**
 * @file act3.c
 * @author Namratha
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include<act3.h>

/**
 * @brief A function which receives 10 bit of ADC input from temperature sensor and outputs as a fast PWM waveform.
 * 
 * @param tem
 * @return char
 */
char PWM(uint16_t tem){

    char temperature;

    if((tem>=0) && (tem<=209)){
        //20% duty cycle
        OCR1A = 205;
        temperature = 20;
        _delay_ms(20);
    }
    else if((tem>=210) && (tem<=509)){
        //40% duty cycle
        OCR1A = 410;
        temperature = 25;
        _delay_ms(20);
    }
    else if((tem>=510) && (tem<=709)){
        //70% duty cycle
        OCR1A = 717;
        temperature = 29;
        _delay_ms(20);
    }
    else if((tem>=710) && (tem<=1024)){
        //95% duty cycle
        OCR1A = 973;
        temperature = 33;
        _delay_ms(20);
    }
    else{
        //0% output
        OCR1A = 0;
        temperature = 0;
    }
    return temperature;

}
