---
date: 2020-07-04 21:30:00
---

## 早期历史

> 计算机与网络发展的历史及其标准化过程、OSI参考模型、网络概念的本质、网络构建的设备等

**[发展方向]**：算盘	-->	步进计算器	-->	 差分机	-->	分析机	-->	打孔卡片制表机

**[贡献人]**：

1. [查尔斯 · 巴贝奇](https://baike.baidu.com/item/%E6%9F%A5%E5%B0%94%E6%96%AF%C2%B7%E5%B7%B4%E8%B4%9D%E5%A5%87/5466849)（Charles Babbage）—— 用机械来计算数学表 
2. [阿达 · 洛芙莱斯](https://baike.baidu.com/item/%E9%98%BF%E8%BE%BE%C2%B7%E6%B4%9B%E8%8A%99%E8%8E%B1%E6%96%AF?fromtitle=Ada+Lovelace&fromid=6825878)（Ada Lovelace）——计算机程序创始人，建立了循环和子程序概念 

**[历程]：**

1. **算盘**——社会规模远超个人心算能力; 在公元2020年的巴比伦就可能有算盘，在公元前五世纪希腊的希罗多德有纪录埃及人有使用，后来其希腊字**άβακασ**成为拉丁文、英文的**abacus**。而相对应的, **星盘**——计算在海上的经纬度；计算尺，帮助计算乘法和除法；而世界上有成千上万种不同的时钟(待补充)

2. Computer从 代职业 变成指代 机器. 在这之前有专门计算的人——计算者（持续到1800年）

3. 步进计算器——第一个可以做加减乘除的机器(延续了300多年)

4. 炮弹进行精校，要计算弹道，二战是查表来做，但是每一次改进就要一张新表, 因成本(金钱+时间成本)，发明除了查表（射程表）

5. 查尔斯·巴贝奇提出**差分机**（最终失败）（1991年成功发明），制造它的过程中，想到分析机（通用计算机）(1823)

6. 阿达·洛芙莱斯给**分析机**假象程序，是第一个程序猿

7. 人口普查10年一次，赫尔曼·何乐礼（Herman Hollerith）（ 创办了制表机器公司（Tabulating Machine Company），后来成为IBM的前身 ）的打孔制表机大大提升了效率，可以解决数据密集 的方面

注意:

1. **以往认为算盘为中国发明的观点并不可靠。事实上，在古中国开始广泛流行算盘已晚至宋元时期，此前通行的是筹算**。

> 在巴比伦、罗马都出土过接近今日中国算盘形制的算板实物，其算盘的形制相对上有着较清晰的演进轨迹。此外，包括北非的古埃及、中亚的俄罗斯、中古欧洲都有形制与之类似的手算盘。因此不能说算盘为中国所独有之巧思。客观来看，算盘是各地人类因应计算需要，透过文明交流而相互参考、逐渐完善的过程。在中国，隶首传说发明珠算，见于东汉末三国时期徐岳撰、北周汉中郎甄鸾注的《数术记遗》：“隶首注术，乃有多种，及余遗忘，记忆数事而已。其一积算...其一珠算，其一计算。”此书也记述中国古代太一算、两仪算、三才算等早期算盘。

2. 互联网的早期目的是解决 物理硬盘 拷贝不方便的问题, 通过远程的网络实现远程数据传输. 方便在**即时**. 其实和后来渠道上的收费不大冲突.
3. **瘦身**: 20世纪90年代上半叶，个人电脑与UNIX工作站从性能上已不亚于一台主机。再加上个人电脑与UNIX工作站本身的网络功能不断提高，利用这些设备搭建一个网络要比使用大型主机构建网络更有优势(操作简单，价格低廉)。由此也引发了一个旨在降低网络架构成本的新趋势。之所以叫“瘦身”是因为这一趋势导致那些曾经在大型主机上才能运行的公司核心业务系统逐渐被转移到“轻量型”的个人电脑或UNIX工作站上去运行。从机体规模 & 成本上都有些“瘦身减负”之意.
4. 分时系统的实现: 一个CPU通常在同一时间只能运行一个程序。为了让多个程序同时运行，操作系统采用CPU时间片轮转机制，在多个程序之间进行切换，合理调度。这种方式叫做多任务调度。

**网络交换机**

> A network switch is a multiport [network bridge](https://en.wikipedia.org/wiki/Network_bridge) that uses [MAC addresses](https://en.wikipedia.org/wiki/MAC_address) to forward data at the [data link layer](https://en.wikipedia.org/wiki/Data_link_layer) (layer 2) of the [OSI model](https://en.wikipedia.org/wiki/OSI_model). Some switches can also forward data at the [network layer](https://en.wikipedia.org/wiki/Network_layer) (layer 3) by additionally incorporating [routing](https://en.wikipedia.org/wiki/Routing) functionality. Such switches are commonly known as layer-3 switches or [multilayer switches](https://en.wikipedia.org/wiki/Multilayer_switch).Switches for [Ethernet](https://en.wikipedia.org/wiki/Ethernet) are the most common form of network switch. The first Ethernet switch was introduced by [Kalpana](https://en.wikipedia.org/wiki/Kalpana_(company)) in 1990.[[3\]](https://en.wikipedia.org/wiki/Network_switch#cite_note-3) Switches also exist for other types of networks including [Fibre Channel](https://en.wikipedia.org/wiki/Fibre_Channel), [Asynchronous Transfer Mode](https://en.wikipedia.org/wiki/Asynchronous_Transfer_Mode), and [InfiniBand](https://en.wikipedia.org/wiki/InfiniBand).Unlike less advanced [repeater hubs](https://en.wikipedia.org/wiki/Repeater_hub), which broadcast the same data out of each of its ports and let the devices decide what data they need, a network switch forwards data only to the devices that need to receive it.-- Wikipedia
>
> 网络交换机是一个多端口[网络桥](https://en.wikipedia.org/wiki/Network_bridge)，使用[MAC地址](https://en.wikipedia.org/wiki/MAC_address)在[OSI模型](https://en.wikipedia.org/wiki/OSI_model)的[数据链路层](https://en.wikipedia.org/wiki/Data_link_layer)（第2层）转发数据。一些交换机还可以通过附加合并[路由](https://en.wikipedia.org/wiki/Routing)功能在[网络层](https://en.wikipedia.org/wiki/Network_layer)（第3层）转发数据。这种开关通常被称为第三层开关或[多层开关](https://en.wikipedia.org/wiki/Multilayer_switch)。[以太网](https://en.wikipedia.org/wiki/Ethernet)交换机是网络交换机的最常见形式。[Kalpana](https://en.wikipedia.org/wiki/Kalpana_(company))于1990 年推出了第一台以太网交换机。[[3\]](https://en.wikipedia.org/wiki/Network_switch#cite_note-3)交换机还用于其他类型的网络，包括[光纤通道](https://en.wikipedia.org/wiki/Fibre_Channel)，[异步传输模式](https://en.wikipedia.org/wiki/Asynchronous_Transfer_Mode)和[InfiniBand](https://en.wikipedia.org/wiki/InfiniBand)。与较不先进的[转发器集线器](https://en.wikipedia.org/wiki/Repeater_hub)不同，[转发器集线器](https://en.wikipedia.org/wiki/Repeater_hub)从其每个端口广播相同的数据，并让设备决定所需的数据，而网络交换机仅将数据转发给需要接收数据的设备．

总结一下就是如下图所示:

![](http://i.dfslfh.cn/%E8%AE%A1%E7%BD%91%E5%8E%86%E5%8F%B2.png)



## 协议

| 网络体系结构                                                 | 协议                                                 | 主要用途                 |
| :------------------------------------------------------------: | :----------------------------------------------------: | :------------------------: |
| TCP/IF                                                       | IP, ICMP, TCP, UDP, HTTP, TELNET, SNMP, SMTP.... | 互联网、局域网           |
| IPX/SPX     Net Ware)                                        | IPX, SPX, NPC....                                    | 个人电脑局域网           |
| AppleTalk                                                    | DDP, RTMP, AEP, ATP, ZIP..                           | 苹果公司现有产品的局域网 |
| DECnet                                                       | DPR, NSP, SCP....                                    | 前DEC小型机              |
| OSI                                                          | FTAM, MOTIS, VT, CMIS/CMIP, CLNP, CONP...       | ......                   |
| XNS(Xerox Network Services)(Novell公司开发的NetWare系统的协议) | IDP, SPP, PEP...                                     | 施乐公司网络             |

### 分组交换协议

> **分组交换是指将大数据分割为一个个叫做包（Packet）的较小单位进行传输的方法。这里所说的包，如同我们平常在邮局里见到的邮包。分组交换就是将大数据分装为一个个这样的邮包交给对方。**

计算机通信也会在每一个分组中附加上源主机地址和目标主机地址送给通信线路。这些发送端地址、接收端地址以及分组序号写人的部分称为“报文首部”。



## 机构标准化

> 所谓标准化是指使不同厂商所生产的**异构产品之间具有兼容性、便于使用的规范化过程**。标准化组织大致分为三类：
>
> **国际级标准化机构:** **ISO、ITU-TV**(International Telecommuni-cation Union Telecommunication Standardization Sector。制定远程通信相关国际规范的委员会。是ITU（International Telecommunication Union：国际电信联盟）旗下的一个远程通信标准化组。前身是国际电报电话咨询委员会（CCITT：International Telegraph andTelephone Consultative Com-mittee）)等
>
> **国家级标准化机构**: **JISC**（制定了日本**JIS**）和美国的**ANSI**
>
> **民间团体**: **IETF**等组织。



## OSI参考模型

|      | 分层名称   | 功能                                                         | 每层功能概牲                                   |
| ---- | ---------- | ------------------------------------------------------------ | ---------------------------------------------- |
| 7    | 应用层     | 针对特定应用的协议。                                         | **针对每个应用的协议**   XX-> XX协议           |
| 6    | 表示层     | 设备固有数据格式和网络标准数据格式的转换。                   | 接收不同表现形式的信息,如文字流、图像、声音等  |
| 5    | 会话层     | 通信管理。负责建立和断开通信连接(数据流动的 逻辑通路) 管理传输层以下的分层。 | 何时建立连接,何时断开连接以及 保持多久的连接?  |
| 4    | 传输层     | 管理两个节点之间的数据传输。负责可靠传输 (确保数据被可靠地传送 到目标地址)。 | 是否有數据丢失?                                |
| 3    | 网络层     | 地址管理与路由选择。                                         | 经过那个路由传递到目标地址?                    |
| 2    | 数据链路层 | 互连设备之间传送和识别数据帧。                               | 数据帧与比特流之间的转换 分段转发              |
| 1    | 物理层     | 以“0” "1"代表电压的高低、灯光的闪灭。 界定连接器和网线的规格。 | 比特流与电子信号之间的切换; 连接器与网线的规格 |

注意:

1. **OSI 协议 != OSI 参考模型**: OSI 协议是为了让异构的计算机之间能够相互通信的、由ISO和ITU-T推进其标准化的一种网络体系结构。



## 传输分类

### 网络发送数据

1. 面向有连接型
2. 面向无连接型

### 交换方式

1. 电路交换
2. 分组交换

### 接收端数量

1. 单播（Unicast）
2. 广播（Broadcast）
3. 多播（Multicast）
4. 任播（Anycast）

## 网络的层次

**IP地址 & MAC地址**: 区别在于后者没有层次性. 

> 人们可以通过 NIC (Network Interface Card) 制造商识别号、制造商内部产品编号以及产品通用编号确保MAC地址的唯一性。然而，人们无法确定哪家厂商的哪个网卡被用到了哪个地方。虽然MAC地址是真正负责最终通信的地址，但是在实际寻址过程中，IP地址却必不可少。

**Ip地址**: 网络号+主机号

网络传输中，每个节点会根据分组数据的地址信息，来判断该报文应该由哪个网卡发送出去。为此，各个地址会参考一个发出接口列表。在这一点上MAC寻址与IP寻址是一样的。只不过MAC寻址中所参考的这张表叫做地址转发表，而IP寻址中所参考的叫做路由控制表( 自动生成 )。MAC地址转发表中所记录的是实际的MAC地址本身，而路由表中记录的IP地址则是集中了之后的网络号(网络号与子网掩码)。

> Q: 家用路由器是不是有交换机的功能？

A: 忽略wan口以后就成了一个有4个lan口的交换机. 事实上家用路由器由一个真路由器和一个交换机组成，路由器由两个端口(wan口，另外一个在内部与交换机相连，交换机露出4个Lan口)

## 网络构成

|           设备            | 作用                                  |
| :-----------------------: | ------------------------------------- |
|           网卡            | 使计算机连网的设备(Network Interface) |
|     中继器(Repeater)      | 从物理层上延长网络的设备              |
|  网桥(Bridge) /2层交换机  | 从数据链路层上延长网络的设备          |
| 路由器(Router) /3层交换机 | 通过网络层转发分组数据的设备          |
|        4-7层交换机        | 处理传输层以上各层网络传输的设备      |
|       网关(Gateway)       | 转换协议的设备                        |

### DataLink

Datalink 指相互直连的设备之间进行通信所涉及的协议及其网络。为此，有众多传输介质与之对应。

| 数据链路名 | 通信媒介                  | 传输速率                             | 主用途  |
| ---------- | ------------------------- | ------------------------------------ | ------- |
| 以太网     | 同轴电缆                  | 10Mbps                               | LAN     |
| 以太网     | 双绞线电缆                | 10Mbps-100Gbps                       | LAN     |
| 以太网     | 光纤电缆                  | 10Mbps-100Gbps                       | LAN     |
| 无线       | 电磁波                    | 数个Mbps-                            | LAN-WAN |
| ATM        | 双绞线电缆 <br />光纤电缆 | 25 Mbps <br />155 Mbps <br />622Mbps | LAN-WAN |
| FDDI       | 光纤电缆 <br />双绞线电缆 | 100Mbps                              | LAN-MAN |
| 帧中继     | 双绞线电缆 <br />光纤电缆 | 约64k-1.5Mbps                        | WAN     |
| ISDN       | 双绞线电缆 <br />光纤电缆 | 64k-1. 5Mbps                         | WAN     |

注意:

1. **吞吐量:** 主机之间实际的传输速率被称作吞吐量。其单位与带宽相同，都是bps（Bits Per Second）。吞吐量这个词不仅衡量带宽，同时也衡量主机的CPU处理能力、网络的拥堵程度、报文中数据字段的占有份额（不含报文首部，只计算数据字段本身）等信息。

### 网卡 - NIC

网络接口卡、 网络适配器、网卡、LAN卡。

很多产品目录中都加入了“内置LAN端口”的参数，说明越来越多的计算机在出厂设置中就具备了以太网（Ethernet）1000BASE-T 或100BASE-TX的端口。没有配置NIC的计算机如果想接人以太网，至少得外接一个扩展槽以便插人NIC。无线局域网的情况下也是如此，计算机必须具备能够接人无线网的NIC才能保证连接到网络。笔记本电脑如果没有内置的NIC，可以通过ExpressCard或CardBus、压缩闪存以及USB方式插一块NIC以后再连网。

注意:

1. **ExpressCard：**笔记本电脑中的卡型扩展设备。由制定PC卡标准的PCMCIA{Personal Computer Memory Card International Association，PC机内存卡国际联合会）统一规格。
2. **CardBus: **PC卡, 旧称PCMCIA(**P**ersonal **C**omputer **M**emory **C**ard **I**nternational **A**ssociation), 又被谐称为“人们记不住计算机产业缩略词”（People Can't Memorize Computer Industry Acronyms）或“个人电脑制造商不能创造出个新的缩略词”（Personal Computer Manufacturers Can't Invent Acronyms）

### 中继器(Repeater)

在OSI模型的第1层一物理层面上延长网络的设备。由电缆传过来的电信号或光信号经由中继器的波形调整和放大再传给另一个电缆。

距离有限。如一个10Mbps的以太网最多可以用4个中继器分段连接，而一个100Mbps的以太网则最多只能连两个中继器。

可以提供多个端口服务。这种中继器被称作中继集线器或集线器(Hub,但现在人们常说的Hub更多是指交换式集线器)。因此，集线器也可以看作是多口中继器，每个端口都可以成为一个中继器。

注意:

1. 中继器无法连接一个 100Mbps 的以太网和另一个 0Mbps 的以太网。连接两个不同速度的网络需要的是网桥或路由器这样的设备。

### 网桥(Bridge) /2层交换机

第2层, 在数据链路上连接两个网络的设备

识别数据链路层中的数据帧(分组数据)，并将这些数据帧临时存储于内存，再重新生成信号作为一个全新的帧转发给相连的另一个网段。由于能够存储这些数据帧，网桥**能够连接10BASE—T与100BASE—TX等传输速率完全不同的数据链路**，**并且不限制连接网段的个数。**

数据链路的数据帧中有一个数据位叫做FCS，用以校验数据是否正确送达目的地。网桥通过检查这个域中的值，将那些损坏的数据丢弃，从而避免发送给其他的网段。此外，网桥还能通过**地址自学机制(**有些网桥能够判断是否将数据报文转发给相邻的网段，这种网桥被称作自学式网桥,	这类网桥会记住曾经通过自己转发的所有数据帧的MAC地址，并保存到自己里的内存表中。由此，可以判断哪个网段中包含持有哪类MAC地址的设备**)和过滤功能控制网络流量**(网络上传输的数据报文的数量).

这里所说的**地址是指MAC地址、硬件地址、物理地址以及适配器地址**，也就是网络上**针对NIC分配的具体地址**。主机A与主机B之间进行通信时，只针对主机A发送数据帧即可。网桥会根据地址自学机制来判断是否需要转发数据帧。

这类功能是OSI参考模型的第2层（数据链路层）所具有的功能。为此，有时也把网桥称作2层交换机（12交换机）。

以太网等网络中常使用交换集线器（Hub），现在基本也属于网桥的一种。交换集线器中连接电缆的每个端口都能提供类似网桥的功能。

注意:

1. FCS: 用CRC (Cyclic RedundancyCheck,循环冗余校验码)方式校验数据帧中的位。有时由于噪音导致通信传输当中数据信号越来越弱，而这种CRC正是用来检查数据帧是否因此而受到破坏的。
2. 具有网桥功能的Hub叫做交换集线器。只有中继器功能的Hub叫做集线器。

### 路由器(Router) /3层交换机

第3层, 在网络层面上连接两个网络、并对分组报文进行转发的设备。

网桥是根据物理地址（MAC地址）进行处理，而**路由器/3层交换机则是根据IP地址进行处理的。由此， TCP/IP中网络层的地址就成为了IP地址**。

路由器可以连接不同的数据链路。例如连接两个以太网，或一个以太网与一个FDDI。现在在家或办公室里连接互联网时所使用的宽带路由器也是路由器的一种。

路由器还有分担网络负荷的作用，甚至有些路由器具备一定的网络安全功能。

注意:

1. 由于路由器会分割数据链路，因此数据链路层的广播消息将无法继续传播。

### 4-7层交换机

处理从传输层至应用层的数据。如果用TCP/IP分层模型来表述， 4—7层交换机就是以TCP等协议的传输层及其上面的应用层为基础，分析收发数据，并对其进行特定的处理。

例如，对于并发访问量非常大的一个企业级Web站点，使用一台服务器不足以满足前端的访问需求，这时通常会架设多台服务器来分担。这些服务器前端访问的入口地址通常只有一个（企业为了使用者的方便，只会向最终用户开放一个统一的访问URL），为了能通过同一个URL将前端访问分发到后台多个服务器上，可以在这些服务器的前端加一个**负载均衡器**。这种负载均衡器就是4—7层交换机的一种。

**带宽控制**: 实际通信当中，人们希望在网络比较拥堵的时候，优先处理像语音这类对及时性要求较高的通信请求，放缓处理像邮件或数据转发等稍有延迟也并无大碍的通信请求。除此之外，还有很多。例如**广域网加速器**、**特殊应用访问加速以及防火墙**（可以防止互联网上的非法访问）等也有 4—7层交换机得到应用。

注意:

1. **负载均衡还可以通过DNS 实现**。通过对多个IP地址配置同一个名字，每次查询到这个名字的客户得到其中的某一个地址，从而使不同客户访问不同的服务器。该方法也称作循环复用DNS技术。

### 网关(Gateway)

从传输层到应用层的数据**进行(不同协议)转换和转发的设备**。与4—7层交换机一样都是处理传输层及以上的数据，但是网关不仅**转发数据**还负责对**数据进行转换**，它通常会使用一个表示层或应用层网关，在两个不能进行直接通信的协议之间进行翻译，最终实现两者之间的通信。

一个非常典型的例子就是互联网邮件与手机邮件之间的转换服务。手机邮件有时可能会与互联网邮件互不兼容，这是由于它们在表示层和应用层中的“电子邮件协议”互不相同所导致的。那么，为什么连到互联网的电脑与手机之间能够互发电子邮件呢？互联网与手机之间设置了一道网关。网关负责读取完各种不同的协议后，对它们逐一进行合理的转换，再将相应的数据转发出去。这样一来即使应用的是不同电子邮件的协议，计算机与手机之间也能互相发送邮件。



## 参考资料

1. https://github.com/1c7/crash-course-computer-science-chinese
2. 《图解TCP IP(第5版)》.(日)竹下隆史