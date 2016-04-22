/* MIPS.C
  TEAM ACT
  
*/

// includes
#include <stdio.h>
#include "fetch.c"
#include "memory.c"
#include "decode.c"
#include "writeback.c"
#include "utility.c"
#include "time.h"

// function definition
//  

//globals
int debug_input = 0;
int debug_fetch = 0;
int debug_decode = 0;
int debug_execute = 0;
int debug_mem = 1;

//memory, global to retain value 
//throughout execution
int mem1 = -1;
int mem2 = -1;
int mem3 = -1;
int mem4 = -1;
int mem5 = -1;

//Control Signals as pointers
int *jmp = 0;
int *regWrite = 0;
int *memtoReg = 0;
int *branch = 0;
int *memRead = 0;
int *memWrite = 0;
int *regDst = 0;
char *aluOp[4];
int *aluSrc = 0;



void main(int argc, char *argv[]) {
    //main vars
    int temp = 0;
    int clk = 1;
    int pcSrc = 0;
    int adder1in = 0, adder1out = 0;
    int FET_instruction = 0, DEC_instruction = 0;
    int i;
    clock_t start_t, end_t;
    int aluZeroOut,aluResultOut,adder2out,rdData2_3,branch4,memRead4,memWrite4,regWrite4;
    int memtoReg4,mux3Out2,adder2Out2,memtoReg5,regWrite5,rdData3,aluResultOut2,mux3Out3;

    
    //init
    //adder1 = 0;
    
    if (debug_input) printf("\nBegin main()...");
    if (debug_input) printf("\narg1 = %s", argv[1]);
    
    ///////////////////////////////////////////////
    // FETCH STAGE
    //  handles:
    //      programcounter
    //      
    ///////////////////////////////////////////////
    if (debug_fetch) printf("\n\nFETCH: ");

    //testing, run through all instructions
    fetch(clk, adder2out, pcSrc, &adder1in, &FET_instruction);
    Reg_FetchToDecode(clk, &adder1in, &FET_instruction, &adder1out, &DEC_instruction);
    if (debug_fetch) printf("\nDEC_instruction: %d", DEC_instruction);  
    
    if (debug_fetch) printf("\nEND FETCH:\n");
    ///////////////////////////////////////////////
    // DECODE STAGE
    //  handles:
    //      
    ///////////////////////////////////////////////
    if (debug_decode) printf("\nDECODE: ");

    decode(clk, reset, &adder1Out, &DEC_instruction, mux4Out, &regWrite);



    if (debug_decode) printf("\nEND DECODE:\n");
    ///////////////////////////////////////////////
    // EXECUTE STAGE
    //  handles:
    //      
    ///////////////////////////////////////////////
    if (debug_execute) printf("\nEXECUTE: ");
    if (debug_execute) printf("\nEND EXECUTE:\n");
    
    ///////////////////////////////////////////////
    // MEM STAGE
    //  handles:
    //      
    ///////////////////////////////////////////////
    if (debug_mem) printf("\nMEM: ");
    
    memory(clk,&aluZeroOut,aluResultOut,rdData2_3,adder2out,&branch4,memRead4,memWrite4,regWrite4, 
            memtoReg4,mux3Out2,&adder2Out2,&pcSrc,&memtoReg5,&regWrite5,&rdData3,&aluResultOut2,&mux3Out3);
    
    if (debug_mem) printf("\nEND MEM:\n");
    
    
    // END MAIN

    if (debug_memory) printf("\nMemory: ");
    if (debug_memory) printf("\nEND Memory:\n");


    if (debug_writeBack) printf("\nWriteBack: ");

    writeBack(clk, &regwrite, &memtoReg, rdData3_2, aluResultOut3, mux3Out4);

    if (debug_writeBack) printf("\nEND WriteBack:\n");
    printf("\n\nEnd main()...");
    printf("\n");
}






