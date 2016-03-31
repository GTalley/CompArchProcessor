`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:09:26 11/30/2015 
// Design Name: 
// Module Name:    register2 
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
module register2(
    input clk,
    input regWrite1,
    output reg regWrite2,
    input memtoReg1,
    output reg memtoReg2,
    input memWrite1,
    output reg memWrite2,
    input memRead1,
    output reg memRead2,
    input branch1,
    output reg branch2,
    input aluSrc1,
    output reg aluSrc2,
    input [1:0] aluOp1,
    output reg [1:0] aluOp2,
    input regDst1,
    output reg regDst2,
    input [7:0] adder2Out,
    output reg [7:0] adder2Out2,
    input [15:0] rdData1,
    output reg [15:0] rdData1_1,
    input [15:0] rdData2,
    output reg [15:0] rdData2_2,
    input [15:0] seOut,
    output reg [15:0] seOut2,
    input [2:0] rd,
    output reg [2:0] rdOut,
    input [2:0] rt,
    output reg [2:0] rtOut
    );
	 
	 always@(posedge clk)
		begin	
		 regWrite2 <= regWrite1;
		 memtoReg2 <= memtoReg1;
		 memWrite2 <= memWrite1;
		 memRead2 <= memRead1;
		 branch2 <= branch1;
		 aluSrc2 <= aluSrc1;
		 aluOp2 <= aluOp1;
		 regDst2 <= regDst1;
		 adder2Out2 <= adder2Out;
		 rdData1_1 <= rdData1;
		 rdData2_2 <= rdData2;
		 seOut2 <= seOut;
		 rdOut <= rd;
		 rtOut <= rt;
		end

endmodule
