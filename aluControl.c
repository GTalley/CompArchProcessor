/*
	aluControl.c
	TEAM ACT
*/


aluControl(int clk, int ALUOp, int funcCode){
	
	if (ALUOp == 0){
		//Sign-Extend FuncCodes
		switch (funcCode){
			
			//ADD - Sign extend
			case 1:
			*ALUCtl = 1;
			break;
			
			//OR - Sign extend
			case 2:
			*ALUCtl = 2;
			break;
			
			//SLT - Sign extend
			case 3:
			*ALUCtl = 3;
			break;
			
			//AND - Sign Extend
			case 4:
			*ALUCtl = 4;
			break;

			default:
			*ALUCtl = 0;
			
		}
	
	//ADDi
	else if(ALUOp == 5){
		*ALUCtl = 5;
	}
	//BEQ
	else if(ALUOp == 6){
		*ALUCtl = 6;
	}
	//BNE
	else if(ALUOp == 7){
		*ALUCtl = 7;
	}
	//JMP
	else if(ALUOp == 8){
		*ALUCtl = 8;
	}
	//LW
	else if(ALUOp == 9){
		*ALUCtl = 9;
	}
	//SLTi
	else if(ALUOp == 10){
		*ALUCtl = 10;
	}
	//SLL
	else if(ALUOp == 11){
		*ALUCtl = 11;
	}
	//SRL
	else if(ALUOp == 12){
		*ALUCtl = 12;
	}
	//SW
	else if(ALUOp == 13){
		*ALUCtl = 13;
	}
	//XOR
	else if(ALUOp == 14){
		*ALUCtl = 14;
	}
}





/*
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

*/