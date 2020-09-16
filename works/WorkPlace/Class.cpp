#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>

#define Cnum 5
//课程数量
#define Nnum 20
// 课名长度
#define Gradenum 2
//班级数量
#define GNamenum 20
//班级名字长
#define Studentnum 1
//学生数量
#define Teachernum 1
//老师数量
#define ErrCnum 5
//容错课程数量
#define ErrNnum 20
//容错课名长度
#define PAUSE() system("read -p '按任意键结束 : ) ' var")
#define key 1

using namespace std;

//User Dep----------------------------------------------------------------------------------------------------------------
typedef class Student{
private:
    string name="DFS";
    string ID;
    string PassW;
    int course[Cnum]={0};
    int CCourse=0;
public:
    void ShowCourse();
    void SearchCourse();
    void DeleteCCourse();
    void ShowCourse();
    void ChooseCourse(int);
    void SearchCourse(int);
    void SwapCourse(int);
    void ChangeStCourse(int);
    void DeleteCCourse(int);
    void ChangeSelfInfo(int);
}St;

typedef class Teacher{
private:
    string name="DFS";
    string ID;
    string PassW;
    bool level=1;
public:
    void SuShowCourseAStudent();
    void SuSearchManStCourse();
    void SuShowCourseAStudent();
    void SuSearchManStCourse();
    void SuShowAllStINfo();
    void SuChangeGradeInfo(int);
    void SuGradeManage();
    void SuChangeCInfo();
    void SuShowGradeInfo();
    void SuAddGrade();
    void SuDelGrade();
    void SuMoveStGrade(int);
    void SuChooseStCourse(int);
    void SuDelStCourse(int);
    int SuSearchStName(string);
    int SuSearchStID(string);
    int SuSearchTeaName(string);
    int SuSearchTeaID(string);
}Te;

typedef class SCourse{
private:
    int StaTime;
    int EndTime;
public:
    SCourse(){StaTime=0,EndTime=0;}
    ~SCourse();
    void SetTime();
    void ChangeTime();
}SC;

typedef class StGrade{
private:
    bool SuDel;
public:
    StGrade();
    ~StGrade();
    void SuDelGrade();
}SG;

//Memory--------------------------------------------------------------------------------------------------------------
int CourseStuSum[Cnum][Nnum];
char course[Cnum][Nnum];
St StuAcc[Studentnum];// Student Struct Num 学生用户组
Te TeaAcc[Teachernum]; //Teacher Struct- NUm 老师用户组
int nowStu=0, nowTea=0;//此时程序处理的用户



//System keep-------------------------------------------------------------------------------------------------------
void Systeminit();
void QuitSystem();
bool SecuityJudge();
bool SuSecuityJudge();
void PrintWelScreen();
void PrintUsrAct();
void PrintSuAct();
void PrintManStu();

//System Tip------------------------------------------------------------------------------------------------------------

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
            if(SecuityJudge()){
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
                        StuAcc[nowStu].ShowCourse();/*增加引用或者传入地址(数组下标)*/
                        system("reset"); 
                        continue;
                    }
                    else if(order==2){
                        if(!(StuAcc[nowStu].CCourse)) {
                            cout<<"现在没有选择任何课程.\n"; 
                            PAUSE();
                            system("reset"); 
                            continue;
                            }
                        cout<< "现在一共选择了"<<StuAcc[nowStu].CCourse<<"门课程, 它们是: "<<endl;
                        StuAcc[nowStu].SearchCourse();
                        PAUSE();
                        system("reset"); 
                        continue;
                    }
                    else if(order==3){
                        cout<<"现在的选课情况如下:\n ";
                        StuAcc[nowStu].DeleteCCourse();
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
            else{
                cout<<"学号或者密码错误, 请更正再尝试登录\n";
                continue;
            }
        }
    }
    else if(order==2){
        if(SuSecuityJudge()){
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
                    TeaAcc[nowTea].SuShowCourseAStudent();
                    PAUSE();
                    system("reset"); 
                    continue;
                }
                else if(order==2){
                    TeaAcc[nowTea].SuSearchManStCourse();
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

//System keep------------------------------------------------------------------------------------------------------------
void Systeminit(){ //运用文件读写 , 写入学生的信息到全局数组里/* needcnm*/
    static St Admin; 
}

void QuitSystem(){//保存文件到目录下/*needcnm*/

}

bool SecuityJudge(){
    string account, password;
    bool flag=0;
    while(!flag){//增加登录失败的提示操作
        cout<<"请输入学号(教职工号):\n";
        cin>>account;
        cout<<"请输入你的密码:\n";
        cin>>password;
        for(int i=0;i<Studentnum;i++){
            if(StuAcc[i].ID==account) nowStu=i;
            break;
        }
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
        // for(int i=0;i<Teachernum;i++){
        //     if(TeaAcc[i].ID==account) nowTea=i;
        //     break;
        // }
        nowTea=0;
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

//System Tip------------------------------------------------------------------------------------------------------------------------------
void PrintWelScreen(){//打印开始登录界面
    cout<<"-->基于学生结构体数组的选课系统<--\n\n";
    cout<<"->请选择您的身份登录!<-\n";
    cout<<"[1]\t学生\n";
    cout<<"[2]\t老师\n";
}

void PrintUsrAct(){
    cout<<"欢迎来到学生选课主页面\n";
     cout<< "请选择对应操作:\n";
     cout<<"[1]\t课程列表及选课\n";
     cout<<"[2]\t查询我的选课\n";
     cout<<"[3]\t更改我的选课\n";
     cout<<"[4]\t更改我的资料\n";
     cout<<"[5]\t注销账户登录\n";
     cout<<"[6]\t退出选课系统\n";
}

void PrintChangeCourse(){
    cout<<"现在的选课情况如下:\n";
    SearchCourse(nowStu);
    cout<<"选择你想要的操作:\n";
    cout<<"[-1]\t返回主页面\n";
    cout<<"[1]\t删除指定选课\n";
    cout<<"[2]\t更换指定选课\n";
}

void PrintUsrInfo(){
    cout<<"您现在的用户资料是:\n";
    cout<<"[学号]\t"<<StuAcc[nowStu].ID<<'\t';
    cout<<"[名字]\t"<<StuAcc[nowStu].name<<'\t';
    cout<<"[密码]\t"<<StuAcc[nowStu].PassW<<'\n';
}

void PrintChangeUsrInfo(){
    cout<<"[-1]\t退出更改\n";
    cout<<"[1]\t更改名字\n";
    cout<<"[2]\t更改密码\n";
}

void PrintSuAct(){
    cout<<"-->欢迎来到老师管理学生选课系统主页面.<--\n";
    cout<< "->请选择对应操作!<-\n";
    cout<<"[1]\t课程列表及课程被选详情.\n";
    cout<<"[2]\t所有学生选课详情.\n";
    cout<<"[3]\t查询/更改指定学生选课.\n";
    cout<<"[4]\t管理班级选课信息\n";
    cout<<"[5]\t更改课程信息\n";
    cout<<"[6]\t注销超级账户登录\n";
    cout<<"[7]\t退出选课系统\n";
}

void PrintManStu(){
    cout<< "[-1]\t返回主页面\n";
    cout<<"[1]\t删除选课\n";
    cout<<"[2]\t增加选课\n";
    cout<<"[3]\t更换选课\n";
    cout<<"[4]\t修改帐号和密码\n";
    cout<<"[5]\t更改学生班级\n";
}

void PrintSuChangeCInfo(){
    cout<<"选择你要进行的操作:\n";
    cout<<"[-1]\t返回主界面\n";
    cout<<"[1]\t增加课程\n";
    cout<<"[2]\t删除课程\n";
    cout<<"[3]\t更改课程\n";
}

void PrintManGrade(){
    cout<<"[1]\t为班级同学集体选课\n";
    cout<<"[2]\t为班级同学集体退课\n";
    cout<<"[3]\t增加班级\n";
    cout<<"[4]\t删除班级\n";
}

//Student Operation------------------------------------------------------------------------------------------------------------------
void St::ShowCourse(){ // 展示课程并进行选择
    int num, flag;//flag查询课程下的学生是否选了这个课程
    char order;
    for(int i = 0; i<Cnum;i++) cout<<i+1<<'\t'<<::course[i]<<'\n';
    
    cout<<"请输入您需要选择的课程对应的序号(退出选课输入-1): \n";
    
    do{
        cin>>num;
        if(num>Cnum)cout<<"请重新输入所选择的课程数. 必须存在在已列课程中! \n";
        else if(num==-1) return;
    } while (num>Cnum);//输入一定要用循环

    if(!(this->course[num-1])) this->CCourse++;

    this->course[num-1]++;
    
    //增加对应课程统计的数组操作
    CourseStuSum[num-1][ CourseStuSum[num-1][0]]= nowStu;
    
    flag=0;
    for(int j=0;j< CourseStuSum[num-1][0];j++){
        if(nowStu==CourseStuSum[num-1][j+1]){flag=1;break;}
    }
    if(!flag)CourseStuSum[num-1][0]++;//改良set集合

    system("reset");
    cout<<"恭喜你选课成功! :),  请问继续选课, 默认继续选课(y/n)\n";
    getchar();//吸收前面的空格
    order=getchar();
    system("reset");
    if(order=='y'|| order=='\n') this->ShowCourse();
    else if(order=='n')  return;
}

void St::SearchCourse(){//学生查看自己的选课情况
    int ii=0; 
    for(int i=0 ;i<Cnum;i++) if(this->course[i]) cout<<ii+1<<'\t'<<::course[i]<<endl , ii++;
}

void St::DeleteCCourse(){
    int order;
    char corder;
    do{
        this->SearchCourse();
        cout<<"请输入您想删除的课程的序号(按 -1 取消删除):\n";
        cin>>order;
        if(order==-1) return;
        if(order>this->CCourse||order<0) {
            system("reset");
            cout<<"删除失败, 因为输入序号不是有效课程, 请重新输入对应序号\n" ;
            continue;
        }
    }while(order>this->CCourse||order<0);
    
    for(int i=0;i<Cnum;i++){
        if(this->course[i]!=0){
            if(order==1){// 
                this->course[i]=0;
                break;
            }
            else if(order!=1) order--;
        }
    }

    this->CCourse--;
    system("reset");
    cout<<"原课程已移除,现在的课程有\n";
    this->SearchCourse();
    cout<<" 请问是否继续删除课程(y/n), 默认继续删除课程\n";
    getchar();
    corder=getchar();
    if(corder=='y'||corder=='\n'||corder=='Y') {
        system("reset");
        this->DeleteCCourse();
    }
    else return;
    
}









//Teacher Operation-----------------------------------------------------------------------------------------------------------------
void Te::SuShowCourseAStudent(){//课程列表及选课情况
    for(int i =0;i<Cnum;i++){
        cout<<i+1<<'\t'<<course[i]<<'\t';
        for(int j=0;j<CourseStuSum[i][0];j++){
            cout<<StuAcc[CourseStuSum[i][j+1]].name<<',';
        }
        cout<<endl;
    }
}

void Te::SuSearchManStCourse(){//查询指定学生选课情况
    int order, flag;
    string temp; 
    cout<<"请选择学号查找还是名字查找: \n";
    cout<<"1. 学号查找 \n";
    cout<<"2. 名字查找: \n";
    cin>>order;
    if(order==1){
        cout<<"请输入学生的学号进行查询:\n";
        cin>>temp;
        for(int i=0;i<Studentnum;i++){
            if(StuAcc[i].ID==temp) {flag=i;break;}
        }
    }
    else if(order==2){
        cout<<"请输入学生的名字进行查询\n";
        cin>>temp;
        for(int i=0;i<Studentnum;i++){
            if(StuAcc[i].name==temp){flag=i;break;}
        }
    }
    system("reset");
    cout<< "查询到的学生是"<<StuAcc[flag].name<< "他的选课情况如下:\n";
    StuAcc[flag].SearchCourse();
    system("reset");
    cout<<endl<<"请选择现在的操作:\n";
    PrintManStu();
    cin>>order;
    if(order==-1) return;
    else if(order==1) StuAcc[flag].DeleteCCourse();
    else if(order==2) StuAcc[flag].ShowCourse();
}

