var electron= require('electron') //引入electron

var app=electron.app // 创建引用

var BrowserWindow = electron.BrowserWindow // 创建窗口应用

var mainWindow=null;

app.on('ready',()=>{
    mainWindow=new BrowserWindow({
        width:800, 

        height:800,

    //     webPreferences: {
    //     nodeIntegration: true
    // }

    }) // 设置窗口大小

    mainWindow.loadFile('index.html') //加载这个页面

    mainWindow.on('closed',()=>{
        mainWindow = null
    })

})
