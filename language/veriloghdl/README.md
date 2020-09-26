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





## [归约运算符](https://www.cnblogs.com/zhongguo135/p/4376031.html)

https://www.cnblogs.com/zhongguo135/p/4376031.html



归约运算符是一元操作数，相当于C中的单目运算符。它是对一个操作数进行位操作，最后得到一个一位的数。

归约运算的过程是第一步先用操作数的第一位和第二位进行位操作，然后再用第一步的结果和操作的数的下一位

进行位操作，如此重复直到最后一位。

1、归约与

![img](https://images0.cnblogs.com/blog2015/378458/201503/291818424429003.jpg)

2、归约或

![img](https://images0.cnblogs.com/blog2015/378458/201503/291819073641051.jpg)

3、归约异或

![img](https://images0.cnblogs.com/blog2015/378458/201503/291819377394030.jpg)

一个例子

![img](https://images0.cnblogs.com/blog2015/378458/201503/291817069425561.jpg)

a = 4'b0000;

&a = 0; ~&a = 1 ;|a = 0 ; ~|a = 1; ^a = 0; ~^a = 1


# 时钟脉冲概念

常看到说，时钟信号是用来“同步”系统各器件（CPU、内存、总线等）的工作的。但是这里的“同步”实在是太笼统了。什么是“同步”？各器件为什么要同步？
以下内容为个个学习总结出来的观点，不保证其正确性
下面举存储器的例子来说明。
先要了解到“存储器”是用触发器(flip-flop)或电容器(capacitor)做的。用触发器的就是SRAM，用电容器的就是DRAM。因为电容是会不断放电的，所以要不断对其充电（刷新），所以才叫做Dynamic RAM。
然后要了解到，触发器和电容器做的都分为两类：不同步的和同步的。不同步的触发器叫做简单(simple)或透明(transparent)触发器；同步的触发器叫做钟控(clocked)触发器。另一方面，不同步的电容器做的RAM就叫DRAM，同步的电容器做的RAM就叫SDRAM。

触发器和电容器都是放在电路里工作（例如返回它们保存的值，设置它们的值等）的；它们工作是要时间的；它们完成工作后，要“通知”其他器件它们工作完成了（这就是各器件要“同步”的原因）。“通知”方式就有两种：通过外部时钟信号和其他方式（例如不同步的CPU用的"pipeline controls" or "FIFO sequencers."等）。通过外部时钟信号来告诉其他部件工作已完成就叫做“同步”。具体地说，就是触发器和电容器在一个时钟周期内必须完成工作，这样其他部件就可以认为是“被通知了”。


我们知道电信号以低电压和高电压来区分1和0，假如我们要传输一段01010101的电信号，只要根据变化就能区分出来得到正确的解析，但是如果我们需要传输一段0000的电信号，你就会发现一个问题，那就是我到底传输了几个0？因为电信号一直没有变化，无法区分，所以时钟信号的作用就在这里，根据时间间隔来分割每一段电信号。
