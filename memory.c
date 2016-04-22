/* memory.c
  TEAM ACT
  
  This file contains useful functions included in the memory stage
  of the MIPS instruction cycle execution
  
*/

// includes
#include <stdio.h>
extern mem1;
extern mem2;
extern mem3;
extern mem4;
extern mem5;
int debug_memoryc = 1;

//////////////////////////////////////////
// MEMORY
//  //INPUTS
//  
//  
//  //OUTPUTS
//
//////////////////////////////////////////
void memory(int clk, int* aluZeroOut, int aluResultOut, int rdData2_3, int adder2Out, int* branch4, 
            int memRead4, int memWrite4, int regWrite4, int memtoReg4, int mux3Out2, int* adder2Out2,
            int* pcSrc, int* memtoReg5, int* regWrite5, int* rdData3, int* aluResultOut2, int* mux3Out3) {
    
    //pcSrc determination
    if ((aluZeroOut == 1) && (branch4 == 1)) {
        *pcSrc = 1;
    } else { *pcSrc = 0; }
    
    *adder2Out2 = adder2Out;
    *mux3Out3 = mux3Out2;
    *memtoReg5 = memtoReg4;
    *regWrite5 = regWrite4;
    dataMemory(clk, memWrite4,memRead4, aluResultOut, rdData2_3, &rdData3);
    
/*      assign pcSrc = aluZeroOut & branch4;
	 assign adder2Out2 = adder2Out;
	 assign mux3Out3 = mux3Out2;
	 assign aluResultOut2 = aluResultOut;
	 assign memtoReg5 = memtoReg4;
	 assign regWrite5 = regWrite4;
	 dataMemory dm(clk, memWrite4, memRead4, aluResultOut, rdData2_3, rdData3); */
    
    
}
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
// DATA MEMORY
//  //INPUTS
//  
//////////////////////////////////////////
int dataMemory(int clk, int memWrite4, int memRead4, int aluResultOut, int rdData2_3, int* rdData3) {
    
        if (memRead4 == 1) {
            if (aluResultOut ==  16) {rdData3 = mem1;}
            else if (aluResultOut == 18) {rdData3 = mem2;}
            else if (aluResultOut == 20) {rdData3 = mem3;}
            else if (aluResultOut == 22) {rdData3 = mem4;}
            else if (aluResultOut == 24) {rdData3 = mem5;}
        }
        
        if (memWrite4 == 1) {
            if (aluResultOut == 16) {mem1 = rdData2_3;}
            else if (aluResultOut == 18) {mem2 = rdData2_3;}
            else if (aluResultOut == 20) {mem3 = rdData2_3;}
            else if (aluResultOut == 22) {mem4 = rdData2_3;}
            else if (aluResultOut == 24) {mem5 = rdData2_3;}
        }
    
    return 1;
}