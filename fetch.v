`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:07:01 11/30/2015 
// Design Name: 
// Module Name:    fetch 
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
module fetch(input clk, input adder2Out, input pcSrc, output adder1, output instruction
    );
	 wire [15:0] address;
	 wire [15:0] muxout1;
	 wire [15:0] adder1out;
	
	 program_counter pc(clk, muxout1, address);
	 mux mux1(adder1, adder2out, pcSrc, muxout1);
	 full_adder_4bit add1(address, adder1);
	 instruction_ROM ROM(clk, address, instruction);
	 
endmodule
