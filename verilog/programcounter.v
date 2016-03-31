module program_counter(
	input clk, 
	input [15:0] muxout1, 
	output [15:0] address
	);
	
	assign address = muxout1;
	
endmodule
