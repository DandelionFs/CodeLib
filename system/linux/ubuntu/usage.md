## PREFACE
简化版命令
```bash
sudo apt update -y && sudo apt upgrade -y 

sudo apt install git && sudo  apt install python3 && sudo apt install python3-pip && sudo apt install node.js && sudo apt install flameshot && sudo apt install kchmviewer && sudo apt install gthumb  && sudo apt install audacity 

wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add - && sudo add-apt-repository 'deb https://typora.io/linux ./' && sudo apt-get update && sudo apt-get install typora && sudo apt install wget g++ git &&git clone "https://gitee.com/wszqkzqk/deepin-wine-for-ubuntu.git" && cd deepin-wine && sudo ./install.sh &&sudo wget "https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.wechat_2.6.8.65deepin0_i386.deb"  && sudo dpkg -i *wechat*deb && apt install libjpeg62:i386 && sudo wget "https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.im/deepin.com.qq.im_9.1.8deepin0_i386.deb"  && sudo  dpkg -i *qq.im*deb &&  sudo apt install firefox && sudo apt install ubuntu-restricted-extras
```

## SOFTWARE Apt
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
sudo apt autoclean
sudo apt autoremove

dpkg -l |grep ^rc|awk '{print $2}' |sudo xargs dpkg -P 
```

#### Knowledge For APT & APT-GET

**[LINK]** https://www.sysgeek.cn/apt-vs-apt-get/

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

