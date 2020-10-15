## Change Vim/Vim-gtk

[LINK] : https://askubuntu.com/questions/1208159/how-do-i-install-vim-gnome-on-ubuntu-19-10

因为 19.10 把 vim-gnome 移除了, 所以搜不到.

## Config

[LINK] : https://www.jianshu.com/p/6bb4e8491132

Vim 的设置文件不会自动保存设置文件, 所以需要自己写.


## 移动(缩进)代码[^1]
[LINK] : https://segmentfault.com/q/1010000000343626

+ 先进visual模式，然后选中要移动的代码快，按shift+<就可以整体移动了。

+ ```shell
    10,100> #第10行至第100行缩进
    20,80< #第20行至第80行反缩进
    ```

+ 提供另一个方法，不用进 V 模式。

    + 移动到需要处理的首行，ma
    + 移动到需要处理的末行，<'a

确实有些底层, 有的时候绑定快捷键可能会好一些.

## 全选

+ `ggvG`/`ggVG`

其中 `gg`是让光标移到首行**[vim特有]**, `v/V`切换到可视化(Visual), `G`则移到最后一行, `d`是删除(剪切), `y`是复制. 

另外, 关于Vim下只可以粘贴50行的Bug, VSCode并没有遇到.摘录网上的解释

> vim中默认有多个寄存器(粘贴板)，其中使用命令y和p是将内容复制粘贴到vim内部剪切板中，即意味着不能用到其他程序中。但是 `“*` 和 `“+` 这两个寄存器与系统相通, 可以将vim中的内容复制到其他程序中.

More Details:
+ https://blog.csdn.net/dadoneo/article/details/6003415
+ https://blog.csdn.net/u012948976/article/details/50493431




## SHORTCUTS
[LINK] :https://blog.csdn.net/HappyCodeFly/article/details/86684827

|操作|效果|
|---|---|
|CTRL-M 或 CTRL-J|开始新行|
|CTRL-E|插入光标下方的字符|
|CTRL-Y	|插入光标上方的字符|
|CTRL-A		|插入上次插入的文本|
|CTRL-@		 | 插入上次插入的文本并结束插入模式|
|CTRL-R {0-9a-z%#:.-="}	|插入寄存器的内容|
|CTRL-W	|	  删除光标前的一个单词|
|CTRL-U		|  删除当前行的所有字符|
|CTRL-T		 | 在当前行首插入一个移位宽度的缩进|
|CTRL-D		  |从当前行首删除一个移位宽度的缩进|
|0 CTRL-D	 | 删除当前行的所有缩进|
|^ CTRL-D	  |删除当前行的所有缩进，恢复下一行的缩进|
