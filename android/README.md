---
date: 2020-07-14 05:00:00
---



## Emulator Slow - 模拟器速度太慢

### Reason[^1]

两点原因:

+ Intel X86/64 上运行 ARM , 指令异常, 所以采用模拟, 模拟带来的时间损耗是数量级的. 利用QEMU转x86解释执行，效率远低于hyper-v的x86硬件虚拟化。
 > 这不同于virtualbox里跑linux，guest指令几乎不用模拟直接在host cpu上执行(?????) 
+ 渲染软实现, 没有 Host 端硬件加速.

对比iOS: 模拟了一个运行iOS环境的虚拟机，所有iOS代码compiled之后都可以mac-native的速度运行。而QE模拟了包括storage system, screen在内的几乎所有的硬件。


### Recommend

1. BlueStack
2. 海马王技术:
> virtualbox+androidx86+intel libhoudini+host渲染加速
>
> **virtualbox解决emulator载体问题**，
> **android x86**使得guest是x86架构，在系统层面确保gust host架构相同，免除指令模拟，
> **intel libhoudini** 是intel提供的免费但不开源arm to x86指令翻译工具，这个工具使得只提供了arm so的app在emulator成为可行且性能不错(由于不开源，不知道翻译是发生在哪个阶段，但我猜是运行时动态翻译，文档显示翻译后性能接近直接跑x86指令，实测的确如此！)
> **host渲染加速**基本原理是，在guesthost间建立一条高速数据传输通道，将guest端渲染命令打包传给host端，host端解包再执行命令，最后把结果返回，注意，这里很多时候是要求同步的，这也是为什么强调通道必须高速。另外，别说我为何知道这些细节，因为我正在做这玩意！(?????说了我也不太了解,++)

### Method

1. 保存emulator的snapshot，具体在AVD manager中勾选 "Store a snapshot for faster startup"；
2. 使用硬件加速，比如你在使用的电脑是基于x86架构的，而你需要模拟的android设备也是x86架构的，那么使用硬件加速可以很大的提升emulator的速度，此时你需要安装 Intel’s Hardware Accelerated Execution Manager (HAXM)；





[^1]: https://www.zhihu.com/question/33423859/answer/57133469