`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:07:54 12/01/2015 
// Design Name: 
// Module Name:    writeBack 
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
module writeBack(
    input clk,
    input regWrite6,
    input memtoReg6,
    input [15:0] rdData3_2,
    input [15:0] aluResultOut3,
    input [15:0] mux3Out4,
    output [15:0] mux4Out,
    output [15:0] mux3Out5,
    output regWrite7
    );
	 
	 assign regWrite7 = regWrite6;
	 assign mux3Out5 = mux3Out4;
	 mux m4(aluResultOut3, rdData3_2, memtoReg6, mux4Out);
	 
endmodule
