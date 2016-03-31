`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:51:31 12/01/2015 
// Design Name: 
// Module Name:    register3 
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
module register3(
    input clk,
    input aluZero,
    input [15:0] aluResult,
    input [15:0] mux3Out,
    input [15:0] adder2,
    input [15:0] rdData2_2,
	 input branch3,
	 input memRead3,
	 input memWrite3,
	 input regWrite3,
	 input memtoReg3,
    output reg aluZeroOut,
    output reg [15:0] aluResultOut,
    output reg [15:0] mux3Out2,
    output reg[15:0] adder2Out,
    output reg [15:0] rdData2_3,
	 output reg branch4,
	 output reg memRead4,
	 output reg memWrite4,
	 output reg regWrite4,
	 output reg memtoReg4
    );
	 
	 always@(posedge clk)
	 begin
		aluZeroOut <= aluZero;
		mux3Out2 <= mux3Out;
		adder2Out <= adder2;
		rdData2_3 <= rdData2_2;
		branch4 <= branch3;
		memRead4 <= memRead3;
		memWrite4 <= memWrite3;
		regWrite4 <= regWrite3;
		memtoReg4 <= memtoReg3;
	 end


endmodule
