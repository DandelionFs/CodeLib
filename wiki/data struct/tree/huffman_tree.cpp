/*
* 数组实现哈夫曼编码
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const int MaxNum=1000000000; //比大小默认的最大值

class TreeNode{
    char NodeData;
    int w, parent, lchild, rchild;
public:
    TreeNode():lchild(NULL),rchild(NULL){};
    TreeNode(char a, int b,int c, int d ,int e):NodeData(a),w(b),parent(c),lchild(d),rchild(e){}
    friend class HuffmanTree;
};

class HuffmanTree {
    int n;//待编字符串个数
    int rn;//实际需要编码的字符串个数
    TreeNode *Root;//编码数组
    char *array;//读进来的原数组
    string code;//得到的总编码
    string CharEdit[257];//记录对应的askii编码
    int CharCount[257];//全编码256位, 1位保护位
public:
    HuffmanTree(char[]);
    TreeNode *root(){ return Root;}
    void SelectMins(int,int &,int &);
    void Creat(char p[]);
    string Reverse(string);
    void Print();
    void GetCode();
    void TCode(string);
};
HuffmanTree::HuffmanTree(char p[]){
    array=new char[strlen(p)];
    strcpy(array,p);
    memset(CharCount,0,sizeof(CharCount));
    n = strlen(p);
    for (int i = 0; i < n; i++) {
        CharCount[(int) p[i]]++;//计数
    }
    rn = 0;
    for (int i = 0; i < 257; i++) {
        if (CharCount[i]) rn++;
    }
    int step=0;
    Root=new TreeNode[2*rn-1];
    for (int i = 0;i < 257; i++) {//初始化哈夫曼树节点
        if(CharCount[i]){
            Root[step]={ (char)i,CharCount[i],-1,-1,-1};
            step++;
        }
    }
    for(int i=rn;i<rn*2-1;i++){//初始化后续需要添加的节点
        Root[i].parent=Root[i].rchild=Root[i].lchild=-1;
    }
}
void HuffmanTree::SelectMins(int k, int &s, int &t) {
    int min1, min2;
    min1 = min2 = MaxNum;
    s = t = -1;
    for(int i=0;i<k;i++){
        if(Root[i].parent==-1){
            if(Root[i].w<min1){
                t=s; min2=min1;
                s=i; min1=Root[i].w;
            }
            else if(Root[i].w<min2){
                t=i; min2=Root[i].w;
            }
        }
    }
}
void HuffmanTree::Creat(char p[]) {
    for(int i=rn;i<2*rn-1;i++){
        int s1,s2;
        SelectMins(i,s1,s2);
        Root[s1].parent=Root[s2].parent=i;
        Root[i].lchild=s1;
        Root[i].rchild=s2;
        Root[i].w=Root[s1].w+Root[s2].w;
    }

}
void HuffmanTree::Print() {
    int p,q,now;
    for (int j = 0; j < rn; ++j) {
        p=j;
        now=Root[j].NodeData;
        string temp;
        q=Root[j].parent;
        cout<<Root[j].NodeData<<"的编码是:";
        while(1){
            if(Root[q].lchild==p) temp+="0";
            else if(Root[q].rchild==p) temp+="1";
            p=q;
            q=Root[q].parent;
            if(q==-1) break;
        }
        CharEdit[now]+=Reverse(temp);
        cout<<endl;
    }
}
string HuffmanTree::Reverse(string a) {
    string temp;
    for(int i=a.size()-1;i>=0;--i){
        cout<<a[i];
        temp+=a[i];
    }
    return temp;
}
void HuffmanTree::GetCode() {
    int len=strlen(array);
    string temp;
    for(int i=0;i<len;i++)
        code += CharEdit[(int)(array[i])];
    cout<<"编码为"<<code<<"\n总编码长度为:"<<code.size()<<endl;
    
    // for(int i=0;i<strlen(array);i++){
    //     WPL+=CharEdit[array[i]].size();
    // } 第二种算权值的方法, 等效于上面的code.size()

    ofstream os;
    os.open("./10.txt");
    os<<code;
}
void HuffmanTree::TCode(string a) {
    string CompareTemp;
    string Compare;
    for(int i=0;i<a.size();i++){
        CompareTemp+=a[i];
        for(int j=0;j<257;j++){
            if(CharCount[j] && CharEdit[j]==CompareTemp){
                CompareTemp="";
                Compare+=(char)j;
            }
        }
    }
    if(CompareTemp!=""&&Compare=="") cout<<"输入的序列有错误, 请重新输入;\n";
    else cout<<Compare<<endl;
}

int main(){
    int c;
    char p[100];
    string temp2;

    ifstream in("./01.txt");
    if(in){
        cout<<"找到文件, 数据读取成功.数据为:\n";
        getline(in,temp2);
    }
    else cout<<"读取失败";
    for(int i=0;i<temp2.size();i++){ p[i]=temp2[i];}
    p[temp2.size()-1]='\0'; //Linux 下 消除编码 \r 的影响(读入一行出错),  LF(\r\n) <=> CRLF(\n)
    cout<<p<<endl;
    HuffmanTree temp(p);
    while(1) {
        cout<<"[  1  ].编码\n";
        cout<<"[  2  ].译码\n";
        cout<<"[ -1  ].退出\n";
        cin>>c; 
        if(c==-1) return 0;
        if(c==1) {
            temp.Creat(p);
            temp.Print();
            temp.GetCode();
        }
        if(c==2){
            cout<<"输入编码序列:\n";
            string a;
            cin>>a;
            temp.TCode(a);
        }
        if(c!=1&&c!=2&&c!=-1){//容错处理
            while(1){
                cout<<"输入不正确, 重新输入\n";
                cin>>c;
                if(c==1||c==2||c==-1) break;
            }
        }
    }
}


/*
## 代码总结:
1. 文件读写使用
   项目中的目录的读取.
2. string 与 字符数组的使用要统一.
3. linux 下 getline 获取的 多一位'\r'



## 相似的编码方式

常用到的领域就是压缩算法. 

1. 信息熵(香农信息熵 Shannon entropy) 
    - (1948) 克劳德·艾尔伍德·香农 引入熵到信息论, 熵是对不确定性的测量。信息世界，熵越高，能传输越多的信息，熵越低，传输的信息越少。
    - 英语文本数据流的熵比较低，因为英语很容易读懂，也就是说很容易被预测。即便我们不知道下一段英语文字是什么内容，但是我们能很容易地预测, 如果未经压缩，一段英文文本的每个字母需要8个比特来编码，但是实际上英文文本的熵大概只有4.7比特
    - 香农的信源编码定理揭示了，任何无损压缩技术不可能让一比特的消息携带超过一比特的信息。消息的熵乘以消息的长度决定了消息可以携带多少信息。任何无损压缩技术不可能缩短任何消息
    - 根据鸽笼原理(pigeonhole principle)，如果有一些消息变短，则至少有一条消息变长。在实际使用中，由于我们通常只关注于压缩特定的某一类消息，所以这通常不是问题。例如英语文档和随机文字，数字照片和噪音，都是不同类型的。所以如果一个压缩算法会将某些不太可能出现的，或者非目标类型的消息变得更大，通常是无关紧要的。但是，在我们的日常使用中，如果去压缩已经压缩过的数据，仍会出现问题。例如，将一个已经是FLAC格式的音乐文件压缩为ZIP文件很难使它占用的空间变小
    > 如果压缩是无损的，即通过解压缩可以百分之百地恢复初始的消息内容，那么压缩后的消息携带的信息和未压缩的原始消息是一样的多。而压缩后的消息可以通过较少的比特传递，因此压缩消息的每个比特能携带更多的信息，也就是说压缩信息的熵更加高。熵更高意味着比较难于预测压缩消息携带的信息，原因在于压缩消息里面没有冗余，即每个比特的消息携带了一个比特的信息
    - 熵实际是对随机变量的比特量和顺次发生概率相乘再总和的数学期望

2. 算数编码(Arithmetic coding)
    - 一种无损数据压缩方法，也是一种熵编码的方法
    - 和其它熵编码方法不同的地方在于，其他的熵编码方法通常是把输入的消息分割为符号，然后对每个符号进行编码，而算术编码是直接把整个输入的消息编码为一个数，一个满足（0.0 ≤ n < 1.0）的小数n。

3. ANS+FSE

REFERENCES:
- [熵 (信息论)](https://zh.wikipedia.org/wiki/%E7%86%B5_(%E4%BF%A1%E6%81%AF%E8%AE%BA))
- [算术编码](https://zh.wikipedia.org/wiki/%E7%AE%97%E6%9C%AF%E7%BC%96%E7%A0%81)
- [熵压缩：信息熵、Huffman编码、算数编码、ANS+FSE](https://www.jianshu.com/p/9157a6fae4de)

*/
