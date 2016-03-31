`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:46:22 11/30/2015 
// Design Name: 
// Module Name:    register 
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
module register1(
	input clk, 
	input adder1In, 
	input instructionIn, 
	output reg adder1Out, 
	output reg instructionOut
    );
	 
	 always@(posedge clk)
		begin
			adder1Out <= adder1In;
			instructionOut <= instructionIn;
		end

endmodule
