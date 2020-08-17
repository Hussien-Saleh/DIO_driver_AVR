#ifndef BUTTON_H
#define BUTTON_H

#include "../../libraries/atmega32.h"

#define BUTTON_PRESSED LOW


/*
 Function to initialize button 
 @param, DIO_Button , pointer to handle structure of DIO peripheral
*/

void Button_Init(DIO_Handle_t* DIO_Button);

uint8 Is_Button_Pressed();

#endif