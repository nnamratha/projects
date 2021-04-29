/**
 * @file act2.h
 * @author Namratha 
 * @brief 
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ACT2_H_INCLUDED
#define ACT2_H_INCLUDED

#include<avr/io.h>

/**
 * @brief to read the adc values
 * 
 */
uint16_t ReadADC(uint8_t ch);

/**
 * @brief initialise the analog to digital converter
 * 
 */
void InitADC();

#endif // ACT2_H_INCLUDED
