/* utility.c
  TEAM ACT
  
  This file contains useful functions regarding commonly
  used hardware during the MIPS process
  
*/

// includes
#include <stdio.h>

//////////////////////////////////////////
// MUX
//  clk: input clock
//  d0 : input, select 0
//  d1 : input, select 1
//  sel: select line
//  return: out - mux output
//////////////////////////////////////////
int mux(int clk, int d0, int d1, int sel) {
    int out = 0;
    if (sel == 0) out = d0;
    if (sel == 1) out = d1;
    return out;
}

//////////////////////////////////////////
// 4-BIT ADDER
//  clk: input clk
//  val: input value to be added to
//  return: out - val+4
//          val = val+4
//////////////////////////////////////////
int fourBitAdder(int clk, int val) {
    //printf("%d  ", val);
    int out = 0;
    out = val+4;
    return out;
}

//////////////////////////////////////////
// Register
//  
//////////////////////////////////////////
int Reg_FetchToDecode(int clk, int* adder1in, int* FET_instruction, int* adder1out, int* DEC_instruction) {
    if (clk) {
        *adder1out = *adder1in;
        *DEC_instruction = *FET_instruction;
    }
    return 1;
}


