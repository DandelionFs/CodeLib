# Number System

## 十进制 -> N进制

### 除N取余法

如十进制整数10转化为2进制的过程

```
10/2 = 5余0
5/2 = 2余1
2/2 = 1余0
1/2 = 0余1 
```
即 `1010`.

### 降幂法

将十进制整数不断减去与该整数最接近的N进制整数的位权，如果够减m次则对应N进制位上的数字为m(m<N)，否则为0。得到的差值作为新的被减数进行下一次计算，直到被减数为0.

```
30-82=66
66-82=2
2-8（不够减）
2-1=1
1-1=1
```

即`202`.

## 十进制->小数转换

### 乘N取整法

十进制的0.54转换为16进制的过程

```cpp
0.55*16=8.8 --8
0.8*16=12.8 --12(C)
0.8*16=12.8 --12(C)
0.8*16=12.8 --12(C)
...
```

由于不能被精确的转换，我们可以只取前4位，为`0.8CCC`.

<font color="red">一般的十进制数转换为N进制数，分别转换整数和小数部分。</font>

#### 倒序处理 -- 数组

<font color="red">取模(%)出来的是从个位开始，也就是说必须从后面开始输出。</font>然而, 不倒序处理无法处理进位。

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
void conversionnum(int m, int j, char p[]) {//m是原来的进制，j是转换进制，p是原来的数
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


#### 倒序处理模板类 -- 栈

栈天然具有倒序处理的能力, 所以自然很方便的可以实现, 但是因为STL里面本身不具备这样的模板函数, 所以需要自己去实现.

```cpp
const int MaxStackSize=10;//栈最大容量
template<class T>
class SeqStack {
    T StackList[MaxStackSize];
    int top;
public:
    SeqStack();
    bool IsEmpty();//判断栈空
    bool IsFull() ;//判断栈满
    void Push(const T x);
    T Pop();//出栈
    void Clear() ;//置栈空
    void Conversion(int M, int N);//进制转换，并输出结果
}; //SeqStack
template<class T>SeqStack<T>::SeqStack(){top=-1;}
template<class T>bool SeqStack<T>::IsEmpty(){
    if(top==-1) return true;
    else return false;
}
template<class T>bool SeqStack<T>::IsFull(){
    if(top==MaxStackSize-1) return true;
    else return false;
}
template<class T>void SeqStack<T>::Push(const T x){
    if(IsFull()) return ;
    else StackList[++top]=x;
}
template<class T>T SeqStack<T>::Pop(){
    if(IsEmpty()) exit(1);
    return StackList[top--];
}
template<class T>void SeqStack<T>::Clear(){
    top=-1;
}
template<class T>void SeqStack<T>::Conversion(int M,int N){
    SeqStack<T>p;
    T temp;
    while(M){
        p.Push(M%N);
        M/=N;
    }
    while(!p.IsEmpty()){
        temp=p.Pop();
        cout<<temp;
    }
    cout<<endl;
}
```
