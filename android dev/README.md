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


## 为什么 Android 的机器主频和核心数比 iPhone 高，却没有更流畅？[^2]

1. **硬件角度**: 
   1. CPU方面，两者CPU型号分别为：A7和MSM8974。MSM8974拥有4核，单核频率最高可达2.3GHz，相比A7拥有2核，最高频率为1.4GHz。所以，就单纯的CPU计算能力来讲，MSM8974要优于A7，毕竟它单核频率比A7要高很多。另外，由于MSM8974有4核，因此它处理多线程并发能力要强于A7。工艺方面，两者拥有相同的28nm制程，但MSM8974频率高，核心多，所以密集计算情况下，它的功耗和发热量应该要比A7高。从CPU的Cache方面看，A7拥有64KB+64KB的L1 Cache，1MB L2 Cache和4MB L3 Cache；相比较，MSM8974在这方面要差得多，相信是为了节约成本，仅仅配置了16KB+16KB L1 Cache, 2MB L2 Cache，且没有L3 Cache。如此小的Cache，在实际运行过程中，肯定会发生大量Cache Miss，这就会导致CPU常常在“等待”外围IO（如内存），从而白白浪费了CPU的高速计算能力。MSM8974在Cache的配置上，犹如V8引擎的跑车，却配置了一套四速变速箱，让人无语。
   2. GPU方面，A7集成PowerVR G6430 GPU，而MSM8974集成了Adreno 330 GPU。根据资料，G6430的图形处理性能GFLOPS为166.4-249.6，而Adreno 330的图形处理性能GFLOPS仅为129.6-158.4。所以，PowerVR G6430的图形性能要明显优于Adreno 330。
   3. 内存（运存）方面，设备配置的内存越大，表示操作系统允许更多的应用程序驻留内存，在不同的应用程序之间切换会更顺畅。而且，每个应用程序允许使用的内存也会越大，相对来说会更流畅。这方面Nexus的2GB内存要占优。
2. **操作系统角度**: Apple IOS，apple开发的移动设备操作系统。IOS的内核使用的是darwin os，该内核与linux的宏内核操作系统不同，是一个类似于windows的混合型内核。有点类型微内核的感觉，不过就性能而言，与Linux相比应该没有什么优势。但是，因为ios的应用程序是使用objective c编码，最终被直接编译为ARM指令集。因此，在实际设备运行过程中，应用程序相当于直接在CPU上运行，避免了虚拟机的指令翻译开销，所以ios的应用程序执行效率相比android要高。Google Android，是基于Linux操作系统的一个应用程序框架。它大致由以下几个组件组成：Linux内核、Android运行库、通用组件库、应用程序框架和应用程序本身。最终的用户应用程序均运行在一个个隔离的“沙箱”环境中，彼此隔离。其中，最重要的是，Android应用程序的指令不是机器指令，而是dalvik虚拟机指令。也就是说，Android提供了一个Dalvik虚拟机，将Android应用程序的dalvik指令翻译成最终的arm机器指令。这中间虚拟机的翻译过程是有性能损耗的。
3. **应用程序角度**: IOS禁止应用程序在后台运行，所有切换到后台的应用程序被操作系统自动休眠，只有前台程序可以占用CPU；相比较，Android就开放得多，它运行应用程序任意创建后台服务Service，所有Service都可以在后台任意占用CPU和内存。因此，当Android安装的应用程序越来越多，且应用程序毫无节制地创建后台服务的话，系统前台应用就被迫和越来越多的后台服务共享CPU资源，从而拖慢了整个系统的速度。也不能说Android这种真正的多任务模式不好，它是一把双刃剑，给应用程序更广阔的发挥空间的前提下，也给了应用程序滥用CPU的权限。因此，从这方面讲，IOS更有利于应用程序发挥流畅性，但代价是应用程序无法再后台工作；Android更有利于发挥应用程序功能，例如后台收离线消息，后台下载等应用。
4. 从**屏幕分辨率**来看，IOS只有有限几种分辨率，最高也就1136*640，都没有达到1080P全高清的级别。比较而言，Nexus5的分辨率达到了1080*1920全高清级别。为此，应用程序需要更多资源来渲染图像，比较而言，IOS的应用程序就可以更容易达到流畅的帧数；但Nexus5的屏幕则可以达到更锐利，更清晰的图像。


[^1]:https://www.zhihu.com/question/33423859/answer/57133469
[^2]:https://www.zhihu.com/question/22836307/answer/22853689