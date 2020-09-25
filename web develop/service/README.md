---
date: 2020‎.02‎.02‎ 21:43:43
---

## Proface
一些必要的常识：

1. **域名**备案
2. CDN
3. 对象存储
4. 内网穿透

之后购买服务器，这里有全球域名购买[索引](https://www.jianshu.com/p/aff58882bf00).

其实服务器都有图形界面，if you need.然后我的感受其实相同配置下Linux类操作SSH比Win流畅，Win的远程桌面比Linux流畅，但是后者比较吃配置，很有意思。Win建站可以采用`Window+IIS`,Linux可以采用`LASP `和`LNSP`的方法，我用的是后者，因为处理并发的时候后者较强，虽然没有几个人访问我的站点。有个便宜的 vps frp 穿透 本地存图 使用第三方 cdn 基本就完美了。

## Sever

### 检查宕机

以下下代码可用性未知，想到的一种好的方法就是用Ping的方式，后续如果摸索出来再来更新。

```shell
#!/bin/bash
mail=1551728654@qq.com
while true
   do ping -c 2  >/dev/null 2>&1
   if [ $? -ne 0 ];then
     echo " |mail-s "ping baidu is down" $mail
     else
      echo "baidu is ok"
      fi;
      sleep 30
      done
```

### Domain Jump

[来源]：https://www.zhihu.com/question/20268914

 1. **空间绑定后+PHP**
 ```php
<?Header("Location: http://你的网址");?> 
 ```

 2. **.htaccess文件**
 ```php
RewriteCond %{HTTP:Host} ^ibibao.com
RewriteRule (.*) http: //www.leQuan.wang [NC,R=301]
 ```
  如果只是暂时性跳转，[NCR=301] 的 301 改成 302 即可。如www.XXX.com/1.html 跳转到 www.XXX.cn/1.html。<br>
    因为这样更利于网站的权重转移，不会丢失内页权重。我们需要在老域名的后面加一个$符号，在新域名后面加一个$1符号。这两个字符的作用就是实现两个域名的内页301跳转。

 3. **列表项目**：URL 转发。
<br>
 4. **网页代码端**：有 meta 标签控制和 JS 代码多种方式实现，轻易不要使用，会被se惩罚。


</br>

## 访问统计

First,What the PV、TPS、QPS、RPS?
>PV is a abbreviate of Page View , so a pv each refresh.

+ TPS=transactions per second(事务数,客户端发起请求到收到服务端最终响应的整个过程)
+ QPS=queries per second(查询次数,所以，一个TPS可能包含多个QPS)
+ RPS=requests per second

**MODEL：**

**<center>(Sever Process Page Request /s) QPS=( 0.8*ALL_PR / 86400*0.4 )/Sever_Num</center>**
注意：

1. 86400=24\*60\*60
2. 0.8、0.4表示一天中有80%的请求发生在一天的40%的时间内。24小时的40%是9.6小时，有80%的请求发生一天的9.6个小时当中（很适合互联网的应用，白天请求多，晚上请求少）

**简单可以获得初步的比较标准**：

<center>( 0.8*500万 / 86400*0.4 )/1 = 115.7  QPS</center>
<center>( 0.8*100万 / 86400*0.4 )/1 = 23.1  QPS</center>
如果你的服务器一秒能处理115.7个请求，就可以承受500万PV/每天。如果你的服务器一秒能处理23.1个请求，就可以承受100万PV/每天。但是实际上这样子理想情况只是我们的假设，实际上的访问量是一个正态分布曲线，而不是一个恒定走向的直线，所以需要在原有的基础上缩水放大，最终结论：

<center> 115.7 * 2 = 231.4 QPS</center>
<center> 115.7 * 3 = 347.1 QPS</center>
<center> 23.1 * 2 = 46.2 QPS</center>
<center> 23.1 * 3 = 69.3 QPS</center>
<font color ="red">如果你的服务器一秒能处理231.4--347.1个 QPS，就可以应对平均500万PV/每天。如果你的服务器一秒能处理46.2--69.3个 QPS，就可以应对平均100万PV/每天。</font>

再让我们看看1M宽带代表着什么？他的单位是B，所以1\*1024/8=128KB/s，所以大概可以用于文字博客的发布，像是页头视频那就别想了，加载个首页得上10s……要不然搭个炫酷的博客也很烧钱，虽然和过去12年烧的钱比起来不值一提……

## 端口
[Ori] :https://zhuanlan.zhihu.com/p/20365900

TCP和UDP协议都存在一个叫做端口的东西，但端口却不是IP协议的一部分。 端口被设计出来主要是为了给协议栈和应用对应：

- 协议栈用端口号将数据分配给不同的应用层程序
- 应用层程序用端口号去区分不同的连接，参见之前提到过的“四元组”

TCP和UDP协议都使用了端口号（Port number）的概念来标识发送方和接收方的应用层。 对每个TCP连接的一端都有一个相关的16位的无符号端口号分配给它们。 即使是UDP这种没有连接的协议，依旧有一个16位的无符号端口号。 可能的、被正式承认的端口号有 2^16 -1 = 65535 个。

### 三类端口

- **著名端口**是由因特网赋号管理局（IANA）来分配的，并且通常被用于系统进程。 IANA对于端口号的分配见这里 [Service Name and Transport Protocol Port Number Registry](https://link.zhihu.com/?target=http%3A//www.iana.org/assignments/port-numbers) 。 系统的/etc/services也有相应端口和服务名的对应，主要是用来给netstat、nmap 等系统命令做端口名反解用。

  著名的应用程序作为服务器程序来运行，并侦听经常使用这些端口的连接。 这些端口的一个显著特征就是限定在0~1023，并且在Linux、UNIX平台均需要 Root权限才能监听这些端口。

  在UNIX刚刚兴起的年代，服务器资源是十分稀缺的， 通常一台服务器上会有很多的用户，同时这台服务器往往还兼任一个学院、公司的邮件、 网站等服务。为了保证这些服务的端口不被普通用户占用， 当时UNIX的设计者就把使用这些端口的权限限制在系统管理员(Root)手里。

  ```text
  常见的`著名端口`有：FTP:21、SSH:22、SMTP:25、HTTP:80、HTTPS:443等。
  ```

- 监听端口通常被用来运行各种用户自己写的服务，服务监听在这些端口下不需要特别的权限。

  - BSD使用的监听端口范围是1024到4999。
  - IANA建议49152至65535作为“监听端口”。
  - 许多Linux内核使用32768至61000范围。 配置文件 /proc/sys/net/ipv4/ip_local_port_range 有当前系统设定。

- 动态端口通常被用来在主动发起连接时随机分配使用，在任何特定的TCP连接外不具有任何意义。 这是由于TCP等协议是通过四元组来区分不同的网络连接。 当本机主动发起TCP连接的时候如果目的IP、目的端口、本地IP都是一样的， 只能通过占用不同的本地端口来区分不同的连接。

  0~65535除去上述著名端口、监听端口两种端口号，剩下的端口都是备用的动态端口。 所以在某些特殊用途的需要主动发起大量连接的服务器上（例如：爬虫、代理）， 需要调整 /proc/sys/net/ipv4/ip_local_port_range 的数值，来保留更多的 动态端口以供使用。

### 0号端口

端口号里有一个极为特殊的端口，各种文档书籍中都鲜有记载，就是0号端口。

在IANA官方的标准里0号端口是保留端口。

![img](http://i.dfslfh.cn/IANA0%E7%AB%AF%E5%8F%A3.png)

也就是说无论是TCP还是UDP网络通信，0号端口都是不能使用的。然而，标准归标准，在UNIX/Linux网络编程中0号端口被赋予了特殊的涵义：

> 如果在bind绑定的时候指定端口0，意味着由系统随机选择一个可用端口来绑定。


用Python实现一个获取可用监听端口的示例：

```python
def findFreePort():
  """
  函数返回值是当前可用来监听的一个随机端口。
  """
  import socket
  s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  s.bind(('localhost', 0))
  # 用getsockname来获取我们实际绑定的端口号
  addr, port = s.getsockname()
  # 释放端口
  s.close()
  return port
```

### 网络地址转换NAT

既然说到了端口，不得不提一下NAT。

NAT是"Network Address Translation"的缩写，直译就是网络地址转换。 1990年代中期，为了应对IPv4地址短缺，NAT技术流行起来。

WikiPedia的解释为：

> 在一个典型的配置中，一个本地网络使用一个专有网络的指定子网 （比如192.168.x.x或10.x.x.x）和连在这个网络上的一个路由器。 这个路由器占有这个网络地址空间的一个专有地址（比如192.168.0.1）， 同时它还通过一个或多个因特网服务提供商提供的公有的IP地址（叫做“过载”NAT） 连接到因特网上。当信息由本地网络向因特网传递时，源地址被立即从专有地址转换为公用地址。 由路由器跟踪每个连接上的基本数据，主要是目的地址和端口。当有回复返回路由器时， 它通过输出阶段记录的连接跟踪数据来决定该转发给内部网的哪个主机； 如果有多个公用地址可用，当数据包返回时，TCP或UDP客户机的端口号可以用来分解数据包。 对于因特网上的一个系统，路由器本身充当通信的源和目的地址。

这个技术能够被广泛使用还要感谢当时端口号的记录字段是2Bytes而不是1Byte。

NAT技术的广泛应用也给很多应用带来了极大的麻烦： 处于NAT网络环境内的服务器很难被外部的网络程序主动连接，受这一点伤害最大的莫过于： 点对点视频、语音、文件传输类的程序。

当然我们聪明的工程师经过长时间的努力，发明了“NAT打洞”技术，一定程度上解决了此类问题。

如果没有他们的努力，我们现在各种QQ视频、微信实时语音、网络电话都是需要用户连接到 服务商的服务器上进行数据传输。这样对服务商的网络消耗将是十分巨大的， 服务质量也是很难以提高的，具体的技术实现，我们以后再表。

### 多进程端口监听

我们都有一个计算机网络的常识：不同的进程不能使用同一端口。

如果一个端口正在被使用，无论是TIME_WAIT、CLOSE_WAIT、还是ESTABLISHED状态。 这个端口都不能被复用，这里面自然也是包括不能被用来LISTEN（监听）。

但这件事也不是绝对的，之前跟大家讲进程的创建过程提到过一件事： 当进程调用fork(2)系统调用的时候，会发生一系列资源的复制，其中就包括句柄。 所以，在调用fork(2)之前，打开任何文件，监听端口产生的句柄也将会被复制。

通过这种方式，我们就可以达成"多进程端口监听"。

但，这又有什么用呢？

我们大名鼎鼎的Nginx就是通过这种手法让多个进程同时监听在HTTP的服务端口上的， 这么做的好处就在于，当外部请求到达，Linux内核会保证多个进程只会有一个accept(2) 成功，这种情况下此端口的服务可用性就和单个进程存在与否无关。 Nginx正是利用这一点达成“不停服务reload、restart”的。

### SO_REUSEADDR
有一个问题就是

> 为什么有时候重启Apache会失败，报“Address already in use”？


TCP的原理会导致这样的一个结果：主动close socket的一方会进入TIME_WAIT，这个状况持续的时间取决于三件事：

- TCP关闭连接的五次挥手包什么时候到达
- SO_LINGER的设置
- /proc/sys/net/ipv4/tcp_tw_recycle 和 /proc/sys/net/ipv4/tcp_tw_reuse 的设置

总之默认情况下，处于TIME_WAIT状态的端口是不能用来LISTEN的。 这就导致，Apache重启时产生80端口TIME_WAIT，进而导致Apache再次尝试LISTEN失败。

在很多开源代码里我们会看到如下代码：

```c
int reuseaddr = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(int));
```

有了上面这段神奇的代码，就不会出现上面的惨剧。但SO_REUSEADDR的作用不仅限于上述

Linux 的 SO_REUSEADDR 设置为 1 有四种效果：

1. 当端口处在TIME_WAIT时候，可以复用监听。

2. 可以允许多个进程监听同一端口，但是必须不同IP。

   > **这里说的比较隐晦，如果进程A监听0.0.0.0:80，B进程可以成功监听127.0.0.1:80， 顺序反过来也是可以的。**

3. 允许单个进程绑定相同的端口到多个socket上，但每个socket绑定的IP地址不同。

4. 使用UDP时候，可以允许多个实例或者单进程同时监听同个端口同个IP。

## FQA

> Q：ECS or 轻量服务器（馋5M带宽）

A：参考链接：https://www.zhihu.com/question/321378304 ， https://www.zhihu.com/question/365407782

主要如下：

**1、使用对象：**轻量应用服务器面向单机应用，云服务器ECS则未做任何限制；

**2、可扩展性：**轻量应用服务器提供的配置仅有少量的几个可供选择，升配局限较大；云服务器ECS提供数十种类型上百种配置可供选择，并且支持升级，同时ECS支持搭配其他应用如RDS、OSS来使用；

**3、网络：**轻量应用服务器面向对象是单机，基本不存在网络的扩展问题；云服务器ECS在专有网络VPC下，用户可以自定义专有网络，并且可以通过网络与线下IDC或者其他云产品进行互联互通；

云服务器ECS给学生提供更大的容错空间，也方便学生学习使用；

</br>

</br>

## Sitemap

参考链接：https://zhuanlan.zhihu.com/p/36665620

生成网站地图其实很简单，首先打开“[站长工具_sitemap网站地图免费生成工具](https://link.zhihu.com/?target=https%3A//sitemap.webkk.net)”([https://sitemap.webkk.net](https://link.zhihu.com/?target=https%3A//sitemap.webkk.net))，按照页面的一些提示做下一步操作。

+ 选择网站协议，（HTTP、HTTPS）；
+ 键入网址；
+ 选择您网站的字符集；
+ 如果您有过使用记录，有更新，需要勾选更新数据按钮从头抓取；
+ 下载对应HTML、XML、TXT格式的网站地图文件。

抓取的时候有一点需要注意，如果之前使用了这个工具，刚好下次使用的时候网站有内容更新，应该在页面上候选上 更新数据。

## IMG Host

压缩个图片整出来个非法图片...

+ Cloudreve，以后再也不用为了图床发愁了；img.dfslfh.cn
    + https://www.tok9.com/archives/390/

## Blog Host

**国内可用的博客技术：**

1. Typecho
2. WordPress（2020年关 国区疯狂连不上）

**国内烧香可用的博客：**

+ 博客大巴: 国内运营不下去倒了. 随着用户的数据永远的消失了.
+ Blogger：与 G Site 同源，可看到老一辈互联网居民情况.
+ FarBox：参考 [我们为什么不再接入国内服务商](http://blog.farbox.com/post/stop-them) - 130316 的老文章，如今 Dropbox 也已经被墙掉了.
+ Bitcorns：Farbox 的替代品，基础60/年.



## Wiki Host

**Wiki**是指内容可以直接在浏览器中编辑，并且每个可编辑页面的版本历史都会被记录下来的网站。通常来说任何访客都可以编辑wiki，但并非总是如此。wiki（作为形容词）、“Wiki 的方式”和反义词un-wiki也表示与Wiki网站共存的、以社区为本的理念（例如“那种做法不是很 wiki”）尽管有人用Wiki（'W' 大写）来指代维基百科或 波特兰模式知识库（也称为 WikiWikiWeb，它是世界上第一个 Wiki），但这种用法实际是错误的。术语 Wiki软件 和 Wik引擎 指的则是驱动Wiki网站的软件。Wiki 软件有许多种，有些很简单，有些则功能复杂。

**Wikiwikiweb**, 最早创建1995年3月25日成立。 原本是PortlandPatternRepository 社群使用的自动化工具。因為網際網路那時候還很新，而且向 InvitedAuthors 邀稿的文章都很棒，一推出就受到該社群的熱烈歡迎。該網站目前仍然留著，以獻給 PeopleProjectsAndPatterns. 該網站是 WardCunnigham 開發設計的。他選了 wiki-wiki 這個意思是「快」的疊韻詞當名字，免得必須取名為 quick-web。 Wiki 的概念可以追溯到他在 80 年代末期寫的 HyperCard 堆疊。文章放在 WikiWikiHyperCard 這篇很老的網頁。

**Wikimedia**, 是维基活动中一系列内在相关计划的集合名词，包括维基媒体、维基词典、维基语录及其他，这些计划通过互联网强大的协作能力和 wiki 理念致力于创建和分享各种类别的自由知识。维基媒体服务器术语一般指托管所有维基媒体计划的计算机硬件。维基媒体基金会是一个总部位于旧金山的运行维基媒体项目的非营利组织。 德国维基媒体协会、俄罗斯维基媒体协会等是维基媒体计划爱好者组成的十二个分会。他们独立于维基媒体基金会和维基媒体计划。在不同的场合和区域，Wikimedia 常被错误地使用为维基媒体计划、分会或维基媒体基金会的简称（后者也可能出现在本维基中）。Wikimedia Meta-Wiki，简称Meta，中文元维基，是用来讨论与所有维基媒体计划有关问题的 wiki。

**MediaWiki**: MediaWiki是一个特殊的wiki引擎。它由维基百科和其他维基媒体计划开发，并用于维基媒体自身。 MediaWiki可供其他人免费使用（和改进），并且现已被全世界各种项目和组织使用。网站mediawiki.org，提供与MediaWiki和相关软件的信息。


### Wiki Site

起初是自己想搭建一个可以查阅的Wiki平台,  但是我还是太天真了, 已经搭建好了, 地址是: Wiki.dfslfh.cn,  开源项目地址是: https://github.com/zthxxx/hexo-theme-Wikitten

我之后还是针对不同领域做出不同的书比较妥当吧,  我总在找一老永益的方法, 有点难以回头.

另外还有技术:
1. vimwiki https://github.com/vimwiki/vimwiki/blob/master/README-cn.md
2. Gitbook https://github.com/GitbookIO/gitbook
3. Gitlab
4. AsciiDoc : https://asciidoc.org/index.html
5. 语雀



## Reference

1. https://blog.csdn.net/ChinarCSDN/article/details/79588171
2. https://cloud.tencent.com/developer/article/1004505
3. https://zhuanlan.zhihu.com/p/59867621
4. https://www.cnblogs.com/manong--/p/8012324.html
5. https://zhuanlan.zhihu.com/p/96460221
6. https://man.linuxde.net
7. https://www.runoob.com/linux/linux-tutorial.html
8. https://www.linuxprobe.com
9. https://www.lulinux.com/archives/category/linux_newbie
10. https://cloud.tencent.com/developer/article/1463836
11. https://www.zhihu.com/question/21556347
12. https://www.mediawiki.org/wiki/Differences_between_Wikipedia,_Wikimedia,_MediaWiki,_
