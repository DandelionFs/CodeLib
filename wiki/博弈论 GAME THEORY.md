# 博弈论 GAME THEORY

- 专门研究多个独立个体之间的竞争行为（对抗行为）。在某些中文书籍里面，它又被称作“对策论 or 赛局理论”。

**THX FOR:**

- [博弈论入门教程——从基本概念到具体案例](http://feedproxy.google.com/~r/programthink/~3/C3hVY1iB-DU/Game-Theory.html)

## 历史 HISTORY

- [约翰·冯·诺伊曼](https://zh.wikipedia.org/wiki/约翰·冯·诺伊曼)（John von Neumann）
    - 《[博弈论与经济行为](https://docs.google.com/document/d/1rV8OFkInke6MJul6uKd8utuDViBJbph11PmpvNMIyCU/)》（“Theory of Games and Economic Behavior”）
    - [路德维希·冯·米塞斯](https://zh.wikipedia.org/wiki/路德维希·冯·米塞斯)是**摩根斯坦**的博士生导师

## 类型

- **合作博弈（cooperative game） VS 非合作博弈（non-cooperative game）**
    - 区别在 某种**外部约束力**与**博弈过程的其它参与者**。

- **同时博弈（simultaneous game） VS 顺序博弈（sequential game）**
    - 是否**已知其它参与者的行为信息**
    - 棋牌类游戏都属于这种

- **零和博弈（zero-sum game） VS 非零和博弈, 变和博弈（non-zero-sum game）**
    - 区别在参与各方的利益总和为**常量**还是**变量**
    - 变和博弈存在可以使得参与各方利益最大的可能, 所以产生了合作.

- **非重复博弈, 单次博弈（non-repeated game） VS 重复博弈, 多次博弈（repeated game）**
    - 博弈的次数



## 收益矩阵( normal-form) VS 决策树(extensive-form)

- 描述博弈过程
    - 收益矩阵特指“静态博弈”（同时博弈）, 类似离散数学的关系矩阵.`1` 表示赢；`-1` 表示输；`0` 表示平局。
    - 决策树（decision tree） 两者均可.

## 策略 ＆ 策略集合

- 决策选项（move） VS 策略（strategy）
    - 策略（strategy）是决策选项（move）的总和.

- 策略集合（strategy set）: 所有可能的策略

## 纯策略（pure strategy） VS 混合策略（mixed strategy）VS 完全混合策略（totally mixed strategy）

- 是否总是【固定选择】“策略集合”中的某【一个】策略



## 支配策略（优势策略）

- 策略之间的【支配性】(优先性)(dominated by)
- 支配策略/优势策略（dominant strategy）: 某个策略能够支配【所有】其它策略
- 强支配策略（strictly dominant strategy） VS 弱支配策略（weakly dominant strategy）: 评价策略的好坏.

- 支配策略 VS 制胜策略（winning strategy）
    - “制胜策略”也称“必胜策略”，它通常只用于“零和博弈”
    - “制胜策略”肯定是“支配策略”（最起码是“弱支配策略”）；但“支配策略”不一定是“制胜策略”。

- 实例：（二战中）新几内亚的航路作战

- 如何发现“支配策略”？
    - 逐步删除【被】支配的策略（“Iterated Elimination of Strictly Dominated Strategies”，简称 IESDS）。

- **罕见性**: 只存在有极其简单的博弈

- **乏味性**
    - 为啥绝大部分棋牌类游戏都【没有】“支配策略”。

## 最小最大定理(Minimax)

- 在最坏情况下最小化损失。

- **举例：动态博弈——切蛋糕博弈**

## 反向归纳法(backward induction)

- 决策树的展开一直推演到【最后一步】（也就是决策树的叶子节点）。此时你就可以看清双方在最后一步各自的最优选择；然后再反向回推到第一步。
- **局限性: **充分的信息
- **重复博弈中的“囚徒困境”**
- **海盗博弈（海盗分金问题）**

## 纳什均衡（Nash equilibrium）

- 在多人的“非合作博弈”中，如果每个博弈者都无法【单方面】改善自己的境地，此时的局面称作“纳什均衡”。
    - “纳什均衡”的前提是【非合作博弈】。不要望文生义，把“非合作博弈”误解为“没有合作的博弈”。请参见本文开头章节对“博弈类型”的解释。
    - 【单方面】指的是——在其他博弈者都没有改变策略的情况下，自己改变策略。

- **稳定性**: 如果每个博弈者都足够理性，他们都【不愿意】主动改变当前的策略。

- **实例：囚徒困境**

- **对“纳什均衡”的【误解】**
    - 把“纳什均衡”误解为“各方利益总和最大化”。
    - 认为“纳什均衡点”是唯一的。

- **局限性**
    - 非建设性
    - 依赖于非常非常多的约束条件

## 博弈中的【信息】因素

- **“perfect information” VS “imperfect information”**
    - 是否知道已经发生的每个事件
    - 大部分棋类游戏（围棋、象棋、跳棋...）属于前者；某些军棋游戏（只能看到己方的棋子）属于后者；大部分扑克游戏（比如：桥牌、拱猪...）属于后者。

- **“complete information” VS “incomplete information”**
    - 是否每个博弈者的特征都是公开的
    - 【棋牌类游戏】属于“complete information”;【拍卖】则属于“incomplete information”。

- **贝叶斯博弈（Bayesian game）＆ 贝叶斯纳什均衡（Bayesian Nash equilibrium）**
    - 概率分析，从而猜测其它对手的特征。

- **实例分析：FQ VS GFW**

## 博弈中的【心理】因素

- **换位思考**: 通过某些复杂的博弈游戏，进行练习。

- **早期经济学的“理性人假设”**
    - 设定市场的行为主体全都是充分理性的

- **装疯策略**
    - 北朝鲜的金三胖

## “博弈论”对其它领域的影响

- **对【经济学理论】的影响**
- **对【金融、投资、营销】的影响**

- **对【军事＆外交】的影响**

- **对【生物学】的影响**