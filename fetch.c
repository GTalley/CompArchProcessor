/* fetch.c
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
//  return: out_ProgramCounter
//////////////////////////////////////////
int programCounter(int clk, int muxout1) {
    int out_ProgramCounter = 0;
    if (debug) printf("\n   Begin programCounter()...");
    out_ProgramCounter = muxout1;
    if (debug) printf("\n   End programCounter()...");
    return out_ProgramCounter;
}

//////////////////////////////////////////
// INSTRUCTION ROM
//  clk: input clock
//  addr: instruction address
//  return: out
//////////////////////////////////////////
int instructionROM(int clk, int addr) {
    int out = 0;
    int opcode = 0;
    
    //disolve instruction to get opcode for instruction
    // 1000 000 000 000000 = 32768
    // 1001 000 000 000000 = 36864
    // therefore any value b/w 32768 and 36864 is an addi
        
    //16b input
    switch(opcode) {
        //addi 1000,rs,rt,immediate
        case 1:
            
            break;
        
        
    }
    
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