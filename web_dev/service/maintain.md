---
date: 2020-10-23 17:40:00
---
## 宝塔
### 网站配置文件

```shell
server{
    listen 80;
	listen 443 ssl http2;
    server_name blog.dfslfh.cn;
    index index.php index.html index.htm default.php default.htm default.html;
    root /www/wwwroot/www.dfslfh.cn/build;
    # SSL-START SSL相关配置，请勿删除或修改下一行带注释的404规则
    # error_page 404/404.html;
    # HTTP_TO_HTTPS_START
    if ($server_port !~ 443){
        rewrite ^(/.*)$ https://$host$1 permanent;
    }
    #HTTP_TO_HTTPS_END
    ssl_certificate     /www/server/panel/vhost/cert/blog.dfslfh.cn/fullchain.pem;
    ssl_certificate_key    /www/server/panel/vhost/cert/blog.dfslfh.cn/privkey.pem;
    ssl_protocols TLSv1.1 TLSv1.2 TLSv1.3;
    ssl_ciphers ECDHE-RSA-AES128-GCM-SHA256:HIGH:!aNULL:!MD5:!RC4:!DHE;
    ssl_prefer_server_ciphers on;
    ssl_session_cache shared:SSL:10m;
    ssl_session_timeout 10m;
    error_page 497  https://$host$request_uri;

    # SSL-END
    
    # ERROR-PAGE-START  错误页配置，可以注释、删除或修改
    # error_page 404 /404.html;
    # error_page 502 /502.html;
    # ERROR-PAGE-END
    
    # PHP-INFO-START  PHP引用配置，可以注释或修改
    include enable-php-56.conf;
    # PHP-INFO-END
    
    # REWRITE-START URL重写规则引用,修改后将导致面板设置的伪静态规则失效
    include /www/server/panel/vhost/rewrite/blog.dfslfh.cn.conf;
    # REWRITE-END
    
    # 禁止访问的文件或目录
    location ~ ^/(\.user.ini|\.htaccess|\.git|\.svn|\.project|LICENSE|README.md){
        return 404;
    }
    
    # 一键申请SSL证书验证目录相关设置
    location ~ \.well-known{
        allow all;
    }
    
    location ~ .*\.(gif|jpg|jpeg|png|bmp|swf)$
    {
        expires      30d;
        error_log off;
        access_log /dev/null;
    }
    
    location ~ .*\.(js|css)?$
    {
        expires      12h;
        error_log off;
        access_log /dev/null; 
    }
    access_log  /www/wwwlogs/blog.dfslfh.cn.log;
    error_log  /www/wwwlogs/blog.dfslfh.cn.error.log;
}
```


### 网站伪静态


### 网站SEO


### 网站跳转


### 网站统计


### 一些常见的错误
- **强转HTTPS导致网站重定向错误**: -> 关闭强转HTTPS


