`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:33:39 11/30/2015 
// Design Name: 
// Module Name:    execute 
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
module execute(
    input clk,
    input regWrite2,
    input memtoReg2,
    input memWrite2,
    input memRead2,
    input branch2,
    input aluSrc2,
    input [2:0] aluOp2,
    input regDst2,
    input [15:0] adder1Out3,
    input [15:0] rdData1_1,
    input [15:0] rdData2_2,
    input [15:0] seOut2,
    input [2:0] rdOut,
    input [2:0] rtOut,
    output memtoReg3,
    output regWrite3,
    output memWrite3,
    output memRead3,
    output branch3,
    output [15:0] adder2,
    output aluZero,
    output [15:0] aluResult,
    output [15:0] rdData2_3,
    output [15:0] mux3Out
    );
	 
	 adder add(clk, adder1Out3, slOut, adder2);
	 shiftLeft sl(clk, seOut2, slOut);
	 alu alu1(clk, rdData1_1, mux2Out, aluCtrlOut, aluZero, aluResult);
	 mux mux2(clk, rdData2_2, seOut2, aluSrc, mux2Out);
	 aluControl aluCtrl(clk, seOut2[2:0], aluOp2, aluCtrlOut);
	 mux mux3(clk, rtOut, rdOut, regDst2, mux3Out);
	 

	 
	

endmodule
