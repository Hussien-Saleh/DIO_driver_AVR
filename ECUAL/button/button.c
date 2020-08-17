#include "button.h"

void Button_Init(DIO_Handle_t* DIO_Button){
    
    // Button Configuration
    DIO_Button->pDIOx = DIOC;
	DIO_Button->DIO_PinConfig.DIO_PinNumber = DIO_PIN_NO_7;
	DIO_Button->DIO_PinConfig.DIO_PinMode = DIO_MODE_IN;
	DIO_Button->DIO_PinConfig.DIO_PinPuPdControl = DIO_PINPU;

    DIO_Init(DIO_Button);

}

uint8 Is_Button_Pressed(){

    return DIO_ReadFromInputPin(DIOC, DIO_PIN_NO_7);

}

