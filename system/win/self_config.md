---
Create Date: 2020-02-05 04:22:00
---

## Preface

> MicrosoftWindows 是由美国微软公司研发的一套操作系统，问世于1985年，起初仅是**Microsoft-DOS**模拟环境，后续的系统版本由于微软不断的更新升级，不但易用，也当前应用最广泛的操作系统。 Windows采用了**图形化模式GUI( Graphial User Interface )**，比起输入指令使用的方式更为人性化。随着计算机硬件和软件的不断升级，微软的  Windows也在不断升级，从架构的16位、32位再到64位,系统版本从最初的 Windows1.0 到 Windows95、 Windows98、 Windows2000、 WindowsXP、 WindowsVista、 Windows7 、 Windows8、Windows8.1、Windows 10和 Windows  Server服务器企业级操作系统。

<br>

## Decoration 

+ [Dock](https://www.mydockfinder.com/)💻
+ RocketDock(在 Utf-8 下乱码的问题).

<br>

## Application 

一切的操作只为让自己走出去，如果不希望花太多时间在磨刀上，那就请把问题聚焦在解决问题上, 即:

**" 个性化设置！"**

### ~~Youdao Note~~

~~打开自己有道云的安装路径下的这个文件：`\Youdao\YoudaoNote\theme\default\skin.xml`开始编辑。后`Ctrl+F`搜索`PanelAd`把`PanelAd Bounds`的值`0.0.0.0`(修改之前记得提前做好备份……) `<PanelAd Bounds="0,0,0,161" DockStyle="bottom"></PanelAd>`~~
~~<font size =1>[吐槽]:从小米便签的编辑功能到它的待办功能，只做差不多的小米生态彻底失望了。便签反馈了三年，开卡了三年无果，真的只剩下骂街了，可能是受众小的缘故吧。待办换Microsoft的TODO，笔记换来换去还是有道云的吧，**排版的方式多、直接暴力保存网页，想要的内容点点手指就可以、关键是公司相比较靠谱……**说起来生态，又有一个经济学原理验证了——“科斯定律“，也可能我没必要要求一个手机公司在应用生态方面做的和高三个层次的Apple相比。</font>~~
### Firefox&Chrome

#### ~~缩放比例~~
~~about:config :火狐标签页，修改配置~~
~~layout.css.devPixelsPerPx ：修改缩放比例~~

两者现在都已经支持默认缩放比例了，上面的设置可以修改全局的CSS字体大小，如果是笔记本的话会很好用

#### 触控板跟手

提高跟手程度只需要把动画时间和幅度变短就好。

像Chrome参数可以改为`200.0.20.80.8.50`；火狐打开`about:config`标签页找到`general.smoothScroll.mouseWheel.durationMaxMS
general.smoothScroll.mouseWheel.durationMinMS`这两个值，分别改为200和50即可。这个和Chrome参数前面的200和0相似.

更多的细节还在Firefox的开发源码[^1]中，这里不再涉及。

</br>

#### 搜索引擎

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

</br>

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
+ 捕捉网页截图 
+ Dark Reader
+ XDown
+ 购物党自动比价工具
+ pakku：哔哩哔哩弹幕过滤器
+ No Per-Script Font!
+ Font Rendering Enhancer
+ Set Character Encoding
+ Sourcegraph
+ Stylish-为任意网站自定义主题
+ GitZip for github
+ 安全外壳 (SSH)

### Typera

页边距：相关主题下的CSS里面搜索`write`找到`max-width`就是显示的页边距，自行调整

### Gmail & Outlook

众多邮箱手机客户端可以丝滑登录Google以及代收邮件，电脑端169收费。

> 据我们的技术说，gmail被屏蔽了，但是仍有一部分地址是漏网之鱼，可以通过这些地址来接收到墙外的邮件。因为只有少部分地址是可以用的，所以你们看现在号称能够接收gmail的客户端，大多都是手机的app，不开放电脑端是因为无法承受大流量的接入，会过载。

### Word To MD[^2]

+  在线工具：https://word2md.com/
   + 项目[源码](https://github.com/benbalter/word-to-markdown).
+ [Writage](http://www.writage.com/)插件

</br>

### VMware

#### 触控板滑动

两种解决方法：

+  朴实的做法，直接放弃滑动，改用上下左右控制界面也不是不可以，你说呢？
+  这个是属于强迫症的做法：改用管理员的模式运行来获取触控板的参数.

[Tip] : 一个有趣的现象就是 Ubuntu 默认触控板驱动不支持双指放大, 但是Win10 的触控板驱动的参数却可以传到 Vmare 中.  

<br>

#### 处理器数和进程数

根据自己电脑的配置进行选择，首先百科`i5-9300H`的一些参数：
1.  处理器频率介于2.4和4.1 GHz之间，并且由于超线程，可同时执行多达8个线程 。
2.  英特尔酷睿i5-9300H的性能与较旧的酷睿i7-7920HQ（3.1 – 4.1 GHz）相似 。
</br>

### 添加右键命令行[^3]

添加保存 ASKII 编码, 然后运行.

```shell
Windows Registry Editor Version 5.00

; 若原先有，先删除原来的
[-HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHere]
[-HKEY_CLASSES_ROOT\Directory\Background\shell\runas]
[-HKEY_CLASSES_ROOT\Directory\Background\shell\PowershellAdmin]
 
; 1.右键：命令行
[HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHere]
@="在此处打开命令行窗口"
 
[HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHere\command]
@="cmd.exe -noexit -command Set-Location -literalPath \"%V\"" 
 
; 2.右键：命令行（管理员）
[HKEY_CLASSES_ROOT\Directory\Background\shell\runas]
@="在此处打开命令行窗口(管理员)"
"ShowBasedOnVelocityId"=dword:00639bc8
 
[HKEY_CLASSES_ROOT\Directory\Background\shell\runas\command]
@="cmd.exe /s /k pushd \"%V\""
 
; 3.shift+右键：Powershell(管理员)
[HKEY_CLASSES_ROOT\Directory\Background\shell\PowershellAdmin]
@="在此处打开 Powershell 窗口(管理员)"
"Extended"=""
 
[HKEY_CLASSES_ROOT\Directory\Background\shell\PowershellAdmin\command]
@="\"C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe\" -windowstyle hidden -Command $stpath = pwd; Start-Process PowerShell -ArgumentList \\\"-NoExit\\\", \\\"-Command Set-Location -literalPath '%V'\\\" -verb RunAs"
 
; 4.设置右键 管理员打开cmd的另一种方法（可用来替换上面的2）
; 通过Powershell调起，会闪过一次Powershell的窗口，去掉下面几行的[; ]可以取消注释
; [-HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHereAdmin]
; 
; [HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHereAdmin]
; @="在此处打开命令行窗口(管理员)"
; 
; [HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHereAdmin\command]
; @="PowerShell -windowstyle hidden -Command \"Start-Process cmd.exe -ArgumentList '/s,/k, pushd,%V' -Verb Run
```
### ~~QQ delete Qzone~~

> 一个高明的方法是该文件采用了不同形式编码集合的方式保存的文件，如果对源文件编辑会破坏部分代码，会导致部分报错，仍然可以使用

**[Loc]：**Tencent -> QQ -> Plugin -> Com.Tencent.Qzone

**[Way]：**编辑 Bundle 的标签。

### Terimal

#### Powershell

+ > PowerShell 与 cmd 有什么不同？[^4]

> 窃以为 PowerShell 和 cmd 最大的不同，并且也是和其它 *nix Shell 最大的不同在于 PowerShell 的 pipe 传递的是 .net object，而不是 raw 字符串，于是这就打开了一扇神奇的大门，因为 PowerShell 的一切组件都可以和谐地共存，彼此不用互相猜忌，不用猜你喂给我的数据合不合法，也不用担心我喂给你的参数格式对不对。大家共享一个 CLR，拥有丰富的 metadata，自由自在地在 .net 的世界里徜徉和探索......

[More]:

1. 收集和分享 Windows PowerShell 相关教程,技术和最新动态: www.pstips.net
2. Chocolatey Packages Manager: www.chocolatey.org
3. https://www.zhihu.com/question/388789219/

#### 命令行全局快捷键设置[^5]

1. Win+R -> `comtrol`
2. 管理工具中加入想要添加应用的快捷方式, 然后右键属性设置全局快捷键.

打开的速度应该还是有比较大的延迟, 但是可以代替 Ubuntu 下的坏习惯.

## Optimization

CMD 下查看自己的序列号:

```powershell
(Get-WmiObject -query 'select * from SoftwareLicensingService').OA3xOriginalProductKey
```

### RAM[^6]

> **4G,8G 内存的 win10 64位系统,一般开机启动系统自身就会占用 1.5-2.5GB 内存, 16G 内存的则占用在 2.5G-3.5G ,且内存越大吃的越多,系统也越快,只有达到一定程度(比如128GB内存),系统才不会继续吃更多,而32位系统则占用的更少(理论上少一半,实际上由于各种优化存在,并不会如此).**

### 虚拟内存[^7]

虚拟内存不应该设置在C盘（即系统盘），这种说法其实是错误的，在C盘剩余空间充足的情况系下，由于系统盘是硬盘中读写系统文件、页面文件最频繁的一个盘，在这个操作中最耗时的就是磁头寻址定位，所以如果设置其他盘，跨分区定位的时间肯定要比设置在C盘本地的定位时间要更长，所以其实虚拟内存设置在C盘是执行最快、效率最高的。

另外虚拟内存并不是设置的越大越好，实际上随着64位系统的广泛使用以及大容量内存产品的普及，虚拟内存技术的作用正在逐渐降低，一般情况下，虚拟内存的大小设置按照系统推荐的数值即可，通常为2GB~4GB，设置的更大也用不到，反而浪费了存储空间。

最后要提到的是，虚拟内存通常设置在机械硬盘上，随着固态硬盘的普及，不少用户的系统盘都是固态硬盘，这种情况下就不推荐在系统盘上设置虚拟内存了，因为虚拟内存会大幅度的消耗硬盘使用寿命，而固态硬盘因为其写入寿命的原因，对此特别忌讳。

## Service

### RuntimeBroker

RuntimeBroker.exe进程Win8或者Win8.1系统中才会出现的进程，是一个重要的系统核心进程，是Win8或者Win8.1用来进行Metro App权限管理的一个进程。该程序正常情况下位于C:\Windows\System32目录下，大小一般为32.7KB。用来进行开始屏幕磁贴与桌面的后台交互，如果没有运行任何磁贴程序应用的话，可能不会出现的进程中。一般占用内存不会超过3M，如果系统出现该进程内存占用太高，应该是此贴应用没有彻底关闭(特别是Win8.1)。

### Diagnostic Policy Service
**[Reasult]：**任务管理的历史记录无法使用

### Microsoft Compatibility Telemetry[^8][^9]
**[loc]: **我的电脑 -> 管理计算机 -> Application组包—> 关闭

### Host process for setting synchronization
**[Affect]：**同步Win的电脑设置

### Window Update[^10][^11]
**[Reasult]：** Mirco的软件商店会无法获取应用。

**定期检查更新服务。**每次重启电脑或者超过两天没有关机时，打开“服务”，并检查“Windows Update”状态，确保它仍然是禁用的。虽然Windows Update服务不会经常重启，但偶尔会重新启动。

- 如果在“Windows Update”标题右侧看到“禁用”，那么Windows Update仍然是禁用的。
- 如果在“Windows Update”标题右侧看到除“禁用”以外的其他内容，再次禁用Windows Update。

**Win10家庭版 使用组策略：**
保存为 CMD 或 BAT 以管理员模式运行，无报错情况下 Win+R 键入 gpedit.msc 打开组策略管理。
```cmd
@echo off
pushd "%~dp0"
dir /b C:\Windows\servicing\Packages\Microsoft-Windows-GroupPolicy-ClientExtensions-Package~3*.mum >List.txt
dir /b C:\Windows\servicing\Packages\Microsoft-Windows-GroupPolicy-ClientTools-Package~3*.mum >>List.txt
for /f %%i in ('findstr /i . List.txt 2^>nul') do dism /online /norestart /add-package:"C:\Windows\servicing\Packages\%%i"
pause
```
### Host process for setting synchronization
**[Affect]：**Win10的系统设置同步选项，可在设置-> 账户 ->同步里选择关闭

### WMI Provider Host
**[Affect]：**某些应用调用这个服务，一般几秒的事，持续占后台就有问题了。

**[loc]：**参考网上的方法-知乎[^12]，个人不喜动防火墙（svhost），关闭了HP Audio Switch后，找到是由于小米互传这个软件占用后台 -> 更新 ，退出后发现即使运行也不用CPU了。

</br>

### Windows Modules Installer Worker
**[Affect]：**启用Windows更新和可选组件的安装。
禁用即可。

### Window恶意软件删除工具[^13]
**[Affect]：**Windows Update 提供的该工具版本每月会在您的计算机后台运行一次。 如果找到感染，该工具将在您下一次启动计算机时显示一份状态报告。 如果您想要每月运行此工具多次，可以运行此网页提供的版本或者使用恶意软件删除工具网站上的版本。


### HP System Info HSA Service
**[Affect]：**

### Xtuservice
**[Affect]：**处理器进行超频 降频操作的控制程序

### IP Helper
**[Affect]：**IPV6 -> IPV4

### SysinfoCap
**[Loc]**：HPSysInfoCap(HP System Info HSA Service)

**[Affect]：**获取系统的相关信息，推测是风扇的驱动之类

他会连带着下面的服务停止，我将他们设置了手动启动。

**[HPNetworkCap]** (HP Network HSA Service)、**[HPAppHelperCap]** (HP App Helper HSA Service)

其他HP(系统品牌)的服务还有：
```
HP Analytics service
HP CASL Framework Service
HP Comm Recovery
HP Omen HSA Service
```

### Software Reporter Tool[^14]
**[Loc] :** Cmd下：——对应版本号里的Software Reporter Tool！

```powershell
%localappdata%\Google\Chrome\User Data\SwReporter
```
**[方法]：**“高级” -> “禁用继承” -> "从此对象中删除所有继承的权限".保证没有用户组可以访问SwReporter文件夹并启动Software Reporter Tool了。


[More]:
+ Bluetooth Handsfree Service：没有蓝牙的用户可以关闭
+ Fax：计算机或网络上的可用传真资源发送和接收传真
+ Workstation：创建和维护到远程服务的客户端网络连接如果服务停止
+ Ssdp Discovery：启动家庭网络上的upnp设备自动发现具有upnp的设备还不多
+ Smart Card：管理计算机对智能卡的读取访问基本上用不上，没有安装UPS的用户可以禁用
+ Print Spooler：将文件加载到内存中以便稍后打印，如果没装打印机，可以禁止该服务
+ Application LayerGateway  Service：为Internet连接共享和Internet连接防火墙提供第三方协议插件的支持如果你没有启用Internet连接共享或Windows XP的内置防火墙，Windows必须禁止的10项服务。则可将其禁止
+ TCP/IP NetBIOS Helper：NetBIOS在Win 9X下就经常有人用它来进行攻击，然后将此数据写入日志或触发警报为了防止被远程计算机搜索数据，否则一定要禁止它
+ Performance Logs  Alerts：性能日志和警报根据预配置的计划参数从本地或远程计算机收集性能数据，然后将该数据写入日志或触发警报。如果停止此服务，将不收集性能信息。如果禁用此服务，则明确依赖它的所有服务将无法启动。
+ RemoteRegistry：使远程用户能修改此计算机上的注册表设置。如果此服务被终止，只有此计算机上的用户才能修改注册表。如果此服务被禁用，任何依赖它的服务将无法启动。
+ 组策略把windows defender关掉：随机高磁盘io 关掉自动维护，如果方便的话关掉自动更新，改成定时更新：随机出现高磁盘io superprefetch，这个服务*有可能*在开机时出现高磁盘io，罕见开机高内存占用，通常会在开机几分钟之后回到正常值 windows search，这个服务*有可能*随机出现高磁盘io
+ [解决win10系统CPU占用过高](https://blog.csdn.net/sky__god/article/details/77914698)



## 右键

http://m.cfan.com.cn/pcarticle/125490



*Windows 10默认的右键菜单不一定适合于所有的用户环境。PC上合适的，移动设备上不一定合适；此用户合适了，彼用户不一定合适。若要满足自己的需求，还需要给右键菜单做做“手术”。*



1. 让右键菜单收紧



Windows  10是一个设计为能够适应多种设备的通用操作系统。其中，为了方便小尺寸移动触摸设备的操作，在右键菜单设计方面进行了必要的改进，明显感觉上的变化就是菜单项目的间隔更大，视觉上也更为宽松。这样做的好处是触摸时不会因间隔太小而按错项目。但是，若将这样的设置搬到键鼠操控的PC或其他大屏显示设备上，反而显得不便于操作或浪费空间。因此，给Windows 10右键菜单“缩身”的想法便变得很自然。但是，Windows 10本身的图形界面没有提供这样的设置方法，只能通过修改注册表来完成“瘦身”。



点击系统任务栏左侧的小娜图标（或搜索框），输入regedit字串，这时列表上部会自动出现regedit运行命令链接，点击该链接启动注册表编辑器。



依次定位到“HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\FlightedFeatures”项，在右侧窗格新建DWORD（32位）值（图1）；然后将其命名为ImmersiveContextMenu，数值数据保持默认的“0”，点击“确定”（图2）。



退出注册表编辑器，重启文件资源管理器，从中查看右键菜单，或到桌面上右键查看，会发现右键菜单比原来紧凑了（图3  右侧为修改后效果）。由于给右键菜单“搜身”后，同样的屏幕区域可以容纳更多的项目，这对于那些安装了很多右键功能的用户来说，操作上就变得方便多了。因为原来右键菜单过长，可能需要通过上下滚动才能看清隐藏在屏幕下部或上部的项目，现在“减肥”之后就可以免去了上下滚动的时间浪费和难以把控的尴尬。



小提示：



注册表修改具有一定的风险，因此建议在修改前先备份注册表。在注册表编辑器中选择“计算机”分支，点击“文件→导出”命令，命名注册表备份文件（如“我的注册表备份”），导出范围选择“全部”，最后点击“保存”即可。若遇到问题需要恢复，只需执行“导入”命令即可。



1. 让右键菜单变短



以上提到由于右键菜单项目过多而造成操作时需要滚动才能定位的情况。这种情况通过以上“缩身”法来解决空间有限。我们转而可以采用删除不必要项的方法，让右键菜单的长度变短。可借用360安全卫士系统工具中的“右键管理”工具来完成。



启动360安全卫士领航版，点击主界面右下角的“更多”文字链接，在弹出窗口的“全部工具”列表中“系统工具”下，找到“右键管理”项点击添加（图4）。启动该工具后点击“开始扫描”按钮，软件会自动扫描当前可用的文件右键菜单、“发送到”右键菜单、IE浏览器右键菜单等项目。点击选择其中不再需要的项目，然后点击窗口右下角的“删除”按钮，即可达到让右键菜单变短的目的（图5）。



![image](https://cdn.nlark.com/yuque/0/2020/png/1114914/1592138226190-95fe767c-9661-44b4-ab8f-64feb470f098.png)



扩展阅读：



由于右键菜单在不同位置的项目均有所不同，而又不局限于如上介绍的3个位置，因此如果要修改其他部位的右键菜单项目，还可以借助于一款专用的右键菜单定制软件RightMenuMgr来实现。在该软件窗口中，给出更多类别的右键菜单项目，只需选择对相应的项目执行去留优化即可（图6）。



1. 深度控制右键菜单



有时我们对右键菜单的某些项目的优化具有不确定性，去掉的也许还会有用到的时候。若需要更加灵活和深入地控制右键菜单项目，可使用专用系统工具Glary Utilities来解决。在Glary  Utilities主界面中点击“高级工具”选项卡，单击“系统控制”分组下的“右键菜单”项（图7），启动右键菜单管理器。在“文件和文件夹”标签页下，右边一列为右键菜单项所在的类别，对照此列按需取消对左侧项目的复选框的选择，即可取消相应项目在右键菜单中的显示，达到为右键菜单“减负”的目的（图8）。如果要为“新建”或“发送到”右键菜单减负，分别选择这两个选项卡，然后用同样的方法操作即可。




[^1]:https://developer.mozilla.org/zh-CN/docs/Mozilla/Developer_guide/Source_Code/Downloading_Source_Archives
[^2]:https://www.zhihu.com/question/24170089
[^3]:https://blog.csdn.net/cxrsdn/article/details/84538767
[^4]:https://www.zhihu.com/question/22611859/answer/28897482
[^5]:https://www.jianshu.com/p/545e3f76eece
[^6]:https://www.zhihu.com/question/39716538/answer/883031599
[^7]:https://www.crucial.cn/learn-with-crucial/memory/how-to-set-up-virtual-memory
[^8]:https://windows10.pro/microsoft-compatibility-telemetry-appraiser/
[^9]:https://blog.csdn.net/qubernet/article/details/82952239?utm_medium=distribute.pc_relevant.none-task-blog-baidujs-2
[^10]:https://www.jianshu.com/p/4485107693ed
[^11]:https://juejin.im/post/5e1c964de51d451c8771c590
[^12]:https://www.zhihu.com/question/58459318
[^13]:http://www.win10jihuoma.com/archives/8207
[^14]:https://www.cnblogs.com/ShaYeBlog/p/10224349.html