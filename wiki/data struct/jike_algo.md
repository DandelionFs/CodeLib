# Jike

极客大学网课.

## 数组、链表、跳表

**Array**

```cpp
int a[100];    //Java/C++
list = []      //Python
let x=[1,2,3]  //JavaScript
```

- 泛化语言，任何一个单元类型都可以放进去
- 内存管理器(Memory Controller)——删除/插入
- o(1)+o(n)=o(n+1/2);

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



- **Deque(Double-End Queue)(双端队列)**
  - vector 线程安全


- [Java 的 PriorityQueue 文档](http://docs.oracle.com/javase/10/docs/api/java/util/PriorityQueue.html)
- [Java 的 Stack 源码](http://developer.classpath.org/doc/java/util/Stack-source.html)
- [Java 的 Queue 源码](http://fuseyism.com/classpath/doc/java/util/Queue-source.html)
- [Python 的 heapq](https://docs.python.org/2/library/heapq.html)
- [高性能的 container 库](https://docs.python.org/2/library/collections.html)


















- 断点继传法
- 对照阅读法
- 教学视频法
- 书看不懂时，不硬看，扫清障碍，咱再来……
- 多找几本书，对照着看……
- 先看教学视频入门，再看书




## 泛型递归、树的递归

- 递归 -> 盗梦空间
  - 向下进入到不同的梦境, 再带着不一样的状态回到原来的这层
  - 声音(参数)同步回到上一层
  - 每一层都是一份拷贝
- 要点:
  - 不要人肉进行递归（最大误区）
  - 找到最近最简方法，将其拆解成可重复解决的问题（重复子问题）
  - 数学归纳法思维, n = 1 时成立, 且 n 成立, n+1 也成立
    - 类似于放鞭炮, 保证第一个会炸, 后一个会接着前一个炸, 那么结论成立
- template:
```python
# Python
def recursion(level, param1, param2, ...): 
    # recursion terminator 
    if level > MAX_LEVEL: 
	   process_result 
	   return 

    # process logic in current level 
    process(level, data...) 

    # drill down 
    self.recursion(level + 1, p1, ...) 

    # reverse the current level status if needed
```
```java

// Java
public void recur(int level, int param) { 


  // terminator 
  if (level > MAX_LEVEL) { 
    // process result 
    return; 
  }


  // process current logic 
  process(level, param); 


  // drill down 
  recur( level: level + 1, newParam); 
  // restore current status 
```

```cpp
// C/C++
void recursion(int level, int param) { 
  // recursion terminator
  if (level > MAX_LEVEL) { 
    // process result 
    return ; 
  }

  // process current logic 
  process(level, param);

  // drill down 
  recursion(level + 1, param);

  // reverse the current level status if needed
}
```
```javascript
// JavaScript
const recursion = (level, params) =>{
   // recursion terminator
   if(level > MAX_LEVEL){
     process_result
     return 
   }
   // process current level
   process(level, params)
   //drill down
   recursion(level+1, params)
   //clean current level status if needed

}
```

- 习题
  - [爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)
    - mutual exclusive: 互斥状况
    - complete exhaustive: 完全详尽
  - [括号生成](https://leetcode-cn.com/problems/generate-parentheses/)
    ```cpp
    //List usage
    list<string>s1;
    list<string>::iterator it;
    it=s1.begin();
    s1.insert(it,"sdasdas");
    for(it=s1.begin();it!=s1.end();++it){
        cout<<' '<<*it;
    }
    ```
    ```cpp
    void _generate(int, int, const std::string);

    std::list<std::string> generateParenthesis(int n) {
      _generate(0, 2 * n, "");
      return {};
    }

    void _generate(int level, int max, const std::string s) { //自顶向下编程.
        //terminator
        if(level>=max) {
            std::cout<<s<<"\n";
            return;
        }
      //process currnet logic : lefe, right
      //down is here.

      //drill down
      _generate(level+1, max, s+"(");
      _generate(level+1, max, s+")");

      //reverse state
    }
    int main(){
        generateParenthesis(3);
    }
    ```
    ```cpp

    void _generate(int, int, int, const std::string);

    std::list<std::string>result;
    std::list<std::string>::iterator it;
    std::list<std::string> generateParenthesis(int n) {

        _generate(-1, 0, n, "");
        return result;
    }

    void _generate(int right, int left ,int n, const std::string s) { //自顶向下编程.
        //terminator
        if(right == n && left == n ) {
    //        std::cout<<s<<"\n";
            it=result.begin();
            result.insert(it,s);
            return;
        }
        //process currnet logic : lefe, right

        //drill down
        if(left < n)
            _generate(right,left+0, n, s+"(");
        if(right < left)
            _generate(right+0,left, n, s+")");


        //reverse state
    }

    int main(){
        generateParenthesis(2);
        for(it=result.begin();it!=result.end();++it)
            std::cout<<*it<<"\n";
    }
    ```
- https://leetcode-cn.com/problems/invert-binary-tree/description/
- https://leetcode-cn.com/problems/validate-binary-search-tree
- https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
- https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
- https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
- **每日一课**: [如何优雅地计算斐波那契数列](https://time.geekbang.org/dailylesson/detail/100028406)
- **作业**
  - https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
  - https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
  - https://leetcode-cn.com/problems/combinations/
  - https://leetcode-cn.com/problems/permutations/
  - https://leetcode-cn.com/problems/permutations-ii/


