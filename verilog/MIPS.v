`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:17:45 11/30/2015 
// Design Name: 
// Module Name:    MIPS 
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
module MIPS();
	 reg clk;
	 reg reset;
	 
	 initial begin
		clk <= 0;
		reset <= 1;
	#5 clk <= 1;
	#5 clk <= 0;
		reset <= 0;
		end
		always
			begin
				#5 clk <= ~clk;
			end
	
	
	wire [15:0] adder2Out2, adder1, instruction, adder1Out, instructionOut, adder1Out2, rdData1, rdData2, seOut;
	wire [2:0] rd, rt;
	wire [1:0] aluOp1;
	wire pcSrc, regWrite1, memtoReg1, memWrite1, memRead1, branch1, aluSrc1, regDst1;
	
	
	fetch f(clk, adder2Out2, pcSrc, adder1, instruction);
	
	register1 r1(clk, adder1, instruction, adder1Out, instructionOut);
	
	decode d(clk, reset, adder1Out, instructionOut, regWrite6, mux4Out, mux3Out5, regWrite1, 
	memtoReg1, memWrite1, memRead1, branch1, aluSrc1, aluOp1, regDst1, adder1Out2, rdData1, 
	rdData2, seOut, rd, rt);
	
	register2 r2(clk, regWrite1, regWrite2, memtoReg1, memtoReg2, memWrite1, memWrite2, memRead1, 
	memRead2, branch1, branch2, aluSrc1, aluSrc2, aluOp1, aluOp2, regDst1, regDst2, adder1Out2, 
	adder1Out3, rdData1, rdData1_1, rdData2, rdData2_2, seOut, seOut2, rd, rdOut, rt, rtOut);
	
	execute e(clk, regWrite2, memtoReg2, memWrite2, memRead2,
	branch2, aluSrc2, aluOp2, regDst2, adder1Out3, rdData1_1, 
	rdData2_2, seOut2, rdOut, rtOut, memtoReg3, regWrite3, memWrite3, 
	memRead3, branch3, adder2, aluZero, aluResult, rdData2_3, mux3Out);
	
	register3 r3(clk, aluZero, aluResult, mux3Out, adder2, rdData2_2, branch3,
	memRead3, memWrite3, regWrite3, memtoReg3, aluZeroOut, aluResultOut, mux3Out2, 
	adder2Out, rdData2_3, branch4, memRead4, memWrite4, regWrite4, memtoReg4);
	
	memory mem(clk, aluZeroOut, aluResultOut, rdData2_3, adder2Out, branch4,
	memRead4, memWrite4, regWrite4, memtoReg4, mux3Out2, adder2Out2, pcSrc, 
	memtoReg5, regWrite5, rdData3, aluResultOut2, mux3Out3);
	
	register4 r4(clk, regWrite5, memtoReg5, rdData3, aluResultOut2, mux3Out3, regWrite6, memtoReg6, rdData3_2, 
	aluResultOut3, mux3Out4);
	
	writeBack wb(clk, regWrite6, memtoReg6, rdData3_2, aluResultOut3, mux3Out4, mux4Out, mux3Out5, regWrite7);
	
	
endmodule
