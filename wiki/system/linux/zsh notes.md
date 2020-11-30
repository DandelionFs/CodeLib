# ZSH(SHELL) NOTES

爬坑ZSH.

THX FOR:
- [linux-command|Linux命令大全搜索工具](https://github.com/jaywcjlove/linux-command)
- https://www.sysgeek.cn/install-zsh-shell-ubuntu-18-04/
- https://my.oschina.net/u/2266513/blog/3103451
- https://zhuanlan.zhihu.com/p/37195261
- https://www.jianshu.com/p/b61473e22c8b
- https://qastack.cn/superuser/232457/zsh-output-whole-history
- https://github.com/ohmyzsh/ohmyzsh/issues/31
- https://comery.github.io/2017/07/20/A-easy-guide-bashrc/
- https://segmentfault.com/a/1190000013612471
- https://juejin.im/post/6844903669578596359
- [Tab key == 4 spaces and auto-indent after curly braces in Vim](https://stackoverflow.com/questions/234564/tab-key-4-spaces-and-auto-indent-after-curly-braces-in-vim)


## `~/.zshrc`

configure your zsh.

### TAB TO 4 SPACE

```shell
filetype plugin indent on
set tabstop=4
set shiftwidth=4
set expandtab
```

## PROXY

```shell
# where proxy
proxy () {
   export http_proxy="http://127.0.0.1:7890"
   export https_proxy="http://127.0.0.1:7890"
   echo "HTTP Proxy on"
}
# where noproxy
noproxy () {
   unset http_proxy
   unset https_proxy
   echo  "HTTP Proxy off"
}
# CLASH
CP() {
   cd /home/usr/clash ; ./clash -d .
}
```

## ZSH Wget URL Not Found

> This is a common problem when working with urls as well.
>
> ```
> curl http://www.google.com/search?q=rails
> # => zsh: no matches found: http://www.google.com/search?q=rails
> ```
>
> However, you can escape it with a backslash or quote it.
>
> ```
> curl "http://www.google.com/search?q=rails"
> ```
>
> I don't know of any config to change this on a case-by-case basis (to keep the wildcard working). Do you?

**双引网址** 即可.

## 查询端口是否开放

### iptables防火墙

1. 基本操作

   ```n
   # 查看防火墙状态
   service iptables status  
   # 停止防火墙service iptables stop  
	# 启动防火墙service iptables start  
	# 重启防火墙service iptables restart  
	# 永久关闭防火墙chkconfig iptables off  
	# 永久关闭后重启chkconfig iptables on　　
   ```
2. 开启80端口

```
vim /etc/sysconfig/iptables
\# 加入如下代码
-A INPUT -m state --state NEW -m tcp -p tcp --dport 80 -j ACCEPT
保存退出后重启防火墙
service iptables restart
```

### firewall防火墙

1. 查看firewall服务状态
```
systemctl status firewalld
```
出现Active: active (running)切高亮显示则表示是启动状态。
出现Active: inactive (dead)灰色表示停止，看单词也行。
2. 查看firewall的状态
```
firewall-cmd --state
```
3. 开启、重启、关闭、firewalld.service服务
```
\# 开启
service firewalld start
\# 重启
service firewalld restart
\# 关闭
service firewalld stop
```
4. 查看防火墙规则
```
firewall-cmd --list-all
```
5. 查询、开放、关闭端口
```
# 查询端口是否开放
firewall-cmd --query-port=8080/tcp
# 开放80端口
firewall-cmd --permanent --add-port=80/tcp
# 移除端口
firewall-cmd --permanent --remove-port=8080/tcp
#重启防火墙(修改配置后要重启防火墙)
firewall-cmd --reload

```
1. firwall-cmd：是Linux提供的操作firewall的一个工具；
2. --permanent：表示设置为持久；
3. --add-port：标识添加的端口；


## ORDER

### History 显示残缺

zsh条目中的范围作为[first] [last]参数

```shell
history 0
```

### SSH LS COLOR

SSH服务器目录会有颜色：

|color|decribe|
|---|---|
|**白色**|普通文件|
|**蓝色**|目录|
|**绿色**|可执行文件|
|**红色**|压缩文件|
|**浅蓝色**|链接文件|
|**红色闪烁**|链接的文件有问题|
|**黄色**|设备文件 |
|**灰色**|其他文件|
|**绿色**|是有问题的，代表权限中有其它组权限拥有写入权限，系统默认这是一个高风险目录。将权限改到775以下就可以解决|


### [traceroute](https://www.yuque.com/books/share/742ca8f6-34f3-41ef-b239-be00aaf0df31/pd83w0)

```shell
traceroute -m 10 www.baidu.comD
```
在校园网的作用下, 每个网址输出都大同小异.
```shell
traceroute to www.baidu.com (39.156.66.18), 10 hops max, 60 byte packets
 1  _gateway (10.102.176.1)  28.351 ms  28.323 ms  28.299 ms
 2  10.101.1.34 (10.101.1.34)  3.229 ms 10.101.1.42 (10.101.1.42)  3.185 ms 10.101.1.34 (10.101.1.34)  3.645 ms
 3  10.101.1.1 (10.101.1.1)  2.682 ms  2.667 ms 10.101.1.25 (10.101.1.25)  2.652 ms
...
traceroute to www.github.com (192.30.255.113), 10 hops max, 60 byte packets
 1  _gateway (10.102.176.1)  4.295 ms  4.267 ms  4.428 ms
 2  10.101.1.42 (10.101.1.42)  8.396 ms 10.101.1.34 (10.101.1.34)  2.777 ms 10.101.1.42 (10.101.1.42)  3.607 ms
 3  10.101.1.1 (10.101.1.1)  2.356 ms 10.101.1.25 (10.101.1.25)  2.342 ms 10.101.1.1 (10.101.1.1)  2.327 ms^C
```
### shutdown

- shutdown -h now : 表示立即关机
- shutdown -h 1 : 表示 1 分钟后关机
- shutdown -r now:  立即重启
- halt
- reboot
- sync : 同步磁盘


### [AR](https://baike.baidu.com/item/ar/7426017)

用于创建、修改备存文件（archive），或从备存文件中提取成员文件。ar命令最常见的用法是将目标文件打包为静态链接库。

压缩的复杂命令可以用SHELL 来简化.

### man 获得帮助信息
man [命令或配置文件]（功能描述：获得帮助信息）


### help 指令
help 命令 （功能描述：获得 shell 内置命令的帮助信息）


ifconfig使用？？？？？？？


### pwd 指令
pwd	(功能描述：显示当前工作目录的绝对路径)
### ls 指令
ls [ 选 项]	[目录或是文件]
-a ：显示当前目录所有的文件和目录，包括隐藏的。
-l	：以列表的方式显示信息
可以-al组合？？？la是不是也可以？？？

### mkdir	[选项]	要创建的目录
-p ：创建多级目录

### rmdir 指令
rmdir 指令删除空目录
rmdir	[选项]	要删除的空目录
rmdir 删除的是空目录，如果目录下有内容时无法删除的。
提示：如果需要删除非空目录，需要使用	rm -rf 要删除的目录

### cat 指令
-n ：显示行号
cat 只能浏览文件，而不能修改文件，为了浏览方便，一般会带上	管道命令 | more
cat 文件名 | more [分页浏览]
cat 文件 1 > 文件 2 （功能描述：将文件 1 的内容覆盖到文件 2）

### more 指令
more 要查看的文件

### less


### > 指令 和 >>  指令
\> 输出重定向 : 会将原来的文件的内容覆盖
\>\> 追加： 不会覆盖原来文件的内容，而是追加到文件的尾部。

ls -l >文件：列表的内容写入文件 a.txt 中（覆盖写））
ls -al >>文件	（功能描述：列表的内容追加到文件 aa.txt 的末尾）

### echo 指令
echo	[选项]	[输出内容]
使用 echo 指令输出环境变量,输出当前的环境路径。


### head 指令

head 用于显示文件的开头部分内容，默认情况下 head 指令显示文件的前 10 行内容
head  文件	(功能描述：查看文件头 10 行内容)

head -n 5 文件	(功能描述：查看文件头 5 行内容，5 可以是任意行数)

### tail 指令
tail 用于输出文件中尾部的内容，默认情况下 tail 指令显示文件的后 10 行内容。
tail文件	（功能描述：查看文件后 10 行内容）
Tail     -n 5 文 件（功能描述：查看文件后 5 行内容，5 可以是任意行数）
Tail    -f	文件功能描述：实时追踪该文档的所有更新，工作经常使用）

实时监控 mydate.txt ,  看看到文件有变化时，是否看到， 实时的追加日期

### ln 指令
ln -s [原文件或目录] [软链接名] （功能描述：给原文件创建一个软链接）

rm -rf LinkToRoot

当我们使用 pwd 指令查看目录时，仍然看到的是软链接所在目录

### find


### locate 指令
locaate 指令可以快速定位文件路径。locate 指令利用事先建立的系统中所有文件名称及路径的locate 数据库实现快速定位给定的文件。Locate 指令无需遍历整个文件系统，查询速度较快。为了保证查询结果的准确度，管理员必须定期更新 locate 时刻
由于 locate 指令基于数据库进行查询，所以第一次运行前，必须使用 updatedb 指令创建 locate 数据库。



