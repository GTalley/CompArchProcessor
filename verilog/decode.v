`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:56:19 11/30/2015 
// Design Name: 
// Module Name:    decode 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module decode(
    input clk,
	 input reset,
    input [15:0] adder1Out,
    input [15:0] instructionOut,
    input regWrite6,
	 input [15:0] mux4Out,
	 input [15:0] mux3Out5,
    output regWrite1,
    output memtoReg1,
    output memWrite1,
    output memRead1,
    output branch1,
    output aluSrc1,
    output [1:0] aluOp1,
    output regDst,
	 output [15:0] adder1Out2,
	 output [15:0] rdData1,
	 output [15:0] rdData2,
	 output [15:0] seOut,
	 output [2:0] rd,
	 output [2:0] rt
    );
	 assign rd[2:0] = instructionOut[5:3];
	 assign rt[2:0] = instructionOut[8:6];
	 
	 
	 
	 registerFile rf(clk, reset, instructionOut[11:9] ,instructionOut[8:6],
	 mux3Out5, mux4Out, regWrite6, rdData1, rdData2);
	 
	 control ctrl(clk, instructionOut[15:12], memtoReg1, memWrite1, memRead1,
	 branch1, aluSrc1, aluOp1, regDst);
	 
	 signExtend se(clk,instructionOut[5:0], seOut[15:0]);

	 
	 


endmodule
