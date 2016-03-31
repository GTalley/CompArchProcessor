`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:58:39 11/30/2015 
// Design Name: 
// Module Name:    Alucontrol 
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
module aluControl(
	input clk,
	input [3:0] ALUOp,
	input [2:0] funcCode,
	output reg [3:0] ALUCtl
	);
	
	always@(posedge clk)
		if (ALUOp == 'b0000)
		  begin
			case(funcCode) //R-Type Check Function code
				3'b001:ALUCtl <= 'b0001; //add
				3'b100:ALUCtl <= 4; //and
				3'b010:ALUCtl <=2; //or
				3'b011:ALUCtl <=3; //slt
			default: ALUCtl <=15; 
			endcase
		  end
		else if (ALUOp == 'b0001)	//addi
		  begin
			ALUCtl <= 'b0101;
		  end
		else if (ALUOp == 'b0011) //beq
			begin
				ALUCtl <= 6;
			end
		else if (ALUOp == 0100) // bne
			begin
				ALUCtl <= 7;
			end
		else if (ALUOp == 0101) //jmp
			begin
				ALUCtl <= 8;
			end
		else if (ALUOp == 0110) //lw
			begin
				ALUCtl <= 9;
			end
		else if (ALUOp == 1010) // slti
			begin
				ALUCtl <= 10;
			end
		else if (ALUOp == 1011) // sll
			begin
				ALUCtl <= 11;
			end
		else if (ALUOp == 1100) // srl
			begin
				ALUCtl <= 12;
			end
		else if (ALUOp == 1101) // sw
			begin
				ALUCtl <= 13;
			end
		else if (ALUOp == 1110) // xor
			begin
				ALUCtl <= 14;
			end
		
endmodule
