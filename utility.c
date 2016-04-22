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



//////////////////////////////////////////
// Register File
// clk: input clock
// Inputs: rdReg1, rdReg2, mux3Out5(address), mux4Out(Data), regWrite
// Outputs: rdData1, rdData2
//////////////////////////////////////////
void registerFile(int clk, char rdReg1[3], char rdReg2[3], char mux3Out5[16], char mux4Out, int regWrite6) {

    //Initialize registers
    char zero[16];
    char v0[16];
    char v1[16];
    char v2[16];
    char v3[16];
    char t0[16];
    char a0[16];
    char a1[16];

    char (*regfile[7])[16];


    //Read registers on positive(1) clock edge
    if(clk){
        //Reset registers to default
        if(reset){
            zero = "0000000000000000";
            v0 = "0000000001000000";
            v1 = "0001000000010000";
            v2 = "0000000000001111";
            v3 = "0000000000000000";
            t0 = "0000000000000000";
            a0 = "0000000000010000";
            a1 = "0000000000000101";
        }
        //Store read data into variable for return
        else{
            rdData1 = regfile[rdReg1];
            rdData2 = regfile[rdReg2];
        }
        return rdData1, rdData2;
    }
    //Store Data in a register on a negative(0) clock edge 
    if(!clk){
        if(regWrite6 == 1){
            if(mux3Out5 == "0000000000010000")
                regfile[0] = mux4Out;
            else if(mux3Out5 == "0000000000010010")
                regfile[1] = mux4Out;
            else if(mux3Out5 == "0000000000010100")
                regfile[2] = mux4Out;
            else if(mux3Out5 == "0000000000010110")
                regfile[3] = mux4Out;
            else if(mux3Out5 == "0000000000011000")
                regfile[4] = mux4Out;
            else if(mux3Out5 == "0000000000011010")
                regfile[5] = mux4Out;
            else if(mux3Out5 == "0000000000011100")
                regfile[6] = mux4Out;
        }
    }

}

//////////////////////////////////////////
// Control
//  Input clock: clk
//  OpCode: opCode = instructionOut[15:12]
//  Signals: jmp, regWrite, memtoReg, branch, memRead, 
//           memWrite, regDst, aluSrc
//  return: Signals
//////////////////////////////////////////
void control(int clk, string* opCode[4] ) {
   
   // R-Type operation 
   if(clk){ 
       if(opCode == "0000"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 1;
        *aluOp = "0000";
        *aluSrc = 0;
       }

       //addi operation
       else if(opCode == "0001"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "0011";
        *aluSrc = 1;
       }

       //and operation
       else if(opCode == "0010"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 1;
        *aluOp = "0000";
        *aluSrc = 0;
       }
       //beq operation
       else if(opCode == "0011"){
        *jmp = 0;
        *regWrite = 0;
        *memtoReg = 0;
        *branch = 1;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "0010";
        *aluSrc = 0;
       }

       //bne operation
       else if(opCode == "0100"){
        *jmp = 0;
        *regWrite = 0;
        *memtoReg = 0;
        *branch = 1;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "0100";
        *aluSrc = 0;
       }

       //jmp operation
       else if(opCode == "0101"){
        *jmp = 1;
        *regWrite = 0;
        *memtoReg = 0;
        *branch = 1;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "1111";
        *aluSrc = 0;
       }

       //lw operation
       else if(opCode == "0110"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 1;
        *branch = 0;
        *memRead = 1;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "0001";
        *aluSrc = 1;
       }

       //lui operation
       else if(opCode == "0111"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "0101";
        *aluSrc = 1;
       }

       //or operation
       else if(opCode == "1000"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 1;
        *aluOp = "0000";
        *aluSrc = 0;
       }

       //xor operation
       else if(opCode == "1001"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 1;
        *aluOp = "0000";
        *aluSrc = 0;
       }

       //slti operation
       else if(opCode == "1010"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "1001";
        *aluSrc = 1;
       }

       //sll operation
       else if(opCode == "1011"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "0110";
        *aluSrc = 1;
       }

       //srl operation
       else if(opCode == "1100"){
        *jmp = 0;
        *regWrite = 1;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "1000";
        *aluSrc = 1;
       }

       //sw operation
       else if(opCode == "1101"){
        *jmp = 0;
        *regWrite = 0;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 1;
        *regDst = 0;
        *aluOp = "0001";
        *aluSrc = 1;
       }

       //Default Case
       else{
        *jmp = 0;
        *regWrite = 0;
        *memtoReg = 0;
        *branch = 0;
        *memRead = 0;
        *memWrite = 0;
        *regDst = 0;
        *aluOp = "0000";
        *aluSrc = 0;
       }
    }

}

//////////////////////////////////////////
// Sign Extend
//  Input clock: clk
//  signIn = instructionOut[5:0]
//  return: signOut
//////////////////////////////////////////
void signExtend(int clk, string* signIn[6]){
    char signOut[16];
    char zString[10] = "0000000000";
    char oString[10] = "1111111111";

    if(clk){
        strncpy(signOut, signIn, 6);
        if(signIn[5] == 0){
            strncpy(signOut + 6, zString, 10);
        }
        else{
            strncpy(signOut + 6, oString, 10);
        }

        return signOut;
    }
}

