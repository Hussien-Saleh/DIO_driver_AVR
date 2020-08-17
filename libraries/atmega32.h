/*
 * File        : DIO_config.h
 * Description : This File includes DIO Driver addresses macros
 */ 
 

#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include "std_types.h"
#include "bit_macros.h"


#define F_CPU 16000000

#define __vo  volatile
#define HIGH      1
#define LOW       0
#define ON        HIGH
#define OFF       LOW
#define SET HIGH
#define RESET LOW

/*
// PORTA
#define IO_PORTA  (*(volatile uint8 *)(0x3B)) 
#define IO_DDRA  (*(volatile uint8 *)(0x3A)) 
#define IO_PINA  (*(volatile uint8 *)(0x39)) 


// PORTB
#define IO_PORTB  (*(volatile uint8 *)(0x38)) 
#define IO_DDRB  (*(volatile uint8 *)(0x37)) 
#define IO_PINB  (*(volatile uint8 *)(0x36)) 


// PORTC
#define IO_PORTC  (*(volatile uint8 *)(0x35)) 
#define IO_DDRC  (*(volatile uint8 *)(0x34)) 
#define IO_PINC  (*(volatile uint8 *)(0x33)) 

// PORTD
#define IO_PORTD  (*(volatile uint8 *)(0x32))
#define IO_DDRD  (*(volatile uint8 *)(0x31)) 
#define IO_PIND  (*(volatile uint8 *)(0x30)) 

*/


typedef struct
{
	__vo uint8 PINx;     // PORT INPUT PIN REGISTER  +  0x00  offset
	__vo uint8 DDRx;     // DATA DIRECTION REGISTER	 +  0x01  offset
    __vo uint8 PORTx;    // DATA REGISTER 			 +  0x02  offset

}DIO_RegDef_t;

#define DIOA_BASEADDR  0x39
#define DIOA   ((DIO_RegDef_t*)DIOA_BASEADDR)

#define DIOB_BASEADDR  0x36
#define DIOB   ((DIO_RegDef_t*)DIOB_BASEADDR)

#define DIOC_BASEADDR  0x33
#define DIOC   ((DIO_RegDef_t*)DIOC_BASEADDR)

#define DIOD_BASEADDR  0x30
#define DIOD   ((DIO_RegDef_t*)DIOD_BASEADDR)

#include "../MCAL/DIO/dio_driver.h"

#endif