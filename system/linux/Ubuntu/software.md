### Ubuntu Config

~~暂时不考虑，浪费时间……~~

**[打脸]**: 使用的原理是Ubuntu的 GNAME 插件，需要Ubuntu系统和浏览器共同安装即可运行

#### 窗口管理移左

听说14版本前都是在左面。但是 Ubuntu18.04 移到了左面, 执行命令:
```bash
sudo  apt install gnome-tweaks`
# alt+f2
gnome-tweaks
```
<br>

#### 输入法选择
语言支持里可以选择实现模式.

~~**Ibus**(不推荐, 没有联想功能)~~

~~我选择了ibus的小鹤双拼的输入法，他不具备网络联想功能, 然后我意识到了网络联想真tm是个好东西，Only Shit! (我一下子想到了小学用诺基亚物理键盘敲打的费劲感觉的说)···~~

~~设置大屏Ubuntu的输入法大小:~~

~~这个要用到无障碍的字体放大功能，在这个地方也是很是想吐槽的说···~~
1. ~~在Ubuntu软件仓库里，搜索“ibus”，安装其中的“ibus font setting”。~~
2. ~~打开这个插件后就可以设置输入法候选字体的大小了。~~

**Fcitx**[^2]
可使用插件实现云输入

~~Google 拼音 &~~ fcitx-pinyin

```bash
sudo apt install language-pack-zh-hans
sudo apt-get install fcitx-googlepinyin
sudo apt install fcitx-pinyin && sudo apt install fcitx-cloudpinyin
```

#### 双Dock修改 

+ 禁用 Ubuntu Dock 的方法 ->  https://zhuanlan.zhihu.com/p/48078003
+ 为什么会有两个 Dock 的贴 -> https://qastack.cn/ubuntu/975387/why-do-i-have-two-docks-in-ubuntu-17-10-desktop.

我采用的是移除 Gnome Shell Ubuntu Dock 包 , 后果是 有的时候开机亮度无法调节, 设置里面的Dock 失效, 前者可以重启解决, 总之问题不大.
```
sudo apt remove gnome-shell-extension-ubuntu-dock
```

#### 主题美化

**Address**: https://www.gnome-look.org/

**Position**: ~/.themes

```bash
mkdir -p ~/.themes
tar -xvf Ant-Dracula.tar -C ~/.themes
gsettings set org.gnome.desktop.interface gtk-theme "XXX"
gsettings set org.gnome.desktop.wm.preferences theme "XXX"
```

<br>

#### 使用跨系统字体[^3]

**单系统:** https://zhuanlan.zhihu.com/p/40434062

**双系统:**

```bash
ln -s /Windowsdrive/Windows/Fonts /usr/share/fonts/WindowsFonts # 将字体位置链接到你的 Linux 系统的字体文件夹
fc-cache # 重新生成 fontconfig 缓存
```
<br>

### Apt

一般来说, 安装命令有：

```bash
# 使用apt安装软件,譬如安装tree,这里的 -y 参数是为了在安装的时候默认选择yes
sudo apt install tree -y

# deb包安装
sudo dpkg -i xxx.deb
sudo gdebi ???
sudo apt install gdebi
sudo gdebi netease-cloud-music_1.2.1_amd64_ubuntu_20190428.deb

#安装依赖（如果提示需要的话）
sudo apt install -f

#另一种deb包安装方式
sudo apt install ./xxxx.deb 

#安装filename.tar.gz软件,然后在解压目录或者bin文件夹中执行setup.sh文件
tar -xzvf file.tar.gz
```

 **源码安装**

有些软件没有被收录进软件镜像源，或者说开发者需要去使用他们最新的版本，这时候就要自己去他们的官网或者是代码托管平台下载最新的Linux源码，自己来build。这种方式安装需要解决很多的依赖，安装前多Google。

此处还是以tree为例：

- 先下载最新的源码包

```bash
  tar zxf tree-1.7.0.tgz #解压
  cd  tree-1.7.0/
  
  sudo make # make and install
  sudo make instal l# 如果没有配置环境，先用apt安装build-essential
```
**忽略某些依赖安装(Wechat Failure)**:[^4]

```bash
# Check Depend
dpkg --info XXX.deb | grep Depends
# Apt-get
sudo apt install XXX.deb-
# dpkg
sudo dpkg -i --ignore-depends=<--->  XXX.deb
```
简化版命令
```bash
sudo apt update -y && sudo apt upgrade -y && sudo apt install git && sudo  apt install python3 && sudo apt install python3-pip && sudo apt install node.js && sudo apt install flameshot && sudo apt install kchmviewer && sudo apt install && sudo apt install gthumb  && sudo apt install audacity 
wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add - && sudo add-apt-repository 'deb https://typora.io/linux ./' && sudo apt-get update && sudo apt-get install typora && sudo apt install wget g++ git &&git clone "https://gitee.com/wszqkzqk/deepin-wine-for-ubuntu.git" && cd deepin-wine && sudo ./install.sh &&sudo wget "https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.wechat_2.6.8.65deepin0_i386.deb"  && sudo dpkg -i *wechat*deb && apt install libjpeg62:i386 && sudo wget "https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.im/deepin.com.qq.im_9.1.8deepin0_i386.deb"  && sudo  dpkg -i *qq.im*deb &&  sudo apt install firefox && sudo apt install ubuntu-restricted-extras
# 配合使用 网易云 & XMind & VSCode & WPS & Mircosoft To Do & 福昕阅读 & Okular & Wine & Abdroid Studio & Clash & JDK & SDK & CPP
# 配合修改 : QQ修改IPV6
```

#### Uninstall

```bash
sudo apt remove --purge XXX
sudo apt autoremove --purge XXX

dpkg --get-selections | grep XXX
sudo apt purge XXX  #一个带core的package，如果没有带core的package，则是情况而定。
```

#### Clean
```bash
sudo apt autoclean
sudo apt autoremove

dpkg -l |grep ^rc|awk '{print $2}' |sudo xargs dpkg -P 
```

#### Typora 

```bash
wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add -
sudo add-apt-repository 'deb https://typora.io/linux ./' && sudo apt update && sudo apt install typora
```
#### Deepin QQ && Deepin Wechat [^5]

Deepin-wine: https://github.com/wszqkzqk/deepin-wine-ubuntu

因为采用Deepin前缀, 所以不会和 Wine 产生冲突

```bash
# deepin-wine容器
sudo apt install wget g++ git
git clone "https://gitee.com/wszqkzqk/deepin-wine-for-ubuntu.git" && cd deepin-wine && sudo ./install.sh

#  Wechat 的两个版本, 自己安装的是第二个 && 最后一个是解决微信无法查看发送图片问题
sudo wget "https://mirrors.huaweicloud.com/deepin/pool/non-free/d/deepin.com.wechat/deepin.com.wechat_2.6.8.65deepin0_i386.deb""https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.wechat_2.6.8.65deepin0_i386.deb"  && sudo dpkg -i *wechat*deb && apt install libjpeg62:i386


# QQ(推荐, 后者Emoji会出问题)
sudo wget "https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.im/deepin.com.qq.im_9.1.8deepin0_i386.deb"  && sudo  dpkg -i *qq.im*deb


# Tim
sudo wget "https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.office/deepin.com.qq.office_2.0.0deepin4_i386.deb" && sudo dpkg -i *qq.office*deb
```
解决托盘ICONS: https://extensions.gnome.org/extension/1031/topicons/

QQ Image Question

```bash
sudo  vim /etc/sysctl.conf

# Add IPv6 disabled
net.ipv6.conf.all.disable_ipv6 =1
net.ipv6.conf.default.disable_ipv6 =1
net.ipv6.conf.lo.disable_ipv6 =1

sudo sysctl -p && sudo touch /etc/rc.local && sudo chmod 755 /etc/rc.local

#!/bin/bash
# /etc/rc.local
/etc/sysctl.d
/etc/init.d/procps restart
exit 0
```

#### 网易云音乐

Debian： https://music.163.com/#/download

#### ~~flash插件(卒)-见下一条~~

~~注意：如b站会发现是没有H5播放的，但是同等条件下Chromium是有的，执行下面的代码~~

#### Browser 

**~~Chromium~~**
自定义 Chrome 的部分设置(chrome://flags/):
 + Extensions Toolbar Menu -> Dis
 + Font Access APIs -> En

**Firefox**

```bash
 sudo apt update && sudo apt install firefox && sudo apt install ubuntu-restricted-extras
```

#### ~~electron_ssr~~[^6] [^7] [^8]

~~找包(或者软件商店???), 之后拿到了他的deb包，然后顺着安装会发现没有他的依赖包，提前到设置里面打开网络代理~~

```bash
sudo dpkg -i ...  #这里会提示你缺少一些必要的依赖包，跟着安装
sudo apt --fix-broken install
#  Doc ???
sudo apt install libcanberra-gtk-module libcanberra-gtk3-module gconf2 gconf-service libappindicator1
# sudo apt install libssl-dev
# sudo apt install libsodium-dev
sudo apt install python
```

#### Xmind 

去官方下载: https://www.xmind.net/ +果壳里面找到破解版文件.

#### VS code

地址：https://code.visualstudio.com/Download 

记得区设置里面把代理选项勾上.

#### WPS

官网地址: https://linux.wps.cn/


#### Node.js & Python & pip & Git &  kchmviewer & gthumb/feh & audacity 

```bash
sudo apt update -y && sudo apt upgrade -y && sudo apt install git && sudo  apt install python3 && sudo apt install python3-pip && sudo apt install node.js && sudo apt install flameshot && sudo apt install kchmviewer && sudo apt install && sudo apt install feh  && sudo apt install audacity 
```

flameshot 设置开机自启动:
```bash
gnome-session-properties
```


</br>

#### 福昕阅读 & Okular

地址: https://www.foxitsoftware.cn/pdf-reader/

~~福昕的官方不怎么维护他的服务器了，下载速度慢的一批，~~, 国内速度感人, 网上有一个CDN的源可以下载，缺点是没有中文，但是还可。

```Shell
 # 这个是你没有SSR情况下的选择，有了代理速度可以追上宽带
 wget "http://cdn07.foxitsoftgonware.cn/pub/foxit/reader/desktop/linux/2.x/2.1/en_us/FoxitReader2.1.0805_Server_x64_enu_Setup.run.tar.gz" && hmod +x FoxitReader.enu.setup.2.1.0805.x64.run && sudo ./FoxitReader.enu.setup.2.1.0805.x64.run
 # Okular
sudo apt install okular   # F6开启注释功能，如果出现乱码问题，查看原地址
```

#### Wine(慎重)

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

#### 百度网盘

[Ori] : https://pan.baidu.com/download).


#### Android Studio

参见Ubuntu 软件商店的直接下载方式.

#### Clash

[GitHub] :https://github.com/Dreamacro/clash

```bash
tar -zxvf clash-linux-amd64-vXXXX.gz
sudo mv clash-linux-amd64-vXXXX /usr/local/bin/clash
sudo chmod +x /usr/local/bin/clash
clash
```

此时会在 ~/.config/clash 目录下生成两个文件：config.yaml 和 Country.mmdb；

+ 保持 clash 运行，打开浏览器访问 clash.razord.top 进行策略配置、选择代理线路等等（可能需要根据提示输入IP、端口和口令，具体内容可在 config.yaml 中查看；

+ 在系统网络设置中设置手动代理 Settings>Network>Network Proxy>Manual（设置>网络>代理>手动）。

如果不想一直保持终端打开，可使用 nohup clash 命令启动后台运行。或者希望开机自启动 clash，可将 nohup clash 这段命令加入到前面提到的 start-service.sh 脚本的最后。

**创建桌面图标**
```bash
sudo vim /usr/share/applications/Clash.desktop
vim Clash.desktop
＃[Desktop Entry] 文件头
＃Version    版本
＃Name    应用名称
＃Name[xx]    不同语言的应用名称
＃Comment 注释
＃Exec    执行文件路径
＃Icon    图标路径
＃Terminal    是否使用终端
＃Type    启动器类型
＃Categories  应用的类型（内容相关）
```

#### Fusuma & Touchegg

一个控制触控板的命令行程序, 原理是将触控板的手势传到命令行映射到快捷键, 所以不如快捷键来的好, 最后被我卸载了, 但是有两个命令我不知道要怎么恢复, 先放在这里.

```bash
sudo usermod -a -G input $USER # sudo gpasswd -a $USER input
gsettings set org.gnome.desktop.peripherals.touchpad send-events enabled
```

#### Git Kraken

[Ori] : https://www.gitkraken.com/

#### JDK

[Ori] : http://www.oracle.com/technetwork/java/javase/downloads/index.html

```bash
# Win10 bin/jlink.exe --module-path jmods --add-modules java.desktop --output jre
bin/jlink --module-path jmods --add-modules java.desktop --output jre

sudo mv jdkXXX /usr/lib/XXX
sudo vim ~/.bashrc #Bash && ZSH 不一样

export JAVA_HOME=/usr/libl/jdkXXX  
export JRE_HOME=${JAVA_HOME}/jre  
export CLASSPATH=.:${JAVA_HOME}/lib:${JRE_HOME}/lib  
export PATH=${JAVA_HOME}/bin:$PATH

sudo source ~/.bashrc && java --version

```

#### SDK [^10] [^11] [^12] [^13] [^14]

[Ori] : https://developer.android.com/studio#downloads

我记得自己是挂了代理进去设置的, 一直在Download T_T

#### CPP

[Need] : gcc , g++ , (c)make [^15]

Diff between cmake and make 
[Ori] : https://stackoverflow.com/qu  estions/25789644/difference-between-using-makefile-and-cmake-to-compile-the-code/25790020#25790020
> Make (or rather a Makefile) is a buildsystem - it drives the compiler and other build tools to build your code.
> CMake is a generator of buildsystems. It can produce Makefiles, it can produce Ninja build files, it can produce KDEvelop or Xcode projects, it can produce Visual Studio solutions. From the same starting point, the same CMakeLists.txt file. So if you have a platform-independent project, CMake **is****** a way to make it buildsystem-independent as well.
> If you have Windows developers used to Visual Studio and Unix developers who swear by GNU Make, CMake is (one of) the way(s) to go.
> I would always recommend using CMake (or another buildsystem generator, but CMake is my personal preference) if you intend your project to be multi-platform or widely usable. CMake itself also provides some nice features like dependency detection, library interface management, or integration with CTest, CDash and CPack.
> Using a buildsystem generator makes your project more future-proof. Even if you're GNU-Make-only now, what if you later decide to expand to other platforms (be it Windows or something embedded), or just want to use an IDE?

#### Android & Ubuntu PC Transform Films[^16]

+ Xender : http://www.xender.com/
+ Send-anywhere : https://send-anywhere.com/
+  Portal: http://portal.pushbullet.com/
+  Reep. io : https://reep.io/
+  Snapdrop: https://snapdrop.net/
+  AirMore: http://airmore.com/
+  BT Sync: https://www.getsync.com/
+  file ai: https://fileai.com
+  Pushbullet: https://www.pushbullet.com/
+   Telegram

#### ZSH [^17] [^18] [^19] [^20]

#### Mircosoft To do

[Github Ori] : https://github.com/klaussinani/ao

采用和VSCode 相同的技术开发--> Electronjs. 安装完成之后, 自然在走系统代理的时候出现了问题, 如无法登录微软账户的问题；根据 项目的 ISSUE [^21] 可以执行以修复登录问题.
```bash
ao --proxy-pac-url= XXXXX
```
<br>

#### Knowledge For APT & APT-GET[^22]

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



#### 添加应用程序到系统

[参考] : https://www.jianshu.com/p/99d3eebcf17f


#### Gedit Namo Vim Vi [^23][^24]

linux下有很多文本编辑器，其中系统都会自带nano和vi这两个最基本的编辑器。

+ Nnno非常適合編輯配置文件，但是如果要進行編程，最好使用Vim或Emacs。 Nano支持突出顯示。但這是非常主觀的。

+ vi是老式的文字处理器，功能已经很齐全。不管好不好用，既然大家这么推崇，肯定有他的好处，我们先学习了肯定不会有坏处。vi使用于文本编辑，但是vim更适用于coding。

+ vim是vim 的升级版, Vim是模態的意思是每個鍵在不同的模式中意味著不同的東西。
  + 多级撤消 : vi里按 u只能撤消上次命令
  + 易用性: 运行于unix,windows ,mac等操作平台
  + 语法加亮: vim可以用不同的颜色来加亮你的代码。
  + 可视化操作: 即vim不仅可以在终端运行，也可以运行于x window、 mac os、 windows。
  + 对vi的完全兼容: 某些情况下，你可以把vim当成vi来使用。

+ Geany 有很好的功能，內置終端窗口非常好。我將它用於大多數編程項目。

+ Gedit 是图形化的编辑程序, 学习成本低, 簡單輕巧，但你必須安裝一堆插件才能趕上Geany的普通內置功能，比如代碼折疊等。而Geany插件將為您提供額外的功能，如版本控製集成，可選和non-intrusive項目管理，在功能定義和聲明等之間跳轉。而Geany中可用的可配置鍵綁定允許您幾乎完全按照自己的喜好進行設置 – 盡管默認值也很不錯。 Gedit可以捆綁Python解釋器，但是Geany捆綁了整個虛擬終端。

+ Emacs 具有語法突出顯示並支持擴展, 並且可以通過其嵌入的Lisp(elisp)方言進行擴展。它還具有許多統計程序的模式，支持tex，日曆，郵件閱讀實用程序，俄羅斯方塊甚至精神科醫生。 Emacs(或Vim，但對於統計數據不太好)值得學習，因為它們都是跨平台的，並且支持世界上幾乎所有的編程語言。

**Reference**

[More] -> https://zhuanlan.zhihu.com/p/139305626

[^1]: https://blog.csdn.net/ysy950803/article/details/78507892 
[^2]: https://www.zhihu.com/question/20432630/answer/161256076
[^3]: https://zhuanlan.zhihu.com/p/40434062
[^4]: https://qastack.cn/server/250224/how-do-i-get-apt-to-ignore-some-dependencies
[^5]: https://zhuanlan.zhihu.com/p/144286142
[^6]: https://github.com/qingshuisiyuan/electron-ssr-backup/blob/master/Ubuntu.md
[^7]: https://github.com/qingshuisiyuan/electron-ssr-backup/blob/master/issue.md
[^8]: https://alanlee.fun/2018/05/18/ubuntu-ssr/#%E5%90%AF%E5%8A%A8-SSR
[^9]: https://zhuanlan.zhihu.com/p/45919661
[^10]: https://developer.android.com/studio/intro/update#sdk-manager 
[^11]: https://developer.android.com/studio#cmdline-tools
[^12]: https://stackoverflow.com/questions/34556884/how-to-install-android-sdk-on-ubuntu
[^13]: https://www.jianshu.com/p/8a2fad182168
[^14]: https://blog.csdn.net/x199699/article/details/82354051
[^15]: https://code.visualstudio.com/docs/cpp/config-linux
[^16]: https://www.ifanr.com/app/668324
[^17]: https://www.sysgeek.cn/install-zsh-shell-ubuntu-18-04/
[^18]: https://my.oschina.net/u/2266513/blog/3103451
[^19]: https://zhuanlan.zhihu.com/p/37195261
[^20]: https://www.jianshu.com/p/b61473e22c8b
[^21]: https://github.com/klaussinani/ao/issues/94
[^22]: https://www.sysgeek.cn/apt-vs-apt-get/
[^23]:  https://developer.aliyun.com/article/309383
[^24]:  https://ubuntuqa.com/zh-tw/article/1230.html