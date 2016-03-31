`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:30:31 11/30/2015 
// Design Name: 
// Module Name:    instruction_ROM 
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
module instruction_ROM(input clk, input [7:0] instAddr, output reg [15:0] dout);

always 
case (instAddr[7:0])
	8'h00:	dout <= 16'hABC1;  // slti $t0, $a1, 1
	8'h04:	dout <= 16'h5A10;	// bne $t0, $zero, END_WHILE
	8'h08:	dout <= 16'h8FFF;	// addi $a1, $a1, -1
	8'h0c:	dout <= 16'h3B80;	// lw  $t0, ($a0)
	8'h10:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h14:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h18:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h1c:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h20:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h24:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h28:	dout <= 16'h8B61;	// addi t0, t0, -31
	8'h2c:	dout <= 16'hAB68;	// slti$t0, $t0, 40
	8'h30:	dout <= 16'h5A0B;	// bne $t0, $zero, ELSE_LOOP
	8'h34:	dout <= 16'h2443;	// srl $v0, $v0, 3
	8'h38:	dout <= 16'hD48A; // or $v1, $v1, $v0
	8'h3c:	dout <= 16'hBB80;	// sw $t0, ($a0)
	8'h40:	dout <= 16'h06C2;	// sll $v2, $v2, 2
	8'h44:	dout <= 16'hE91B; // xor $v3,$v3, $v2
	default: dout <= 16'h0000;
endcase

endmodule
