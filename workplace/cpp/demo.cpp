#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<sstream>
#define ll long long
using namespace std;
char StuAcc[3][20];
int main(){
    // int a=100;
    // string b;
    // char str[25];
    // itoa(a,str,10);
    // cout<<b;
    // cout<<str;

    stringstream ss;
    // for(int i=0;i<100;i++){
    //     ss<<i;
    //     cout<<i<<endl;
    // }
    int a=154;
    ss<<a;
    string b=ss.str();
    cout<<b;

}  

/*
    ifstream infile;
    infile.open("/data/StInfo.in");
    infile>>StuAcc[0]>>StuAcc[1]>>StuAcc[2];
    infile.close();
    for(int i=0;i<3;i++)cout<<StuAcc[i]<<endl;
;    string a= static_cast<string>(8);
    cout<<a;
    a="io"+
    int Step=1;
    string a ="学生"+(string)Step; 
    cout<<a<<endl;
    int i,ii=0,k;
    cin>>i;
    k=i;
    while(i--){
        cin>>data[ii];
        if(!ii) datasum[ii]=data[ii];
        if(ii>0) datasum[ii]=datasum[ii-1]+data[ii];
        ii++;
    }
    for(int i=0;i<k;i++)cout<<datasum[i]<<" ";
    ofstream outi;
    cout<<outi.bad();
    输入坏快???
    }
*/
    // // ofstream outf;
    // // outf.open("text.txt");
    // fstream fs("fstream.txt", ios::in | ios::out | ios::trunc);
    // if (!fs.bad()) {
    //     fs << "Writing to a basic_fstream object..." << endl;
    //     fs.close();
    // }
    // char* a=" 0";
    // int i;
    // i= static_cast<int>(a);
    // cout<<i;
// int i;
// char *p = "This is an example.";
// i = reinterpret_cast<int>(p);
// int x=100;
// while(x-->0) printf("%d\n",x);


/*
    ofstream outfile("demo.txt");
    for(int i=0;i<5;i++){
        outfile<<course[i]<<endl;
    }
    outfile.close();


    ifstream uu;
    uu.open("demo.txt"); 
    
    while(uu.good() && !uu.eof())
        uu>>course[i++];
    
    for(int i=0;i<5;i++)
        cout<<course[i]<<endl;
    
    uu.close();

*/