## ALGO

# ALGO WIKI

这里写一些感谢的链接以及各种数据结构与算法的概况

THX FOR:
- IMU
- Ncode


![](./img/data-struct.png)

如上图所示, 以下总结各数据结构的优胜劣汰：

| 数据结构 |                            优点                            |                         缺点                         |
| :------: | :--------------------------------------------------------: | :--------------------------------------------------: |
|   数组   |                           插入快                           |      查找慢，删除慢，大小固定，只能存储单一元素      |
| 有序数组 |                      比无须数组查询快                      |      插入慢，删除慢，大小固定，只能存储单一元素      |
|    栈    |                   提供后进先出的存取方式                   |                    存取其他项很慢                    |
|   队列   |            提供先进先出的存取方式插入快，删除快            |                    存取其他项很慢                    |
|   链表   |           如果树是平衡的，则查找、插入、删除都快           |                        查找慢                        |
|  二叉树  |         查找、删除、插入都快。树总是平衡的算法复杂         |                     删除算法复杂                     |
|  红黑树  | 查找、删除、插入都快。树总是平衡的。类似的树对磁盘存储有效 |                   算法复杂算法复杂                   |
| 2-3-4树  |                   如果关键字已知则存取极                   | 删除慢，如果不知道关键字存取慢，对存储空间使用不充分 |
|  哈希表  |             快插入、删除快，对最大数据项存取快             |                  对其他数据项存取慢                  |
|    堆    |                       对现实世界建模                       |                    有些算法慢且身                    |



## 一、链表
### 1.1 单向链表
单向链表固然强大，但是**缺点**在于：在单链表中只能通过一个结点的引用访问其后续结点，而无法直接访问其前驱结点，要在单链表中找到某个结点的前驱结点，必须从链表的首结点出发依次向后寻找，但是需要Ο(n)时间。 

### 1.2 双向链表/循环链表
扩展单链表结点结构很简单，在单链表结点结构中新增加一个域，该域用于指向结点的直接前驱结点即可。


## TOC
- 预处理
  - 前缀最大和

### 特征 
1. 有穷性：一个算法必须总是在执行有限步之后结束。
2. 确定性：算法的每一个步骤必须是确切地定义的。
3. 输入：一个算法有0个或多个输入。
4. 输出：-个算法有1个或多个输出。
5. 可行性：算法中要执行的每一个计算步骤都是可以在有限时间内完成的.

### 尺度
1. 正确性
2. 可读性
3. 健壮性( 容错性 ) -- 对不规范数据的处理能力( 竞赛中不考虑 )
4. 时间复杂度
    1. floor(x)=[x] (<=x的最大整数)  ceil(x)=[x] (>=x 的最小整数)
    2. 大O表示法
        O（1）和输入数据规模无关
        O（logn）-般我们默认底数是2，不是2也没关系，用换底公式之后就是常数了
        O（Vn）
        O（n）线性时间复杂度
        O（n^2）
        O（n^3）.）.....
        O（C^n）C是一个常数，指数级
        O（n！）阶乘级
5. 空间复杂度
    1. int 32位二进制 2^31-1=2147483647(+/-都会溢出)
    2. long long 
        1. double : 符号位1+指数位11+小数位52
            0.3*2取二进制?? -- 精度丢失
        2. |a-b|<=10^-9 / 10\^-6
    3. 512M/32位=128\*1024\*1024
    4. 1s -> 3-5s
6. 空间复杂度
    1. int 32位二进制:  符号位+数值位


## CONTENT

+ **OI** （Olympiad in Informatics，信息学奥林匹克竞赛）: 在中国起源于 1984 年，五大高中学科竞赛[^1]之一[^2]
  + 官方地址: [www.noi.cn](http://www.noi.cn/)
+ **ICPC/ACM** （International Collegiate Programming Contest, 国际大学生程序设计竞赛）: 最具影响力的大学生计算机竞赛[^3]
  + 官方地址: [icpc.baylor.edu](https://icpc.baylor.edu/)
+ **CCPC**（China Collegiate Programming Contest）中国大学生程序设计竞赛
  + 官方地址: [ccpc.io](https://ccpc.io/)

## WIKI LINK

+ **CTF Wiki**: http://ctf-wiki.github.io/
+ **OI-Wiki**: https://oi-wiki.org/

## OJ JUDGEMENT

1. [ACdream](http://acdream.info/)
2. [Aizu](http://judge.u-aizu.ac.jp/)
3. [CFGym](http://codeforces.com/gyms)
4. [CSU](http://acm.csu.edu.cn/)
5. [CodeForces](http://codeforces.com/)
6. [FZU](http://acm.fzu.edu.cn/)
7. [HDU](http://acm.hdu.edu.cn/)
8. [HUST](http://acm.hust.edu.cn/)
9. [HYSBZ](http://www.lydsy.com/JudgeOnline/)
10. [LOCAL](http://citel.bjtu.edu.cn/boj)
11. [LightOJ](http://lightoj.com/)
12. [NBUT](https://ac.2333.moe/)
13. [POJ](http://poj.org/)
14. [SCU](http://acm.scu.edu.cn/)
15. [SGU](http://acm.sgu.ru/)
16. [SPOJ](http://www.spoj.com/)
17. [Tyvj](http://www.tyvj.cn/)
18. [UESTC](http://acm.uestc.edu.cn/)
19. [UESTC-old](http://acm.uestc.edu.cn/)
20. [URAL](http://acm.timus.ru/)
21. [UVA](https://uva.onlinejudge.org/)
22. [UVALive](https://icpcarchive.ecs.baylor.edu/)
23. [ZOJ](http://acm.zju.edu.cn/onlinejudge/)  
24. [ZTrening](http://www.codah.club/)




## ACM SoftwareProcesse

### SE/Software Processes

#### Topics

**[Core-Tier1]（必须掌握的核心知识：第 1 级）**
• Systems level considerations, i.e., the interaction of software with its intended environment (crossreference IAS/Secure Software Engineering)
• Introduction to software process models (e.g., waterfall, incremental, agile)
o Activities within software lifecycles
• Programming in the large vs. individual programming

**[Core-Tier2]（必须掌握的核心知识：第 2 级）**
• Evaluation of software process models

[Elective]（选修部分）
• Software quality concepts
• Process improvement
• Software process capability maturity models
• Software process measurements

#### Learning Outcomes

**[Core-Tier1]**

1. Describe how software can interact with and participate in various systems including information management, embedded, process control, and communications systems.[Familiarity]

2. Describe the relative advantages and disadvantages among several major process models (e.g., waterfall, iterative, and agile). [Familiarity]

3. Describe the different practices that are key components of various process models. [Familiarity]

4. Differentiate among the phases of software development. [Familiarity]

5. Describe how programming in the large differs from individual efforts with respect to understanding a large code base, code reading, understanding builds, and understanding context of changes. [Familiarity]

**[Core-Tier2]**

6. Explain the concept of a software lifecycle and provide an example, illustrating its phases including the deliverables that are produced. [Familiarity]

7. Compare several common process models with respect to their value for development of particular classes of software systems taking into account issues such as requirement stability, size, and non-unctional characteristics. [Usage] 

**[Elective]**

8. Define software quality and describe the role of quality assurance activities in the software process.[Familiarity]

9. Describe the intent and fundamental similarities among process improvement approaches. [Familiarity]

10. Compare several process improvement models such as CMM, CMMI, CQI, Plan-Do-Check-Act, or ISO9000. [Assessment]

11. Assess a development effort and recommend potential changes by participating in process improvement (using a model such as PSP) or engaging in a project retrospective. [Usage]

12. Explain the role of process maturity models in process improvement. [Familiarity]

13. Describe several process metrics for assessing and controlling a project. [Familiarity]

14. Use project metrics to describe the current state of a project. [Usage]


## ACM总结的18个计算机科学关键领域

| 缩写 | 关键知识领域（英文名称） | 说明 |
| :----: | :------------------------: | :----: |
|AL| Algorithms and Complexity |算法与复杂度|
|AR| Architecture and Organization| 体系结构与组织|
|CN| Computational Science| 计算科学|
|DS| Discrete Structures| 离散结构|
|GV| Graphics and Visualization| 图形与可视化|
|HCI| Human-Computer Interaction| 人机交互|
|IAS |Information Assurance and Security| 信息安全|
|IM |Information Management| 信息管理|
|IS| Intelligent Systems| 智能系统|
|NC |Networking and Communication |网络与通讯|
|OS |Operating Systems |操作系统|
|PBD| Platform-based Development| 基于特定平台的开发|
|PD |Parallel and Distributed Computing| 并行与分布式计算|
|PL |Programming Languages |编程语言|
|SDF| Software Development Fundamentals| 软件开发基础|
|SE| Software Engineering |软件工程|
|SF | Systems Fundamentals| 系统基础|
|SP| Social Issues and Professional Practice| 社会性主题与职业实践|
http://www.acm.org/education/curricula-recommendations

《Computer Science Curricula-2013》


不要试图做你认为做不到的事情, 而当你感到自闭的时候. 那恰巧正是你意识到要发生改变的时候.





## ACM的《Computer Science Curricula-2013》





## 衡量计算机科学知识的掌握程度

> What do you know about this ?
> What do you know how to do ?
> Why would you do that ?

当你主要在第N层工作时，需要对第N-1和N+1层下功夫，通常就足以应付日常的工作和学习任务了







[1] :全国高中数学联赛、全国中学生物理竞赛复赛、中国化学奥林匹克竞赛(初赛)、全国中学生生物学联赛、全国青少年信息学奥林匹克联赛
[2] :https://oi-wiki.org/contest/oi/
[3] :https://oi-wiki.org/contest/icpc/
