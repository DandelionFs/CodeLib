/*//Ncode
// #include<bits/stdc++.h>
// using namespace std;
// struct Tang{
//     bool grade;
//     bool live;
//     int Cap;
// };
// int main(){
//     int T,n,m,step,temp,flag;
//     int clk;
//     Tang *p;
//     int *count;
//     cin>>T;
//     while(T--){
//         cin>>n>>m;
//         clk=0;
//         p=new Tang[n];
//         count=new int[m];

//         temp=n;
//         step=0;
//         for(int stepp=0;stepp<n;stepp++){
//             cin>>flag>>p[step].Cap;
//             if(flag) p[step].grade=true;
//             if(!flag) p[step].grade=false;
//             p[step].live=true;
//             step++;
//         }

//         temp=m;
//         step=0;
//         while(temp--){
//             cin>>count[step];
//             step++;
//         }

//         temp=n;
//         step=0;
//         while(temp--){
//             for(int i=clk;i>=0;i--){
//                 if(i==0) continue;
//                 for(int j=i-1;j>=0;j--){
//                     if(p[j].live && p[j].grade!=p[i].grade && p[j].Cap < p[i].Cap) 
//                         p[j].live= false; //标记前面的人清除
//                     }
//                 }
//             }

//             if(clk==count[step]-1) {
//                 for(int i=0;i<clk;i++){
//                     p[i].Cap++;
//                 }
//                 step++;
//             }//发功
//             clk++;
//         }
//         temp=0;
//         for(int i=0;i<n;i++){
//             if(p[i].live) temp++;
//         }
//     cout<<temp<<endl;
// }
*/


// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:

// };

#include<iostream>
#include<cstring>
using namespace std;
const  int  MaxListSize=100;//根据问题修改该值
class SeqCharList{
    char data[MaxListSize]; //存储字符串
    int size;            //元素个数
public:
    SeqCharList();//构造函数
    void Clear();//清空表
    bool IsEmpty();//判断如果为空表，返回true，否则返回false
    char Get(int k);//返回第k个字符
    int Locate(char e);//返回第一个与元素e匹配的元素位序
    char Delete(int i);//删除第i个元素，并返回所删除元素值
    void Print();//输出字符串
    void Encryption();//字符串加密
}; //SeqCharList

SeqCharList::SeqCharList(){size=0;}
void SeqCharList::Clear(){size=0;};
bool SeqCharList::IsEmpty(){
    if(size==0)return true;
    else return false;
}
char SeqCharList::Get(int k){return data[k-1];}
int SeqCharList::Locate(char e){
    int flag=-1;
    for(int i=0;i<size;i++){
        if(data[i]==e){flag=i;break;}
    }
    return flag;
}
char SeqCharList::Delete(int i){
    char ret=data[i-1];
    for(int j=i-1;j<size;j++){
        data[j]=data[j+1];
    }
    size--;
    return ret;
}
void SeqCharList::Print(){
    for(int i=0;i<size;i++){
        if(data[i]=='!'||data[i]=='#'||data[i]=='@'||data[i]=='+'||data[i]=='+'||data[i]=='-'||data[i]=='*'||data[i]=='?'||data[i]=='$'||data[i]==':'||data[i]==';')
            continue;
        cout<<data[i];
    }
}
void SeqCharList::Encryption(){
    int flag;
    cin>>flag;
    cin>>data;
    size=strlen(data);
    for(int i=0;i<strlen(data);i++){
        if(data[i]=='!'||data[i]=='#'||data[i]=='@'||data[i]=='+'||data[i]=='+'||data[i]=='-'||data[i]=='*'||data[i]=='?'||data[i]=='$'||data[i]==':'||data[i]==';')
            continue;
        data[i]+=flag;
    }
}

int main(){
    SeqCharList l1;
    while(1){
        l1.Encryption();
        l1.Print();
        cout<<endl;
    }
    return 0;
}

