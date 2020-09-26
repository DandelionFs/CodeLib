# MFC入门（一）-- 第一个简单的windows图形化界面小程序（打开计算器，记事本，查IP）

https://blog.csdn.net/zmdsjtu/article/details/52311107



大约三年前，学过一些简单的编程语言之后其实一直挺苦恼于所写的程序总是拘泥于用的编译器，脱离了编译环境基本没运行的可行性，故而写一个在任意windows电脑下都能运行的小软件便成为了一块心病。

 

大约两年前着手开始做本科毕业设计的时候接触到了MFC，写过一些代码，发现确实是挺容易入门也可以做出一些简单而漂亮的demo的，下面不多废话来做我们的第一个简单的可以发给爸妈使用的简单MFC小软件吧。

 

//////////////////////////////准备工作/////////////////////////

 

惯例放上编程所用软件VS2015下载地址：https://www.visualstudio.com/

//VS2010，VS2012也是类似的

值得注意的是这里采用C++编译，安装时务必勾选编程语言里的C++，如果不慎没安装，之后新建项目选择C++项目会提示安装，但会等挺久的

 

////////////////////////////正式开工/////////////////////////

 

第一步，新建项目  //新建项目--Visual C++ --MFC --MFC应用程序

 

 

 

 

 

这里比较习惯用基于对话框的MFC界面，要注意下右下角的MFC的使用，如果是在本机上可以选择动态库Dll的模式，如果想在别人并没有你的环境的情况下（比如给爸妈使用）则最好选择静态库中使用MFC，这样就相当于把dll也封装进了程序，从而程序会比DLL的略大一点~






到这步可以直接点完成然后生成如下界面：

 


首先改下说明，点击图片中的文字，在属性栏中找到对应的Caption便可以修改文字，这里准备做一个简单的打开计算器的功能。

 

 

下面我们来给按钮加上打开计算器的功能。

首先左击确定按钮看到属性栏的Caption改成“打开计算器”如图：




双击“打开计算器”按钮便可以跳转到按钮对应的功能定义位置进行代码的撰写。

 

修改代码如下：

void CFirst_MFCDlg::OnBnClickedOk()

{

// TODO: 在此添加控件通知处理程序代码

HINSTANCE hRslt = ShellExecute(NULL, _T("open"),

_T("calc.exe"),NULL,NULL,SW_SHOWNORMAL);

assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

}

 

之后需要在这个文件的最上方#include <assert.h>方便调用打开计算器的程序。

 

//////////////////到了这里可以测试下程序了~生成-生成解决方案，在release里有可以点开使用的EXE文件//////////

 

如果想添加新的控件,点击左侧的工具箱，例如我想加一个新的按钮来增加一个打开记事本的功能，就拖动button到界面上，修改名字成“打开记事本”






对应粘贴代码如下：

 

void CFirst_MFCDlg::OnBnClickedButton1()

{

// TODO: 在此添加控件通知处理程序代码

HINSTANCE hRslt = ShellExecute(NULL, _T("open"),

_T("notepad.EXE"),NULL,NULL,SW_SHOWNORMAL);

assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

}

 

再加上一个查看IP地址的button以及对应的代码如下：

 

 

void CFirst_MFCDlg::OnBnClickedButton2()

{

// TODO: 在此添加控件通知处理程序代码

// TODO: 在此添加控件通知处理程序代码Nslookup

HINSTANCE hRslt = ShellExecute(NULL, _T("open"),

_T("Nslookup.EXE"),NULL,NULL,SW_SHOWNORMAL);

assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

}

 

 

然后选择Release并生成解决方案，在项目对应的Release里可以看到生成的可以使用的EXE啦~

默认的目录如下：

 

 

实现结果如下： //一个可以发给爸妈使用的程序就完成啦~

 

 

最后祝大家编程愉快~
————————————————
版权声明：本文为CSDN博主「朱铭德」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/zmdsjtu/article/details/52311107