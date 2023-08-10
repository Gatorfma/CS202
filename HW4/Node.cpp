module Register_Testbench();
	logic clk, reset, load, shift;
	logic[7:0] in;
	logic out;

	Register dut(clk, reset, load, shift, in, out);

	always begin
		clk = 0; #5;
		clk = 1; #5;
	end

	initial begin
		load = 0; shift = 0; in = 8'b00000000; #5;
		reset = 1; #5;
		reset = 0; #5;

		in = 8'b10101010; load = 1; #50;
		load = 0; shift = 1; #50;
	end
endmodule