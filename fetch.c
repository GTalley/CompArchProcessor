/* fetch.c
  TEAM ACT
  
  This file contains useful functions included in the fetch stage
  of the MIPS instruction cycle execution
  
*/

// includes
#include <stdio.h>

int debug = 0;

//////////////////////////////////////////
// FETCH
//  //INPUTS
//  clk: input clk
//  adder2out:
//  pcSrc:
//  
//  //OUTPUTS
//  adder1:
//  instruction: 
//////////////////////////////////////////
void fetch(int clk, int adder2out, int pcSrc, int adder1, int instruction) {
    int muxout1;
    int address;
    int i;
    
    //test init
    pcSrc = 0; //select = adder2out
    adder1 = 0;
    adder2out = 2;
    
    //this shows consecutive fetch of all instructions
    //for (i = 0; i < 18; i++) {
        
    muxout1 = mux(clk, adder1, adder2out, pcSrc);    //check for ordering (mux)
    //if (debug) printf("\nmuxout1 = %d", muxout1);
    address = programCounter(clk, muxout1, address); //check for ordering (mux)
    //if (debug) printf("\naddress = %d", address);
    //muxout1 = mux(clk, adder1, adder2out, pcSrc);    //check for ordering (mux)
    adder1 = fourBitAdder(clk, address);
    if (debug) printf("\nadder1 = %d", adder1);
    instruction = instructionROM(clk, address);
    if (debug) printf("\ninstruction = %d", instruction);
    
    //}
    
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
        case 0: //0000 0000 0000 0000 
            output = 43969;
            break;
        case 4: //0000 0000 0000 0100
            output = 23056;
            break;
        case 8: //0000 0000 0000 1000
            output = 36863;
            break;
        case 12: //0000 0000 0000 1100
            output = 15232;
            break;
        case 16:
        case 20:
        case 24:
        case 28:
        case 32:
        case 36:
        case 40:
            output = 35681;
            break;
        case 44:
            output = 43880;
            break;
        case 48:
            output = 23051;
            break;
        case 52:
            output = 9283;
            break;
        case 56:
            output = 54410;
            break;
        case 60:
            output = 48000;
            break;
        case 64:
            output = 1730;
            break;
        case 68:
            output = 59675;
            break;        
    }
    return output;
}

/* always 
case (instAddr[7:0])
	8'h00:	dout <= 16'hABC1;  // slti $t0, $a1, 1
	8'h04:	dout <= 16'h5A10;	// bne $t0, $zero, END_WHILE
	8'h08:	dout <= 16'h8FFF;	// addi $a1, $a1, -1
	8'h0c:	dout <= 16'h3B80;	// lw  $t0, ($a0)
	8'h10:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h14:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h18:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h1c:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h20:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h24:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h28:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h2c:	dout <= 16'hAB68;	// slti$t0, $t0, 40
	8'h30:	dout <= 16'h5A0B;	// bne $t0, $zero, ELSE_LOOP
	8'h34:	dout <= 16'h2443;	// srl $v0, $v0, 3
	8'h38:	dout <= 16'hD48A; // or $v1, $v1, $v0
	8'h3c:	dout <= 16'hBB80;	// sw $t0, ($a0)
	8'h40:	dout <= 16'h06C2;	// sll $v2, $v2, 2
	8'h44:	dout <= 16'hE91B; // xor $v3,$v3, $v2
	default: dout <= 16'h0000;
endcase

endmodule */