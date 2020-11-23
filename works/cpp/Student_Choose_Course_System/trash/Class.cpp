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
/*
/#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<sstream>

#define Cnum 5
//课程数量
#define ErrCnum 5
//增加课程数量
#define Gradenum 2
//班级数量
#define ErrGrade 2
//增加班级数量
#define Studentnum 1
//学生数量
#define ErrStudentnum 50
//注册学生数量
#define Teachernum 1
//老师数量
#define ErrTeachernum 50
//注册老师数量
#define PAUSE() system("read -p '-->按任意键结束<--' var")
#define key 1
using namespace std;

void Systeminit();
void QuitSystem();
bool GalSecuityJudge();
void ShowAllGrade();
void ShowAllCourse();
int SearchRealCourseNum(int);
void ChangeCourseStu(int,int);
int SuSearchStName(string);
int SuSearchStID(string);
int SuSearchTeaName(string);
int SuSearchTeaID(string);
int SuSearchCourseName(string);
int SuSearchGradeName(string);

//System Tip------------------------------------------------------------------------------------------------------------
void PrintWelScreen();
void PrintUsrAct();
void PrintChangeCourse();
void PrintUsrInfo();
void PrintChangeUsrInfo();
void PrintSuAct();
void PrintManStu();
void PrintSuChangeCInfo();
void PrintManGrade();
int InputCheck(int, int);
string InputNameCheck();

//Static Memory--------------------------------------------------------------------------------------------------------------
int StInitTemp, TeaInitTemp;
char TimeTable[24][6]={
    ("00:00"),("01:00"),("02:00"),("03:00"),("04:00"),("05:00"),("06:00"),("07:00"),("08:00"),
    ("09:00"),("10:00"),("11:00"),("12:00"),("13:00"),("14:00"),("15:00"),("16:00"),("17:00"),
    ("18:00"),("19:00"),("20:00"),("21:00"),("22:00"),("23:00")
};//设置时间
int nowUsr=0, nowStu=0, nowTea=0;//区别老师和学生 //处理的用户位次
int ErrTeachernumFlag, ErrStudentnumFlag,Flag_ErrCourse, ErrGradenumFlag;//注册老师,学生位置//增加的课程
int ATeachernum=Teachernum, AStudentnum=Studentnum,ACourse=Cnum, AGradenum=Gradenum;

typedef class SCourse{
private:
    //First Port
    bool SuDelete;//课程是否被删除
    bool CheckSelect;//检测课程是否被选择
    //Second Port
    string Name;
    int InitTime,EndTime;//时间
    int TeachTeacher;//负责的老师的序号
    bool Student[Studentnum+ErrStudentnum];//记录学生是否选择
public:
    SCourse(){CheckSelect=false,SuDelete=0,InitTime=EndTime=-1,TeachTeacher=-1;}
    ~SCourse(){InitTime=EndTime=-1;};
    
    string GetName(){return Name;}
    bool GetCheckSelect(){return CheckSelect;}
    bool GetSuDelete(){return SuDelete;}
    int GetInitTime(){return InitTime;}
    int GetEndTime(){return EndTime;}
    int GetTeachTeacher(){return TeachTeacher;}
    int GetCourseNum(){int a=SuSearchCourseName(Name);return a;};
    //First Port
    void PrintSetTime();//打印时间表
    void SetName();//设置课程名字
    void SetTime();//设置课程时间
    void SelectCourse();//选择课程
    void DeleteStuCourse();//删除课程
    void PrintSelectStu();//查看选择了该课程的学生
    //Second Port
    void AddCourse();//增加课程
    void DeleteCourse();//删除课程
    void RecordStuCourse(int);//标记该位置的学生课程选择
    void DelRecStuCourse(int);//删除上面的标记
}SC;

typedef class SGrade{
private:
    string Name;//班级名字
    bool SuDelete;//判定是否删除
    int TeacherManage;//指定一位老师管理
public:
    SGrade();
    ~SGrade();
    string GetName(){return Name;}
    bool GetSuDelete(){return SuDelete;}
    int GetTeacherManage(){return TeacherManage;}
    int GetGradeNum(){int a=SuSearchGradeName(Name);return a;}//返回全局课程数组的下标
    bool GradeStu[Studentnum+ErrStudentnum];//用位模式判断学生是否选课, 选课则True, 否则False
    // int GetGradeflag(){return Gradeflag;}

    void SetName(){ Name=InputNameCheck();}//输入名字
    int FoundRealGrade(int);//排除删除的课程,判断输入数字应当处理的正确课程下标
    void AddGrade();//增加班级
    void DeleteGrade();//删除班级
    void AllMoveGrade();//移动班级的学生
    void AllChooseCourse();//班级集体选课
    void AllDeleteCourse();//班级集体删除课程
}SG;

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
    Student();//初始化学生名字为DFS1,DFS2.
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

typedef class Teacher:public Student{
private:
    string Name;//名字
    string ID;//学号
    string PassW;//密码
    int LoginNum;//初次登录时验证密码
    int Grade;//管理班级
    bool SuDelete;
public:
    Teacher();
    ~Teacher();

    string GetName(){return Name;}
    string GetID(){return ID;}
    string GetPassW(){return PassW;}
    int GetLoginNum(){return LoginNum;}
    int GetGrade(){return Grade;}
    bool GetSuDelete(){return SuDelete;}

    void SuShowCourseAStudent();//课程列表以及学生的信息
    void SuSearchManStCourse();//查询指定学生选课情况
    void SuShowAllStINfo();//展示所有学生的选课信息
    void SuChangeGradeInfo(int);//单独改变a学生的班级信息
    void SuGradeManage();//管理班管理班级选课信息
    void SuChangeCInfo();//更改/增加/删除 课程信息
    void SuShowGradeInfo();//展示现存所有课程的信息
    void SuAddGrade();//增加班级及选课情况
    void SuDelGrade();//删除班级
    void SuMoveStGrade(int);//用对应班级来定位学生,从而移动学生到其他班级集体选课 段错误???
    void SuChooseStCourse(int);//选择班级课程
    void SuDelStCourse(int);//班级集体退课
}Te;

SC course[Cnum+ErrCnum];//记录课程的名字和数量//可以增加的课程即数量
SG Grade[Gradenum+ErrGrade]; //班级信息//增班设定
St StuAcc[Studentnum+ErrStudentnum]; //学生用户组//注册学生
Te TeaAcc[Teachernum+ErrTeachernum]; //老师用户组//注册老师

//////////////////////////////////////////////////////////

void SC::PrintSetTime(){
    int step=1;
    for(int i=0;i<24;i++){
	cout<<"["<<step++<<"] \t"<<TimeTable[i]<<'\t';
	if((i+1)%6==0) cout<<endl;
    }
}

void SC::SetName(){
    while(key){
	string temp1,temp2;
	cout<<"请输入课程的名字\n";
	cin>>temp1;
	cout<<"请再次输入课程的名字\n";
	cin>>temp2;
	if(temp1==temp2) Name=temp1;
	else {
	cout<<"两次的输入不相符, 请尝试重新输入\n";
	continue;
	}   
    }
}

void SC::SetTime(){
    while(key){
	cout<<"请输入该课程的上课时间.\n";
	cin>>InitTime;
	cout<<"请输入改课程的下课时间.\n";
	cin>>EndTime;
	if(InitTime<EndTime) break;
	else {
	    cout<<"课程时间设置有误,请注意是否时长足够一个小时!\n";
	    continue;
	}
    }
    cout<<"设置成功.\n此节课的上课时间是"<<InitTime<<" -> "<<EndTime;
}

void SC::SelectCourse(){
    CheckSelect=true;
}

void SC::DeleteStuCourse(){
    SuDelete=true;
}

void SC::PrintSelectStu(){
    for(int i=0;i<Cnum+Flag_ErrCourse;i++){
	if(!::course[i].GetSuDelete()){
	    for(int j=0;j<Studentnum+ErrStudentnum;j++){
		if(Student[j])
		    cout<<StuAcc[j].GetName()<<"\t";
	    }
	}
    }
}
//Second Port
void SC::AddCourse(){
    cout<<"输入想要增加的课程名字\n";
    cin>>Name;
    cout<<"输入想要的时间段\n";
    SetTime();
}

void SC::DeleteCourse(){
    ShowAllCourse();
    cout<<"输入想要删除的课程序号\n";
    int order=InputCheck(1,ACourse);
    order=SearchRealCourseNum(order);
    // order=FoundRealGrade(order);
    ::course[order].SuDelete=true;
    cout<<"删除成功";
}

void SC::RecordStuCourse(int a){
    int CI=GetCourseNum();
    ::course[CI].Student[a]=true;
}

void SC::DelRecStuCourse(int a){
    ::course[a].Student[a]=false;
}

//////////////////////////////////////////////////////////
SG::SGrade(){
    SuDelete=0;
    GradeStu[Studentnum+ErrStudentnum]={false};
    TeacherManage=-1;
}

SG::~SGrade(){}

int FoundRealGrade(int a){
    int k=a;
    for(int i=0;i<Gradenum+ErrGrade;i++){
	if(!Grade[i].GetSuDelete()){
	    k--;
	    if(!k){
		k=i;
		return k;
	    }
	}
    }
    k=-1;
    return k;
}

void SG::AddGrade(){
    cout<<"请输入要增加班级的名字\n";
    SetName();
    Gradeflag++;
    cout<<"增加成功\n";
}

void SG::DeleteGrade(){
    cout<<"请输入要删除班级的序号\n";
    ShowAllGrade();
    int order=InputCheck(1,AGradenum);
    order=FoundRealGrade(order);
    cout<<order<<endl;
    Grade[order].SuDelete=true;
    cout<<"删除成功.\n";
}

void SG::AllMoveGrade(){
    cout<<"你现在选择的班级是: ["<<Name<<"]\n";
    cout<<"选择你要移动的班级.\n";
    ShowAllGrade();
    int order=InputCheck(1,AGradenum);
    order=FoundRealGrade(order);
    for(int i=0;i<Studentnum+ErrStudentnum;i++){
	if(GradeStu[i]){
	    StuAcc[i].Grade.Name=Grade[order].GetName();
	    StuAcc[i].Grade.TeacherManage=Grade[order].GetTeacherManage();
	    StuAcc[i].Grade.Gradeflag=Grade[order].GetGradeflag();
	}
	    
    }
}

void SG::AllChooseCourse(){
    ShowAllCourse();
    cout<<"输入选择的序号\n";
    int order=InputCheck(1,Cnum+ACourse);
    order=SearchRealCourseNum(order);
    for(int i=0;i<Gradeflag;i++){
	StuAcc[GradeStu[i]].SimpleChoose(order);
    }
}

void SG::AllDeleteCourse(){
    ShowAllCourse();
    cout<<"输入选择的序号\n";
    int order=InputCheck(1,Cnum+ACourse);
    order=SearchRealCourseNum(order);
    for(int i=0;i<Studentnum+ErrStudentnum;i++){
	StuAcc[GradeStu[i]].course[order].DeleteCourse();
    }
}

//////////////////////////////////////////////////////////
St::Student(){
    string Temp;
    stringstream ss;
    ss<<StInitTemp;
    Temp=ss.str();
    ID=Temp;
    StInitTemp++;
    Name="DFS"+Temp;
    PassW="1";
    LoginNum=0;
    CCourse=0;
}//itoa(StInitTemp,name,10);方法失效

St::~Student(){}

int St::GetStNum(){
    int a=SuSearchStName(Name);
    if(a==-1) a=SuSearchStID(ID);
    return a;
}

void St::ChooseCourse(){
    int num;
    int flag; //查询课程下的学生是否选了这个课程
    char order;
    cout<<"请输入您需要选择的课程对应的序号(退出选课输入-1): \n";
    
    num=InputCheck(1,ACourse);
    num=SearchRealCourseNum(num);


    if(!(course[num-1].GetCheckSelect())) CCourse++;
    course[num-1].SelectCourse();

    if(!course[num-1].GetCheckSelect())
	cout<<"[Tip]: 你已经选择过该课程,请核对后再次选择!\n";
    
    if(num<=Cnum){
	int a=GetStNum();
	::course[num-1].RecordStuCourse(a);
    }

    system("reset");
    cout<<"恭喜你选课成功! :),  请问是否退出选课(默认继续)(y/n)\n";
    getchar();//吸收前面的空格
    order=getchar();
    system("reset");
    if(order=='y'|| order=='\n') {
	ShowAllCourse();
	ChooseCourse();
    }
    else if(order=='n')  return;
}

void St::SimpleChoose(int a){
    int temp=GetStNum();
    course[a].SelectCourse();
    ::course[a].RecordStuCourse(temp);
}

void St::SearchCourse(){
    int ii=0; 
    string temp;
    for(int i=0 ;i<Cnum+Flag_ErrCourse;i++) 
	if(course[i].GetCheckSelect() && (!(::course[i].GetSuDelete())))
	    cout<<ii+1<<'\t'<< (::course[i].GetName()) <<endl , ii++;
}

void St::SimpleSCourse(){
    string temp;
    for(int i=0 ;i<Cnum+Flag_ErrCourse;i++) 
	if(course[i].GetCheckSelect() && (!(::course[i].GetSuDelete())))
	    cout<< (::course[i].GetName()) <<'\t';
}

void St::SwapCourse(){
    int order, insteadnum;
    char corder;
    while(key){
	PrintChangeCourse();
	cin>>order;
	system("reset");
	if(order==-1) return;

	if(order==1) DeleteCCourse();
	else if(order == 2) ChangeStCourse();
    }
}

void St::ChangeStCourse(){
    int order,insteadnum;
    int flag;
    char corder;
    SearchCourse();
    cout<<"请输入你想换的课程序号:\n";
    cin>>order;
    if(order==-1) return;
    system("reset");

    for(int j=0;j<Cnum+Flag_ErrCourse;j++){
	if(course[j].GetCheckSelect() && (!::course[j].GetSuDelete())) {
	    if(order==1) {flag=j;break;}
	    order--;
	}
    }//输入指令的处理

    cout<<"您选中["<<::course[flag].GetName();
    cout<< "]. 现在可以更换的课程是;\n";
    ShowAllCourse();
    cout<<"输入你要选择的课程(取消请按-1):\n"; 
    do{
	cin>>insteadnum;
	if(insteadnum>Cnum+Flag_ErrCourse||insteadnum<-1)
	    cout<<"请重新输入所选择的课程数. 必须存在在已列课程中! \n";
	if(insteadnum==-1) return;
    } while (insteadnum>Cnum+Flag_ErrCourse);

    int location=0;
    order=flag;//复要被制替换的课程序号
    int Snum=GetStNum();

    insteadnum--;
    insteadnum=SearchRealCourseNum(insteadnum);

    course[insteadnum].SelectCourse();
    ::course[flag].DelRecStuCourse(Snum);
    ::course[insteadnum].RecordStuCourse(Snum);

    cout<<"换课完成, 已经把 [";
    cout<<course[flag].GetName();
    cout<<"] 换为:"<<::course[insteadnum].GetName()<<endl;
    PAUSE();
    system("reset");
    cout<<"你现在的课程情况是:\n";
    SearchCourse();
    cout<<"请问是否继续更改课程信息(y/n), 默认退出\n";
    getchar();
    corder=getchar();
    system("reset");//这里之前多了一个getchar()???
    
    if(corder=='y'||corder=='Y') {
	system("reset");
	SwapCourse();
    }
    return;
}

void St::DeleteCCourse(){
    int order,flag;
    char corder;
    int a=GetStNum();
    order=InputCheck(-1,GetCCourse());
    order--;
    order=SearchRealCourseNum(order);
    
    if(course[order].GetCheckSelect()) 
	CCourse--;
    course[order].DeleteStuCourse();
    ::course[a].DelRecStuCourse(order);
    Flag_ErrCourse--;
    system("reset");
    cout<<"课程 ["<<course[order].GetName();
    cout<<"] 已移除,现在的课程有\n";
    SearchCourse();
    PAUSE();
    system("reset");
}

void St::SimpleDelete(int a){
    int temp=GetStNum();
    course[a].DeleteStuCourse();
    ::course[a].DelRecStuCourse(temp);
}

void St::ChangeSelfInfo(){
    int order;
    string temp1,temp2;
    PrintUsrInfo();
    cout<<"请输入您想要的操作:\n";
    PrintChangeUsrInfo();

    order=InputCheck(-1,3);

    if(order==1){
	while(key){
	    cout<<"请输入想要更改的名字(-1退出)\n";
	    cin>>temp1;
	    if(temp1=="-1") return;
	    cout<<"请再次输入想要更改的名字(请注意和第一次的一致性,-1退出)\n";
	    cin>>temp2;
	    if(temp2=="-1") return;
	    if(temp1!=temp2) {
		cout<<"名字两次不一致, 请重新输入\n";
		continue;
	    }
	    Name=temp1;
	    cout<<"更改成功,现在你的名字是:\n";
	    cout<<Name<<endl;
	    PAUSE();
	    break;
	}   
    }
    else if(order==2){
	while(key){
	    cout<<"请输入想要更改的密码\n";
	    cin>>temp1;
	    cout<<"请再次输入想要更改的密码(注意两次的一致性)";
	    cin>>temp2;
	    if(temp1!=temp2) continue;
	    PassW=temp1;
	    cout<<"更改成功,现在你的密码是:\n";
	    cout<<PassW<<endl;
	    PAUSE();
	    break;
	}   
    }
}

//////////////////////////////////////////////////////////

Te::Teacher(){
    string Temp;
    stringstream ss;
    ss<<StInitTemp;
    Temp=ss.str();
    ID=Temp;
    TeaInitTemp++;
    Name="DFS"+Temp;
    PassW="1";
    LoginNum=0;
    Grade=-1;
}

void Te::SuShowCourseAStudent(){
    int step=1;
    for(int i =0;i<Cnum+Flag_ErrCourse;i++){
	if(::course[i].GetCheckSelect())
	    continue;//课程已删除，返回主函数
	cout<<"["<<step++<<"]"<<'\t'<<course[i].GetName()<<'\t';
	::course[i].PrintSelectStu();
	cout<<endl;
    }
}

void Te::SuSearchManStCourse(){
    int order, flag=-1;
    string temp; 
    cout<<"请选择学号查找还是名字查找: \n";
    cout<<"[1]\t学号查找\n";
    cout<<"[2]\t名字查找\n";
    order=InputCheck(1,2);
    system("reset");

    if(order==1){
	cout<<"请输入学生的学号进行查询:\n";
	cin>>temp;
	for(int i=0;i<Studentnum;i++){
	    if(StuAcc[i].GetID()==temp) {
		flag=i;break;
	    }
	}
    }
    else if(order==2){
	cout<<"请输入学生的名字进行查询\n";
	cin>>temp;
	for(int i=0;i<Studentnum;i++){
	    if(StuAcc[i].GetName()==temp){
		flag=i;break;
	    }
	}
    }
    if(flag==-1) 
	cout<<"对不起, 没有查找到该用户\n";
    if(flag!=-1) 
	cout<<"恭喜你, 查找成功\n";
    PAUSE();
    system("reset");

    while(key){
	cout<< "查询到的学生是"<<StuAcc[flag].GetName()<< "他的选课情况如下:\n";
	StuAcc[flag].SearchCourse();
	PrintManStu();
	order=InputCheck(-1,5);
	system("reset");

	if(order==-1) return;
	if(order==1) StuAcc[flag].DeleteCCourse();
	if(order==2) StuAcc[flag].SearchCourse();
	if(order==3) StuAcc[flag].SwapCourse();
	if(order==4) StuAcc[flag].ChangeSelfInfo();
	if(order==5) SuChangeGradeInfo(flag);
    }
}

void Te::SuShowAllStINfo(){
    cout<<"名字\t"<<"学号\t"<<"班级\t"<<"选课数量\t"<<"选择的课程\n";
    for(int i=0;i<Studentnum;i++){
	cout<<StuAcc[i].GetName()<<'\t'<<StuAcc[i].GetID()<<'\t';
	cout<<StuAcc[i].Grade.GetName()<<'\t'<<StuAcc[i].GetCCourse()<<'\t'<<'\t';
	StuAcc[i].SimpleSCourse();
	cout<<endl;
    }
}

void Te::SuChangeGradeInfo(int a){
    int order;
    cout<<"现在的学生的班级是:\n";
    cout<<::Grade[StuAcc[a].Grade.GetGradeNum()].GetName();
    cout<<"现在存在的班级有\n";
    SuShowGradeInfo();
    cout<<"输入你想要更换的班级\n";
    cin>>order;
    order=FoundRealGrade(order);
    StuAcc[a].Grade=::Grade[order];
}

void Te::SuGradeManage(){
    int order;
    int flag;
    while(key){
	system("reset");
	SuShowGradeInfo();
	cout<<"输入您要操作的班级(-1退出)\n";
	cin>>flag;

	if(flag==-1) return;

	if(flag> (Gradenum+Gradenum) || flag<0 ) {
	    cout<<"请重新输入正确的班级序号\n";
	    continue;
	}
	
	while(key){
	    system("reset");
	    cout<<"输入你想要为 [";
	    cout<<::Grade[flag-1].GetName();
	    cout<<"] 做的事情(-1退出)\n";

	    PrintManGrade();
	    cin>>order;
	    system("reset");

	    if(order==-1) break;
	    if(order<-1||order>4) {
		cout<<"请输入正确的序号\n";
		continue;
	    }        
	    
	    if(order==1){
		SuChooseStCourse(flag-1);
		PAUSE();
		continue;
	    }
	    else if(order==2){
		SuDelStCourse(flag-1);
		PAUSE();
		continue;
	    }
	    else if(order==3){
		SuAddGrade();
		PAUSE();
		continue;
	    }
	    else if(order==4){
		SuDelGrade();
		PAUSE();
		continue;
	    }
	}
    }
}

void Te::SuChangeCInfo(){
    int order;
    while(key){
	cout<<"现在的课程有:\n";
	ShowAllCourse();
	order=InputCheck(1,3);
	if(order==1){//增加课程
	    cout<<"输入您要增加的课程\n";
	    ::course[Cnum+Flag_ErrCourse].AddCourse();
	    Flag_ErrCourse++;
	}
	else if(order==2){//删除课程
	    ShowAllCourse();
	    cout<<"输入你想删除的课程(-1取消)\n";
	    cin>>order;
	    order=SearchRealCourseNum(order);
	    if(order==-1) continue;
	    ::course[order-1].DeleteCourse();
	    system("reset");
	    cout<<"删除 ["<<::course[order-1].GetName()<<"] 成功\n";
	    PAUSE();
	    system("reset");
	}
	else if(order==3){//更改课程
	    ShowAllCourse();
	    cout<< "输入你想更改的课程\n";
	    cin>>order;
	    order=SearchRealCourseNum(order);
	    if(order==-1) continue;
	    cout<<"你选择的是 ["<<::course[order-1].GetName()<<"] \n";
	    ::course[order-1].SetName();
	}
    }
}

void Te::SuShowGradeInfo(){
    for(int i=0;i<Gradenum+ErrGradenumFlag;i++){
	cout<<"["<<i+1<<"] "<<'\t'<<::Grade[i].GetName()<<endl;
    }
}

void Te::SuAddGrade(){
    cout<<"请输入想要增加的班级:\n";
    ::Grade[Gradenum+ErrGradenumFlag].AddGrade();
    ErrGradenumFlag++;
    AGradenum++;
    cout<<"增加班级成功!";
}

void Te::SuDelGrade(){
    int step;
    SuShowGradeInfo();
    cout<<"请输入想要删除班级的序号\n";
    cin>>step;
    step--;
    step=FoundRealGrade(step);
    cout<<"已选中 [";
    cout<<::Grade[step].GetName();
    cout<<"] , 请移动班级学生到其他班级中, 否则将会删除失败";
    SuMoveStGrade(step);
    ::Grade[step].DeleteGrade();//标记班级已经删除
    cout<<"删除班级成功";
}

void Te::SuMoveStGrade(int a){
    int order;
    cout<<"您已经选中 ["<<::Grade[a].GetName();
    cout<<"] 的全部学生, 请选择移动;\n";
    SuShowGradeInfo();
    cin>>order;
    order--;
    order=FoundRealGrade(order);
    for(int i=0;i<Studentnum+Flag_ErrCourse;i++)
	StuAcc[i].Grade=::Grade[order];
    cout<<"移动完成\n";
    PAUSE();
}

void Te::SuChooseStCourse(int a){
    int order;
    cout<<"您已经选中 ["<<::Grade[a].GetName();
    cout<<"] 的全部学生, 请选课(-1退出);\n";
    ShowAllCourse();
    cin>>order;
    if(order==-1) return;
    // order=FoundRealGrade(order);
    order=SearchRealCourseNum(order);
    for(int i=0;i<Studentnum+Flag_ErrCourse;i++){
	if(::Grade[a].GradeStu[i]){
	    StuAcc[i].SimpleChoose(order);
	}
    }
}

void Te::SuDelStCourse(int a){
    int order;
    cout<<"您已经选中 ["<<::Grade[a].GetName();
    cout<<"] 的全部学生, 请选择退课;\n";
    ShowAllCourse();
    cin>>order;
    order=SearchRealCourseNum(order);
    for(int i=0;i<Studentnum+Flag_ErrCourse;i++){
	if(::Grade[a].GradeStu[i]){
	    StuAcc[i].SimpleDelete(order);
	}
    }
}

///////////////////////////////////////////////////////

int main(){
    int order;
    Systeminit();

Start: PrintWelScreen();
    order=InputCheck(1,2);
    system("reset");

    if(order==1){ // 学生登录
	nowUsr=1;
	while(key){
	    if(GalSecuityJudge()){
		while(key){
		    system("reset"); 
		    PrintUsrAct();
		    cin>>order;
		    system("reset");

		    if(order<0 || order > 6){
			system("reset");
			cout<<"请根据提示重新输入!!!\n";
			continue;
		    }// 错误检查

		    if(order==1){ //课程列表及选课/*增加引用或者传入地址(数组下标)
			ShowAllCourse();
			StuAcc[nowStu].ChooseCourse();
			continue;
		    }
		    else if(order==2){//查询我的选课
			if(!(StuAcc[nowStu].GetCCourse())){
			    cout<<"现在没有选择任何课程.\n"; 
			    PAUSE();
			    continue;
			}
			cout<< "现在一共选择了"<<StuAcc[nowStu].GetCCourse()<<"门课程, 它们是: "<<endl;
			StuAcc[nowStu].SearchCourse();
			PAUSE();
			continue;
		    }
		    else if(order==3){//更改我的选课
			StuAcc[nowStu].SwapCourse();
			continue;
			}
		    else if(order==4){//更改我的资料
			StuAcc[nowStu].ChangeSelfInfo();
			continue;
			}
		    else if (order==5){ //注销 
			cout<< "注销成功\n";
			PAUSE();
			system("reset");
			goto Start;
		    }
		    else if(order==6){//退出
			QuitSystem();
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
	nowUsr=2;
	while(key){
	    if(GalSecuityJudge()){
		while(key){
		    system("reset"); 
		    PrintSuAct();
		    cin>>order;
		    system("reset");

		    if(order<0 || order > 7){
			cout<<"请根据提示重新输入!!!";
			continue;
		    }

		    if(order==1){ //课程列表及课程被选情况 
			TeaAcc[nowTea].SuShowCourseAStudent();
			PAUSE();
			system("reset");
		    }
		    else if(order==2){ //展示所有课程以及学生选课信息
			TeaAcc[nowTea].SuShowAllStINfo();
			PAUSE();
		    continue;
		    }
		    else if(order==3){//搜索并管理指定的学生, 可以姓名或者学好搜索
			TeaAcc[nowTea].SuSearchManStCourse();
			PAUSE();
			continue;
		    }
		    else if (order==4) { //管理班级选课信息
			TeaAcc[nowTea].SuGradeManage();
		    }
		    else if(order==5){ //更改/增加/删除 课程信息
			TeaAcc[nowTea].SuChangeCInfo();
			continue;   
		    }
		else if(order==6){//注销超级账户登录
			cout<<"注销成功\n";
			PAUSE();
			system("reset");
			goto Start;
		    }
		    else if(order==7){//退出选课系统
			QuitSystem();
			cout<<"期待您的下次使用! See U~\n";
			return 0;
		    }
		}
	    }     
	}
    }
}

//System keep------------------------------------------------------------------------------------------------------------
void Systeminit(){ //运用文件读写 , 写入学生的信息到全局数组里
    ifstream infile;
}

void QuitSystem(){//保存文件到目录下
    ofstream outfile;
}

bool GalSecuityJudge(){
    string account, password,TeaInitPassW,StInitPassW;
    int flag=0;
    while(key){
	cout<<"请输入学号(教职工号)/名字进行登录(输入-1退出):\n";
	cin>>account;
	cout<<"请输入你的密码(输入-1退出):\n";
	cin>>password;
	system("reset");

	if(nowUsr==1){//学生
	    nowStu=SuSearchStID(account);
	    if(nowStu==-1)
		nowStu=SuSearchStName(account);
	    if(nowStu==-1){
		cout<<"[Error] 没有找到你输入的账户，请检查输入后再进行登录\n";
		continue; 
	    }
	    if(password==StInitPassW)flag=1; 
	}

	if(nowUsr==2){//老师
	    nowStu=SuSearchStID(account);
	    if(nowStu==-1){nowStu=SuSearchStName(account);}
	    if(nowStu==-1){ cout<<"[Error] 没有找到你输入的账户，请检查输入后再进行登录\n";continue;}

	    StInitPassW="2";
	    if(password==TeaInitPassW)flag=1; 
	}
	if(flag){
	    cout<<"恭喜你, 登录成功"<<endl;
	    PAUSE();
	    return true;
	}  
	else {
	    system("reset"); 
	    cout<<"登录超时, 请尝试重新登录"<<endl;
	    PAUSE();
	    flag=0;
	}
    }
}

//System Print Tip------------------------------------------------------------------------------------------------------------------------------
void PrintWelScreen(){//打印开始登录界面
    cout<<"-->基于学生类数组的选课系统<--\n";
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
    StuAcc[nowStu].SearchCourse();
    cout<<"选择你想要的操作:\n";
    cout<<"[-1]\t返回主页面\n";
    cout<<"[1]\t删除指定选课\n";
    cout<<"[2]\t更换指定选课\n";
}

void PrintUsrInfo(){
    cout<<"您现在的用户资料是:\n";
    cout<<"[学号]\t"<<StuAcc[nowStu].GetID()<<'\t';
    cout<<"[名字]\t"<<StuAcc[nowStu].GetName()<<'\t';
    cout<<"[密码]\t"<<StuAcc[nowStu].GetPassW()<<'\n';
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
    cout<<"[-1]\t退出该页面\n";
    cout<<"[1]\t为班级同学集体选课\n";
    cout<<"[2]\t为班级同学集体退课\n";
    cout<<"[3]\t增加班级\n";
    cout<<"[4]\t删除班级\n";
}

void ShowAllGrade(){
    int step=1;
    for(int i=0;i<Gradenum+ErrGradenumFlag;i++){
	if(!Grade[i].GetSuDelete())
	    cout<<"["<<step++<<"]\t"<<Grade[i].GetName()<<endl;
    }
}

void ShowAllCourse(){//展示现在存有的课程
    int jnum, step=1;
    for(jnum=0; jnum<Cnum+Flag_ErrCourse; jnum++){
	if(!course[jnum].GetSuDelete())
	    cout<<"["<<step++<<"]\t"<<course[jnum].GetName()<<'\n';
    }
}

int SearchRealCourseNum(int a){//返回现在的正确课程的序号
    int k=a,i=0,flag=0;
    while(key){
	if(k==0){flag=i;break;}
	if(!::course[i].GetSuDelete())k--;
	i++;
    }
    return flag;
}

int SuSearchStName(string a){
    int flag=-1;
    for(int i=0;i<Studentnum+ErrStudentnumFlag;i++){
	if(StuAcc[i].GetName()==a) { flag=i;break;}
    }
    return flag;
}

int SuSearchStID(string a){
    int flag=-1;
    for(int i=0;i<Studentnum+ErrStudentnumFlag;i++){
	if(StuAcc[i].GetID()==a) { flag=i;break;}
    }
    return flag;
}

int SuSearchTeaName(string a){
    int flag=-1;
    for(int i=0;i<Teachernum+ErrTeachernum;i++){
	if(TeaAcc[i].GetName()==a) { flag=i;break;}
    }
    return flag;
}

int SuSearchTeaID(string a){
    int flag=-1;
    for(int i=0;i<Teachernum+ErrTeachernum;i++){
	if(TeaAcc[i].GetID()==a) { 
	    flag=i;break;
	}
     }
   return flag;
}

int SuSearchCourseName(string a){
    int flag=-1;
    for(int i=0;i<Teachernum+ErrTeachernum;i++){
	if(::course[i].GetName()==a) { 
	    flag=i;break;
	}
     }
   return flag;
}

int SuSearchGradeName(string a){
    int flag=-1;
    for(int i=0;i<Gradenum+ErrGradenumFlag;i++){
	if(::Grade[i].GetName()==a) { 
	    flag=i;break;
	}
     }
   return flag;

}

//Input Function------------------------------------------
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

string InputNameCheck(){
	string temp1,temp2;
	while(key){
	cout<<"请输入名字\n";
	cin>>temp1;
	cout<<"请再次输入名字\n";
	cin>>temp2;
	if(temp1==temp2) return temp1;
	else {
	    cout<<"[Tip]: 两次输入的名字不相同, 请检查后重新输入!!!\n";
	    continue;
	}
    }
}

缺点: 无法增加学生; 以后存班级用第二个位置存, 适当的预处理,而不是大量的预处理
增加班级变成移动班级
//字符串初始化, 通过askii实现长进制的加法
//初始化文件读写如何读写
/检查输入和其他的冲突

#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define Cnum 5
//课程数量
#define Nnum 20
// 课名长度
#define Gradenum 2
//班级数量
#define GNamenum 20
//班级名字长度
#define Studentnum 1
//学生数量
#define Teachernum 1
//老师数量
#define ErrCnum 5
//容错课程数量
#define ErrNnum 20
//容错课名长度
#define PAUSE() system("read -p '-->按任意键结束<--' var")
#define key 1

using namespace std;
//User Dep----------------------------------------------------------------------------------------------------------------
typedef class Student{//,  . 选择的指针占位符号, 选择存储的位置
    string name;//名字
    string ID;//学号
    string PassW;//密码
    int Grade;//班级序号
    int course[Cnum+ErrCnum]={0};//选择的课程编号(序号)最多的情况就是课程的数量选择的课程数 
    int CCourse=0;//学生已经选择的课程数量
}St;

typedef class Teacher:Student{
    bool level=1;
}Te;

//Memory--------------------------------------------------------------------------------------------------------------
char course[Cnum][Nnum];//记录课程的名字和数量
char ErrCourse[ErrCnum][ErrNnum];//可以增加的课程即数量
int CourseStuSum[Cnum+ErrCnum][Nnum];//记录课程下的学生序号
int SuDeleteCourse[Cnum+ErrCnum];//老师要删除的课程序号
int Flag_ErrCourse;//增加的课程

char Gradecourse[Gradenum][GNamenum]; //班级信息
char ErrGradecourse[Gradenum][GNamenum];
int GradeErr[Gradenum+Gradenum];
int AddGrade;

St StuAcc[Studentnum]; //学生用户组
Te TeaAcc[Teachernum]; //老师用户组
int nowUsr=0; //区别老师和学生
int nowStu=0, nowTea=0; //此时程序处理的用户

//System keep-------------------------------------------------------------------------------------------------------
void Systeminit();
void QuitSystem();
bool GalSecuityJudge();
int InputCheck(int DownLimit, int Uplimit){
    int order=-1;
    do{)
        cin>>order;
        if(!order) continue;
        if(order==-1) break;

        if(order<DownLimit||order>Uplimit)
            cout<< "[Tip]: 输入有误,请重新输入 -> ";        
    }while(order<DownLimit || order>Uplimit; 
    return order;
}

//System Tip------------------------------------------------------------------------------------------------------------
void PrintWelScreen();
void PrintUsrAct();
void PrintChangeCourse();
void PrintUsrInfo();
void PrintChangeUsrInfo();
void PrintSuAct();
void PrintManStu();
void PrintSuChangeCInfo();
void PrintManGrade();

//Student Operation, Show, Search , Delete -------------------------------------------------------------
void ShowCourse();
int SearchRealCourseNum(int);
void ChangeCourseStu(int,int);
int TextStCourse(int,int);
void ChooseCourse(int);
void SearchCourse(int);
void SwapCourse(int);
void ChangeStCourse(int);
void DeleteCCourse(int);
void ChangeSelfInfo(int);

//Teacher Operation------------------------------------------------------------------------------------------------
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

int main(){
    int order;
    Systeminit();

Start: PrintWelScreen();
    // do{
    //     cin>>order;
    //     if(order==1||order==2) break;
    //     else if(order!=1||order!=2) cout<<"请再次选择身份以进行再度登录\n";
    // }while(1);//先进行输入再进行判断
    order=InputCheck(1,2);

    system("reset");

    if(order==1){ // 学生登录
        nowUsr=1;
        while(key){
            if(GalSecuityJudge()){
                while(key){
                    system("reset");
                    PrintUsrAct();
                    cin>>order;
                    system("reset");

                    if(order<0 || order > 6){
                        system("reset");
                        cout<<"请根据提示重新输入!!!\n";
                        continue;
                    }// 错误检查

                    if(order==1){ //课程列表及选课/*增加引用或者传入地址(数组下标)*/
                        ShowCourse();
                        ChooseCourse(nowStu);
                        continue;
                    }
                    else if(order==2){//查询我的选课
                        if(!(StuAcc[nowStu].CCourse)) {
                            cout<<"现在没有选择任何课程.\n"; 
                            PAUSE();
                            continue;
                        }
                        cout<< "现在一共选择了"<<StuAcc[nowStu].CCourse<<"门课程, 它们是: "<<endl;
                        SearchCourse(nowStu);
                        PAUSE();
                        continue;
                    }
                    else if(order==3){//更改我的选课
                        SwapCourse(nowStu);
                        continue;
                        }
                    else if(order==4){//更改我的资料
                        ChangeSelfInfo(nowStu);
                        continue;
                        }
                    else if (order==5){ //注销 
                        cout<< "注销成功\n";
                        PAUSE();
                        system("reset");
                        goto Start;
                    }
                    else if(order==6){//退出
                        QuitSystem();
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
        nowUsr=2;
        while(key){
            if(GalSecuityJudge()){
                nowUsr=2;
                while(key){
                    system("reset"); 
                    PrintSuAct();
                    cin>>order;
                    system("reset");

                    if(order<0 || order > 7){
                        cout<<"请根据提示重新输入!!!";
                        continue;
                    }

                    if(order==1){ //课程列表及课程被选情况 
                        SuShowCourseAStudent();
                        PAUSE();
                        system("reset");
                    }
                    else if(order==2){ //展示所有课程以及学生选课信息
                        SuShowAllStINfo();
                        PAUSE();
                        continue;
                    }
                    else if(order==3){//搜索并管理指定的学生, 可以姓名或者学好搜索
                        SuSearchManStCourse();
                        PAUSE();
                        continue;
                    }
                    else if (order==4) { //管理班级选课信息
                        SuGradeManage();
                    }
                    else if(order==5){ //更改/增加/删除 课程信息
                        SuChangeCInfo();
                        continue;   
                    }
                    else if(order==6){//注销超级账户登录
                        cout<<"注销成功\n";
                        PAUSE();
                        system("reset");
                        goto Start;
                    }
                    else if(order==7){//退出选课系统
                        QuitSystem();
                        cout<<"期待您的下次使用! See U~\n";
                        return 0;
                    }
                }
            }     
        }
    }
}

//System keep------------------------------------------------------------------------------------------------------------
void Systeminit(){ //运用文件读写 , 写入学生的信息到全局数组里
    ifstream infile;

    infile.open("./data/CourseInfo.in"); //初始化课程信息
    for(int i=0;i<Cnum;i++) 
        infile>>course[i];
    infile.close();

    infile.open("./data/GradeInfo.in");//初始化班级信息
    for(int i=0;i<Gradenum;i++) 
        infile>>Gradecourse[i];
    infile.close();

    infile.open("./data/StInfo.in");//初始化学生信息
    for(int i=0;i<Studentnum;i++)
        infile>>StuAcc[i].name>>StuAcc[i].ID>>StuAcc[i].PassW>>StuAcc[i].Grade;
    infile.close();

    infile.open("./data/TeaInfo.in");//初始化老师信息
    for(int i=0;i<Teachernum;i++)
        infile>>TeaAcc[i].name>>TeaAcc[i].ID>>TeaAcc[i].PassW>>TeaAcc[i].Grade;
    infile.close();
}

void QuitSystem(){//保存文件到目录下
    ofstream outfile;

    outfile.open("./data/CourseInfo.out"); // 写入课程信息
    for(int i=0;i<Cnum+ErrCnum;i++){
        if(i<Cnum)
            outfile<<course[i]<<endl;
        else 
            outfile<<ErrCourse[i-Cnum]<<endl;
    }
    outfile.close();
    
    outfile.open("./data/GradeInfo.out");//写入班级信息
    for(int i=0;i<AddGrade+Gradenum;i++){ 
        if(i<Gradenum)
            outfile<<Gradecourse[i]<<endl;
        else
            outfile<<ErrGradecourse[i-Gradenum]<<endl;
    }
    outfile.close();
    
    outfile.open("./data/StInfo.out");//写入学生信息
    for(int i=0;i<Studentnum;i++){
        outfile<<StuAcc[i].name<<'\t'<<StuAcc[i].ID<<'\t'<<StuAcc[i].PassW<<'\t'<<Gradecourse[StuAcc[i].Grade]<<'\t'<<StuAcc[i].CCourse<<'\t';
        
        for(int j=0;j<Cnum;j++){
            if(StuAcc[i].course[j] && !SuDeleteCourse[j]) 
                outfile<<course[j]<<'\t';
        }
        if(!Flag_ErrCourse) {
            outfile<<endl;
            return;
        }//没有增加课程信息
        for(int j=0;j<Flag_ErrCourse;j++){
            if(StuAcc[i].course[Cnum+j] && !SuDeleteCourse[Cnum+j])
                outfile<<ErrCourse[j]<<'\t';
        }
        outfile<<endl;
    }
    outfile.close();

}

bool GalSecuityJudge(){
    string account, password,TeaInitPassW,StInitPassW;
    int flag=0;
    while(key){
        cout<<"请输入学号(教职工号)/名字进行登录(输入-1退出):\n";
        cin>>account;
        // if(account=="-1") return;
        cout<<"请输入你的密码(输入-1退出):\n";
        cin>>password;
        // if(password=="-1") return;

        system("reset"); 

        if(nowUsr==1){//学生
            nowStu=SuSearchStID(account);
            if(nowStu==-1)
                nowStu=SuSearchStName(account);

            if(nowStu==-1){
                cout<<"[Error] 没有找到你输入的账户，请检查输入后再进行登录\n";
                continue; 
            }
            StInitPassW="1";            
            if(password==StInitPassW)flag=1; 
        }

        if(nowUsr==2){//老师
            nowStu=SuSearchStID(account);
            if(nowStu==-1){nowStu=SuSearchStName(account);}
            if(nowStu==-1){ cout<<"[Error] 没有找到你输入的账户，请检查输入后再进行登录\n";continue;}

            TeaInitPassW="2";
            if(password==TeaInitPassW)flag=1; 
        }

        if(flag){
            cout<<"恭喜你, 登录成功"<<endl;
            PAUSE();
            return true;
        }  
        else {
            system("reset"); 
            cout<<"登录超时, 请尝试重新登录"<<endl;
            PAUSE();
            flag=0;
        }
    }
}

//System Print Tip------------------------------------------------------------------------------------------------------------------------------
void PrintWelScreen(){//打印开始登录界面
    cout<<"-->基于学生结构体数组的选课系统<--\n";
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
void ShowCourse(){ // 展示现在存有的课程
    int jnum;
    int step=1;
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

int SearchRealCourseNum(int a){//返回现在的正确课程的序号
    int k=a,i=0,flag=0;
    while(key){
        if(k==0){flag=i;break;}
        if(!SuDeleteCourse[i])k--;
        i++;
    }//*1
    return flag;
}

void ChangeCourseStu(int flag, int a){//操作CourseStuSum数组的函数, 替换掉flag课程下的a
    if( CourseStuSum[flag][0] && CourseStuSum[flag][(CourseStuSum[flag][0])-1]==a){
        CourseStuSum[flag][CourseStuSum[flag][0]-1]=-1;
        CourseStuSum[flag][0]--; //课程最后一个位置是a 原课程的学生位置移除完毕}
    }
    else if(CourseStuSum[flag][0] && CourseStuSum [flag][CourseStuSum[flag][0]-1] !=a){//课程最后一个不是a
        for(int j=1;j<=CourseStuSum[flag][0];j++){
            if(CourseStuSum[flag][j]==a)
                CourseStuSum[flag][j]=-1;
        }
    }
}

int TextStCourse(int flag,int a){
    int sameflag=0;
    for(int i=1;i<=CourseStuSum[flag][0];i++)
        if(CourseStuSum[flag][i]==a){ sameflag=1;break;}
    return sameflag;
}

void ChooseCourse(int a){//进行已有的课程的选择
    int num, flag;//flag查询课程下的学生是否选了这个课程
    char order;
    cout<<"请输入您需要选择的课程对应的序号(退出选课输入-1): \n";
    do{
        cin>>num;//xygf
        if(num>Cnum+Flag_ErrCourse) 
            cout<<"请重新输入所选择的课程数. 必须存在在已列课程中! \n";
        else if(num==-1) return;
    } while (num>Cnum);//输入一定要用循环

    num=SearchRealCourseNum(num);

    if(!(StuAcc[a].course[num-1]))StuAcc[a].CCourse++;

    StuAcc[a].course[num-1]++;

    if(StuAcc[a].course[num-1]==2)
        cout<<"[Tip]: 你已经选择过该课程,请核对后再次选择!\n";
    
    //增加对应课程统计的数组操作
    CourseStuSum[num-1][CourseStuSum[num-1][0]]=a;
    
    flag=0;
    for(int j=0;j< CourseStuSum[num-1][0];j++){
        if(nowStu==CourseStuSum[num-1][j+1]){flag=1;break;}
    }
    if(!flag)CourseStuSum[num-1][0]++;//改良set集合

    system("reset");
    cout<<"恭喜你选课成功! :),  请问是否退出选课(默认继续)(y/n)\n";
    getchar();//吸收前面的空格
    order=getchar();
    system("reset");
    if(order=='y'|| order=='\n') {
        ShowCourse();
        ChooseCourse(a);
    }
    else if(order=='n')  return;
}

void SearchCourse(int a){//学生查看自己的选课情况
    int ii=0; 
    for(int i=0 ;i<Cnum;i++) 
        if(StuAcc[a].course[i] && (!SuDeleteCourse[i])) 
            cout<<ii+1<<'\t'<<course[i]<<endl , ii++;
    
    if(!Flag_ErrCourse) return;

    for(int i=0;i<Flag_ErrCourse;i++)
        if(StuAcc[a].course[Cnum+i] && (!SuDeleteCourse[Cnum+i]))
           cout<<ii+1<<'\t'<<ErrCourse[i]<<endl, ii++;
}

void SwapCourse(int a){// 删除和更换学生选课
    int order, insteadnum;
    char corder;
    while(key){
        PrintChangeCourse();
        cin>>order;
        system("reset");
        if(order==-1) return;

        if(order==1) DeleteCCourse(a);
        else if(order == 2) ChangeStCourse(a);
    }
}

void ChangeStCourse(int a){//换课
    int order, insteadnum;
    int flag;
    char corder;
    SearchCourse(a);
    cout<<"请输入你想换的课程序号:\n";
    cin>>order;
    if(order==-1) return;
    system("reset");

    for(int j=0;j<Cnum+Flag_ErrCourse;j++){
        if(StuAcc[a].course[j] && (!SuDeleteCourse[j])) {
            if(order==1) {flag=j;break;}
            order--;
        }
    }

    cout<<"您选中[";
    if(flag<Cnum)cout<<course[flag];
    else cout<<ErrCourse[flag-Cnum];
    cout<< "]. 现在可以更换的课程是;\n";

    ShowCourse();
    cout<<"输入你要选择的课程(取消请按-1):\n"; 
    do{
        cin>>insteadnum;
        if(insteadnum>Cnum+Flag_ErrCourse||insteadnum<-1)
            cout<<"请重新输入所选择的课程数. 必须存在在已列课程中! \n";
        if(insteadnum==-1) return;
    } while (insteadnum>Cnum+Flag_ErrCourse);

    int location=0;
    order=flag;//复要被制替换的课程序号
    
    insteadnum--;
    insteadnum=SearchRealCourseNum(insteadnum);

    StuAcc[a].course[flag]=0;

    ChangeCourseStu(flag,a);//移除flag下的a同学

    if(!TextStCourse(insteadnum,a)){
        CourseStuSum[insteadnum][CourseStuSum[flag][0]]=a;
        CourseStuSum[insteadnum][0]++;
        StuAcc[a].course[insteadnum]++;
    }

    cout<<"换课完成, 已经把 [";
    if(flag<Cnum)
        cout<<course[flag];
    else 
        cout<<ErrCourse[flag-Cnum];

    cout<<"] 换为:"<<course[insteadnum]<<endl;
    PAUSE();
    system("reset");
    cout<<"你现在的课程情况是:\n";
    SearchCourse(a);
    cout<<"请问是否继续更改课程信息(y/n), 默认退出\n";
    getchar();
    corder=getchar();
    system("reset");//这里之前多了一个getchar()???
    
    if(corder=='y'||corder=='Y') {
        system("reset");
        SwapCourse(a);
    }
    return;
}

void DeleteCCourse(int a){//根据学生数组打印学生课程; 拿课程去查学生, 选课的时候存上编号.
    int order,flag;
    char corder;
    do{
        SearchCourse(a);
        cout<<"请输入您想删除的课程的序号(按 -1 取消删除):\n";
        cin>>order;
        system("reset");

        if(order==-1) return;
        if(order>StuAcc[a].CCourse||order<0) {
            system("reset");
            cout<<"删除失败, 因为输入序号不是有效课程, 请重新输入对应序号\n" ;
            continue;
        }
    }while(order>StuAcc[a].CCourse||order<0);
    order--;
    order=SearchRealCourseNum(order);
    if(StuAcc[a].course[order]) StuAcc[a].CCourse--;
    StuAcc[a].course[order]=0;
    ChangeCourseStu(a,order);
    system("reset");
    cout<<"课程 ["<<course[order];
    cout<<"] 已移除,现在的课程有\n";
    SearchCourse(a);
    PAUSE();
    system("reset");
}

void ChangeSelfInfo(int a){//更改自己的名字, 密码以及ID
    int order;
    string temp1,temp2;
    PrintUsrInfo();
    cout<<"请输入您想要的操作:\n";
    PrintChangeUsrInfo();
    do{
        cin>>order;
        if(order==-1) return;
        
        if(order>3||order<0){
            cout<<"请重新输入操作\n";
            continue;
        }

        if(order<3&&order>0) break;

    } while (order>3||order<0);//输入一定要用循环
    
    if(order==1){
        while(key){
            cout<<"请输入想要更改的名字(-1退出)\n";
            cin>>temp1;
            if(temp1=="-1") return;

            cout<<"请再次输入想要更改的名字(请注意和第一次的一致性,-1退出)\n";
            cin>>temp2;
            if(temp2=="-1") return;

            if(temp1!=temp2) continue;
            StuAcc[a].name=temp1;
            cout<<"更改成功,现在你的名字是:\n";
            cout<<StuAcc[a].name<<endl;
            PAUSE();
            break;
        }   
    }
    else if(order==2){
        while(key){
            cout<<"请输入想要更改的密码\n";
            cin>>temp1;
            cout<<"请再次输入想要更改的密码(注意两次的一致性)";
            cin>>temp2;
            if(temp1!=temp2) continue;
            StuAcc[a].PassW=temp1;
            cout<<"更改成功,现在你的密码是:\n";
            cout<<StuAcc[a].PassW<<endl;
            PAUSE();
            break;
        }   
    }
}

//Teacher Operation-----------------------------------------------------------------------------------------------------------------
void SuShowCourseAStudent(){//课程列表以及学生的信息
    int step=1;
    for(int i =0;i<Cnum;i++){
        if(SuDeleteCourse[i])
            continue;//课程已删除，返回主函数
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

void SuSearchManStCourse(){//查询指定学生选课情况
    int order, flag=-1;
    string temp; 
    cout<<"请选择学号查找还是名字查找: \n";
    cout<<"[1]\t学号查找\n";
    cout<<"[2]\t名字查找\n";
    cin>>order;
    system("reset");

    if(order==1){
        cout<<"请输入学生的学号进行查询:\n";
        cin>>temp;
        for(int i=0;i<Studentnum;i++){
            if(StuAcc[i].ID==temp) {
                flag=i;break;
            }
        }
    }
    else if(order==2){
        cout<<"请输入学生的名字进行查询\n";
        cin>>temp;
        for(int i=0;i<Studentnum;i++){
            if(StuAcc[i].name==temp){
                flag=i;break;
            }
        }
    }
    if(flag==-1) cout<<"对不起, 没有查找到该用户\n";
    if(flag!=-1) cout<<"恭喜你, 查找成功\n";

    PAUSE();
    system("reset");

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
        if(order==1) DeleteCCourse(flag);
        if(order==2) SearchCourse(flag);//ShowCourse(flag);
        if(order==3) SwapCourse(flag);
        if(order==4) ChangeSelfInfo(flag);
        if(order==5) SuChangeGradeInfo(flag);
    }
}

void SuChangeGradeInfo(int a){//单独改变a学生的班级信息
    int order;

    cout<<"现在的班级是:\n";
    
    if(StuAcc[a].Grade<Gradenum)
        cout<<Gradecourse[StuAcc[a].Grade];
    else
        cout<<ErrCourse[StuAcc[a].Grade-Gradenum];

    cout<<"现在存在的班级有\n";

    SuShowGradeInfo();
    cout<<"输入你想要更换的班级\n";
    cin>>order;
    StuAcc[a].Grade=order-1;
}

void SuGradeManage(){//管理班管理班级选课信息
    int order;
    int flag;
    while(key){
        system("reset");
        SuShowGradeInfo();
        cout<<"输入您要操作的班级(-1退出)\n";
        cin>>flag;

        if(flag==-1) return;

        if(flag> (Gradenum+Gradenum) && AddGrade==0 || flag<0 ) {
            cout<<"请重新输入正确的班级序号\n";
            continue;
        }
        
        while(key){
            system("reset");
            cout<<"输入你想要为 [";
            cout<<Gradecourse[flag-1];
            cout<<"] 做的事情(-1退出)\n";

            PrintManGrade();
            cin>>order;
            system("reset");

            if(order==-1) break;
            if(order<-1||order>4) {
                cout<<"请输入正确的序号\n";
                continue;
            }        
            
            if(order==1){
                SuChooseStCourse(flag-1);
                PAUSE();
                continue;
            }
            else if(order==2){
                SuDelStCourse(flag-1);
                PAUSE();
                continue;
            }
            else if(order==3){
                SuAddGrade();
                PAUSE();
                continue;
            }
            else if(order==4){
                SuDelGrade();
                PAUSE();
                continue;
            }
        }
    }
}

void SuChangeCInfo(){//更改/增加/删除 课程信息
    int order;
    // string sorder;
    while(key){
        cout<<"现在的课程有:\n";
        ShowCourse();
        do{
            PrintSuChangeCInfo();
            cin>>order;
            if(order==-1) return;
            if(order==1||order==2||order==3) break;
            else cout<<"请重新输入!!!";
            system("reset");
        }while(order<-1||order>3);

        if(order==1){//增加课程
            cout<<"输入您要增加的课程\n"; 
            cin>>ErrCourse[Flag_ErrCourse];
            Flag_ErrCourse++;
        }
        else if(order==2){//删除课程
            ShowCourse();
            cout<<"输入你想删除的课程(-1取消)\n";
            cin>>order;

            order=SearchRealCourseNum(order);

            if(order==-1) continue;
            SuDeleteCourse[order-1]=1;
            system("reset");
            
            for(int i=1;i<=CourseStuSum[order][0];i++)
                StuAcc[CourseStuSum[order][i]].CCourse--;//选择数量减少

            if(order<Cnum) cout<<"删除 ["<<course[order-1]<<"] 成功\n";
            else cout<<"删除 ["<<ErrCourse[order-Cnum]<<"] 成功\n";
            PAUSE();
            system("reset");
        }
        else if(order==3){//更改课程
            ShowCourse();
            cout<< "输入你想更改的课程\n";
            cin>>order;

            order=SearchRealCourseNum(order);

            if(order==-1) continue;
            if(order<Cnum) {
                cout<<"你选择的是 ["<<course[order-1]<<"] \n"<<"输入你想要更改的名字:\n";
                cin>>course[order-1];
            }
            else {
                cout<<"你选择的是 ["<<ErrCourse[order-Cnum-1]<<"] \n"<<"输入你想要更改的名字:\n";
                cin>>ErrCourse[order-Cnum-1];
            }
        }
    }
}

void SuShowGradeInfo(){//展示现存所有课程的信息
    for(int i=0;i<Gradenum+AddGrade;i++){
        if(i<Gradenum){
            if(!GradeErr[i])
                cout<<"["<<i+1<<"] "<<'\t'<<Gradecourse[i];
            cout<<endl;
        }
        if(i>Gradenum ){
            if(!GradeErr[i-Gradenum])
                cout<<i+1<<'\t'<<ErrGradecourse[i-Gradenum];
            cout<<endl;
        }
    }
}

void SuAddGrade(){//增加班级及选课情况
    cout<<"请输入想要增加的课程:\n";
    cin>>ErrGradecourse[AddGrade];
    AddGrade++;
    cout<<"增加班级成功!";
}

void SuDelGrade(){//删除班级
    int step;
    SuShowGradeInfo();
    cout<<"请输入想要删除班级的序号\n";
    cin>>step;
    cout<<"已选中 [";
    if(step<Gradenum)
        cout<<Gradecourse[step];
    else
        cout<<ErrGradecourse[step-Gradenum];
    cout<<"] , 请移动班级学生到其他班级中, 否则将会删除失败";
    SuMoveStGrade(step);
    GradeErr[step]=1;//标记班级已经删除
    cout<<"删除班级成功";
}

void SuMoveStGrade(int a){//用对应班级来定位学生,从而移动学生到其他班级集体选课 段错误???
    int order;
    cout<<"您已经选中 [";
    if(a<Gradenum)
        cout<<Gradecourse[a];
    else
        cout<<ErrGradecourse[a-Gradenum];
    cout<<"] 的全部学生, 请选择移动;\n";
    SuShowGradeInfo();
    cin>>order;
    for(int i=0;i<Studentnum;i++){
        if(StuAcc[i].Grade==a-1) StuAcc[i].Grade=order-1;
    }
    cout<<"移动完成\n";
    PAUSE();
}

void SuChooseStCourse(int a){//选择班级课程
    int order;
    cout<<"您已经选中 [";
    if(a<Gradenum)
        cout<<Gradecourse[a];
    else
        cout<<ErrGradecourse[a-Gradenum];
    cout<<"] 的全部学生, 请选课(-1退出);\n";

    ShowCourse();
    cin>>order;
    if(order==-1) return;
    order=SearchRealCourseNum(order);

    for(int i=0;i<Studentnum;i++){
        if(StuAcc[i].Grade==a-1){
            if(!StuAcc[i].course[order-1]) StuAcc[i].CCourse++;
            StuAcc[i].course[order-1]++;
            for(int j=1;j<=CourseStuSum[order-1][0];j++)
                if(CourseStuSum[order-1][j]==i) return; //如果原来有这个课程, 不要在预处理学生课程中加
            CourseStuSum[order-1][CourseStuSum[order][0]]=i;
            CourseStuSum[order-1][0]++;
        }
    }
}

void SuDelStCourse(int a){//班级集体退课
    int order;
    cout<<"您已经选中 [";
    if(a<Gradenum)
        cout<<Gradecourse[a];
    else
        cout<<ErrGradecourse[a-Gradenum];
    cout<<"] 的全部学生, 请选择退课;\n";

    ShowCourse();
    cin>>order;

    order=SearchRealCourseNum(order);

    for(int i=0;i<Studentnum;i++){
        if(StuAcc[i].Grade==a-1){
            if(!StuAcc[i].course[order-1]) StuAcc[i].CCourse--;
            StuAcc[i].course[order-1]=0;
            ChangeCourseStu(i,order);
        }
    }
}

int SuSearchStName(string a){
    int flag=-1;
    for(int i=0;i<Studentnum;i++){
        if(StuAcc[i].name==a) { flag=i;break;}
    }
    return flag;
}

int SuSearchStID(string a){
    int flag=-1;
    for(int i=0;i<Studentnum;i++){
        if(StuAcc[i].ID==a) { flag=i;break;}
    }
    return flag;
}

int SuSearchTeaName(string a){
    int flag=-1;
    for(int i=0;i<Teachernum;i++){
        if(TeaAcc[i].name==a) { flag=i;break;}
    }
    return flag;
}

int SuSearchTeaID(string a){
    int flag=-1;
    for(int i=0;i<Teachernum;i++){
        if(TeaAcc[i].ID==a) { 
            flag=i;break;
        }
     }
   return flag;
}

/*缺点: 无法增加学生; 以后存班级用第二个位置存, 适当的预处理,而不是大量的预处理*/
/*增加班级变成移动班级*/
*/
