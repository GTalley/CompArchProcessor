/* fetch.c
  TEAM ACT
  
  This file contains useful functions included in the fetch stage
  of the MIPS instruction cycle execution
  
*/

// includes
#include <stdio.h>

int debug_fetchc = 1;

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
void fetch(int clk, int adder2out, int pcSrc, int* adder1, int* instruction) {
    int muxout1 = -1;
    int address = -1;
    
    //get output of mux, determines if output is PC+4 or branch
    muxout1 = mux(clk, *adder1, adder2out, pcSrc);    //check for ordering (mux)
    //if (debug_fetchc) printf("\nmuxout1 = %d", muxout1);
    
    //determine address, this does nothing to value
    address = programCounter(clk, muxout1, address); //check for ordering (mux)
    //if (debug_fetchc) printf("\naddress = %d", address);
    
    //get instruction from instruction register file
    *instruction = instructionROM(clk, address);
    //if (debug_fetchc) printf("\ninstruction = %d", instruction);
    
    //increment PC, PC = PC+4, wired to muxout1
    *adder1 = fourBitAdder(clk, address); //increment program counter
    //if (debug_fetchc) printf("\nadder1 = %d", adder1);

    
}
//////////////////////////////////////////
//////////////////////////////////////////




//////////////////////////////////////////
// PROGRAM COUNTER
//  clk: input clock
//  muxout1: output from PC mux
//  return: out_ProgramCounter
//////////////////////////////////////////
int programCounter(int clk, int muxout1) {
    int address = 0;
    address = muxout1;
    return address;
}

//////////////////////////////////////////
// INSTRUCTION ROM
//  clk: input clock
//  addr: instruction address
//  return: out
//////////////////////////////////////////
int instructionROM(int clk, int addr) {
    int output = 0;
    
    //16b input
    //PC increments by 4 everytime
    switch(addr) {
        case 0: //8'h00:	dout <= 16'hABC1;  // slti $t0, $a1, 1
            output = 43969;
            break;
        case 4: //8'h04:	dout <= 16'h5A10;	// bne $t0, $zero, END_WHILE
            output = 23056;
            break;
        case 8: //8'h08:	dout <= 16'h8FFF;	// addi $a1, $a1, -1
            output = 36863;
            break;
        case 12: //8'h0c:	dout <= 16'h3B80;	// lw  $t0, ($a0)
            output = 15232;
            break;
        case 16: //8'h10:	dout <= 16'h8B61;	// addi t0, t0, -31
        case 20:
        case 24:
        case 28:
        case 32:
        case 36:
        case 40:
            output = 35681;
            break;
        case 44: //8'h2c:	dout <= 16'hAB68;	// slti$t0, $t0, 40
            output = 43880;
            break;
        case 48: //8'h30:	dout <= 16'h5A0B;	// bne $t0, $zero, ELSE_LOOP
            output = 23051;
            break;
        case 52: //8'h34:	dout <= 16'h2443;	// srl $v0, $v0, 3
            output = 9283;
            break;
        case 56: //8'h38:	dout <= 16'hD48A; // or $v1, $v1, $v0
            output = 54410;
            break;
        case 60: //8'h3c:	dout <= 16'hBB80;	// sw $t0, ($a0)
            output = 48000;
            break;
        case 64: //8'h40:	dout <= 16'h06C2;	// sll $v2, $v2, 2
            output = 1730;
            break;
        case 68: //8'h44:	dout <= 16'hE91B; // xor $v3,$v3, $v2
            output = 59675;
            break;
        //default: dout <= 16'h0000;
    }
    return output;
}

