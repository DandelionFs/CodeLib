### 数组、链表、跳表

**Array**

```cpp
int a[100];    //Java/C++
list = []      //Python
let x=[1,2,3]  //JavaScript
```

泛化语言，任何一个单元类型都可以放进去

内存管理器(Memory Controller)——删除/插入

o(1)+o(n)=o(n+1/2);

java 自动内存回收机制。

```cpp
prepend		o(1)
append 		o(1)
lookup		o(1)
insert 		o(n)
delete		o(n)
```

**Linked List**

Head Tail 

java的next指针是引用

双向链表

循环链表

```java
Entry<T>
```

java的链表是双向链表

slide

```cpp
prepend 	o(1)//增加
append 		o(1)
lookup		o(n)
insert 		o(1)
delete		o(1)
```
**Skip LIst**

Redis

升维思想——空间换时间

添加第一级索引

添加二级索引

增加log2n个级索引

64（2^6）个元素(log2n-1)

```
n/2、n/4、n/8、第k级索引结点的个数就是n/（2k）
假设索引有h级，最高级的索引有2个结点。n/（2h）=2，从而求得h=log2（n）-1
```

维护成本高

n*(1-1/2^n)<n



LRU Cache - Linked list

https://www.jianshu.com/p/b1ab4a170c3c 

https://leetcode-cn.com/problems/Iru-cache



Redis - Skip - List 

https://redisbook.readthedocs.io/en/latest/internal-datastruct/skiplist.html 

https://www.zhihu.com/question/20202931



> 给的建议也是让我们快速的练习，而不是从零到有，我觉得不好，但是又想不出下文。



### 练习

1. https://leetcode-cn.com/problems/container-with-most-water/
2. https://leetcode-cn.com/problems/move-zeroes/
3. https://leetcode-cn.com/problems/climbing-stairs/
4. https://leetcode-cn.com/problems/3sum/（高频老题）



### Stack&Queue 

Stack：先入后出；添加、删除皆为o（1）

Queue：先入先出；添加、删除皆为o（1）

 查询加哈希表加速



**Deque:Double-End Queue（双端队列）**





断点继传法
对照阅读法
教学视频法
书看不懂时，不硬看，扫清障碍，咱再来……
多找几本书，对照着看……
先看教学视频入门，再看书




