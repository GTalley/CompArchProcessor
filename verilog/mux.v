
//2x1 Multiplexer

module mux(
	 input clk,
    input wire d0,
    input wire d1,
    input wire sel,
    output reg [15:0] out
    );
	 
	 always @(posedge clk)
		begin
			case(sel)
				0: out = d0;
				1: out = d1;
					default: out = 1'b0;
			endcase
		end


endmodule
