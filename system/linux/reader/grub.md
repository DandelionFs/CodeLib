## Grub

https://www.phodal.com/blog/cray-boot-method-linux-windows-mac-os-install-experience/

linux下的引导方式就比较多了，从早期的lilo、grub到grub2、burg等等，以及Livecd的isolinux，及习惯了的syslinux。mac os x（x86)，可以有darwin、chameleon等等。win上面的话就是bootmgr及ntldr了。

先从win上的引导方式说起，win上就是群雄逐鹿的地方了，当然这只是表面的，实际情况是Microsoft占领了主要市场从而使得各个系统的引导方式不得不寄生与win，因而win上几乎可以引导多数的操作系统。win的黑白引导管理除了难看还是难看，bootmgr的话，就是多数操作系统寄生之地了。首先先从古老的grub说起，从xp时代开始装GNU/Linux系统说起，早期的GNU/Linux就是从GRLDR引导开始的。反正我记忆里是那样的，DOS时代我就不是很了解了。虽然是那个时代走过来的人，但是印象不是很深。DOS我记得的命令基本上没有了，软件倒是有几个——LOGO、UCDOS。小学嘛，学的东西就只有这些了，原归正转。说说早期用GRLDR引导GNU/Linux的经历了。

因为之前对这个不是很了解，有点片面吧。而且初学的时候，装的系统是GHOST版的，是那种自带有GRLDR和menu.lst的版本的。于是我们先要改的就是boot.ini文件了，XP上可以依托的地方了。

```shell
[boot loader]
timeout=1
default=C:\grldr
[operating systems]
C:\grldr=Ubuntu 10.04
multi(0)disk(0)rdisk(0)partition(1)\WINDOWS="Microsoft Windows XP " /noexecute=optin /fastdetect
```

早期装的是红旗Linux，所以就……。因为那时间UBUNTU好像中文支持还不算很好，不过红旗感觉算是还行。至少在虚拟机安装是如此的，也实践起来差不多是一样的。然后再修改一下menu.lst就差不多了。解压到一个目录应该就差不多了，印象不是很深了。反正，后来有了钱就买了个U盘。所以，对于这个方法就基本上没再经历过了。
```shell
title Ubuntu
kernel(hd0,0)/vmlinuz
initrd(hd0,0)/initrd.img
```

这个差不多是这样没错的。至于menu.lst再回XP上就是这样的

```shell
title [06] 启动Windows 2000/XP/2003
find --set-root /ntldr
chainloader /ntldr
title [07] 启动Windows Vista/2008/Win7
find --set-root /bootmgr
chainloader /bootmgr
```

这个是从我的U盘上截取下来的片断，也就是返回引导的方法，WIN7上也是一样的。
 
然后，随后就是用光盘安装Ubuntu了，早期的时候Ubuntu还会从国内寄过来光盘，因为我还不是里面的开发者。然后送了几次，也收了几次光盘，反正是免费的嘛。不过，感觉就是爽多了。Ubuntu  Linux用的是isolinux就那个时候吧，不过光盘安装就是比较简单，不过，已经没那个功夫玩那个了。反正，蜀国也就这点能耐，有着很多的技术，但是打不赢天下的。不过，那个是用于光盘的，至于U盘的话，用的是syslinux，我很满意的一种方法，很环保，很安全。因为习惯用Puppy Linux了，所以也就没有领悟上syslinux是怎么安装的，不过总的来说是ldlinux.sys+syslinux.cfg。

syslinux算是比较自由和开放的，可以使用PNG格式的图片，这个比grub2dos好多了，

早期的话，我记得这个就相对比较麻烦了，得使用16位的图片好像，显示的质量相对是相当的糟糕。

 ```shell
 splashimage=(hd0,*)/grub/mm.xpm.gz
 ```
 

后期的话grub可以怎么做。

 ```shelll
 gfxmenu /BOOT/message
 ```

不过感觉没有多大区别，不如syslinux爽。
```shell
MENU BACKGROUND /boot/slax.png
```

多干净多利落啊。一个syslinux的示例：
```shell
PROMPT 0
TIMEOUT 90
DEFAULT /boot/vesamenu.c32
MENU BACKGROUND /boot/slax.png

MENU TITLE 
MENU WIDTH 22
MENU MARGIN 1
MENU ROWS 20
MENU HELPMSGROW 23
MENU TIMEOUTROW 24
MENU TABMSGROW 24
MENU CMDLINEROW 1
MENU HSHIFT 18
MENU VSHIFT 2
MENU AUTOBOOT
 
MENU color border           10;10      #00000000 #00000000 none
MENU color title            1;36;44    #FFFFFFFF #00000000 none
MENU color sel              30;37      #FF00FF00 #00000000 none
MENU color unsel            37;44      #FFFFFFFF #00000000 none
MENU color help             37;40      #FFFFFFFF #00000000 none
MENU color cmdline          37;40      #FFFF0000 #00000000 none
MENU color msg07            37;40      #FFFFFF00 #00000000 none
MENU color timeout          37;40      #FFFF0000 #00000000 none
MENU color timeout_msg      37;40      #FFFFFF00 #00000000 none  
MENU color hotkey           1;37;44    #ffffff00 #00000000 none
MENU color hotsel           1;7;37;40  #FF00FF00 #00000000 none


MENU LABEL [^P] Puppy Linux
MENU DEFAULT
kernel /puppy/VMLINUZ
initrd /puppy/INITRD.LZ

MENU LABEL [^G] GRUB
kernel /BOOT/GRLDR.BIN
```

因为是来自于slax的所以，基本上也就没改多少了。第一个是启动puppy Linux的，按P可以直接选择这个，G也一样是选择GRLDR的多干净利落。也就是syslinux令人愉快的地方了。而且同grub一样可以设置下一个目录。
 ```shell
 LABEL Phodal
MENU LABEL [^p] Phodal
config /BOOT/phodal.CFG
```

img文件的使用方法：
```shell
 LABEL ghost
MENU LABEL [^1] Ghost
kernel /BOOT/SYSLINUX/MEMDISK
append initrd=/BOOT/IMGS/GHOST.IMG
```
这也是我后来觉得很爽的syslinux了，不过这个还是没有比得上后来的 burg.

 

让我们看看burg的启动示例。
 ```shell
 menuentry " Linux Mint 12"  --class linuxmint {
        insmod ntfs
	search --set -f /linuxmint-12-gnome-dvd-32bit.iso
        loopback loop ($root)/linuxmint-12-gnome-dvd-32bit.iso
        linux (loop)/casper/vmlinuz boot=casper iso-scan/filename=/linuxmint-12-gnome-dvd-32bit.iso locale=zh_CN.UTF-8 noprompt noeject splash
        initrd (loop)/casper/initrd.lz
}
```

不过这个是比较麻烦了啦，没有那个syslinux来得简单和利落。
```shell
menuentry "Windows" --class windows {
  if search -s -f /bootmgr ; then
    ntldr /bootmgr
  else
    search -s -f /ntldr
    ntldr /ntldr
  fi
}
```

这是来自选windows的，不过，整体上burg.cfg算是比较难配置的，不过要是使用linux习惯了也行了。

```shell
 set theme_name=ubuntu
set gfxmode=800x600
if [ -s $prefix/burgenv ]; then
  load_env
fi
set default="0"
if [ ${prev_saved_entry} ]; then
  set saved_entry=${prev_saved_entry}
  save_env saved_entry
  set prev_saved_entry=
  save_env prev_saved_entry
  set boot_once=true
fi

function savedefault {
  if [ -z ${boot_once} ]; then
    saved_entry=${chosen}
    save_env saved_entry
  fi
}
function select_menu {
  if menu_popup -t template_popup theme_menu ; then
    free_config template_popup template_subitem menu class screen
    load_config ${prefix}/themes/${theme_name}/theme ${prefix}/themes/custom/theme_${theme_name}
    save_env theme_name
    menu_refresh
  fi
}
function toggle_fold {
  if test -z $theme_fold ; then
    set theme_fold=1
  else
    set theme_fold=
  fi
  save_env theme_fold
  menu_refresh
}
function select_resolution {
  if menu_popup -t template_popup resolution_menu ; then
    menu_reload_mode
    save_env gfxmode
  fi
}
```

不过加载模块什么的也比较自由了，而且可以启动吴国了，所以呢。Mac很犀利，不过，好像没有配置文件的，因为装的是黑苹果，所以原先的那个什么什么也就用不了。可是呢，是用变色龙安装到U盘上的。就没有解决这个问题了。

 
