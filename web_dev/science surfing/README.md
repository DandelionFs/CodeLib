# Science Surfing

**THX FOR:**
- [Link](https://10101.io/2019/10/27/internet-provider)
- https://teddysun.com
- https://doub.io
- https://www.oldking.net
- https://github.com/tcp-nanqinlang
- https://v2ray666.com

**机场:**
+ [CCCAT](//cccat.io)
+ [召唤师](//zhs.today/auth/register?code=ILoveMask)
+ [蓝岸](//my.v2fly.club/#/register?code=1bzRvUqk)
   - 2020-04-23  最近蓝岸被“脱裤”，大家注意风险；
+  [极游](//jiyou.world)
   - 2020-05-18  最近缺少维护，可用性低，据说机场主忙于高考，购买需谨慎；
+ [Catchflying](//catchflying.network/auth/register?code=5ATO)
+ [咸鱼](salty-tuna.link)
+ NFNF: 见Twitter
+ [YTOO](//ytoo.li/clientarea.php)
+ [魅影](//maying.co)

**策略组、规则:**
- 在线Subconverter订阅转换(仅供参考，安全自负)
  - https://acl4ssr-sub.github.io/
  - https://subcon.py6.pw/
  - https://sub.weleven11.com/
  - https://id9.cc/
  - https://subcon.dlj.tf/
  - https://sub-web.wcc.best/
  - https://api.nameless13.com/
  - https://agwa.page/
  - https://acl4ssr.netlify.app/
  - [神机规则](https://github.com/ConnersHua/Profiles/blob/master/Clash/Pro.yaml)
  - Fndroid 大佬的[关于策略组的理解](https://github.com/Fndroid/jsbox_script/wiki/关于策略组的理解)
  - [LINK](https://github.com/tindy2013/subconverter/blob/master/README-cn.md)

**VPS脚本:**
+ VPS综合性能测试脚本
  + [Bench.sh](//teddysun.com/444.html)
    ```bash
    wget -qO- bench.sh | bash
    # https://github.com/oooldking/script/blob/master/superbench.sh
    ```
  + [SuperBench.sh](//www.oldking.net/350.html)
    ```bash
    wget -qO- --no-check-certificate https://raw.githubusercontent.com/oooldking/script/master/superbench.sh | bash
    ```
  + [UnixBench.sh](//teddysun.com/245.html)
    ```bash
    wget --no-check-certificate https://github.com/teddysun/across/raw/master/unixbench.sh
    chmod +x unixbench.sh
    ./unixbench.sh
    ```
  + [LemonBench](//blog.ilemonrain.com/linux/LemonBench.html)
    ```bash
    curl -fsL https://ilemonra.in/LemonBenchIntl | bash -s fast # 快速测试
    curl -fsL https://ilemonra.in/LemonBenchIntl | bash -s full # 完整测试
    ```
+ VPS网络测试脚本
  + [speedtest-cli](//raw.githubusercontent.com/sivel/speedtest-cli/master/speedtest.py)
    ```bash
    wget -O speedtest-cli https://raw.githubusercontent.com/sivel/speedtest-cli/master/speedtest.py
    chmod +x speedtest-cli
    mv speedtest-cli /usr/bin/
    # speedtest-cli
    #`peedtest-cli --bytes 以字节计算的方式来测试
    # speedtest-cli --share 生成图片分享
    # speedtest-cli --simple 只显示ping和上下行速度
     # speedtest-cli --help 显示可用命令
    ```
  + [Superspeed](//github.com/ernisn/superspeed)
    ```bash
    bash <(curl -Lso- https://git.io/superspeed)
    ```
  + [MTR](https://zhuanlan.zhihu.com/p/30591816)
    ```bash
    apt install mtr-tiny
    mtr -rw ip # `ip` 自己替换成本地地址；参数设定可以通过`mtr -h` 查看；
    ```
+ 梯子搭建脚本
  + [Shadowsocks](https://teddysun.com/486.html)
  + [ShadowsocksR](//doub.io/ss-jc42)
  + [V2Ray](//v2ray666.com/post/1/)
+ 梯子优化脚本
  + Debain 9+ 开启 BBR 等
  ```bash
  echo "vm.swappiness = 10" >> /etc/sysctl.conf
  echo "net.core.default_qdisc = fq" >> /etc/sysctl.conf
  echo "net.ipv4.tcp_congestion_control = bbr" >> /etc/sysctl.conf
  echo "net.ipv4.tcp_fastopen = 3" >> /etc/sysctl.conf
  sed -i '$a root hard nofile 1024000\nroot soft nofile 1024000' /etc/security/limits.conf
  sed -i '$a * hard nofile 1024000\n* soft nofile 1024000' /etc/security/limits.conf
  ulimit -n 1024000
  sysctl -p
  ```
  + [BBR脚本](https://doub.io/wlzy-16/)
  ```bash
  wget -N --no-check-certificate https://raw.githubusercontent.com/ToyoDAdoubi/doubi/master/bbr.sh && chmod +x bbr.sh && bash bbr.sh

  # 备用地址
  wget -N --no-check-certificate https://raw.githubusercontent.com/WithdewHua/doubi/master/bbr.sh && chmod +x bbr.sh && bash bbr.sh
  ```
  +  [暴力BBR脚本](https://www.moerats.com/archives/523/)
  ```bash
  wget https://raw.githubusercontent.com/iiiiiii1/tcp_nanqinlang-test/master/tcp_nanqinlang-test.sh
  bash tcp_nanqinlang-test.sh
  ```


## NOUN & PROBLEMS
### NOUN
- IPLC: IPLC是国际线路 ( International Private Leased Circuit )，即国际私有租赁线路.延迟低&速度快 专线延迟可低至25ms, 甚至低于日本CN2线路不用担心IP不可用: 真正意义上的IPLC是完全内网通讯, 流量不像普通VPS经过某些审查; 三大运营商是付费网间结算，暂时没有免费对等互联。要中继的原因一部分是三大国际出口网络质量不一样，一部分是小运营商几乎没啥国际出口，所以要借助其他表现好的。
- 中继节点: 中继分公网中继/专线传输。公网就是还走三大统一出国，专线是国内国外两头内网传输。用户——中继入口服务器——中继服务器2——中继服务器N——落地服务器——用户访问的网站用户直接通过代理协议（ss、v2等），通过公网与中继入口服务器进行通讯。一般情况下中继入口是放在国内的，中继的入口到落地之间穿越防火墙的这一段一般会使用一些隧道协议，以实现负载均衡、高可用、防止被墙等效果。当然也有一些用单纯的端口转发过墙传输数据的，这种情况比较容易被墙。中继入口也有可能会通过IPLC/IEPL等专线出国，这种情况下连只需进行端口转发也不会被墙。
- 隧道
- 透明代理: 
- 代理的不同平台:
  - armv6、armv7、armv7s、armv8、armv64 : 简而言之 armv8 == arm64/aarch64 是我自己手机使用的型号.
  - i386	x86_64	i386|x86_64	是电脑的型号.
  - 详见: https://blog.csdn.net/tony_vip/article/details/105889734
  - https://blog.csdn.net/u012505617/article/details/89205642
  - https://www.zhihu.com/question/63627218

## PROTOCOLS

代理协议.

### SS
**[LINK]**
1. https://233v2.com/
2. https://vpsland.xyz/

+ [Shadowsocks脚本](https://teddysun.com/486.html)

```bash
wget --no-check-certificate -O shadowsocks-all.sh https://raw.githubusercontent.com/teddysun/shadowsocks_install/master/shadowsocks-all.sh
chmod +x shadowsocks-all.sh
./shadowsocks-all.sh 2>&1 | tee shadowsocks-all.log
#管理脚本：/etc/init.d/shadowsocks-libev start | stop | restart | status
# 配置文件：/etc/shadowsocks-libev/config.json
```

[纪念酸酸乳大佬](https://printempw.github.io/about-clowwindy-archive/) [@clowwindy](https://github.com/shadowsocks/shadowsocks-iOS/issues/124)

> Two days ago the police came to me and wanted me to stop working on  this. Today they asked me to delete all the code from GitHub. I have no  choice but to obey.
>
> I hope one day I’ll live in a country where I have freedom to write any code I like without fearing.
>
> I believe you guys will make great stuff with Network Extensions.



### SSR

+ [ShadowsocksR脚本](https://doub.io/ss-jc42/)

以teddysun的一键安装为例，如果遇到安装失败或安装后无法正常使用的情况，可以尝试另一个版本：逗比SSR一键安装脚本

服务器系统：CentOS6及以上、Debian7及以上、Ubuntu12及以上系统内存支持128M及以上，推荐256M起步。

```bash
wget --no-check-certificate -O shadowsocks-all.sh https://raw.githubusercontent.com/teddysun/shadowsocks_install/master/shadowsocks-all.shchmod +x shadowsocks-all.sh
./shadowsocks-all.sh 2>&1 | tee shadowsocks-all.log
# CentOS
yum -y install wget
apt -y install wget
```

选择SSR安装 -> 输入自定义密码后按回车，建议不要使用默认密码 -> 加密方式，如果选择chacha20的话，就输入对应序号12 -> 选择协议，建议选择自auth aes128md5 ->选择混淆方式 -> reboot
```bash
/etc/init.d/shadowsocks-r start #启动Rss
/etc/init.d/shadowsocks-r stop#退出Rss
/etc/init.d/shadowsocks-r restart #重启RSs：
/etc/init.d/shadowsocks-r status # Rss状态：
./shadowsocks-all.sh uninstall # 卸载RSS：
```
SSR的相关配置文件位置在：/etc/shadowsocks-r/config.json

+ 第二种方法
```bash
wget -N --no-check-certificate https://softs.wtf/Bash/ssr.sh && chmod +x ssr.sh && bash ssr.sh
# 备用地址
wget -N --no-check-certificate https://raw.githubusercontent.com/WithdewHua/doubi/master/ssr.sh && chmod +x ssr.sh && bash ssr.sh
#运行脚本：bash ssr.sh
#管理脚本：/etc/init.d/ssr start| stop | restart | status
#配置文件：/etc/shadowsocksr/user-config.json
```

### V2ray

+ [V2Ray脚本](https://v2ray666.com/post/1/)
+ [V2ray软件](https://github.com/vkuajing/v2ray)

1. 避免VPS没装Curl，保险起见运行一下 Curl的安装命令, 两种系统下随便用一个命令就可以。
2. 命令` bash <(curl -s -L https://git.io/v2ray.sh)
3. 一路Enter, 打开V2ray 软件:  添加 Vmess 服务器,  复制刚才复制的代码 Vmess地址,  我把这个共享在 Free SS 资源  有需要的直接拿来用，也可以用来测试下速度,  从剪切板导入URL ； 点确定,  回到V2ray 主界面，这里多了一个 新的服务器,  参数设置 2333,  点确定,  和 SS类似，右键点图标启用即可，有风险提示，就点允许,  连接完成

```bash
bash <(curl -s -L https://v2ray666.com/v2ray.sh)
#运行脚本
V2Ray
# 管理脚本
v2ray info# 查看V2Ray配置信息
v2ray config #修改V2Ray配置
v2ray link#生成V2Ray配置文件链接
vzray infolink#生成V2Ray配置信息链接
v2ray qr#生成V2Ray配置二维码链接
v2ray ss#修改Shadowsocks配置
v2ray ssinfo#查看Shadowsocks配置信息
vzray ssqr#生成Shadowsocks配置二维码链接
vzray status #查着V2Ray运行状态
v2ray start#启动V2Ray
v2ray stop#停止V2Ray
v2ray restart#重启V2Ray
v2ray log#查看V2Ray运行日志
v2ray update#更新V2Ray
v2ray update.sh#更新V2Ray管理脚本
v2ray uninstall#卸载V2Ray
#配置文件：/etc/v2ray/config.json
```

## [CLASH](https://docs.cfw.lbyczf.com/)

> 一款用`Go`开发的支持多平台的代理工具，支持`ss`/`v2ray`/`snell`（不支持`ssr`），支持规则分流（类似于 Surge 的配置）。
+ Clash: https://github.com/Dreamacro/clash
+ ClashX For Mac: https://github.com/yichengchen/clashX/
+ [Clash For Windows](https://github.com/Fndroid/clash_for_windows_pkg) By [Fndroid](https://github.com/Fndroid)
+ Clash For Android
+ Clash For Magisk

- 下载替代Github镜像
  - https://tmpclashpremiumbindary.cf/
- MMDB 维护
  - https://github.com/alecthw/mmdb_china_ip_list

### PROBLEMS
- UWP 回环代理.
  

### CLASH FOR ANDROID/MAGISK/LINUX

- [CFG](https://github.com/Kr328/ClashForMagisk)
- [CPFG](https://github.com/kalasutra/Clash_Premium_For_Magisk)

总结一下 *INX 的问题:
- 配置文件有问题
  - 变量的大小写问题
  - 变量的端口的有无
  - 映射端口是否对应
  - 值得吐槽的是`Win`&`Linux`的文件在机场主是区别对待的, 或者说对使用者的门槛更高.
- 命令行`./clash -d .` 和`./clash` 的效果不一致.
- 开了系统代理但是没有打开`Clash`
- 开了`Clash`没有开启系统代理
- 套餐过期
- 场主起飞
......

日常的检修记录如下:

1. 关闭系统代理端口转发后打开`clash.razord.top/#/settings`.
2. 执行Clash, 发现此页面会刷新. 表示 Clash 的外部映射端口几次场子的配置问题没有问题. 
3. 选择节点, 开启代理, 进行测试.

## Internet

- Telegram
  - [shuziyimin](https://github.com/bates33/shuziyimin)
