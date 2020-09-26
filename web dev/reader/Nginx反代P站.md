# [Pixiv] Nginx 真·反代P站

神代綺凜-https://moe.best/technology/pixiv-proxy.html#%E5%89%8D%E8%A8%80

解决了一年前的我无法解决的世纪难题（x

深刻意识到，很多以前自己认为无解的问题并不是真的无解，只是自己的知识面不够而无法意识到问题的核心所在罢了。

总结起来就一个字：菜

Head Pic: [「Halloween」/「鳥成」のイラスト [pixiv\]](https://www.pixiv.net/member_illust.php?mode=medium&illust_id=71361930)

## 前言

**本文所述的所有内容仅供学习参考，请勿实际做出任何违反国家法律的行为！**

此方案为真的反代，而不是在本地反代以绕过 SNI 审查的方法（[Mashiro - PIXIV网页版及客户端访问恢复指南](https://2heng.xin/2017/09/19/pixiv/)）

这两种方法都各有利弊

在本地反代无需任何成本，你需要配置 Nginx、自签证书并导入、修改 Hosts（虽然步骤多，不过好在大佬们已经帮你做完了大部分工作，并且可以傻瓜化），最终得以享受成果的只有部署了本地反代的设备以及同一内网环境下的设备

本文要讲的反代是在公网机器上真的反代，这使得受众可以扩大到任何有网络的设备，并且只需要配置 Nginx 与 SSL 证书，但需要一定成本（域名与 VPS），并且存在一定局限性



请不要在互联网上公开自己搭建的反代站，P站可能会发邮件到您的主机商投诉。如果您因为此种原因导致 VPS 服务等被终止，本人不负任何责任。

## 准备工作

1. 一台没被P站屏蔽的主机
    众所周知 Vultr 大部分IP段都被P站屏蔽
2. 一个船新的域名
    其实随意啦，用自己域名的二级来弄也可，只是域名会变得比较长
    **后续均以`example.com`来指代我们使用的域名，请灵性代换**
3. 使用“不需要通过验证站点文件来签发/续签”并且最好还支持泛域名的 SSL 证书
    这里我们自然首推 Let's Encrypt，这是看起来唯一符合所有需求并且还免费的证书

## 域名及证书

### 需要使用哪些域？

在反代时我们需要用到以下几个域

如果你愿意使用一个船新域名专门反代：

```
example.com
*.example.com
*.pximg.example.com
```

- **example.com**
   随意，你可以放点自己的东西做一些伪装或者说明，或者直接 301 到`www.example.com`
- ***.example.com**
   用于反代对齐`*.pixiv.net`
- ***.pximg.example.com**
   用于反代对齐`*.pximg.net`，其实该域名中的`pximg`也可以替换成其他的字符串，**只要不与P站的二级域名服务产生冲突即可**

如果你想用一个自己正在使用的域名反代并且不想影响该域名的其他服务：

```
pixiv.example.com
*.pixiv.example.com
*.pximg.example.com
```

各自作用同上，在后续配置上灵性修改即可

### 获取证书

如果你愿意套 CloudFlare，你可以跳过这一节

使用 acme 的 DNS API 方式进行挑战验证来签发证书是最方便的

参考以下文章

https://moe.best/tutorial/acme-le-wc.html

在配置好 API 之后我们使用这样的命令即可签发一个我们想要的三域名合一的证书了，并且还能自动续签，岂不美哉

```

~/.acme.sh/acme.sh --issue --dns dns_cx -d example.com -d '*.example.com' -d '*.pximg.example.com'
```

## Nginx



不要使用 Tengine 等 Nginx 分支版本，在某些模块上可能会有一些奇怪的差异与问题

### 基础配置

这里仅列出关键配置，通常配置例如`listen`、`expires`、`cache`以及 SSL 之类的不会写出，自行添加

```

# *.example.com
server
{
    server_name ~^([^.]+)\.example\.com$;
    set $domain $1;

    resolver 8.8.8.8;

    location ~ .*
    {
        proxy_set_header Host $domain.pixiv.net;
        proxy_set_header Referer "https://www.pixiv.net";
        proxy_cookie_domain pixiv.net example.com;
        proxy_pass https://$domain.pixiv.net;
        proxy_ssl_server_name on;
        proxy_set_header Accept-Encoding "";
        proxy_redirect https://accounts.pixiv.net/ https://accounts.example.com/;

        sub_filter "i-cf.pximg.net" "i.example.com";
        sub_filter "pixiv.net" "example.com";
        sub_filter "pximg.net" "pximg.example.com";
        # 防止错误上报暴露站点
        sub_filter "js_error.php" "block_js_error";
        # 防止谷歌服务暴露站点，同时也可以加快网站加载
        sub_filter "www.google" "block_google";
        sub_filter_once off;
        sub_filter_types *;
    }
}

# *.pximg.example.com
server
{
    server_name ~^([^.]+)\.pximg\.example\.com$;
    set $domain $1;

    resolver 8.8.8.8;

    location ~ .*
    {
        proxy_set_header Host $domain.pximg.net;
        proxy_set_header Referer "https://www.pixiv.net";
        proxy_pass https://$domain.pximg.net;
        proxy_ssl_server_name on;
        proxy_set_header Accept-Encoding "";

        sub_filter "i-cf.pximg.net" "i.example.com";
        sub_filter "pixiv.net" "example.com";
        sub_filter "pximg.net" "pximg.example.com";
        # 防止错误上报暴露站点
        sub_filter "js_error.php" "block_js_error";
        # 防止谷歌服务暴露站点，同时也可以加快网站加载
        sub_filter "www.google" "block_google";
        sub_filter_once off;
        sub_filter_types *;
    }
}
```

### 详解

- **server_name** 与 **set**
   使用正则表达式匹配以方便直接提取出我们要反代的二级域名
- **resolver**
   必要，指定域名解析所用 DNS，因为在后续`proxy_pass`中我们要反代的域名是由`$domain`决定，本身是不定的，Nginx 必须被指定 DNS 才能处理域名解析
- **proxy_cookie_domain**
   改变反代后返回的 header 中 set-cookie 里 cookie 对应的域名，只在`*.example.com`中需要，是解决登陆问题的关键，如想了解后续文章会解释
- **proxy_ssl_server_name**
   由于 P 站开始上 CF 了，其 TLS 启用了 SNI，因此必须指定此项为`on`，否则会握手失败
- **proxy_set_header Referer**
   设置 header 中的 Referer，主要目的是解决`i.pximg.net`的防盗链问题，以及`www.pixiv.net`的部分 API 的 Referer 验证问题
- **proxy_set_header Accept-Encoding**
   将接受的压缩编码设为空，即不接受压缩，因为`sub_filter`无法对压缩过的内容起效
- **proxy_redirect**
   将返回原站 302 的请求进行重定向
- **sub_filter**
   将反代后得到的内容进行字符串替换，以保证链接域名等与反代域名一致
- **sub_filter_types**
   必须设置为`*`，否则默认对于 API 返回的 json 内容等不会进行替换，会导致依靠 ajax 运作的一些功能的异常

## 增强隐蔽性（建议）

### 防止被搜索引擎收录

在 Nginx 配置中向每个 server 添加此句

```

    if ($http_user_agent ~* "qihoobot|Baiduspider|Googlebot|Googlebot-Mobile|Googlebot-Image|Mediapartners-Google|Adsbot-Google|Feedfetcher-Google|Yahoo! Slurp|Yahoo! Slurp China|YoudaoBot|Sosospider|Sogou spider|Sogou web spider|MSNBot|ia_archiver|Tomato Bot|^$") {  
        return 403;
    }
```

请加到`set $domain $1;`这句之后，因为该配置也使用了正则表达式，会导致`$1`改变

### 禁止大陆外IP访问

由于反代P站的受众只可能为大陆内用户，因此我们完全可以禁止大陆外IP访问反代站，同时还能防止P站检测投诉

但请注意，这个方案是对整台 VPS 的`80`与`443`端口生效，这意味着你如果同时在 VPS 上布置了其他站点，他们也将无法被大陆外用户访问

如果需要仅对反代站点生效，请自行百度参考“nginx geoip”，或者使用后面所述的套 CloudFlare 的方式

参考步骤：

1. 安装 ipset

   ```
   
   ```

```
# Debian / Ubuntu
apt-get -y install ipset
# CentOS
yum -y install ipset
```

创建一个 ipset 并添加大陆IP作为白名单

```

ipset -N cnip hash:net
for i in $(curl https://raw.githubusercontent.com/17mon/china_ip_list/master/china_ip_list.txt); do ipset -A cnip $i; done
# 如果你想要添加单个IP x.x.x.x 进此白名单
ipset -A cnip x.x.x.x/32
```

写入防火墙规则（顺序十分重要，请不要改变执行顺序）

```

```

1. ```
   iptables -I INPUT -p tcp --dport 443 -j DROP
   iptables -I INPUT -p tcp --dport 80 -j DROP
   iptables -I INPUT -p tcp -m set --match-set cnip src -j ACCEPT
   ```

### 套 CloudFlare

除了上述方案外，我自己是套了层 CloudFlare，并设置了防火墙规则来阻止非国内以及搜索引擎爬虫访问

这样有个优点，一是 SSL 证书都是 Cloudflare 自动签发和续期的，因此使用 Flexible SSL  选项，然后源反代站就不需要操心证书的事了，直接使用 HTTP；二是 Cloudflare 的防火墙可以实现上面提到的屏蔽国内 IP  以及搜索引擎的功能，不需要自己去维护

当然这样是有缺点的，就是设置 DNS 记录

Cloudflare **CDN** 是**不支持设置泛域名记录**的

因此我们只能一条一条记录加，首次部署简直是要了命，以下列出主站功能相关域名：

```

www.pixiv.net
accounts.pixiv.net
source.pixiv.net
imp.pixiv.net

i.pximg.net
s.pximg.net
pixiv.pximg.net
```

其他的例如小说、直播等等我个人使用频率很低所以我就不考虑了，当然如果你有需求就自己找域名吧（

## 局限性

不能使用绑定的社交账号的登录方式

帐号可能会出现需要 reCAPTCHA 验证导致无法登录，无解，只能自己将原站已登录的 cookie 导出，替换域名，然后导入反代站来进行登录

可能存在尚未发现的问题

## 解决登陆问题的关键

这个问题困扰我一年了，以前我尝试反代的时候，**登录会提示“无效的服务器”而无法登陆**，直到最近才发现真正原因

我通过搜索引擎查找了很多文章，直到遇见了这篇
 [模拟登录pixiv.net后续 - ことりのおやつにしてやるぞー！](https://kotori.love/archives/curl-login-pixiv-next.html)

之前我认为，登录时唯一要注意的只有`postKey`，而代码中的获取 cookie 的操作提醒了我，我的直觉告诉我登录失败是跟 cookie 有关

于是我又翻看了一下 GET 登陆页面时的 header，原来是有 set-cookie 的，而我之前一直从登录相关 js 的操作入手因此没有注意到这个细节

根据这个思路我试着自己用 Nodejs 写了个模拟登录来尝试

```

const Axios = require('axios');
const Qs = require('qs');

async function test() {
    let postKey, cookie = '';

    //访问登录页
    await Axios.get('https://accounts.pixiv.net/login?lang=zh&source=pc&view_type=page&ref=wwwtop_accounts_index', {
        headers: {
            "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36"
        }
    }).then(res => {
        //获取登录页 cookie 和 postKey
        for (let set of res.headers['set-cookie']) {
            cookie += '; ' + set.split(';')[0];
        }
        cookie = cookie.substr(2);
        postKey = /"pixivAccount\.postKey":"([0-9a-z]+)"/.exec(res.data)[1];
    });

    //向登录 API 发送 POST
    await Axios.post('https://accounts.pixiv.net/api/login?lang=zh', Qs.stringify({
        pixiv_id: '邮箱',
        password: '密码',
        captcha: '',
        g_recaptcha_response: '',
        post_key: postKey,
        source: 'pc',
        ref: 'wwwtop_accounts_index',
        return_to: 'https://www.pixiv.net/'
    }), {
        headers: {
            "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36",
            "content-type": "application/x-www-form-urlencoded",
            "accept": "application/json",
            "cookie": cookie
        }
    }).then(res => {
        console.log(res.data);
        console.log(res.headers['set-cookie']);
    });
}

test();
```

返回内容与返回 header 中的 set-cookie：





可喜可贺，也就是说确实是 cookie 的锅

准确地说是因为 sub_filter 只能替换 response 中的内容，我没有想到 set-cookie 的 domain 由于是 `.pixiv.net`，不会被任何机制自动替换，与反代域名不同，没有 set 上，因此导致发出登录 POST 的时候没有携带上这个 cookie

知道了问题核心所在，那么解决方案自然也就不难想到了，经过搜索我找到了 Nginx 官方文档中有提到 [proxy_cookie_domain](http://nginx.org/en/docs/http/ngx_http_proxy_module.html#proxy_cookie_domain)





> **Syntax:**
>  **proxy_cookie_domain** off;
>  **proxy_cookie_domain** domain replacement;
>
> **Default:**
>  **proxy_cookie_domain** off;
>
> **Context:** http, server, location
>
> This directive appeared in version 1.1.15.
>
> Sets a text that should be changed in the domain attribute of the "Set-Cookie" header fields of a proxied server response.

问题解决√

而且没想到解决方式竟如此简单，只不过是加一行配置的事



