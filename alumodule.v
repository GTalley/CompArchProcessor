module alu(
	input clk,
	input [15:0] a, 
	input [15:0] b, 
	input [3:0] aluCtl, 
	output reg [15:0] aluOut, 
	output reg zero
	);


	always@(posedge clk)begin
		case(aluCtl)
			4'b0001: aluOut <= a + b;   // ADD
			4'b0010: aluOut <= a | b;   // OR
			4'b0011: if (a < b) 
							begin
								aluOut <= 1;
							end
			         else 
							begin
								aluOut <= 0;
							end
			4'b0100: aluOut <= a & b;
			4'b0101: if (b[15] == 1)
			             begin
							   aluOut <= ~b + 1;
								aluOut <= aluOut + a;
							 end
						else
						    begin
						   	aluOut <= a + b;
							 end
			4'b0110: if (a == b)
                      begin
                         zero <= 1;
                      end
                  else
						    begin
                         zero <= 0;
                      end								 
			4'b0111: if (a != b)
                      begin
                         zero <= 1;
                      end
                  else
						    begin
                         zero <= 0;
                      end	
			4'b1000: zero <= 1;  // jump
			4'b1001: aluOut <= a + b;  // lw
			4'b1010: if (a < b)
			             begin
							   aluOut <= 1;
							 end
						else
						    begin
							   aluOut <= 0;
							 end
			4'b1011: aluOut <= a << b;
			4'b1100: aluOut <= a >> b;
			4'b1101: aluOut <= a + b;
			4'b1110: aluOut <= a ^ b;
			default: aluOut <= 0;
		endcase
	end
endmodule
	