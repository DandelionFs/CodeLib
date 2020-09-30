---
date: 2020-06-01 00:00:00
---

## Environment Var
### Linux



### Win10<sup>1</sup>
1. 不区分大小写
2. 系统变量对所有用户有效,  优先级高于用户变量
3. 系统在执行用户命令时，若用户未给出文件的绝对路径，则首先在当前目录下寻找相应的可执行文件、批处理文件等,   找到为止(不会递归文件夹,  只指文件 )；
4. 新加命令后注意要保存. 






## Usr
关于我看书的一个假想（其实也确实如此，至少Wiki上面已经提过）——早期多人共享一台计算机，共享的系统可能就是Unix或者Linux，而不会是win，因为Unix可比Win出现的要早啊，

1. **PC和操作系统一次只能供一个用户使用**。即使您可以物理连接外围设备（例如USB集线器），**操作系统仍然只能渲染一个台式机**，随之而来的是欢闹声。
   PCs are designed for one user at a time as are operating systems. Eve n if you could physically get the peripherals connected (eg. USB hub), the OS would still only render one desktop and hilarity would ensue. 

2. 在操作系统级别，来自多个连接的键盘或鼠标的输入被解释为来自单一来源。如果要使用多个鼠标和键盘，则任何尝试读取输入的应用程序都必须降低级别。 
   On the OS level, the input from multiple connected keyboards or mice is interpreted as coming from a single source...




## HOST

一个没有扩展名的系统文件，作用就是将一些常用的网址域名与其对应的IP地址建立一个关联“数据库”，当用户在浏览器中输入一个需要登录的网址时，系统会首先自动从Hosts文件中寻找对应的IP地址，一旦找到，系统会立即打开对应网页，如果没有找到，则系统会再将网址提交[DNS](https://laod.cn/tag/dns/)域名解析服务器进行IP地址的解析。

### 修改

接下来关键问题就是如何修改[hosts文件](https://laod.cn/tag/hosts文件/)，[hosts文件](https://laod.cn/tag/hosts文件/)存放目录：

- Window目录 C:\Windows\System32\drivers\etc\[hosts](https://laod.cn/tag/hosts/)
- Linux及其他类Unix操作系统：/etc
- Android目录/system/etc/
- 更多系统[hosts](https://laod.cn/tag/hosts/)文件目录可参考：[常用的各平台 hosts 文件位置](https://laod.cn/hosts/hosts-position.html)

编辑修改以上目录下的hosts文件。目前实现方式有许多形式，最直接的就是使用文件管理器将获取的hosts文件覆盖系统的hosts文件。


### 作用

1. **虚拟域名**: 很多时候，网站建设者需要把”软环境“搭建好，再进行上传调试。但类似于邮件服务，则需要使用域名来辅助调试，这时就可以将本地 IP 地址与一个”虚拟域名“做地址指向，就可以达到要求的效果，且无需花费。
2. **加快域名解析**: 对于要经常访问的网站，我们可以通过在Hosts中配置域名和IP的映射关系，提高域名解析速度，当我们输入域名计算机就能很快解析出IP，而不用请求网络上的DNS服务器。
3. **屏蔽网站（域名重定向）**:有很多网站不经过用户同意就将各种各样的插件安装到你的计算机中，其中有些说不定就是木马或病毒。对于这些网站我们可以利用Hosts把该网站的域名映射到错误的IP或本地计算机的IP，这样就不用访问了。在WINDOWS系统中，约定 127.0.0.1 为本地计算机的IP地址, 0.0.0.0是错误的IP地址。
4. **方便局域网用户**: 在很多单位的局域网中，会有服务器提供给用户使用。但由于局域网中一般很少架设DNS服务器，访问这些服务器时，要输入难记的IP地址。这对不少人来说相当麻烦。可以分别给这些服务器取个容易记住的名字，然后在Hosts中建立IP映射，这样以后访问的时候，只要输入这个服务器的名字就行了。
5. **顺利连接系统**: 对于Lotus的服务器和一些数据库服务器，在访问时如果直接输入IP地址那是不能访问的，只能输入服务器名才能访问。那么我们配置好Hosts文件，这样输入服务器名就能顺利连接了。
6. **强制域名解析指定IP**: 比如一些网站有很多的服务器ip，有些ip可能被和谐了，那么我们可以在hosts文件里添加我们想要的ip跟域名。

[1]:https://zhuanlan.zhihu.com/p/93719752