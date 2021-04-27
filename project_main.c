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
// #include "project_config.h"

// #include "user_utils.h"
// #include "blinky.h"

// /**
//  * @brief Initialize all the Peripherals and pin configurations
//  * 
//  */
// void peripheral_init(void)
// {
// 	/* Configure LED Pin */
// 	DDRB |= (1 << DDB0);
// }

// void change_led_state(uint8_t state)
// {
// 	LED_PORT = (state << LED_PIN);
// }


// /**
//  * @brief Main function where the code execution starts
//  * 
//  * @return int Return 0 if the program completes successfully
//  * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
//  * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
//  */
// int main(void)
// {
// 	/* Initialize Peripherals */
// 	peripheral_init();

// 	for(;;)
// 	{
//         change_led_state(LED_ON);
// 		delay_ms(LED_ON_TIME);
		
//         change_led_state(LED_OFF);
// 		delay_ms(LED_OFF_TIME);	
// 	}
// 	return 0;
// }


/*
 */
//#include <avr/io.h>
//#include<util/delay.h>
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

