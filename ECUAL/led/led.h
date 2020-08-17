#ifndef LED_H
#define LED_H

#include "../../libraries/atmega32.h"

/*
 Function to initialize led 
 @param, DIO_Led , pointer to handle structure of DIO peripheral
*/
void Led_Init(DIO_Handle_t* DIO_Led);

/*
 Function to toggle the led
*/

void Led_Toggle();

#endif