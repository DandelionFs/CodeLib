## Preface

200125从虚拟机折腾, 一直到失联，在200323花了一下午入手双系统，对虚拟机say bye，入手Ubuntu……

某天了解到官网曾经可以申请免费的Ubuntu光盘，很有趣, 应该已经绝版了，指导点[我](https://wiki.ubuntu.org.cn/%E7%94%B3%E8%AF%B7Ubuntu%E5%85%8D%E8%B4%B9%E5%85%89%E7%9B%98%E7%9A%84%E5%85%A8%E7%A8%8B%E6%8C%87%E5%AF%BC)，写在前面留个纪念。（选择版本 -> 填写表格 -> 发出申请 -> 申请接受 -> 收到CD）在安装前请一定看一看Ubuntu官网的[Wiki](https://wiki.ubuntu.org.cn/%E5%AE%89%E8%A3%85_Linux_%E5%BA%94%E7%9F%A5%E7%9A%84%E5%8D%81%E4%BB%B6%E4%BA%8B).大致如下: 

![](./img/Ubuntu.png)

**声明**：这个**教程针对UEFI+GPT的Win10电脑, 或者说本教程用的格式化Ubuntu Ext2 分区就是采用此格式.** **所有命令都有最简模式, 目的是图我自己重装系统的时候方便, 嘻嘻**

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


## Ubuntu Touchpad
[LINK] : https://www.thefanclub.co.za/how-to/ubuntu-touchpad-gestures-install

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

## Links
1. 配合翻译来看(日语): https://sicklylife.jp/ubuntu/2004/settings.html
2. 没事点一下: http://u.nu/ubuntu

<center>基于<b>wiki.ubuntu.org.cn</b></center>

在用完 Win 后有感, 在没有深入了解人类设计的技术前，永远不要过分相信他，就像是你的电脑，在你真正摸清楚他的操作原理和操作逻辑之前，不要过分依赖他，在他面前，你可能就是赤裸的，所以人生啊，多学习一点东西，可能看书会吸收的很慢，但是幸好他永远是没有上限的，如果有瓶颈，突破它就好了，我所真正担心的是我没有足够的时间和精力去见证世间的一切，害怕的是自己不能静下心来慢慢的学习起来，对那些Fest Learner肃然起敬，但同时我始终都不了解真正的自己，永远在以伤害自己的方式来逼迫自己努力，而不是全身心的投入到自己的学习生涯中，这又是多么的可悲，而有的人意识不到这点，何等的讽刺……