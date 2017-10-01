module AsyncReadMem
#(parameter NUM_BYTES = (1 << 21),
  parameter DATA_WIDTH = 32)
  (
    input clk,
    input reset,

    input [ADDR_WIDTH-1:0] dw_addr,
    input [DATA_WIDTH-1:0] dw_data,
    input [MASK_WIDTH-1:0] dw_mask,
    input dw_en,

    input [ADDR_WIDTH-1:0] dataInstr_0_addr,
    output [DATA_WIDTH-1:0] dataInstr_0_data,
    input [ADDR_WIDTH-1:0] dataInstr_1_addr,
    output [DATA_WIDTH-1:0] dataInstr_1_data
  );

  localparam ADDR_WIDTH = $clog2(NUM_BYTES);
  localparam MASK_WIDTH = DATA_WIDTH >> 3;

  reg [7:0] 		mem [0:NUM_BYTES-1];

  initial begin
    $readmemh("bin.txt", mem);
  end

  genvar i;
  generate
  for (i = 0; i < MASK_WIDTH; i = i + 1) begin : gen_sel_read
    always @ (posedge clk) begin
      if (dw_en) begin
        if (dw_mask[i] == 1'b1) begin
          mem[dw_addr + i] <= dw_data[i*8 +: 8];
        end
      end
    end

    always @* begin
      dataInstr_0_data[i*8 +: 8] = mem[dataInstr_0_addr + i];
      dataInstr_1_data[i*8 +: 8] = mem[dataInstr_1_addr + i];
    end
  end 
  endgenerate

  /*
   // for debugging
  always @ (posedge clk) begin
    $fwrite(32'h80000002,"byte1= 0x%h byte2= 0x%h\n", mem[32'h402dc], mem[32'h402dd]);
      if (dw_en) begin
        $fwrite(32'h80000002,"dw_mask= 0x%h dw_addr= 0x%h dw_data= 0x%h\n", dw_mask, dw_addr, dw_data);
      end
  end
  */
endmodule // AsyncReadMem
