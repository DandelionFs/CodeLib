### Preface

写代码, 后有些想法. 一为作业, 二来是为了记录.

因为结构体数组和类数组的流程图基本相似

### 功能概述

#### 信息存储

**[效果/方式] :**  在系统开始时候, 进行信息的初始化, 包括学生信息, 老师信息, 班级信息, 课程信息的读入和写入. 而在退出系统的时候进行四个文件的全部写入. 

```cpp
#include<fstream>
int SystemInit(){
    ifstream infile;
    infile.open("./data/CourseInfo.in"); //初始化课程信息
    for(int i=0;i<Cnum;i++) 
        infile>>course[i];
    infile.close();
}        
```

#### 登录/注册 功能

**[效果] :** 开头先进行注册或者登录, 注册成功后即可登录; 四部分代码全部具有初始密码, 具体为学生初始为"1", 老师为"2".如果是初次登录. 可以使用初始密码或者预设密码进行登录, 而再次登录则预设密码失效.

**[方式]** : 通过单个`int`变量计数器来判断该用户是不是初次登录.

```cpp
void Judge(){
...
    if(nowUsr==1){//学生
		nowStu=SuSearchStID(account);
		if(nowStu==-1)
			nowStu=SuSearchStName(account);
		if(nowStu==-1){
			cout<<"[Error] 没有找到你输入的账户，请检查输入后再进行登录\n";
			continue; 
		}
		StInitPassW="1";
		if(!StuInit && password==StInitPassW)flag=1;
		if(StuInit && password==StuAcc[nowStu].PassW)flag=1;
    }
    if(flag){
    	cout<<"恭喜你, 登录成功"<<endl;
    	PAUSE();
        return true;
     } 
}
```

#### 初始化学生信息

**[效果]** : 学生名字初始化为"DFS100","DFS101","DFS102"......; 学号信息对应初始化为"100", "101", "102"等效果.

**[方式]** : 采用了 `sstring`里面的`stringstream`来进行学生信息(学号)的初始化, 相关代码如下:

```cpp
#include<sstream>
St::Student(){
    string Temp;
    stringstream ss;
    ss<<StInitTemp;
    Temp=ss.str();
    ID=Temp;
    StInitTemp++;
    Name="DFS"+Temp;
}
```

#### 学生管理课程

##### 选课

**[效果]** : 学生选择对应序号的课程.

**[方式]** : 在学生类中的 标记位数组 赋值为1, 表示这个位置的课程已经被学生选定. 如果之前没有选择这门课程, 选定课程的数量加1.

```cpp
void ChooseCourse(int a){//进行已有的课程的选择
    int num, flag;//flag查询课程下的学生是否选了这个课程
    char order;
    cin>>num;
    ...
    num=SearchRealCourseNum(num);//对序号进行再处理获得正确的数组下标
    if(!(StuAcc[a].course[num-1]))StuAcc[a].CCourse++;
    StuAcc[a].course[num-1]++;
    if(StuAcc[a].course[num-1]==2)
        cout<<"[Tip]: 你已经选择过该课程,请核对后再次选择!\n";
	...
}
```



##### 退选/更换 课程

**[效果]** : 学生按序号退掉或者更换自己的课程.

**[方式]** : 在学生类中的 标记位数组 赋值为0, 表示这个位置的课程已经被学生删除, 如果之前确实选择过这门课程, 选定课程数量减1.如果是更换课程, 需要再选择一门课程, 并且选定课程数不变.

```cpp
void ChangeStCourse(int a){//换课
    int order, insteadnum, flag;
    char corder;
    SearchCourse(a);
    cout<<"请输入你想换的课程序号:\n";
    cin>>order;
    ...
    cout<<"输入你要选择的课程(取消请按-1):\n"; 
    cin>>insteadnum;
    ...
    insteadnum--;
    insteadnum=SearchRealCourseNum(insteadnum);
    StuAcc[a].course[flag]=0;
	StuAcc[a].course[insteadnum]++;
	...
    return;
}

void DeleteCCourse(int a){//根据学生数组打印学生课程; 拿课程去查学生, 选课的时候存上编号.
    int order,flag;
    char corder;
    cin>>order;
    ...
    order--;
    order=SearchRealCourseNum(order);
    if(StuAcc[a].course[order]) StuAcc[a].CCourse--;
    StuAcc[a].course[order]=0;
    ChangeCourseStu(a,order);
    ...
}
```

#### 老师管理课程

##### 加课

**[效果]** : 输入加入的课程, 如果已经存在就重新输入, 如果不存在就加入成功.

**[方式]** : 如果课程不存在在原来的数组中, 容错数组标记向后位移一位.存在则重新输入.

```cpp
void SuAddGrade(){//增加班级及选课情况
    cout<<"请输入想要增加的班级:\n";
    cin>>ErrGradecourse[AddGrade];
    if(IsGradeEx(ErrGradecourse[AddGrade])==-1){
        AddGrade++;
        cout<<"增加班级成功!";
    }
    else {
        cout<<"添加失败, 即将退出\n";
    }
}
```

##### 删课

**[效果]** :  输入删除课程的序号, 如果输入合法则删除, 否则重新输入.

**[方式]** : 在课程的标记数组中赋值对应位置的值为1, 表示课程已经被销毁.

```cpp
void SuDelGrade(){//删除班级
    int step;
    SuShowGradeInfo();
    cout<<"请输入想要删除班级的序号\n";
    cin>>step;
    step--;
    step=FoundRealGrade(step);
    ...
    SuShowGradeInfo();
    cin>>step;
    step--;
    step=FoundRealGrade(step);
    SuMoveStGrade(step);
    GradeErr[step]=1;//标记班级已经删除
    cout<<"删除班级成功\n";
}
```



#### 老师管理班级

##### 增加班级

**[效果]** : 输入增加课程的序号, 如果输入合法则增加, 否则重新输入.

**[方式]** : 原数组标记结束位置后移一位, 写入课程, 不合法就继续

```cpp

```





##### 删除班级

**[效果]** : 输入删除班级的序号, 如果输入合法则删除, 否则重新输入.

**[方式]** : 



#### 老师查看所有课程下的学生

**[效果]** : 查看所有课程下选择该课程的学生

**[方式]** : 因为第一种方式耦合读较高, 代码维护量成倍上升, 所以采用第二种方式.

+ 通过预处理在学生选择的时候就将下标存入一个二维数组, 后期访问二维数组即可, **复杂度O(n)**(n表示学生的选课操作, 基本等同于学生的数量)
+ 通过遍历打印课程, 再在学生中遍历查找是否选择了该课程, **遍历查找可以用位数组降低复杂度到O(1)**, 所以整体的**复杂度是O(n\*n)=O(n^2^)**

```cpp
void SuShowCourseAStudent(){//课程列表以及学生的信息
    int step=1;
    for(int i =0;i<Cnum;i++){
        if(SuDeleteCourse[i])
            continue;//课程已删除，返回主函数, 继续下一个
        cout<<"["<<step++<<"]"<<'\t'<<course[i]<<'\t';
        for(int j=0;j<CourseStuSum[i][0];j++){
            if(CourseStuSum[i][j+1]!=-1) //或者改成j<=以及j=1
                cout<<StuAcc[CourseStuSum[i][j+1]].name<<' ';
        }
        cout<<endl;
    }
    if(!Flag_ErrCourse) return;
    for(int j=0;j<Flag_ErrCourse;j++){
        cout<<"["<<step++<<"]"<<'\t'<<ErrCourse[j]<<'\t';
        for(int k=1;k<=CourseStuSum[j+Cnum][0];k++){
            if(CourseStuSum[j+Cnum][k]!=-1)
                cout<<StuAcc[CourseStuSum[Cnum+j][k]].name<<' ';
        }
        cout<<endl;
    }
}
```



#### 老师查看所有的学生的选课信息

**[效果]** : 查看所有用户的个人资料和选课信息.

**[方式]** : 重用学生查询自己选课信息的函数.

```cpp
void SuShowAllStINfo(){ //展示所有学生的选课信息
    cout<<"名字\t"<<"学号\t"<<"班级\t"<<"选课数量\t"<<"选择的课程\n";
    for(int i=0;i<Studentnum;i++){
        cout<<StuAcc[i].name<<'\t'<<StuAcc[i].ID<<'\t'<<StuAcc[i].Grade<<'\t'<<StuAcc[i].CCourse<<'\t'<<'\t';
        for(int j=0 ;j<Cnum+Flag_ErrCourse;j++)
            if(StuAcc[i].course[j] && !SuDeleteCourse[j]){
                if(j<Cnum)
                    cout<<course[j]<<'\t';
                if(j>Cnum)
                    cout<<ErrCourse[j-Cnum]<<'\t';
            }
        cout<<endl;
    }
}
```



#### 老师查询学生信息

**[效果]** : 根据学号或者姓名对学生进行查找, 因为学生有查重机制, 所以保证每一个学生的唯一性, 查找到后可以对学生进行学生本人的操作.

**[方式]** : 遍历学生的名字和学号, 直到找到该学生的位置为止, 然后可以和学生代码共用, 可以简化教师的封装复杂度, 高效利用重复代码.

```cpp
void SuSearchManStCourse(){//查询指定学生选课情况
    ...
    while(key){
        cout<< "查询到的学生是"<<StuAcc[flag].name<< "他的选课情况如下:\n";
        SearchCourse(flag);
        do{
            cout<<endl<<"请选择现在的操作:\n";
            PrintManStu();
            cin>>order;
            system("reset");
            if(order<-1||order>5)cout<<"请输入有效的命令以进行下一步操作\n";
        }while(order<-1||order>5);
        system("reset");
        if(order==-1) return;
        if(order==1) DeleteCCourse(flag);//删除选课信息
        if(order==2) SearchCourse(flag);//展示选课信息
        if(order==3) SwapCourse(flag);//更换课程信息
        if(order==4) ChangeSelfInfo(flag);//改变自己的资料
        if(order==5) SuChangeGradeInfo(flag);//管理员改变学生资料
    }
}
```



### 心得体会

#### 预处理

- **[弊端]** : 受学习算法思维的影响, 在用数组设计代码的时候习惯引入了大量的预处理数组. 但是在后期维护功能时, 发现书写复杂度成倍增长, 在预处理数组在面对新需求整改的时候, 维护量基本上升到了整篇代码的量. 牵一发而动全身, 耦合度大, 维护起来笨重且容易忘记部分功能, 耗时久但效率极低. 所以在数组预处理上应该避重就轻.没有一劳永逸的预处理. 对于常用的预处理更是如此.
  
    ```cpp
    int CourseStuSum[Cnum+ErrCnum][Nnum];//记录课程下的学生序号
    int SuDeleteCourse[Cnum+ErrCnum];//老师要删除的课程序号
    int Flag_ErrCourse;//增加的课程
    char ErrGradecourse[Gradenum][GNamenum];//增加班级的信息
int GradeErr[Gradenum+Gradenum];//班级是否被删除
    int AddGrade;//增加班级的数量
    ```
    
- **[好处]** : 简化查找对应课程下的学生的代码复杂度, 在查找量巨大的时候可以减少查找的量. 降低时间和空间复杂度.
  
- 引入了宏定义来预处理输出化数组的大小, 如处理课程数量, 课名长度, 班级数量, 班级名字长度, 学生数量, 老师数量, 容错课程数量, 容错课名长度. 这些初始写代码不知道且需要快速确定的常量, 可以采用宏定义的方式快速确定下来, 在未来修改可以更容易修改.经过资料查找, 这个是C语言的典型处理方式, 而对于常量, 可以取而代之的C++做法是: `const int Cnum=5;`
  
    ```cpp
    #define Cnum 5 //课程数量
    #define Nnum 20 // 课名长度
    #define Gradenum 2 //班级数量
    #define GNamenum 20 //班级名字长度
    #define Studentnum 1 //学生数量
    #define Teachernum 1 //老师数量
    #define ErrCnum 5 //容错课程数量
    #define ErrNnum 20 //容错课名长度
    #define PAUSE() system("read -p '-->按任意键结束<--' var")//暂停函数
    ```
#### 功能切离

虽然在写代码的初期进行了一部分的功能切离, 但是在区分必要打印信息和不必要打印信息上还存在差距.

自己总结出来的一些规律是:

+ 把核心逻辑代码变为函数放在外部; 其中重要的是, 对于被管理(权限比较低) 的用户, 应该尽量把权限变为 Public , 即放在全局环境中. 好处是可以供管理员(权限高) 重复调用, 提高代码的可重读性, 如:

    ```cpp
    # 面向过程中
    # 此函数常常显示课程信息, 所以经常被调用, 写成核心代码的形式可以重复调用.
    void ShowCourse(){ // 展示现在存有的课程
        int jnum, step=1;
        for(jnum=0; jnum<Cnum; jnum++){
            if(!SuDeleteCourse[jnum])
                cout<<"["<<step++<<"]\t"<<course[jnum]<<'\n';
        }
        if(!Flag_ErrCourse) return;
        for(int i=0;i<Flag_ErrCourse;i++){
            if(!SuDeleteCourse[jnum+i])
                cout<<"["<<step++<<"]\t"<<ErrCourse[i];
            cout<<'\n';
        }
    }
    
    # 类与对象中
    # 简单的打印课程函数, 检查标记数组封装在类中, 所以显得更加简洁干净.
    # 检查当course[i].GetCheckSelect()为1, 代表选中; 检查当::course[i].GetSuDelete()为0,表示没有被删除
    void St::SimpleSCourse(){
        string temp;
        for(int i=0 ;i<Cnum+Flag_ErrCourse;i++) 
            if(course[i].GetCheckSelect() && (!(::course[i].GetSuDelete())))
    			cout<< (::course[i].GetName()) <<'\t';
    }
    ```



#### 数组利用位模式优化时间复杂度

**[方法]** : 在写 [选课, 课程预处理] 以及 [删除课程或者班级] 的时候使用同 [存储数组] 大小的标记数组 来标记课程的被选和删除情况, 如果对应位置的标记不为0 的时候就表示该位置的课程被选或者删除, 利用**数组下标的特殊性**可以进行**对应课程/班级/情况的记录**. 如:

```cpp
char course[Cnum][Nnum];//记录课程的名字和数量
char ErrCourse[ErrCnum][ErrNnum];//可以增加的课程即数量
int SuDeleteCourse[Cnum+ErrCnum];//老师要删除的课程序号
```



#### 类与对象的高效和易维护

深刻体会了类与对象书写代码的方式处理了**程序功能的分离和归属**的特点. 尤其在增设了 班级(Grade) 和 课程(Course) 后, **无论是从逻辑上而言, 还是代码书写上, 不需要再考虑担心是否遗漏某部分功能**, 因为所有的功能全部封装在一个大类中, 结合注释的查找可以让书写的逻辑思路更加清晰, 而不是像结构体那样滑动半个屏幕找寻之前的定义而一头雾水的感觉. 以学生类型为例: 

```cpp
#面向过程, 查找函数与对应存储单元(数组)
//Student Operation, Show, Search , Delete
void ShowCourse();
int SearchRealCourseNum(int);
void ChangeCourseStu(int,int);
int TextStCourse(int,int);
void ChooseCourse(int);
...
char course[Cnum][Nnum];//记录课程的名字和数量
char ErrCourse[ErrCnum][ErrNnum];//可以增加的课程即数量
int CourseStuSum[Cnum+ErrCnum][Nnum];//记录课程下的学生序号
int SuDeleteCourse[Cnum+ErrCnum];//老师要删除的课程序号
int Flag_ErrCourse;//增加的课

# 类与对象
typedef class Student{//选择的指针占位符号, 选择存储的位置
private:
    string Name;//名字
    string ID;//学号
    string PassW;//密码
    int LoginNum;//初次登录验证密码
    int CCourse;//学生已经选择的课程数量
public:
    SG Grade;//班级序号
    SC course[Cnum+ErrCnum];//选择的课程编号(序号)最多的情况就是课程的数量选择的课程数 
    Student();//初始化学生名字为DFS1,DFS2...
    ~Student();
    int GetStNum();//搜索学生, 返回下标和名字.
    string GetName(){return Name;}
    string GetID(){return ID;}
    string GetPassW(){return PassW;}
    int GetLoginNum(){return LoginNum;}
    int GetCCourse(){return CCourse;}
    void ChooseCourse();//进行已有的课程的选择
    void SimpleChoose(int);//根据参数选择客场
    void SearchCourse();//学生查看自己的选课情况
    void SimpleSCourse();//横向展示自己的的课程
    void SwapCourse();//删除和更换学生选课
    void SimpleDelete(int);//根据参数删除课程
    void ChangeStCourse();//换课
    void DeleteCCourse();//根据学生数组打印学生课程; 拿课程去查学生, 选课的时候存上编号.
    void ChangeSelfInfo();//更改自己的名字, 密码以及ID
}St;
```

#### 链表对动态的适应性

在删除课程, 班级的过程中, 如果使用的是链表的结构, 到最后是真的删除这个节点, 无法找回, 而正是因为链表的纯粹性, 所以在用链表写注册和删除的时候可以非常简便, 思路自然也很清晰. 而反观数组就不一样了, 在空间复杂度上要比链表多一倍的空间, 带来的好处是调用方便, 不必遍历整个链表从头查找,  所以在开头注册登录使用链表, 在后面选课运用数组是一个高明的选择. 



#### 输入检查

**[效果]** : 对于不符合条件的情况, 重复输入. 

**[实现]** : 对于**需要容错的重复输入的情况**, 一种简单处理的做法是写成循环; 而另外一中高明的做法就是**写成模板, 或者函数**

```cpp
# 第一种情况:
do{
	cin>>order;
    if(!order) continue;
	if(order==-1) return;
	else cout<<"请重新输入!!!";
	system("reset");
}while(order<-1||order>3);
# 第二种情况:
int InputCheck(int DownLimit, int Uplimit){
    int order=-1;
    do{
        cin>>order;
        if(!order) continue;
        if(order==-1) break;
        if(order<DownLimit||order>Uplimit)
            cout<< "[Tip]: 输入有误,请重新输入\n";        
    }while(order<DownLimit || order>Uplimit); 
    return order;
}
```

### Afterwords

最后, 可能是疫情隔离我与世界太久的缘故, 我已经忘记了如何和世界相处.

所以造成这一切的后果之后我不能过分消极, 困难的到来不是为了停留, 而是过去, 我始终羡慕那些 逢山开路，遇水架桥 的人, 而这条心路是我不得不修炼的地方, 关于如何和这个世界相处, 如何约法三章......

