<center><font size =2 color=grey>CD:2020-01-12 01:29:05</font></center>


### 0x07 Circle

菱形

```c++
int main() {
	cout << "请输入半菱形高度n\n";
	int n = 0;
	cin >> n;
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * n + 1; j++) {
			if (abs(i - n) + abs(j - n) == n - 1) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
}
```

</br>



#### 8.4 堆栈

</br>

### 0x09 Newton's method

牛顿迭代，其又称为**牛顿-拉夫逊方法（Newton-Raphson method）**是牛顿在17世纪提出的一种在实数域和复数域上近似求解方程的方法。 多数方程不存在求根公式，因此求精确根非常困难，甚至不可能，从而寻找方程的近似根就显得特别重要。方法使用函数f(x)的泰勒级数的前面几项来寻找方程f(x) = 0的根。牛顿迭代法是求方程根的重要方法之一，其最大优点是在方程f(x) = 0的单根附近具有平方收敛，而且该法还可以用来求方程的重根、复根。

解非线性方程f(x)=0的牛顿法是把非线性方程线性化的一种近似方法。把f(x)在x0点附近展开成泰勒级数 f(x) = f(x0)+(x－x0)f'(x0)+(x－x0)^2*f''(x0)/2! +… 取其线性部分，作为非线性方程f(x) = 0的近似方程，即泰勒展开的前两项，则有f(x0)+f'(x0)(x－x0)=f(x)=0 设f'(x0)≠0则其解为x1=x0－f(x0)/f'(x0) 这样，得到牛顿法的一个迭代序列：x(n+1)=x(n)－f(x(n))/f'(x(n))。

迭代公式具体为Xn+1=(Xn+a/xn)/2 (n=0,1,2,3….;X0=a/2)，

C++实现：
```c++
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double a, x0, x;
	cout << "please input a:";
	cin >> a;
	x0 = a / 2;
	x = (x0 + a / x0) / 2;
	while (fabs(x - x0) > 0) {
		x0 = x;
		x = (x0 + a / x0) / 2;
		cout << x << endl;
		cout << x0 << endl;
	}
	cout << x << endl;
}
```

</br>

### 0x0a 二分查找

二分查找思想以及查找次数——它的主要思想就是在一个有序数列中取中间的数作为基点，比大小，看是从左找还是右面找

```c++
void binarysh(int p[], int len, int goal) {
	int start = 0, step = 1, mid;
	while (start <= len) {
		mid = (start + len) / 2;//取整操作后的整数是抛掉所有的小数部分（!=四舍五入）
		//如果是偶数（数组），以上操作取整后不会造成任何影响
		//如果是奇数（数组），那么中间数会前移一位，造成前小后大的操作
		//这样的话如果在中间数的后一位，关于这里取整后查找的次数就存在商榷（从你的全世界路过）
		//基于1 2 3 4 5 6 7 8 查找4得出
		if (goal == p[mid])break;
		else if (goal < p[mid])len = mid - 1;
		else if (goal > p[mid])start = mid + 1;//这里头加一和尾减一才可以交错开
		step++;
	}
	cout << mid << " " << step << endl;
}
```

</br>



<br/>

### 0x0c `String`类库 

有趣的一点是，string和字符数组有时是可以相互转化的

#### 6.1 输出操作（类切片）

```c++
char p[100];
cin>>p;
cout<<string(p,5);
cout<<(p,5);
```

然后就真的可以输出到那个位置就结束了（一共5个字符）

#### 6.2 对象连接

体现string优越的可能只有这个了

```c++
int main(){
	string a,b;
	cin>>a>>b;
	string c=a+b;
	cout<<c<<endl;
}
```

```c++
int main(){
	char a[]="dsafjuhjs";
	char b[]="sdjfhjshf";
	char *p=(char*)malloc(strlen(a)+strlen(b)+1);
	strcpy(p,a);
	strcat(p,b);
	cout<<p<<endl;
}
```

string的写法优化

```cpp
#include<iostream>
using namespace std;
int main() {
	char p[100];
	cin >> p;
	cout << string(p, 5);
}//类似于Python的切片操作，原理是字符数组和字符串是可以转化的
```

string和字符数组可以相互转化

```cpp
#include<iostream>
using namespace std;
int main() {
	string a;
	cin >> a;
	cout << a.c_str() << endl;
	//这样就可以从标准输入里输入任意长的字符串，并按const*char来使用。
	//如果要把一个char转换成string,可以使用strings(char*);
	cout << a;
}
```

`string`的大小是提前设定好的：

```cpp
#include <iostream>
using namespace std;
int main() {
	while (1) {
		string a;
		cin >> a;
		cout << sizeof(a);
	}
}
```

在我的VS里面`sizeof`大小永远是28.另外，找了一下`string`的函数，列在下面：

|                函数                |                         作用                          |
| :--------------------------------: | :---------------------------------------------------: |
|      `    string s(cstr)    `      |                 将C字符串作为s的初值                  |
| `  string s(chars,chars_len)     ` |     将C字符串前chars_len个字符作为字符串s的初值。     |
|     `  string s(num,c)      `      |            生成一个字符串，包含num个c字符             |
|     `    string s(beg,end)  `      |   以区间beg;end(不包含end)内的字符作为字符串s的初值   |
|        `    s.~string()   `        |                销毁所有字符，释放内存                 |
|       `    =,assign()     `        |                       赋以新值                        |
|          `  swap()      `          |                 交换两个字符串的内容                  |
|  `    +=,append(),push_back()   `  |                    在尾部添加字符                     |
|         `  insert()     `          |                       插入字符                        |
|          `   erase()   `           |                       删除字符                        |
|         `    clear()    `          |                     删除全部字符                      |
|        `    replace()    `         |                       替换字符                        |
|             `  +     `             |                      串联字符串                       |
|  `   ==,!=,>= ,=,compare()     `   |                      比较字符串                       |
|     `   size(),length()     `      |                     返回字符数量                      |
|         `  max_size()    `         |                返回字符的可能最大个数                 |
|         `  empty()      `          | 判断字符串是否为空，是空时返回ture，不是空时返回false |
|        ` capacity()      `         |              返回重新分配之前的字符容量               |
|        `    reserve()    `         |          保留一定量内存以容纳一定数量的字符           |
|         `   [ ], at()    `         |                     存取单一字符                      |
|       `    >>,getline()   `        |                   从stream读取某值                    |
|             `  <<    `             |                   将谋值写入stream                    |
|           `   copy()   `           |               将某值赋值为一个C_string                |
|          `   c_str()    `          |                 将内容以C_string返回                  |
|          `    data()   `           |               将内容以字符数组形式返回                |
|         `    substr()   `          |                   返回某个子字符串                    |
|       `  begin() end()    `        |                提供类似STL的迭代器支持                |
|      ` rbegin() rend()     `       |                      逆向迭代器                       |
|    `  y) get_allocator()     `     |                      返回配置器                       |

相对的，字符数组库：

|      函数       |           作用            |
| :-------------: | :-----------------------: |
| `   strlen   `  |       求字符串长度        |
| `  strcmp    `  |   比较2个字符串是否一样   |
|  `   strcat  `  |      字符串连接操作       |
| `   strcpy   `  |      字符串拷贝操作       |
| ` strncat     ` | 字符串连接操作(前n个字符) |
| `   strncpy   ` | 字符串拷贝操作(前n个字符) |
| `    strchr   ` |         查询字串          |
| `  strstr    `  |         查询子串          |
| `  strrev    `  |        反转字符串         |

<br/>

### 0x0e 统计字符
```c++
int main() {
	int sz, zm, kg, qt;
	sz = zm = kg = qt = 0;
	char p[1000];
	cin.getline(p, 1000);
	for (int i = 0; p[i] != '\0'; i++) {
		if (p[i] >= 'A' && p[i] <= 'Z' || p[i] >= 'a' && p[i] <= 'z') zm++;
		else if (p[i] >= '0' && p[i] <= '9') sz++;
		else if (p[i] == ' ') kg++;
		else qt++;
	}
	cout << zm << " " << sz << " " << kg << " " << qt;
}
```

升级版
#### 统计一个段落单词数量

```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string a, b, temp;
	cin >> a;
	cin.get();
	getline(cin, b);
	a.insert(a.begin(), ' ');
	b.insert(0, " ");
	transform(a.begin(), a.end(), a.begin(), ::toupper);
	transform(b.begin(), b.end(), b.begin(), ::toupper);
	int step = 0, m = 0, n = 0;
	m = b.find(a);
	int k = m;
	if (m == -1) {
		cout << "-1";
		return 0;
	}
	else {
		while (b.find(a, n) != -1) {
			step++;
			n = b.find(a, n) + 1;
		}
	}
	cout << step << " " << k;
}
```

###  0x0f 全排列 

```c++
int main(){
	int a[4];
	for (int i = 0; i < 4; i++) cin >> a[i];
	for (int i = 3; i >= 0; i--)
		for (int j = 0; j <= 3; j++)
			if (i != j)
				for (int k = 0; k <= 3; k++)
					if (k != i && k != j)
						for (int t = 0; t <= 3; t++)
							if (t != k && t != i && t != j)
								cout << a[j] << " " << a[k] << " " << a[t] << endl;
}
```

截取字符串

```c++
int main() {
	int N;
	cin >> N;
	cin.get();
	for (int i = 0; i < N; i++) {
		int step = 0;
		char p[1000];
		cin.getline(p, 1000);
		bool m = false;
		for (int i = 0; p[i] != '\0'; i++) {
			if (p[i] <= 'z' && p[i] >= 'a') m = true;
			else break;
			if (m) step++;
		}
		cout << step << endl;
	}
}
```

</br>

</br>



### 0x10 回文数 [·](https://baike.baidu.com/item/%E5%9B%9E%E6%96%87%E6%95%B0/1830170?fr=aladdin#5_3)

回文数的处理有两种：一种是全都转化为字符进行处理；一种是全都转化为数字处理。虽然说两者是等效的，但是方法不同，代码如下

其一：

```c++
int palindromeint(int a) {
	int k = a, sum = 0;
	while (a) {
		sum *= 10;
		sum += a % 10;
		a /= 10;
	}
	if (k == sum)return 1;
	else return 0;
}
```

其二：主函数用getline将字符数组取回来

```c++
#include<cstring>
int palindromechar(char p[]) {
	int i, len = strlen(p);
	for (i = 0; i < len / 2 + 1; i++)if (p[i] != p[len - i - 1]) return 0;
	return 1;
}
```

但是字符串就又是不一样的画风了，第一种方法（倒序）的话的方法就显得效率很低了···这里不再赘写。

</br>


### 0x11 递归

</br>

#### 4.3.1 阶乘

```c++
int lfh(int a) {
	if (a == 1)return 2;
	if (a > 1)return lfh(a - 1) * 2;
}
```

</br>

#### 4.3.2 多次输入输出

```c++
void lfh(int a) {
	cout << "ABC\n";
	if (a > 1) return lfh(a - 1);
}
```

</br>

#### 4.3.3 从1打印

```c++
int a;
int lfh(int m) {
	if (m <= a) {
		cout << m << " ";
		return lfh(m + 1);
	}
}
int main() {
	int m = 1;
	cin >> a;
	lfh(m);
}
```

</br>


### 0x12 栈

当我学习了栈之后写逆序的题我不太想用循环写了,手动滑稽

```c++
char p[1000];
cin.getline(p, 1000);
stack<char>m;
for (int i = 0; p[i] != '\0'; i++) m.push(p[i]);
while (!m.empty()) cout << m.top(), m.pop();
```
（回去重做字符替换1637，1685）（字符逆序用栈可以过去 为什么数组不可以？？？）

</br>


### 0x13 蛇矩

下面是从算法书里面找到的方法：利用每行的横纵坐标相加的和是定值来确定书写的格式

```c++
int p[50][50];
int main() {
	int N, i, j, y, k, step1 = 0, step2 = 0;
	cin >> N;
	k = N;
	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++)
			for (y = 0; y < k; y++) {
				if (i % 2) {
					if (y + j == i) p[j][y] = N--;
					if (N == 0) goto L;
				}
				else {
					if (y + j == i) p[y][j] = N--;
					if (N == 0) goto L;
				}
			}
	}
L: for (j = 0; p[0][j] != 0; j++)step1++;
	for (j = 0; p[j][0] != 0; j++)step2++;
	for (i = 0; ; i++) {
		for (j = 0; j < step2; j++) {
			for (y = 0; y < step1 - i; y++)
				if (p[j][y] != 0) cout << p[j][y] << " ";
			cout << endl;
		}
		return 0;
	}
}
```

发现自己现在还是爱用goto，期末考完试再优化一下自己写的代码吧······（用外层的break可以出去）

还有另外一种方法不用开数组直接暴力用`for`模拟，[参考题目](https://www.luogu.com.cn/problem/P1014)：

```cpp
#define _for(i,a,b) for(int i=(a);i<(b);++i)
int main() {
	int N, ii, i_x, i_y;
	cin >> N;
	for (ii = 1; (ii * (ii + 1)) / 2 < N; ii++);//ii行
	N -= ((ii - 1) * ii) / 2;
	if (ii % 2) {
		_for(i, 0, ii) {
			if ((N--) == 0)break;
			i_y = i;
			i_x = ii - 1 - i_y;
		}
	}
	else {
		_for(i, 0, ii) {
			if ((N--) == 0)break;			
			i_x = i;
			i_y = ii - 1 - i_x;
		}
	}
	cout << i_x + 1 << "/" << i_y + 1;
}
```



</br>

### 0x14 最长上升自序列(LIS算法)

```c++
char str[10001];
int main() {
	int T, i, j, len, ans;
	cin >> T;
	cin.get();
	while (T--) {
		cin.getline(str, 10001);
		len = strlen(str);
		ans = 0;
		for (i = 0; i < len; i++) {
			for (j = 0; j < ans; j++) {
				if (str[j] >= str[i]) {
					str[j] = str[i];
					break;
				}
			}
			if (j == ans) {
				str[j] = str[i];
				ans++;
			}
		}
		cout << ans << endl;
	}
}
/*
abklmnnopqrstcdefg 2
abklmnopqrstcdefg
abcdefgpqrstcdefg
abcdefgpqrsttcdefg
*/
```

补充：字符串的修改（

### 0x15 动态规划

```c++
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int p[20][20];
int main() {
	char p1[20];
	char p2[20];
	cin.getline(p1, 20);
	cin.getline(p2, 20);
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	for (int i = 0; i < len1; i++)p[0][i] = i;
	for (int i = 0; i < len2; i++)p[i][0] = i;
	for (int j = 0; j < len2; j++) {
		for (int i = 0; i < len1; i++) {
			if (j != 0 && i != 0) p[j][i] = min(min(p[j - 1][i] + 1, p[j][i - 1] + 1), p[j - 1][i - 1] + ((p1[i - 1] == p2[j - 1]) ? 0 : 1));
		}//这里最好不要写成if(i&&j)要不然会有的地方赋不了值。（？？？？？？）
	}
	for (int j = 0; j < len2; j++) {
		for (int i = 0; i < len1; i++) cout << p[j][i] << " ";//注意行列应用在字符串先后中的应用
		cout << "\n";
	}
	cout << p[len2 - 1][len1 - 1];//注意不可以解决首尾字母相同的情况
}
```

</br>

### Aferword

转自系其他学生的曲子：😄（09/22 22:40）

```cpp
#include<iostream>
#include<windows.h>
using namespace std;
enum fy {
	d1 = 262, d1_ = 277, d2 = 294, d2_ = 311, d3 = 330, d4 = 349, d5 = 392, d5_ = 415,
	d6 = 440, d6_ = 466, d7 = 494, z1 = 523, z1_ = 554, z2 = 578, z2_ = 622, z3 = 659,
	z4 = 698, z4_ = 740, z5 = 784, z5_ = 831, z6 = 880, z6_ = 932, z7 = 988, g1 = 1046,
	g1_ = 1109, g2 = 1175, g2_ = 1245, g3 = 1318, g4 = 1397, g4_ = 1480,
	g5 = 1568, g5_ = 1661, g6 = 1760, g6_ = 1865, g7 = 1976, yaya = 0
};
struct yf {
	enum fy s;
	int t;
};
int main() {
	struct yf a[1000] = {
	{z6,50},{z7,50},{g1,150},{z7,50},{g1,100}, //5
	{g3,100},{z7,300},{z3,100},{z6,150},{z5,50}, //10
	{z6,100},{g1,100},{z5,300},{z2,50}, //14
	{z3,50},{z4,150},{z3,50},{z4,50},{g1,150}, //19
	{z3,150},{z2,50},{z3,50},{g1,150},{z7,150}, //24
	{z4_,50},{z4_,100},{z7,100},{z7,200},{z6,50}, //29
	{z7,50},{g1,150},{z7,50},{g1,100},{g3,100}, //34
	{z7,200},{z3,100},{z6,150}, //37
	{z5,50},{z6,100},{g1,100},{z5,300},{z3,100},{z4,100},{g1,50}, //44
	{z7,150},{g1,100},{g2,100}, //47
	{g3,50},{g1,150},{g1,50},{z7,50},{z6,100},{z7,100},{z5_,100}, //54
	{z6,300},{g1,50},{g2,50}, //57
	{g3,150},{g2,50},{g3,100},{g5,100},{g2,300},{z5,100}, //63
	{g1,150},{z7,50},{g1,100},{g3,100},{g3,300},{z6,50},{z7,50},{g1,150}, //71
	{z7,50},{g1,100},{g2,100},{g1,150},{z5,50}, //76
	{z5,200},{g4,100},{g3,100},{g2,100},{g1,100}, //81
	{g3,400},{yaya,50},{g3,50},{g6,200},{g5,100},{g5,100},{g3,50}, //88
	{g2,50},{g1,100},{yaya,50},{g1,50},{g2,100},{g1,50},{g2,100},{g5,100}, //96
	{g3,200},{yaya,50},{g3,50},{g6,200},{g5,200},{g3,50},{g2,50}, //103
	{g1,200},{yaya,50},{g1,50},{g2,100},{g1,50},{g2,100},{z7,100}, //110
	{z6,200},{yaya,100},{z6,50},{z7,50},{z6,500}
	};
	struct yf* atop;
	atop = a;
	int n = 194;
	while (n--) {
		Beep(atop->s, atop->t * 5);
		atop++;
	}
	return 0;
}
```

