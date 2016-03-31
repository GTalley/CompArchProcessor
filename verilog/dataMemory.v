`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:28:13 12/01/2015 
// Design Name: 
// Module Name:    dataMemory 
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
module dataMemory(
    input clk,
    input memWrite4,
    input memRead4,
    input [15:0] aluResultOut,
    input [15:0] rdData2_3,
    output reg [15:0] rdData3
    );
	 reg [15:0] a0;
	 reg [15:0] a2;
	 reg [15:0] a4;
	 reg [15:0] a6;
	 reg [15:0] a8;
	 
	 always@(posedge clk)
		 if (memRead4 == 1)
			if (aluResultOut == 16'h0010)
				begin 
					rdData3 <= a0;
				end
			else if (aluResultOut == 16'h0012)
				begin 
					rdData3 <= a2;
				end
			else if (aluResultOut == 16'h0014)
				begin 
					rdData3 <= a4;
				end
			else if (aluResultOut == 16'h0016)
				begin 
					rdData3 <= a6;
				end
			else if (aluResultOut == 16'h0018)
				begin 
					rdData3 <= a8;
				end
				
	always@(negedge clk)		
		if (memWrite4 == 1)
			if (aluResultOut == 16'h0010)
				begin 
					a0 <= rdData2_3;
				end
			else if (aluResultOut == 16'h0012)
				begin 
					a2 <= rdData2_3;
				end
			else if (aluResultOut == 16'h0014)
				begin 
					a4 <= rdData2_3;
				end
			else if (aluResultOut == 16'h0016)
				begin 
					a6 <= rdData2_3;
				end
			else if (aluResultOut == 16'h0018)
				begin 
					a8 <= rdData2_3;
				end
		
endmodule
