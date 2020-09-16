#include<iostream>
#include<cstdio>
#include<string>

#define key 1
//-----------------------------------------------------------------------------------------------------------------------------
#define Cnum 5
//课程数量
#define Nnum 20
// 课名长度
#define Studentnum 1
//学生数量
#define Teachernum 1
//老师数量
#define PAUSE() system("read -p '按任意键结束 : ) ' var")

using namespace std;

//User Dep----------------------------------------------------------------------------------------------------------------
typedef struct Student{
    string name="DFS";
    string ID, PassW;
    bool level=0;//安全检查权限
    int course[Cnum]={0}, CCourse=0, ChooseTemp=0, num=0;
    Student * NextStu;
}St;

typedef struct Teacher:Student{
    bool level=1;
    Teacher * NextTea;
}Te;

//Memory--------------------------------------------------------------------------------------------------------------
// int CourseStuSum[Cnum][Nnum];
char course[Cnum][Nnum]={ ("大学数学"), ("大学英语") ,("大学语文") ,("大学物理") ,("大学化学")};
St *StuAcc=NULL, *StuTemp=NULL, *HeadStu=NULL, *nowStu=NULL;         // Student Num 学生用户组
Te *TeaAcc=NULL, *TeaTemp=NULL, *HeadTea=NULL, *nowTea=NULL;     //Teacher  NUm 老师用户组

//StuAcc 申请内存, 

//System keep-------------------------------------------------------------------------------------------------------
void Systeminit();
void QuitSystem();
bool SecuityJudge();
bool SuSecuityJudge();
void LocStu(string);
void LocTea(string);
void NameLocStu(string);
void NameLocTea(string);


//System Tip------------------------------------------------------------------------------------------------------------
void PrintWelScreen();
void PrintUsrAct();
void PrintSuAct();
void PrintManStu();

//Student Operation, Show, Search , Delete -------------------------------------------------------------
void ShowCourse(St*);
void SearchCourse(St*);
void DeleteCCourse(St*);

//Teacher Operation------------------------------------------------------------------------------------------------
void SuShowCourseAStudent();
void SuSearchManStCourse();

int main(){
    int order;
 Start: Systeminit();
    PrintWelScreen();

    do{
        cin>>order;
        if(order==1||order==2) break;
        else if(order!=1||order!=2) cout<<"请再次选择身份以进行再度登录\n";
    }while(1);//先进行输入再进行判断

    system("reset"); 

    if(order==1){ // 学生登录
        while(key){
            if(key){
                while(SecuityJudge()){
                    while(key){
                        PrintUsrAct();
                        cin>>order;
                        system("reset");
                        if(order<0 || order > 5){
                            system("reset");
                            cout<<"请根据提示重新输入!!!";
                            continue;
                        }// 错误检查
                        if(order==1){ 
                            ShowCourse(nowStu);/*增加引用或者传入地址(数组下标)*/
                            system("reset"); 
                            continue;
                        }
                        else if(order==2){
                            if(!(nowStu->CCourse)) {
                                cout<<"现在没有选择任何课程.\n"; 
                                PAUSE();
                                system("reset"); 
                                continue;
                                }
                            cout<< "现在一共选择了"<<nowStu->CCourse<<"门课程, 它们是: "<<endl;
                            SearchCourse(nowStu);
                            PAUSE();
                            system("reset"); 
                            continue;
                        }
                        else if(order==3){
                            cout<<"现在的选课情况如下:\n ";
                            DeleteCCourse(nowStu);
                            system("reset"); 
                            continue;    
                        }
                        else if(order==4){//用goto实现注销
                            system("reset"); 
                            cout<< "注销成功\n";
                            goto Start;
                        }
                        else if (order==5) { 
                            QuitSystem();
                            system("reset"); 
                            cout<<"期待您的下次使用! See U~\n";
                            return 0;
                        }
                    }
                }
            }
            else{
                cout<<"学号或者密码错误, 请更正再尝试登录\n";
                continue;
            }
        }
    }
    else if(order==2){
        if(key){
            while(SuSecuityJudge()){
                while(key){
                    PrintSuAct();
                    cin>>order;
                    system("reset");
                    if(order<0 || order > 4){
                    system("reset");
                        cout<<"请根据提示重新输入!!!";
                        continue;
                    }
                    if(order==1){ 
                        SuShowCourseAStudent();
                        PAUSE();
                        system("reset"); 
                        continue;
                    }
                    else if(order==2){
                        SuSearchManStCourse();
                        PAUSE();
                        system("reset"); 
                        continue;    
                    }
                    else if(order==3){//用goto实现注销
                        system("reset"); 
                        cout<< "注销成功\n";
                        goto Start;
                    }
                    else if (order==4) { 
                        QuitSystem();
                        system("reset"); 
                        cout<<"期待您的下次使用! See U~\n";
                        return 0;
                    }
                }
            }
        } 
    }
}

//System------------------------------------------------------------------------------------------------------------
void Systeminit(){ //运用文件读写 , 写入学生的信息到全局数组里/* needcnm*/
     int StuNum=Studentnum;
    while(StuNum--){//初始化用户ID 以及密码
        if(HeadStu==NULL){
            StuAcc= new St;
            HeadStu=StuAcc;
        }
        else{
            StuTemp=StuAcc;
            StuAcc= new St;
            StuTemp->NextStu=StuAcc;
        }
    }
    int TeaNum=Teachernum;
    while (TeaNum--){
        if(HeadTea==NULL){
            TeaAcc= new Te;
            HeadStu=TeaAcc;
        }
        else{
            TeaTemp=TeaAcc;
            TeaAcc= new Te;
            TeaTemp->NextTea=TeaAcc;
        }
    }
}

void QuitSystem(){//保存文件到目录下/*needcnm*/

}

bool SecuityJudge(){
   string account, password;
    bool flag=0;
    while(flag==0){//增加登录失败的提示操作
        cout<<"请输入学号(教职工号):\n";
        cin>>account;
        cout<<"请输入你的密码:\n";
        cin>>password;
        LocStu(account);
        // nowStu=StuTemp;
        nowStu=HeadStu;
        if(password=="1") {
            system("reset"); 
            cout<<"恭喜你, 登录成功"<<endl;
            return true;
        }
        else{
            system("reset"); 
            cout<<"登录超时, 请尝试重新登录"<<endl;
            flag=0;
        }
    }
}

bool SuSecuityJudge(){
    string account, password;
    bool flag=0;
    while(!flag){//增加登录失败的提示操作
        cout<<"请输入学号(教职工号):\n";
        cin>>account;
        cout<<"请输入你的密码:\n";
        cin>>password;
        LocTea(account);
        nowTea=TeaTemp;
        if(password=="1") {
            system("reset"); 
            cout<<"恭喜你, 登录成功"<<endl;
            return true;
        }
        else{ 
            system("reset"); 
            cout<<"登录超时, 请尝试重新登录"<<endl;
        }
    }

}

void LocStu(string ID){/*全局指针来避免匿名内存的遗漏*/
    StuTemp=HeadStu;
    while(StuTemp!=NULL) {
        if(StuTemp->ID==ID){nowStu = StuTemp; break;}
        StuTemp=StuTemp->NextStu;
    }
}

void LocTea(string ID){
    TeaTemp = HeadTea;
    while(TeaTemp!=NULL) {
        if(TeaTemp->ID==ID) {nowTea = TeaTemp; break;}
        TeaTemp=TeaTemp->NextTea;
    }
}

void NameLocStu(string name){
    StuTemp=HeadStu;
    while(StuTemp!=NULL) {
        if(StuTemp->name==name) {nowStu = StuTemp; break;}
        StuTemp=StuTemp->NextStu;
    }
}

void NameLocTea(string name){
    TeaTemp = HeadTea;
    while(TeaTemp!=NULL) {
        if(TeaTemp->name==name) {nowTea = TeaTemp; break;}
        StuTemp=StuTemp->NextStu;
    }
}


//System Print------------------------------------------------------------------------------------------------------------------------------
void PrintWelScreen(){//打印开始登录界面
    cout<<"***基于学生结构体数组的选课系统***\n\n";
    cout<<"选择您的角色登录 !\n"; //Please choose your Identidy for logging in
    cout<<"1. 学生\n";
    cout<<"2. 老师\n";
}

void PrintUsrAct(){
     cout<< "选择对应操作!:\n";
     cout<<"1. 课程列表及选课.\n";
     cout<<"2. 查询我的选课.\n";
     cout<<"3. 更改我的选课.\n";
     cout<<"4. 注销账户登录\n";
     cout<<"5. 退出选课系统\n";
}

void PrintSuAct(){
     cout<< "选择对应操作!:\n";
     cout<<"1. 课程列表及选课情况.\n";
     cout<<"2. 查询/更改指定学生选课情况.\n";
     cout<<"3. 注销超级账户登录\n";
     cout<<"4. 退出选课系统\n";
}

void PrintManStu(){
    cout<< "-1. 返回主页面\t";
    cout<<"1. 删除学生选课.\t";
    cout<<"2. 增加学生选课.\n";
}


//Student Operation------------------------------------------------------------------------------------------------------------------
void ShowCourse(St *a){ // 展示课程并进行选择
    int num, flag;//flag查询课程下的学生是否选了这个课程
    char order;
    for(int i = 0; i<Cnum;i++) cout<<i+1<<'\t'<<course[i]<<'\n';
    
    cout<<"请输入您需要选择的课程对应的序号(退出选课输入-1): \n";
    
    do{
        cin>>num;
        if(num>Cnum)cout<<"请重新输入所选择的课程数. 必须存在在已列课程中! \n";
        else if(num==-1) return;
    } while (num>Cnum);//输入一定要用循环

    if(a->course[num]==0)a->CCourse++;

    a->course[num-1]++;

    /*存学生数组下标的方式失效*/

    system("reset");
    cout<<"恭喜你选课成功! :),  请问继续选课, 默认继续选课(y/n)\n";
    getchar();//吸收前面的空格
    order=getchar();
    system("reset");
    if(order=='y'|| order=='\n') ShowCourse(a);
    else if(order=='n')  return;
}

void SearchCourse(St* a){//学生查看自己的选课情况
    int ii=0; 
    for(int i=0 ;i<Cnum;i++) if(a->course[i]) cout<<ii+1<<'\t'<<course[i]<<endl , ii++;
}

void DeleteCCourse(St* a){
    int order;
    char corder;
    do{
        SearchCourse(a);
        cout<<"请输入您想删除的课程的序号(按 -1 取消删除):\n";
        cin>>order;
        if(order==-1) return;
        if(order>a->CCourse||order<0) {
            system("reset");
            cout<<"删除失败, 因为输入序号不是有效课程, 请重新输入对应序号\n" ;
            continue;
        }
    }while(order>a->CCourse||order<0);
    
    for(int i=0;i<Cnum;i++){
        if(a->course[i]!=0){
            if(order==1){// 
                a->course[i]=0;
                break;
            }
            else if(order!=1) order--;
        }
    }

    a->CCourse--;
    system("reset");
    cout<<"原课程已移除,现在的课程有\n ";
    SearchCourse(a);
    cout<<" 请问是否继续删除课程(y/n), 默认继续删除课程\n";
    getchar();
    corder=getchar();
    if(corder=='y'||corder=='\n'||corder=='Y') {
        system("reset");
        DeleteCCourse(a);
    }
    else return;
    
}
/*根据学生数组打印学生课程
拿课程去查学生, 选课的时候存上编号.
*/

//Teacher Operation-----------------------------------------------------------------------------------------------------------------
void SuShowCourseAStudent(){//课程列表及选课情况
    
}

void SuSearchManStCourse(){//查询指定学生选课情况
    int order;
    St* flag;
    string temp; 
    cout<<"请选择学号查找还是名字查找: \n";
    cout<<"1. 学号查找 \n";
    cout<<"2. 名字查找: \n";
    cin>>order;
    if(order==1){
        cout<<"请输入学生的学号进行查询:\n";
        cin>>temp;
        LocStu(temp);
        flag=StuTemp;
    }
    else if(order==2){
        cout<<"请输入学生的名字进行查询\n";
        cin>>temp;
        NameLocStu(temp);
        flag=StuTemp;
    }

    system("reset");
    cout<< "查询到的学生是"<<flag->name<< "他的选课情况如下:\n";
    SearchCourse(flag);
    system("reset");
    cout<<endl<<"请选择现在的操作:\n";
    PrintManStu();
    cin>>order;
    if(order==-1) return;
    else if(order==1) DeleteCCourse(flag);
    else if(order==2) ShowCourse(flag);
}
