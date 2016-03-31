`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:47:21 11/30/2015 
// Design Name: 
// Module Name:    shiftLeft 
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
module shiftLeft(
    input clk,
    input [15:0] seOut2,
    output reg [15:0] slOut
    );
	 
	 always@(posedge clk)
		begin
			slOut[15:2] <= seOut2[13:0];
			slOut[1:0] <= 'b00;
		end


endmodule
