#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool Matrix[100][100];
int getch(char s, char a[]){
    int len = strlen(a);
    for (int i = 0; i < len; i++){
        if (a[i] == s) return i;
    }
    return -1;
}
void Warshall(int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            int temp = 0;
            for (int x = 0; x < len; x++) {
                temp += Matrix[i][x] * Matrix[x][j];// Matrix[i][x]理解为在i行上遍历, Matrix[x][j]理解为在j行上遍历, 如果符合传递性, 就有 ij点 为新得到的节点 
                if (!Matrix[i][j]) {
                    Matrix[i][j] = temp;
                    break;//找到符合传递率的两个节点, 出去找下一个
                }
            }
        }
    }
}
void Print(int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++)
            cout << Matrix[i][j]<<' ';
        cout << endl;
    }
}
int main(){
    char a[10];
    cout << "输入集合A(如'abcd'):\n";
    cin >> a;
    int len = strlen(a);
    cout<<"请输入A上的二元关系R(如'ab','-1停止')\n";
    string r;
    while(cin>>r&&r!="-1") 
        Matrix[getch(r[0],a)][getch(r[1],a)]=1;

    cout << "关系矩阵:\n";
    Print(len);
    Warshall(len);
    cout << "传递闭包:\n";
    Print(len);
}
