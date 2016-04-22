/* fetch.c
  TEAM ACT
  
  This file contains useful functions included in the fetch stage
  of the MIPS instruction cycle execution
  
*/

// includes
#include <stdio.h>

int debug = 1;

//////////////////////////////////////////
// FETCH
//  //INPUTS
//  clk: input clk
//  adder2out:used for branch, to mux1
//  pcSrc:used to determine output of mux1
//  
//  //OUTPUTS
//  adder1: incremented program counter
//  instruction: current instruction to decode
//////////////////////////////////////////
void writeBack(int clk, int *regWrite, int *memtoReg, char rdData3_2[16], char aluResultOut3[16], char mux3Out4[16]) {

    mux4Out = mux(aluResultOut3, rdData3_2, &memtoReg);  
}

