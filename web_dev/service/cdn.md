---
date: 2020-05-25 16:10:00
---

[来源]：

1. https://juejin.im/post/5af46498f265da0b8d41f6a3
2. https://blog.csdn.net/whoim_i/article/details/104380541?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-3&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-3

> 来源的总结，只做学习整理。
>
> 因为想要面对一个新的开始，一个人必须有梦想、有希望、有对未来的憧憬。如果没有这些，就不叫新的开始，而叫逃亡。    ——玛丽亚·杜埃尼亚斯


###  CDN？
CDN(Content Delivery  Network)，即**内容分发网络**。CDN是构建在现有网络基础之上的智能虚拟网络，依靠部署在各地的边缘服务器，通过中心平台的负载均衡、内容分发、调度等功能模块，使用户就近获取所需内容，降低网络拥塞，提高用户访问响应速度和命中率。CDN的关键技术主要有**内容存储和分发技术**。

**核心**：广泛采用各种缓存服务器，将这些缓存服务器分布到用户访问相对集中的地区或网络中，在用户访问网站时，利用全局负载技术将用户的访问指向距离最近的工作正常的缓存服务器上，由缓存服务器直接响应用户请求。

**原理：**给源站域名添加CNMAE,别名为加速节点的域名。当用户向源站发起请求时，dns服务器解析源站域名时会发现有CNMAE记录，这时dns服务器会向CNAME域名发起请求，请求会被调度至加速节点的域名。

**优势**：

1. **本地cache加速**：提高了企业站点（尤其含有大量图片和静态页面站点）的访问速度，并大大提升以上性质站点的稳定性。
2. **镜像服务**：消除了不同运营商之间互联的瓶颈造成的影响，实现了跨运营商的网络加速，保证不同网络中的用户都能得到良好的访问质量。
3. **远程加速**：远程访问用户根据DNS负载均衡技术智能自动选择Cache服务器，选择最快的Cache服务器，加快远程访问的速度。
4. **集群抗攻击**：分布广泛的CDN节点加上节点之间的智能冗余机制，可以有效地预防黑客入侵以及降低DOS攻击对网站的影响。
5. **隐藏真实服务器的ip**
6. **提供WAF功能**：目前很多CDN也提供了WAF的功能，我们的访问请求会先经过CDN节点的过滤，该过滤可对SQL注入、XSS、Webshell上传、命令注入、恶意扫描等攻击行为进行有效检测和拦截。CDN节点将认为无害的数据提交给真实的主机服务器。


**过程：**

![cdn 访问过程](http://r.photo.store.qq.com/psc?/V13aSAY12tLYCN/jkqgNxaPJb7RsklupiKoXZhljjjUHG5Ul1xE89rIjmK*Qxn5ZsYkzpr71gCbeKfFhkGtm0NGzCKFiYxUzKaMAzeIZE163*pqrFo88*slicI!/r)

1. **[拿到对应IP地址]**  首先访问本地的 DNS ，如果没有命中，继续递归或者迭代查找，直到命中拿到对应的 IP 地址。
2. **[拿到全局负载均衡系统的 IP 地址]**  服务器端发送请求到目的地址。注意这里返回的不直接是 cdn 服务器的 IP 地址，而是全局负载均衡系统的 IP 地址
3. **[全局负载均衡系统与区域负载的通信]**  全局负载均衡系统会根据**客户端的 IP地址**和请**求的 url 和相应的区域负载均衡系统通信** 
4. **[区域负载返回全局以附近IP地址]**  均衡系统拿着这两个东西获取距离客户端最近且有相应资源的cdn 缓存服务器的地址，返回给全局负载均衡系统
5. **[全局返回客户端附近IP地址]**  全局负载均衡系统返回确定的 cdn 缓存服务器的地址给客户端。
6. **[客户端请求成功]** 客户端请求缓存服务器上的文件


简单来说，其实 CDN 就是个放服务端资源的一个仓库。但是有一点——在1里有一个 CNAME 的过程：

我们访问 cdn 资源的地址一般是 a.cloud.com  或者类似的地址（一个的 cdn 的专用地址）。但是我们用的 cdn 的服务却是第三方的，即其实资源在他们的地址上比如  tencent.cdn。这时候就需要在 dns 查询的时候，需要把我们访问 a.cloud.com的地址映射到 tencent.cdn  的地址上，然后拿着映射后的地址再去走一遍 dns 解析，成功之后才获取到第三方提供的全局负载均衡系统的 IP。再继续走后面的流程。

（涉及到CANEMA的解析过程？？）


### 回源？

原服务器 -> CDN1 -> CND2 -> CDN3 -> ...... -> 客户端

向上递归寻到资源，即当**没有资源，资源过期，访问的资源是不缓存资源等都会导致回源。**

注意题目所描述的情况不是 cdn 的动态加速。

> 动态加速的对象是动态生成的网页，动态加速一般是对针对内容（如数据库信息等）在**用户与源站之间建立高速通道**，**通过路由优化、TCP加速等技术手段对动态内容进行加速**，**降低节点到源站之间的时延**，从而大大降低了用户访问动态网页的延迟。

其实这个问题我没有找到比较合适的解答，下面我想说一下我个人的见解。 我们使用 cdn  的原因是（原文作者）：

> 我们经常有一些比较频繁请求且容量比较大的文件，并且更新频率不那么高的文件。这些文件如果我们都放在自己的服务器上，于客户端问题在于访问时间长，于服务器端是占用服务器端的资源。所以我们采用分布式的方式扔在 cdn 上。但是 API 不同，首先他常更新，其次他多和用户信息等相关联，并且 cdn 判断是否缓存是依靠 url，意味着他只能缓存 get  请求，所以他的应用范围是有限的。并且 api 常更新，推送更新到所有 cdn 节点同样是需要耗费资源的。所以 API 是不适合放在 cdn  上的。但是如果你的内容是相对静态的，不涉及和用户信息关联，并且能在一段时间内容忍缓存，更新不频繁，那么也不是不能考虑。


### 过期更新？

资源过期时间就是根据我们老生常谈的请求头部来判定。

 那么 cdn 是如何更新数据的？

分两种，主动（PUSH）和被动（PULL）。

被动刚才我们已经提到过了，利用回源就可以被动在途经的 cdn 节点缓存数据。

 主动指的是，我们从服务器主动往 cdn 推送数据。


### 缓存配置？

1. 将域名的 NS 记录指向 CDN 厂商提供的 DNS 服务器。

2. 给域名设置一个 CNAME 记录，将它指向CDN厂商提供的另一个域名。
   详情参考文章：[CDN配置教程](https://blog.csdn.net/HatOfDragon/article/details/85058116)


### 访问姿势？

1. **传统访问：**用户访问域名–>解析服务器IP–>访问目标主机
2. **普通CDN：**用户访问域名–>CDN节点–>真实服务器IP–>访问目标主机
3. **带WAF的CDN：**用户访问域名–>CDN节点（云WAF）–>真实服务器IP–>访问目标主机


### 判断CDN

1. **NSLOOKUP**——若返回域名解析结果为多个ip，多半使用了CDN，是不真实的ip。
2. **用不同区域ping**——查看ping的ip结果是否唯一。
   1. wepcc.com
   2. ping.chinaz.com
   3. ping.aizhan.com


### 绕过CDN各种姿势


## CDN的配置

1. 将域名的 NS 记录指向 CDN 厂商提供的 DNS 服务器。
2. 给域名设置一个 CNAME 记录，将它指向CDN厂商提供的另一个域名。
    详情参考文章：[CDN配置教程](https://blog.csdn.net/HatOfDragon/article/details/85058116)

## CDN的特点及优势

1. 本地cache加速：提高了企业站点（尤其含有大量图片和静态页面站点）的访问速度，并大大提升以上性质站点的稳定性。
2. 镜像服务：消除了不同运营商之间互联的瓶颈造成的影响，实现了跨运营商的网络加速，保证不同网络中的用户都能得到良好的访问质量。
3. 远程加速：远程访问用户根据DNS负载均衡技术智能自动选择Cache服务器，选择最快的Cache服务器，加快远程访问的速度。
4. 集群抗攻击：分布广泛的CDN节点加上节点之间的智能冗余机制，可以有效地预防黑客入侵以及降低DOS攻击对网站的影响。
5. 隐藏真实服务器的ip
6. 提供WAF功能：目前很多CDN也提供了WAF的功能，我们的访问请求会先经过CDN节点的过滤，该过滤可对SQL注入、XSS、Webshell上传、命令注入、恶意扫描等攻击行为进行有效检测和拦截。CDN节点将认为无害的数据提交给真实的主机服务器。

## 几种访问姿势

    传统访问：用户访问域名–>解析服务器IP–>访问目标主机
    普通CDN：用户访问域名–>CDN节点–>真实服务器IP–>访问目标主机
    带WAF的CDN：用户访问域名–>CDN节点（云WAF）–>真实服务器IP–>访问目标主机

如何判断网站是否存在CDN

NSLOOKUP
nslookup解析一下，若返回域名解析结果为多个ip，多半使用了CDN，是不真实的ip。
在这里插入图片描述
多地ping查询
使用不同区域ping，查看ping的ip结果是否唯一。若不唯一，则目标网站可能存在CDN。
ping测试的网站有：
https://wepcc.com/
http://ping.chinaz.com/
http://ping.aizhan.com/
绕过CDN各种姿势

    查看ip与域名绑定的历史记录，可能会存在使用CDN前的记录，相关查询网站传送门：
    DNS查询
    微步在线
    在线域名信息查询
    DNS、IP等查询
    CDN查询IP
    SecurityTrails平台
    https://sitereport.netcraft.com
    查询子域名，某些企业业务线众多，有些站点的主战使用了CDN，或者部分域名使用了CDN，而很多小站点又跟主站在同一台服务器或者同一个C段内，此时就可以通过查询子域名对应的ip来辅助查找网站的真实ip。像上面列举到的一些查询网站，以及像子域名挖掘机都可以使用。
    查询主域名，以前用CDN的时候有习惯只让www域名使用CDN，主域名不使用，为了是在维护网站时更方便，不用等CDN缓存。所以试着把目标www去掉ping一下，说不定有意想不到的效果。
    网络空间引擎搜索，常见的有zoomeye、shodan、fofa。
    邮件服务器，一般的邮件系统都在内部，没有经过CDN解析，通过目标网站用户注册或者RSS订阅功能，查看邮件，寻找邮件头中的邮件服务器域名ip。ping这个邮件服务器的域名就可以获得目标的真实ip。（必须是目标自己的邮件服务器）
    国外访问，国内的CDN往往只对国内用户的访问进行加速，而国外的CDN就不一定了。所以可以通过在线代理网站https://asm.ca.com/en/ping.php 访问，可能会得到真实的ip地址。
    网站漏洞查找，如phpinfo之类的探针，github信息泄露等，若存在web漏洞，服务器主动与我们发起请求连接，我们也能获取目标点的真实ip。如xss，ssrf，命令执行反弹shell等。
    censys查询ssl证书找到真实ip，利用censys网络空间搜索引擎进行证书探测，若目标站点有https证书并且默认虚拟主机配置了https证书，我们就可以找所有目标站点是该https证书的站点。

443.https.tls.certificate.parsed.extensions.subject_alt_name.dns_names:www.xxx.com

    1

在这里插入图片描述

相关文章：
绕过CDN方法整理
11种绕过CDN查找真实IP方法
绕过CDN查找网站真实ip




### 专业术语

**边缘节点**：指距离最终用户接入具有较少的中间环节的网络节点





### 图床配置

参见：https://developer.qiniu.com/fusion/kb/1680/cdn-cache-rule-set

源站配置文件中设置缓存时间为 0，Nginx 为例，或者自定义域名的缓存时间

```nginx
server {
    listen       80;
    server_name  localhost;
    location ~* ^(.+\.php)(.*)$ {
        root     html;
        expires  -1;
        fastcgi_pass 127.0.0.1:9000;
        fastcgi_index index.php;
        fastcgi_param SCRIPT_FILENAME         $document_root$fastcgi_script_name;
        include fastcgi_params;
    }
}
```




HTTp延拓：https://juejin.im/post/5a1d4e546fb9a0450f21af23



### 参考文献：

1.  [CDN 学习中的一点小思考](https://cloud.tencent.com/developer/article/1004979) 
2. [CDN 命中率、回源率常见问题](https://developer.qiniu.com/fusion/kb/4080/the-common-problems-in-the-cdn) 
3. [CDN缓存那些事](https://cloud.tencent.com/document/api/228/3236) 
4. [让 API 也上 CDN 吧](https://www.web-tinker.com/article/21331.html)
5.  [CDN的基本工作过程](http://book.51cto.com/art/201205/338756.htm) [CDN是什么？使用CDN有什么优势？](https://www.zhihu.com/question/36514327?rf=37353035)
6.  [cname记录是什么？他存在的意义是什么？](https://www.zhihu.com/question/22916306) [CDN工作原理（CNAME）](https://blog.csdn.net/heluan123132/article/details/73331511) 
7. [【CDN 最佳实践】CDN缓存策略解读和配置策略](https://zhuanlan.zhihu.com/p/29468624)
8.  [CDN缓存那些事儿](http://genie88.github.io/2015/11/03/talk-about-content-delivery-network-and-caches/)
9.   [绕过CDN方法整理](https://www.cnblogs.com/-qing-/p/10743874.html)
10.   [11种绕过CDN查找真实IP方法](https://www.cnblogs.com/qiudabai/p/9763739.html)
11.   [绕过CDN查找网站真实ip](https://blog.csdn.net/qq_36119192/article/details/89151336)


