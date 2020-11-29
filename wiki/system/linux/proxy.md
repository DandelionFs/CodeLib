### Git[^1] [^2] [^3]

Git SSH 提交分支的时候速度可以上2Mib/s，但是Clone的时候就奇慢无比……离谱

![http://i.dfslfh.cn/comper_github.png](/img/tool/comper_github.png)

```bash
git config --global https.proxy  http://127.0.0.1:1087
git config --global http.proxy  http://127.0.0.1:1087
git config --global http.https://github.com.proxy socks5://127.0.0.1:1080 # 只对 github.com
git config --global --unset http.https://github.com.proxy # 取消代理

#ss
git config --global http.proxy 'socks5://127.0.0.1:1087'
git config --global https.proxy 'socks5://127.0.0.1:1087'

git config --global  --get http.proxy
git config --global  --get https.proxy

git config --global --unset http.proxy
git config --global --unset https.proxy
```

#### 再次码云导入Github

无脑关联Github，然后导入自己的仓库，从Github下面直接Clone ; 速度你根本无法想象，工具人[码云](https://gitee.com)了解一下

![](http://i.dfslfh.cn/gitee.png)

#### 后记

在Clone一个300+M的项目的时候，出现了`git clone: error: RPC failed;The remote end hung up unexpectedlyfatal: The remote end hung up unexpectedly Everything up-to-dat`的错误，好像是因为curl的postBuffer 默认值较小的原因,配置下个这个值,就不会出现该错误了.

```nginx
git config http.postBuffer 524288000
```

### Yarn

```bash
yarn config list

yarn config set https-proxy http://127.0.0.1:1087
yarn config set proxy http://127.0.0.1:1087

yarn config delete proxy
yarn config delete https-proxy
```

### npm

```bash
npm config list

npm config set proxy  http://127.0.0.1:1087
npm config set https-proxy http://127.0.0.1:1087

npm config delete proxy
npm config delete https-proxy
```

linux 全局安装 Hexo 居然还需要 Sudo 是我没有想到的. 

```
npm WARN deprecated hexo-bunyan@2.0.0: Please see https://github.com/hexojs/hexo-bunyan/issues/17
/usr/local/bin/hexo -> /usr/local/lib/node_modules/hexo-cli/bin/hexo
npm WARN optional SKIPPING OPTIONAL DEPENDENCY: fsevents@~2.1.2 (node_modules/hexo-cli/node_modules/chokidar/node_modules/fsevents):
npm WARN notsup SKIPPING OPTIONAL DEPENDENCY: Unsupported platform for fsevents@2.1.3: wanted {"os":"darwin","arch":"any"} (current: {"os":"linux","arch":"x64"})
npm WARN optional SKIPPING OPTIONAL DEPENDENCY: good-listener@^1.2.2 (node_modules/hexo-cli/node_modules/clipboard/node_modules/good-listener):
npm WARN optional SKIPPING OPTIONAL DEPENDENCY: sha1-1TswzfkxPf+33JoNR3CWqm0UXFA= integrity checksum failed when using sha1: wanted sha1-1TswzfkxPf+33JoNR3CWqm0UXFA= but got sha512-QpGW37eDFd+i2NIhe/OPlzgIMD0NiPE3PJcN3Gh0FxgFp0zPr6i+7+9jhhsbXoAQRR8Ab08jR1Iyk+OmhzAhrg== sha1-aCdPuD7hUb1vycIqaN0bonlSivA=. (4759 bytes)

+ hexo-cli@3.1.0
added 78 packages from 322 contributors in 233.62s

```

### Bash

使用环境变量, `~/.bashrc` 的尾部:

#### HTTP

|  环境变量   | 描述                                                         | 值示例                                                       |
| :---------: | :----------------------------------------------------------- | :----------------------------------------------------------- |
| http_proxy  | 为http网站设置代理；                                         | 10.0.0.51:8080; <br />user:pass@10.0.0.10:8080 <br />socks4://10.0.0.51:1080<br /> socks5://192.168.1.1:1080 |
| https_proxy | 为https网站设置代理；                                        | 同上                                                         |
|  ftp_proxy  | 为ftp协议设置代理；                                          | socks5://192.168.1.1:1080                                    |
|  no_proxy   | 无需代理的主机或域名； 可以使用通配符； 多个时使用“,”号分隔； | \*.aiezu.com,10.\*.\*.\*,192.168.\*.\*, <br />\*.local,localhost,127.0.0.1 |

```bash
export http_proxy=10.0.0.52:8080 # 为http站点设置http代理（默认）

export http_proxy=socks://10.0.0.52:1080 # # 设置 socks 代理，自动识别socks版本
export http_proxy=socks4://10.0.0.52:1080 # 设置 socks4 代理
export http_proxy=socks5://10.0.0.52:1080 # 设置 socks5 代理

export http_proxy=user:pass@192.158.8.8:8080 #代理使用用户名密码认证
```

#### HTTPS

如果需要为https网站设置代理，设置*https_proxy*环境变量即可；设置方法完全与*http_proxy*环境变量相同：

```bash
# 任意使用一项
export https_proxy=10.0.0.52:8080
export https_proxy=user:pass@192.158.8.8:8080
export https_proxy=socks://10.0.0.52:1080
export https_proxy=socks4://10.0.0.52:1080
export https_proxy=socks5://10.0.0.52:1080

curl -I http://www.fackbook.com # 测试代理
```

### 基于 Electronjs[^4] 开发应用的通解

You could see that Doc[^5]: 

```
# Disable proxy
--no-proxy-server

# Manual proxy address
--proxy-server=<scheme>=<uri>[:<port>][;...] | <uri>[:<port>] | "direct://"

# Manual PAC address
--proxy-pac-url=<pac-file-url>

# Disable proxy per host
--proxy-bypass-list=(<trailing_domain>|<ip-address>)[:<port>][;...]
```
So you should execute follow command:
```
ao --proxy-pac-url=xxx
```
Nice!!!
<br>


## DNS-Hosts

主要的误点是 Hosts 写成了 Host, 然后没有发现, 然后就是漫长的 Google 过程, 过程不再赘述, 这里写下我收集到的资料.

+ Firefox, Chrome 浏览器是可以设置 浏览器代理的, 并且自身是拥有 DNS缓存服务的, Chrome在 `chrome://net-internals/` 里, 虽然在71版本后就看不到具体的Cache了, 但是清除还是有效的.
+ 在浏览器设置代理之后的优先级回大于本地, 以及部分网站会采用长连接的形式, 故表现为 开了代理 或 短时间快速(长连接时间之内)修改Hosts 就出现 Hosts 失效的问题; 然后因为隐私模式下不会复用 TCP 连接，新开连接的时候，会重新解析 DNS 域名，重启浏览器, 所有的连接（包括长连接）都会断开, 自然可以生效了; 
+ 重启网络服务
  ```bash
    service network restart
  ```

+ 在Ubuntu中，如果要刷新DNS缓存，则需要重新启动nscd守护程序。nscd使用以下命令进行安装. 使用以下命令在Ubuntu中刷新DNS缓存：
   ```bash
   sudo service nscd restart
   sudo service dns-clean start
   ```
+ 关于清理缓存报错 `Failed to start dns-clean.service: Unit dns-clean.service is masked.`

  > mask is a stronger version of disable. Using disable all symlinks of the specified unit file are removed. If using mask the units will be linked to /dev/null. This will be displayed if you check e.g. by systemctl status halt.service. The advantage of mask is to prevent any kind of activation, even manual.
  >
  > Caution: systemctl list-unit-files is listing the state of the unit files (static, enabled, disabled, masked, indirect) and has nothing to do with the state of the service. To have a look at the services use systemctl list-units

+ NSCD(name service cache daemon).

> nscd缓存三种服务passwd group hosts，所以它会记录三个库，分别对应源/etc/passwd, /etc/hosts 和 /etc/resolv.conf每个库保存两份缓存，一份是找到记录的，一份是没有找到记录的。每一种缓存都保存有生存时间（TTL）
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

service nscd stop # 停止nscd 服务
```





### Reference

[^1]:https://www.zhihu.com/question/27159393).
[^2]:https://www.v2ex.com/t/574303).
[^3]:https://blog.51cto.com/11887934/2051323)
[^4]:https://www.electronjs.org/
[^5]:https://code.visualstudio.com/docs/setup/network
