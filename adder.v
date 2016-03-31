`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:51:49 11/30/2015 
// Design Name: 
// Module Name:    adder 
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
module adder(
    input clk,
    input [15:0] adder1Out3,
    input [15:0] slOut,
    output reg [15:0] adder2
    );
	 
	 always@(posedge clk)
		begin
			adder2 <= adder1Out3 + slOut;
		end


endmodule
