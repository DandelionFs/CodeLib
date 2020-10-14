## History[^1]

zsh条目中的范围作为[first] [last]参数

```shell
history 0
```

## ZSH Wget URL Not Found[^2]

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

所以 **[双引网址]** 即可.

## Flag

- https://comery.github.io/2017/07/20/A-easy-guide-bashrc/
- https://segmentfault.com/a/1190000013612471
- https://juejin.im/post/6844903669578596359



## SSH LS COLOR

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

[^1]:https://qastack.cn/superuser/232457/zsh-output-whole-history
[^2]:https://github.com/ohmyzsh/ohmyzsh/issues/31