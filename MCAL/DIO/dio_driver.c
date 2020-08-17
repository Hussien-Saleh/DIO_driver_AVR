#include "../../libraries/atmega32.h"

void DIO_Init(DIO_Handle_t *pDIOHandle){

	// if the pin mode is output mode
	if (pDIOHandle->DIO_PinConfig.DIO_PinMode == DIO_MODE_OUT){
		 
		SET_BIT(pDIOHandle->pDIOx->DDRx,pDIOHandle->DIO_PinConfig.DIO_PinNumber);

		 // Output Low (Sink)
		if (pDIOHandle->DIO_PinConfig.DIO_OutputType == DIO_OUT_LOW)
		{	
			CLEAR_BIT(pDIOHandle->pDIOx->PORTx,pDIOHandle->DIO_PinConfig.DIO_PinNumber);
		}
		// Output High (Source)
		if (pDIOHandle->DIO_PinConfig.DIO_OutputType == DIO_OUT_HIGH)
		{	
			SET_BIT(pDIOHandle->pDIOx->PORTx,pDIOHandle->DIO_PinConfig.DIO_PinNumber);
		}

	// if the pin mode is input mode
	  }else if (pDIOHandle->DIO_PinConfig.DIO_PinMode == DIO_MODE_IN){
		  	
			CLEAR_BIT(pDIOHandle->pDIOx->DDRx,pDIOHandle->DIO_PinConfig.DIO_PinNumber);
			// activating the pull up resistor
			if (pDIOHandle->DIO_PinConfig.DIO_PinPuPdControl == DIO_PINPU)
			{	
				SET_BIT(pDIOHandle->pDIOx->PORTx,pDIOHandle->DIO_PinConfig.DIO_PinNumber);

			}
			// deactivating the pullup resistor
			if (pDIOHandle->DIO_PinConfig.DIO_PinPuPdControl == DIO_NO_PU){
				CLEAR_BIT(pDIOHandle->pDIOx->PORTx,pDIOHandle->DIO_PinConfig.DIO_PinNumber);

			}
	  }
}

uint8 DIO_ReadFromInputPin(DIO_RegDef_t *pDIOx, uint8 pinNumber){

	uint8 value; // temp value to store the result
	// shift by the value equal to bit position to the right LSB
	// then mask the other bits 
	value = (uint8) ((pDIOx->PINx >> pinNumber) & 0x00000001);
	return value;  // return value is 0 or 1

}


uint8 DIO_ReadFromInputPort(DIO_RegDef_t *pDIOx){

	uint8 value; // temp value to store the result
	value = (uint8)pDIOx->PINx;
	return value;

}

void DIO_WriteToOutputPin(DIO_RegDef_t *pDIOx, uint8 pinNumber, uint8 value){
    
	if (value == SET){
		SET_BIT(pDIOx->PORTx, pinNumber);
    }
    else {
		CLEAR_BIT(pDIOx->PORTx, pinNumber);
    }
}

void DIO_WriteToOutputPort(DIO_RegDef_t *pDIOx, uint8 value){

    pDIOx->PORTx = value;

}
void DIO_ToggleOutputPin(DIO_RegDef_t *pDIOx, uint8 pinNumber){
	// toggling the output pin
	TOGGLE_BIT(pDIOx->PORTx,pinNumber);
}