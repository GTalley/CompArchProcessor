`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/30/2015 06:02:42 PM
// Design Name: 
// Module Name: control
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module control(
	 input clk,
    input [3:0] OPcode,
    output reg jmp,
    output reg RegWrite,
    output reg MemtoReg,
    output reg Branch,
    output reg MemRead,
    output reg MemWrite,
    output reg RegDst,
    output reg [3:0] ALUOp,
    output reg ALUSrc
	 );
    
    //R-type operation
	 always@(posedge clk)
		 if (OPcode == 'b0000)
			begin
			  jmp <= 0;
			  RegWrite <= 1;
			  MemtoReg <= 0;
			  Branch <= 0;
			  MemRead <= 0;
			  MemWrite <= 0;
			  RegDst <= 1;
			  ALUOp <= 0000;
			  ALUSrc <= 0;
			end
		 
		 //addi operation
		 else if (OPcode == 0001)
			begin
			  jmp <= 0;
			  RegWrite <= 1;
			  MemtoReg <= 0;
			  Branch <= 0;
			  MemRead <= 0;
			  MemWrite <= 0;
			  RegDst <= 0;
			  ALUOp <= 0011;
			  ALUSrc <= 1;
			end
		 
		 //and operation
		 else if (OPcode == 'b0010)
			  begin
					jmp <= 0;
					RegWrite <= 1;
					MemtoReg <= 0;
					Branch <= 0;
					MemRead <= 0;
					MemWrite <= 0;
					RegDst <= 1;
					ALUOp <= 0000;
					ALUSrc <= 0;
			  end
		 
		 //Beq operation
		  else if (OPcode == 'b0011)
				begin
						 jmp <= 0;
						 RegWrite <= 0;
						 MemtoReg <= 0;
						 Branch <= 1;
						 MemRead <= 0;
						 MemWrite <= 0;
						 RegDst <= 0;
						 ALUOp <= 0010;
						 ALUSrc <= 0;
				end
		 
		 //Bne operation
		 else if (OPcode == 'b0100)
			  begin
						 jmp <= 0;
						 RegWrite <= 0;
						 MemtoReg <= 0;
						 Branch <= 1;
						 MemRead <= 0;
						 MemWrite <= 0;
						 RegDst <= 0;
						 ALUOp <= 0100;
						 ALUSrc <= 0;
			  end
		  
		  //Jmp operation
		  else if (OPcode == 'b0101)
			  begin
						 jmp <= 1;
						 RegWrite <= 0;
						 MemtoReg <= 0;
						 Branch <= 1;
						 MemRead <= 0;
						 MemWrite <= 0;
						 RegDst <= 0;
						 ALUOp <= 1111;
						 ALUSrc <= 0;
			  end
		  
		  //lw operation
		  else if (OPcode == 'b0110)
			 begin
						 jmp <= 0;
						 RegWrite <= 1;
						 MemtoReg <= 1;
						 Branch <= 0;
						 MemRead <= 1;
						 MemWrite <= 0;
						 RegDst <= 0;
						 ALUOp <= 0001;
						 ALUSrc <= 1;
			  end
		
		  //lui operation
		  else if (OPcode == 'b0111)
			  begin
						 jmp <= 0;
						 RegWrite <= 1;
						 MemtoReg <= 0;
						 Branch <= 0;
						 MemRead <= 0;
						 MemWrite <= 0;
						 RegDst <= 0;
						 ALUOp <= 0101;
						 ALUSrc <= 1;
			  end
		  
		  //or operation
		  else if (OPcode == 'b1000) 
			  begin
						 jmp <= 0;
						 RegWrite <= 1;
						 MemtoReg <= 0;
						 Branch <= 0;
						 MemRead <= 0;
						 MemWrite <= 0;
						 RegDst <= 1;
						 ALUOp <= 0000;
						 ALUSrc <= 0;
			  end
		 
		  //xor operation
		  else if (OPcode == 'b1001) 
			  begin
						 jmp <= 0;
						 RegWrite <= 1;
						 MemtoReg <= 0;
						 Branch <= 0;
						 MemRead <= 0;
						 MemWrite <= 0;
						 RegDst <= 1;
						 ALUOp <= 0000;
						 ALUSrc <= 0;
			  end
		  
		  //slti operation
		  else if (OPcode == 'b1010)
			  begin
						 jmp <= 0;
						 RegWrite <= 1;
						 MemtoReg <= 0;
						 Branch <= 0;
						 MemRead <= 0;
						 MemWrite <= 0;
						 RegDst <= 0;
						 ALUOp <= 1001;
						 ALUSrc <= 1;
			  end
		  
		 //sll operation
			else if (OPcode == 'b1011) 
				begin
						  jmp <= 0;
						  RegWrite <= 1;
						  MemtoReg <= 0;
						  Branch <= 0;
						  MemRead <= 0;
						  MemWrite <= 0;
						  RegDst <= 0;
						  ALUOp <= 0110;
						  ALUSrc <= 1;
				end
		  
		  //srl operation
		  else if (OPcode == 'b1100) 
				begin
						 jmp <= 0;
						 RegWrite <= 1;
						 MemtoReg <= 0;
						 Branch <= 0;
						 MemRead <= 0;
						 MemWrite <= 0;
						 RegDst <= 0;
						 ALUOp <= 1000;
						 ALUSrc <= 1;
				end
		  
		  //sw operation
		  else if (OPcode == 'b1101) 
				begin
						 jmp <= 0;
						 RegWrite <= 0;
						 MemtoReg <= 0;
						 Branch <= 0;
						 MemRead <= 0;
						 MemWrite <= 1;
						 RegDst <= 0;
						 ALUOp <= 0001;
						 ALUSrc <= 1;
				end
		  
		  else 
			 begin
				jmp <= 0;
				RegWrite <= 0;
				MemtoReg <= 0;
				Branch <= 0;
				MemRead <= 0;
				MemWrite <= 0;
				RegDst <= 0;
				ALUOp <= 0000;
				ALUSrc <= 0;
			 end
    
endmodule
