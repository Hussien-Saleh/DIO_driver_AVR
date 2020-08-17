#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

#include "../../libraries/std_types.h"
/*
 * DIO configuration pin numbers
 */

#define DIO_PIN_NO_0  0
#define DIO_PIN_NO_1  1
#define DIO_PIN_NO_2  2
#define DIO_PIN_NO_3  3
#define DIO_PIN_NO_4  4
#define DIO_PIN_NO_5  5
#define DIO_PIN_NO_6  6
#define DIO_PIN_NO_7  7

/*
 * Non-interrupt DIO POSSIBLE MODES
 */

#define DIO_MODE_IN 0
#define DIO_MODE_OUT 1

/*
 * DIO Pull up configuration macros
 */

#define DIO_NO_PU     0
#define DIO_PINPU     1

/*
  DIO output type - high or low
 */

#define DIO_OUT_LOW      0
#define DIO_OUT_HIGH     1


typedef struct DIO_PinConfig_t {

	uint8 DIO_PinNumber; // 8bit pin numbers 
	uint8 DIO_PinMode;   // output or input modes of the pin	
	uint8 DIO_PinPuPdControl;	// controlling the pull up resistor 
	uint8 DIO_OutputType;	// type of output (high or low)

}DIO_PinConfig_t;


typedef struct DIO_Handle_t{

	DIO_RegDef_t *pDIOx;  // pointer to hold the base address of the DIO peripheral
	DIO_PinConfig_t DIO_PinConfig;  // this holds the DIO pin configuration settings

}DIO_Handle_t;

/*
 Function to initialize the DIO pin direction and activating the pullup resistors
 @param pDIOHandle, pointer to a handling structure of DIO peripheral
 @return 
*/
void DIO_Init(DIO_Handle_t *pDIOHandle);

/*
 Function to read from specific pin of the DIO periperhal
 @param pDIOX, pointer to the structure of DIO peripheral
 @param pinNumber, the number of the pin to read from
 @return the value of the pin
*/
uint8 DIO_ReadFromInputPin(DIO_RegDef_t *pDIOx, uint8 pinNumber); 

/*
 Function to read from specific port of the DIO periperhal
 @param pDIOX, pointer to the structure of DIO peripheral
 @return the value of the port
*/

uint8 DIO_ReadFromInputPort(DIO_RegDef_t *pDIOx);

/*
 Function to write to a specific pin of the DIO periperhal
 @param pDIOX, pointer to the structure of DIO peripheral
 @param pinNumber, the number of the pin to write to
 @param value, the value of the pin to be written
 @return
*/
void DIO_WriteToOutputPin(DIO_RegDef_t *pDIOx, uint8 pinNumber, uint8 value); 

/*
 Function to write to a specific port of the DIO periperhal
 @param pDIOX, pointer to the structure of DIO peripheral
 @param value, the value of the port to be written
 @return
*/

void DIO_WriteToOutputPort(DIO_RegDef_t *pDIOx, uint8 value);

/*
 Function to toggle a specific pin of the DIO periperhal port
 @param pDIOX, pointer to the structure of DIO peripheral
 @param pinNumber, the number of the pin to be toggled
 @return
*/

void DIO_ToggleOutputPin(DIO_RegDef_t *pDIOx, uint8 pinNumber);


#endif