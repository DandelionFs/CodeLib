## Boot[^1]

由于 Ubuntu(Linux) 并不是内置N卡驱动，所以如果有 N卡独显 笔记本会发生在 Ufi模式 下启动U盘进入系统的时候卡死。应该先用 `e` 进去 Boot 设置，在末尾 quiet splash 的后面先空一格再加上下面的字符串，F10保存退出：

```shell
acpi_osi=linux nomodeset
```
[Tip] : 如果quiet splash后面发现有- - -这串符号，直接删了就是，只要保证上述添加的参数在splash后面即可



## N卡驱动

进去之后要换aliyun的源, 进去发现分辨率是锁死的(反正不是1080P)，~~是Ubuntu自带的显卡驱动背的锅~~(好像Ubuntu20.04LTS 已经自带 N卡 驱动了......)，更新N卡驱动: 

```bash
sudo ubuntu-drivers autoinstall # 自动安装

sudo gedit /etc/modprobe.d/blacklist.conf # 黑名单
blacklist vga16fb # for nvidia display device install
blacklist nouveau
blacklist rivafb
blacklist rivatv
blacklist nvidiafb

sudo update-initramfs -u &&  reboot # 刷新重启
```



## 亮度异常

安装完成之后发现亮度是不可以调节 :

```bash
# edit by nano, choose one between vim and nano. 
# 按 Ctrl+O 保存、按 Ctrl+X 退出编辑
sudo nano /etc/default/grub

# edit by vim/vi
sudo apt
sudo vim /etc/default/grub
```

将` GRUB_CMDLINE_LINEX_DEFAULT`那一行改成：

```bash
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash acpi_backlight=vendor acpi_osi=Linux"
# 更新后重启 (重启可能时间比较长)
sudo update-grub && reboot
```

补充一个小小的建议：语言设置这是用拖动的(笑) 。



## dpkg:错误：另外一个进程已经为 dpkg 状态数据库 加锁

可能是开机自动更新会占用一会儿这个进程，要么PS kill 他，要么等一会就可以。



## 安装deb 包缺少以来关系，仍未被处理的时候

```shell
sudo apt install -f
```


#### ubuntu 18.04无法从fwupd下载固件[^1]

> 通常是更新BIOS、更新网卡之类的需要fwupd。Android手机的bootloader就相当于电脑BIOS，所以Android更容易刷成砖。电脑重装系统是不会碰BIOS的，所以特殊情况才会成砖。



## 双系统的时间不统一[^2][^3]

```shell
#这个是Bios里面的 Boot Secury 的问题, 但是关闭之后在进入Ubuntu后又会出现一系列问题.
sudo hwclock -w --localtime
```



## initramfs-tools报错[^4]

mdzz，当初分盘的时候太小气，看见别人`/boot`分区给了200M，但是太小了，以后给大点就不会有这问题了。解决方法是删掉多余的内核。dpkg命令是Debian Linux系统用来安装、创建和管理软件包的实用工具。查看自己的linux内核和正使用的内核，然后选择性删除。

```shell
sudo dpkg --get-selections |grep linux-image
sudo uname -a
sudo apt purge 内核名称
```

然后清理/usr/src目录,删除你已经卸载的内核目录

内核版本显示为**install，表示系统已经安装了相应的内核，使用purge命令删除相应的内核。**

```shell
sudo apt purge linux-image-4.4.0-130-generic
```

**deinstall**，表示系统没有安装此内核，但是在配置文件中还残留它的信息，也有可能是以前卸载的时候不彻底。 正常情况下，就已经清理完成辣。输入`df`查看/boot的已用百分比。

```shell
 sudo dpkg -P linux-image-extra-4.4.0-128-generic
```



## 更换介质：请把标有……

> “更换介质：请把标有…… DVD 的盘片插入驱动器“/media/cdrom/”再按回车键，

```shell
# 修改`/etc/apt/sources.list`文件，注释掉`deb cdrom:`开头的一行（第一行）
cd ~
vim /etc/apt/sources.list
apt update
```



## ubuntu支持`exfat`方法[^5]

> 推荐u盘使用exfat格式，为什么呢？两个原因：
>  1、三大主流操作系统（Linux、Mac、Windows）都支持exfat格式。
>  2、exfat支持大于4G的文件。

在ubuntu下，由于版权的原因（据说），默认不支持exfat格式的u盘，对于ubuntu 14.04以上版本，直接运行下面的命令就可以了：

```shell
sudo apt install exfat-utils
```



## Ubuntu的在线账户

及时获取Ubuntu社区的更新.



## snap错误has install-snap change in progress

```shell
snap changes # 获取任务Id
sudo snap abort 14
```



## Ubuntu 永久挂载Win10磁盘[^6]

实际挂载前，D盘为 `/dev/XX`，E盘为 `/dev/XXX`（**注意！这里 sd 后面的不一定和 Windows 一样，图里 Windows 和 Ubuntu 同处于 SSD 上，而 D 和 E 盘均位于 HDD 上，所以从 `a` 变成了 `b`**）

> **接下来，我们假设你要挂载的分区地址为 `/dev/XX`（原 Windows 中的非系统文件目录，即通常意义上的 Windows 分区），要挂载到地址为 `/mnt/windows/d`（Ubuntu 中的非系统文件目录，即 Linux 中的一个目录）**
> 你当然可以（而且必须）根据你的实际情况修改分区地址

```bash
sudo mkdir /mnt/windows/d# 然后关闭 WIndows 的**快速启动**，临时挂载，重启失效，适用于偶尔需要一次的：
sudo mount /dev/XX  /mnt/windows/d
```

在执行完成后，访问你的 `/mnt/windows/d` 应该就能看到原盘符中的文件了，没有文件显示请重启电脑查看第二种方式——永久挂载。

我们需要修改系统文件 `/etc/fstab`，在此之前，我们需要先获得 `/dev/XX` 的 `UUID`，执行指令：

```bash
sudo blkid /dev/XX
sudo apt install vim
sudo vim /etc/fstab
#插入形如 UUID=XXXXXXXXXX   /mnt/windows/d   ntfs  defaults   0   2的字段; 其中第一列为UUID, 第二列为挂载目录（该目录必须为空目录），第三列为文件系统类型，第四列为参数，第五列0表示不备份，最后一列必须为２或0(除非引导分区为1)，如果你是grub引导的话，你会注意到boot分区是1.
sudo mount -a#检查一下，发现还是报错，The disk contains an unclean file system，执行下面：
sudo apt install ntfs-3g
sudo ntfsfix /dev/XX
sudo mount -a#再检查一下，发现全是OK，哈哈
```

上面流程走一遍发现该目录下没有文件，可以右键属性检查一下，如果确实存在，那么重启电脑就OK了，我只挂载了我win的数据盘，系统盘还是不要动的好……



## Uninstall Ubuntu[^7][^8]

用的不习惯当然先卸载了，Emmmmm，哈哈哈哈，卸载比较简单，大家都知道如果你按照下面的链接安装无误的话，启动引导用的是Ubuntu自带的的 `GUN GRUB`，如果你分盘的时候没有选择下面的启动引导设置，那么你第一次启动的时候一定不会进入Ubuntu的系统。

综上所述，我们把 `GUN GRUB`干掉，然后选择磁盘分区的删除卷即可，软件的话，用EasyUEFI，官网下载的话需要梯子，然后我这里如果有时间会给出下载链接，去网上随便下载一个就好了。



## Grub Wifi

```shell
909778] iwlwifi 0000: 00: 14.3: BIOS contains HGDS but no HRDS
```
暂时无解, 不影响使用...



## Root模式 部分命令找不到

因为系统变量和用户变量不一样, 所以需要将用户变量配置到系统变量里.



## 没有批量操作的压缩命令[^9]

+ 写 Shell/Python 脚本

```shell
for i in (fileName)
do
xxx -x $i
done
```

+ 使用gnome的右键压缩指令.

+ Other



## Ubuntu Utf-8 和 Win GBK 的转化[^10]

+ 使用`unar`命令: 

```shell
unar (-o (GBK)) xx.zip
```

+ Other




## /bin/bash^M: bad interpreter: No such file or directory[^11]

[Cause] : 脚本文件是DOS格式的, 即每一行的行尾以\r\n来标识

```shell
:set ff? # 如果显示是DOS/UNIX
set ff=unix
```





## Run AppImage

> AppImage 是一种把应用打包成单一文件的格式，允许在各种不同的目标系统（基础系统(Debian、RHEL等)，发行版(Ubuntu、Deepin等)）上运行，无需进一步修改。[^12]

简而言之就是绿色通用版本.

下载好程序的时候选择[属性]-> 可执行文件. 点击即可[^13], 一般我习惯放在 `/home/usrname/opt/`下, 也可以节省下根目录的空间内存......

```
cd /usr/share/applications
```

创建一个`.desktop`文件. 然后编辑以下内容即可创建图标, 值得注意的是程序运行的图标的是包自带的, 这里定义的只能是应用菜单的.[^14][^15]

```shell
[Desktop Entry]
Version=1.0	
Encoding=UTF-8			# 字符编码  
Name= XXX 
Comment= XXX			# 鼠标经上提示名称 也可国际化
Exec=XXX 				# 菜单执行的命令或程序路径
Terminal=false
Icon=XXX 				# 图标路径
Type=Application
Categories=Development
StartupNotify=false；	#设置软件启动是不通知
Hidden=false			#菜单是否隐藏，类似NoDisplay属性
```

## Proxy Proxy

开电脑的时候很少时候不用修网. 然而网络堵塞原因是多层面的, 以下是自己常常遇到的情况;

- 配置文件有问题, 值得吐槽的是 Win 服务的文件和 Linux 的文件是分开的, 或者更准确的说是区别对待的.我在折腾其他变量之后重新下载了一个手机端的文件才可以使用...
- 开了代理但是没有打开`Clash`
- 开了`Clash`没有开启系统代理
- 套餐过期
- 场主起飞
......

日常的检修记录如下:

1. 关闭系统代理端口转发后打开`clash.razord.top/#/settings`.
2. 执行Clash, 发现此页面会刷新. 表示 Clash 的外部映射端口几次场子的配置问题没有问题. 
3. 选择节点, 开启代理, 进行测试.

之前启示还用的好好的, 可以开机傻瓜的代理. 但是某一天就不可以用了. 可能是自己的Ubuntu又改了什么设置而我没有发现吧......

## Hang Up Bug

长时间挂起会导致显示出现问题, 我自己遇到的是 GUI页面崩溃. 可以进入tty2 输入 r 来重启 GUI页面, 但是声卡出现问题[输出显示伪输出]暂时没有什么有效的解决方法, 

#### 挂起后花屏？

挂起时间和导致的问题相关, 短时间内挂机不会产生什么作用, 但是长时间就会导致 Preface 里面的问题.

挂起:Suspend To RAM(STR)[^16]

休眠: Suspend To Disk(STD)

一种可能是设备的驱动问题不支持挂起[^17], 但是短时间却可以这是什么鬼??? 

#### 伪输出[Undo]

+ 把你当前的用户加入audio组[^18]

```bash
sudo usermod -a -G audio $USER
```

更加详细的可以参考[这个](https://zhuanlan.zhihu.com/p/122887848)

+ 可能是内核的问题[^19]

暂无解决方法, TO BE CONTINUED...

## DNS

吐了吐了, 每天都在修 Ubuntu 的 Bugs , 还好 Ubuntu 在维护方面的教程较多, 即使是搞崩了系统还是可能在安全模式里面修复(大部分时候), 所以也是我选择 Ubuntu 的一个原因吧, 有意思的是我感到 GUI 真的是一个大势所趋, 用了就会不去的那种, 如果在这方面比的话, 选择 Ubuntu 即是再一次的对 Window 示好. 嘿嘿.

### DNS-Hosts

主要的误点是 Hosts 写成了 Host, 然后没有发现, 然后就是漫长的 Google 过程, 过程不再赘述, 这里写下我收集到的资料.

+ Firefox, Chrome 浏览器是可以设置 浏览器代理的, 并且自身是拥有 DNS缓存服务的, Chrome在 `chrome://net-internals/` 里, 虽然在71版本后就看不到具体的Cache了, 但是清除还是有效的[^20].
+ 在浏览器设置代理之后的优先级回大于本地, 以及部分网站会采用长连接的形式, 故表现为 开了代理 或 短时间快速(长连接时间之内)修改Hosts 就出现 Hosts 失效的问题; 然后因为隐私模式下不会复用 TCP 连接，新开连接的时候，会重新解析 DNS 域名，重启浏览器, 所有的连接（包括长连接）都会断开, 自然可以生效了; [^21]
+ 重启网络服务
  ```bash
    service network restart
  ```

+ 在Ubuntu中，如果要刷新DNS缓存，则需要重新启动nscd守护程序。nscd使用以下命令进行安装. 使用以下命令在Ubuntu中刷新DNS缓存：[^22]
   ```bash
   sudo service nscd restart
   sudo service dns-clean start
   ```
+ 关于清理缓存报错 `Failed to start dns-clean.service: Unit dns-clean.service is masked.`

  > mask is a stronger version of disable. Using disable all symlinks of the specified unit file are removed. If using mask the units will be linked to /dev/null. This will be displayed if you check e.g. by systemctl status halt.service. The advantage of mask is to prevent any kind of activation, even manual.
  >
  > Caution: systemctl list-unit-files is listing the state of the unit files (static, enabled, disabled, masked, indirect) and has nothing to do with the state of the service. To have a look at the services use systemctl list-units.[^23]

+ NSCD(name service cache daemon).

> nscd缓存三种服务passwd group hosts，所以它会记录三个库，分别对应源/etc/passwd, /etc/hosts 和 /etc/resolv.conf每个库保存两份缓存，一份是找到记录的，一份是没有找到记录的。每一种缓存都保存有生存时间（TTL）[^24]
>
> |:--:|:--:|
> |logfile debug-file-name|指定调试信息写入的文件名|
> |debug-level value|设置希望的调试级别|
> |threads number|这是启动的等待请求的线程数。最少将创建5个线程|
> | server-user user|如果设置了该选项，nscd将作为该用户运行，而不是作为root。如果每个用户都使用一个单独的缓存（-S参数），将忽略该选项|
> |enable-cache service <yes/no>|启用或禁用制定的 服务 缓存|
> |positive-time-to-live service value|设置 service 在指定缓存中正的项目（成功的请求）的TTL（存活时间）.Value 以秒为单位。较大的值将增加缓存命中率从而减低平均响应时间，但是将增加缓存的一致性问题|
> | negative-time-to-live service value|设置 service 在指定缓存中负的项目（失败的请求）的TTL（存活时间）。 Value 以秒为单位。如果存在由不在系统数据库中的uid（用户ID）（例如在以root身份解包linux 内核源代码时）所拥有的文件将明显改善性能；应该维持较小的值以降低缓存一致性问题|
> | suggested-size service value|这是内部散列表的大小， value 应该保持一个素数以达到优化效果。 |
> |check-files service <yes/no>|启用或禁用检查属于指定 服务 的文件的改变。这些文件是 /etc/passwd， /etc/group， 以及/etc/hosts|

命令[^25]
```bash
nscd -g # 查看统计信息

nscd -i passwd # 清除 nscd缓存：
nscd -i group
nscd -i hosts

rm -f /var/db/nscd/hosts # 删除缓存库或者停掉nscd服务：
service nscd restart

service nscd stop。# 停止nscd 服务
```






#### More

1. [Ubuntu提示boot分区剩余空间不足或boot分区已满](https://blog.csdn.net/songkai320/article/details/78761391).
2. [Ubuntu /boot空间不足时解决办法](https://www.jianshu.com/p/b8e09fa1a387).
3. [ubuntu开机卡在logo界面修复](https://blog.csdn.net/weixin_40851278/article/details/82701410).
4. [win10没全部关闭导致Ubuntu的WiFi模块不可用](https://blog.csdn.net/github_33678609/article/details/86502916)
1. [安装Ubuntu18.04](https://blog.csdn.net/weixin_45591044/article/details/104157669).
2. [安装SSR](https://github.com/qingshuisiyuan/electron-ssr-backup/releases).
7. [粘贴板](https://blog.csdn.net/lanchunhui/article/details/51670785)



[^1]:https://tieba.baidu.com/p/5732130742
[^2]:https://blog.csdn.net/gatieme/article/details/51883981
[^3]:https://blog.csdn.net/qq_21397217/article/details/52439111
[^4]:https://blog.csdn.net/yc1404/article/details/8559852
[^5]:https://www.jianshu.com/p/c0dc9189e991
[^6]:https://jakting.com/archives/ubuntu-rw-windows-files.html
[^7]:http://blog.csdn.net/tjuyanming/article/details/64929901
[^8]:http://blog.csdn.net/u013427969/article/details/52744688
[^9]:http://blog.itpub.net/10256541/viewspace-591042/
[^10]: https://www.zhihu.com/question/20523036
[^11]:	https://blog.csdn.net/kwu_ganymede/article/details/54134104
[^12]: https://doc.appimage.cn/docs/appimage/
[^13]: https://blog.csdn.net/SHE_WithWings/article/details/73511345
[^14]: https://blog.csdn.net/cuiguanjun/article/details/52832165
[^15]: https://blog.csdn.net/liguangxianbin/article/details/86479395
[^16]:https://www.cnblogs.com/yymn/p/4581894.html
[^17]:http://people.ubuntu.com/~happyaron/ubuntu-docs/precise-html/power-suspendfail.html
[^18]:https://www.zhihu.com/question/383262541
[^19]:https://forum.ubuntu.org.cn/viewtopic.php?t=482097

[^20]: https://www.zhihu.com/question/19721279/answer/677855112
[^21]: https://www.cnblogs.com/hustskyking/p/hosts-modify.html
[^22]: https://qastack.cn/ubuntu/347152/why-is-the-etc-hosts-file-not-working
[^23]: https://askubuntu.com/questions/710420/why-are-some-systemd-services-in-the-masked-state
[^24]: https://www.php.cn/linux-440040.html
[^25]: https://www.php.cn/linux-440040.html

