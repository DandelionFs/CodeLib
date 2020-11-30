# System Dev
写下这个分支的原因是 起源于自己的懒, 糟心于鼓捣工具的繁琐, 我一开始希望写一个打包的程序, 安装之后所有需要的程序就都有了. 起初我看了注册表的相关知识，想从注册表的配置实现用户的自定义配置... 之后我发现了 `Advanced Installer`这样的`Window`打包工具, 可以简单地做完了安装包的打包和解压工作，但是有一个局限的点是无法批量的做一个工程，换句话说，这个项目以半完成状态暂时放弃...

之后我选择了这条路子, 边写心得, 边开发. 期待后续 :)  

THX FOR:
1. https://zhuanlan.zhihu.com/p/93719752
2. https://www.cnblogs.com/lxmhhy/p/6212405.html
3. https://mp.weixin.qq.com/s/tTgqO4kM29uKm2Sy5KSbiA
4. https://www.jb51.net/article/176264.htm
5. https://mp.weixin.qq.com/s/enFpkGGeoNw9v_pGzhe2uw
6. [美丽新世界：linux 下的惬意生活](https://github.com/yangyangwithgnu/the_new_world_linux)
7. 

## Environment Var
### Linux



### Win10<sup>1</sup>
1. 不区分大小写
2. 系统变量对所有用户有效,  优先级高于用户变量
3. 系统在执行用户命令时，若用户未给出文件的绝对路径，则首先在当前目录下寻找相应的可执行文件、批处理文件等,   找到为止(不会递归文件夹,  只指文件 )；
4. 新加命令后注意要保存. 






## Usr
关于我看书的一个假想（其实也确实如此，至少Wiki上面已经提过）——早期多人共享一台计算机，共享的系统可能就是Unix或者Linux，而不会是win，因为Unix可比Win出现的要早啊，

1. **PC和操作系统一次只能供一个用户使用**。即使您可以物理连接外围设备（例如USB集线器），**操作系统仍然只能渲染一个台式机**，随之而来的是欢闹声。
   PCs are designed for one user at a time as are operating systems. Eve n if you could physically get the peripherals connected (eg. USB hub), the OS would still only render one desktop and hilarity would ensue. 

2. 在操作系统级别，来自多个连接的键盘或鼠标的输入被解释为来自单一来源。如果要使用多个鼠标和键盘，则任何尝试读取输入的应用程序都必须降低级别。 
   On the OS level, the input from multiple connected keyboards or mice is interpreted as coming from a single source...




## HOST

一个没有扩展名的系统文件，作用就是将一些常用的网址域名与其对应的IP地址建立一个关联“数据库”，当用户在浏览器中输入一个需要登录的网址时，系统会首先自动从Hosts文件中寻找对应的IP地址，一旦找到，系统会立即打开对应网页，如果没有找到，则系统会再将网址提交DNS域名解析服务器进行IP地址的解析。

### 修改

接下来关键问题就是如何修改hosts文件，hosts文件存放目录：

- Window目录 C:\Windows\System32\drivers\etc\[hosts](https://laod.cn/tag/hosts/)
- Linux及其他类Unix操作系统：/etc
- Android目录/system/etc/

修改方向:
- [ADhosts](https://github.com/otobtc/ADhosts)
- [yhosts](https://github.com/VeleSila/yhosts)

### 作用

1. **虚拟域名**: 很多时候，网站建设者需要把”软环境“搭建好，再进行上传调试。但类似于邮件服务，则需要使用域名来辅助调试，这时就可以将本地 IP 地址与一个”虚拟域名“做地址指向，就可以达到要求的效果，且无需花费。
2. **加快域名解析**: 对于要经常访问的网站，我们可以通过在Hosts中配置域名和IP的映射关系，提高域名解析速度，当我们输入域名计算机就能很快解析出IP，而不用请求网络上的DNS服务器。
3. **屏蔽网站（域名重定向）**:有很多网站不经过用户同意就将各种各样的插件安装到你的计算机中，其中有些说不定就是木马或病毒。对于这些网站我们可以利用Hosts把该网站的域名映射到错误的IP或本地计算机的IP，这样就不用访问了。在WINDOWS系统中，约定 127.0.0.1 为本地计算机的IP地址, 0.0.0.0是错误的IP地址。
4. **方便局域网用户**: 在很多单位的局域网中，会有服务器提供给用户使用。但由于局域网中一般很少架设DNS服务器，访问这些服务器时，要输入难记的IP地址。这对不少人来说相当麻烦。可以分别给这些服务器取个容易记住的名字，然后在Hosts中建立IP映射，这样以后访问的时候，只要输入这个服务器的名字就行了。
5. **顺利连接系统**: 对于Lotus的服务器和一些数据库服务器，在访问时如果直接输入IP地址那是不能访问的，只能输入服务器名才能访问。那么我们配置好Hosts文件，这样输入服务器名就能顺利连接了。
6. **强制域名解析指定IP**: 比如一些网站有很多的服务器ip，有些ip可能被和谐了，那么我们可以在hosts文件里添加我们想要的ip跟域名。


## 进程

### 守护进程 & 僵尸进程 & 孤儿进程

+ **守护进程(daemon)**:以进程的形式初始化, 是一种在后台执行的电脑程序。进程程序的名称通常以字母“d”结尾; 很多守护进程在系统引导的时候启动，并且一直运行直到系统关闭; 如syslogd就是指管理系统日志的守护进程。
+ **僵尸进程**: 子进程先于父进程退出后，子进程的PCB需要其父进程释放，但是父进程并没有释放子进程的PCB，这样的子进程就称为僵尸进程。即完成执行（通过 exit 系统调用，或运行时发生致命错误或收到终止信号所致）但在操作系统的进程表中仍然有一个表项（进程控制块PCB），处于"终止状态 "的进程, 实际上是一个已经死掉的进程。对应PS里面的defunct和Top里面的zombie.下面俩个僵尸进程我居然不能杀, 太TM... 值得一提的是 WPS 退出来居然也是僵尸进程...
   ```bash
   dfs        53396   53321  0 18:05 tty2     00:00:00 [fcitx] <defunct>
   dfs        55583   55388  0 18:07 pts/1    00:00:00 grep --color=auto defunct
   ```
+ **孤儿进程**: 在其父进程执行完成或被终止 后仍继续运行的一类进程。
    
普通进程:
```cpp
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
void main(){
    FILE *fp;
    time_t t;
    while(1){
        sleep(6);
        fp=fopen("hello.log","a");
        if(fp>=0){
            time(&t);
            fprintf(fp,"current time is:%s\n",asctime(localtime(&t)));
            fclose(fp);
        }
    }
    return;
}
```
守护进程:
```cpp
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
void init_daemon(){
    int pid, ;
    pid=fork();
    if(pid<0) exit(1);
    else if(pid>0) exit(0);
    setsid();
    pid=fork();
    if(pid>0) exit(0); 
    else if(pid<0) exit(1);
    for(i=0;i<NOFILE;i++)close(i);
    chdir("/tmp");
    umask(0);
    return;
}
void main(){
    FILE *fp;
    time_t t;
    printf("pid = %d\n", getpid());
    init_daemon();
    while(1){
        sleep(6);
        fp=fopen("hello2.log","a");
        if(fp>=0){
            time(&t);
            fprintf(fp,"current time is:%s\n",asctime(localtime(&t)));
            fclose(fp);
        }
    }
    return;
}
```

僵尸进程（子进程）

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
   pid_t id = fork();
   if(id < 0){
      perror("fork");
      return 1;
   }
   else if(id > 0){
      printf("parent [%d] is sleeping\n",getppid());
      sleep(500);
   }
   else{
      printf("child [%d] is begining\n",getpid());
      sleep(2);
      exit(1);
   }
   return 0;
}
```




用到的简单命令

```bash
gcc xxx.c -o xxx #后面是指明输出文件的名字
./xxx 
ps -aux | grep xxx # 
cat /tmp/xxx.log 
top # 不看不知道, 一看吓一跳, 我的电脑里面有两个僵尸进程, woc
```


### Linux 基础命令

```bash
man XXX
```
目录的写法:
+ **绝对路径**：从根目录开始,依次将各级子目录的名字组合起来，路径的写法一定是由根目录 / 写起，例如 /usr/local/ ”
+ **相对路径**：相对当前所在路径的位置，路径的写法不是由根目录“ / ”写起，例如“ work/test ”

### Linux 进程

#### terminal & shell & bash

+ 终端（terminal）作用是提**供一个命令的输入输出环境**。对于普通 Linux 来说，终端的作用是一个**字符（或者模拟字符）的命令交互界面**，实现对计算机的控制。(动态交互以及静态交互)
+ shell是一个**命令行解释器**，是**linux内核的一个外壳**,负责**外界与linux内核的交互**。shell接收命令, 然后将这些命令转化成内核能理解的语言并传给内核, 内核执行命令完成后将结果返回给用户或者应用程序。
  + **当打开一个terminal时，操作系统会将terminal和shell关联起来，当在terminal中输入命令后，shell就负责解释命令。**
+ bash(Bourne Again shell): 从名字上可以看出bash是Bourne shell的扩展，bash 与 Bourne shell 完全向后兼容，并且在 Bourne shell 的基础上增加和增强了很多特性，如命令补全、命令编辑和命令历史表等功能，它还包含了很多 C shell 和 Korn shell 中的优点，有灵活和强大的编程接口，同时又有很友好的用户界面。总而言之，bash是shell的一种，是增强的shell。

linux终端分为物理终端，伪终端，串行终端，虚拟终端

+ 物理终端：/dev/console
+ 伪终端（远程网络终端 、图形下的终端）：/dev/pts/#(数字)
+ 虚拟终端:/dev/tty#
+ 串行终端：/dev/ttys#

```bash
cat /etc/shells # see your shell in Linux

```



[补充]:

![](/img/linux/ps-auxcl.png)

以上的有VSZ & RSS & TTY & STAT & START 

+ VSZ 
+ RSS 
+ TTY
+ STAT 
+ START 

PTS & TTY [3]

TTY History
```bash
# Physical Line         
| teletype |<--------------------->| teletype |
# Physical Line 
| Terminal |<->| Modem |<--------------------->| Modem |<->| UART |<->| Computer |
  +-----------------------------------------------+
  |          Kernel           |
| UART |  |  Line  |  | TTY  |<---------->| User process A |
<------>|    |<->|      |<->|    |  | driver |  | discipline |  | driver |<---------->| User process B |
  |  +--------+  +------------+  |    |  |    +----------------+
  |                 +--------+  |
  |                        |
  +-----------------------------------------------+

```



#### 进程 & 程序 & PCB? & 作用？

+ 进程的静态描述:
  +  **PCB(Processing Control Block; 进程控制块)**：每个进程在内核中都有一个进程控制块, 为了描述**进程情况及控制进程运行所需的全部信息**，是操作系统用来**感知进程存在**的一个重要数据结构(使用task_struct结构体,是系统为了管理进程设置的一个专门的数据结构)。
     - 进程id、用户id和组id
     - 进程的状态(就绪、运行、阻塞等)
     - 进程切换时需要保存和恢复的CPU寄存器的值
     - 描述虚拟地址空间的信息
     - 描述控制终端的信息
     - 当前工作目录
     - 文件描述符表，包含很多指向file结构体的指针
  + **代码段**：进程中**能被进程调度程序在CPU上执行的程序代码段**。
  + **数据段**：进程的数据段是**进程对应的程序加工处理的原始数据**，也可以是**程序执行后产生的中间或最终数据**
    + 只读数据段：常量
    + 已初始化数据段：全局变量，静态变量
    + 位初始化数据段（bss)（0初始化段）：未初始化的全局变量和静态变量（实际上不分配内存，因为都为0，只有一些标记信息）

<font color=red>一个进程=代码段（编译后形成的一些指令）+数据段（程序运行时需要的数据）+堆栈段（程序运行时动态分配的一些内存）+PCB（进程信息，状态标识等）</font>


#### 进程管理的 fork函数?

- 进程管理相关的函数说明
    - **fork：函数用于从已存在的进程中创建一个新进程**（新进程称为子进程，而原进程称为父进程。这个函数有两个返回值，子进程返回0，父进程返回父进程的pid，pid 是一个标志进程的数字，可以用函数getpid() 获得）
    - **exec：函数提供在进程中启动另一个程序执行的方法**。
    - **exit：函数用来进程结束**。
    - **wait：进程一旦调用了wait，就立即阻塞自己**，当发现当前进程的子进程已经exit，便会收集这个子进程的信息，然后彻底销毁，如果没有找到这样的子进程，就会一直阻塞。
    - **sleep：就是挂起进程指定的秒数**。
    - **getpid：返回当前进程（调用这一函数的进程）的ID**。
    - **getppid：返回当前进程的父进程的ID**。

用法如下:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void){
    pid_t childpid;
    int status;
    childpid = fork();
    if (-1 == childpid){
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    else if(0 == childpid){
        puts("In child process");
        sleep(10);
        printf("\tchild pid = %d\n", getpid());
        printf("\tchild ppid = %d\n", getppid());
        exit(EXIT_SUCCESS);
    }else{
        waitpid(childpid, &status, 0);
        puts("in parent");
        printf("\tparent pid = %d\n", getpid());
        printf("\tparent ppid = %d\n", getppid());
        printf("\tchild process exited with status %d \n", status);
    }
    exit(EXIT_SUCCESS);
}
```





#### 进程 & 进程(父子,兄弟)，执行守护进程时，父进程是谁？

P523

> UID是用户ID，PID是 进程ID ， PPID 是 父进程ID 。 UIDUID 用户身份证明(User Identification)的缩写。  UID用户 在注册会员后，系统会自动的给你一个UID的数值。 意思就是给这名用户编个号

+ 程序是完成特定任务的一系列指令集合。
+ 从用户的角度来看进程是程序的一次动态执行过程。
+ 从操作系统的核心来看，进程是操作系统分配的内存、CPU时间片等资源的基本单位。
+ 每一个进程都有自己独立的地址空间与执行状态。


区别和联系

+ 进程是动态的，程序是静态的
+ 进程的生命周期是相对短暂的，而程序是永久的。
+ 进程数据结构PCB
+ 一个进程只能对应一个程序，一个程序可以对应多个进程。






#### 信号？杀进程?

**信号**

- 操作系统中，信号是**事件发生时对进程的通知机制**，有时也称为**软件中断**。
- **信号**与**硬件中断**的相似之处在于打断了程序执行的正常流程，大多数情况下，无法预测信号到达的准确时间。
- 一个进程可以向另一进程发送信号。
- **信号也是进程间通信的一种方式。**

**杀进程**

+ kill命令是通过向进程发送指定的信号来结束相应进程的
+ kill命令可以带信号号码选项，也可以不带。如果没有信号号码，kill命令就会发出终止信号(15)，这个信号可以被进程捕获，使得进程在退出之前可以清理并释放资源。

例如： kill -2 1234 相当于kill -INT 1234

- SIGINT 终止进程，通常Ctrl+C就发送的2号信号
- 杀死一个进程，可以使用kill  <pid> 命令


那么最后再来分析一遍之前的守护进程:

```cpp
void init_daemon(){
    int pid, ;
    pid=fork(); //首次调用fork：父进程直接退出，貌似要“脱胎换骨搞独立”
    if(pid<0) exit(1);
    else if(pid>0) exit(0);
    setsid(); //setsid()：调用成功后，进程成为新的会话组长和新的进程组长，并与原来的登录会话和进程组脱离。同时与控制终端脱离。
    pid=fork();//第二次调用fork：结束第一进程（组长），第二子进程继续（第二子进程不再是会话组长），目的是禁止进程重新打开控制终端。
    if(pid>0) exit(0); 
    else if(pid<0) exit(1);
    for(i=0;i<NOFILE;i++)close(i);//close()：关闭打开的文件描述符，进程从创建它的父进程那里继承了打开的文件描述符。如不关闭，将会浪费系统资源，造成进程所在的文件系统无法卸载以及可以引起无法预料的其他错误。
    chdir("/tmp");//chdir():改变当前工作目录。脱离当前工作目录，改变到一个新的目录
    umask(0);//umask():重设文件的权限掩码，为了防止继续沿用从父进程继承下来的掩码内容
    return;
}
```

+ 当前守护进程的父进程是谁？
+ 关联的终端是哪一个？

