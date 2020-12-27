# CPP DETAILS
这里记录关于 C/C++ 底层的东西.

THX FOR:
- [cppreference.com](https://en.cppreference.com/w/)
- [LearnCpp.com](https://www.learncpp.com/)
- [cplusplus](http://cplusplus.com/)
- [awesome-cpp](https://github.com/fffaraz/awesome-cpp)
- [C++诞生历史](https://blog.csdn.net/zxxssdsd/article/details/9309203).
- [void main()](https://blog.csdn.net/fengyuruhui/article/details/1682319).
- [Make 命令教程](http://www.ruanyifeng.com/blog/2015/02/make.html)
- [Linux下C语言编程实践（Makefile入门）](https://mp.weixin.qq.com/s/TbiaacY3h8SutWVNeNEdeQ)
- [为什么会选择 make，cmake 之流来控制程序编译，而不是用现成的脚本语言，如 Python？](https://www.zhihu.com/question/51607490/answer/126627362)
- [Make (software)](https://en.wikipedia.org/wiki/Make_%28software%29)
- [5分钟理解make/makefile/cmake/nmake](https://zhuanlan.zhihu.com/p/111110992)
- [[Windows]使用nmake命令](https://www.cnblogs.com/russellluo/archive/2011/10/15/2212787.html)
- [cmake与make的区别](https://blog.csdn.net/lisfaf/article/details/90411862)
- [今日份学习粮食——GCC和GDB的使用](https://mp.weixin.qq.com/s/9cFFBS2srnoK8BujQNhB0A)
- [为什么 C 语言源程序最后一行要是一个空行](https://www.zhihu.com/question/20018991/answer/15239139)
- [降低耦合](http://blog.csdn.net/tianyaxingge/article/details/6696114)
- [如何降低耦合度](https://www.cnblogs.com/candyzhmm/p/7119690.html)
- [Compiling Cpp](https://wiki.ubuntu.org.cn/Compiling_Cpp)
- [Linux 下C++开发入门指南,简易入门版](https://blog.csdn.net/luoduoduojiayou/article/details/54585114)
- [.c vs .cc vs. .cpp vs .hpp vs .h vs .cxx [duplicate]](https://stackoverflow.com/questions/5171502/c-vs-cc-vs-cpp-vs-hpp-vs-h-vs-cxx)


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


## `void*`

void在英文中作为名词的解释为“空虚；空间；空隙”；而在C语言中，void被翻译为“无类型”，相应的void *为“无类型指针”。void似乎只有“注释”和限制程序的作用，当然，这里的“注释”不是为我们人提供注释，而是为编译器提供一种所谓的注释。

作用：
1. 对函数返回的限定，这种情况我们比较常见。
2. 对函数参数的限定，这种情况也是比较常见的。

一般我们常见的就是这两种情况：

1. 当函数不需要返回值值时，必须使用void限定，这就是我们所说的第一种情况。例如：void func（int a,char *b）。
2. 当函数不允许接受参数时，必须使用void限定，这就是我们所说的第二种情况。例如：int func(void)。

### void指针的使用规则：

1. void指针可以指向任意类型的数据，就是说可以用任意类型的指针对void指针对void指针赋值。例如：
    ```cpp
    int *a；
    void *p；
    p=a；
    ```
    如果要将void指针p赋给其他类型的指针，则需要强制类型转换，就本例而言：a=（int *）p。在内存的分配中我们可以见到void指针使用：内存分配函数malloc函数返回的指针就是void *型，用户在使用这个指针的时候，要进行强制类型转换，也就是显式说明该指针指向的内存中是存放的什么类型的数据（int *)malloc(1024)表示强制规定malloc返回的void*指针指向的内存中存放的是一个个的int型数据。

2. 在ANSI C标准中，不允许对void指针进行一些算术运算如p++或p+=1等，因为既然void是无类型，那么每次算术运算我们就不知道该操作几个字节，例如char型操作sizeof（char）字节，而int则要操作sizeof（int）字节。而在GNU中则允许，因为在缺省情况下，GNU 认为void *和char *一样，既然是确定的，当然可以进行一些算术操作，在这里sizeof（*p）==sizeof（char）。void几乎只有“注释”和限制程序的作用，因为从来没有人会定义一个void变量，让我们试着来定义：`void a;` 语句编译时会出错，提示“illegal use of type 'void'”。即使void a的编译不会出错，它也没有任何实际意义。众所周知，如果指针p1和p2的类型相同，那么我们可以直接在p1和p2间互相赋值；如果p1和p2指向不同的数据类型，则必须使用强制类型转换运算符把赋值运算符右边的指针类型转换为左边指针的类型。
    ```cpp
    float *p1;
    int *p2;
    p1 = p2;
    //其中p1 = p2语句会编译出错，
    //提示“'=' : cannot convert from 'int *' to 'float *'”，必须改为：
    p1 = (float *)p2;

    //而void *则不同，任何类型的指针都可以直接赋值给它，无需进行强制类型转换. 但这并不意味着，void *也可以无需强制类型转换地赋给其它类型的指针。因为“无类型”可以包容“有类型”，而“有类型”则不能包容“无类型”。
    void *p1;
    int *p2;
    p1 = p2;

    ```

    小心使用void指针类型: 按照ANSI(American National Standards Institute)标准，不能对void指针进行算法操作，即下列操作都是不合法的：
    ```cpp
    void * pvoid;
    pvoid++; //ANSI：错误
    pvoid += 1; //ANSI：错误
    //ANSI标准之所以这样认定，是因为它坚持：进行算法操作的指针必须是确定知道其指向数据类型大小的。
    //例如：
    int *pint;
    pint++; //ANSI：正确
    pint++的结果是使其增大sizeof(int)。
    ```
    但是GNU则不这么认定，它指定void *的算法操作与char *一致。因此下列语句在GNU编译器中皆正确： 
    ```cpp
    pvoid++; //GNU：正确
    pvoid += 1; //GNU：正确
    pvoid++的执行结果是其增大了1
    ```
    在实际的程序设计中，为迎合ANSI标准，并提高程序的可移植性，我们可以这样编写实现同样功能的代码：
    ```cpp
    void * pvoid;
    ((char *)pvoid)++; //ANSI：错误；GNU：正确
    (char *)pvoid += 1; //ANSI：错误；GNU：正确
    ```

- GNU和ANSI还有一些区别，总体而言，GNU较ANSI更“开放”，提供了对更多语法的支持。但是我们在真实设计时，还是应该尽可能地迎合ANSI标准。 如果函数的参数可以是任意类型指针，那么应声明其参数为void *
- void指针可以任意类型的数据，可以在程序中给我们带来一些好处，函数中形为指针类型时，我们可以将其定义为void指针，这样函数就可以接受任意类型的指针。如：
- 典型的如内存操作函数memcpy和memset的函数原型分别为：
    ```cpp
    void * memcpy(void *dest, const void *src, size_t len);
    void * memset ( void * buffer, int c, size_t num );
    ```
    这样，任何类型的指针都可以传入memcpy和memset中，这也真实地体现了内存操作函数的意义，因为它操作的对象仅仅是一片内存，而不论这片内存是什么类型（参见[C语言实现泛型编程](http://www.cnblogs.com/archimedes/p/c-general-function1.html)）。如果memcpy和memset的参数类型不是void *，而是char *，那才叫真的奇怪了！这样的memcpy和memset明显不是一个“纯粹的，脱离低级趣味的”函数！void的出现只是为了一种抽象的需要，如果你正确地理解了面向对象中“抽象基类”的概念，也很容易理解void数据类型。正如不能给抽象基类定义一个实例，我们也不能定义一个void（让我们类比的称void为“抽象数据类型”）变量。


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



## C++ 编程中相关文件后缀

| **.a**                                                   | 静态库 (archive)            |
| -------------------------------------------------------- | --------------------------- |
| **.C** **.c** **.cc** **.cp** **.cpp** **.cxx** **.c++** | C++源代码（需要编译预处理） |
| **.h**                                                   | C或者C++源代码头文件        |
| **.ii**                                                  | C++源代码（不需编译预处理） |
| **.o**                                                   | 对象文件                    |
| **.s**                                                   | 汇编语言代码                |
| **.so**                                                  | 动态库                      |
| **\<none\>**                                               | 标准C++系统头文件           |

> Historically, the first extensions used for C++ were `.c` and `.h`, exactly like for C. This caused practical problems, especially the `.c` which didn't allow build systems to easily differentiate C++ and C files.
> 
> Unix, on which C++ has been developed, has case sensitive file systems. So some used `.C` for C++ files. Other used `.c++`, `.cc` and `.cxx`. `.C` and `.c++` have the problem that they aren't available on other file systems and their use quickly dropped. DOS and Windows C++ compilers tended to use `.cpp`, and some of them make the choice difficult, if not impossible, to configure. Portability consideration made that choice the most common, even outside MS-Windows.
> 
> Headers have used the corresponding `.H`, `.h++`, `.hh`, `.hxx` and `.hpp`. But unlike the main files, `.h` remains to this day a popular choice for C++ even with the disadvantage that it doesn't allow to know if the header can be included in C context or not. Standard headers now have no extension at all.
> 
> Additionally, some are using `.ii`, `.ixx`, `.ipp`, `.inl` for headers providing inline definitions and `.txx`, `.tpp` and `.tpl` for template definitions. Those are either included in the headers providing the definition, or manually in the contexts where they are needed.
> 
> Compilers and tools usually don't care about what extensions are used, but using an extension that they associate with C++ prevents the need to track out how to configure them so they correctly recognize the language used.
> 
> 2017 edit: the experimental module support of Visual Studio recognize `.ixx` as a default extension for module interfaces, clang++ is recognizing `.c++m`, `.cppm` and `.cxxm` for the same purpose.


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
- [gnu c和标准c都有哪些区别？](https://www.zhihu.com/question/24151438/answer/26841871)
    > 然后说正题，具体的区别可以到下面的文档里找，英语文档，感觉不太难，没有太生僻的单词：GCC在线文档总索引：[https://gcc.gnu.org/onlinedocs/gcc/index.html](https://link.zhihu.com/?target=https%3A//gcc.gnu.org/onlinedocs/gcc/index.html)GCC支持的标准C的一些设置（比如默认GCC使用C90），这个页面里还包括C++等：[https://gcc.gnu.org/onlinedocs/gcc/Standards.html#Standards](https://link.zhihu.com/?target=https%3A//gcc.gnu.org/onlinedocs/gcc/Standards.html%23Standards)GCC/C的新特性，主要是语法描述（没有太多区别性的描述）：[https://gcc.gnu.org/onlinedocs/gcc/C-Implementation.html#C-Implementation](https://link.zhihu.com/?target=https%3A//gcc.gnu.org/onlinedocs/gcc/C-Implementation.html%23C-Implementation)GCC对标准C的扩展（大部分都是GCC新增的）：[https://gcc.gnu.org/onlinedocs/gcc/C-Extensions.html#C-Extensions](https://link.zhihu.com/?target=https%3A//gcc.gnu.org/onlinedocs/gcc/C-Extensions.html%23C-Extensions)因为数量太多，还是看文档吧
    >



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



## `cpp`以空行结束

有一点是从 Python 中发现的, 就是最后一行都得空着, 也就是说, 代码的结束之后得多敲一个'\n', 否则报错 :

> no newline at end of file

原因如下:

C 语言是在 Unix 中发明的，为 Unix 系统的编程语言，它对文件的处理遵循一个基本的原则：

> 文件是流式的，可以被任意的拼接并且拼接后仍然保证完整性。

为了保证这一点，在 Unix 中 \n 符号被定义为一行的『结束符』，换句话说，如果一行的结尾没有 \n 视为这一行没有结束，换句话说这个文件不完整，也就是说这根本不是一个合法的文本文件。（题外话：同时为了保证这一点，**Unix 文本通常不允许使用 BOM**，**因为 BOM 拼接之后将出现在字符流的中间位置**，**无法有效的定义其处理方法**。）

在 Windows 中，微软把 \n 定义为两行之间的『分隔符』而非结束符，所以 Unix 文件结尾的 \n ，在 Windows 看起来就是一个空行，而这一个空行在 Unix 中并不存在，如果你使用 Vim 之类的文本编辑器，会根本看不到最后这个空行。

不遵守标准会带来的问题是：如果 \n 是两行之间的分隔符，那么最后一行不带 \n，结果是拼接两个文件时，后一个文件的第一行就会被拼到前一个文件的最后一行，这很可能会造成语意错误。

比较常见的例子是：

前一个文件最后一行是 } 后一个文件第一行是 #include，如果 } 后面没有结束符，拼接之后就成了 }#include ，立即发生语法错误。

## C 源程序最后一行要是一个空行？

> C 语言它对文件的处理遵循一个基本的原则: 
> 
> **文件是流式的，可以被任意的拼接并且拼接后仍然保证完整性。**
>
> 为了保证这一点，在 Unix 中 \\n 符号被定义为一行的『结束符』，即如果一行的结尾没有 \\n 视为这一行没有结束，说明这个文件不完整，也就是说这根本不是一个合法的文本文件。同时为了保证这一点，Unix 文本通常不允许使用 BOM，因为 BOM 拼接之后将出现在字符流的中间位置，无法有效的定义其处理方法。在 Windows 中 \\n 定义为两行之间的『分隔符』而非结束符，所以 Unix 文件结尾的 \\n ，在 Windows 看起来就是一个空行，而这一个空行在 Unix 中并不存在，如果你使用 Vim 之类的文本编辑器，会根本看不到最后这个空行。



## 耦合

> 模块（类）与其它模块（类）之间的关联、感知和依赖的程度，是衡量代码独立性的一个指标，也是软件工程设计及编码质量评价的一个标准。
> 
> 比如说若函数A依赖于函数B的实现中某个细微的对于全局变量的副作用，那么我们可以说A和B之间的耦合很深；这可能导致我们简单地修改了B之后发现A不能正常工作 了；可能会花费我们大量的时间来寻找原因。
> 
> 就像是不会写网页的自己写了许多耦合度巨大的网页，而当时我改一个样式，另外一个区域的样式也就改变了，折腾了一天只写了一点点代码，而且还是不能用，最后结果还是全部删除重新开写。

**“模块”一词是一个模糊的概念，可以是一个变量、一个函数、一个类，或者是一个package（在大型软件项目中）**


- 耦合强度依赖于以下几个因素：
  1. 对另一个模块的调用；
  2. 另一个模块传递的数据量；
  3. 施加到另一个模块的控制的多少；
  4. 接口的复杂程度。
- 耦合按从强到弱的顺序可分为以下几种类型：
  1. 内容耦合。当一个模块直接修改或操作另一个模块的数据,或者直接转入另一个模块时，就发生了内容耦合。此时，被修改的模块完全依赖于修改它的模块。类与类之间直接调用或继承关系都是属于这种耦合。
  2. 公共耦合。两个及两个以上的模块共同引用一个全局数据项就称为公共耦合。
  3. 控制耦合。一个模块在界面上传递一个信号（如开关值、标志量等）控制另一个模块，接收信号的模块的动作根据信号值进行调整，称为控制耦合。
  4. 标记耦合。模块间通过参数传递复杂的内部数据结构，称为标记耦合。此数据结构的变化将使相关的模块发生变化。
  5. 数据耦合。模块间通过参数传递基本类型的数据，称为数据耦合。
  6. 非直接耦合。模块间没有信息传递时，属于非直接耦合。
- 重要性
  - **耦合度很高**的情况下，**维护代码时修改一个地方会牵连到很多地方，如果修改时没有理清这些耦合关系，那么带来的后果可能会是灾难性的**，特别是对于需求变化较多以及多人协作开发维护的项目，修改一个地方会引起本来已经运行稳定的模块错误，严重时会导致恶性循环，问题永远改不完，开发和测试都在各种问题之间奔波劳累，最后导致项目延期，用户满意度降低，成本也增加了，这对用户和开发商影响都是很恶劣的，各种风险也就不言而喻了。
  - 值得注意的是，**不可能有绝对的零耦合**，比如基于J2EE编程那就必须和JDK耦合，而且高耦合也不是一无是处，如果在设计前期预料到某功能后期基本不用修改，那么即使高耦合了也关系不大。但是，在还没有能力设计出基本不用修改的代码前，还得要求以低耦合为标准。那么怎样才能最大限度地降低耦合度呢？下面介绍降低耦合度的几种方法。
- 方法
  1. 少使用类的继承，多用接口隐藏实现的细节。 java面向对象编程引入接口除了支持多态外， 隐藏实现细节也是其中一个目的。 
  2. 模块的功能化分尽可能的单一，供其它模块调用的机会就少。(高内聚低耦合)
  3. 遵循一个定义只在一个地方出现。
  4. 少使用全局变量 ("Singleton") 。
  5. 类属性和方法的声明少用public，多用private关键字。
  6. 多用设计模式，比如采用MVC的设计模式就可以降低界面与业务逻辑的耦合度。
  7. 尽量不用“硬编码”的方式写程序，同时也尽量避免直接用SQL语句操作数据库。
  8. 避免直接操作或调用其它模块或类（内容耦合）；如果模块间必须存在耦合，原则上尽量使用数据耦合，少用控制耦合，限制公共耦合的范围，避免使用内容耦合。
  9. 不要过早在意细节优化。先用最清楚的逻辑描述出程序的框架，如果真的有时间效率问题那一般来说是算法复杂度的问题，在程序编好且正确之后再考虑细节优化吧。这是耦合度增加的温床。
  10. 面向对象。

    > 我知道很难让人像我一样，每当要在程序中用到某种数据结构——不管是最简单的队列还是复杂些的并查集或者Suffix Tree——我都会编一个class，而且很可能是Template Class。我并不是炫耀，我只是想减少耦合，我只是想使程序更清晰些。“面向对象”这个话题会在本系列中单列一篇文章来做更详尽的分析。
    >
    > 我不知道你是否听说过UML、MVC等等这些在软件工程界很“时髦”的缩写词。我认为这些技术（尤其是MVC）存在的主要目的就是为了减少耦合。所以说，不要再写像涂了胶水的绳结一样的程序了，试图减少耦合，从今天开始。


## 右值引用
相关概念: 右值、纯右值、将亡值、universal references、引用折叠、移动语义、move语义和完美转发等等
```cpp
//c++98/03中的左值引用(int&却不能绑定右值)
int i = 0;
int& j = i;

int&& i = 0;//绑定一个右值
```
右值引用是C++11中新增加的一个很重要的特性，他主是要用来解决C++98/03中遇到的两个问题，
- **临时对象非必要的昂贵的拷贝操作**
- **在模板函数中如何按照参数的实际类型进行转发**

```cpp
int i = getVar();
//产生两种类型的值，一种是左值i(表达式结束后仍然存在)，一种是函数getVar()返回的临时值(在表达式结束后就销毁了),区别于取地址
int i = 0;
//i 可以被引用，0 就不可以了, 0是纯右值（prvalue）
//
//在C++11中所有的值必属于左值、将亡值、纯右值三者之一。如非引用返回的临时变量、运算表达式产生的临时变量、原始字面量和lambda表达式等都是纯右值。
//
//而将亡值是C++11新增的、与右值引用相关的表达式，比如，将要被移动的对象、T&&函数返回值、std::move返回值和转换为T&&的类型的转换函数的返回值等。
int j = 5;//一个原始字面量
auto f = []{return 5;};//[]{return 5;}是一个lambda表达式，纯右值，在表达式结束之后销毁
//--
T&& k = getVar();//“&&” 就是右值引用, 表达式结束后会被“续命”, 和变量k的声明周期一样长。
//右值是匿名变量，我们也只能通过引用的方式来获取右值
//--
T(T&& a) : m_val(val){ a.m_val=nullptr; }// 一个类的构造函数, 一个参数是一个右值引用
//--
template <typename T>void f(T&& val){ foo(std::forward<T>(val)); }
//C++11之前调用模板函数时，存在一个比较头疼的问题，如何正确的传递参数
//如下, 都不能按照参数的本来的类型进行转发。

template <typename T>
void forwardValue(T& val){
    processValue(val); //右值参数会变成左值 
}
template <typename T>
void forwardValue(const T& val){
    processValue(val); //参数都变成常量左值引用了 
}

/*
C++11引入了完美转发：在函数模板中，完全依照模板的参数的类型（即保持参数的左值、右值特征），将参数传递给函数模板中调用的另外一个函数。C++11中的std::forward正是做这个事情的，他会按照参数的实际类型进行转发。
*/

void processValue(int& a){ cout << "lvalue" << endl; }
void processValue(int&& a){ cout << "rvalue" << endl; }
template <typename T>
void forwardValue(T&& val){
    processValue(std::forward<T>(val)); //照参数本来的类型进行转发。
}//右值引用T&&是一个universal references，可以接受左值或者右值，正是这个特性让他适合作为一个参数的路由，然后再通过std::forward按照参数的实际类型去匹配对应的重载函数，最终实现完美转发。我们可以结合完美转发和移动语义来实现一个泛型的工厂函数，这个工厂函数可以创建所有类型的对象。
void Testdelcl(){
    int i = 0;
    forwardValue(i); //传入左值 
    forwardValue(0);//传入右值 
}
/*
lvaue 
rvalue
*/

template<typename…  Args>
T* Instance(Args&&… args){
    return new T(std::forward<Args >(args)…);
}//这个工厂函数的参数是右值引用类型，内部使用std::forward按照参数的实际类型进行转发，如果参数的实际类型是右值，那么创建的时候会自动匹配移动构造，如果是左值则会匹配拷贝构造。
```

- 关于右值引用作为构造函数的参数详尽的说明, 看下面的代码.
    ```cpp
    class A{
    public:
        A():m_ptr(new int(0)){cout << "construct" << endl;}
        A(const A& a):m_ptr(new int(*a.m_ptr)) {//深拷贝的拷贝构造函数
            cout << "copy construct" << endl;
        }
        ~A(){ delete m_ptr;}
    private:
        int* m_ptr;
    };
    int main() {
        A a = GetA();
        return 0;
    }
    /*
    construct
    copy construct
    copy construct
    */
    //一个带有堆内存的类，必须提供一个深拷贝拷贝构造函数，否则会发生“指针悬挂”的问题。
    //
    //如果不提供深拷贝的拷贝构造函数，上面的测试代码将会发生错误（编译选项-fno-elide-constructors），内部的m_ptr将会被删除两次，一次是临时右值析构的时候删除一次，第二次外面构造的a对象释放时删除一次，而这两个对象的m_ptr是同一个指针，这就是所谓的指针悬挂问题。
    //
    //提供深拷贝的拷贝构造函数虽然可以保证正确，但是在有些时候会造成额外的性能损耗(如果堆内存很大的话，那么，这个拷贝构造的代价会很大，带来了额外的性能损失)，因为有时候这种深拷贝是不必要的

    //解决方案如下:
    class A{
    public:
        A():m_ptr(new int(0)){}
        A(const A& a):m_ptr(new int(*a.m_ptr)){ //深拷贝的拷贝构造函数
            cout << "copy construct" << endl;
        }
        A(A&& a) :m_ptr(a.m_ptr){
            a.m_ptr = nullptr;
            cout << "move construct" << endl;
        }//这个构造函数并没有做深拷贝，仅仅是将指针的所有者转移到了另外一个对象，同时，将参数对象a的指针置为空，这里仅仅是做了浅拷贝，因此，这个构造函数避免了临时变量的深拷贝问题。
        ~A(){ delete m_ptr;}
    private:
        int* m_ptr;
    };
    int main(){
        A a = Get(false); 
    } 
    /*
    construct
    move construct
    move construct
    并没有调用拷贝构造函数，只调用了move construct函数，让我们来看看这个move construct函数

    上面这个函数其实就是移动构造函数，他的参数是一个右值引用类型，这里的A&&表示右值，为什么？前面已经提到，这里没有发生类型推断，是确定的右值引用类型。为什么会匹配到这个构造函数？因为这个构造函数只能接受右值参数，而函数返回值是右值，所以就会匹配到这个构造函数。这里的A&&可以看作是临时值的标识，对于临时值我们仅仅需要做浅拷贝即可，无需再做深拷贝，从而解决了前面提到的临时变量拷贝构造产生的性能损失的问题。这就是所谓的移动语义，右值引用的一个重要作用是用来支持移动语义的。

    需要注意的一个细节是，我们提供移动构造函数的同时也会提供一个拷贝构造函数，以防止移动不成功的时候还能拷贝构造，使我们的代码更安全。

    我们知道移动语义是通过右值引用来匹配临时值的，那么，普通的左值是否也能借助移动语义来优化性能呢，那该怎么做呢？事实上C++11为了解决这个问题，提供了std::move方法来将左值转换为右值，从而方便应用移动语义。move是将对象资源的所有权从一个对象转移到另一个对象，只是转移，没有内存的拷贝，这就是所谓的move语义。如图1-1所示是深拷贝和move的区别。

    */

    //--
    {
        std::list< std::string> tokens;
        //省略初始化...
        std::list< std::string> t = tokens; //这里存在拷贝 
    }
    std::list< std::string> tokens;
    std::list< std::string> t = std::move(tokens);  //这里没有拷贝 
    /*
    如果不用std::move，拷贝的代价很大，性能较低。使用move几乎没有任何代价，只是转换了资源的所有权。他实际上将左值变成右值引用，然后应用移动语义，调用移动构造函数，就避免了拷贝，提高了程序性能。如果一个对象内部有较大的对内存或者动态数组时，很有必要写move语义的拷贝构造函数和赋值函数，避免无谓的深拷贝，以提高性能。事实上，C++11中所有的容器都实现了移动语义，方便我们做性能优化。

    这里也要注意对move语义的误解，move实际上它并不能移动任何东西，它唯一的功能是将一个左值强制转换为一个右值引用。如果是一些基本类型比如int和char[10]定长数组等类型，使用move的话仍然会发生拷贝（因为没有对应的移动构造函数）。所以，move对于含资源（堆内存或句柄）的对象来说更有意义。
    */
    ```


### 特点
1. 编译器优化引发的内存报错
    ```cpp
    //在编译时设置编译选项-fno-elide-constructors用来关闭返回值优化效果
    #include <iostream>
    using namespace std;
    int g_constructCount=0;
    int g_copyConstructCount=0;
    int g_destructCount=0;
    struct A{
        A(){cout<<"construct: "<<++g_constructCount<<endl;    }
        A(const A& a){cout<<"copy construct: "<<++g_copyConstructCount <<endl;}
        ~A(){cout<<"destruct: "<<++g_destructCount<<endl;}
    };
    A GetA(){return A();}
    int main() {
        A a = GetA();
        return 0;
    }
    /*
    关闭返回值优化效果: 
    construct: 1
    copy construct: 1
    destruct: 1
    copy construct: 2
    destruct: 2
    destruct: 3

    拷贝构造函数调用了两次，一次是GetA()函数内部创建的对象返回出来构造一个临时对象产生的，另一次是在main函数中构造a对象产生的。第二次的destruct是因为临时对象在构造a对象之后就销毁了。

    开启返回值优化的话，输出结果
    construct: 1
    destruct: 1
    */
    //返回值优化将会把临时对象优化掉，但这不是c++标准，是各编译器的优化规则。

    // 在编译时设置编译选项-fno-elide-constructors

    int main() {
        A&& a = GetA();
        return 0;
    }
    /*
    construct: 1
    copy construct: 1
    destruct: 1
    destruct: 2

    通过右值引用，比之前少了一次拷贝构造和一次析构，原因在于右值引用绑定了右值，让临时右值的生命周期延长了。我们可以利用这个特点做一些性能优化，即避免临时对象的拷贝构造和析构.
    */
    ```

    事实上，在c++98/03中，通过常量左值引用也经常用来做性能优化。上面的代码改成：`const A& a = GetA()`;输出的结果和右值引用一样，因为**常量左值引用是一个“万能”的引用类型****，可以接受左值、右值、常量左值和常量右值**。需要注意的是**普通的左值引用不能接受右值**，比如这样的写法是不对的：`A& a = GetA();`会报一个编译错误，因为非常量左值引用只能接受左值。
2. 右值引用独立于左值和右值。意思是**右值引用类型的变量可能是左值也可能是右值**。比如下面的例子：
    ```cpp
    int&& var1 = 1; // var1类型为右值引用，但var1本身是左值
    ```
    关于右值引用一个有意思的问题是：T&&是什么，一定是右值吗？让我们来看看下面的例子：
    ```cpp
    template<typename T>
    void f(T&& t){}

    f(10); //t是右值

    int x = 10;
    f(x); //t是左值
    //T&&表示的值类型不确定，可能是左值又可能是右值
    ```
3. `T&& t`在发生自动类型推断的时候，它是未定的引用类型（universal references），如果被一个左值初始化，它就是一个左值；如果它被一个右值初始化，它就是一个右值，它是左值还是右值取决于它的初始化。我们再回过头看上面的代码，对于函数`template<typename T>void f(T&& t)`，当参数为右值10的时候，根据universal references的特点，t被一个右值初始化，那么t就是右值；当参数为左值x时，t被一个左值引用初始化，那么t就是一个左值。需要注意的是，仅仅是当发生自动类型推导（如函数模板的类型自动推导，或auto关键字）的时候，T&&才是universal references。再看看下面的例子：
    ```cpp
    template<typename T>
    void f(T&& param); 

    template<typename T>
    class Test {
        Test(Test&& rhs); 
    };
    ```
    上面的例子中，param是universal reference，rhs是Test&&右值引用，因为模版函数f发生了类型推断，而Test&&并没有发生类型推导，因为Test&&是确定的类型了。

    正是因为右值引用可能是左值也可能是右值，依赖于初始化，并不是一下子就确定的特点，我们可以利用这一点做很多文章，比如后面要介绍的移动语义和完美转发。

    这里再提一下引用折叠，正是因为引入了右值引用，所以可能存在左值引用与右值引用和右值引用与右值引用的折叠，C++11确定了引用折叠的规则，规则是这样的：

    - 所有的右值引用叠加到右值引用上仍然还是一个右值引用；
    - 所有的其他引用类型之间的叠加都将变成左值引用。



### 非常量引用的初始值必须为左值的问题

首先，先看下面一个例子：
```cpp
#include<iostream>
using namespace std;
int main(){
int i =2;
double &r =i;
return 0;
}
// gcc error: invalid initialization of reference of type 'double&' from expression of type 'int'
```
如果改成 const double &r =i;没有问题。难道这里的i不是左值？程序改成 :

```cpp
int main(){
double i =2;
double &r =i;
return 0;
}
```

没有错误, 难道这里的i又是左值啦？

其实：`const double &r = i;` 由于类型不匹配，实际相当于：`const double inner_tmp = (double)i;` 这里就产生了一个临时变量`const double &r = inner_tmp;`临时的中间变量都是const，所有没有const的引用会失败。


- **右值引用**：
    >右值引用（及其支持的Move语意和完美转发）是C++0x将要加入的最重大语言特性之一，这点从该特性的提案在C++ - State of the Evolution列表上高居榜首也可以看得出来。从实践角度讲，它能够完美解决C++中长久以来为人所诟病的临时对象效率问题。从语言本身讲，它健全了C++中的引用类型在左值右值方面的缺陷。从库设计者的角度讲，它给库设计者又带来了一把利器。从库使用者的角度讲，不动一兵一卒便可以获得“免费的”效率提升… 　在标准C++语言中，临时量（术语为右值，因其出现在赋值表达式的右边）可以被传给函数，但只能被接受为const &类型。这样函数便无法区分传给const &的是真实的右值还是常规变量。而且，由于类型为const &，函数也无法改变所传对象的值。C++0x将增加一种名为右值引用的新的引用类型，记作typename &&。这种类型可以被接受为非const值，从而允许改变其值。

- **左值与右值：**
  - C++ 11中引入的一个非常重要的概念就是右值引用。理解右值引用是学习“移动语义”（move semantics）的基础。而要理解右值引用，就必须先区分左值与右值。
  - 对左值和右值的一个最常见的误解是：等号左边的就是左值，等号右边的就是右值。
  - 左值和右值都是针对表达式而言的，左值是指表达式结束后依然存在的持久对象，右值是指表达式结束时就不再存在的临时对象。一个区分左值与右值的便捷方法是：看能不能对表达式取地址，如果能，则为左值，否则为右值。下面给出一些例子来进行说明。 
      ```cpp
      int a = 10;
      int b = 20;
      int* pFlag = &a;
      vector<<span style="line-height: 25px; color: rgb(0, 0, 255);">int> vctTemp;
      vctTemp.push_back(1);
      string str1 = "hello ";
      string str2 = "world";
      const int &m = 1;
      //请问，a，b, a+b, a++, ++a, pFlag, *pFlag, vctTemp[0], 100, string("hello"), str1, str1+str2, m分别是左值还是右值？
      ```
- **左值引用：** 区分清楚了左值与右值，我们再来看看左值引用。左值引用根据其修饰符的不同，可以分为非常量左值引用(**eg.1 double &r =i;**)和常量左值引用(**eg.1 const double &r =i;**)。非常量左值引用只能绑定到非常量左值，不能绑定到常量左值、非常量右值和常量右值。如果允许绑定到常量左值和常量右值，则非常量左值引用可以用于修改常量左值和常量右值，这明显违反了其常量的含义(**eg.1中就是出现了非常量左值引用绑定到常量右值的情况**)。如果允许绑定到非常量右值，则会导致非常危险的情况出现，因为非常量右值是一个临时对象，非常量左值引用可能会使用一个已经被销毁了的临时对象。常量左值引用可以绑定到所有类型的值，包括非常量左值、常量左值、非常量右值和常量右值。

- **区分非常量右值引用：**  可以看出，使用左值引用时，我们无法区分出绑定的是否是非常量右值的情况。那么，为什么要对非常量右值进行区分呢，区分出来了又有什么好处呢？这就牵涉到C++中一个著名的性能问题——拷贝临时对象。考虑下面的代码： 
    ```cpp
    vector<<span style="line-height: 25px; color: rgb(0, 0, 255);">int> GetAllScores(){
    vector<<span style="line-height: 25px; color: rgb(0, 0, 255);">int> vctTemp;
    vctTemp.push_back(90);
    vctTemp.push_back(95);
    returnvctTemp;
    }
    //当使用vector vctScore = GetAllScores()进行初始化时，实际上调用了三次构造函数。尽管有些编译器可以采用RVO（Return Value Optimization）来进行优化，但优化工作只在某些特定条件下才能进行。可以看到，上面很普通的一个函数调用，由于存在临时对象的拷贝，导致了额外的两次拷贝构造函数和析构函数的开销。当然，我们也可以修改函数的形式为void GetAllScores(vector &vctScore)，但这并不一定就是我们需要的形式。另外，考虑下面字符串的连接操作：
    strings1("hello")
    strings = s1 + "a"+ "b"+ "c"+ "d"+ "e";

    //在对s进行初始化时，会产生大量的临时对象，并涉及到大量字符串的拷贝操作，这显然会影响程序的效率和性能。怎么解决这个问题呢？如果我们能确定某个值是一个非常量右值（或者是一个以后不会再使用的左值），则我们在进行临时对象的拷贝时，可以不用拷贝实际的数据，而只是“窃取”指向实际数据的指针（类似于STL中的auto_ptr，会转移所有权）。C++ 11中引入的右值引用正好可用于标识一个非常量右值。C++ 11中用&表示左值引用，用&&表示右值引用，如：`int&&a = 10; `右值引用根据其修饰符的不同，也可以分为非常量右值引用和常量右值引用。
    //非常量右值引用只能绑定到非常量右值，不能绑定到非常量左值、常量左值和常量右值（VS2010 beta版中可以绑定到非常量左值和常量左值，但正式版中为了安全起见，已不允许）。如果允许绑定到非常量左值，则可能会错误地窃取一个持久对象的数据，而这是非常危险的；如果允许绑定到常量左值和常量右值，则非常量右值引用可以用于修改常量左值和常量右值，这明显违反了其常量的含义。
    //常量右值引用可以绑定到非常量右值和常量右值，不能绑定到非常量左值和常量左值（理由同上）。可以看出，使用左值引用时，我们无法区分出绑定的是否是非常量。
    ```


## C++有没有类C中的sprintf和sscanf函数似？

```cpp
#inlucde <sstream>
stringstream ss;
ss <<a <<b <<"=" <<d <<ends;
cout <<ss.str() <<endl;

#include "iostream"
#include "string"
#include "sstream"
using namespace std;
void main(){
  string a("12+");
  string b("12");
  int d=24;
  string c;

  //add by meteor007
  string e;
  ostringstream ost(e);
  ost<<d;

  c=a+b+"="+ost.str();
  
  cout<<c<<endl;
}
```
## 共用体Union&Struct

- 构造数据类型,也叫联合体用途：使几个不同类型的变量共占一段内存(相互覆盖)
- 结构体是一种构造数据类型用途：把不同类型的数据组合成一个整体; 
- 自定义数据结构体变量所占内存长度是各成员占的内存长度的总和。共同体变量所占内存长度是各最长的成员占的内存长度。
- 共同体每次只能存放哪个的一种！！共同体变量中起作用的成员是尊后一次存放的成员，在存入新的成员后原有的成员失去了作用！Structure 与 Union主要有以下区别:
1. struct和union都是由多个不同的数据类型成员组成, 但在任何同一时刻, union中只存放了一个被选中的成员, 而struct的所有成员都存在。在struct中，各成员都占有自己的内存空间，它们是同时存在的。一个struct变量的总长度等于所有成员长度之和。在Union中，所有成员不能同时占用它的内存空间，它们不能同时存在。Union变量的长度等于最长的成员的长度。
2. 对于union的不同成员赋值, 将会对其它成员重写, 原来成员的值就不存在了, 而对于struct的不同成员赋值是互不影响的。



## [什么时候应该使用宏定义？](https://www.zhihu.com/question/22608939/answer/21986257)

> 从宏的几种用法来说说宏的具体应用范围：
>
> **1、编译器参数和条件编译
>
> 2、定义常数
>
> 3、宏函数**
>
> 一个一个说：
>
> **1、编译器参数和条件编译**
>
> 这个没别的选择，绝大多数C编译器都是通过define某些宏（或者宏的值）来告知代码编译平台/硬件平台的。
>
> 同时，Makefile或者其它编译脚本希望传递某些编译参数给代码的几乎唯一方式就是宏，所以这是宏最重主要的用途。头文件里大量使用的#ifdef _XXXX_H_ 也是类似用途。
>
> 如果说普通宏函数什么的可以被替代的话，条件编译这些是很难被别的方法取代的。
>
> **2、定义常数**
>
> 肯定有人会说，用const更好，但const是强类型的，单独占用一个内存的，在某些场景下const的效果不如用宏好。
>
> 例子1：
>
> \#define MIN_VALUE -1
> const unsigned int x = -1;
> unsigned long long y;
>
> y = MIN_VALUE;
> y = x;
>
> 可能有人说我耍赖，数据类型不一致，但实际工程中，如果大量用到const，那么使用者很难一一确认const的类型是什么。
>
> 例子2：
>
> \#define STRING "Hello"
> const char * p = "Hello";
> char * n;
> n = p;
> n = STRING;
>
> 这个例子中，const赋值给非const变量，会有风险，编译器有警告，而用宏定义是没有问题的。如果const赋值给多个变量，各个变量共享同一段内存空间，如果是宏常数，通过修改编译器开关，可以保证各个变量使用不同的。
>
> **3、宏函数**
>
> 宏函数可以分为两类，一类是“普通”的宏函数，就是一小段跟普通函数差不多的代码，这种宏函数是完全可以被普通函数或者inline替代的。
>
> 一般来说，如果是“普通”但又复杂（代码较长）的宏函数，**多数商业代码里是不推荐使用的**，因为宏函数有展开风险。（比较著名的max宏传++参数的代码，可以自己在网上找到）
>
> 对于“普通”且较小的宏函数，在嵌入式行业特别常见，因为早期的时候编译器优化做的还不够好，嵌入式代码有些对性能有要求，所以有大量使用宏函数的地方，但现在正在被慢慢取代。
>
> 宏的另一类函数就是带“#”和“##”的宏，就比如这个东西：
>
> \#define ERRMSG(type,fmt,arg) \
>     do { \
>         if ((type##Debug) & DEBUG_LEVEL) \
>            printf("ERROR: "#type" - " fmt, arg) \
>     } while (FALSE)
>
> **C语言里没有模板**，可以大概理解为#和##类似于C++里的模板。这也是宏函数不可替代的部分。
>
> ---------总结---------
>
> 宏是有很多问题，但大多数宏的问题都表现在宏函数展开风险上，在我列举的其它应用中，宏的意义很重要，**并且不可取代**。如果是普通宏函数，**根据自己的需要，尽量使用普通函数替代。**



## [诸如 __u32 __u16 __u8 这类定义主要适用于什么情况？](https://www.zhihu.com/question/23223900/answer/23969589)'

> 驱动开发的原则：
>
> 能用__u32就最好用它，或者用u_int32_t之类的也可以，但不要直接用unsigned int等默认的数据类型。**目的是让别人明白，你这个变量占多大内存**。
>
> 原因：
>
> 你不能确定你的代码未来只在一个平台上运行，它可能会被移植到非Linux平台（确实有很多人这么做），它可能运行在不同的CPU平台，比如64位环境，非x86环境。
>
> 因为C语言中并**未明确规定int一定要占多少字节**，只是规定了long >= int >= short，所以__u32就是告诉别人，这变量占4字节。
>
> 同样的：__iomem也是能加就加，这样当你的驱动被别人维护的时候，别人会明白，这块内存是用于IO的，可DMA的，而不是paged-memory。
>
> 说到底，**这是一种良好的编码风格**，确实，不加这些东西，对于编译和运行来说，可能是无任何影响的，但是，不写注释的代码一样也对编译和运行无影响，**你敢一句注释都不写吗？
>
> **--------------------------------------
>
> 驱动中使用哪种类型最标准，这个没有正确答案，但建议是不使用C语言原始的数据类型（char/short/int/long），而是使用有明确字节大小的数据类型（u_int32_t/__u32/uint32_t/DWORD/UINT32均可）。保持代码风格的一致性即可。
>
> Linux社区提倡开放，并不严格限制开发者必须用哪种类型，一切都只是**建议使用**。
>
> 但有一种情况是例外的：开发标准库函数，比如自己实现strlen，那么返回值就必须是size_t，因为标准库是标准的。




##  AFTERWARDS
Today is 23^th^ Jul, 2020. I have a little envious about something, which is reason I continue to write these words. Emotion needs to be freed, such as her lived in my past memory , some hurt words in the past I couldn't forget. But unfortunatly nobody company with me. it actually make more effictive in hurt myself, which is reason why we want a pet like a cat or dog, beacuse we just would't like alone. Meanwhile, it likes not the first that  Even I could thought I cry for myself alone again one day in futurn. It sucks! Fu\*\*\*\*\* dame it! I waana leave !!!
