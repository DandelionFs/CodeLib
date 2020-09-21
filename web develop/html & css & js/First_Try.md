---
title: '[Front-end] 初探'
date: 2020-01-15 00:00:00
toc: true
---

## 0x00 Preface

> 查了三个小时的英文 Wikipedia 无果，科学上网 倒腾了4个小时无果，Github CLone 奇慢,  我只想说在国内查资料的门槛太高了...... In 2020-01-15 00:00:00
>
> 这个时代的主流技术, 下个时代的预备技术.

<br>

## 0x01  Internet Theory

> 弄清楚计算机是怎样连成网的
>
> 弄清楚一些核心概念和术语的含义，弄清楚它们之间的联系与区别
>
> 理论是贯穿学习始终的,  所以不一定一开始就一定要搞懂和全通

### 1.1 计算机网络

计算机网络（computer network），通常也简称网络，是指**容许节点分享资源的数字电信网络**。在电脑网络，电脑设备会透过节点之间的连接（数据链路）互相交换数据。传输介质可分为有线及无线两类——有线的可用到双绞线、光纤电缆等介质；无线则可用到Wi-Fi、NFC。
当一个设备能够与另一设备交换信息时，便可视它们俩已连接成网络，不论它们是否直连
电脑网络可依照传输介质、传输协议、 网络大小、拓扑、流量控制机制、创建目的等因素区分。**世界上最大的电脑网络为互联网**

**IP数据包** : 由于**网络的最大传输单位**会因技术而异，故在过程中**IP数据包可能需要切割成较小的数据包**，然后在目的地重组。此一方式的传输效率高，但也容易发生壅塞。IP数据包分为两部分：表头及承载数据[2]:7-6。表头包含了目的及来源地址、上层协议、存活时间等信息
**网络拓扑**:（网络的几何形状分类）。影响网络的容错度、管理方式、信息如何流通外、_网络的可靠性和架设成本_（可靠和成本呈现正相关）


- 总线拓扑：所有节点共享一个介质，以此连接其他节点。早期的以太网10BASE5及10BASE2会应用此一拓扑。
- 星状拓扑：所有节点集中连接至一个特殊的设备，例如交换器、集线器。
- 环状拓扑：所有节点以形成一个环状的方式连接，节点间需以顺序的方式发送信息。应用此一拓扑的有IBM Token Ring、IEEE 802.5 Token Ring。
- 网状拓扑：所有节点连接至一个以上的节点。
- 树状网络：所有节点一层一层地以分支形式连接。
- 混合式拓扑：将上述拓扑混合使用。在布置网络时，一般会混合多种拓扑。



**网络连接**：以太网是局域网的主流传输介质技术。以太网的标准行业规格为IEEE 802.3。以太网可以铜线或光纤电缆传输数据。无线局域网则一般会以无线电作传输介质，不过也有以红外线作传输介质的。电力线网络以既有电力线来传输数据。


- 有线网络：同轴线缆以标准10Base2及10Base5来计，其最高速度为10Mbps。光纤是一种玻璃纤维或塑胶。其以光为传递的介质。它的好处为速度快、信号难以衰减。其传输速度可超过2Gbps
- 无线网络：陆上微波通信会以地上发送站来把微波发送至类似卫星的天线接收器。陆上微波的频谱在千兆赫以内——因此所有通信限制在无阻碍的情况下才能顺利进行。基站最高可分开约40公里。通信卫星通信亦会透过微波来实现通信。该些卫星位于太空，一般距离地球地面约36000公里。其可发送语音、GPS、视频等信息。无线电与扩频技术——利用了功率较低的无线电技术的无线局域网。使用了扩频技术的无线局域网可使之间距离不远的设备互相沟通。IEEE 802.11定义了一种十分盛行的无线电技术的开放式标准——Wi-Fi。



创建一个网络还需要一些相关设备，比如**网卡**（ 电脑能够访问传输介质上的数据 ）、**中继器**（ 增强信号的网络设备 ）**集线器**、**桥接器**（ 连接两个独立的网段及过滤之间的流量 ）、**网络交换器**、**路由器**、**调制解调器**、**防火墙**（ 一种控制网络安全和访问规则的网络系统 ， 按特定规则来充许或阻止数据通过 ）

<br>

<br>

#### 互联网

互联网( Internet)是指20世纪末期兴起电脑网络与电脑网络之间所串连成的庞大网络系统。这些网络以一些标准的网络协议相连。它是由从地方到全球范围内几百万个私人、学术界、企业和政府的网络所构成，通过电子，无线和光纤网络技术等等一系列广泛的技术联系在一起。互联网承载范围广泛的信息资源和服务，例如相互关系的超文本文件，还有万维网（WWW）的应用，电子邮件，通话，以及文件共享服务。

<br>

<br>

#### Web


万维网（World Wide Web）亦作**WWW、Web**，是一个透过互联网访问的，由**许多互相链接的超文本组成的系统**。英国科学家**蒂姆·伯纳斯-李**于1989年发明了万维网。1990年他在瑞士CERN的工作期间编写了第一个网页浏览器。网页浏览器于1991年在CERN以外发行，1991年1月最先向其他研究机构发行，并于1991年8月在互联网上向公众开放。


注意：互联网并不等同万维网，**互联网是指凡是能彼此通信的设备组成的网络就叫互联网**，指利用**TCP/IP通讯协定**所创建的各种网络，是国际上最大的互联网，也称“国际互联网”。万维网是一个**由许多互相链接的超文本组成的系统**，通过互联网访问。在此定义下，万维网是互联网的一项服务。不过多数民众并不区分两者，常常混用。

**超文本以及超文本标记**

超文本（Hypertext）是一种可以显示在电脑显示器或其他电子设备的文本，**其中的文字包含有可以链接到其他字段或者文档的超链接**，**允许从当前阅读位置直接切换到超链接所指向的文字**。超文本文档**通过超链接**相互链接，超链接通常通过鼠标点击、按键设置或触屏来点阅。
（笔者这里直接认为是超链接）

超文本标记语言（HyperText Markup Language）是一种用于创建网页的标准标记语言。HTML是一种基础技术，常与CSS、JavaScript一起被众多网站用于设计网页、网页应用程序以及移动应用程序的用户界面[3]。网页浏览器可以读取HTML文件，并将其渲染成可视化网页。HTML描述了一个网站的结构语义随着线索的呈现，使之成为一种标记语言而非编程语言。

HTML元素是构建网站的基石。HTML允许嵌入图像与对象，并且可以用于创建交互式表单，它被用来结构化信息——例如标题、段落和列表等等，也可用来在一定程度上描述文档的外观和语义。HTML的语言形式为尖括号包围的HTML元素（如），浏览器使用HTML标签和脚本来诠释网页内容，但不会将它们显示在页面上。
HTML可以嵌入如JavaScript的脚本语言，它们会影响HTML网页的行为。网页浏览器也可以引用层叠样式表（CSS）来定义文本和其它元素的外观与布局。维护HTML和CSS标准的组织万维网联盟（W3C）鼓励人们使用CSS替代一些用于表现的HTML元素。

<br>

<br>

#### IP

**網際協議** （ **I**nternet **P**rotocol ） 也称**互联网协议**  是用于封包交換数据网络的一种协议。

IP是在TCP/IP协议族中网络层的主要协议，任务仅仅是根据源主机和目的主机的地址来传送数据。为此目的，IP定义了寻址方法和数据报的封装结构。第一个架构的主要版本为IPv4，目前仍然是广泛使用的互联网协议，尽管世界各地正在积极部署IPv6。

<br>

<br>

#### 端口

[参考] : https://blog.csdn.net/flying_man_/article/details/79392923

可以理解 成为黑箱的窗户 吧 : )

那么为什么要给端口[编号](http://www.so.com/s?q=编号&ie=utf-8&src=internal_wenda_recommend_textn)来区分它们呢，既然一个程序开了一个端口，那么不是[外部信息](http://www.so.com/s?q=外部信息&ie=utf-8&src=internal_wenda_recommend_textn)都可以通过这个开启的端口来访问了吗？为什么呢？

不可以,  因为数据是用端口号来通知[传输层](http://www.so.com/s?q=传输层&ie=utf-8&src=internal_wenda_recommend_textn)[协议](http://www.so.com/s?q=协议&ie=utf-8&src=internal_wenda_recommend_textn)送给哪个软件来处理的，数据是没有智慧的，如果很多的程序共用一个端口来接受数据的话，那么当外界的一个[数据包](http://www.so.com/s?q=数据包&ie=utf-8&src=internal_wenda_recommend_textn)送来后传输层就不知道该送给哪一个软件来处理，这样势必将导致混乱。



0-1023是公认端口号，即已经公认定义或为将要公认定义的软件保留的;

1024-65535是并没有公共定义的端口号，用户可以自己定义这些端口的作用。

<br>

<br>

#### DNS

Domain Name System, 

> **The Domain Name System** (**DNS**) is a [hierarchical](https://en.wikipedia.org/wiki/Hierarchy) and [decentralized](https://en.wikipedia.org/wiki/Decentralised_system) naming system for computers, services, or other resources connected to the [Internet](https://en.wikipedia.org/wiki/Internet) or a private network. It associates various information with [domain names](https://en.wikipedia.org/wiki/Domain_name) assigned to each of the participating entities. Most prominently, it translates more readily memorized domain names to the numerical [IP addresses](https://en.wikipedia.org/wiki/IP_address) needed for locating and identifying computer services and devices with the underlying [network protocols](https://en.wikipedia.org/wiki/Communication_protocol). By providing a worldwide, [distributed](https://en.wikipedia.org/wiki/Distributed_computing) [directory service](https://en.wikipedia.org/wiki/Directory_service), the Domain Name System has been an essential component of the functionality of the Internet since 1985.
>
> The domain name space consists of a [tree data structure](https://en.wikipedia.org/wiki/Tree_(data_structure)). Each node or leaf in the tree has a *label* and zero or more *resource records* (RR), which hold information associated with the domain name. The domain name itself consists of the label, concatenated with the name of its parent node on the right, separated by a dot.
>
> -- Wikipeia

TLD(N)(Top-level domain (number))

> A **top-level domain** (**TLD**) is one of the [domains](https://en.wikipedia.org/wiki/Domain_name) at the highest level in the hierarchical [Domain Name System](https://en.wikipedia.org/wiki/Domain_Name_System) of the [Internet](https://en.wikipedia.org/wiki/Internet). The top-level domain names are installed in the [root zone](https://en.wikipedia.org/wiki/DNS_root_zone) of the name space. For all domains in lower levels, it is the last part of the [domain name](https://en.wikipedia.org/wiki/Domain_name), that is, the last label of a [fully qualified domain name](https://en.wikipedia.org/wiki/Fully_qualified_domain_name). For example, in the domain name [www.example.com](https://en.wikipedia.org/wiki/Example.com), the top-level domain is [com](https://en.wikipedia.org/wiki/.com). Responsibility for management of most top-level domains is delegated to specific organizations by the Internet Corporation for Assigned Names and Numbers (ICANN), which operates the [Internet Assigned Numbers Authority](https://en.wikipedia.org/wiki/Internet_Assigned_Numbers_Authority) (IANA), and is in charge of maintaining the [DNS root zone](https://en.wikipedia.org/wiki/DNS_root_zone).
>
> -- Wikipedia

<br><br>

#### URI&URL

**URL**

> A URL is a global address of documents and protocols to retrieve resource on a computer network. URLs occur most frequently in reference to web pages (HTTP) but can also be used for database access using JDBC, email (mailto), file transfer (FTP), and many other applications. URL stands for Uniform Resource Locator.

**URI**

> A URI is a string containing characters that identify a physical or logical resource. URI follows syntax rules to ensure uniformity. Moreover, it also maintains extensibility via a hierarchical naming scheme. The full form of URI is Uniform Resource Identifier.It consists two elements:
>
> 1. **URL:** URL specifies a location on the computer network and technique for retrieving it.
> 2. **URN:** Uniform Resource Name (URN) is an internet resource that specifies URN scheme.

**URI Vs URL**

| **URL**                                                      | **URI**                                                      |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| URL stands for Uniform Resource Locator.                     | URI stands for Uniform Resource Identifier.                  |
| URL is a subset of URI that specifies where a resource is exists and the mechanism for retrieving it. | A URI is a superset of URL that identifies a resource either by URL or URN (Uniform Resource Name) or both. |
| The main aim is to get the location or address of a resource | The main aim of URI is to find a resource and differentiate it from other resources using either name or location. |
| URL is used to locate only web pages                         | Used in HTML, XML and other files XSLT (Extensible Stylesheet Language Transformations) and more. |
| The scheme must be a protocol like HTTP, FTP, HTTPS, etc.    | In URI, the scheme may be anything like a protocol, specification, name, etc. |
| Protocol information is given in the URL.                    | There is no protocol information given in URI.               |
| Example of URL: [https://google.com](https://google.com/)    | Example of URI: urn:isbn:0-486-27557-4                       |
| It contains components such as protocol, domain, path, hash, query string, etc. | It contains components like scheme, authority, path, query, fragment component, etc. |
| All URLs can be URIs                                         | Not all URIs are URLs since a URI can be a name instead of a locator. |

**Example of URI**

```shell
www.guru99.com# No protocol mentioned
what-is-sap.html# Domain not mentioned
```

**Example of URL**

```shell
https://career.guru99.com/category/heavy-industries/ # This example URL has a folder but no extension
https://www.guru99.com/what-is-sap.html# This example URL has no folder
https://career.guru99.com/top-33-investment-banking-interview-questions-answers/# This example URL has no extension
```

[Continuation] : https://www.guru99.com/url-vs-uri-difference.html

<br><br>

### 1.2 Web Server

**Web Server**

Web Server handles (解析) HTTP协议, return 一个 HTTP Response (响应) 来让浏览器可以浏览，如: 送回一个HTML页面。然而**应用程序服务器提供的是客户端应用程序可以调用(call)的方法(methods)**。确切一点，你可以说：**Web服务器专门处理HTTP请求(request)**，但是应用程序服务器是通过很多协议来为应用程序提供(serves)商业逻辑(business logic)。

Web服务器可以响应(response)一个静态页面或图片，进行页面跳转(redirect)，或者把动态响应(dynamic response)的产生委托(delegate)给一些其它的程序例如CGI脚本，JSP(JavaServer Pages)脚本，servlets，ASP(Active Server Pages)脚本，服务器端(server-side)JavaScript，或者一些其它的服务器端(server-side)技术




















## 0x02 相关配置和软件


### 2.1 IIS







## HTML


超文本标记语言（HyperText Markup Language）是一种用于创建网页的标准标记语言。


### 框架格局


```html
<!DOCTYPE html><!--浏览器得知自己要处理的是HTML-->
<html lang="en"><!--文档中HTML的开始，Chrome中谷歌翻译识别的原文本由此而来-->
<head>
    <meta charset="UTF-8"><!--是一个网页的标签  mata元数据，在HTML5中新加入的一种新的编码方式另外的iso的编码-->
    <title>Title</title><!--标签页显示的标题-->
</head><!--提供有关文档内容和标注信息的（头元素）-->
<body><!--面向内容--><!--用Ctrl+/可以添加注释-->
</body>
</html>
```


注意：


### 解析


**meta**


两种属性，不同属性又有不同的参数值


1. name属性主要用于描述网页，与之对应的属性是content，content中的内容，主要便于搜索引擎机器人查找信息和分类信息用的 。
1. http-equiv顾名思义，相当于http的文件头作用，它可以向浏览器传回一些有用的信息，以帮助正确和精确的显示网页内容，与之对应的属性为content，content中的内容其实就是各个参数的变量值。
```html
<meta http-equiv="Refresh" content="2"> #每隔2秒刷新界面
   <link rel="icon" href="https://common.cnblogs.com/favicon.ico">#做网页上面的小图标
```


**body**


```html
<hn>:n的取值是1~6；从大到小，用来表示标题。
<p>：段落标签，包裹的内容被换行，并且也上下内容之间有一行空白
<b> <strong>:加粗标签
<s><strike>：为文字加上一条中线
<em>：文字变成斜体
<sup> 和<sub>：上角标和下角标
<br>：换行（可以单独使用）
<hr>：水平线
<u>: 下划线 是过时的保留 在CSS里面也可以设置</u><!--颜色要用CSS调整-->
<div> <span>两个在html中没有实质性作用，只是配合css的使用。div是块级的，而span是内联的
```

2. 块级标签和内联标签：
```html
块级标签：<p> <h1> <table> <ol> <ul> <form> <div>
```

   1. block（块）元素的特点：
      1. 总是在新行上开始
      1. 高度，行高以及外边框和内边距都可控制
      1. 宽度缺省是它的容器的100%，除非设定一个宽度
      1. 它可以容纳内联元素和其他块元素
```html
内联标签：<a> <input> <img> <sub> <sup> <textarea> <span>
```

   1. lnline元素的特点：
      1. 和其他元素都在一行上
      1. 高，行高以及外边距和内边距不可改变
      1. 宽度就是它的文字或图片的宽度，不可改变
      1. 内联元素只能容纳文本或者其他内联元素
   2. 对行内元素注意如下：
      1. 设置宽度width无效，
      1. 设置高度height无效，可以通过line-height设置，
      1. 设置margin只有左右margin无效，上下无效。
      1. 特殊字符：<>"©®　　<>"©®　　对应的字符



**图形标签**


```html
src：要显示图片的路径
alt：图片没有加载成功时的提示
title：鼠标悬浮时的提示信息
width：图片的宽
height：图片的高（宽高两个属性只用一个会自动等比缩放）
```


**超链接标签**`<a>`


```html
<a href="002.html" >2、LFH的第二个网页</a></p><!--默认是self刷新-->
<a href="002.html" target="_blank">2、1 LFH的第二个网页</a></p>
<a href="002.html" target="_parent">2、2 LFH的第二个网页</a></p>
<a href="002.html" target="_self">2、3 LFH的第二个网页</a></p>
<a href="002.html" target="_top">2、4 LFH的第二个网页</a></p>
```

2. 有 4 个保留的目标名称用作特殊的文档重定向操作：
   1. target的属性–>_blank：浏览器总在一个新打开、未命名的窗口中载入目标_
   1. target的属性–>_parent：这个目标使得文档载入父窗口或者包含来超链接引用的框架的框架集。如果这个引用是在窗口或者在顶级框架中，那么它与目标 _self 等效。
   1. target的属性–>_self：这个目标的值对所有没有指定目标的 [ 标签是默认目标，它使得目标文档载入并显示在相同的框架或者窗口中作为源文档。这个目标是多余且不必要的，除非和文档标题  标签中的 target 属性一起使用。]()
   1. target的属性–>_top：这个目标使得文档载入包含这个超链接的窗口，用 _top 目标将会清除所有被包含的框架并将文档载入整个浏览器窗口。--><!--标签的 target 属性规定在何处打开链接文档。
   1. 插入图片 在img标签里面只设置宽，不设置高，图片就会等比例缩放。



**列表标签**


```html
<ul>:无序列表
<ol>：有序列表
<li>：列表中的每一项
```
```html
<dl>：定义列表
<dt>：列表标题
<dd>：列表项
```

3. reversed ：倒序列表属性



**表格标签(table)**


```html
border：表格边框
cellpadding:内边框
cellspacing：外边框
width:像素百分比（最好是通过css来设置长宽）
<tr>：table row
<th><thead>：table head cell
<td>:table data cell
rowspan：单元格竖跨多少行
colspan：单元格横跨多少列
```


**表单标签`<form>`:（29种）**


1. 表单用于向服务器传输数据，比如文本字段、复选框、单选框、提交按钮等等。HTML表单用于接收不同类型的用户输入，用户提交表单时向服务器传输数据，从而实现用户与web服务器的交互。表单标签，要提交的所有内容都应该在该标签中。
1. `<form>`
1. `<input>`（自动断掉）
   1. **name**：表单提交项的键，注意和id的区别；name属性是和服务器通信时使用的名称，而id属性是浏览器端使用的名称，该属性主要是为了方便客户端编程。
   1. Type
      1. text:
         1. size：拓宽单行文本
         1. value：显式占位，表单提交项的值 , 对于不同的输入类型，value属性的用法也不同
         1. placeholder：隐式占位
         1. maxlength：最大长度
         1. readonly：文本属性
      2. password：密码
      2. textarea：多行文本框
         1. rows
         1. cols
      4. submit:
         1. method：表单的提交方式post、get默认取值就是get（信封）
            1. get：1、提交的键值对，放在地址栏中url后面。2、安全性相对较差。3、对提交的内容的长度有限制
            1. post：1、提交的键值对不在地址栏。2、安全性相对较差。3、对提交内容的长度理论上无限制。
         2. action：表单提交到哪，一般指向服务器端一个程序，程序接收到表单提交过来的数据（即表单元素值）作相应处理.
      5. button:
         1. Button > input button > input submit
      6. range
      6. file:
         1. multiple：一次允许上传多个文件
         1. required：一次只可以上传一个文件
   3. Name
   3. textarea
   3. select
   3. fieldset
   3. label



**嵌入图片和创建分区式响应**


1. `map`：响应图的关键元素
1. `area`：图片可被点击的元素
   1. 指定URL：href  和  Alt
   1. shape和coords 属性，共同起作用
      1. shape值：
         1. rect：四个逗号相隔的左上右下的四个区域
         1. circle：三个逗号相隔的左右边缘到圆心的距离和圆的半径
         1. poly：多边形，至少六个逗号，代表一个顶点（6个数值，实际是三个坐标，完成之后是一个三角形）
         1. dafault：代表默认区域，也就是说覆盖整个图片。不需要coords值。



**video**


1. src
1. height
1. width
1. autoplay
1. preload
1. controls
1. loop
1. poster
1. muted





## CSS


**层叠样式表**（英语：**C**ascading **S**tyle **S**heets，缩写：**CSS**；又称**串样式列表**、**级联样式表**、**串接样式表**、**阶层式样式表**）是一种用来为结构化文档（如HTML文档或XML应用）添加样式（字体、间距和颜色等）的计算机语言，由W3C定义和维护。当前最新版本是CSS2.1，为W3C的推荐标准。CSS现在已被大部分现代浏览器支持，而下一版的CSS4仍在开发中。


### 一、CSS基础元素


1. Style元素
   1. 全局属性
2. Font-size设置文本大小的属性
2. Color 设置文本颜色的属性



二、制作一个初级的CSS设计


1. 元素内嵌样式表
1. 文档内嵌样式表
1. 外部样式表



以上三者的优先级逐递减，随着控制范围的提高而使得自己的操作权限减少，体现了一种中庸的思想。


### 二、使用CSS基本选择器


选择器一般存在于2.2和2.3，对2.1不太感冒。


1. 选择所有元素
```html
<style type="text/css">
        *{
            font-size: 50px;
            color: blueviolet;
        }/*所有元素的选择*/
</style>
```

2. 根据类型选择元素
```html
<style type="text/css">
	p{
            font-size: large;
            color: beige;
      }
</style>
```

3. 根据类选择元素
类是一个全局概念，意思是所有的元素都有累的属性
```html
<style type="text/css">
.class1 {
            font-size: 40px;
            color: aqua;
        }
</style>
```

4. 根据ID选择元素
和类相同，一个区别是不要用点，而是#；另一个区别是id是唯一身份的标识(不推荐这样使用)，而类可以使多个成员的归类。
```html
<style type="text/css">
#12345{
            font-size: xx-large;
            color: dodgerblue;
        }
</style>
```

5. 根据属性选择元素
```html
<style type="text/css">
[href]{
            font-size: 40px;
            color: aqua;
        }
</style>
```

6. 其他选择器



四、：选择器


```html
<style type="text/css">
a:hover{
  		font-size: 40px;
  	   	color: darkblue;
         }
</style>
```


### 三、定义简单边框和背景设置


```html
 <style type="text/css">
        .class2{
            border-width:5px;
            border-style: dashed;
            border-color: aqua;
            border-bottom-color: blueviolet;
            border-bottom-style: dashed;
            border-left-color: darkblue;
            border-right-style: hidden;
            border-right-color: #ffc244;
            border-left-style: dotted;
            border-radius:20px/15px
        }
    </style>
```


`border-style: dashed;`这个有多种属性，测试后总结如下


六、border简写属性


```html
<style type="text/css">
        .class2{
            border: 5px solid red;
        }
    </style>
```


七、定义简单背景


八、Background简写属性


### 四、CSS文本样式


1. 对齐文本`Text-align`
`center`&&`left`&&`right`
```html
<style type="text/css">
    .class4{
        text-align: center;
    }
</style>
<body>
<p class="class4" align="center">我是最帅的</p>
</body>
```

2. 文字方向`Direction`:`ltr`&&`rtl`
2. 指定字母间距，单词间距，行高`Letter-spacing,word-spacing,line-height`
```html
<style type="text/css">
    .class4{
        text-align: center;
        letter-spacing: 10px;
        word-spacing: 10px;
        line-height: 100px;
    }
</style>
```

4. 首行缩进`Text-indent`
```html
<style type="text/css">
    .class4{
        text-indent: 50px;
    }
</style>
```

5. 文本装饰`Text-decoration`
```html
<style type="text/css">
    .class4{
        text-decoration: overline;
        /*text-decoration: underline;*/
        /*text-decoration:line-through;*/
    }
</style>
```

6. 文本大小写转换`Text-transform`
```html
<style type="text/css">
     .class4{
         text-transform: capitalize;/*首字母大写*/
     /*  text-transform: uppercase;
         text-transform: lowercase;*/
     }
</style>
```

7. 字体名称`Font-family`
7. 字体大小`Font-size`
7. 字体样式`Font-style`
   1. `italic`:斜体&&`oblique(拉伸)`
10. 指定字母是否以小型大写字母显示`Font-variant`
10. 字体粗细`Font-weight`
10. 文本阴影`Font-shadow`
```html
    <style type="text/css">
        .class5{
            font-family: 微软雅黑;
            font-size: 40px;
            font-style: oblique;
            font-variant: small-caps;/*小型大写转换（和text-transform不同的地方）*/
            font-weight: 200;/*(bold,bolder)*/
            text-shadow: 10px 10px 10px red;(左右，上下，模糊程度)
        }
    </style>
```


### 五、CSS过渡


```html
<style type="text/css">
        p{
            width: 100px;
            height: 100px;
            background-color: bisque;
        }
        p:hover{
            width: 150px;
            height: 150px;
            background-color: aqua;
            transition-delay: 150ms;
            transition-duration: 250ms;
            /*-webkit-transition-duration: ;
            -o-transition-duration: ;
            -moz-transition-duration: ;*/
            transition-property: width,height;
        }/*指定动作*/
    </style>
```


### 六、CSS动画


贝塞尔曲线


`ease`、`eaae-in(前慢)`、`ease-out（后慢）`、`ease-in-out（前后都慢）`


```html
<style type="text/css">
    p{
            width: 100px;
            height: 100px;
            background-color: bisque;
        }
    p:hover{
        	width: 150px;
            height: 150px;
            background-color: aqua;
            transition-delay: 150ms;
        transition-timing-function: ease-in;
    }
```


和过渡相比动画演示完成以后会回到初始状态，但是过渡动画不同，它会随着鼠标的停留而动画停留


```html
<meta charset="UTF-8">
    <title>CSS动画</title>
    <style type="text/css">
        p{
            width: 100px;
            height: 100px;
            background-color: orange;
        }
        p:hover{
            animation-duration: 500ms;/*动画的过渡时间*/
            animation-delay: 200ms;
            animation-name: lfh;
            animation-iteration-count: infinite;
            animation-direction: alternate;/*变大之后变小*/
        }
        @keyframes lfh {
            from{
                width: 125px;
                height: 125px;
                background-color: #ffc244;
            }
            50%{
                width: 150px;
                height: 150px;
                background-color: #ffc244;
            }
            75%{
                width: 175px;
                height: 175px;
                background-color: #ffc244;
            }
            to{
                width: 200px;
                height: 200px;
                background-color: #ffc244;
            }
        }
    </style>
```

### 七、CSS使用变换





### Color

#### Num

- 十六进制 : \#RRGGBB
- RGB : rgb(red, green, blue) (0 ~ 255 / 0% ~ 100%) : 256\*256\*256 = 16,777,216
- RGBA ( alpha , 0.0 - 1.0 )
- HSL : hsl ( hue, saturation, lightness ) (颜色柱面坐标表示法)
  - Hue : 0 / 360 红，120 绿，240 蓝
  - Saturation 百分比值；0% 灰， 100% 全彩
  - Lightness 百分比值；0% 黑，100% 白
- HSLA :hsla(hue, saturation, lightness, alpha) ( alpha 同上 )
- 预定义/跨浏览器

**[延拓] :** https://www.w3school.com.cn/cssref/css_colors_legal.asp





#### Name

规范中定义了 147 中颜色名（17 种标准颜色加 130 种其他颜色）

> 17 种标准色是 aqua, black, blue, fuchsia, gray, green, lime, maroon, navy, olive, orange, purple, red, silver, teal, white, yellow。

**[延拓] :** 

1. 查询 130 种颜色移步 https://www.w3school.com.cn/cssref/css_colornames.asp
2. **“网络安全色”** : 多年前，当电脑只支持最多 256 种颜色时，**216 种“网络安全色”列表被定义为 Web 标准**，并保留了 40 种固定的系统颜色。



































