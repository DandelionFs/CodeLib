
### Version 0.1 -> 1.0

```shell
npm install electron -g
# ?
npm install electron --save-dev
# ??
npm install electron -g --unsafe-perm
# ???
sudo npm npm install electron -g
# ????
sudo npm npm install electron -g --unsafe-perm
# ?????
npm config set proxy url
# ??????!!!!!!
npm config delete proxy
# what about you???
# reboot! F*** U


# > electrona9.2.0 postinstall /usr/local/lib/node modules/electron
# > node install.js
# Error: EACCES: permission denied. mkdtemp '/usr/local/lib/node modules/electron/electron-download-nosukt'
#npm ERR! code ELIFECYCLE
#npm ERR! errno 1
#npm ERR! electron@9.2.0 postinstall: node install.js
#npm ERR! Exit status 1
#npm ERR!
#npm ERR! Failed at the electronag.2.0 postinstall script.
#npm ERR! This is probably not a problem with npm. There is likely additional logging output above.
#npm ERR! A complete log of this run can be found in:
#npm ERR! /root/.npm/ logs/2020-08-13T05 20 38 701z-debug.log
```
从上面可以看出总是卡在 node install.js 的 download `electron-linux-x64.zip`, 是校园网+GFW的原因了.

而因为不知道具体的路径, 所以智能乖乖的执行这个脚本...

失败总结: 

+ 就算挂代理下载这个JS包还是很慢, 几乎没有进度... 所以以后开发还是用上阿里的 cnpm 吧, 在这方面不能不妥协[^1].
+ `/home/usr/.npmrc` 加上 `electron_mirror="https://npm.taobao.org/mirrors/electron/"`[^2]





### Demo [^3]

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Text</title>
    </head>

    <body>
        <center> <h1> Hello, Electron!!! </h1></center>
    </body>
</html>
```

```javascript
var electron= require('electron') //引入electron
var app=electron.app // 创建引用
var BrowserWindow = electron.BrowserWindow // 创建窗口应用
var mainWindow=null;//声明要打开的主窗口
app.on('ready',()=>{
    mainWindow=new BrowserWindow({
        width:800, 
        height:800,
    //     webPreferences: {//最新的electron@5.0系列中，nodeIntegration参数默认是false。而在以前版本的electron中，这个nodeIntegration参数，默认为true。
    //     nodeIntegration: true
    // }
    }) // 设置窗口大小
    mainWindow.loadFile('index.html') //加载这个页面
    mainWindow.on('closed',()=>{////监听关闭事件，把主窗口设置为null
        mainWindow = null
    })
})
```

之后总算是交上了这四天的答卷 ...

### Notes[^4]

+ NodeJS: http://nodejs.cn/learn
+ Electron: https://www.electronjs.org/docs/tutorial


#### Nodejs

```javascript
const http = require('http')

const hostname = '127.0.0.1'
const port = 3000

const server = http.createServer((req, res) => {//会创建新的 HTTP 服务器并返回它
  res.statusCode = 200
  res.setHeader('Content-Type', 'text/plain')
  res.end('你好世界\n')
})

server.listen(port, hostname, () => {
  console.log(`服务器运行在 http://${hostname}:${port}/`)
})
```

每当接收到新的请求时，[`request` 事件](http://nodejs.cn/api/http.html#http_event_request)会被调用，并提供两个对象.

+ 一个请求（[`http.IncomingMessage`](http://nodejs.cn/api/http.html#http_class_http_incomingmessage) 对象）提供了请求的详细信息。 在这个简单的示例中没有使用它，但是你可以访问请求头和请求数据。

+ 一个响应（[`http.ServerResponse`](http://nodejs.cn/api/http.html#http_class_http_serverresponse) 对象）用于返回数据给调用方。



#### Electron

使用[`ipcRenderer`](https://www.electronjs.org/docs/api/ipc-renderer) 和 [`ipcMain`](https://www.electronjs.org/docs/api/ipc-main)模块发送消息

使用 [remote](https://www.electronjs.org/docs/api/remote)模块进行RPC方式通信

RPC方式通信

[web页面间如何共享数据](https://www.electronjs.org/docs/faq#how-to-share-data-between-web-pages)。

主进程和渲染进程中，你可以通过require的方式将其包含在模块中以此，获取Electron的API

```cpp
const electron = require('electron')
```

+ 主进程或渲染进程
+ 一些API可以同时在两种进程中使用. 每一个API的文档都将声明你可以在哪种进程中使用该API。
+ Electron通过`remote`模块暴露一些通常只能在主进程中获取到的API。 为了在渲染进程中创建一个`BrowserWindow`的实例，我们通常使用remote模块为中间件：


同时对主进程和渲染进程暴露了Node.js 所有的接口

1)所有在Node.js可以使用的API，在Electron中同样可以使用。 在Electron中调用如下代码是有用的：

```cpp
const fs = require('fs')
const root = fs.readdirSync('/')
// 这会打印出磁盘根级别的所有文件
// 同时包含'/'和'C:\'。
console.log(root)
```

+ 加载远程内容的信息和指南
+ npm 提供了目前世界上最大的开源代码库，那里包含了经过良好维护和测试的代码，这些代码之前往往是专门供给服务器应用程序使用的，能够使用这些代码是Electron的重要特色之一。
+ 在你的应用程序中如果要使用官方的AWS SDK，你需要首先将它作为一项依赖进行安装, 然后在你的Electron应用中，通过require引入并使用该模块，就像构建Node.js应用程序那样：

```cpp
// 准备好被使用的S3 client模块
const S3 = require('aws-sdk/clients/s3')
```

原生Node.js模块 (即指，需要编译源码过后才能被使用的模块) 需要在编译后才能和Electron一起使用。绝大多数的Node.js模块都*不*是原生的， 在650000个模块中只有400是原生的。 当然了，如果你的确需要原生模块，可以在这里查询[如何重新为Electron编译原生模块](https://www.electronjs.org/docs/tutorial/using-native-node-modules)(很简单)。









[^1]:https://developer.aliyun.com/mirror/NPM?from=tnpm
[^2]:https://www.electronjs.org/docs/tutorial/installation
[^3]:https://jspang.com/detailed?id=62
[^4]:https://www.electronjs.org