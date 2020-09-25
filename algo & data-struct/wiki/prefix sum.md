#### Prefix Sum[^1]

前缀最大和是一种预处理，能降低查询的时间复杂度。

ADDRESS: https://www.luogu.com.cn/problem/U53525 ;一道练练手的题目. 

思路就是 把数组输入和计算并行处理, 利用b[i]=a[i]+b[i-1];  <font color=red>前提是两个数组第一项相等. </font>

```cpp
#include<iostream>
#define ll long long
using namespace std;
ll data[10000];
ll datasum[10000];
int main(){
    int i,ii=0,k;
    cin>>i;
    k=i;
    while(i--){
        cin>>data[ii];
        if(!ii) datasum[ii]=data[ii];
        if(ii>0) datasum[ii]=datasum[ii-1]+data[ii];
        ii++;
    }
    for(int i=0;i<k;i++)cout<<datasum[i]<<" ";
}  
```



#### 2D Prefix Sum

二维矩阵的前缀最大和, 线性代数, 劝退劝退......



[^1]:https://oi-wiki.org/basic/prefix-sum/