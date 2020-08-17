#include "led.h"


void Led_Init(DIO_Handle_t* DIO_Led){

    // Led configuration
    DIO_Led->pDIOx = DIOA;
    DIO_Led->DIO_PinConfig.DIO_PinNumber = DIO_PIN_NO_5;
    DIO_Led->DIO_PinConfig.DIO_PinMode = DIO_MODE_OUT;
    DIO_Led->DIO_PinConfig.DIO_OutputType = DIO_OUT_HIGH;

    DIO_Init(DIO_Led);

}

void Led_Toggle(){
    
    DIO_ToggleOutputPin(DIOA,DIO_PIN_NO_5); // toggle the led

}
