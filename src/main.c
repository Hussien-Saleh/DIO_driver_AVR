#include "../libraries/atmega32.h"
#include "../ECUAL/button/button.h"
#include "../ECUAL/led/led.h"


void delay(){

	for(uint32 i=0; i<500000/2; i++);
}

int main(void){

    DIO_Handle_t DIO_Led, DIO_Button;

	Led_Init(&DIO_Led);
	Button_Init(&DIO_Button);
	
	while(1){

		// check if the button is pressed (active low)
		if (Is_Button_Pressed() == BUTTON_PRESSED)
		{
	        delay(); // wait until the debouncing effect of button is over
			Led_Toggle();
		}
	}

	return 0;
}

