/**
 * PLL configuration
 *
 * This Verilog module was generated automatically
 * using the icepll tool from the IceStorm project.
 * Use at your own risk.
 *
 * AND MODIFIED
 *
 * Given input frequency:        16.000 MHz
 * Requested output frequency:   32.000 MHz
 * Achieved output frequency:    32.000 MHz
 */

module pll(
	input  clock_in,
	output clock_out,
	output locked
	);

SB_PLL40_CORE #(
		.FEEDBACK_PATH("SIMPLE"),
		.DIVF(1),	// DIVF = 14
		.DIVQ(0),		// DIVQ =  7
		.DIVR(0),		// DIVR =  1
		.FILTER_RANGE(3'b001)	// FILTER_RANGE = 1
	) uut (
		.LOCK(locked),
		.RESETB(1'b1),
		.BYPASS(1'b0),
		.REFERENCECLK(clock_in),
		.PLLOUTCORE(clock_out)
		);
  defparam uut.DELAY_ADJUSTMENT_MODE_FEEDBACK = "FIXED";
  defparam uut.FDA_FEEDBACK = 4'b0000;
  defparam uut.DELAY_ADJUSTMENT_MODE_RELATIVE = "FIXED";
  defparam uut.FDA_RELATIVE = 4'b0000;
  defparam uut.SHIFTREG_DIV_MODE = 2'b00;
  defparam uut.PLLOUT_SELECT = "GENCLK";
  defparam uut.ENABLE_ICEGATE = 1'b0;
endmodule
