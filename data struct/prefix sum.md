# Prefix Sum(前缀最大和)
THX FOR:
- [前缀和 & 差分](https://oi-wiki.org/basic/prefix-sum/)
- [容斥原理-CNWIKIPEDIA](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%AE%B9%E5%8E%9F%E7%90%86)
- [洛谷练手题目-U53525 前缀和（例题）](https://www.luogu.com.cn/problem/U53525)
- [P1387 最大正方形](https://www.luogu.com.cn/problem/P1387)

## Inclusion and Exclusion(容斥原理/排容原理)
- 离散数学/组合数学中的容斥定理
![](./img/Inclusion_and_Exclusion.png)
- 概率论
![](./img/Inclusion_and_Exclusion_2.png)

Tip: 上下两个领域其实都是一个原理, 对吧.在 **[素数计算]** 里用 **埃拉托斯特尼筛法** 计算素数的个数是一个道理.

## 1D PREFIX SUM(一维)

前缀最大和是一种预处理，能降低查询的时间复杂度。

**[思路]** 把数组输入和计算并行处理, 利用b[i]=a[i]+b[i-1]; 需要注意的是 <font color=red>两个数组第一项相等. </font>

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

## 2D Prefix Sum(二维)

二维矩阵的前缀最大和,  牵扯到数表矩阵的使用, 酌情观看.

主要定义:
![](./img/Inclusion_and_Exclusion_4.png)

前缀和递推计算规则如下, 常应用计算子矩阵的和:
![](./img/Inclusion_and_Exclusion_3.png)

