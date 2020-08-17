/*
 * File        : bit_macros.h
 * Description : This File includes macro functions for bit manipulation
 */ 
 
#ifndef BIT_MACROS_H_
#define BIT_MACROS_H_

#define SET_BIT(REG,BIT)    REG|=(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)
#define CLEAR_BIT(REG,BIT)  REG&=~(1<<BIT)
#define GET_BIT(REG,BIT) (REG&(1<<BIT))>>BIT

#define SET_BYTE(REG)    REG|=0xFF
#define CLEAR_BYTE(REG)  REG&=0x00

#define SET_HIGH_NIBBLE(BYTE) (BYTE|=(0xF0))
#define SET_LOW_NIBBLE(BYTE)  (BYTE|=(0x0F))

#define CLEAR_HIGH_NIBBLE(BYTE) (BYTE&=(0x0F))
#define CLEAR_LOW_NIBBLE(BYTE)  (BYTE&=(0xF0))

#endif 