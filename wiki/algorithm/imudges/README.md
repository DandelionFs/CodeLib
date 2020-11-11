### Flag

+ 1175
+ 1214
+ 1429
+ 1741
+ 1977
+ 1334



完数

```
#include<iostream>
using namespace std;
void lfh(int a)
{
	int  i;
	for (i = 1; i < a; i++)
	{
		if (a % i == 0) cout << i << " ";
	}
}
int main()
{
	int p[100];
	int i, m = 0, a = 2, sum = 0, N, j=0, d;
	cin >> N;
	if (N >=6)
	{
		while (a <= N)
		{
			if (a != 1)
			{
				for (i = 1; i < a; i++)
				{
					if (a % i == 0) sum += i;
				}
				if (sum == a)
				{
					p[j] = a;
					j++;											
				}
				sum = 0;
			}
			a++;
		}
		
		for (d = 0; d <= j-1; d++)
		{
	     	cout << p[d] << " its factors are ";
			lfh(p[d]);
			cout << endl;
		}
	}
}




#include<iostream>
using namespace std;
void lfh(int a)
{
	int  i;
	for (i = 2; i < a; i++)
	{
		if (a % i == 0) cout << "+" << i;
	}
}
int main()
{
	int p[100];
	int i, m = 0, a = 2, sum = 0, N, j = 0, d;
	N = 1000;
	if (N >= 6)
	{
		while (a <= N)
		{
			if (a != 1)
			{
				for (i = 1; i < a; i++)
				{
					if (a % i == 0) sum += i;
				}
				if (sum == a)
				{
					p[j] = a;
					j++;
				}
				sum = 0;
			}
			a++;
		}
		cout << "1=1" << endl;
		for (d = 0; d <= j - 1; d++)
		{
			cout << p[d] << "=1";
			lfh(p[d]);
			cout << endl;
		}
	}
}
```



```cpp

#include <stdio.h>
int main()
{
    int n;
    int a[59000]; ///确保保存最终运算结果的数组足够大
     int digit = 1; ///当前位数
     int temp;   ///阶乘的任一元素与a[]某位数的乘积结果
     int i, j, carry; ///carry：进位数
 
    
    while(scanf("%d",&n)) 
    {
        digit = 1;
         a[0] = 1;   ///将第一位数先初始化为1
 
    for ( i=2; i<=n; i++ )  ///阶乘开始，阶乘元素从2开始；
    {
         for( j=1, carry=0;  j<=digit; j++ )///当前元素依次与a[]中每一位上的数相乘
        {                   ///digit为当前相乘结果的位数；
            temp = a[j-1] * i + carry; ///当前元素依次与a[]中某位相乘的结果（加上进位）
             ///j-1 为当前第几位
              a[j-1] = temp % 10; ///更新当前a[]位的值；
              carry = temp / 10; ///看是否有进位
         }
        while(carry)
        {    ///如果有进位
              a[digit] = carry % 10; ///新加一位，添加信息。
              digit++;   ///位数增1
            carry = carry / 10; ///看还能不能进位
         }
    }
    //printf("n ! = ");    //显示结果
    for(j = digit; j >=1;j--)///从最高位开始输出
    {
        printf("%d",a[j-1]);
    }
    printf("\n");
    }
   
    return 0;
}


#include<iostream>
using namespace std;
int main()
{
	while (1)
	{
		int N, j;
		cin >> N;
		int p[1000] = { 0 };//控制后面的进位问题
		p[0] = 1;	
		for (int i = 1; i <= N; i++)
		{
			for (j = 0; p[j]!='\0'; j++)
			{
				p[j] *= i;
				if (p[j] > 10)
				{
					p[j + 1] += p[j]/10;
					p[j] =p[j] % 10;				
				}
			}
		}
		for (; p[j] == 0; j--);
		for (; j >= 0; j--)cout << p[j];
	}
	
}
```

+ 2176

```cpp
#include<iostream>
using namespace std;
int main()
{
	char p[1000];
	int a[1000], i, j, sum;
	cin.getline(p, 1000);
	for (i = 0, j = 0; p[i] != '\0'; i++)
	{
		if (p[i] != ' ')
		{
			a[j] = p[i];
			j++;
		}
	}
	a[j] = '\0';
	sum = j;
	int q = 0, dc = 0, su=0;
	for (int i = 0; i < j; i++)
	{
		if (a[i] < a[i + 1])  dc++;
		su = ((2 + dc) * dc) / 2;
		sum += su;
		if (a[i] < a[i + 1])
	}
	
	/*for (int m = 0; m < j - 1; m++)
	{
		if (a[m] < a[m + 1])sum++;
		
	}
	cout << sum;*/
}
```



打印

```cpp
   int N;
    cin>>N;
    for (int i = N - 1; i >= 0; i++) cout << " ";
    cout << "*\n";
    for(int i=2;i<N;i++){
        for (int j = N - i; j >= 0; j--) cout << " ";
        cout << "*";
        for (int j = 1; j <=i-1; j--) cout << " ";
    }
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout << "请输入半菱形高度n\n" ;
    int n;
    cin >> n;
    for (int i = 0; i <=  2*n ; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (abs(i - n) + abs(j - n) == n-1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}
```



集合

```cpp
#include<iostream>
using namespace std;
int main()
{
	int num;
	num = 10;
	num =  num << 2;
	 cout << num;
}
```





代码

```cpp

/*
#include<cstdlib>
#include<fstream>
using namespace std;
int main(int argc, char* argv[])
{
	const int N = 1024;
	const char f[] = "in.txt";
	int line = 0;
	char buf[N];啊

	ifstream inf(f, ios_base::in);

	while (inf.getline(buf, N))
	{
		line++;
	}
	inf.close();
}





#include<iostream>
#include<string>
using namespace std;
int main()
{
	char s[10][256], ss[256];
	int i, j;
	for (i = 0; i < 10; i++) scanf("%s", s[i]); //输入：要求每个字符串字符个数小于255
	for (i = 0; i < 9; i++) //排序
		for (j = i + 1; j < 10)
			if (strcmp(s[i], s[j]) > 0) { strcpy(ss, s[i]); strcpy(s[i], s[j]); strcpy(s[j], ss); }
	for (i = 0; i < 10; i++) printf("%s\n", s[i]); //输出显示
	return 0;
}



#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[5][50], t[50];
	int i, j;
	for (i = 0; i < 5; i++)
	{
		cin >> s[i];

	}
	for (i = 1; i < 5; i++)
	{
		for (i = 0; j <= 4 - i; j++)
		{
			if (strcmp(s[j], s[i + 1]) > 0)
			{
				strcpy(t, s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j + 1], t);
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		cout << s[i] << endl;
	}
}
```



链表

```cpp
/*#include<iostream>
using namespace std;
struct node {
	int data;			//数据域
	node *next;  //指针域
};
int main()
{
	int n;
	node* head = new node;
	node* s = head, * p;
	while (cin >> n && n)
	{
		p = new node;
		p->data = n;
		s->next = p;
		p->next = NULL;
		s = p;
	}
	s = head->next;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	return 0;
}
*/
```









```cpp
#include<iostream>
using namespace std;
int main()
{
	int N, n,z;
	int steps = 0;
	int outs = 0;
	cin >> N; //总人数
	cin >> z;//间隔数
	bool* p = new bool[N];
	for (int i = 0; i < N; i++) p[i] = true;
	while (outs < N - 1)
	{
		for (int i = 0; i < N; i++)
		{
			if (p[i] != false) steps++;
			if (steps % z == 0)
			{
				if (p[i] != false)
				{
					p[i] = false;
					outs += 1;
					steps = 0;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) if (p[i] != false)cout << i + 1;
}

//输出序号


#include<iostream>
using namespace std;
int main()
{
	int N, n, z,j;
	int steps = 0;
	int outs = 0;
	cin >> N; //总人数
	cin >> z;//间隔数
	if (N % 2 == 1)
	{
		bool* p = new bool[N];
		for (int i = 0; i < N; i++) p[i] = true;
		while (outs < N)
		{
			for (int i = 0; i < N; i++)
			{

				if (p[i] != false) steps++;
				if (steps % z == 0)
				{
					if (p[i] != false)
					{
						p[i] = false;
						p[i + 1] = false;
						outs += 2;
						steps = 0;
						cout << i + 1 << " " << i + 2 << " ";
					}
				}
			}
		}
	}
	else {
		bool* p = new bool[N];
		for (int i = 0; i < N; i++) p[i] = true;
		while (outs < N)
		{
			for (int i = 0; i < N; i++)
			{

				if (p[i] != false) steps++;
				if (steps % z == 0)
				{
					if (p[i] != false&&i!=N-2)
					{
						p[i] = false;
						p[i + 1] = false;
						outs += 2;
						steps = 0;
						cout << i + 1 << " " << i + 2 << " ";
					}
					else {
						if (p[i] != false && i == N - 2)
						{
							p[i] = false;
							for (j = 0; j < N; j++)if (p[j] == true)break;
							p[j] = false;
							outs += 2;
							steps = 0;
							cout << i + 1 << " " << j + 1 << " ";
						}
					}
				}									
			}
		}
	}
	
}
```





栈进制转化

```cpp
#include <iostream>
#include <malloc.h>
#include <cstring>
#include <string>
 
#define size 100
#define addsize 50
 
using namespace std;
 
typedef struct {
	int *base;
	int *top;
	int stack_size;
}SqStack;
 
//初始化栈
void InitStack(SqStack &S) {
	S.base = (int*)malloc(size * sizeof(int));
	if (!S.base) {
		cout << "初始化失败!" << endl;
		exit(0);
	}
	S.top = S.base;
	S.stack_size = size;
}
 
//入栈
bool PushStack(SqStack &S, int elem) {
	//先要判断是否满栈
	if (S.top - S.base >= S.stack_size) {
		S.base = (int*)realloc(S.base, (size + addsize) * sizeof(int));
		if (!S.base) {
			return false;
		}
		S.top = S.base + S.stack_size;
		S.stack_size += addsize;
	}
	*S.top++ = elem;
	return true;
}
 
//出栈
bool Popstack(SqStack &S, int &elem) {
	if (S.base == S.top) {
		cout << "该栈为空，出栈失败!" << endl;
		return false;
	}
	elem = *--S.top;
	return true;
}
 
//判断是否为空栈
bool StackEmpty(SqStack S) {
	if (S.base == S.top)
		return true;
	return false;
}
 
//进制转化的函数
void conversion() {
	int ten, N, elem;
	//用个字母来记录超过9的数
	char a = 'A';
	SqStack S;
	InitStack(S);
	cout << "输入你要转化的数（十进制）和你要转化成（N）进制的数(中间用空格分开)：";
	cin >> ten >> N;
	elem = ten;
	while (ten) {
		PushStack(S, ten%N);
		ten /= N;
	}
	cout << "10进制数"<<elem<<"转化的" << N << "进制数如下:" << endl;
	while (!StackEmpty(S)) {
		Popstack(S, elem);
		if (elem > 9)
			printf("%c", a + elem - 10);
		else 
			cout << elem ;
	}
}
int main(){
	conversion();
	return 0;
}
————————————————
版权声明：本文为CSDN博主「anzunming」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_41743392/article/details/83866441
```





```cpp
自首书
    #include<iostream>
using namespace std;
int lfh(int a,int b)//分位的次数
{
	int c=1;
	int g=0;
	while (c <= a)
	{
		g = g * 10;
		g = b % 10;



		c++;
	}
}
int main()
{
	const int a = 200000;
	int i=0,sum=1,k;
	int s;
	while (i<=20000)
	{
		if (i < 100)
		{
			sum = i * i;
			if (sum == i) cout << i<<"  ";
			else if((sum%10)==i) cout << i << "  ";
		}
		else if (i >= 100 && i < 1000)
		{
			k = i;
			int m, n;
			m = k % 10;
			n = (k / 10) % 10;
			s = m * 10 + n;
			sum = s * s;
			if (sum == i)cout << i << "  ";
		}
		else if (i >= 1000 && i < 10000)
		{

		}
		else if (i >= 10000 && i < 200000)
		{

		}
		sum = 0;
		i++;
	}

}
```

