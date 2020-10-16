---
date: 2020-10-16 14:40:00
---

## Shortcut
### Win

|     Operation      |                      Effects                       |      Operation      |            Effects             |
| :----------------: | :------------------------------------------------: | :-----------------: | :----------------------------: |
|     Win+Ctrl+D     |                  创建虚拟Desktop                   |        Win+Q        |              搜索              |
|  Win + Ctrl + F4   |                  关闭虚拟Desktop                   |        Win+R        |             对话框             |
| Win + Ctrl + 左/右 |                左右切换虚拟Desktop                 |        Win+X        |   “Windows移动中心”设置面板    |
|       Win+F4       |                      关闭窗口                      |       Alt+F4        |            关闭窗口            |
|       win+m        |               最小化窗口（全部窗口）               |     alt+space+n     | 单个窗口最小化（配合Dock使用） |
|       ctrl+w       |            关闭浏览器当前页（我的电脑）            |   Windows+Shift+M   |     还原窗口最小化（全部）     |
|       ctrl+t       |                    打开新标签页                    |   ctrl+alt+delete   |         打开任务管理器         |
|    ctrl+shift+t    |                恢复关闭的浏览器页面                |      alt+enter      |        查看选中文件属性        |
|      ctrl + +      |                      放大页面                      |        win+E        |         打开资源管理器         |
|       ctrl+-       |                      缩小页面                      | alt+前进/后退方向键 |       浏览器页面后退前进       |
|         F1         |         显示当前程序或者windows的帮助内容          |         F2          |  如果选中文件的话，进行重命名  |
|         F3         |                        查找                        |         F5          |         浏览器页面刷新         |
|         F6         | 使用浏览器时，地址栏获得焦点（即光标移到了地址栏） |         F11         |           浏览器全屏           |
|        F12         |              浏览器审查元素/调试界面               |        prtsc        |              截屏              |
|       win+t        |                   循环切换任务栏                   |        alt+d        |        焦点固定到地址栏        |
| Alt+Shief+Num Lock |                   用键盘控制鼠标                   |                     |                                |

</br>

### Typera&Markdown

|     Operation      |              Effections              |
| :----------------: | :----------------------------------: |
|       Ctrl+/       |         代码和预览的快速切换         |
|   shift + enter    |                软换行                |
|       enter        |                硬换段                |
|      Ctrl + /      |            调出源代码格式            |
|      Ctrl + K      |     将选中词变为剪切板的网页索引     |
| Ctrl + Shief + 1/2 | 关闭/隐藏侧边任务栏（源码模式无效）  |
| Ctrl + Shief + 1/2 | 大纲和文件的互相切换（源码模式无效） |
|         F8         |               专注模式               |
|         F9         |               翻译模式               |
|        F11         |               全屏模式               |

</br>

### Youdao&Markdown
有道云笔记：

|       Operation        |      Effects       |  Operation   |     Effects      |
| :--------------------: | :----------------: | :----------: | :--------------: |
|         ctrl+←         |  切换界面模块隐藏  |    ctrl+→    |       显示       |
|         ctrl+n         |      新建笔记      | ctrl+shfit+y |     激活窗口     |
| ctrl+shfit+PrintScreen | 隐藏窗口的截屏方式 |      F5      |       同步       |
|         ctrl+d         |    插入待办事项    | shift+alt+d  |   插入当前时间   |
|    ctrl+数字（1-4）    |    修改字体大小    |    ctrl+h    |    插入分割线    |
|         ctrl+w         |    关闭当前页面    |    ctrl+L    | 当前行成无序列表 |
|      ctrl+shift+L      |  当前行成有序列表  |    ctrl+y    |   返回撤销操作   |

从这里大概更新一下自己不太熟悉的Markdown语法（复杂的见后记）：

| Operation  |       Effects        | Operation | Effects  |
| :--------: | :------------------: | :-------: | :------: |
| $$E=mc^2$$ | 质能守恒公式[^LaTeX] |   - [ ]   | 待办事宜 |


## Optimization

CMD 下查看自己的序列号:

```powershell
(Get-WmiObject -query 'select * from SoftwareLicensingService').OA3xOriginalProductKey
```

### RAM
**[LINK]**
- https://www.zhihu.com/question/39716538/answer/883031599

> **4G,8G 内存的 win10 64位系统,一般开机启动系统自身就会占用 1.5-2.5GB 内存, 16G 内存的则占用在 2.5G-3.5G ,且内存越大吃的越多,系统也越快,只有达到一定程度(比如128GB内存),系统才不会继续吃更多,而32位系统则占用的更少(理论上少一半,实际上由于各种优化存在,并不会如此).**

### 虚拟内存[^7]
**[LINK]**
- https://www.crucial.cn/learn-with-crucial/memory/how-to-set-up-virtual-memory

虚拟内存不应该设置在C盘（即系统盘），这种说法其实是错误的，在C盘剩余空间充足的情况系下，由于系统盘是硬盘中读写系统文件、页面文件最频繁的一个盘，在这个操作中最耗时的就是磁头寻址定位，所以如果设置其他盘，跨分区定位的时间肯定要比设置在C盘本地的定位时间要更长，所以其实虚拟内存设置在C盘是执行最快、效率最高的。

另外虚拟内存并不是设置的越大越好，实际上随着64位系统的广泛使用以及大容量内存产品的普及，虚拟内存技术的作用正在逐渐降低，一般情况下，虚拟内存的大小设置按照系统推荐的数值即可，通常为2GB~4GB，设置的更大也用不到，反而浪费了存储空间。

最后要提到的是，虚拟内存通常设置在机械硬盘上，随着固态硬盘的普及，不少用户的系统盘都是固态硬盘，这种情况下就不推荐在系统盘上设置虚拟内存了，因为虚拟内存会大幅度的消耗硬盘使用寿命，而固态硬盘因为其写入寿命的原因，对此特别忌讳。

## Service
### RuntimeBroker

RuntimeBroker.exe进程Win8或者Win8.1系统中才会出现的进程，是一个重要的系统核心进程，是Win8或者Win8.1用来进行Metro App权限管理的一个进程。该程序正常情况下位于C:\Windows\System32目录下，大小一般为32.7KB。用来进行开始屏幕磁贴与桌面的后台交互，如果没有运行任何磁贴程序应用的话，可能不会出现的进程中。一般占用内存不会超过3M，如果系统出现该进程内存占用太高，应该是此贴应用没有彻底关闭(特别是Win8.1)。

### Diagnostic Policy Service
**[Reasult]：**任务管理的历史记录无法使用

### Microsoft Compatibility Telemetry
**[LINK]**
- https://windows10.pro/microsoft-compatibility-telemetry-appraiser/
- https://blog.csdn.net/qubernet/article/details/82952239

**[loc]: **我的电脑 -> 管理计算机 -> Application组包—> 关闭

### Host process for setting synchronization
**[Affect]：**同步Win的电脑设置

### Window Update
**[LINK]**
- https://www.jianshu.com/p/4485107693ed
- https://juejin.im/post/5e1c964de51d451c8771c590

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

**[loc]：**[参考网上的方法-知乎](https://www.zhihu.com/question/58459318)，个人不喜动防火墙（svhost），关闭了HP Audio Switch后，找到是由于小米互传这个软件占用后台 -> 更新 ，退出后发现即使运行也不用CPU了。

### Windows Modules Installer Worker
**[Affect]：**启用Windows更新和可选组件的安装。

禁用即可。

### Window恶意软件删除工具
**[LINK]**
- http://www.win10jihuoma.com/archives/8207
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

### Software Reporter Tool
**[LINK]** https://www.cnblogs.com/ShaYeBlog/p/10224349.html 

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


### 添加右键命令行
**[LINK]** https://blog.csdn.net/cxrsdn/article/details/84538767

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

- **让右键菜单收紧**: 修改注册表
  - Windows 10适应多种设备 -> 小尺寸移动触摸设备 + PC或其他大屏显示设备
  - 定位到`HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\FlightedFeatures`项，在右侧窗格新建DWORD（32位）值; 然后将其命名为`ImmersiveContextMenu`，数值数据保持默认的`0`，点击“确定”。退出注册表编辑器，重启文件资源管理器，从中查看右键菜单，或到桌面上右键查看，会发现右键菜单比原来紧凑了.
  - **注册表修改具有一定的风险，因此建议在修改前先备份注册表**。
- 由于右键菜单在不同位置的项目均有所不同，而又不局限于如上介绍的3个位置，因此如果要修改其他部位的右键菜单项目，还可以借助于一款专用的右键菜单定制软件RightMenuMgr来实现。在该软件窗口中，给出更多类别的右键菜单项目，只需选择对相应的项目执行去留优化即可。(Glary  Utilities)
