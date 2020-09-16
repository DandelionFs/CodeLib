#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define Cnum 5
//课程数量
#define Nnum 20
// 课名长度
#define Studentnum 1
//学生数量
#define Teachernum 1
//老师数量
#define PAUSE() system("read -p '-->按任意键结束<--' var")
#define key 1

using namespace std;
//User Dep----------------------------------------------------------------------------------------------------------------
typedef struct Student{//选择的指针占位符号, 选择存储的位置
    string name;//名字
    string ID;//学号
    string PassW;//密码
    int course[Cnum]={0};//选择的课程编号(序号)最多的情况就是课程的数量选择的课程数 
    int CCourse=0;//学生已经选择的课程数量
}St;

typedef struct Teacher{
    string name;//名字
    string ID;//学号
    string PassW;//密码
    bool level=1;
}Te;

//Memory--------------------------------------------------------------------------------------------------------------
char course[Cnum][Nnum]={ ("大学数学"), ("大学英语") ,("大学语文") ,("大学物理") ,("大学化学")};
int CourseStuSum[Cnum][Nnum];//记录课程下的学生序号
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
int IsStLogin(string a);
int IsTeaLogin(string a);
int IsStLoginID(string a);
int IsTeaLoginID(string a);
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

Start:
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
                    if(order<0 || order > 5){
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
                    else if (order==4){ //注销 
                        cout<< "注销成功\n";
                        PAUSE();
                        system("reset");
                        goto Start;
                    }
                    else if(order==5){//退出
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
                    else if(order==4){//注销超级账户登录
                        cout<<"注销成功\n";
                        PAUSE();
                        system("reset");
                        goto Start;
                    }
                    else if(order==5){//退出选课系统
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
    StuAcc[0].name="111";
    StuAcc[0].PassW="1";

    TeaAcc[0].name="111";
    TeaAcc[0].PassW="1";
}

void QuitSystem(){//保存文件到目录下
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
            if(password==TeaAcc[nowTea].PassW) flag=1; 
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
    cout<<"-->基于结构体数组的选课系统<--\n";
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
     cout<<"[4]\t注销账户登录\n";
     cout<<"[5]\t退出选课系统\n";
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
    cout<<"[4]\t注销超级账户登录\n";
    cout<<"[5]\t退出选课系统\n";
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

//Student Operation------------------------------------------------------------------------------------------------------------------
void ShowCourse(){ // 展示现在存有的课程
    int jnum;
    int step=1;
    for(jnum=0; jnum<Cnum; jnum++){
        cout<<"["<<step++<<"]\t"<<course[jnum]<<'\n';
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
        if(num>Cnum) 
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
    
    flag=-1;
    for(int j=0;j< CourseStuSum[num-1][0];j++){
        if(nowStu==CourseStuSum[num-1][j+1]){flag=1;break;}
    }
    if(flag==-1) CourseStuSum[num-1][0]++;//改良set集合

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
        if(StuAcc[a].course[i]) 
            cout<<ii+1<<'\t'<<course[i]<<endl , ii++;
    
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

    for(int j=0;j<Cnum;j++){
        if(StuAcc[a].course[j] ) {
            if(order==1) {flag=j;break;}
            order--;
        }
    }

    cout<<"您选中[";
    cout<<course[flag];
    cout<< "]. 现在可以更换的课程是;\n";

    ShowCourse();
    cout<<"输入你要选择的课程(取消请按-1):\n"; 
    do{
        cin>>insteadnum;
        if(insteadnum>Cnum||insteadnum<-1)
            cout<<"请重新输入所选择的课程数. 必须存在在已列课程中! \n";
        if(insteadnum==-1) return;
    } while (insteadnum>Cnum);

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
    cout<<course[flag];
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

//Teacher Operation-----------------------------------------------------------------------------------------------------------------
void SuShowCourseAStudent(){//课程列表以及学生的信息
    int jnum;
    int step=1;
    for(jnum=0; jnum<Cnum; jnum++){
        cout<<"["<<step++<<"]\t"<<course[jnum]<<'\t';
            for(int j=0;j<Studentnum;j++){
                if(StuAcc[j].course[jnum])
                    cout<<StuAcc[j].name<<" ";
            }
        }
    cout<<endl;
}

void SuShowAllStINfo(){ //展示所有学生的选课信息
    cout<<"名字\t"<<"学号\t"<<"选课数量\t"<<"选择的课程\n";
    for(int i=0;i<Studentnum;i++){
            cout<<StuAcc[i].name<<'\t'<<StuAcc[i].ID<<'\t'<<StuAcc[i].CCourse<<'\t'<<'\t';
        for(int j=0 ;j<Cnum;j++)
            if(StuAcc[i].course[j]){
                    cout<<course[j]<<'\t';
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
        if(order==2) SearchCourse(flag);
        if(order==3) SwapCourse(flag);
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

int SearchRealCourseNum(int a){//返回现在的正确课程的序号
    int k=a,i=0,flag=0;
    while(key){
        if(k==0){flag=i;break;}
        k--;
        i++;
    }
    return flag;
}
