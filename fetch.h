/* fetch.h
  TEAM ACT
  
  This file contains useful functions included in the fetch stage
  of the MIPS instruction cycle execution
  
*/

// includes
#include <stdio.h>

int debug = 0;

//////////////////////////////////////////
// PROGRAM COUNTER
//  clk: input clock
//  muxout1: output from PC mux
//////////////////////////////////////////
int programCounter(int clk, int muxout1) {
    int out_ProgramCounter = 0;
    if (debug) printf("\n   Begin programCounter()...");
    out_ProgramCounter = muxout1;
    if (debug) printf("\n   End programCounter()...");
    return out_ProgramCounter;
}

