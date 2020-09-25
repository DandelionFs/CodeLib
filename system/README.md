---
date: 2020-06-01 00:00:00</font></center>
---

## Environment Var

### Linux

### Win10<sup>1</sup>

1. 不区分大小写
2. 系统变量对所有用户有效,  优先级高于用户变量
3. 系统在执行用户命令时，若用户未给出文件的绝对路径，则首先在当前目录下寻找相应的可执行文件、批处理文件等,   找到为止(不会递归文件夹,  只指文件 )；
4. 新加命令后注意要保存. 

## Usr

关于我看书的一个假想（其实也确实如此，至少Wiki上面已经提过）——早期多人共享一台计算机，共享的系统可能就是Unix或者Linux，而不会是win，因为Unix可比Win出现的要早啊，

1. **PC和操作系统一次只能供一个用户使用**。即使您可以物理连接外围设备（例如USB集线器），**操作系统仍然只能渲染一个台式机**，随之而来的是欢闹声。
   PCs are designed for one user at a time as are operating systems. Eve n if you could physically get the peripherals connected (eg. USB hub), the OS would still only render one desktop and hilarity would ensue. 

2. 在操作系统级别，来自多个连接的键盘或鼠标的输入被解释为来自单一来源。如果要使用多个鼠标和键盘，则任何尝试读取输入的应用程序都必须降低级别。 
   On the OS level, the input from multiple connected keyboards or mice is interpreted as coming from a single source.

   If 

[1]:https://zhuanlan.zhihu.com/p/93719752