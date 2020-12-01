# CONFIG

> 一切的优化只为让自己的产品走出去，如果不希望花太多时间在磨刀上，那就请把问题聚焦在解决问题上

THX FOR:
- [Deepin-Apps-Installation](https://github.com/Jactor-Sue/Deepin-Apps-Installation)
- [](http://www.keyxl.com/aaa4cff/235/VLC-keyboard-shortcuts.htm)

## DECORATION 
- **Window:** 
  - [Mydockfinder](https://www.mydockfinder.com/)
  - RocketDock(在 Utf-8 下乱码的问题).
- **Ubuntu**:
  - GTK
  - Unity
  - Gname[最美]: 需要Ubuntu系统和浏览器共同安装即可运行
    - Dash-to-dock
      - [禁用 Ubuntu Dock 的方法](https://zhuanlan.zhihu.com/p/48078003)
      - [为什么会有两个 Dock 的贴](https://qastack.cn/ubuntu/975387/why-do-i-have-two-docks-in-ubuntu-17-10-desktop)
      - `sudo apt remove gnome-shell-extension-ubuntu-dock`
    - 窗口三金刚移左(14版本之后) `sudo  apt install gnome-tweaks`+`gnome-tweaks`
    - [Gnome-look官网](https://www.gnome-look.org/) + `~/.themes` +`gsettings set org.gnome.desktop.interface gtk-theme "XXX"` + `gsettings set org.gnome.desktop.wm.preferences theme "XXX"`
  - [Font 指南](https://zhuanlan.zhihu.com/p/40434062)
    - 更多: https://zhuanlan.zhihu.com/p/40434062
    - `ln -s /Windowsdrive/Windows/Fonts /usr/share/fonts/WindowsFonts` 将字体位置链接到你的 Linux 系统的字体文件夹
    - `fc-cache` 重新生成 fontconfig 缓存

## SOFTWARE
**TOC**:
- **Music**
  - [Netease Music](https://music.163.com/#/download)
  - QQ Music
    - [Deepin-QQ](https://github.com/gorquan/QQMusic)
    - [X-Droid](https://www.linzhuotech.com/)
    - [QQMusic QMC Decoder (convert QMC File to MP3 or FLAC)](https://github.com/Presburger/qmc-decoder)
    - [Unlock Music 音乐解锁](https://github.com/ix64/unlock-music)
- **Works**
  - [WPS](https://linux.wps.cn/)
  - [BaidunetDisk-百度网盘](https://pan.baidu.com/download)
  - [XMind](https://www.xmind.net/) + 果壳
  - Master Reader
    - [Shortcuts](https://code-industry.net/masterpdfeditor-help/keyboard_shortcuts/)
  - Cailbre
  - [Audacity](https://audacity.org)  
  - Darktable
  - GIMP
  - OBS
  - TeamViewer
  - Mypainter
  - Krita
- **Proxy**
  - **Clash**
    - Clash For Android
    - Clash For Magisk / Linux
    - Clash For Window
- Tools For Beaytifying
- **Build Soteware**:
  - 坚果云
  - GoldenDict
  - Mircosoft To Do
  - [FluentRSS](https://github.com/yang991178/fluent-reader)
  - Ao
  - Flowchar
  - Bookworn
- **Chat**
  - QQ
  - Wechat
  - Telegram
- **Sys Tools**
  - PulseAudio: 音量调节
  - Blueman: 蓝牙管理器
  - Dconf: 系统编辑器
  - Flameshot: 截图助手
  - [**V16config**](https://wwa.lanzous.com/icv18ob)：
  - [**搜狗输入法简化版**](https://wwa.lanzous.com/ibsjy8f)
  - [**Fliqlo 屏保**](https://wwa.lanzous.com/ibsjzha)
  - [**Bandica 录屏**](https://wwa.lanzous.com/ibsjzjc)
  - [**Rockdock**](https://wwa.lanzous.com/iaD3Wdbvvij)
- **Play**
  - Steam
    - Proxychains
  - Uplay
  - VLC
- Code
  - [GitKaken](https://www.gitkraken.com/)
  - **JetBrains**
    - Clion
    - Pycharm
  - **Typora** / MarkEditor
    - [Pandoc](https://github.com/jgm/pandoc/releases)
  - [VsCode](https://code.visualstudio.com/Download)
  - **Dev-Cpp**：https://wwa.lanzous.com/ifYm8diuo1g
  - **Vim / GVim-for-gtk**
  - [**BvSSH**](https://www.bitvise.com/ssh-client-download):
    - https://wwa.lanzous.com/ibsksbi


## IMG HOSTS
[图床](https://zhuanlan.zhihu.com/p/35270383)
+ [堆爱图床](//img.duiai.cc/tc/)
+ [SM.MS图床](//sm.ms/)
+ [聚合图床](//www.superbed.cn)
+ [堆爱图床](//img.duiai.cc/tc/)

### FCITX-PINYIN
**[LINK]**: https://www.zhihu.com/question/20432630/answer/161256076

可使用插件实现云输入
```bash
sudo apt install language-pack-zh-hans
sudo apt-get install fcitx-googlepinyin
sudo apt install fcitx-pinyin && sudo apt install fcitx-cloudpinyin
```

### [Clash](https://github.com/Dreamacro/clash)

```bash
tar -zxvf clash-linux-amd64-vXXXX.gz
sudo mv clash-linux-amd64-vXXXX /usr/local/bin/clash
sudo chmod +x /usr/local/bin/clash
clash
```

此时会在 ~/.config/clash 目录下生成两个文件：config.yaml 和 Country.mmdb；

- 保持 clash 运行，打开浏览器访问 clash.razord.top 进行策略配置、选择代理线路等等（可能需要根据提示输入IP、端口和口令，具体内容可在 config.yaml 中查看；
- 在系统网络设置中设置手动代理 Settings>Network>Network Proxy>Manual（设置>网络>代理>手动）。

如果不想一直保持终端打开，可使用 nohup clash 命令启动后台运行。或者希望开机自启动 clash，可将 nohup clash 这段命令加入到前面提到的 start-service.sh 脚本的最后。

#### Ubuntu创建桌面图标
**[LINK]**
- https://www.jianshu.com/p/99d3eebcf17f

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

### Firefox & Chrome

**[Dev Link]** : https://developer.mozilla.org/zh-CN/docs/Mozilla/Developer_guide/Source_Code/Downloading_Source_Archives

#### ~~缩放比例~~
- `about:config :火狐标签页，修改配置`
- `layout.css.devPixelsPerPx ：修改缩放比例`

两者现在都已经支持默认缩放比例了，上面的设置可以修改全局的CSS字体大小，如果是笔记本的话会很好用

#### 触控板跟手
提高跟手程度只需要把动画时间和幅度变短就好。

- Chrome参数可以改为`200.0.20.80.8.50`；
- 火狐打开`about:config`标签页找到`general.smoothScroll.mouseWheel.durationMaxMS` `general.smoothScroll.mouseWheel.durationMinMS`这两个值，分别改为200和50即可。这个和Chrome参数前面的200和0相似.

#### Chrome 插件显示
自定义 Chrome 的部分设置(chrome://flags/):
 + Extensions Toolbar Menu -> Dis
 + Font Access APIs -> En

#### H5播放引擎
```bash
sudo apt install ubuntu-restricted-extras
```

#### 引擎
```http
# Every 
https://www.google.com/search?q＝%s
https://www.baidu.com/s?wd=%s
https://www.dogedoge.com/results?q=%s
https://www.sogou.com/web?query＝%s
https://cn.bing.com/search?g＝%s
https://www.so.com/s?q=%s
https://search.yahoo.com/search?p=%s
https://seeres.com/search?q=%s
#mobile
https://quark.sm.cn/s?q=%s
https://yz.m.sm.cn/s?q=%s
https://m.toutiao.com/result?q=%s
# Video
https://search.bilibili.com/all?keyword=%s
#Book
https://www.douban.com/search?q=%s
https://www.amazon.cn/s?k=%s&__mk_zh_CN=%E4%BA%9A%E9%A9%AC%E9%80%8A%E7%BD%91%E7%AB%99&ref=nb_sb_noss
# Question
https://www.zhihu.com/search?q=%s
#Translate
https://translate.google.cn/#view=home&op=translate&sl=auto&tl=zh-CN&text=%s
# Code
https://github.com/search?q=%s
#hackr.io
# Wiki
https://zh.wikipedia.org/zh-cn/%s
https://baike.baidu.com/search?&word=%s
https://wiki.mbalib.com/w/index.php?title=Special:Search&search=%s
#Emoji
https://emojipedia.org/search/?q=%s&utm_source=opensearch
```

#### Extension
+ **[视频弹窗]：**
详见拓展**[[视频弹出工具-Github](https://github.com/harytfw/popup-tool )]**
+ **[侧边翻译]:** 
  +  **EdgeTranslate - 1.7.2** 及以下 -> [[移步]](https://github.com/EdgeTranslate/EdgeTranslate/blob/fftf/docs/wiki/zh_CN/%E8%87%B4%E7%81%AB%E7%8B%90%E7%94%A8%E6%88%B7.md)。
  +  **Saladict - 7.6** 及以下,Firefox 一直显示包下载是损坏的…
+ **Video Speed Controller**
+ **OneTab**
+ **SmoothScroll**
+ **沙拉查词-聚合词典划词翻译**
+ **Copy as Plain Text**
+ **uTab - Custom New Tab**
+ **Tampermonkey**
  + 智慧树插件
  + **Bilibili**
+ 捕捉网页截图 
+ Dark Reader
+ XDown
+ **购物党自动比价工具**
+ **pakku：哔哩哔哩弹幕过滤器**
+ No Per-Script Font!
+ Font Rendering Enhancer
+ Set Character Encoding
+ Sourcegraph
+ Stylish-为任意网站自定义主题
+ GitZip for github
+ 安全外壳 (SSH)
+ **Vimium**


### Typora

页边距：相关主题下的CSS里面搜索`write`找到`max-width`就是显示的页边距，自行调整

**Ubuntu:** 
```bash
wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add -
sudo add-apt-repository 'deb https://typora.io/linux ./' && sudo apt update && sudo apt install typora
```

### Word To MD
**[LINK]** https://www.zhihu.com/question/24170089
+  在线工具：https://word2md.com/
   + 项目[源码](https://github.com/benbalter/word-to-markdown).
+ [Writage](http://www.writage.com/)插件

### Gmail & Outlook
众多邮箱手机客户端可以丝滑登录Google以及代收邮件，电脑端169收费。

> 据我们的技术说，gmail被屏蔽了，但是仍有一部分地址是漏网之鱼，可以通过这些地址来接收到墙外的邮件。因为只有少部分地址是可以用的，所以你们看现在号称能够接收gmail的客户端，大多都是手机的app，不开放电脑端是因为无法承受大流量的接入，会过载。


### Deepin QQ && Deepin Wechat
**[LINK]** https://zhuanlan.zhihu.com/p/144286142

**[Deepin-wine]** https://github.com/wszqkzqk/deepin-wine-ubuntu

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

#### QQ Image Question
- 禁用IPV6......
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
- 解决托盘ICONS: https://extensions.gnome.org/extension/1031/topicons/

### FlameShot
UBUNTU 开机自启动:
```bash
gnome-session-properties
```

### Android & PC Transform Films

**[LINK]** : https://www.ifanr.com/app/668324

+ **Xender** : http://www.xender.com/
+ Send-anywhere : https://send-anywhere.com/
+  Portal: http://portal.pushbullet.com/
+  Reep. io : https://reep.io/
+  Snapdrop: https://snapdrop.net/
+  AirMore: http://airmore.com/
+  BT Sync: https://www.getsync.com/
+  file ai: https://fileai.com
+  Pushbullet: https://www.pushbullet.com/
+  Telegram

### Mircosoft To do -- Ao

**[LINK]**  
- https://github.com/klaussinani/ao
- https://github.com/klaussinani/ao/issues/94

采用和VSCode 相同的技术开发--> Electronjs. 安装完成之后, 自然在走系统代理的时候出现了问题, 如无法登录微软账户的问题；根据 项目的 ISSUE [^21] 可以执行以修复登录问题.
```bash
ao --proxy-pac-url= XXXXX
```

### VLC
| F                            | Fullscreen               |
| ---------------------------- | ------------------------ |
| Space                        | Play/Pause               |
| T                            | Show position (time)     |
| S                            | Stop                     |
| Ctrl+Q                       | Quit                     |
| +/-                          | Faster/Slower            |
| N/P                          | Next/Previous            |
| Shft+Left/Shft+Right         | Jump very short          |
| Alt+Left/Alt+Right           | Jump short               |
| Ctrl+Left/Ctrl+Right         | Jump medium              |
| Ctrl+Alt+Left/Ctrl+Alt+Right | Jump long                |
| Ctrl+Up/Ctrl+Down            | Volume up/down           |
| M                            | Mute                     |
| Ctrl+M                       | Show DVD-menu            |
| Left/Right Up/Down Enter     | DVD-menu navigation keys |


### VMware
#### 触控板滑动
> 一个有趣的现象就是 **Ubuntu 默认触控板驱动不支持双指放大, 但是Win10 的触控板驱动的参数却可以传到 Vmare 中**.  

两种解决方法：
- 直接放弃滑动，改用上下左右控制界面也不是不可以，你说呢？
- 改用管理员的模式运行来获取触控板的参数.

#### 处理器数和进程数
根据自己电脑的配置进行选择，首先百科`i5-9300H`的一些参数：
1.  处理器频率介于2.4和4.1 GHz之间，并且由于超线程，可同时执行多达8个线程 。
2.  英特尔酷睿i5-9300H的性能与较旧的酷睿i7-7920HQ（3.1 – 4.1 GHz）相似 。


### Terimal

#### Powershell

> PowerShell 的 pipe 传递的是 .net object，而不是 raw 字符串，于是这就打开了一扇神奇的大门，因为 PowerShell 的一切组件都可以和谐地共存，彼此不用互相猜忌，不用猜你喂给我的数据合不合法，也不用担心我喂给你的参数格式对不对。大家共享一个 CLR，拥有丰富的 metadata，自由自在地在 .net 的世界里徜徉和探索......
>
> 参考: https://www.zhihu.com/question/22611859/answer/28897482

[More]:
1. 收集和分享 Windows PowerShell 相关教程,技术和最新动态: www.pstips.net
2. Chocolatey Packages Manager: www.chocolatey.org
3. https://www.zhihu.com/question/388789219/

#### 命令行全局快捷键设置
**[LINK]** https://www.jianshu.com/p/545e3f76eece

1. Win+R -> `comtrol`
2. 管理工具中加入想要添加应用的快捷方式, 然后右键属性设置全局快捷键.

打开的速度应该还是有比较大的延迟, 但是可以代替 Ubuntu 下的坏习惯.


## MORE LINK
- **SSR**
  - https://github.com/qingshuisiyuan/electron-ssr-backup/blob/master/Ubuntu.md
  - https://github.com/qingshuisiyuan/electron-ssr-backup/blob/master/issue.md
  -  https://alanlee.fun/2018/05/18/ubuntu-ssr/#%E5%90%AF%E5%8A%A8-SSR
