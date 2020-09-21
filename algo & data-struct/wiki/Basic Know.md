### Preface

C/C++ 的知识, 包含用法.



### Auto 关键词

> auto不能作为函数的参数
>
> auto不能直接用来声明数组
>
> 为了避免与C++98中的auto发生混淆，C++11只保留了auto作为类型指示符的用法 ，只是一个占位符
>
> auto不能定义类的非静态成员变量
>
> 实例化模板时不能使用auto作为模板参数

```cpp
int main() {
	int a;
	auto m = a;//C++11后auto 声明的变量必须由编译器在编译时期推导而得
	auto n;//用auto声明引用类型时则必须加&
	auto q = 3.14;//用auto声明指针类型时，用auto和auto*没有任何区别
	auto w = 4;
	auto r = " ";
	auto v = 3, d = 3.0;//求同一类型
}
```

针对于`auto`的使用，在处理复杂类型，如标准模块库（STL）中的类型时，才能显现出来
例如，对于下述C++98代码：——《C++ Primer Plus》

```cpp
std::vector<double> scores；
std::vectorsdouble>::iterator pv = scores.begin();
//C++11允许您将其重写为下面这样:
std::vector<double> scores;
auto pv = scores.begin();
```

对于使用`auto`形成的新的循环:

```cpp
#include<iostream>
using namespace std;
int main() {
	int array[] = { 1,2,3,4,5 };
	for (auto& e : array)e *= 2;
	for (auto& e : array)cout << e << " ";
	cout << endl;
	return 0;
}
```

还是很神奇的，`auto`应该是C++11里面的新特性。



### OVERFLOW 上溢

```cpp
int main(){
	int  sum = 1,i;
	for (i = 1; i <= 32; i++) sum *= 2;
	cout << sum;
}
```

结果是3. 

OVERFLOW为math.h中的一个[宏定义](https://www.baidu.com/s?wd=宏定义&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)，其值为3。

含义为运算过程中出现了上溢，即运算结果超出了运算变量所能存储的范围。 



### Data Transform 自动类型转换

```c++
int main() {
	int a;
	cin >> a;
	cout << (5 / 9.0) * (a - 32) << endl; //还是和数字运算的时候不同类型（int double）的 转化相关
	cout << (5 / 9) * (a - 32) << endl;
	cout << 5 / 9 * (a - 32) << endl;
	cout << 5 * (a - 32) / 9 << endl;
}
```

> 编程的过程中需要将值从一种数据类型转换为另一种数据类型 ，C++ 提供了这样做的方法：
>
> 当运算符的操作数具有不同的数据类型时，C++ 会自动将它们转换为相同的数据类型。当它这样做时，遵循一组规则。理解这些规则将有助于程序员防止一些细微的错误蔓延到自己的程序中。就像军队的军官有军阶一样，数据类型也可以按等级排名。如果一个数字数据类型可以容纳的数字大于另一个数据类型，那么它的排名就高于后者。例如，float类型就超越了 int 类型，而 double 类型又超越了 float 类型。

 数字优先级（逐级递减)  ：` long double`、`float``unsigned long long int`    、`long long int`、`unsigned long int`、`long int`、`unsigned int`、`int`。

运行这段代码你会发现结果是`0`,但其实结果是`4,294,967,296`,已经远超int的范围了，所以应该换成`long long`或者`double`才可以。





### Variable

|          数据类型          |                     具体大小                     |
| :------------------------: | :----------------------------------------------: |
|       unsigned   int       |                  0～4294967295                   |
|            int             | <font color="red">-2147483648～2147483647</font> |
|       unsigned long        |                  0～4294967295                   |
|            long            |             -2147483648～2147483647              |
|     long long的最大值      |   <font color="red">9223372036854775807</font>   |
|     long long的最小值      |               -9223372036854775808               |
| unsigned long long的最大值 |               1844674407370955161                |
|      __int64的最大值       |               9223372036854775807                |
|      __int64的最小值       |               -9223372036854775808               |
|  unsigned __int64的最大值  |               18446744073709551615               |

注意：

1. 观察上面的规律： **负数的范围要比正数的范围大1 **、还有一点就是：**数据类型分配的字节数会根据机器的字长和编译器有所不同，不同的大小所表示的范围是不同的。上图唯一一个与机器有关的取值范围是 long 类型的，64位机器使用8个字节（264），而32位机器使用4个字节（232）**
2. C语言的int你会发现有多种不同的版本：有的最大是2^16^,有的最大是2^32^,其实这是**和你的机器和编译器的版本**有关的数据。前者是16位系统的，是最基本的设置，后者是32和64位的版本，**如果你想要最大是2^64^的话，在32位上使用`long long [int]`，在64位上使用`long [int]`**。这是区别。

</br>

#### 定义变量的考量

值得注意的是，在考虑程序的移植性的时候，应该兼顾16位系统的定义：

> 如果知道变量可能表示的整数值大于16位整数的最大可能值，则使用long。即使系统上int为32位，也应这样做。这样，将程序移植到16位系统时，就不会突然无法正常工作，如果要存储的值超过20亿，可使用long long。

</br>

#### 整型字面值

> 整型字面值（常量）是显式地书写的常量，如212或1776，与C相同，C++能够以三种不同的计数方式来书写整数：基数为10、基数为8（老式UNIX版本）和基数为16（硬件黑客的最爱）。
>
> 这里将介绍C++表示法。C++使用前一（两）位来标识数字常量的基数。
>
> 如果第一位为`1~9`，则基数为10（十进制）；因此93是以10为基数的。
>
> 如果第一位是0，第二位为1~7，则基数为8（八进制）；因此`042`的基数是8，它相当于十进制数34。
>
> 如果前两位为Ox或0x，则基数为16（十六进制）；因此0x42为十六进制数，相当于十进制数66，对于十六进制数，字符`a~f`和`A~F`表示了十六进制位，对应于10~15，`OxF`为15，`OxA5`为165（10个16加5个1）。

```cpp
chest = 42; //(42 in decimal)
waist = 66; //(0x42 in hexadecimal )
inseam = 34; //(042 in octal)
```

#### 运算符的结合顺序

这个的重要性不言而喻，简单来说对于`20/4*5`到底是从左往右算，还是从右往左算的结果都是不一样的。因为乘除都是从左到右的，所以最后结果是`25`而不是`1`。运算符重载的`*`(取内容)`+`(取正)`-`(取负)的结合顺序是从右到左，但是相同符号下的加减运算是从左到右，这是容易搞混的点。

### 参数传递

包括形式参数、指针参数、引用参数、指针引用参数。形式参数，顾名思义，只是一个形式，最后不做保留；指针参数，将变量的地址传递到函数中，直接作用于main中的变量；引用参数，和指针略不同。

<font color="red">回去查了一下资料，以下列举：</font>

1.　<font color="red">这里存在一个小的知识点：new返回值是系统给的一片内存的首地址，所以申请内存只可以指针，用引用申请绝对是来捣乱的（手动滑稽）？！</font>
2.　<font color="red">指针数组是可以申请动态内存，但是函数体结束的时候该指针被回收，如果你没有及时把内存地址return回去，内存变成了鬼存（内存泄漏），你也不知道怎么使用。你也是来捣乱的（手动滑稽）</font>

以上，解释完了，另外还有应用的一个小知识，引用底层和指针相似，但是显示的是不占内存，而且在外函数内用完之后，其他函数是无法使用的.(我为什么回文如此脑残的问题？！)

```c++
int lfh(int a, int* b, int& c) {
	int sum = 0, sum1 = 1, sum2 = 0;
	int m = *b, n = c;
	for (int i = 1; i <= a; i++) sum += i;
	for (int i = 1; i <= m; i++) sum2 += i * i;
	for (int i = 1; i <= n; i++) sum1 *= i;
	*b = sum2;
	c = sum1;
	return sum;
}
```

#### 函数返回引用和返回值[·](https://blog.csdn.net/keyouan2008/article/details/5771844)

函数返回**值**时会产生一个临时变量作为函数返回值的副本，而返回**引用**时不会产生值的副本，既然是引用，那引用谁呢？以下是几种引用情况：

1. 引用函数的参数，当然该参数也是一个引用

```c++
const string &shorterString(const string &s1,const string &s2){
return s1.size()<s2.size()?s1:s2;
}
```

以上函数的返回值是引用类型。无论返回s1或是s2,调用函数和返回结果时，都没有复制这些string对象。简单的说，返回的引用是函数的参数s1或s2，同样s1和s2也是引用，而不是在函数体内产生的。

2. 千万不要返回局部对象的引用

```c++
const string &mainip(const string &s){
string ret=s;
return ret;
}
```

当函数执行完毕，程序将释放分配给局部对象的存储空间。此时，对局部对象的引用就会指向不确定的内存。











### cin.eof[^2]

in.eof()返回流结束位，如：

```cpp
char gc;
while(!cin.eof()){ //直至按ctrl+z键退出！控制台窗口中，用ctrl+z来模拟文件结束符
  cin>>gc;
  cout<<gc<<endl; 
}
//相应的，在C中使用的是scanf，如
int M, N;
while(scanf("%d%d", &M, &N) != EOF){
      .....
}
```



### 如何操作内存

> 计算机是一种精确的、有条理的机器。要将信息项存储在计算机中，必须指出信息的存储位置和所需的内存空间。在C++中，完成这种任务的一种相对简便的方法，是使用声明语句来指出存储类型并提供位置标签。

### 数组扩容

不存在任何扩容操作，所谓扩容就是申请更大的数组拷贝过去，即所谓的伪扩容。

类似的还有数组的删除操作，思路如下：

![数组删除](http://i.dfslfh.cn/数组删除.png)

### 输出ASKII码 

将char转化int即得。值得注意的是 两位数字不是没有askii码 而是他的码是八位。

值得注意的是，字符数组的初始化为数字 `0`的时候数组内全补充的`\0`（全局变量也可以达到这个效果）,有的时候用动态申请内存的时候，无法保证最后一位的下一位是`\0`来保证数组停下来（判断条件是`p[i]！=‘\0’ `）,所以应该尽量避免这样的判断条件，如果一定要用这个条件，可以选择初始化的时候就全员`\0`.

### `for`&`while`

做题存在的问题——`for`不超`while`超时.

+ 从内存角度考虑:

    + 局部变量在栈内存中存在,当for循环语句结束,那么变量会及时被gc(垃圾回收器)及时的释放掉,不浪费空间
    + 如果使用循环之后还想去访问循环语句中控制那个变量,使用while循环

+ 应用场景 

    + 如果一个需求明确循环的次数,那么使用for循环(开发中使用for循环的几率大于while循环)
    + 如果一个需求,不知道循环了多少次,使用while循环

### 保留小数

```cpp
cout<<setiosflags(ios::fixed)<<setprecision(2);//第一种写法

cout.setf(ios::fixed)；
cout<<setprecision(2);//第二种写法

cout<<fixed<<setprecision(2);//第三种写法
```

其中：

1. `setprecision(n)`：功能是控制浮点数显示的有效数字个数。
    有意思的是：

    ```cpp
    int main() {
    	double p = 12.56;
    	cout << setprecision(1) <<p<< endl;
    }
    ```

    运行结果：`1e+01`.

2. **`showpoint`：显示一个小数点**

3. **`fixed`：**`setprecision(n)`和`fixed`合用的话可以控制小数点后有几位，只要加上以下**任意一个**语句就可以。

    ```cpp
    cout<<setiosflags(ios::fixed);
    cout.setf(ios::fixed);
    cout<fixed;
    ```

### `while(cin>>a)`

**cin>>a的过程是先取得从键盘的输入值a，并将a赋给cin**

如果[输入流](https://www.baidu.com/s?wd=输入流&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)（输入的值有效）正常，就会继续循环获取键盘值，如果[输入流](https://www.baidu.com/s?wd=输入流&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)错误，或者达到文件末尾（在windows下`Ctrl+Z`，在Linux下`Ctrl+D`），该循环就会终止。输入缓冲是行缓冲。当从键盘上输入一串字符并按回车后，这些字符会首先被送到输入缓冲区中存储。每当按下回车键后，cin.get()  就会检测输入缓冲区中是否有了可读的数据。cin.get()  还会对键盘上是否有作为流结束标志的  `Ctrl+Z ` 或者  `Ctrl+D ` 键按下作出检查，其检查的方式有两种：阻塞式以及非阻塞式。(这里有检查而宏定义中没有检查！！!)

 Windows系统中一般采用阻塞式检查 `Ctrl+Z`、Unix/Linux系统下一般采用非阻塞式的检查  Ctrl+D。

 这种阻塞式的方式有一个特点：

1. 只有按下回车之后才有可能检测在此之前是否有`Ctrl+Z`按下。
2. 如果输入缓冲区中有可读的数据则不会检测`Ctrl+Z`（因为有要读的数据，还不能认为到了流的末尾）。
3. Ctrl+Z产生的不是一个普通的ASCII码值，也就是说它产生的不是一个字符，所以不会跟其它从键盘上输入的字符一样能够存放在输入缓冲区。明白了这几点之后就可以来解释楼主提出的问题了。

因此，输入流结束的条件就是：`^z ` 之前不能有任何字符输入（回车除外），否则  ^z  起不到流结束的作用。相似地，如果在按 ` Ctrl+D ` 之前已经从键盘输入了字符，则  `Ctrl+D`的作用就相当于回车，即把这些字符送到输入缓冲区供读取使用，此时`Ctrl+D`不再起流结束符的作用。如果按 `Ctrl+D  `之前没有任何键盘输入，则`  Ctrl+D  `就是流结束的信号。

阻塞式检查方式指的是只有在回车键按下之后才对此前是否有  Ctrl+Z  组合键按下进行检查，非阻塞式样指的是按下  Ctrl+D  之后立即响应的方式。例如：

从键盘上输入abcd^z  加  回车之后在Windows系统上是这样处理的：由于回车的作用，前面的  abcd  等字符被送到输入缓冲区（注意：上面说过了，^z不会产生字符，所以更不会存储到输入缓冲区，缓冲区中没有  ^z  的存在）。这时，cin.get()  检测到输入缓冲区中已经有数据存在（因此不再检查是否有  ^z  的输入），于是从缓冲中读取相应的数据。如果都读取完了，则输入缓冲区重新变为空，cin.get()  等待新的输入。可见，尽管有  ^z  按下，但是由于在此之前还有其它输入字符（abcd），所以流也不会结束。

### 主函数的返回类型 

1. `void`,即无返回值
2. ` int`,返回int型

`main`的返回值是返回给系统的,0表示成功,其他为失败。有的时候`int `返回值不写也是可以的如果没有值被返回，系统将得到一个表示程序成功完成的值。来自`main()`的非0值表示出错。

### 宏定义

define的定义更像是简单的文本替换，而不是作为一个量来使用

```cpp
#define Add(a,b) a+b;
```

在一般使用的时候是没有问题的，但是如果遇到如：c * Add(a,b) * d的时候就会出现问题，代数式的本意是a+b然后去和c，d相乘，但是因为使用了define（它只是一个简单的替换），所以式子实际上变成了` c*a + b*d`.

```cpp
#include<iostream>
#define f(x) x*x
using namespace std;
int main(){
	int a = 6.0, b = 2.0;
	cout << double(f(a)) / double(f(b)) << endl;
	cout << sizeof(f(a) / f(b)) << endl;//具体的4去哪里了？？？
}
```

**在大规模的开发过程中，特别是跨平台和系统的软件里，define最重要的功能是条件编译**

```cpp
#ifdef WINDOWS
......
......
#endif
#ifdef LINUX
......
......
#endif
```

可以在编译的时候通过#define设置编译环境

### 截取数字数组的长度

由于字符的长度可以用`strlen`截取，所以我数字字符就看着眼红，自己无聊的时候手写了一个(前提是必须最后一位有`\0`)

```cpp
#define LENGTH(ii) int ii=0;for(ii=0;p[ii]!='\0';ii++);
//用法
LENGTH(step);
cout << step;
```

第二种

```cpp
int Length(int p[]) {
	int step, ii = 0;
	for (ii = 0; p[ii] != '\0'; ii++);
	return ii;
}
```



### exit & return[^3]

1. exit用于在程序运行的过程中随时结束程序，exit的参数是返回给OS的。main函数结束时也会隐式地调用exit函数。exit函数运行时首先会执行由atexit()函数登记的函数，然后会做一些自身的清理工作，同时刷新所有输出流、关闭所有打开的流并且关闭通过标准I/O函数tmpfile()创建的临时文件。exit是结束一个进程，它将删除进程使用的内存空间，同时把错误信息返回父进程,而return是返回函数值并退出函数 

2. return是**语言级别**的，它表示了**调用堆栈**的返回；而exit是**系统调用**级别的，它**表示了一个进程的结束**。
    按照ANSI C，在最初调用的main()中使用return和exit()的效果相同。 但要注意这里所说的是“**最初调用**”。**如果main()在一个递归程序中，exit()仍然会终止程序；但return将控制权移交给递归的前一级，直到最初的那一级，此时return才会终止程序**。return和exit()的另一个区别在于，**即使在除main()之外的函数中调用exit()，它也将终止程序。**
3. exit函数是退出应用程序，并将应用程序的一个状态返回给OS，这个状态标识了应用程序的一些运行信息。

4. 和机器和操作系统有关一般是  0 为正常退出 非0 为非正常退出



### Code Way

+ char数组写的时候一定要记住最后的'\0'，因为他的后面可能是随机数，也可能全是0，好点的编译器会给你加\0,但是不要侥幸。
+ dec的用处就是1在其他编译器里去转换。
+ 逻辑结构的背后是逻辑电路，正如逻辑语言背后是逻辑内存
+ 遇到有限制条件的题在进行循环的时候将限制条件放在第一位（如题1128）——逻辑短路
+ 读取EOF的意思：`while(scanf("%d %d%d",&m,&n,&t)!=EOF&&(n&&m&&t)) `
+ 在有些语言中，有返回值的函数被称为函数（function）；没有返回值的函数被称为过程（procedure）或子程序（subroutine），但C++与C一样，这两种变体都被称为函数。
+ 数组初始化的问题，不可以写`int p[N]`但是Devcpp里面却可以，这是因为C语言C99标准里的变长数组VLA,c++标准不支持。gcc编译器支持变长数组,但vc那个编译器不支持。你搜一下变长数组。会有很多这个资料的。
+ 二维数组初始化不可以用（）因为会识别为逗号表达式，返回最后的值。



### Error

| Section               | What                                                         |
| --------------------- | ------------------------------------------------------------ |
| Accepted              | 你的程序对所有的测试数据都输出了正确的答案，你已经得到了该题的所有分数，恭喜。 |
| Wrong Answer          | 评判系统测试到你的程序对若干组（或者全部）测试数据没有输出正确的结果。<br />出现该种错误后，一般有两种解决方向：<br />1. 如果对设计的算法正确性有较大的把握，那么你可以**重点考虑代码健壮性**，即是否存在某些特殊数据使程序出现错误，比如边界数据，比如程序中变量出现溢出。<br />2. 即怀疑算法本身的正确性，那么你就需要重新考虑你的算法设计了。 |
| Presentation Error    | 评判系统认为你的程序输出“好像”是正确的，只是没有严格按照题目当中输出所要求的输出格式来输出你的答案，例如你忽略了题目要求在每组输出后再输出一个空行。<br/>出现这种错误，往往预示着你离完全正确已经不远了，出现错误似乎只是因为**多输出了一些空格、换行之类的多余字待而已**。但这**不是绝对**的，假如在排版题中出现格式错误，那么有可能你离正确的答案仍然有一定的距离。 |
| Time Limit Exceeded   | 你的程序在输出所有需要输出的答案之前已经超过了题目中所规定的时间。<br/>若这种结果出现在你的评判结果里，依然有两种方向可供参考：<br />1. 假如你确定算法时间复杂度能够符合题目的要求，那么依旧可以检查是否程序**可能在某种情况下出现死循环**，**是否有边界数据**可能会让你的代码不按照预想的工作，从而使程序不能正常的结束。<br />2.你设计的**算法时间复杂度**是否已经离于题目对复杂度的要求，如果是这样，那么你需要重新设计更加高效的算法或者对你现行的算法进行一定的优化。 |
| Runtime Error         | 你的程序在计算答案的过程中由于出现了某种致命的原因异常终止。你可以考虑以下几个要点来排除该错误：<br />1. 程序是否**访问了不该访问的内存地址**，比如访问**数组下标越界**。<br />2.程序是否出现了**除以整数0**，从而使程序异常。<br />3.程序**是否调用了评判系统禁止调用的函数**。<br />4.程序是否会出现**因为递归过深或其他原因造成的栈溢出**。 |
| Compile Error         | 你提交的程序并没有通过评判系统的编译，可根据更详细的编译信息修改你的程序。 |
| Memory Limit Exceeded | 你提交的程序在运行输出所有的答案之前所调用的内存已经超过了题目中所限定的内存限制。造成这种错误的原因主要有两个方面：<br />1.你的程序**申请过多的内存**来完成所要求的工作，即**算法空间复杂度**过高。<br />2.因为**程序本身的某种错误使得程序不断的申请内存**，例如因为某种原因出现了**死循环，使得队列中不断的被放入元素**。当然也千万别忽略自己的低级错误，比如**在声明数组大小时多打了一个0**。 |
| Output Limit Exceeded | 你的程序**输出了过多的东西，甚至超出了评判系统为了自我保护而设定的被评判程序输出大小的最高上限**。一般来说该种错误并不常见，一旦出现了也 很好找原因。<br />1. 要么就是你在提交时忘记关闭你在调试时输出的调试信息（我经常输出DP时的数组来动态的观察状态的转）<br />2.要么就是程序的输出部分出现了死循环，使得程序不断地输出而超出系统的限制。<br/>3.其实还有一种错误就是你容易把其中的一些字符给打错这样子 |





### `<std/c++lib>`万能头文件

```cpp
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
```



### Reference

1. https://www.zhihu.com/question/22826568/answer/318102471



[^]: 
[^2]: https://blog.csdn.net/guhaoxin/article/details/83518679
[^3]:https://baike.baidu.com/item/Exit%28%29/1883141

