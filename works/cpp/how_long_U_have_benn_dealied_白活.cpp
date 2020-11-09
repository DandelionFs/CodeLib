#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);++i)
const int N = 10000000;
struct TS {
	int a, b, c;
};
inline bool cmp(const TS& t1, const TS&t2) {
	if (t1.a != t2.a)return t1.a < t2.a;
	if (t1.b != t2.b)return t1.b < t2.b;
	return t1.c < t2.c;
}
int cmp4qsort(const void* a, const void* b) {
	TS* t1 = (TS*)a, * t2 = (TS*)b;
	if (t1->a != t2->a)return t1->a - t2->a;
	if (t1->b != t2->b)return t1->b - t2->b;
	return t1->c - t2->c;
}
struct cmpFunctor {
	inline bool operator()(const TS& t1, const TS& t2) {
		if (t1.a != t2.a)return t1.a < t2.a;
		if (t1.b != t2.b)return t1.b < t2.b;
		return t1.c < t2.c;
	}
};
TS tss[N];
void genData() {
	_for(i, 0, N) {
		tss[i].a = rand();
		tss[i].b = rand();
		tss[i].c = rand();
	}
}
int main() {
	srand(time(NULL));

	genData();
	clock_t start = clock();
	sort(tss, tss + N, cmp);
	printf("sort by functor pointer: %ld\n", clock() - start);

	genData();
	start = clock();
	sort(tss, tss + N, cmpFunctor());
	printf("sort by functor: %ld\n", clock() - start);

	genData();
	start = clock();
	qsort(tss, N, sizeof(TS), cmp4qsort);
	printf("qsort by functor pointer: %ld\n", clock() - start);

	return 0;
}

/*
这里剖析一下自己写的程序：
1. 我是一个笨比，在确定读取y/n后，我居然把如此简单的程序写错了······我已经不想和自己说些什么了，我TM的。<font size=4 color="red">值得注意的是，如果是连续的东西（特别是时间直接的连贯的事物），首先一点确定一个好计算的短点，将之前的先计算完，再整理好计算的部分，所谓掐头去尾就是这个道理</font>
2. 之前还犯过一个错误就是获取不到输入的是y还是n（这里模拟Linux）具体的问题就是永远获取的是空格,写法如下：
    ```c++
    int main() {
    	char w;
    	cin >> w;
    	cout << p << endl;
    	if (p == 'y')cout << "1";
    	else cout << "0";
    }
    ```
    原因是因为：

    所以应该改为：

    ```c++
    int main() {
    	char p=cin.get();
    	cout << p << endl;
    	if (p == 'y')cout << "1";
    	else cout << "0";
    }
    ```

    但是应用于上面的程序的时候不知道为什么读取的时候不会停留，而是直接跳过，我猜测是直接读取的上面的一个换行符所导致的结果，所以中间加了两个`cin.get()；`

3. 第三点，我查阅了一下获取系统时间的方法（应该是调用window的API接口实现的）
    ```c++
    #include<iostream>
    #include<cstdio>
    #include <windows.h>
    using namespace std;
    int main()
    {
    	SYSTEMTIME st;
    	GetLocalTime(&st);
    	printf("%d-%02d-%02d %02d:%02d:%02d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    	printf("\nAnd it's the %d day of a week.", st.wDayOfWeek);
    	system("pause");
    	return 0;
    }
    ```
    这里顺便整合一下关于C++的时间函数：

**<font size =4>后记</font>**：
- 编译问题：曾经卡了我好几个晚上的编译问题今天找到了解答，应该是自己过去的程序大部分在VS里面编写没有导出写exe的缘故，我不会导出！！随后想起DevCpp自动编译出来一个Exe有了灵感，自己脸了一个项目，加上`.ico`.的图片，自动编译运行就OK了，可以项目设置里面设置自定义的ico图标，过程如下：
    1. 使用文本编辑器编写程序，并将其保存到文件中，这个文件就是程序的源代码。
    2. 编译源代码。这意味着运行一个程序，将源代码翻译为主机使用的内部语言-机器语言。包含了翻译后的程序的文件就是程序的目标代码（object code）
    3. 将目标代码与其他代码链接起来。例如，C++程序通常使用库 C+库包含一系列计算机例程（被称为函数）的目标代码，这些函数可以执行诸如在屏幕上显示信息或计算平方根等任务。链接指的是将目标代码同使用的函数的目标代码以及一些标准的启动代码（startup code）组合起来，生成程序的运行阶段版本。包含该最终产品的文件被称为可执行代码。
- `.0`的文件打开是16位的16进制数，应该是我的的编码方式和国外的对不上，出现了乱码表示的格式，如图

*/

