
module full_adder_4bit(in, sum);
    input   in;
    output  [15:0] sum;
    assign   sum = in + 4;
    
endmodule