`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:21:34 12/01/2015 
// Design Name: 
// Module Name:    memory 
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
module memory(
    input clk,
    input aluZeroOut,
    input [15:0] aluResultOut,
    input [15:0] rdData2_3,
    input [15:0] adder2Out,
    input branch4,
    input memRead4,
    input memWrite4,
    input regWrite4,
    input memtoReg4,
    input [15:0] mux3Out2,
    output [15:0] adder2Out2,
    output pcSrc,
    output memtoReg5,
    output regWrite5,
    output [15:0] rdData3,
    output [15:0] aluResultOut2,
    output [15:0] mux3Out3
    );
	 
	 assign pcSrc = aluZeroOut & branch4;
	 assign adder2Out2 = adder2Out;
	 assign mux3Out3 = mux3Out2;
	 assign aluResultOut2 = aluResultOut;
	 assign memtoReg5 = memtoReg4;
	 assign regWrite5 = regWrite4;
	 dataMemory dm(clk, memWrite4, memRead4, aluResultOut, rdData2_3, rdData3);


endmodule
