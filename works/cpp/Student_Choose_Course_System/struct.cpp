#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define Cnum 5
//课程数量
#define Nnum 20
// 课名长度
#define ErrCnum 5
//容错课程数量
#define ErrNnum 20
//容错课名长度
#define Gradenum 2
//班级数量
#define GNamenum 20
//班级名字长度
#define ErrGrade 2
#define ErrNGrade 20
#define Studentnum 1
//学生数量
#define ErrStudentnum 20
//可注册的学生数量
#define Teachernum 1
//老师数量
#define ErrTeachernum 20
//可注册的学生数量
#define PAUSE() system("read -p '-->按任意键结束<--' var")
#define key 1

using namespace std;
//User Dep----------------------------------------------------------------------------------------------------------------
typedef struct Student{//选择的指针占位符号, 选择存储的位置
    string name;//名字
    string ID;//学号
    string PassW;//密码
    int Grade;//班级序号
    int SuDel=0;
    int course[Cnum+ErrCnum]={0};//选择的课程编号(序号)最多的情况就是课程的数量选择的课程数 
    int CCourse=0;//学生已经选择的课程数量
}St;

typedef struct Teacher:public Student{
    int MGrade; 
    bool level=1;
}Te;

//Memory--------------------------------------------------------------------------------------------------------------
char course[Cnum][Nnum];//记录课程的名字和数量
char ErrCourse[ErrCnum][ErrNnum];//可以增加的课程即数量
int CourseStuSum[Cnum+ErrCnum][Nnum];//记录课程下的学生序号
int SuDeleteCourse[Cnum+ErrCnum];//老师要删除的课程序号
int Flag_ErrCourse;//增加的课程

char Gradecourse[Gradenum][GNamenum]; //班级信息
char ErrGradecourse[ErrGrade][ErrNGrade];
int GradeErr[Gradenum+ErrGrade];
int AddGrade;

St StuAcc[Studentnum]; //学生用户组
St ErrStuAcc[ErrStudentnum];//学生注册用户组织
int StuFlag;
Te TeaAcc[Teachernum]; //老师用户组
Te ErrTeaAcc[ErrTeachernum];//老师注册用户组
int TeaFlag;
int nowUsr=0; //区别老师和学生
int nowStu=0, nowTea=0; //此时程序处理的用户

//System keep-------------------------------------------------------------------------------------------------------
void Systeminit();
void QuitSystem();
bool GalSecuityJudge();
int InputCheck(int DownLimit, int Uplimit){
    int order=-1;
    do{
        cin>>order;
        if(!order) continue;
        if(order==-1) break;

        if(order<DownLimit||order>Uplimit)
            cout<< "[Tip]: 输入有误,请重新输入 -> ";        
    }while(order<DownLimit || order>Uplimit); 
    return order;
}

//System Tip------------------------------------------------------------------------------------------------------------
int IsStLogin(string);
int IsTeaLogin(string);
int IsStLoginID(string);
int IsTeaLoginID(string);
int IsCourseEx(string);
void PrintLogin();
void PrintLoginin();
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
string InputNameCheck();
int GradeNameCheck(string a);
int CourseNameCheck(string a);

int main(){
    int order;
    Systeminit();

Start: PrintLogin();
    PrintWelScreen();
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
    for(int i=0;i<Studentnum+StuFlag;i++){
        if(!StuAcc[i].SuDel)
            outfile<<StuAcc[i].name<<'\t'<<StuAcc[i].ID<<'\t'<<StuAcc[i].PassW<<'\t'<<Gradecourse[StuAcc[i].Grade]<<'\t'<<StuAcc[i].CCourse<<'\t';
        else continue;

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
        cout<<"请输入学号(教职工号)/名字进行登录:\n";
        cin>>account;
        cout<<"请输入你的密码:\n";
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
            StInitPassW="1";            
            if(password==StInitPassW)flag=1; 
            if(password==StuAcc[nowStu].PassW) flag=1;
        }
        if(nowUsr==2){//老师
            nowStu=SuSearchStID(account);
            if(nowStu==-1){nowStu=SuSearchStName(account);}
            if(nowStu==-1){ cout<<"[Error] 没有找到你输入的账户，请检查输入后再进行登录\n";continue;}
            TeaInitPassW="2";
            if(password==TeaInitPassW)flag=1;
            if(password==TeaAcc[nowTea].PassW)flag=1; 
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
void PrintLogin(){
    int order;
    do{
        cout<<"请选择登录还是注册.\n";
        cout<<"[1]\t登录\n"<<"[2]\t注册\n";
        cin>>order;
        if(order==1||order==2) break;
        system("reset");
    }while(order!=1||order!=2);

    system("reset");
    if(order==1) return;
    if(order==2) PrintLoginin();
}

void PrintLoginin(){
    int order;
    string Temp1,Temp2; 
    do{
        cout<<"请选择注册用户.\n";
        cout<<"[1]\t学生\n"<<"[2]\t老师\n";
        cin>>order;
        if(order==1||order==2)
        system("reset");
    }while(order!=1||order!=2);
    if(order==1){
        cin>>ErrStuAcc[Cnum+StuFlag].name;
        ErrStuAcc[Cnum+StuFlag].PassW=InputNameCheck();
        
        StuFlag++;
        cout<<"注册成功.\n";
    }
    if(order==2){
        cin>>ErrTeaAcc[Cnum+TeaFlag].name;
        ErrTeaAcc[Cnum+TeaFlag].PassW=InputNameCheck();
        TeaFlag++;
        cout<<"老师注册成功.\n";
    }
}

int IsStLogin(string a){
    int flag =-1;
    for(int i=0;i<Studentnum+ErrStudentnum;i++){
        if(StuAcc[i].name==a){
            flag=i;
            return flag;
        }
    }
    return flag;
}

int IsTeaLogin(string a){
    int flag =-1;
    for(int i=0;i<Teachernum+ErrTeachernum;i++){
        if(TeaAcc[i].name==a){
            flag=i;
            return flag;
        }
    }
    return flag;
}

int IsStLoginID(string a){
    int flag =-1;
    for(int i=0;i<Studentnum+ErrStudentnum;i++){
        if(StuAcc[i].ID==a){
            flag=i;
            return flag;
        }
    }
    return flag;
}

int IsTeaLoginID(string a){
    int flag =-1;
    for(int i=0;i<Teachernum+ErrTeachernum;i++){
        if(TeaAcc[i].ID==a){
            flag=i;
            return flag;
        }
    }
    return flag;
}

int IsCourseEx(string a){
    int flag=-1;
    for(int i=0;i<Cnum;i++){
        if(course[i]==a){flag=1; break;}
    }
    if(flag!=-1) return flag;
    for(int i=0;i<Flag_ErrCourse;i++){
        if(ErrCourse[i]==a){flag=1;break;}
    }
    return flag;
}

int IsGradeEx(string a){
    int flag=-1;
    for(int i=0;i<Gradenum;i++){
        if(Gradecourse[i]==a) {flag=1;break;}
    }
    if(flag!=-1) return flag;
    for(int i=0;i<AddGrade;i++){
        if(ErrGradecourse[i]==a){flag=1;break;}
    }
    return flag;
}

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
            string temp1; 
            cout<<"输入您要增加的课程\n";
            cin>>ErrCourse[Flag_ErrCourse];
            if(IsCourseEx(ErrCourse[Flag_ErrCourse])==-1){
                Flag_ErrCourse++;
                cout<<"添加成功.\n";
                PAUSE();
                system("reset");
            }
            else {
                cout<<"课程已存在, 添加失败, 请重新添加.\n";
                PAUSE();
                system("reset");
                continue;
            }
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

void SuShowGradeInfo(){//展示班级
    int step=1;
    for(int i=0;i<Gradenum+AddGrade;i++){
        if(i<Gradenum){
            if(!GradeErr[i])
                cout<<"["<<step++<<"] "<<'\t'<<Gradecourse[i];
            cout<<endl;
        }
        if(i>=Gradenum){
            if(!GradeErr[i])
                cout<<"["<<step++<<"]"<<'\t'<<ErrGradecourse[i-Gradenum];
            cout<<endl;
        }
    }
}

int FoundRealGrade(int a){
    int flag=-1, k=a;
    for(int i=0;i<Gradenum+AddGrade;i++){
        if(GradeErr[i])
            k--;
        if(!k){
            flag=i;
            return flag;
        }
    }
    return flag;
}

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

void SuDelGrade(){//删除班级
    int step;
    SuShowGradeInfo();
    cout<<"请输入想要删除班级的序号\n";
    cin>>step;
    step--;
    step=FoundRealGrade(step);
    cout<<"已选中 [";
    if(step<Gradenum)
        cout<<Gradecourse[step];
    else
        cout<<ErrGradecourse[step-Gradenum];
    cout<<"] , 请移动班级学生到其他班级中, 否则将会删除失败";
    SuShowGradeInfo();
    cin>>step;
    step--;
    step=FoundRealGrade(step);
    SuMoveStGrade(step);
    GradeErr[step]=1;//标记班级已经删除
    cout<<"删除班级成功\n";
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
        if(StuAcc[i].Grade==a) StuAcc[i].Grade=order-1;
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

string InputNameCheck(){
        string temp1,temp2;
        while(key){
        cout<<"请输入\n";
        cin>>temp1;
        cout<<"请再次输入\n";
        cin>>temp2;
        if(temp1==temp2) return temp1;
        else {
            cout<<"[Tip]: 两次输入不一致, 请检查后重新输入!!!\n";
            continue;
        }
    }
}

int GradeNameCheck(string a){
    for(int i=0;i<Gradenum+AddGrade;i++){
        if(i<Gradenum && Gradecourse[i]==a) return 1;
        if(i>=Gradenum && Gradecourse[i]==a) return 1;
    }
    return 0;
}

int CourseNameCheck(string a){
    for(int i=0;i<Cnum+ErrCnum;i++){
        if(i<Cnum && ErrCourse[i]==a) return 1;
        if(i>=Cnum && ErrCourse[i]==a) return 1;
    }
    return 0;
}
