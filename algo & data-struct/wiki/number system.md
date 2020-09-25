# Number System

## 十进制->N进制

**[除N取余法]**：如十进制整数10转化为2进制的过程为：

```cpp
10/2 = 5余0
5/2 = 2余1
2/2 = 1余0
1/2 = 0余1 
```

所以二进制形式为`1010`.

**[降幂法]：**将十进制整数不断减去与该整数最接近的N进制整数的位权，如果够减m次则对应N进制位上的数字为m(m<N)，否则为0。得到的差值作为新的被减数进行下一次计算，直到被减数为0.

```cpp
30-82=66
66-82=2
2-8（不够减）
2-1=1
1-1=1
```

所以对应的8进制整数为`202`.

## 十进制->小数转换

**[乘N取整法]**：十进制的0.54转换为16进制的过程为：

```cpp
0.55*16=8.8 --8
0.8*16=12.8 --12(C)
0.8*16=12.8 --12(C)
0.8*16=12.8 --12(C)
...
```

由于不能被精确的转换，我们可以只取前4位，为`0.8CCC`.

<font color="red">一般的十进制数转换为N进制数，分别转换整数和小数部分。</font>

**[注]：** **倒序处理！**

这是十进制转化二进制!%N处理没有进位的数字，然后相当于转化后的数字移位，转化的数字再从个位开始的操作。但是从十进制到其他进制的时候就画风不一样了。<font color="red">%出来的是个位开始，也就是说必须从后面开始输出。</font>

简单来说，不倒序处理无法处理进位。

```cpp
#include<iostream>
using namespace std;
int main(){
  int m,i;
  char p[1000];
  cin>>m;
  for(i=0;m!=0;i++){
      p[i]=(m%2)+'0';
      m=m/2;
  }
    p[i]='\0';
    for(int j=i-1;j>=0;j--)cout<<p[j];	
}//这里采取倒序输出是因为开始处理的位数是个位，所以最后输出的位数也因该是倒序输出，关于这类问题，首先着手的是自己处理的位数是哪位！是关于移位处理的进制转换问题，
```

这是二进制转化十进制的操作！

```cpp
#include<iostream>
#include<cstring>
using namespace std;
int main(){
  int sum=0;
  char p[1000];
  cin.getline(p,1000);
  int len=strlen(p);
  for(int i=0;i<len;i++){
      sum*=2;
      sum+=p[i]-'0'; 
  }
    cout<<sum<<endl;
}//getline读取后的数组从最大位置开始，然后迭代算到个位结束。
```

</br>

std::bitset（转2进制），std::oct（转8进制），std::dec （转10进制），std::hex（转16进制）。另外发现的一个有趣的点是VS内置iostream是支持strlen的操作的，但是不不通用真是鸡肋的说·····

```c++
#include<cstring>
void conversionnum(int m, int j, char p[]) {//m是原来的进制，j是转换进制，p是原来的数组
	int i, sum = 0;
	char z[1000];
	for (int i = 0; i < strlen(p); i++) {
		sum *= m;
		if (p[i] >= 'A' && p[i] <= 'Z')sum += p[i] - 'A' + 10;
		else if (p[i] >= '0' && p[i] <= '9')sum += p[i] - '0';
	}//将读回来的字符数组转化成为对应十进制的数字（可不可以一步从m到j转化）
	i = 0;
	if (sum > j) {
		for (i = 0; sum != 0; i++) {
			if ((sum % j) <= 9)z[i] = (sum % j) + '0';
			else z[i] = (sum % j) + 'A' - 10;
			sum = sum / j;
		}
	}//对应的进制转换（貌似不用提前讨论转换后是不是比十进制要大···以前写复杂了）
	else z[i++] = sum + '0';
	z[i] = '\0';
	for (int j = i - 1; j >= 0; j--) cout << z[j];
	cout << endl;
}
```

</br>