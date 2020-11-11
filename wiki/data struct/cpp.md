# CPP DETAILS
这里记录关于 C/C++ 底层的东西.

THX FOR:
- [C++诞生历史](https://blog.csdn.net/zxxssdsd/article/details/9309203).
- [C/C++ 误区二：void main()](https://blog.csdn.net/fengyuruhui/article/details/1682319).
- [Make 命令教程](http://www.ruanyifeng.com/blog/2015/02/make.html)
- https://mp.weixin.qq.com/s/TbiaacY3h8SutWVNeNEdeQ
- https://www.zhihu.com/question/51607490/answer/126627362
- https://en.wikipedia.org/wiki/Make_%28software%29
- https://zhuanlan.zhihu.com/p/111110992
- https://www.cnblogs.com/russellluo/archive/2011/10/15/2212787.html
- https://blog.csdn.net/lisfaf/article/details/90411862
- https://mp.weixin.qq.com/s/9cFFBS2srnoK8BujQNhB0A



## Birth

> 在Bjarne博士等人试图去分析UNIX的内核的时候(1979.04)，当时由于没有合适的工具能够有效的**分析由于内核分布而造成的网络流量**，以及怎样将内核模块化。同年10月，Bjarne博士完成了一个可以运行的预处理程序，称之为Cpre，它为C加上了类似Simula的类机制。在这个过程中，Bjarne博士开始思考是不是要开发一种新的语言，当时贝尔实验室对这个想法很感兴趣，就让Bjarne博士等人组成一个开发小组，专门进行研究。当时不是叫做C++，而是C with class，这是把它当作一种C语言的有效扩充。由于当时C语言在编程界居于老大的地位，要想发展一种新的语言，最强大的竞争对手就是C语言，所以当时有两个问题最受关注：
> 
> 1. C++要在运行时间、代码紧凑性和数据紧凑性方面能够与C语言相媲美
> 2. 尽量避免在语言应用领域的限制。
> 
> 在这种情况下，一个很自然的想法就是让C++从C语言继承过来，但是我们的**Bjarne为了避免受到C语言的局限性，参考了很多的语言，例如：从Simula继承了类的概念，从Algol68继承了运算符重载、引用以及在任何地方声明变量的能力，从BCPL获得了//注释，从Ada得到了模板、名字空间，从Ada、Clu和ML取来了异常**。下图是C++标准的上个世纪的历史：

## Details

先看一个标准的程序:

```c++
#include<cstdio>//头文件(.h) stdio代表standard input/output，也就是标准输入输出的意思(对键盘输入输出的支持)
#include<iostream>
using namespace std;
int main(void){// 圆括号（）表明main是一个函数，void表明main 函数不接受任何参数 int main(void)是ISO/ANSI C标准中定义的 main 函数定义方法之一
	cout<<"hello world!";
	return 0;
}// { 标志着函数体开始。函数体以闭大括弧 } 结束
```

总结以下几点: 

1. **ISO/[ANSI C](https://baike.baidu.com/item/ANSI%20C/7657277)**
   > ANSI C是由美国国家标准协会（ANSI）及国际标准化组织（ISO）推出的关于C语言的标准。ANSI C 主要标准化了现存的实现， 同时增加了一些来自 C++ 的内容 （主要是函数原型） 并支持多国字符集 （包括备受争议的三字符序列）。 ANSI C 标准同时规定了 C 运行期库例程的标准。
2. 头文件：包含着编译器进行编译时所需的信息。可能指明了函数名和函数调用方法，但是这些函数的**实现代码**在**预先编译**好了的**库文件**里。
3. **链接器**负责在库文件中寻找我们的程序所需的代码，并且把那些代码和我们写的程序进行链接，从而将我的写的程序**链接成可执行文件**。一句话，头文件用于指导编译器正确地将我们写的源程序编译成可执行文件。
4. **main函数** 误区：**void main()**
   > C/C++ 中从来没有定义过**void main( )** 。**C++** 之父 **Bjarne Stroustrup** 在他的主页上的 **FAQ** 中明确地写着：
   >
   > The definition void main( ) { /* ... */ } is not and never has been C++, nor has it even been C.（ void main( ) 从来就不存在于 C++ 或者 C ）

   在 **C89** 中，**main( )** 是可以接受的。**Brian W. Kernighan** 和 **Dennis M. Ritchie** 的经典巨著 The C programming Language 2e（《C 程序设计语言第二版》）用的就是 main( )。
   
   **C98**中定义了如下两种 main 函数的定义方式：

   ```c++
   int main( )//等同于上
   int main( int argc, char *argv[] )
   ```
   **C99** 标准中，只有以下两种定义方式是正确的：
   ```cpp
   int main( void )//不需要从命令行中获取参数
   int main( int argc, char *argv[] )//和上面的需求相反
   ```
   当然，``char *argv[]` 可以写成`char **argv`；
   
   如果 main 函数的最后没有写 `return` 语句的话，注意：
   + C99 规定编译器要自动在生成的目标文件中（如 exe 文件）加入return 0; ，表示程序正常退出。
   + VC6(1998年)不会在目标文件中加入`return 0`；gcc3.2（Linux 下的 C 编译器）会在生成的目标文件中加入 return 0。
   + main 函数的返回值应该定义为 int 类型，C 和 C++ 标准中都是这样规定的。虽然在一些编译器中，void main 可以通过编译（如 vc6），但并非所有编译器都支持 void main ，因为<font color="red">**标准中从来没有定义过** **void main** 。**g++3.2 中如果 main 函数的返回值不是 int** **类型，就根本通不过编译**</font>。而 gcc3.2 则会发出警告。所以，如果你想你的程序拥有很好的**可移植性**，请一定要用 int main 。(原来markdown的颜色设置可以用英文来代替，是可以说是很方便的)。

5. **返回值**: **main 函数的返回值**用于说明程序的退出状态。如果返回 0，则代表程序正常退出；返回非零(具体由系统决定)代表程序异常退出。

   > [小实验] 在CMD里运行刚才编译好的exe，然后输入“echo **%ERRORLEVEL%**”，回车，就可以看到程序的返回值为 0 。
   >
   > 假设刚才编译好的文件是 a.exe ，如果输入“**a && dir**”，则会列出当前目录下的文件夹和文件。
   >
   > 但是如果改成“return -1”，或者别的非 0 值，重新编译后输入“a && dir”，则 dir 不会执行。
   >
   > 如果你闲，可以把 main 函数的返回值类型改成非 int 类型（如 float），重新编译后执行“a && dir”，看看会出现什么情况，想想为什么会出现那样的情况。顺便提一下，如果输入 **a || dir** 的话，则表示如果 a 异常退出，则执行 dir。
   
   **表示了：**如果 && 前面的程序正常退出，则继续执行 && 后面的程序，否则不执行。也就是说，利**用程序的返回值，我们可以控制要不要执行下一个程序**。这就是 int main 的好处。

   * 编译器也可以提供main()的更多重载版本，不过它们都必须返回int，这个int是返回给你的程序的调用者的，这是种“负责”的做法，“什么都不返回”可不大好哦。如果你程序的调用者不支持用“返回值”来交流，这个值会被自动忽略——但这也不能使void
    main()成为合法的C++或C代码。即使你的编译器支持这种定义，最好也不要养成这种习惯——否则你可能被其他C/C++程序员认为浅薄无知哦。
   * 另外，还要请你注意：无论是ISO C++还是C99都不允许你省略返回类型。这也就是说，和C89及ARM C++[译注：指Margaret Ellis和Bjarne Stroustrup于1990年合著的《The Annotated C++ Reference Manual》中描述的C++]不同，int并不是缺省返回值类型。
6. **注释**: C99 之前的注释只是“*” ，C89之后加入//（**VC6** 支持 //，**TC2** 不支持）
7. **空间**: C95之前都是全局空间，C99后加入名空间
8. **申明的位置**: C99之后支持在任何地方进行申明 但是使用只能在声明之后。
9. **输出函数**: printf与cout: 
   1. <font color="red">Printf **%d** 告诉 printf 用 num 的值替换掉 %d ，并且以
              **整数形式显示** num 的值(d 告诉 printf 以
              **十进制**整数的形式显示 num 的值)。</font>
   2.  cout能够识别类型的功能表明，其设计更灵活、更好用。由于`print()`不够精密，因此根本发现不了错误。它将继续处理，显示一堆乱码; cout可扩展的（extensible），也就是说，可以重新定义`< `运算符，使cout能够识别和显示所开发的新数据类型。
10. **`endl`和`\n`的区别**
    1. 换行符是一种被称为“转义序列”的按键组合，`endl`是一个特殊的C++符号，诸如`endl`等对于`cout`来说有特殊含义的特殊符号被称为控制符（manipulator）。和`cout`一样，`endl`也是在头文件iostream中定义的，且位于名称空间`std`中。
    2.  `endl`确保程序继续运行前刷新输出（将其立即显示在屏幕上）；而使用`"\n"`不能提供这样的保证，这意味着在有些系统中，有时可能在您输入信息后才会出现提示。
11. **C++关键字**（一共32个）：
    > `auto`、`break`、`case`、`char `、`const`、`continue`、`default`、`do` 、`double`、`else`、`enum`、`extern` 、`float`、`for`、`goto`、`if `、`int`、`long`、`register`、`return` 、`short`、`signed`、`sizeof`、`static`、`struct`、`witch`、`typedef`、`union` 、`unsigned`、`void`、`volatile`、`while`.

   当你作死想要用关键字作为变量名的时候也不是不可以，不要全局`using namespace std;`，你可以只是用`std::`达到相同的效果，然后用其他关键字做表，变量名……
12. **语句**(6种)：
    > + 声明语句：定义函数中使用的变量的名称和类型。
    > + 赋值语句：使用赋值运算符（=）给变量赋值。
    > + 消息语句：将消息发送给对象，激发某种行动。
    > + 函数调用：执行函数。被调用的函数执行完毕后，程序返回到函数调用语句后面的语句。
    > + 函数原型：声明函数的返回类型、函数接受的参数数量和类型。
    > + 返回语句：将一个值从被调用的函数那里返回到调用函数中。

    `if( )~else` 条件语句、`for( )~` 循环语句、`while( )~` 循环语句、`do~while( )` 循环语句、`continue` 结束本次循环语句、`break` 中止执行`switch`或循环语句、`switch` 多分支选择语句、`goto` 转向语句、`return` 从函数返回语句。

## 强语言类型
> 有些语言（最典型的是BASIC）在使用新名称时创建新的变量，而不用显式地进行声明。这看上去对用户比较友好，事实上从短期上说确实如此。问题是，如果错误地拼写了变量名，将在不知情的情况下创建一个新的变量。在BASIC中，ss程序员可能编写如下语句：
>
> ```basic
> CastleDark = 34
> CastleDank= CastleDark+MoreGhosts 
> PRINT CastleDark
> ```
>
> 由于CastleDank是拼写错误（将r拼成了n），因此所作的修改实际上并没有修改CastleDark。这种错误很难发现，因为它没有违反BASIC中的任何规则。然而，在C++中，将声明`CastleDark`，但不会声明被错误拼写的`CastleDank`，因此对应的C++代码将违反“使用变量前必须声明它”的规则，因此编译器将捕获这种错误，发现潜在的问题。



## 后缀名(区别c和c++)

| C/C++ |  头文件后缀名  |       源文件后缀名       |
| :---: | :------------: | :----------------------: |
|   c   |       .h       |            .c            |
|  C++  | .h, .hpp, .hxx | .cpp  .cc .cxx  .C  .c++ |

不同编译器和不同的操作系统对不同的版本有所区别.
1. `.h`和`.hpp`的区别是：*.h里面只有声明，没有实现，而*`.hpp`里声明实现都有，后者可以减少`.cpp`的数量，适合用来编写公用的开源库。
2. `inl 文件`是内联函数的源文件。内联函数通常在c++头文件中实现，但有的时候内联函数较多或者出于一些别的考虑（使头文件看起来更简洁等），往往会将这部分具体定义的代码添加到`INL文件`中，然后在该头文件的末尾将其用`#include`引入。由此也可以看到`inl文件`的例外一个用法的影子——模板函数、模板类的定义代码的存放。

## C? C++?
> C++ 编写的程序，都能用等效的 C 程序代替，但 C++ 在语言层面上提供了 OOP/GP 语法、更严格的类型检查系统、大量额外的语言特性（如异常、RTTI等），并且 C++ 标准库也较丰富。有时候 C++ 的语法可使程序更简洁，如运算符重载、隐式转换。但另一方面，C 语言的 API 通常比 C++ 简洁，能较容易供其他语言程序调用。因此，一些 C++ 库会提供 C 的 API 封装，同时也可供 C 程序调用。相反，有时候也会把 C 的 API 封装成 C++ 形式，以支持 RAII 和其他 C++ 库整合等。

## gcc & g++ 

> GCC（GNU Compiler Collection，GNU编译器套件）是由GNU开发的编程语言译器。GNU编译器套件包括C、C++、  Objective-C、 Fortran、Java、Ada和Go语言前端，也包括了这些语言的库（如libstdc++，libgcj等。） 

简单来说，gcc与g++都是GNU(组织)的一个编译器。gcc是linux系统集成的编译器。在linux环境下**没有集成开发环境的一键式操作所带来的麻烦**。这其中涉及**命令行操作、编译选项的设定、文件依赖关系的书写(makefile)等问题**。这里主要介绍的是关于gcc的常用命令行参数及其相应的作用。以C为例, C++同理。需要注意以下几点：

### DIFF

1. gcc与g++都可以编译c代码与c++代码。后缀为.cpp的，两者都会认为是C++程序；但是：后缀为.c的，gcc把它当做C程序，而g++当做是C++程序；。
2. 编译阶段，g++会调用gcc，对于c++代码，两者是等价的，但是因为gcc命令不能自动和C＋＋程序使用的库联接，所以通常用g++来完成链接。
3. 编译可以用gcc/g++，而链接可以用g++或者gcc -lstdc++。因为gcc命令不能自动和C＋＋程序使用的库联接（当然可以选择手动链接，使用命令如下），所以通常使用g++来完成联接。但在编译阶段，g++会自动调用gcc，二者等价。
   ```shell
   gcc main.cpp -lstdc++
   ```
### USAGE 
```shell
gcc-o hello hello.c
```

1. **预处理(Pre-processing)**：编译器将C源代码中的包含的头文件如stdio.h添加进来。
   ```shell
   gcc -E hello.c -o hello.i # 将hello.c预处理输出hello.i文件 # 预处理；对源码进行头文件展开，宏替换等操作
   ```
2. **编译(Compiling)**：gcc首先要检查代码的规范性、是否有语法错误等，以确定代码的实际要做的工作，在检查无误后，gcc把代码翻译成汇编语言
   ```shell
   gcc –S hello.i –o hello.s  # 将预处理输出文件hello.i汇编成hello.s文件# 编译；把c++代码翻译成汇编语言
   ```
3. **汇编(Assembling)**：把编译阶段生成的”.s”文件转成二进制目标代码“.o”文件
   ```shell
   gcc –c hello.s –o hello.o # 将汇编输出文件hello.s编译输出hello.o文件# 汇编；将输出的汇编代码翻译成符合一定格式的机器代码
   ```
4. **链接(Link)**：在成功编译之后，就进入了链接阶段
   ```shell
   gcc hello.o –o hello # 将编译输出文件hello.o链接成最终可执行文件hello # 连接；将汇编生成的OBJ文件，系统库的OBJ文件，库文件链接起来，最终生成可以在特定平台运行的可执行程序
   ```

其他命令:

- `-o <文件名>` ：指定编译器输出可执行文件的文件名；
- `-g` ：在编译时添加调试信息（使用 gdb 调试时需要）；
- `-Wall` ：显示所有编译警告信息；
- `-O1` ， `-O2` ， `-O3` ：对编译的程序进行优化，数字越大表示采用的优化手段越多（开启优化会影响使用 gdb 调试）；
- `-DDEBUG` ：在编译时定义 `DEBUG` 符号（符号可以随意更换，例如 `-DONLINE_JUDGE` 定义了 `ONLINE_JUDGE` 符号）；
- `-UDEBUG` ：在编译时取消定义 `DEBUG` 符号。
- `list` （ `l` ）：列出程序源代码，如 `l main` 指定列出 `main` 函数附近的若干行代码。
- `break` （ `b` ）：设置断点，如 `b main` 表示在 `main` 函数处设置断点。
- `run` （ `r` ）：运行程序直到程序结束运行或遇到断点。
- `continue` （ `c` ）：在程序遇到断点后继续执行，直到程序结束运行或到达下一个断点。
- `next` （ `n` ）：执行当前行语句，如果当前行有函数调用，则将其视为一个整体执行。
- `step` （ `s` ）：执行当前行语句，如果当前行有函数调用，则进入该函数内部。
- `display` （ `disp` ）：指定程序暂停时显示的表达式。
- `quit` （ `q` ）：退出 gdb。
Window ：
1. `Cygwin` 和 `MinGW` 都包含编译器 `GNU C++`，它们使用的编译器名为gtt要使用g++编译器，首先需要打开一个命令提示符窗口。
2. 通常，必须为程序创建一个项目，并将组成程序的一个或多个文件添加到该项目中。每个厂商提供的IDE（集成开发环境）都包含用于创建项目的菜单选项（可能还有自动帮助）。必须确定的非常重要的一点是，需要创建的是什么类型的程序。通常，编译器提供了很多选择，如Windows应用程序、MFC Windows应用程序、动态链接库、Activex控件、DOS或字符模式的可执行文件、静态库或控制台应用程序等。其中一些可能既有32位版本，又有64位版本.
    创建好项自后，需要对程序进行编译和链接。IDE通常提供了多个菜单项，如
    **Compile（编译）**对当前打开的文件中的代码进行编译。
    **Build（建立）、Make（生成）**：编译项目中所有源代码文件的代码。这通常是一个递增过程，也就是说，如果项目包含3个文件，而只有其中一个文件被修改，则只重新编译该文件。
    **Buld All（部建立）**重新编译所有的源代码文件。
    **Link（链接）**（如前所述）将编译后的源代码与所需的库代码组合起来。
    **Execute（执行）/Run（运行）**运行程序。通常，如果您还没有执行前面的步骤，Run将在运行程序之前完成这些步骤。
    **Debug（调试）**以步进方式执行程序
    编译器可能让您选择要生成调试版还是发布版。调试版包含额外的代码，这会增大程序、降低执行速度，但可捷供详细的调试信息



## Make/Compile

> 程序的生命周期是从一个高级C语言程序开始的（被人读懂）（高级编程语言）。为了在系统上运行hello.c程序，每条C语句都必须被其他程序转化为一系列的低级机器语言指令。然后**这些指令按照一种称为可执行目标程序的格式打好包，并以二进制磁盘文件的形式存放起来**。目标程序也称为可执行目标文件。在Unix系统上，从源文件到目标文件的转化是由编译器驱动程序完成的; 在这里，GCC编译器驱动程序读取源程序文件hello.c，并把它翻译成一个可执行目标文件hello，这个翻译过程可分为四个阶段<font color="red">（预处理器、编译器、汇编器和链接器）</font>，四个阶段的程序一起构成了**编译系统（compilation system）**。 ——摘自《深入理解计算机系统》 



## Makefile

### Makefile

> 在软件开发中，**make通常被视为一种软件构建工具**。该工具主要**经由读取一种名为“makefile”或“Makefile”的文件来实现软件的自动化建构**。

**make命令执行时，需要一个 makefile 文件，以告诉make命令如何去编译程序**。

> 不同于之前只留有一个源文件, 一个大型的工程项目中的源文件不计其数，其按类型、功能、模块分别放在若干个目录中。makefile定义了一系列的规则来指定工程项目中哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译。


+ 第一种方法
    ```cpp
    #include<stdio.h>
    #define PI 3.141592653
    int main(){
        double r;
        printf("Please enter the radius of the circle: ");
        scanf("%lf",&r);
        printf("Circumference of the circle is: ");
        printf("%lf\n",r*PI*2);
        printf("Area of the circle is: ");
        printf("%lf\n",r*r*PI);
        return 0;
    }
    ```  
+ 第二种方法
    ```cpp
    #include<stdio.h>
    #define PI 3.141592653
    double  get_circumference(double r);
    double  get_area(double r);
    int main(){
        double r;
        printf("Please enter the radius of the circle ");
        scanf("%lf",&r);
        printf("Circumference of the circle is: ");
        printf("%lf\n",get_circumference(r));
        printf("Area of the circle is: ");
        printf("%lf\n",get_area(r));
        return 0;
    }
    double  get_circumference(double r){
         return  2*PI*r;
    }
    double  get_area(double r){
         return  PI*r*r;
    }
    ```
+ 第三种方法
    ```cpp
    // 第一个文件 text.c
    #include <stdio.h>
    #include "mylib.h"
    int main(){
        double r;
        printf("Please enter the radius of the circle：\n");
        scanf("%lf",&r);
        printf("Circumferenceof the circle is：\n");
        printf("%lf\n",get_circumference(r));
        printf("Area of the circleis：\n");
        printf("%lf\n",get_area(r));
        return 0;
    }
    //第二个文件 mylib.c
    #include "mylib.h"
    double  get_circumference(double r){
        return  2*PI*r;
    }
    double  get_area(double r){
        return  PI*r*r;
    }
    //第三个文件 lib.h
    #define  PI 3.141592653
    double  get_circumference(double r);
    double  get_area(double r);
    ```
    执行编译命令
    ```bash
    gcc -o text mylib.c text.c
    ```

上面的编译方式，当我们修改一个文件时，不需要所有的源文件都参与编译，只需要编译改动的那个文件即可，然后最终编译为可执行文件。但是如果源文件很多，那就比较麻烦了，因此需要下面的Make了。


+ 第四种方法:
    ```bash
    hello : mylib.o  text.o
        gcc -o hello mylib.o text.o
    mylib.o : mylib.c mylib.h
        gcc -c mylib.c
    text.o: text.c
        gcc -c text.c
    clean:
        rm hello mylib.o text.o
    ```
    执行编译命令
    ```bash
    make
    ./hello
    make clean
    ```

以上只是简陋的实例, 以实际为标准


### 为什么不用类 Python 的脚本语言[^2]

make、cmake 这种是领域特定语言(DSL, Domain Specific Language)，使用前需要掌握特定的领域知识。具体需要理解程序和库，怎么从源码一步步构建出来的。中间需要配置目标、路径、依赖关系、生成规则等等。难的并非是 make 和 cmake 语法本身，而是构建和编译的基本知识。没有这些基本知识，就算换了 Python 来写，也是一样会难的。这里说换 Python 来写，是指配置文件用 Python 的语法来写。如果你不使用任何已有工具，从头使用 Python 来控制整个编译构建过程，工作量太大。

编译构建本身是个复杂过程，不同的项目构建规则会有所不同。比如项目有个 txt 的列表文件，需要先调用一个 Python 脚本生成 c 数组，产生一个 list.c 文件，之后让这个 list.c 跟项目其它文件一起编译。或者项目有 Debug 和 Release 两种设置，Debug 不优化，Release 使用 O3 优化。或者项目依赖一个第三方库，需要指定库的路径。

总需要某种方式来告诉构建工具，各种各样的规则。使用 make 工具，规则就写在 makefile 中。而一旦写好 makefile，之后的构建就只需要敲 make 命令。假如不写 makefile，规则还是会以另一种方式存在，比如像 go 语言那样，按照一定的命名方式来组件代码，再运行 go build。

对于 make，最关键的规则是指定依赖关系。当某些文件变了，直接或者间接依赖这些文件的目标就需要重新构建，其它没有依赖的目标不用重新构建。这样可以大大加快构建速度。make 用于构建，并不一定非要用于编译。比如写一本书，就可以用 make 来管理，书稿一但变动，敲入 make 命令，就生成书的交叉索引和目录，并同时生成 word 文档，网页格式、pdf 格式。另外也可以用 make 来生成网站。

make 是很基础的工具。现在基本不会手写 makefile, 而是用其它更高级的工具根据平台，额外配置来生成 makefile（或者生成常用 IDE 的工程文件）, 之后再调用 make。cmake 就是这样的工具，类似的工具还有 Qt 用的 qmake，Lua 写的 premake。

实际上开源库，这些生成规则已经写好了。构建通常只需要三步

```text
./configure
make
make install
```

configure 根据平台和配置自动生成 makefile，之后用 make 来构建项目，再使用 make install 来安装到相应目录。并不需要过多了解 make 和 cmake 的语法。当编写自己的库，才需要了解 make 或者 cmake 的具体语法。

现在编写程序经常依靠 IDE，IDE 将整个构建的过程封装起来。构建过程对于很多人来说是个黑箱子，只知道将文件拖进工程，按个 Build 按钮，程序就出来了。有些人甚至连 Debug 和 Release 有什么区别也不知道。缺乏基本的编译和构建概念，之前只接触过 IDE，初次接触 make、cmake 这些工具, 多少会有不适应的。

那为什么有了 IDE 这样“先进”的东西，还需要 make 和 cmake 这些看似“原始”的工具呢？

1. 某些语言根本就没有 IDE。make 工具是很通用的，任何语言都可以使用，甚至并非是编程也可以使用。上文就提到可以用 make 工具来管理书稿，或者编写网站。
2. 为了跨平台。不同的平台有不同的 IDE，比如同一个 C++ 工程，在 Windows 常用的 IDE 是 Visual Studio, Mac 平台的 IDE 是 Xcode。假如使用 IDE，就需要分别为每个 IDE 重复配置。使用 cmake 工具，只需要写好配置一次，开发的时候根据开发人员的习惯来选择开发方式。有些人在 Linux 平台选择 Vim 来开发；有些人习惯用 IDE，就生成 IDE 项目文件。Mac 平台开发人员就可以用 Xcode，Windows 平台开发人员可以使用 Visual Studio。发布时候，不用发布 IDE 的项目文件。每个平台都用相应的 cmake 来构建。
3. 需要很多控制。让同一份代码，根据不同的情况、不同的平台、编译出不同的版本。比如可以选择编译成静态库和动态库，是否需要 WebKit 功能，是否需要界面，是否需要支持特定的硬件等等。这些控制，使用 IDE 也很难做得。


### make & makefile & cmake & nmake

+ make: 可以看成是一个智能的批处理工具，它本身并没有编译和链接的功能，而是用类似于批处理的方式—**通过调用makefile文件中用户指定的命令来进行编译和链接**的。
+ makefile: 就像一首歌的乐谱，make工具就像指挥家，指挥家根据乐谱指挥整个乐团怎么样演奏，**make工具就根据makefile中的命令进行编译和链接的**。makefile命令中就**包含了调用gcc（也可以是别的编译器）去编译某个源文件的命令**。makefile在一些简单的工程完全可以人工拿下，但是当工程非常大的时候，手写makefile也是非常麻烦的，如果换了个平台makefile又要重新修改，这时候就出现了下面的Cmake这个工具。
+ cmake: 可以更加简单的生成makefile文件给上面那个make用。当然cmake还有其他更牛批功能，就是**可以跨平台生成对应平台能用的makefile**，我们就不用再自己去修改了。**cmake根据一个叫CMakeLists.txt文件（学名：组态档）去生成makefile**。
  + CMakeList.txt: 自己手写CMakeLists.txt (呵呵)
+ nmake: nmake是Microsoft Visual Studio中的附带命令，需要安装VS，实际上可以说相当于linux的make.

总的来说是下图如此:

![](/img/program/c++make.png)



## GDB

linux程序调试中最常用的工具，gdb主要可以做四件事情帮我们找到bug：
+ 启动你的程序，指定任意可以影响程序行为的参数；
+ 让你的程序在指定的条件停下；
+ 测试你的程序停止的时候发生了什么；
+ 改变程序内部的变量，来改正程序的错误继续执行。


### GDB常用命令

+ 开始/结束gdb：使用 gdb filename 启动gdb，其中 filename 应为可执行文件;  gdb以命令行环境运行，进入gdb后，程序会等待用户的指令并执行，直至用户选择退出。使用q 或 Ctrl + d退出。

```bash
gdb a.out # 使用gdb对a.out进行调试　　
```
+ 运行指令（run/r)

```bash
r # 表示开始运行程序，如果是正在调试的程序，表示再次进行调试
```
+ l/list指令: 可以使用指令l来列出源文件中的部分源代码。(需要编译时加入 -g 选项生成对应的编译符号)
  + 对于多个文件的而言，可以通过 l 源文件名：行号 来指定所需查看的源代码
  + 也可以以函数为整体进行输出，命令格式为 l function_name

```bash
l 10 # 输出源程序10行的源码，可以方便进行调试。若要继续查看，按回车键会继续向下显示。
l hello.c:10 # 输出hello.c在第10行前后的代码（默认共十行代码）
l main # 输出main函数上下共十行的源代码
```
+ 断点指令

指令 b可以在需要地方放置断点，使得程序在指令的位置停止运行，指令格式为 b 断点位置。其中，断点位置可以是行号，也可以是函数名(指定方式与 l 指令类似)，也可以是地址。

```bash
b 10 # 在源代码10行处放置断点　　
b main # 在main函数开始处放置断点　　
b *0x80480000 # 在存放在0x80480000处的指令处放置断点，直接使用地址时需要使用 *地址 的格式 　　
b 10 if a<10 # 可以在断点中加入中断执行的条件，表示当a < 10 时才会中断程序执行
```

在断点处检查完毕后，可以使用 c 指定继续指令的执行，跳转到下个断点，或者跳转到观察点。使用指令 disable/enable 断点号 可以启用/停用某断点。使用指令 d 可删除所有的断点，d 1 删除breakpoint 1.

```bash
disable/enable n # 停用/启用编号为n的断点
d # 删除所有断点
d n # 删除标号为n的断点
```
+ 观测点(watch)指令: 一般用来观察某个变量/内存地址的状态（也可以是表达式），如可以监控该变量/内存值是否被程序读/写情况。

```bash
watch a # 当（指定变量/内存地址/表达式）a 的值发生变化时，中断程序执行　　
awatch a # 当a被读或者被写的时候将停住程序
rwatch a # 当 a 的值被读取时，中断表达式的执行
```
+ 显示(disp)和打印(p)指令: disp指令(display)可以在每次程序暂定时显示指定变量的值，指令格式为 disp 变量名。若输入的变量为数组名，则每次显示数组的所有元素，若为结构体，则输出结构体的所有成员的值。

```bash
disp temp # 在每次程序暂停时输出指定的变量的值(确保程序在指定变量的作用域内执行，如某个在特定函数中的局部变量在程序进入该函数执行之前是无法被显示的)　　
undisplay # 取消所有disp指定的自动显示变量
```

p指定(print)同样将变量的值打印出来，用法与diap类似，但结果只显示一次。

除变量外，p指令还可以输出给定寄存器、给定地址处的值。同时，可以通过一些参数对打印格式进行规定，如 /x 表示以16进制格式打印值，/t表示以二进制格式打印值。

```bash
p $eax # 打印寄存器%eax存储的值，注意使用$标志寄存器名称　　
p /x ($ebp + 8)# 以十六进制的格式打印%ebp + 8 的值　　
p /t 100# 以二进制格式输出100的值　　
p *0x08048000# 输出位于0x08048000处的数据(此处实际存放的是机器代码)，注意地址需使用 * 标志，否则会被默认为常数　　
p *(int *)0xxxxxxxx # 将指定地址处数据按照整数格式输出，这里一般需要指出指针类型方便gdb解释数据
```
+ nfo命令：列出相应的信息

```bash
info watchpoints # 输出所有观察点　　
info frame # 输出栈帧的使用情况　　
info  b n # 其中 n 为指定的断点号，显示指定断点的状态信息，不加参数 n 时，会显示所有的断点的信息
```
+ ptype指令

```bash
pt a # 可以查看变量a的类型，ptype可以简写为pt
```
+ 格式化输出(printf)指令: 使用方法与C语言中的格式化输出函数相似. 使用指令whatis可以方便的得知所需对象的类型，如 whatis temp 会显示出temp的类型定义，在调试时有用。

```bash
printf" %d , %d \n",X,Y # 对于两个整型变量X，Y进行输出
```
+ s(step)与n指令: s 与 n 指令都是表示执行下一条指令指令的意思。但是，当遇到函数调用时，s 指令会进入函数调用内部进行执行，即下一步为被调函数的第一指令，而 n 指令不进入函数调用内部，会将整个函数的执行过程当作一步执行。

+ 回溯(bt)指令: 回溯指令(backtrace)可以查看程序内存访问越界等错误信息，显示程序出错的位置，从而帮助定位程序错误。

+ 设置(set)指令: 可以将指定的变量的值修改为调试所需要的值。如对于一个int型的变量X，可以使用 set X = 12 将变量的值进行设置。

##  AFTERWARDS
Today is 23^th^ Jul, 2020. I have a little envious about something, which is reason I continue to write these words. Emotion needs to be freed, such as her lived in my past memory , some hurt words in the past I couldn't forget. But unfortunatly nobody company with me. it actually make more effictive in hurt myself, which is reason why we want a pet like a cat or dog, beacuse we just would't like alone. Meanwhile, it likes not the first that  Even I could thought I cry for myself alone again one day in futurn. It sucks! Fu\*\*\*\*\* dame it! I waana leave !!!
