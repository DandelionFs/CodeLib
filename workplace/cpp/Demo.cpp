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
//Leecode
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     // vector<int> twoSum(vector<int>& nums, int target) {
//     //     map<int , int>p;
//     //     map<int , int>::iterator it;
//     //     int Msize=nums.size();
//     //     for(int i=0;i<Msize;i++){
//     //         // p.insert(i,sums[i]);
//     //         p.insert(pair<int,int>(i,nums[i]));
//     //     }    
//     //     for(int j=0;j<Msize;j++){
//     //         it=p.find(target-nums[j]);
//     //         // ptarget-nums[j]
//     //         return {it->first,it->second};
//     //     }
//     // }
//     vector<int> twoSum(vector<int>& nums, int target) {
//     }
// };
#include<iostream>
using namespace std;
const int MaxStackSize=10; //栈最大容量（根据问题修改该值）
template<class T>
class SeqStack {
    T StackList[MaxStackSize];
    int top;   //指示栈顶的变量
public:
    SeqStack();//构造函数
    bool IsEmpty();//判断栈空
    bool IsFull() ;//判断栈满
    void Push(const T x);
    T Pop();   //出栈
    void Clear() ;   //置栈空
    void Conversion(int M, int N);   //进制转换，并输出结果
}; //SeqStack
template<class T>SeqStack<T>::SeqStack(){top=-1;}
template<class T>bool SeqStack<T>::IsEmpty(){
    if(top==-1) return true;
    else return false;
}
template<class T>bool SeqStack<T>::IsFull(){
    if(top==MaxStackSize-1) return true;
    else return false;
}
template<class T>void SeqStack<T>::Push(const T x){//入栈
    if(IsFull()) return ;
    else StackList[++top]=x;
}
template<class T>T SeqStack<T>::Pop(){
    if(IsEmpty()) exit(1);
    return StackList[top--];
}
template<class T>void SeqStack<T>::Clear(){
    top=-1;
}
template<class T>void SeqStack<T>::Conversion(int M,int N){//进制转换，并输出结果
    SeqStack<T>p;
    T temp;
    while(M){
        p.Push(M%N);
        M/=N;
    }
    while(!p.IsEmpty()){
        temp=p.Pop();
        cout<<temp;
    }
    cout<<endl;
}

int main(){
    int m,n;
    SeqStack<int>oo;
    do{
        cin>>m>>n;
        if(m==-1 && n==-1) return 0;
        else oo.Conversion(m,n);
    }while(1);
    return 0;
}


/*
1 9
9999 7
7 2
10000 2
156 8
15 5
10000 9
1234 6
780 4
6143 3
-1 -1


1
41103
111
10011100010000
234
30
14641
5414
30030
22102112
*/


// #include<iostream>
// using namespace std;
// template <class T> //声明一个模板，虚拟类型名为T。注意：这里没有分号。
// class Compare //类模板名为Compare
// {
// public :
//    Compare(T a,T b){
//       x=a;y=b;
//    }
//    T max(){
//       return (x>y)?x:y;
//    }
//    T min(){
//       return (x<y)?x:y;
//    }
// private :
//    T x,y;
// };

// int main(){
//     Compare<int> x(1,2);
//     Compare<int> y(2,3);
//     cout<<x.max()<<endl;
// }