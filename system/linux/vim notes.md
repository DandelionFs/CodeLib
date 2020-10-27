# Vim Notes
## Config
**[LINK]** https://www.jianshu.com/p/6bb4e8491132
Vim 的设置文件不会自动保存设置文件, 所以需要自己写.

```shell
"===========================
"  文件设置
"===========================
set encoding=utf-8
set termencoding=utf-8
set fileencoding=utf-8
set fileencodings=ucs-bom,utf-8,chinese,cp936
"解决菜单乱码
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
set autoread         "设置当文件在外部被修改，自动更新该文件
"vim提示信息乱码的解决
language messages zh_CN.utf-8
set nobackup        " 不要备份
set noundofile      " 不生成undo文件
set nowritebackup
set nowrap
colorscheme elflord " 颜色主题
set nu          " 显示行号
set history=500     " 保留历史记录
set backspace=2     " 退格键可用
"===========================
" 插件设置
"===========================
call plug#begin( '$VIMRUNTIME/plugged' )
Plug 'vim-airline/vim-airline'
Plug 'zxqfl/tabnine-vim'
call plug#end()
"===========================
"代码设置
"===========================
syntax enable "打开语法高亮
syntax on "打开语法高亮
set showmatch "设置匹配模式，相当于括号匹配
set smartindent "智能对齐
filetype on
filetype plugin indent on
"===========================
"查找/替换相关的设置
"===========================
set hlsearch "高亮显示查找结果
set incsearch "增量查找
```

### MORE
- **复制**: `y`
  - `n+yy`    复制n行
  - `yy`   复制当前光标行整行内容
- **粘贴**: `p`
- **删除** `d`
  - `行数+两次d`: 可删除从当前行+n行的数据
- **撤回**: `u`
- **减少行换行**: `Shief+J`
- **当前行新起一空行且进入插入模式**: o
- **全选** `ggvG`/`ggVG`: 其中 `gg`是让光标移到首行 **[vim特有]**, 
  - `v/V`切换到可视化(Visual),
  - `G`则移到最后一行`:$`
  - `d`是删除(剪切)
  - `y`是复制
  - https://blog.csdn.net/dadoneo/article/details/6003415
  - https://blog.csdn.net/u012948976/article/details/50493431
  > vim中默认有多个寄存器(粘贴板)，其中使用命令y和p是将内容复制粘贴到vim内部剪切板中，即意味着不能用到其他程序中。但是 `“*` 和 `“+` 这两个寄存器与系统相通, 可以将vim中的内容复制到其他程序中.
- [移动(缩进)代码](https://segmentfault.com/q/1010000000343626)
  - 先进visual模式，然后选中要移动的代码快，按shift+<就可以整体移动了。
  - ```shell
    10,100> #第10行至第100行缩进
    20,80< #第20行至第80行反缩进
    ```
  - 提供另一个方法，不用进 V 模式
    - 移动到需要处理的首行，ma
    - 移动到需要处理的末行，<'a

## SHORTCUTS
[LINK] :https://blog.csdn.net/HappyCodeFly/article/details/86684827

### Insert

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

## DIFF- Gedit && Namo && Vim && Vi
**[LINK]**:
1. https://developer.aliyun.com/article/309383
2. https://ubuntuqa.com/zh-tw/article/1230.html

- 系统都会自带nano和vi这两个最基本的编辑器。
+ Nnno非常適合編輯配置文件，但是如果要進行編程，最好使用Vim或Emacs。 Nano支持突出顯示。但這是非常主觀的。
+ vi是老式的文字处理器，功能已经很齐全。不管好不好用，既然大家这么推崇，肯定有他的好处，我们先学习了肯定不会有坏处。vi使用于文本编辑，但是vim更适用于coding。
+ vim是vim 的升级版, Vim是模態的意思是每個鍵在不同的模式中意味著不同的東西。
  + 多级撤消 : vi里按 u只能撤消上次命令
  + 易用性: 运行于unix,windows ,mac等操作平台
  + 语法加亮: vim可以用不同的颜色来加亮你的代码。
  + 可视化操作: 即vim不仅可以在终端运行，也可以运行于x window、 mac os、 windows。
  + 对vi的完全兼容: 某些情况下，你可以把vim当成vi来使用。
+ Geany 有很好的功能，內置終端窗口非常好。我將它用於大多數編程項目。
+ Gedit 是图形化的编辑程序, 学习成本低, 簡單輕巧，但你必須安裝一堆插件才能趕上Geany的普通內置功能，比如代碼折疊等。而Geany插件將為您提供額外的功能，如版本控製集成，可選和non-intrusive項目管理，在功能定義和聲明等之間跳轉。而Geany中可用的可配置鍵綁定允許您幾乎完全按照自己的喜好進行設置 – 盡管默認值也很不錯。 Gedit可以捆綁Python解釋器，但是Geany捆綁了整個虛擬終端。
+ Emacs 具有語法突出顯示並支持擴展, 並且可以通過其嵌入的Lisp(elisp)方言進行擴展。它還具有許多統計程序的模式，支持tex，日曆，郵件閱讀實用程序，俄羅斯方塊甚至精神科醫生。 Emacs(或Vim，但對於統計數據不太好)值得學習，因為它們都是跨平台的，並且支持世界上幾乎所有的編程語言。

## Change Vim/Vim-gtk
**[LINK]**  https://askubuntu.com/questions/1208159/how-do-i-install-vim-gnome-on-ubuntu-19-10

> 因为 19.10 把 vim-gnome 移除了, 所以搜不到.
