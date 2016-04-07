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
//////////////////////////////////////////
int fourBitAdder(int clk, int val) {
    int out = 0;
    out = val+4;
    return out;
}