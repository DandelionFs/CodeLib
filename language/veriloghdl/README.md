### Prerface

贴出~~自己~~别人的作业.

### Details

```shell
module my(o,t,th,f,out);
  input o,t,th,f;
  output out;
  reg out;
  always @( o or t or th or f)
    begin
      case ({o,t,th,f})
        4'b0000:out<=0;
        4'b0001:out<=0;
        4'b0010:out<=0;
        4'b0011:out<=0;
        4'b0100:out<=0;
		default :out<=1;
      endcase
    end      
endmodule

module Dff_p (clk, d, q,n_q) ;
  input clk, d; 
  output q,n_q;
  reg q ,n_q;
  always @ (posedge clk)
    begin
      q<=d; 
      n_q<= d;
 end 
endmodule

module Dff_p (clk, Reset, Set,d, q,n_q);
  input clk, d, Reset, Set; 
  output q,n_q;
  reg q,n_q;
  always @ (posedge clk or negedge Reset or negedge Set) 
    if (!Reset)
      begin q<=0; n_q<=1; end
  else if (!Set)
    		begin q<=1;n_q=0; end
  			else
    		begin q<=d; n_q<=~d; end
endmodule
```

回头补充......
