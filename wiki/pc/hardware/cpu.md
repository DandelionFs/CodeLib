# CPU

记录关于CPU.

THX FOR:
1. Intel 中国.
2. Intel 官网.
3. AMD
4. Intel and Rayon 对比数据对比图请走: http://www.mydrivers.com/zhuanti/tianti/cpu/
5. https://en.wikipedia.org/wiki/Xeon
6. https://en.wikipedia.org/wiki/Celeron
7. https://zhuanlan.zhihu.com/p/77556255
8. https://www.zhihu.com/question/294387995/answer/490353572



## PREFACE

搬运来自知乎的笔记本CPU简单识别流程:

> 举例-> i5-7300HQ 

1. 其中i5叫做前缀，前缀是指定位级别，从低到高分为三种i3、i5、i7，可以理解为低端、中端、高端。建议选购i5，可以满足大部分游戏需求。i7相对于i5提升不大，价格却很高，性价比不值，发烧友可以考虑。
2. 其中HQ叫做后缀，**H代表标压并且不可拆卸，也就是封装，无法进行更换**。**Q代表四核处理器，其他的字母比如U代表低压，K代表超频，Y代表超低电压**。可理解为U、Y是低性能处理器，一般用于轻薄本；HQ为标准性能处理器，一般用于5k-10k的游戏本；HK为高性能处理器，一般用于10k+的游戏本。轻薄本使用U已足够，游戏本使用H已足够。
3. 其中数字7300,7代表第七代（目前最新是第八代，前些日子刚出），300代表性能定位，数字越高性能越强。


## Intel

- Xeon(至强)
  - Targeted at the non-consumer workstation, server, and embedded system markets
  - Some advanced features such as support for ECC memory, higher core counts, support for larger amounts of RAM, larger cache memory and extra provision for enterprise-grade reliability, availability and serviceability (RAS) features responsible for handling hardware exceptions through the Machine Check Architecture
- Core(酷睿)
- Pentium(奔腾)
  - 作为其x86处理器品牌之一，于1993年推出。以往，“奔腾”是英特尔的唯一的x86处理器产品线，后来随着其产品线的扩展派生出低端的“赛扬”（Celeron）系列、供服务器以及工作站使用的“至强”（Xeon）系列。2006年英特尔推出“酷睿”（Core）系列处理器产品线，取代原奔腾处理器系列的市场定位。时至今日，“奔腾”这个品牌仍然继续使用，但市场定位被定位为比低端入门型的赛扬系列高一级、比主流型的酷睿系列低一级的中间级别。
- Celeron(赛扬)
  - **Celeron** is a brand name given by Intel to a number of different low-end [IA-32](https://en.wikipedia.org/wiki/IA-32) and [x86-64](https://en.wikipedia.org/wiki/X86-64) computer microprocessor models targeted at low-cost personal computers.

- [Died] Atom (凌动): 准确的说法是intel在桌面和移动端放弃了atom品牌.
- Movidius VPU: 低功耗视觉处理器
- [Died] Quark (夸克)
  - 2013年的时候，英特尔为了与ARM芯片抢占智能穿戴设备和物联网等产业的市场，就推出了Quark(夸克)系列处理器，而目前最新的Quark处理器产品是2015年发布的，随着智能穿戴设备市场没么火了，Quark也走向了终点。
  - Intel发出通知，包括SoC、处理器及微控制器在内的13款Quark芯片将从2019年7月18日开始退役，预计最终出货时间为2022年7月17日。


## AMD

- RYZEN Threadripper: 专为需要超凡性能台式处理器的人们打造，如专业人士、创意工作者和性能发烧友
- RYZEN 速龙

## Questions

#### 手机的CPU制程工艺已经到达7nm，而计算机还停留在14nm？
**[来源]**: 

Intel的14nm+++综合性能优于台积电和三星的10nm，至于台积电三星的7nm，事实上已经是超过牙膏厂的14nm+++了。而严格意义上来说，牙膏厂也不是全系14nm，如最新的的i3已经用上10nm了，而牙膏厂的10nm是优于台积电三星的7nm的，所以预估Intel下一代正式启动10nm。

Intel 电脑cpu死守14nm，是因为电脑和手机的需求不同，**手机cpu更追求功耗和散热，电脑CPU更追求绝对性能**，**Intel用成熟的工艺维持高频率保障高性能，至于用户担心的只有电费，但是那点电费算个毛**。而手机CPU就很好理解了，845和A11再吊，**手机就那点空间，电池就那么大，所以追求最新的制程工艺以获取最好的功耗和散热也是可以理解的**。


## DETAILS
- IPC(Instruction Per Clock, 每个时钟的指令), 代表一款CPU的设计架构，一旦该CPU设计完成之后，IPC值就不会再改变了。
  - **CPU性能=IPC(CPU每一时钟周期内所执行的指令多少)×频率(MHz时钟速度)，**
  - 
- 
