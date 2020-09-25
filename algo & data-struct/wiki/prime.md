# Prime Num

素数历史比较悠久了，我还是挖出来写了一写，发现和第一次写差不太多诶!!!(bug满天飞，想哭woc)······
在不考虑时间复杂度的时候（测试数据不大）可以直接从 2 暴力循环到 该数-1，好处是不用动脑子，简单暴力；以下提供优化计算速度和时间复杂度的方法：

<font color ="red">**源于证明（所有 ≤√m 的数都不能整除 m，则＞√m的数也一定不能整除m。O(n*log(n))**</font>

```cpp
int prime(int a){
if(a>1){
    for(int i=2;i<=sqrt(a);i++)
        if(!(a%i)) return 0;
    return 1;
    }
else return 0;
}
//for(i=2;i<=sqrt(a)+1;i++)||for(i=2;i < sqrt(a)+1;i++)这两种写法1会是个问题？
//看上去不错，但其实很不经济。我们知道，我们的算法如果写成线性算法，也就是O(n)，已经算是不错了，但是最好的是O(Log(n))的算法，这是一个对数级的算法，著名的二分取中（Binary Search）正是O(Log(n))的算法。通常来说，O(Log(n))的算法都是以排除法做为手段的。所以，找质数的算法完全可以采用排除法的方式。
```

* <font color ="red">**筛取质数的方法——埃拉托斯特尼筛法(埃氏筛 O(n(log(logn)))**</font>

    > 埃拉托斯特尼筛法，简称埃氏筛或爱氏筛，是一种由希腊数学家埃拉托斯特尼所提 出的一种简单检定素数的算法。
    > 给出要筛选的范围N，找出∨N以内的素数 p1,p2,p3...pk，不断用素数去筛。如果一次筛完这个序列中最大数小于等于最后一个标出质数的平方，那么剩下来的数都是质数，否则返回重新筛选。

     简单模拟这个过程如下 :

伪代码：

```cpp
  Input: an integer n > 1
  Let A be an array of Boolean values, indexed by integers 2 to n,
  initially all set to true.
   for i = 2, 3, 4, ..., not exceeding  ∨n:
    if A[i] is true:
      for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n :
        A[j] := false
  Output: all i such that A[i] is true.
```

代码示例（Wikipedia）：

```cpp
  #include <vector>
  auto eratosthenes(int upperbound){
      std::vector<bool> flag(upperbound+1, true);
  	flag[0]=flag[1]=false; //exclude 0 and 1
  	
  	for(int i=2; i<=upperbound; ++i)
  	    if(flag[i]) // if i is prime number
  		    for(int j=i*i; j<=upperbound; j+=i)
  			    flag[j] = false;
  	return flag
  }
```

最终实现：

```cpp
  const int MAXN = 100000001;
  int p[MAXN];//这里避免使用了memset，合数是1，素数是0
  void Prime(int end) {
  	p[0] = p[1] = 1;
  	for (int i = 2; i < sqrt(end); i++) {
  		if (p[i])continue;
  		for (int j = i * 2; j < end; j += i)p[j] = 1;
  	}
  }
```

* **实际应用的算法**：实际应用中，我们通常不会使用上述的两种算法，因为那是理论学院派的算法。实际中的算法是，我**把质数事先就计算好，放在一个文件中，然后在程序启动时（注意是在启动时读这个文件，而不是运行时每调用一次就读一次文件），读取这个文件，然后打印出来就可以了**。如果需要查找的话，二分查找或是hash表查找将会获得巨大的性能提升。当然，这样的方法对于空间来说比前面两个都要消耗得大，但是你可以有O(log(n))或是O(1)的时间复杂度。对应现实中很多事情不是计算出来的，而是事先写在文件中的。

* <font color ="red">**线性筛法  O(n)**</font>
    原理：对于任意合数，必定可以有最小质因子乘以最大因子的分解方式。因此，对于每个合数，只要用最大因子筛一遍，枚举时只要枚举最小质因子即可

    （运用到欧拉函数的知识，这里还没有学习，看了好半天也没有看懂，先在这里立下一个小小的Flog）[·](https://www.wikii.cc/zh-cn/%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0)   [·](https://coolshell.cn/articles/3738.html)   [·](https://www.cnblogs.com/grubbyskyer/p/3852421.html) 

    



