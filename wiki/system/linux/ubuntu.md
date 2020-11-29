# Ubuntu

Ubuntu 爬坑.

THX FOR:
- [Ubuntu提示boot分区剩余空间不足或boot分区已满](https://blog.csdn.net/songkai320/article/details/78761391).
- [Ubuntu /boot空间不足时解决办法](https://www.jianshu.com/p/b8e09fa1a387).
- [ubuntu开机卡在logo界面修复](https://blog.csdn.net/weixin_40851278/article/details/82701410).
- [win10没全部关闭导致Ubuntu的WiFi模块不可用](https://blog.csdn.net/github_33678609/article/details/86502916)
- [安装Ubuntu18.04](https://blog.csdn.net/weixin_45591044/article/details/104157669).
- [安装SSR](https://github.com/qingshuisiyuan/electron-ssr-backup/releases).
- [粘贴板](https://blog.csdn.net/lanchunhui/article/details/51670785)
- https://tieba.baidu.com/p/5732130742
- https://blog.csdn.net/gatieme/article/details/51883981
- https://blog.csdn.net/qq_21397217/article/details/52439111
- https://blog.csdn.net/yc1404/article/details/8559852
- https://www.jianshu.com/p/c0dc9189e991
- https://jakting.com/archives/ubuntu-rw-windows-files.html
- http://blog.csdn.net/tjuyanming/article/details/64929901
- http://blog.csdn.net/u013427969/article/details/52744688
- http://blog.itpub.net/10256541/viewspace-591042/
- https://www.zhihu.com/question/20523036
- https://blog.csdn.net/kwu_ganymede/article/details/54134104
- https://doc.appimage.cn/docs/appimage/
- https://blog.csdn.net/SHE_WithWings/article/details/73511345
- https://blog.csdn.net/cuiguanjun/article/details/52832165
- https://blog.csdn.net/liguangxianbin/article/details/86479395
- https://www.cnblogs.com/yymn/p/4581894.html
- http://people.ubuntu.com/~happyaron/ubuntu-docs/precise-html/power-suspendfail.html
- https://www.zhihu.com/question/383262541
- https://www.zhihu.com/question/19721279/answer/677855112
- https://www.cnblogs.com/hustskyking/p/hosts-modify.html
- https://qastack.cn/ubuntu/347152/why-is-the-etc-hosts-file-not-working
- https://askubuntu.com/questions/710420/why-are-some-systemd-services-in-the-masked-state
- https://www.php.cn/linux-440040.html
- https://www.php.cn/linux-440040.html
- https://forum.ubuntu.org.cn/viewtopic.php?t=482097
- https://superuser.com/questions/636274/iterm2-terminal-giving-330132muh3300m330136mw3300m
- https://www.unix.com/shell-programming-and-scripting/196573-how-remove-00m-bash-file.html
- https://qastack.cn/unix/107371/how-to-turn-off-color-with-ls
- http://c.biancheng.net/linux/alias.html
- 配合翻译来看(日语): https://sicklylife.jp/ubuntu/2004/settings.html
- 没事点一下: http://u.nu/ubuntu
- https://www.sysgeek.cn/apt-vs-apt-get/
- https://blog.csdn.net/ysy950803/article/details/78507892 
- https://www.thefanclub.co.za/how-to/ubuntu-touchpad-gestures-install
- [ubuntu 释放空间的7种简单方法](https://blog.csdn.net/qq_42427109/article/details/107882574)



## Preface

200125从虚拟机折腾, 一直到失联，在200323花了一下午入手双系统，对虚拟机say bye，入手Ubuntu…… 某天了解到官网曾经可以申请免费的Ubuntu光盘，很有趣, 应该已经绝版了，指导点[我](https://wiki.ubuntu.org.cn/%E7%94%B3%E8%AF%B7Ubuntu%E5%85%8D%E8%B4%B9%E5%85%89%E7%9B%98%E7%9A%84%E5%85%A8%E7%A8%8B%E6%8C%87%E5%AF%BC)，写在前面留个纪念。（选择版本 -> 填写表格 -> 发出申请 -> 申请接受 -> 收到CD）在安装前请一定看一看Ubuntu官网的[Wiki](https://wiki.ubuntu.org.cn/%E5%AE%89%E8%A3%85_Linux_%E5%BA%94%E7%9F%A5%E7%9A%84%E5%8D%81%E4%BB%B6%E4%BA%8B).大致如下: 

![](./img/Ubuntu.png)

**声明**：**BLOG 只针对 UEFI+GPT 的 Win10 电脑, 或者说本教程用的格式化 Ubuntu Ext2 分区就是采用此格式. 所有命令都有最简模式, 目的是图我自己重装系统的时候方便**

## Install

下载官方的镜像（国内有大量的开源镜像网站），然后用`Ultralso`烧录到一个8G（4G）大小的U盘。重启机器开到BIOS界面，把BOOT里面的``BOOT Security`关掉，重启进入系统UEFI的U盘启动的模式，先进入Ubuntu里面体验一下，不要直接安装。


去找系统的安装源list文件，在`/etc/apt/sources.list`里，用管理员的权限修改下载源地址（提前查到自己对应版本的源地址）。

```shell
sudo vi /etc/apt/sources.list
sudo apt update
```

分盘的时候还请参考最下面的地址，但是值得注意一下`boot`不要太小气，就我的话, 我给他2G，主分区32G，交换空间8G( 貌似和Win10虚存类似, 太大也不必 )，/home 60G，共100G, 不再赘述，分区仅供参考。


**换源**

高校镜像源: 
-  [**USTC Ubuntu Mirror**](https://mirrors.ustc.edu.cn/help/ubuntu.html)
- [**Tinghua Ubuntu Mirror**](https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/)
- [**Ali Ubuntu Mirror**](https://developer.aliyun.com/mirror/ubuntu)

企业镜像源: 
- [**Ali Baba Ubuntu Mirror**](http://mirrors.aliyun.com/help/ubuntu) 
- [**Netease Ubuntu Mirror**](http://mirrors.163.com/.help/ubuntu.htmll)
- [**Huawei Mirrors**](https://mirrors.huaweicloud.com/)


更详细的可以查看 [Ubuntu 换源，安装&卸载软件](https://zhuanlan.zhihu.com/p/27187622), 简单来说:
```bash
#backup your old sourse 
sudo cp /etc/apt/sources.list /etc/apt/sources.list_backup
# open sources.list 
sudo gedit /etc/apt/sources.list
```

## Sys Update
```bash
sudo update-manager -c -d
```

<center>基于<b>wiki.ubuntu.org.cn</b></center>

在用完 Win 后有感, 在没有深入了解人类设计的技术前，永远不要过分相信他，就像是你的电脑，在你真正摸清楚他的操作原理和操作逻辑之前，不要过分依赖他，在他面前，你可能就是赤裸的，所以人生啊，多学习一点东西，可能看书会吸收的很慢，但是幸好他永远是没有上限的，如果有瓶颈，突破它就好了，我所真正担心的是我没有足够的时间和精力去见证世间的一切，害怕的是自己不能静下心来慢慢的学习起来，对那些Fest Learner肃然起敬，但同时我始终都不了解真正的自己，永远在以伤害自己的方式来逼迫自己努力，而不是全身心的投入到自己的学习生涯中，这又是多么的可悲，而有的人意识不到这点，何等的讽刺……




## SOFTWARE Apt

简化版命令
```bash
sudo apt update -y && sudo apt upgrade -y 

sudo apt install git && sudo  apt install python3 && sudo apt install python3-pip && sudo apt install node.js && sudo apt install flameshot && sudo apt install kchmviewer && sudo apt install gthumb  && sudo apt install audacity 

wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add - && sudo add-apt-repository 'deb https://typora.io/linux ./' && sudo apt-get update && sudo apt-get install typora && sudo apt install wget g++ git &&git clone "https://gitee.com/wszqkzqk/deepin-wine-for-ubuntu.git" && cd deepin-wine && sudo ./install.sh &&sudo wget "https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.wechat_2.6.8.65deepin0_i386.deb"  && sudo dpkg -i *wechat*deb && apt install libjpeg62:i386 && sudo wget "https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.im/deepin.com.qq.im_9.1.8deepin0_i386.deb"  && sudo  dpkg -i *qq.im*deb &&  sudo apt install firefox && sudo apt install ubuntu-restricted-extras
```
一般来说, 安装命令有：

```bash
# 使用apt安装软件,譬如安装tree,这里的 -y 参数是为了在安装的时候默认选择yes
sudo apt install tree -y
# deb包安装
sudo dpkg -i xxx.deb
sudo apt install gdebi
sudo gdebi netease-cloud-music_1.2.1_amd64_ubuntu_20190428.deb
#安装依赖（如果提示需要的话）
sudo apt install -f
#另一种deb包安装方式
sudo apt install ./xxxx.deb 
#安装filename.tar.gz软件,然后在解压目录或者bin文件夹中执行setup.sh文件
```
**源码安装**: 有些软件没有被收录进软件镜像源，或者说开发者需要去使用他们最新的版本，这时候就要自己去他们的官网或者是代码托管平台下载最新的Linux源码，自己来build。这种方式安装需要解决很多的依赖，安装前多Google。此处还是以tree为例：

- 先下载最新的源码包

```bash
  tar zxf tree-1.7.0.tgz #解压
  cd  tree-1.7.0/
  
  sudo make # make and install
  sudo make instal l# 如果没有配置环境，先用apt安装build-essential
```
+ [忽略某些依赖安装(Wechat Failure)](https://qastack.cn/server/250224/how-do-i-get-apt-to-ignore-some-dependencies)

```bash
# Check Depend
dpkg --info XXX.deb | grep Depends
# Apt-get
sudo apt install XXX.deb-
# dpkg
sudo dpkg -i --ignore-depends=<--->  XXX.deb
```

### Uninstall

```bash
sudo apt remove --purge XXX
sudo apt autoremove --purge XXX

dpkg --get-selections | grep XXX
sudo apt purge XXX  #一个带core的package，如果没有带core的package，则是情况而定。
```

### Clean
```bash
sudo apt autoclean # 只删除过时的软件包，例如最近更新所取代的软件包，就完全不需要它们。
sudo apt autoremove

dpkg -l |grep ^rc|awk '{print $2}' |sudo xargs dpkg -P 

# 清理日志问题.
sudo echo > /var/log/syslog
sudo echo > /var/log/kern.log

```
**清理SNAP**

执行脚本:

```shell
#!/bin/bash
# Removes old revisions of snaps
# CLOSE ALL SNAPS BEFORE RUNNING THIS
set -eu
snap list --all | awk '/disabled/{print $1, $3}' |
    while read snapname revision; do
        snap remove "$snapname" --revision="$revision"
    done
```

## Run AppImage

> AppImage 是一种把应用打包成单一文件的格式，允许在各种不同的目标系统（基础系统(Debian、RHEL等)，发行版(Ubuntu、Deepin等)）上运行，无需进一步修改。

简而言之就是绿色通用版本.

下载好程序的时候选择[属性]-> 可执行文件. 点击即可, 一般我习惯放在 `/home/usrname/opt/`下, 也可以节省下根目录的空间内存......

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





#### Knowledge For APT & APT-GET

**APT**的其它命令选项可以实现与使用 apt-get 时相同的操作。虽然 apt 与 apt-get 有一些类似的命令选项，但它并不能完全向下兼容 apt-get 命令。也就是说，可以用 apt 替换部分 apt-get 系列命令，但不是全部。

|     apt 命令     |      取代的命令      |           命令的功能           |
| :--------------: | :------------------: | :----------------------------: |
|   apt install    |   apt-get install    |           安装软件包           |
|    apt remove    |    apt-get remove    |           移除软件包           |
|    apt purge     |    apt-get purge     |      移除软件包及配置文件      |
|    apt update    |    apt-get update    |         刷新存储库索引         |
|   apt upgrade    |   apt-get upgrade    |     升级所有可升级的软件包     |
|  apt autoremove  |  apt-get autoremove  |       自动删除不需要的包       |
| apt full-upgrade | apt-get dist-upgrade | 在升级软件包时自动处理依赖关系 |
|    apt search    |   apt-cache search   |          搜索应用程序          |
|     apt show     |    apt-cache show    |           显示装细节           |

当然，apt 还有一些自己的命令：

|   新的apt命令    |              命令的功能              |
| :--------------: | :----------------------------------: |
|     apt list     | 列出包含条件的包（已安装，可升级等） |
| apt edit-sources |              编辑源列表              |

To Be Continued......

**APT-GET**

对于低级操作，仍然需要 apt-get。

### SHORTCUT

#### Desktop Shortcut

| Operation  |                   Effects                    | Operation |             Effects             |
| :--------: | :------------------------------------------: | :-------: | :-----------------------------: |
|  Alt + F1  | 聚焦到桌面左侧任务导航栏，可按上下键进行导航 | Alt + F2  |            运行命令             |
|  Alt + F4  |                 关闭当前窗口                 | Alt + Tab |          切换程序窗口           |
| Alt + 空格 |                 打开窗口菜单                 |   PrtSc   |            桌面截图             |
|  Win + A   |                搜索/浏览程序                 |    Win    | 搜索/浏览程序、文件、音乐文件等 |
|  Win + F   |                搜索/浏览文件                 |  Win + M  |        搜索/浏览音乐文件        |



#### Terminal Shortcut

|       Operation       |                 Effects                  |        Operation        |                        Effects                        |
| :-------------------: | :--------------------------------------: | :---------------------: | :---------------------------------------------------: |
|    Ctrl + Alt + T     |                 打开终端                 |           Tab           |                 命令或文件名自动补全                  |
|   Ctrl + Shift + C    |                   复制                   |    Ctrl + Shift + V     |                         粘贴                          |
|   Ctrl + Shift + T    |        在同一个窗口新建终端标签页        |    Ctrl + Shift + W     |                      关闭标签页                       |
|   Ctrl + Shift + N    |               新建终端窗口               |    Ctrl + Shift + Q     |                     关闭终端窗口                      |
| Ctrl + Shift + PageUp |                标签页左移                | Ctrl + Shift + PageDown |                      标签页右移                       |
|       Ctrl + D        |                关闭标签页                |        Ctrl + C         |                     终止当前任务                      |
|       Ctrl + L        |                 清除屏幕                 |        Ctrl + P         |                  显示上一条历史命令                   |
|       Ctrl + N        |            显示下一条历史命令            |        Ctrl + R         |                   反向搜索历史命令                    |
|      Ctrl + J/M       |          回车（同enter键功能）           |        Ctrl + A         |                    光标移动到行首                     |
|       Ctrl + E        |              光标移动到行尾              |        Ctrl + B         |           关闭想后移动一个位置（backward）            |
|       Ctrl + Z        |          把当前任务放到后台运行          |      Ctrl + PageUp      |                   前一个终端标签页                    |
|    Ctrl + PageDown    |             下一个终端标签页             |           F1            |                     打开帮助指南                      |
|        Win + W        |               展示所有窗口               |         Win + T         |                      打开回收站                       |
|    Ctrl + Win + ↓     |           还原/最小化当前窗口            |     Ctrl + Win + D      |                    最小化所有窗口                     |
|       Ctrl + &        |        恢复Ctrl + H/D/W删除的内容        |     Ctrl + Win + ↑      |                    最大化当前窗口                     |
|       Ctrl + D        |  删除光标位置的一个字符（delete键功能）  |        Ctrl + W         | 删除光标位置的前一个单词（Alt + Backspace组合键功能） |
|       Ctrl + K        |      剪切从光标位置到行末的所有字符      |        Ctrl + Y         |            粘贴Ctrl + U/Ctrl + K剪切的内容            |
|       Ctrl + U        | 剪切从行的开头到光标前一个位置的所有字符 |       Ctrl + H/\*       |      删除光标位置的前一个字符（backspace键功能）      |
|       Ctrl + ←        |        光标移动到下一个单词的词尾        |        Ctrl + →         |              光标移动到上一个单词的词首               |
|        Alt + H        |          打开“帮助”菜单（help）          |        Ctrl + T         |       将光标位置的字符和前一个字符进行位置交换        |
|        Alt + V        |          打开“查看“菜单（view）          |         Alt + T         |              打开“终端”菜单（terminal）               |
|        Alt + E        |          打开“编辑”菜单（edit）          |         Alt + S         |               打开“搜索”菜单（search）                |
|          F11          |                 全屏切换                 |         Alt + F         |                打开“文件”菜单（file）                 |

补充：

2次连续Tab/4次连续Esc/2次连续Ctrl + I|将显示所有命令和工具名称



#### Gedit Shortcut

| Operation |  Effects   |    Operation     |  Effects   |
| :-------: | :--------: | :--------------: | :--------: |
| Ctrl + N  |  新建文档  |     Ctrl + W     |  关闭文档  |
| Ctrl + S  |  保存文档  | Ctrl + Shift + S |   另存为   |
| Ctrl + F  |    搜索    |     Ctrl + H     | 搜索并替换 |
| Ctrl + I  | 跳到某一行 |     Ctrl + C     |    复制    |
| Ctrl + V  |    粘贴    |     Ctrl + X     |    剪切    |
| Ctrl + Q  |    退出    |                  |            |

使用 `ctrl + ;`（此为 fcitx 自带剪贴板插件） ：查看粘贴板的内容，此时显示的就不只有一条内容，一般而言是最近的五次复制的内容。使用数字键进行选择。



#### Screen ShortCut

采用Flameshot[^9] 配合自定义快捷键即可使用


**Reference**

[More] -> https://zhuanlan.zhihu.com/p/139305626


## TRASH SOTWARE
### 福昕阅读 & Okular
地址: https://www.foxitsoftware.cn/pdf-reader/

~~福昕的官方不怎么维护他的服务器了，下载速度慢的一批，~~, 国内速度感人, 网上有一个CDN的源可以下载，缺点是没有中文，但是还可。

```Shell
 # 这个是你没有SSR情况下的选择，有了代理速度可以追上宽带
 wget "http://cdn07.foxitsoftgonware.cn/pub/foxit/reader/desktop/linux/2.x/2.1/en_us/FoxitReader2.1.0805_Server_x64_enu_Setup.run.tar.gz" && hmod +x FoxitReader.enu.setup.2.1.0805.x64.run && sudo ./FoxitReader.enu.setup.2.1.0805.x64.run
 # Okular
sudo apt install okular   # F6开启注释功能，如果出现乱码问题，查看原地址
```


### Wine(慎重)
[ori] [Wine](https://wiki.winehq.org/Ubuntu_zhcn)官方网站（上面失效走这）

经过了漫长的几个晚上和下午,  我决定了, 还是弄虚拟机好了, 主要原因是挂了代理还是下载不来这个,  我想说的是网络不好下的 Ubuntu 就是一个 \*\*

```bash
sudo dpkg --add-architecture i386 
wget -nc https://dl.winehq.org/wine-builds/winehq.key
sudo apt-key add winehq.key
#分支
sudo apt-add-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ eoan main' #Ubuntu 19.10 
sudo apt-add-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ bionic main'#Ubuntu 18.04,Linux Mint 19.x
sudo apt-add-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ xenial main'#Ubuntu 16.04&Linux Mint 18.x
sudo apt update
sudo apt install --install-recommends winehq-stable#稳定分支 	
sudo apt install --install-recommends winehq-devel#开发分支 	
sudo apt install --install-recommends winehq-staging#Staging 分支 	
```

### Fusuma & Touchegg 
一个控制触控板的命令行程序, 原理是将触控板的手势传到命令行映射到快捷键, 所以不如快捷键来的好, 最后被我卸载了, 但是有两个命令我不知道要怎么恢复, 先放在这里.

```bash
sudo usermod -a -G input $USER # sudo gpasswd -a $USER input
gsettings set org.gnome.desktop.peripherals.touchpad send-events enabled
```
### Pinyin

~~**Ibus**(不推荐, 没有联想功能)~~
~~我选择了ibus的小鹤双拼的输入法，他不具备网络联想功能, 然后我意识到了网络联想真tm是个好东西，Only Shit! (我一下子想到了小学用诺基亚物理键盘敲打的费劲感觉的说)···~~
~~设置大屏Ubuntu的输入法大小:~~
~~这个要用到无障碍的字体放大功能，在这个地方也是很是想吐槽的说···~~
1. ~~在Ubuntu软件仓库里，搜索“ibus”，安装其中的“ibus font setting”。~~
2. ~~打开这个插件后就可以设置输入法候选字体的大小了。~~


### ~~QQ delete Qzone~~
> QQ一个高明的方法是该文件采用了不同形式编码集合的方式保存的文件，如果对源文件编辑会破坏部分代码，会导致部分报错，仍然可以使用
- **[Loc]：**Tencent -> QQ -> Plugin -> Com.Tencent.Qzone
- **[Way]：**编辑 Bundle 的标签。

### Youdao Note
> 因为对功能的阉割以及非全平台而弃用
~~打开自己有道云的安装路径下的这个文件：`\Youdao\YoudaoNote\theme\default\skin.xml`开始编辑。后`Ctrl+F`搜索`PanelAd`把`PanelAd Bounds`的值`0.0.0.0`(修改之前记得提前做好备份……) `<PanelAd Bounds="0,0,0,161" DockStyle="bottom"></PanelAd>`~~
~~<font size =1>[吐槽]:从小米便签的编辑功能到它的待办功能，只做差不多的小米生态彻底失望了。便签反馈了三年，开卡了三年无果，真的只剩下骂街了，可能是受众小的缘故吧。待办换Microsoft的TODO，笔记换来换去还是有道云的吧，**排版的方式多、直接暴力保存网页，想要的内容点点手指就可以、关键是公司相比较靠谱……**说起来生态，又有一个经济学原理验证了——“科斯定律“，也可能我没必要要求一个手机公司在应用生态方面做的和高三个层次的Apple相比。</font>~~





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


## Touchpad

```bash
#!/bin/bash
#
# Gestures install 
# version 1.3
# 
# by The Fan Club 2020
#
# NOTE: run as sudo
#
#
# Remove if selected 
if [ "$1" = "--remove" ]; then 
	echo "[Gestures] Gestures uninstall started..."
	python3 -m pip uninstall gestures
	rm /usr/local/bin/gestures
	rm /usr/share/applications/org.cunidev.gestures.desktop
	rm /usr/share/metainfo/org.cunidev.gestures.appdata.xml
	rm /usr/share/icons/hicolor/scalable/apps/org.cunidev.gestures.svg
	# remove libinput-gestures
	su $SUDO_USER libinput-gestures-setup stop
	su $SUDO_USER libinput-gestures-setup autostop
	libinput-gestures-setup uninstall	
	echo "[Gestures] Gestures removal complete."
	exit 
fi
#
# Install libinput-gestures - https://github.com/bulletmark/libinput-gestures
echo "[Gestures] Gestures install started..."
#
# Add user to input group
gpasswd -a $SUDO_USER input
echo "[Gestures] $SUDO_USER added to input user group"
# Install prerequisites
echo "[Gestures] Install all depedencies"
apt-get install xdotool wmctrl libinput-tools python3 python3-setuptools python3-gi python-gobject python3-pip build-essential git 
# Install/Update
if [ -d libinput-gestures ]; then
	rm -r libinput-gestures 
fi
echo "[Gestures] Downloading libinput-gestures from GitHub..."
git clone https://github.com/bulletmark/libinput-gestures.git
cd libinput-gestures
make install
cd ..
echo "[Gestures] libinput-gestures installed"
#
# Install Gestures - https://gitlab.com/cunidev/gestures
#
# Install 
if [ -d gestures ]; then
	rm -r gestures 
fi
echo "[Gestures] Downloading Gestures from GitLab..."
git clone https://gitlab.com/cunidev/gestures
cd gestures
python3 setup.py install
# Cleanup
cd ..
rm -r gestures 
rm -r libinput-gestures 
echo "[Gestures] Gestures installation complete"
# Autostart libinput-gestures at boot and start now for current user
su $SUDO_USER libinput-gestures-setup stop
su $SUDO_USER libinput-gestures-setup autostart
su $SUDO_USER libinput-gestures-setup start
echo "[Gestures] libinput-gestures started for $SUDO_USER"
# Autostart Gestures 
cp /usr/share/applications/org.cunidev.gestures.desktop /home/$SUDO_USER/.config/autostart/
sed -i 's/=gestures/=gestures\&/g' /home/$SUDO_USER/.config/autostart/org.cunidev.gestures.desktop
chown $SUDO_USER:$SUDO_USER /home/$SUDO_USER/.config/autostart/org.cunidev.gestures.desktop
echo
echo "[Gestures] Reboot to complete the installation"
```
解决无法支持三指和四指的遗憾.


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


#### ubuntu 18.04无法从fwupd下载固件

> 通常是更新BIOS、更新网卡之类的需要fwupd。Android手机的bootloader就相当于电脑BIOS，所以Android更容易刷成砖。电脑重装系统是不会碰BIOS的，所以特殊情况才会成砖。



## 双系统的时间不统一

```shell
#这个是Bios里面的 Boot Secury 的问题, 但是关闭之后在进入Ubuntu后又会出现一系列问题.
sudo hwclock -w --localtime
```



## initramfs-tools报错

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



## ubuntu支持`exfat`方法

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



## Ubuntu 永久挂载Win10磁盘

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



## Uninstall Ubuntu

用的不习惯当然先卸载了，Emmmmm，哈哈哈哈，卸载比较简单，大家都知道如果你按照下面的链接安装无误的话，启动引导用的是Ubuntu自带的的 `GUN GRUB`，如果你分盘的时候没有选择下面的启动引导设置，那么你第一次启动的时候一定不会进入Ubuntu的系统。

综上所述，我们把 `GUN GRUB`干掉，然后选择磁盘分区的删除卷即可，软件的话，用EasyUEFI，官网下载的话需要梯子，然后我这里如果有时间会给出下载链接，去网上随便下载一个就好了。



## Grub Wifi

```shell
909778] iwlwifi 0000: 00: 14.3: BIOS contains HGDS but no HRDS
```
暂时无解, 不影响使用...



## Root模式 部分命令找不到

因为系统变量和用户变量不一样, 所以需要将用户变量配置到系统变量里.



## 没有批量操作的压缩命令

+ 写 Shell/Python 脚本

```shell
for i in (fileName)
do
xxx -x $i
done
```

+ 使用gnome的右键压缩指令.

+ Other



## Ubuntu Utf-8 和 Win GBK 的转化

+ 使用`unar`命令: 

```shell
unar (-o (GBK)) xx.zip
```

+ Other




## /bin/bash^M: bad interpreter: No such file or directory

[Cause] : 脚本文件是DOS格式的, 即每一行的行尾以\r\n来标识

```shell
:set ff? # 如果显示是DOS/UNIX
set ff=unix
```






## Hang Up Bug

长时间挂起会导致显示出现问题, 我自己遇到的是 GUI页面崩溃. 可以进入tty2 输入 r 来重启 GUI页面, 但是声卡出现问题[输出显示伪输出]暂时没有什么有效的解决方法, 

#### 挂起后花屏？

挂起时间和导致的问题相关, 短时间内挂机不会产生什么作用, 但是长时间就会导致 Preface 里面的问题.

挂起:Suspend To RAM(STR)

休眠: Suspend To Disk(STD)

一种可能是设备的驱动问题不支持挂起, 但是短时间却可以这是什么鬼??? 

#### 伪输出[Undo]

+ 把你当前的用户加入audio组

```bash
sudo usermod -a -G audio $USER
```

更加详细的可以参考[这个](https://zhuanlan.zhihu.com/p/122887848)

+ 可能是内核的问题

暂无解决方法, TO BE CONTINUED...

### 输出文件中带有` [34;42m` `[00m` 等乱码字符

这个是因为输入的文件带有颜色转义符号引起的, 所以想办法临时禁用颜色即可.


## 指定运行级别

`/etc/inittab`

0：关机
1：单用户【找回丢失密码】
2：多用户状态没有网络服务
**3**：多用户状态有网络服务
4：系统未使用保留给用户
**5**：图形界面
6：系统重启


如何找回 root 密码，如果我们不小心，忘记 root  密码，怎么找回。
- 思路： 进入到 单用户模式，然后修改 root 密码。因为进入单用户模式，root 不需要密码就可以登录。
