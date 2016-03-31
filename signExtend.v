`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:37:55 11/30/2015 
// Design Name: 
// Module Name:    signExtend 
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
module signExtend(
	 input clk,
    input [5:0] signIn,
	 output reg [15:0] seOut
    );
	 always@(posedge clk)
	   begin
		seOut[5:0] <= signIn[5:0];
		 if (signIn[5] == 0)
			begin
				seOut[15:6] <= 'b0000000000;
			end
		 else
			begin
				seOut[15:6] <= 'b1111111111;
			end
		end


endmodule
