/* decode.c
  TEAM ACT
  
  This file contains useful functions included in the decode stage
  of the MIPS instruction cycle execution
  
*/

// includes
#include <stdio.h>
#include <cstring>

static int clk = 0;
static int reset = 0;


// Decode Subroutine
void decode(int clk, int reset, char *adder1Out[16], char instruction[16], char mux4Out[16], int *regWrite){




    
    char adder1Out2[16];            //Adder1 Output as Output
    char rdData1[16];               //Read Data1 as Output
    char rdData2[16];               //Read Data2 as Output
    char signIn[6];
    char seOut[16];                 //Sign Extend Output


    char rd[3];                     //rd bits
    char rt[3];                     //rt bits

    char rdReg1[3];
    char rdReg2[3];
    char wrReg[3];
    char code[4];                   //opCode


    strncpy(rd, instructionOut+3, 3);
    strncpy(rt, instructionOut+6, 3);

    strncpy(rdReg1, instructionOut+9, 3);
    strncpy(rdReg2, instructionOut+6, 3);
    strncpy(wrReg, instructionOut+3, 3);
    strncpy(code, instructionOut+13,4);
    strncpy(signIn, instructionOut, 6)




    control(clk,code);

    mux2Out = mux(clk, rdReg2, wrReg, regDst);

    seOut = signExtend(clk,signIn);

    if(clk){
        rdData1, rdData2 = registerFile(clk, rdReg1,  rdReg2, mux2Out, mux4Out, regWrite6);
    }
    else{
        registerFile(clk, rdReg1, rdReg2, mux2Out, mux4Out, regWrite6);
    }

}