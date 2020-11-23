


// ```cpp
// #include<iostream>
// #include<cstring>
// #include<cstdio>
// #include<stdio.h>
// #include<stdlib.h>
// #include<cstdlib>
// #include<fstream>
// #include<sstream>
// #define ll long long
// using namespace std;
// char StuAcc[3][20];
// int main(){
//     // int a=100;
//     // string b;
//     // char str[25];
//     // itoa(a,str,10);
//     // cout<<b;
//     // cout<<str;

//     stringstream ss;
//     // for(int i=0;i<100;i++){
//     //     ss<<i;
//     //     cout<<i<<endl;
//     // }
//     int a=154;
//     ss<<a;
//     string b=ss.str();
//     cout<<b;

// }  

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

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
stack<int>acahe;
stack<char>acahe0;
int operate(char a) {
	int temp1, temp2;
	if (a == '+') {
		temp1 = acahe.top();
		acahe.pop();
		temp2 = acahe.top();
		acahe.pop();
		return temp1 + temp2;
	}
	else if (a == '-') {
		temp1 = acahe.top();
		acahe.pop();
		temp2 = acahe.top();
		acahe.pop();
		return temp2 - temp1;
	}
	else if (a == '*') {
		temp1 = acahe.top();
		acahe.pop();
		temp2 = acahe.top();
		acahe.pop();
		return temp2 * temp1;
	}
	else if (a == '/') {
		temp1 = acahe.top();
		acahe.pop();
		temp2 = acahe.top();
		acahe.pop();
		return temp1 / temp2;
	}
}
int main() {
	char p[1000];
	cin.getline(p, 1000);
	int len = strlen(p);
	for (int i = 0; i < len; i++) {
		if (p[i] <= '9' && p[i] >= '0') acahe.push(p[i] - '0');
		else acahe0.push(p[i]);
	}
	while (!acahe0.empty()) {
		int temp = operate(acahe0.top());
		acahe.push(temp);
		acahe0.pop();

	}
	cout << acahe.top() << endl;
}

*/

/*
#include<iostream>     //输入的表达式要以'#'结尾，如‘5+6*3/(3-1)#’
#include<cstring>
#include<cstdio>
#include<cctype>
#include<stack>
using namespace std;

stack<char> opter;    //运算符栈
stack<double> opval;  //操作数栈

int getIndex(char theta)   //获取theta所对应的索引
{
	int index = 0;
	switch (theta)
	{
	case '+':
		index = 0;
		break;
	case '-':
		index = 1;
		break;
	case '*':
		index = 2;
		break;
	case '/':
		index = 3;
		break;
	case '(':
		index = 4;
		break;
	case ')':
		index = 5;
		break;
	case '#':
		index = 6;
	default:break;
	}
	return index;
}

char getPriority(char theta1, char theta2)   //获取theta1与theta2之间的优先级
{
	const char priority[][7] =     //算符间的优先级关系
	{
		{ '>','>','<','<','<','>','>' },
		{ '>','>','<','<','<','>','>' },
		{ '>','>','>','>','<','>','>' },
		{ '>','>','>','>','<','>','>' },
		{ '<','<','<','<','<','=','0' },
		{ '>','>','>','>','0','>','>' },
		{ '<','<','<','<','<','0','=' },
	};

	int index1 = getIndex(theta1);
	int index2 = getIndex(theta2);
	return priority[index1][index2];
}

double calculate(double b, char theta, double a)   //计算b theta a
{
	switch (theta)
	{
	case '+':
		return b + a;
	case '-':
		return b - a;
	case '*':
		return b * a;
	case '/':
		return b / a;
	default:
		break;
	}
}

double getAnswer()   //表达式求值
{
	opter.push('#');      //首先将'#'入栈opter
	int counter = 0;      //添加变量counter表示有多少个数字相继入栈，实现多位数的四则运算
	char c = getchar();
	while (c != '#' || opter.top() != '#')   //终止条件
	{
		if (isdigit(c))   //如果c在'0'~'9'之间
		{
			if (counter == 1)   //counter==1表示上一字符也是数字，所以要合并，比如12*12，要算12，而不是单独的1和2
			{
				double t = opval.top();
				opval.pop();
				opval.push(t * 10 + (c - '0'));
				counter = 1;
			}
			else
			{
				opval.push(c - '0');     //将c对应的数值入栈opval
				counter++;
			}
			c = getchar();
		}
		else
		{
			counter = 0;   //counter置零
			switch (getPriority(opter.top(), c))   //获取运算符栈opter栈顶元素与c之间的优先级，用'>'，'<'，'='表示
			{
			case '<':               //<则将c入栈opter
				opter.push(c);
				c = getchar();
				break;
			case '=':               //=将opter栈顶元素弹出，用于括号的处理
				opter.pop();
				c = getchar();
				break;
			case '>':               //>则计算
				char theta = opter.top();
				opter.pop();
				double a = opval.top();
				opval.pop();
				double b = opval.top();
				opval.pop();
				opval.push(calculate(b, theta, a));
			}
		}
	}
	return opval.top();   //返回opval栈顶元素的值
}

int main()
{
	//freopen("test.txt", "r", stdin);
	int t;     // 需要计算的表达式的个数
	cin >> t;
	getchar();
	while (t--)
	{
		while (!opter.empty())opter.pop();
		while (!opval.empty())opval.pop();
		double ans = getAnswer();
		cout << ans << endl << endl;
		getchar();
	}
	return 0;
}

*/ 

/*
#include<iostream>
using namespace std;
struct park {
	char a;
	int b, c;
};
int main() {
	char m;
	while (cin >> m) {
		if (m == 'E') return 0;
		else;
	}
}*/
/*
*//*
#include<iostream>
using namespace std;
int main() {
	//ctring b不可以memset指针数组
	int N, step = 1;
	cin >> N;
	int** p = new int* [N];
	for (int i = 0; i < N; i++)p[i] = new int[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			for (int y = 0; y < N; y++) {
				if (y + j == i)p[y][j] = step++;
			}
	}
	for (int j = 0; j < N; j++) {
		for (int y = 0; y < N; y++) cout << p[j][y] << " ";
		cout << endl;
	}

}*/
/*
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int p[100], i = 0, step = 1, n;
	while (cin >> p[i]) {
		if (p[i] == 0) {
			p[i] = '\0';
			break;
		}
		i++;
	}
	int len = i, start = 0;
	sort(p, p + len);
	cin >> n;
	while (start < len) {
		int mid = (start + len) / 2;
		if (n == p[mid]) {
			for (int i = 0; i < n; i++)cout << p[i] << " ";
			cout << endl;
			cout << mid << endl << step;
			return 0;
		}
		else if (n > mid) start = mid + 1;
		else if (n < mid) len = mid - 1;
		step++;
	}
	return 0;
}*/

/*
#include <iostream>
using namespace std;
#include <cmath>
int main()
{
	int a[10], i, j, s, f;
	cout << "请任意输入10个数：" << endl;
	for (i = 0; i < 10; i++) cin >> a[i];
	s = 0;
	for (i = 0; i < 10; i++){
		j = 2; f = 1;
		while (j <= sqrt(a[i]))
			if (a[i] % j == 0){
				f = 0;
				break;
			}
			else j++;
				if (f == 1)a[s++] = a[i];
	}
	cout << "结果：" << endl;
	for (i = 0; i < s; i++)cout << a[i] << "  ";
	return 0;
}//从任意n个数中找出素数。要求：将找出的素数存放在数组中。
*//*

#include<iostream>
using namespace std;
int cdivisor(int a, int b) {
	while (a != b) {
		if (a > b)a -= b;
		else b -= a;
	}
	return a;
}
void trans(string a,int &sum1,int &sum2) {
	int i, j;
	for (i = 0; a[i] != '/'; i++) {
		sum1 *= 10;
		sum1 += a[i] - '0';
	}
	for (j = i + 1; a[j] != '\0'; i++) {
		sum2 *= 10;
		sum2 += a[j] - '0';
	}
}
int main() {
	int N;
	string a;
	cin >> N;
	while (N--) {
		int sum1(0),sum2(0),sum3(0),sum4(0),i,j;
		cin >> a;
		trans(a, sum1, sum2);
		cout << sum1 << " " << sum2;
		
	}
}*/

////------------------查重的方法-------------------------------
//#include <algorithm>
//#include <vector>
////////////////////////////////////////////////
//int nArray[] = { 0, 1, 2, 3, 4, 5 };
//std::vector<int> vecNum(nArray, nArray + 6);
//CString strText;
//// 第一种用法：最原始的语法(用下标)
//for (size_t i = 0; i < vecNum.size(); ++i)
//{
//	strText.Format("%d", nArray[i]);
//	AfxMessageBox(strText);
//}
//
//// 第二种用法：最原始的语法(用迭代器)
//for (auto it = vecNum.begin(); it != vecNum.end(); ++it)
//{
//	strText.Format("%d", *it);
//	AfxMessageBox(strText);
//}
//
//// 第三种用法：简化数组遍历语法(从vs2008开始支持)
//for each (auto item in vecNum)
//{
//	strText.Format("%d", item);
//	AfxMessageBox(strText);
//}
//
//// 第四种用法：STL函数
//std::for_each(vecNum.begin(), vecNum.end(), [](int item) {
//	CString strText;
//	strText.Format("%d", item);
//	AfxMessageBox(strText);
//	});
//
//// 第五种用法：C++11新增加的(VS2012支持)
//for (auto item : vecNum)
//{
//	strText.Format("%d", item);
//	AfxMessageBox(strText);
//}
//#include<cstdio>
//#include<iostream>
//#include<ctime>
//#include<algorithm>
//using namespace std;
//#define _for(i,a,b) for(int i=(a);i<(b);++i)
//const int N = 10000000;
//struct TS {
//	int a, b, c;
//};
//inline bool cmp(const TS& t1, const TS&t2) {
//	if (t1.a != t2.a)return t1.a < t2.a;
//	if (t1.b != t2.b)return t1.b < t2.b;
//	return t1.c < t2.c;
//}
//int cmp4qsort(const void* a, const void* b) {
//	TS* t1 = (TS*)a, * t2 = (TS*)b;
//	if (t1->a != t2->a)return t1->a - t2->a;
//	if (t1->b != t2->b)return t1->b - t2->b;
//	return t1->c - t2->c;
//}
//struct cmpFunctor {
//	inline bool operator()(const TS& t1, const TS& t2) {
//		if (t1.a != t2.a)return t1.a < t2.a;
//		if (t1.b != t2.b)return t1.b < t2.b;
//		return t1.c < t2.c;
//	}
//};
//TS tss[N];
//void genData() {
//	_for(i, 0, N) {
//		tss[i].a = rand();
//		tss[i].b = rand();
//		tss[i].c = rand();
//	}
//}
//int main() {
//	srand(time(NULL));
//
//	genData();
//	clock_t start = clock();
//	sort(tss, tss + N, cmp);
//	printf("sort by functor pointer: %ld\n", clock() - start);
//
//	genData();
//	start = clock();
//	sort(tss, tss + N, cmpFunctor());
//	printf("sort by functor: %ld\n", clock() - start);
//
//	genData();
//	start = clock();
//	qsort(tss, N, sizeof(TS), cmp4qsort);
//	printf("qsort by functor pointer: %ld\n", clock() - start);
//
//	return 0;
//}



//--------------建立一个单向链表----------------------------------------
//#include<iostream>
//using namespace std;
//typedef struct Node {
//	int name;
//	Node* next;
//}D;
//int main() {
//	int N;
//	cin >> N;
//	D* s = NULL, * p = NULL, * head = NULL;
//	while (N--) {
//		s = new D;
//		cin >> s->name;//完成s的name的值输入操作
//		if (head == NULL) head = s;
//		else p->next = s;//完成s的指针指向操作
//		p = s;
//	}
//	p->next = NULL;
//	delete s;
//	D* temp = head;
//	while (temp) {
//		cout << temp->name << endl;
//		temp = temp->next;
//	}
//	return 0;
//}
//--------------------------------------------

//----------------双向循环链表----------------------------
//是在单向上面多加一个指针
//如果头=尾=本身：代表链表为空
//#include<iostream>
//using namespace std;
//typedef struct Node {
//	int data;
//	Node* prior, * next;
//}N;
//
//int main(){
//	N* head, * s,* p;
//	s = new N;
//	s->next = s->prior = s;//为什么指针不用取地址就能指向自身？？
//
//}
//-------------------------------------------

//#include<iostream>
//#include<algorithm>
//#define _for(i,a,b) for(int i=(a);i<(b);++i)
//using namespace std;
//bool cmp(int a, int b) {
//	return a > b;
//}
//int filtrate[11];
//int main() {
//	int k = 0;
//	char p[12];
//	cin.getline(p, 12);
//	_for(i, 0, 12) {
//		bool flag = false;
//		_for(j, 0, k) if (filtrate[j] == (p[i] - '0')) flag = true;
//		if (flag) continue;
//		else  filtrate[k++] = p[i] - '0';
//	}
//	/*for (int i = 0; i < k; i++)cout << filtrate[i] << " ";*/
//	filtrate[k--] = '\0';//这里有点疑问？？？？？？
//	sort(filtrate, filtrate + k, cmp);
//	//for (int i = 0; i < k; i++)cout << filtrate[i] << " ";
//	cout << "int[] arr = new int[]{";
//	_for(i, 0, k - 1)cout << filtrate[i] << ",";
//	cout << filtrate[k - 1] << "};\n";
//	cout << "int[] index = new int[]{";
//	_for(i, 0, 10) {
//		_for(j, 0, k) {
//			if (filtrate[j] == p[i] - '0') cout << j << ",";
//		}
//	}
//	_for(i, 0, k) if (filtrate[i] == p[10] - '0') {
//		cout << i << "};";
//		break;
//	}
//}

//#include<iostream>
//#include<>
//#define _for(i,a,b) for(int i=(a);i<(b);++i)
//using namespace std;
//int main() {
//	string a;
//	while (compare)
//	{
//
//	}
//}
//#include<iostream>
//#include<cstring>
//#define _for(i,a,b)for(int i=(a);i<(b);++i)
//using namespace std;
//int main() {
//	int sum1 = 0, sum2 = 0, flag1 = 0, flag2 = 0, k;
//	char p[200];
//	cin.getline(p, 200);
//	for (int i = 0; p[i] != ' '; i++) {
//		if (p[i] <= '9' && p[i] >= '0') {
//			sum1 *= 10;
//			sum1 += p[i] - '0';
//		}
//		else {
//			flag1 = 1;
//			break;
//		}
//	}
//	_for(i, 0, strlen(p)) if (p[i] == ' ') {
//		k = i; break;
//	}
//	_for(i, k + 1, strlen(p)) {
//		if (p[i] <= '9' && p[i] >= '0') {
//			sum2 *= 10;
//			sum2 += p[i] - '0';
//		}
//		else {
//			flag2 = 1;
//			break;
//		}
//	}
//	if (flag1 || flag2) {
//		if (flag1)cout << "?";
//		else cout << sum1;
//		cout << " + ";
//		if (flag2)cout << "?";
//		else cout << sum2;
//		cout << " = ";
//		cout << "?";
//	}
//	else cout << sum1 << " + " << sum2 << " = " << sum1 + sum2;
//}有两组数过不去欸
//上面Amy的那道题不可以把++写在方括号里面？？？？？不知道为什么，就是写不进去sex吗，是和编译顺序有关吗



//#include<iostream>
//using namespace std;
//template<typename T>
//T* My_find(T* array, T n, T x) {
//	T* p = array;
//	int i;
//	for (i = 0; i < n; i++) {
//		if (*p == x) {
//			return p;
//		}
//		p++;
//	}
//	return 0;
//}
//int main() {
//	int a[] = { 1,2,3,4,5,6,7,8,10 };
//	int* result = My_find<int>(a, 10, 3);
//	cout << (*result) << "\n" << endl;
//	
//	
//	return 0;
//}



//# include<stdio.h>
//# define INF 1000000000
//int main() {
//	FILE* fin, * fout;
//	fin = fopen("data. in", "rb");
//	fout = fopen("data. out", "wb");
//	int x, n = 0, min = INF, max = -INF, s = 0;
//	while (fscanf(fin, "%d", &x) == 1) {
//		s += x;
//		if (x < min) min = x;
//		if (x > max) max = x;
//		n++;
//	}
//	fprintf(fout, "%d %d .31f\n", &min, &max, (double)s / n);
//	fclose(fin);
//	fclose(fout);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main() {
//	int temp, a, b;
//	temp = a;
//	a = b;
//	b = temp;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	cout << a << b;
//}
//#include<iostream>
//using std::cin;
//using std::cout;
//using std::wcin;
//using std::wcout;
//using std::endl;
//int main(){
//	char* a = new char[4];
//	wchar_t* b = new wchar_t[4];
//	cin >> a;
//	wcin >> b;
//	cout << a << endl;
//	wcout << b << endl;
//	delete[] a;
//	delete[] b;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main() {
//	string a;
//	cin >> a;
//	cout << a;
//	char data[]{ "fdnjhsahgfl" };
//	cout << data;
//
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int ans = 1;// 递归必须定义全局变量吗？
//int temp[1000];
//int Length(int p[]) {
//	int step, ii = 0;
//	for (ii = 0; p[ii] != '\0'; ii++);
//	return ii;
//}
//int udjs(int a) {
//	if (a == 1) return 1;
//	if (a % 2) ans += udjs((a - 1) / 2);
//	else ans += udjs(a / 2);
//}
//int main() {
//	int n, i=0;
//	cin >> n;
//	temp[i++] = 1;
//	for (i; i < n / 2; i++) {
//		temp[n-1]+=temp[i];
//	}
//	cout << temp[n-1];
//}
//
	/*int len = Length(temp);
	cin >> n;
	udjs(n);
	cout << ans;
	for (int i = 0; i <len; i++) cout << temp[i] << " ";
	return 0;*/
	/*
	f[1]=1
	f[2]=2=f[1]+1
	f[3]=2=f[1]+1
	f[4]=4=f[1]+f[2]+1
	f[5]=4=f[1]+f[2]+1
	f[6]=6=f[1]+f[2]+f[3]+1
	观察可以知道奇数隶属于上位偶数
	*/

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//void replace1(string p,char m[],char n[]) {
//	int start = p.find(m);
//
//}
//int main() {
//	string p;
//	getline(cin, p);
//	cout << p << endl;
//	transform(p.begin(), p.end(), p.begin(), ::toupper);
//	replace1(p,"can you","I can");
//
//}
//#include<iostream>
//#include<cmath>
//#define _for(i,a,b) for(int i=(a);i<(b);++i)
//using namespace std;
//int* p;
//int isprime(int a) {
//	if (a <= 1) return 0;
//	else {
//		int m = sqrt(a);
//		for (int i = 2; i <= m; i++) {
//			if (a % i == 0) return 0;
//		}
//		return 1;
//	}
//}
//int ruleplus(int choose_Number, int plussum, int start, int end) {
//	if (!choose_Number)return isprime(plussum);
//	int sum = 0;
//	for (int i	= start; i <= end; i++) {
//		sum += ruleplus(choose_Number - 1, plussum + p[i], i+1, end);
//	}
//	return sum;
//}
//
//int main() {
//	int m, n;
//	cin >> m >> n;//m个数，取n个
//	p = new int[m];//模拟深度如何实现？？？------数学里的找规律可以实现每次找到哪里简化运算但是不可以找到深度，因为深度取决去n
//	_for(i, 0, m)cin >> p[i];
//	cout << ruleplus(n, 0, 0, m - 1);
//}
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main() {
//	int i, p, q;
//	cin >> p >> q;
//	if (p % 2 == 0)p = p + 1;
//	for (int a = p; a <= q; a += 2) {
//		int m = a, c = 0;
//		while (m) {
//			c = c * 10 + m % 10;
//			m = m / 10;
//		}
//		if (c == a) {
//			if (a > 1) {
//				for (i = 2; i <= sqrt(a); i++) {
//					if (a % i == 0) break;
//				}
//				if (i > sqrt(a))cout << a << endl;
//			}
//		}
//		
//	}
//}
/*
		int m = a;
		while (m) {
			b = m % 10;
			c = c * 10 + b;
			m = m / 10;
		}
*/
/*
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int p, q, o[10],i;
	cin >> p >> q;
	if (p % 2 == 0)p = p + 1;
	for (int a = p; a <= q; a+=2) {
		int k = 0,flag=1;
		while (a) {
			o[k++] = a % 10;
			a /= 10;
		}
		for (int j = 0; j <= k / 2; j++) {
			if (o[j] != o[k - j - 1]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			if (a > 1) {
				for (i = 2; i <= sqrt(a); i++) {
					if (a % i == 0) break;
				}
				if (i > sqrt(a))cout << a << endl;
			}
		}
	}
}
*/

//#include<bits/stdc++.h>
//#include <windows.h>
////作者 cdqz_ssw 
//#define l1 262
//#define l2 294
//#define l3 330
//#define l4 349
//#define l5 392
//#define l6 440
//#define l7 493
//
//#define n1 532
//#define n2 588
//#define n3 660
//#define n4 698
//#define n5 784
//#define n6 880
//#define n7 988
//
//#define h1 1046
//#define h2 1175
//#define h3 1319
//#define h4 1397
//#define h5 1568
//#define h6 1760
//#define h7 1976
//
//#define A 1600*1.25 //四拍
//#define B 800*1.25  //两拍
//#define C 400*1.25  //一拍
//#define D 200*1.25  //半拍
//#define E 100*1.25  //1/4拍
//#define F 50*1.25   //1/8拍
//
//#define S(i) Sleep(i)
//#define wq( i , j ) Beep( i , j )
//
//int  main() {
//	wq(n3, D); wq(n4, D); wq(n3, D); wq(n4, D); wq(n5, C); wq(n3, D); wq(n4, D);
//
//	wq(n3, D); wq(n4, D); wq(n5, C); wq(n5, D); wq(n4, D); wq(n3, D); wq(n4, D);
//
//	wq(n3, E); wq(n1, D); wq(n1, D); wq(n1, E); wq(l6, D);
//	wq(n3, E); wq(n1, D); wq(n1, D); wq(n1, E); wq(l6, D);
//
//	wq(n1, E); wq(n1, D); wq(n1, D); wq(n1, E); wq(l6, D); wq(n3, C); S(C);
//	//-----------------------------------------作者 cdqz_ssw -----
//	//----------C1----D0.5---------------------------------------2
//	wq(n3, D); wq(n4, D); wq(n3, D); wq(n4, D); wq(n5, C); wq(n3, D); wq(n4, D);
//
//	wq(n3, D); wq(n4, D); wq(n5, C); wq(n5, D); wq(n4, D); wq(n3, D); wq(n4, D);
//
//	wq(n3, E); wq(n1, D); wq(n1, D); wq(n1, E); wq(l6, D);
//	wq(n3, E); wq(n1, D); wq(n1, D); wq(n1, E); wq(n2, D);
//
//	wq(n1, E); wq(n1, D); wq(n1, D); wq(n1, E); wq(n3, D); wq(n3, C); S(C);
//	//-----------------------------------------作者 cdqz_ssw -----
//	//----------C1----D0.5---------------------------------------3
//	wq(n5, C); wq(n3, C); wq(n2, C); wq(n3, D); wq(n3, D);
//
//	wq(n2, D); wq(n1, D); wq(n2, D); wq(n3, B); wq(n3, D);
//
//	wq(n6, C); wq(n3, C); wq(n2, C); wq(n1, D); wq(n1, D);
//
//	wq(n1, D); wq(n2, D); wq(n3, D); wq(n2, C); S(C); S(D);
//	//-----------------------------------------作者 cdqz_ssw -----
//	//----------C1----D0.5---------------------------------------4
//	wq(n5, C); wq(n3, C); wq(n2, C); wq(n3, D); wq(n3, D);
//
//	wq(n2, D); wq(n1, D); wq(n2, D); wq(n3, B); wq(n3, D);
//
//	wq(n6, C); wq(n3, C); wq(n1, C); wq(n3, C);
//
//	wq(n1, C); S(C); S(C); S(D); wq(n1, E); wq(l5, E);
//	//----------------------------------------作者 cdqz_ssw -----1
//	//----------C1----D0.5---------------------------------------4
//	wq(l6, 375); wq(l6, 375); wq(l5, D); wq(n1, 375); wq(n1, E); S(D); wq(n1, E); wq(l5, E);
//
//	wq(l6, 375); wq(l6, 375); wq(l5, D); wq(n1, 375); wq(n3, E); S(D); wq(n1, E); wq(l5, E);
//
//	wq(l6, 375); wq(l6, D); wq(l6, E); wq(n5, D); wq(n1, 375); wq(n1, D); wq(n1, E); wq(n2, D);
//
//	wq(n1, 375); wq(n1, E); S(E); wq(n1, E); wq(l6, D); wq(n3, C); S(D); wq(n1, E); wq(l5, E);
//
//	wq(l6, 375); wq(l6, 375); wq(l5, D); wq(n1, 375); wq(n1, E); S(D); wq(n1, E); wq(l5, E);
//
//	wq(l6, 375); wq(l6, 375); wq(l5, D); wq(n3, 375); wq(n1, E); S(D); wq(n1, E); wq(l5, E);
//
//	wq(l6, 375); wq(l6, D); wq(l6, E); wq(n5, D); wq(n1, 375); wq(n1, D); wq(n1, E); wq(n2, D);
//
//	wq(n1, 375); wq(n1, D); wq(n3, 375); wq(n1, C); S(C);
//
//
//}
//#include<iostream>
//using namespace std;
//int main() {
//	int a, b, i = 0;
//	cin >> a >> b;
//	int s = a * b;
//	int* p = new int[s];
//	while (s--) cin >> p[i++];
//	int m, n;
//	cin >> m >> n;
//	if (b != m ) {
//		cout << "Error: " << b << " != " << m;
//		return 0;
//	}
//	s = m * n;
//	int* u = new int[s];
//	while (s--)  cin >> u[i++];
//	cout << a << " " << n << endl;
//	for (int i = 0; i < a; i++) {
//		for (int j = 0; j < b; j++) {
//			for (int y = 0; y < m; y++) {
//				for (int x = 0; x < n; x++) {
//					cout<<
//				}
//			}
//		}
//	}
//}
//#include<iostream>
//using namespace std;
//int main() {
//	char p[5];
////	fgets(p, 5, stdin);
//	cin.getline(p, 5);
//	cout << p;
//}
//#include<iostream>
//using namespace std;
//void lfh() {
//	static int gh=0;
//	gh+= 2;
//	cout << gh << endl;
//}
//int main() {
//	lfh();
//	lfh();
//	lfh();
//}
//#include<iosream>
//using namespace std;
//struct MyStruct
//{
//	int a, o, g, e, w,we;
//};
//int main() {
//	MyStruct p;
//	cout << sizeof(p);
//}
//#include<iostream>
//using namespace std;
//void pA(int &a[]) {
//	a[0] = 1;
//}
//int main() {
//	int p[2] = {0};
//	pA(p);
//	cout << p[0];
//}
//#include<iostream>
//using namespace std;
//int main() {
//	int p1, p2, a1, a2, a3;
//	cin >> p1 >> p2 >> a1 >> a2 >> a3;
//	if (a1 == a2 ==a3 == 1) {
//		cout << "The winner is b: " << p2 << " + " << 3;
//		return 0;
//	}
//	else if (a1 ==a2 ==a3 == 0) {
//		cout << "The winner is a: " << p1 << " + " << 3;
//		return 0;
//	}
//	else {
//		int temp1 = 0, temp2 = 0;
//		if (a1) temp2++;
//		else temp1++;
//		if (a2) temp2++;
//		else temp1++;
//		if (a3) temp2++;
//		else temp1++;
//		if (temp1 + p1 > temp2 + p2) cout << "The winner is a: " << p1 << " + " << temp1;
//		else cout << "The winner is b: " << p2 << " + " << temp2;
//	}
//}
//#include<iostream>
//using namespace std;
//void sm(const int p[]) {
//	p[2] += 1;
//	cout << p[0];
//}
//int main() {
//	int p[5];
//	p[0] = 0;
//	cout << p[0];
//}
//sort(p, p + N, cmp);
	//for (i = 0; i < N; i++) {
	//	cout << p[i].id << " " << p[i].name << endl;
	//}

//bool cmp(S a, S b) {
//	return a.name < b.name;
//}

//#include<iostream>
//using namespace std;
//int main() {
//	int N = 5,i=0;
//	char m;
//	string a[5];
//	while (N--) {
//		
//		cin >> m >> a[i++];
//		cout << m << endl;
//	}
//	for (int i = 0; i < 5; i++)cout << a[i] << endl;
//
//}



// 调试数组
//#include<iostream>
//using namespace std;
//int main() {
//	while (1) {
//		char m = getchar();
//		
//		if (!cin) {
//			break;
//		}
//		cout << m;
//	}
//}
//#include<iostream>
//using namespace std;
//char p[2500][30];
//void System(int sys) {
//	int i = 0;
//	int a = 0, b = 0;
//	while (cin.getline(p[i], 30)) {
//		for (int j = 0; p[i] != '\0'; i++) {
//			if (p[i][j] == 'W')a++;
//			else b++;
//			if()
//		}
//		i++;
//	}
//}
//int main() {
//	int scr1_11, scr2_11, scr1_21, scr2_21, i;
//	scr1_11 = scr2_11 = scr1_21 = scr2_21 = 0;
//	System(11);
//	System(21);
//} https://www.luogu.com.cn/problem/P1042 还是不太知道11分制和21分制的区别……


//#include<iostream>
//#include<algorithm>
//using namespace std;
//typedef struct Bom {
//	int a, b;
//};
//bool cmp(Bom p, Bom q) {
//	return p.a < q.a;
//}
//bool cmpplus(Bom p, Bom q) {
//	return p.b < q.b;
//}
//int main() {
//	int N;
//	long long sum = 1;
//	cin >> N;
//	Bom* p = new Bom[N + 1];
//	for (int i = 0; i < N; i++) {
//		cin >> p[i].a >> p[i].b;
//		sum *= p[i].a;
//	}
//	sort(p, p + N + 1, cmp);
//
//
//}


//#include<iostream>
//#include<string>
//using namespace std;
//void strinit(int a[]) {
//	string b;
//	cin >> b;
//	a[0] = b.length();
//	for (int i = 1; i < a[0]; i++)a[i] = b[a[0] - i] - '0';
//}
//
//int main() {
//	int p[1000];
//	strinit(p);
//	cout << p[2];
//}

//#include<iostream>
//using namespace std;
//int main() {
//	cout << (-2) % 10;
//}

//#include<iostream>
//using namespace std;
//typedef struct Node {
//	int a;
//	Node* next;
//}N;
//N* head = NULL;
//void insert() {
//	N* p, * e = head, * ee = head;;
//	p = new N;
//	cin >> p->a;
//	p->next = NULL;
//	if (head == NULL) {
//		head = p;
//	}
//	else {
//		if (head->a > p->a) {
//			p->next = head;
//			head = p;
//			return;
//		}
//		while (e != NULL && (p->a > e->a)) {
//			ee = e;
//			e = e->next;
//		}
//		if (e == NULL) {
//			ee->next = p;
//		}
//		else {
//			p->next = e;
//			ee->next = p;
//		}
//	}
//}
//void show() {
//	N* p = head;
//	while (p != NULL) {
//		cout << p->a << " ";
//		p = p->next;
//	}
//}
//int main() {
//	int N;
//	cin >> N;
//	while (N--) {
//		insert();
//	}
//	insert();
//	show();
//}

//#include<iostream>
//using namespace std; 
//typedef struct student { 
//	char number[10]; 
//	char name[100]; 
//	double score; 
//	student* next;
//}S; 
//S* head=NULL,*s;
//void initdata(int n) { 
//	S* p; 
//	for (int i = 0; i < n; i++) {
//		p = new S;
//		cin >> p->number >> p->name >> p->score;
//		p->next = NULL;
//		if (head == NULL) {
//			head = p;
//			s = head;
//		}
//		else {
//			s->next = p;
//			s = p;
//		}
//	}
//} 
//void showdata(double k) {
//	S* p = head;
//	while (p != NULL) {
//		if (p->score >= k)cout << p->number << " " << p->name << " " << p->score << " " << endl;;
//		p = p->next;
//	}
//} 
//int main() { 
//	int n;
//	double k; 
//	cin>>n;
//	initdata(n); 
//	cin>>k; 
//	showdata(k); 
//}


//#include<iostream>
//using namespace std;
//typedef struct Node {
//	int number;
//	char name[100];
//	int a;
//	Node* next;
//}N;
//N* head = NULL, * e = head;
//void insert() {
//	N* p;
//	p = new N;
//	cin >> p->number >> p->name >> p->a;
//	p->next = NULL;
//	if (head == NULL) {
//		head = p;
//		e = head;
//	}
//	else {
//		e->next = p;
//		e = p;
//	}
//}
//void show(int w) {
//	int step = 0, flag = 0, k = w;
//	N* pa = head, * ee = head;
//	w--;
//	while (w--) {
//		ee = pa;
//		pa = pa->next;
//	}
//	N* p = new N;
//	p->number = k;
//	cin >> p->name >> p->a;
//	p->next = NULL;
//	ee->next = p;
//	p->next = pa;
//	p = head;
//	while (p != NULL) {
//		cout << p->number << " " << p->name << " " << p->a << endl;
//		p = p->next;
//	}
//}
//int main() {
//	int N;
//	cin >> N;
//	while (N--) {
//		insert();
//	}
//	cin >> N;
//	show(N);
//}



//#include<iostream>
//using namespace std;
//typedef struct Node {
//	int a;
//	Node* next;
//}N;
//N* head = NULL;
//void insert() {
//	N* p, * e = head, * ee = head;;
//	p = new N;
//	cin >> p->a;
//	p->next = NULL;
//	if (head == NULL) {
//		head = p;
//		e = head;
//	}
//	else {
//		e->next = p;
//		e = p;
//	}
//}
//int main() {
//	int N,flag=0;
//	
//	N* p = head;
//	cin >> N;
//	while (N--) {
//		insert();
//	}
//	while (p != NULL) {
//		if ((p->a) == 1) flag++;
//		p = p->next;
//	}
//}


//#include<iostream>
//using namespace std;
//typedef struct Node {
//	int num;
//	Node* next;
//}NN;
//NN* head, * s;
//void create_Insert(int loc) {
//	int i = 1;
//	NN* p = new NN;
//	p->num = 0;
//	p->next = NULL;
//	NN* temp = head;
//	while (temp != NULL && loc - i) {
//		temp = temp->next;
//		i++;
//	}
//	if (temp != NULL) {/*?*/
//		s = temp->next;
//		temp->next = p;
//		p->next = s;
//	}
//	else {
//		temp->next = p;
//	}
//}
//void node_Plus(int loc) {
//	int i = 1;
//	NN* p = new NN;
//	p->num = 0;
//	p->next = NULL;
//	NN* temp = head;
//	while (temp != NULL && loc - i) {
//		temp = temp->next;
//		i++;
//	}
//	if (temp != NULL)temp->num++;
//}
//void node_Delete(int loc) {
//	int i = 1;
//	NN* p,* temp = head;
//	if (loc == 1) {
//		p = head;
//		head = head->next;
//		delete p;
//	}
//	else {
//		while (temp->next != NULL && loc - i) {
//			s = temp;
//			temp = temp->next;
//			i++;
//		}
//		s->next = temp->next;
//		delete temp;
//	}
//
//	
//	
//
//
//	
//}
//void show() {
//	NN* p = head;
//	while (p != NULL) {
//		cout << p->num << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//int main() {
//	NN* p;
//	p = new NN;
//	p->num = 3;
//	p->next = NULL;
//	head = p;
//	s = head;
//	p = new NN;
//	p->num = 7;
//	p->next = NULL;
//	s->next = p;
//	s = p;
//	p = new NN;
//	p->num = 1;
//	p->next = NULL;
//	s->next = p;
//	s = p;
//	int N, M;
//	do {
//		cin >> N;
//		if (N == 0)return 0;
//		cin >> M;
//		show();
//		if (N == 1) {
//			create_Insert(M);
//			show();
//		}if (N == 2) {
//			node_Plus(M);
//			show();
//		}if (N == 3) {
//			node_Delete(M);
//			show();
//		}
//	} while (N);
//}
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<cstdlib>
//using namespace std;
//int main() {
//	ifstream fin;
//	fin.open("text.txt");
//	if (fin.is_open() == false){
//		cerr << "Can't open file. Bye.\n";
//		exit(EXIT_FAILURE);
//	}
//	string item;
//	int count = 0; 
//	getline(fin, item, ':');
//	while (fin) {//while input is good
//		++count;
//		cout << count << ": " << item << endl;
//		getline(fin, item, ':');
//	}
//	cout << "Done\n"; 
//	fin.close();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int a = 0;
//void loop(int a) {
//	if (a = 10)cout << a<<'\n';
//	else loop(a + 1);
//}
//int main() {
//	loop(a);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main() {
//	int* p;
//	p = new int(5);
//	cout << *p;
//	system("pause");
//	system("cls");
//	cerr << "Rrror:404";
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//class  Name {
//public:
//	double* p;
//	void show();
//	Name() {};
//	Name(double,double);
//	~Name();
//	Name(const Name&);
//};
//Name::Name(double a,double b) {
//	p = new double[2];
//	p[0] = a;
//	p[1] = b;
//}
//Name::~Name() {
//	cout << "ccc\n";
//	delete []p;
//	p = NULL;
//}
//Name::Name(const Name& a) {
//	p = new double[2];
//	//p[0] = a.p[0];
//	//p[1] = a.p[1];//double和char不兼兼容
//}
//void Name::show() {
//	if (this->p[0] == 0 && this->p[1] == 0) {
//		cout << 0;
//		return;
//	}
//	if (this->p[0] != 0)cout << this->p[0];
//	if (this->p[1] == 0)return;
//	if (this->p[0] != 0 && this->p[1] > 0)cout << "+";
//	if (this->p[1] == 1) {
//		cout << "i"; return;
//	}
//	else if (this->p[1] == -1) {
//		cout << "-i"; return;
//	}
//	else {
//		cout << this->p[1] << "i";
//	}
//}
//Name add(Name a,Name b) {
//	static Name temp;
//	temp.p[0] = a.p[0] + b.p[0];
//	temp.p[1] = a.p[1] + b.p[1];
//	 
//	return temp;
//}
//Name sub(Name a, Name b) {
//	Name temp;
//	temp.p[0] = a.p[0] - b.p[0];
//	temp.p[1] = a.p[1] - b.p[1];
//	return temp;
//}
//Name mul(Name a, Name b) {
//	Name temp;
//	temp.p[0] = a.p[0] * b.p[0] - a.p[0] * b.p[0];
//	temp.p[1] = a.p[0] * b.p[1] + a.p[1] * b.p[0];
//	return temp;
//}
//int main() {
//	Name temp1(1, 2);
//	Name temp2 = temp1;//学的是复制构造函数，所以你的假设办不成立
//	cout << &temp1.p[0] << endl;
//	cout << &temp2.p[0];
//	double a, b;
//	char p;
//	cin >> a >> b;
//	Name temp1(a,b);
//	cin >> a >> b;
//	Name temp2(a,b);
//	Name temp3(0,0);
//	cin >> p;
//	if (p == '+') {
//		
//		//add(temp1, temp2).show();
//		//cout<<add(temp1, temp2).p[0]<<" "<< add(temp1, temp2).p[1];
//		//Name temp4=add(temp1, temp2);
//		//temp4.show();
//
//		//Name* p;
//		//p=&(add(temp1, temp2));
//		//p->show();    最后输出p是空的，return 回来的变量转手就会被析构掉????
//
//
//		Name temp4 = add(temp1, temp2);
////		temp3 = temp4;怎么写？？？
//	}
//	else if (p == '-')temp3 = sub(temp1, temp2);
//	else if (p == '*')temp3 = mul(temp1, temp2);
	//Name temp2 = temp1;;
//}

//#2004202305
//#include<iostream>
//using namespace std;
//class Text {
//public:
//	const int a, b;
//	int c;
//	Text(int,int ,int);
//};
//Text::Text(int a, int b, int c) :a(a), b(b) {
//	this->c = c;
//}
//int main() {
//
//}
//#2004202305
//#include<iostream>
//using namespace std;
//class scross {
//	char id[20];
//	int Mat, Eng, Pro, avs;
//	static int cre, del;
//public:
//	void inscore();
//	void showscore();
//	scross() { pluobj(); };
//	//static void initdel(int a) { cre = a;}
//	static void initdel(int a) { del = a; }
//	static void pluobj() { cre++; }
//	static void delobj() { del--; }
//	static void showdel() { cout << del; }
//	static void showcre() { cout << cre; }
//	~scross() { delobj(); }
//};
//int scross::del;
////int scross::cre;
//int scross::cre = 0;
//void scross::inscore() {
//	cin >> this->id;
//	cin >> this->Mat >> this->Eng >> this->Pro;
//	this->avs = (this->Mat + this->Eng + this->Pro) / 3;
//}
//void scross::showscore() {
//	cout << this->id << " " << this->Mat << " " << this->Eng << " " << this->Pro << " " << this->avs << endl;
//}
//int main() {
//	int N;
//	cin >> N;
//	scross::initdel(N);
//	scross* stu = new scross[N];
//	for (int j = 0; j < N; j++) {
//		stu[j].inscore();
//	}
//	for (int j = 0; j < N; j++) {
//		stu[j].showscore();
//	}
//	delete[]stu;
//	cout << N;
//	return 0;
//}
//complex::complex(double m=0, double n=0) 



//#include<iostream>
//using namespace std;
//class complex {
//	double a;
//	double b;
//public:
//	complex(double m = 0, double n = 0);
//	void show();//直接输出a+bi的形式，不用区分a和b的正负符号，例如a=1,b=-1则输出1+-1i，例如a=1,b=0则输出1+0i即可。
//	friend complex operator+(complex c1, complex c2);
//};
//complex::complex(double m, double n) {
//	this->a = m;
//	this->b = n;
//}
//void complex::show() {
//	cout << this->a;
//	if (this->b >= 0)cout << "+";
//	cout << this->b << "i";
//}
//complex operator+(complex c1, complex c2) {
//	complex temp;
//	temp.a = c1.a + c2.a;
//	temp.b = c1.b + c2.b;
//	return temp;
//}
//int main() {
//	double a, b, c, d;
//	cin >> a >> b >> c >> d;
//	complex c1(a, b), c2(c, d), c3;
//	c3 = c1 + c2;
//	c3.show();
//}

//#include<iostream>
//using namespace std;
//class complex {
//	double a;
//	double b;
//public:
//	complex(double aa = 0, double bb = 0) { a = aa, b = bb; }
//	friend complex& operator-(const complex& c1, const complex& c2);
//	friend complex& operator+(complex c1, complex c2);
//	friend istream& operator>>(istream& i, complex& c);
//	friend ostream& operator<<(ostream& o, complex& c);
//};
//complex& operator-(const complex& c1, const complex& c2) {
//	complex temp;
//	temp.a = c1.a - c2.a;
//	temp.b = c1.b - c2.b;
//	return temp;
//}
//complex& operator+(complex c1, complex c2) {
//	complex temp;
//	temp.a = c1.a + c2.a;
//	temp.b = c1.b + c2.b;
//	return temp;
//}

//ostream& operator<<(ostream& o, complex& c) {
//	if (c.a) o << c.a;
//	if (c.a && c.b > 0 && c.b) o << "+";
//	if (c.b && c.b == 1)o << "i";
//	if (c.b && c.b != 1 && c.b != -1) o << c.b << "i";
//	if (c.b && c.b == -1)o << "-i";
//	if (c.a == 0 && c.b == 0)o << "0";
//	o << '\n';
//	return o;
//}
//
//int main() {
//	char p[100], m;
//	int ii = 1;
//	//for (int i = 0; i < 2; i++) {
//	complex c1, c2;
//	complex temp1;
//	//cin >> p;
//	cin >> c1 >> c2;
//	cin >> m;
//	if (m == '+') {
//		temp1 = c1 + c2;
//		/*cout << "【样例输出" << ii << "】\n";*/
//		cout << temp1;
//	}
//	else if (m == '-') {
//		temp1 = c1 - c2;
//		/*cout << "【样例输出" << ii << "】\n";*/
//		cout << temp1;
//	}
//	//	ii++;
//	//}
//}
//	friend complex& operator-(const complex& c1, const complex& c2);
//	friend complex& operator+(complex c1, complex c2);
//	friend istream& operator>>(istream& i, complex& c);
//	friend ostream& operator<<(ostream& o, complex& c);
//};

//#include<iostream>
//using namespace std;
//class complex {
//	double a;
//	double b;
//public:
//	complex(double , double );
//	void show();//直接输出a+bi的形式，不用区分a和b的正负符号，例如a=1,b=-1则输出1+-1i，例如a=1,b=0则输出1+0i即可。
//	complex operator+(complex c) {
//		complex temp;
//		temp.a = this->a + c.a;
//		temp.b = this->b + c.b;
//		return temp;
//	}
//	complex operator-(complex c) {
//		complex temp;
//		temp.a = this->a - c.a;
//		temp.b = this->b - c.b;
//		return temp;
//	}
//};
//complex::complex(double m=0, double n=0) {//不可以写在外面？？
//	this->a = m;
//	this->b = n;
//}
//void complex::show() {
//	cout << this->a;
//	cout << "+";
//	cout << this->b << "i" << endl;
//}
//int main() {
//	double a, b, c, d;
//	cin >> a >> b >> c >> d;
//	complex c1(a, b), c2(c, d), c3;
//	c3 = c1 + c2;
//	c3.show();
//	c3 = c1 - c2;
//	c3.show();
//}
//using namespace std;
//int main() {
//	int i = 2;
//	double& r = i;
//	const double& r = i;
//	double i = 2;
//	double& r = i;
//	return 0;
//
//}
//#include <iostream>
//using namespace std;
//int g_constructCount = 0;
//int g_copyConstructCount = 0;
//int g_destructCount = 0;
//struct A{
//	A() {
//		cout << "construct: " << ++g_constructCount << endl;
//	}
//	A(const A& a){
//		cout << "copy construct: " << ++g_copyConstructCount << endl;
//	}
//	~A(){
//		cout << "destruct: " << ++g_destructCount << endl;
//	}
//};
//A GetA(){
//	return A();
//}
//int main() {
//	A a = GetA();//编译时设置编译选项-fno-elide-constructors用来关闭返回值优化效果。
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int*& fun() {
//	int a = 2;
//	int*& b = &a;
//	return b;
//}
//int fun2() {
//	int a[100];
//	for (int i = 0; i < 100; i++)
//		a[i] = 1000;
//	return 0;
//}
//int main(int argc, char* argv[]) {
//	int& c = fun();
//	fun2();
//	cout << c << endl;
//	system("pause");
//	return 0;
//}
//-------------------------算法----------------------------
//最后的书本都会看，为什么不先看一些长效的东西呢？
//能在时间差不大的情况下落到实处的东西才是真知识，所以谁讲就不一定重要了
//渐渐地，我把编译器当做了我之前的有道云笔记，我把一些灵感直接写在了注释里
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main() {
//	double a = 4.01;
//	double b = floor(a + 0.5);
//	if (b== a)cout << "Y";
//}


//#include<iostream>
//using namespace std;
//int main() {
//	int a = 987654321;
//	a = a * 3;
//	cout << a;
//}


//#include<iostream>
//#include<ctime>
//using namespace std;
//int main() {
//	int sum = 1;
//	for (int i = 1; i < 20; i++) {
//		sum *= i;
//	}
//	system("pause");
//	cout << clock() / CLOCKS_PER_SEC << endl;
//	cout << sum;
//}


//#include<iostream>
//using namespace std;
//int main() {
//	int x;
//	char a[7] = { '0','1','2','5','6','8','\0' };
//	a[x = 1] = 'd';
//	cout << a;
//}


//#include<iostream>
//using namespace std;
//int main() {
//	int *a, b;
//	a=new int 
//}


	//~M() {所以我这个到底是哪里的内存提前被释放然后出现了内存错误？？？？？
	//	//for (int i = 0; i < this->len; i++) {
	//	//	delete[]p[i];
	//	//	p[i] = NULL;
	//	//}
	//	delete[]p;
	//	p = NULL;
	//}//赋值调用的时候离开又会释放这个内存
		/*strcpy(this->p,c.p);*///深复制
//#include<iostream>
//#include<cstring>
//using namespace std;
//int n;
//class M {
//	int** p;
//	int len;
//public:
//	M(int a) {
//		len = a;
//		p = new int* [a];
//		for (int i = 0; i < a; i++)p[i] = new int[a];
//	}
//	M operator=(M c) {
//		for (int ii = 0; ii < c.len; ii++) {
//			for (int j = 0; j < c.len; j++) {
//				this->p[ii][j] = c.p[ii][j];
//			}
//		}
//		return *this;
//	}
//	friend M operator+(M& c1, M& c2);
//	friend istream& operator>>(istream& i, M& c);
//	friend ostream& operator<<(ostream& o, M& c);
//};
//M operator+(M& c1, M& c2) {
//	M temp(c1.len);
//	for (int i = 0; i < c1.len; i++) {
//		for (int j = 0; j < c1.len; j++) {
//			temp.p[i][j] = c1.p[i][j] + c2.p[i][j];
//		}
//	}
//	return temp;
//}
//istream& operator>>(istream& i, M& c) {
//	for (int ii = 0; ii < c.len; ii++) {
//		for (int j = 0; j < c.len; j++) {
//			i >> c.p[ii][j];
//		}
//	}
//	return i;
//}
//ostream& operator<<(ostream& o, M& c) {
//	for (int i = 0; i < c.len; i++) {
//		for (int j = 0; j < c.len; j++) {
//			if (j + 1 < c.len) o << c.p[i][j] << " ";
//			else  o << c.p[i][j];
//		}
//		o << endl;
//	}
//	return o;
//}
//int main() {
//	cin >> n;
//	M m1(n), m2(n), m3(n);
//	cin >> m1 >> m2;
//	m3 = m1 + m2;
//	cout << m3;
//}

//M mi(3);
//cin >> mi;
//cout << mi;



//for (int ii = 0; ii << len; ii++) v[ii] = d.v[ii];


//#include<iostream>
//using namespace std;
//class douary {
//public:
//	douary(int m, int n) {
//		r = m, c = n;
//		int len = m * n;
//		v = new int[len];
//	}
//	~douary() {
//		delete []this->v;
//	}
//	douary(const douary& d) {
//		r = d.r,c = d.c;
//		int len = d.r * d.c;
//		v = new int[len];
//		for (int ii = 0; ii < len; ii++) v[ii] = d.v[ii];
//		cout << "Copying.\n";
//	}
//	friend istream& operator>>(istream&, douary&);//输入向量内容
//	friend ostream& operator<<(ostream&, const douary&);//输出向量内容，须排列成二维的形式
//	friend douary operator+(const douary& d1, const douary& d2);
//private:
//	int* v;
//	int r, c;//r表示行数，c表示列数
//};
//douary operator+(const douary& d1, const douary& d2) {
//	static douary temp(d1.r, d1.c);
//	for (int ii = 0; ii < d1.r; ii++) {
//		for (int jj = 0; jj < d1.c; jj++) {
//			temp.v[ii * d1.c + jj] = d1.v[ii * d1.c + jj] + d2.v[ii * d1.c + jj];
//		}
//	}
//	return temp;
//}
//istream& operator>>(istream& i, douary& c1) {
//	for (int ii = 0; ii < c1.r; ii++) {
//		for (int jj = 0; jj < c1.c; jj++) {
//			i >> c1.v[ii * c1.c + jj];
//		}
//	}
//	return i;
//}
//ostream& operator<<(ostream& o, const douary& c1) {
//	for (int ii = 0; ii < c1.r; ii++) {
//		for (int jj = 0; jj < c1.c; jj++) {
//			if (jj < c1.c - 1)o << c1.v[ii * c1.c + jj] << " ";
//			else o << c1.v[ii * c1.c + jj];
//			//o << c1.[ii * c1.c + jj * c1.r] <<" ";
//		}
//		o << endl;
//	}
//	return o;
//}
//int main() {
//	douary a1(2, 3), a2(2, 3);
//	cin >> a1 >> a2;
//	cout << a1 + a1 + a2;
//}
/*
3
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
2
*/

//#include<iostream>
//using namespace std;
//class M{
//public:
//	int n;
//	int* p;
//	M(int a = 0){
//		int len = a * a;
//		p = new int[len];
//		n = a;
//	}
//	//M(const M& d) {
//	//	int len = d.n * d.n;
//	//	p = new int[len];
//	//	n = d.n;
//	//	for (int i = 0; i < n * n; i++) p[i] = d.p[i];
//	//}//额外空间的析构必须要写复制构造函数！！！
//	M operator=(M);
//	friend istream& operator>>(istream&, M&);
//	friend ostream& operator<<(ostream&, M&);
//	friend M& operator+(M, M);
////	~M();
//};
//M M::operator=(M x){
//	delete[]p;
//	int i;
//	n = x.n;
//	p = new int[n * n];
//	if (p != 0){
//		for (i = 0; i < n * n; i++)
//			p[i] = x.p[i];
//	}
//	return *this;
//}
////M::~M(){//return的匿名函数不是静态的，他和局部变量是指向同一片内存，要想不写构造函数，就要同时保证两边不要同时释放
////	delete[]p;
////	p = NULL;
////	n = 0;
////}
//istream& operator>>(istream& cin, M& x){
//	int i;
//	for (i = 0; i < x.n * x.n; i++)
//		cin >> x.p[i];
//	return cin;
//}
//ostream& operator<<(ostream& cout, M& x){
//	int i;
//	for (i = 0; i < x.n * x.n; i++){
//		cout << x.p[i] << " ";
//		if ((i + 1) % 3 == 0)
//			cout << endl;
//	}
//	return cout;
//}
//M& operator+(M x, M y){
//	static M z;//定义为静态引用还是不太对
//	z.n = x.n;
//	z.p = new int[x.n *x.n];
//	int i;
//	for (i = 0; i < x.n * x.n; i++)
//		z.p[i] = x.p[i] + y.p[i];
//	return z;
//}
//int main(){
//	int n;
//	cin >> n;
//	M m1(n), m2(n), m3(n);
//	cin >> m1 >> m2;
//	m3 = m1 + m2;
//	cout << m3;
//}


//#include<iostream>
//#define ll long long int
//using namespace std;
//int main() {
//	ll sum = 0;
//	for (int i = 0; i < 10000; i++) {
//		sum += i;
//	}
//	cout << sum;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	int a[9] = { 0,1,2,3,4,6,7,8,9 };
//	cout << (lower_bound(a, a + 9, 5) - a);
//}

//#include<iostream>
//using namespace std;
//int p[200][200];
//int next[4][4]={(1,0),(-1,0),(0,1),(0,-1)};
//void dfs() {
//	
//}
//int main() {
//	int t, ii, jj, step = 0;
//	cin >> t;
//	while (t--) {
//		cin >> ii >> jj;
//
//		step = 0;
//	}
//}

//#include<iostream>
//#include<algorithm>
//#define ll unsigned long long
//using namespace std;
//typedef struct xm {
//	ll  a, m, b, tep;
//}w;
//bool cmp(w a, w b) {
//	return a.m > b.m;
//}
//w p[100001];
//int main() {
//	ll sum = 0, t, t1;;
//	cin >> t;
//	while (t--) {
//		cin >> t1;
//		for (int i = 0; i < t1; i++) cin >> p[i].a;
//		for (int i = 0; i < t1; i++) cin >> p[i].b;
//		for (int i = 0; i < t1; i++) p[i].m = (p[i].b * 1.0) / (p[i].a * 1.0);
//		sort(p, p + t1, cmp);
//		for (int i = 0; i < t1; i++)sum+=p[i].a,p[i].tep = sum;
//		for (int i = 0; i < t1; i++)sum += p[i].b * p[i].tep;
//			cout << sum << endl;
//			sum = 0;
//	}
//}

//#include<iostream>
//#include<cmath>
//#include<cstring>
//#define r(i,a,b) for(int i=a;i<b;i++)
//#define rr(i,a,b) for(int i=a;i<=b;i++)
//bool cn[1000000000];
//using namespace std;
//int main() {
//	int a;
//	cin >> a;
//	memset(cn,0,sizeof)
//	int len = sqrt(a);
//	r(ii, 0, len) {
//		if (!a % ii) cn[ii] = 1;
//	}
//	
//}
//#include<iostream>
//#define ll long long 
//ll L1(ll n, ll i, ll dfs) {
//	if (!n % i) return L1(n / i, i + 1, dfs + 1);
//	else return dfs;
//}
//int main() {
//	cout<<L1()
//}


//没有边界的词语：...之内的
//要做到不以词害意，简短而干练的表达真的很难

//#include<iostream>
//#include<cstring>
//using namespace std;
//class test {
//	char* a;
//	int len;
//public:
//	test(int n = 26) {
//		a = new char[n + 1];
//		strcpy(a, "");
//		len = n;
//		for (int i = 0, count = 0; i < len; i++) {
//			a[i] = 'a' + count;
//			if (i % 27 == 0)
//				count = 0;
//			count++;
//		}
//	}
//	test(test& c1) {
//		delete[]a;
//		a = new char[c1.len];
//		strcpy(a, c1.a);
//		len = c1.len;
//	}
//	test& operator=(const test& obj) {
//		delete[]a;
//		a = new char[obj.len];
//		strcpy(a, obj.a);
//		len = obj.len;
//		return *this;
//	}
//	~test() { delete[]a; len = 0; }
//	friend ostream& operator<<(ostream& output, test& obj);
//};
//ostream& operator<<(ostream& output, test& obj) {
//	int step = 0;
//	for (int i = 0; i < obj.len; i++) {
//		output << obj.a[i] << " ";
//		step++;
//		if (!(step % 10))output << endl;
//	}
//	return output;
//}
//int main() {
//	int k, l;
//	cin >> k >> l;
//	test a(k);
//	test c(a);
//	test b(l);
//	c = b;
//	cout << "a=" << endl << a << endl;
//	cout << "b=" << endl << b << endl;
//	cout << "c=" << endl << c << endl;
//}


//#include<iostream>
//using namespace std;
//class node {
//	int data;
//public:
//	node* next;
//	void set(int mm) {
//		data = mm;
//		next = NULL;
//	};
//	void print() {
//		cout << data << " ";
//	}
//};
//class list {
//	node* head=NULL;
//public:
//	void creatlist1() {//逆序
//		int mm;
//		node* p;
//		cin >> mm;
//		while (mm) {
//			p = new node;
//			p->set(mm);
//			if (head == NULL) { head = p; }
//			else {
//				p->next = head;
//				head = p;
//			}
//			cin >> mm;
//		}
//	}
//	void creatlist2() {//正序 
//		int mm;
//		node* p, * s=NULL;
//		cin >> mm;
//		while (mm) {
//			p = new node;
//			p->set(mm);
//			if (head == NULL) {
//				head = p;
//				s = p;
//			}
//			else {
//				s->next = p;
//				s = p;
//			}
//			cin >> mm;
//		}
//	}
//	void showlist() {//遍历 
//		node* p = head;
//		while (p!= NULL) {
//			//if(p->next!=NULL) 
//			p->print();
//			p = p->next;
//		}
//		cout << endl;
//	}
//	void deletelist() {
//		node* p = head, * s = head;
//		while (p != NULL) {
//			s = s->next;
//			delete p;
//			p = s;
//		}
//	}
//};
//int main() {
//	int n;
//	while (1) {
//		cin >> n;
//		if (n == 0)break;
//		if (n == 1) {
//			list l1;
//			l1.creatlist1();
//			l1.showlist();
//			l1.deletelist();
//		}
//		if (n == 2) {
//			list l2;
//			l2.creatlist2();
//			l2.showlist();
//			l2.deletelist();
//		}
//	}
//
//}

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

// #include<iostream>
// #include<cstring>
// using namespace std;
// const  int  MaxListSize=100;//根据问题修改该值
// class SeqCharList{
//     char data[MaxListSize]; //存储字符串
//     int size;            //元素个数
// public:
//     SeqCharList();//构造函数
//     void Clear();//清空表
//     bool IsEmpty();//判断如果为空表，返回true，否则返回false
//     char Get(int k);//返回第k个字符
//     int Locate(char e);//返回第一个与元素e匹配的元素位序
//     char Delete(int i);//删除第i个元素，并返回所删除元素值
//     void Print();//输出字符串
//     void Encryption();//字符串加密
// }; //SeqCharList

// SeqCharList::SeqCharList(){size=0;}
// void SeqCharList::Clear(){size=0;};
// bool SeqCharList::IsEmpty(){
//     if(size==0)return true;
//     else return false;
// }
// char SeqCharList::Get(int k){return data[k-1];}
// int SeqCharList::Locate(char e){
//     int flag=-1;
//     for(int i=0;i<size;i++){
//         if(data[i]==e){flag=i;break;}
//     }
//     return flag;
// }
// char SeqCharList::Delete(int i){
//     char ret=data[i-1];
//     for(int j=i-1;j<size;j++){
//         data[j]=data[j+1];
//     }
//     size--;
//     return ret;
// }
// void SeqCharList::Print(){
//     for(int i=0;i<size;i++){
//         if(data[i]=='!'||data[i]=='#'||data[i]=='@'||data[i]=='+'||data[i]=='+'||data[i]=='-'||data[i]=='*'||data[i]=='?'||data[i]=='$'||data[i]==':'||data[i]==';')
//             continue;
//         cout<<data[i];
//     }
// }
// void SeqCharList::Encryption(){
//     int flag;
//     cin>>flag;
//     cin>>data;
//     size=strlen(data);
//     for(int i=0;i<strlen(data);i++){
//         if(data[i]=='!'||data[i]=='#'||data[i]=='@'||data[i]=='+'||data[i]=='+'||data[i]=='-'||data[i]=='*'||data[i]=='?'||data[i]=='$'||data[i]==':'||data[i]==';')
//             continue;
//         data[i]+=flag;
//     }
// }

// int main(){
//     SeqCharList l1;
//     while(1){
//         l1.Encryption();
//         l1.Print();
//         cout<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// int main (){
//  std::vector<int> myvector;
//  int myint;
//  std::cout << "Please enter some integers (enter 0 to end):\n";
//  do {
//    std::cin >> myint;
//    myvector.push_back (myint);
//  } while (myint);
//  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
//  return 0;
// }
/*
		cout<<max<<endl<<flag;
		a/=flag;
		flag++;
		while(!(a%flag)){
			cout<<"*"<<flag;
			a/=flag;
			flag++;
		}
        cout<<endl;
*/
//#include<iostream>
//#include<cstring>
//using namespace std;
//class student{
//    char name[100];
//    int id;
//public:      
//    student(){strcpy(name,"");id=0;}
//    char* getname(){return name;}
//    friend istream& operator>>(istream&input,student &obj);
//    friend ostream& operator<<(ostream&output,student &obj);
//};
//istream& operator>>(istream&input,student &obj){
//	input>>obj.id>>obj.name;
//	return input;
//}
//ostream& operator<<(ostream&output,student &obj){
//	output<<obj.id<<" "<<obj.name;
//	return output;
//}
//class student_array{
//    student *a;
//    int num;
//public:
//    student_array(int i=0){a=new student[i];num=i;}
//    void input(){
//       for(int j=0;j<num;j++) cin>>a[j];
//    }
//    void sort(){
//       for(int i=0;i<num;i++){
//	   	    for(int j=i;j<num;j++){
//    			if(strcmp(a[i].getname(),a[j].getname())>0)swap(a[i],a[j]);
//			}
//	   }
//    }
//    void show(){
//       for(int i=0;i<num;i++)
//           cout<<a[i]<<endl;
//    }
//};
//int main(){
//    int k;
//    cin>>k;
//    student_array m(k);
//    m.input();
//    m.sort();
//    m.show();
//}
//
//#include<iostream>
//#include<cstring>
//using namespace std;
//class building{
//public:
//	building(){};
//	building(char p[],int fl){strcpy(name,p);floor=fl;}
//	virtual ~building(){}
//	virtual void print(){cout<<"name="<<name<<" floors="<<floor;}
//protected:
//	char name[100];
//	int floor;
//};
//class house:virtual public building{
//	int sellprice;
//public:
//	house(int se){ sellprice=se;}
//	void print(){cout<<" sellprice="<<sellprice;} 
//	int getsgetsellprice(){return sellprice;}
//};
//class office :virtual public building{
//	int lendprice;
//public:	
//	office(int le){lendprice=le;}
//	void print(){cout<<" lendprice="<<lendprice<<endl;} 
//	int getlendprice(){return lendprice;}
//};
//class A:virtual public office,virtual public house{
//public:
//	A(char na[],int fl,int se,int le):building(na,fl),house(se),office(le){cout<<"Building house office A"<<endl;}
//	~A(){cout<<"A office house Building";}
//	void print(){
//	building::print();
//	house::print();
//	office::print();
//	} 
//};
//int main(){
//	char n[100];
//	int f,sel,lea;
//	cin>>n>>f>>sel>>lea;
//	building *p=new A(n,f,sel,lea);
//	p->print();
//	delete p;
//	return 0;
//
//}
//
//
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct node{
// int data;
// node *next;
//};
//node * head;
//void create(){ 
//	int i;
//	node *p;
//	cin>>i;
//	while(i!=0){
//		p=new node;
//  		p->data=i;
//  		p->next=head;
//  		head=p;
//  		cin>>i;
// 	}
//}
//int max3(){
//	int step=0,i=0;
//	node*p=head;
//	while(p!=NULL){
//		step++;
//		p=p->next;
//	}
//	int *list=new int[step+1];
//	p=head;
//	while(p!=NULL){
//		list[i]=p->data;
//		i++;
//		p=p->next;
//	}
//	list[i]='\0';
//	sort(list ,list+step+1);
//	int temp=list[step]+list[step-1]+list[step-2];
//	return temp;
//}
//int main(){
// create(); 
// cout<<max3();
// return 0;
//}   �Զ����� 

//#include<iostream>
//using namespace std;
//class Shape{
//public:
//	Shape *next;
//	double x;
//	double y;
//	Shape(double m,double n):x(m),y(n){next=NULL;}
//	virtual coid print()=0;
//};
//class A:public Shape{
//public:
//	double a,b;
//	A(double m,double n):a(m),b(n){}
//	void print(){
//		
//	}
//};
//class B: public Shape{
//public:
//	double r;
//	B (double a, double b ,double c ):
//	void print(){
//	}
//};
//class C: public Shape{
//public:
//	double a,b;
//	void print(){
//	}
//};
//Shape *head;
//void insertnode(Shape *s){
//	Shape *p;
//	if(head==NULL){
//		
//	}
//	else{
//		
//	}
//}
//void deletenode(){
//	
//}
//void showlist(){
//	Shape *p;
//	p=head;
//	while(p!=NULL){
//		p->print();
//		p=p->next;
//	}
//}
//int main(){
//	int order();
//	while(1){
//		cout<<"1����,2����,3����,0�˳�"<<endl;
//		cin>>order;
//		if(order==0)return 0;
//		if(order==1){
//			int n; 
//			cout<<"1 ������,2Բ��,3��Բ"<<endl;
//			cin>>n;
//			if(n==1){
//				Shape*temp;
//				double a,b,c;
//				cin>>a>>b>>c;
//				temp=new B(a,b,c);
//				insertnode(temp);
//			}
//			if(n==2){
//				
//			}
//			if(n==3){
//				
//			}
//			insertnode();
//		}
//		if(order==2)
//		if(order==3)
//	}
//	 
//} 
// #include<unistd.h>
// #include<signal.h>
// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/param.h>
// #include<sys/types.h>
// #include<sys/stat.h>
// #include<time.h>
// void init_daemon(){
//     int pid;
//     int i;
//     pid=fork();
//     if(pid<0) exit(1);
//     else if(pid>0) exit(0);
//     setsid();
//     pid=fork();
//     if(pid>0) exit(0); 
//     else if(pid<0) exit(1);
//     for(i=0;i<NOFILE;i++) close(i);
//     chdir("/tmp");
//     umask(0);
//     return;
// }
// void main(){
//     FILE *fp;
//     time_t t;
//     printf("pid = %d\n", getpid());
//     init_daemon();
//     while(1){
//         sleep(6);
//         fp=fopen("hello2.log","a");
//         if(fp>=0){
//             time(&t);
//             fprintf(fp,"current time is:%s\n",asctime(localtime(&t)));
//             fclose(fp);
//         }
//     }
//     return;
// }
// #include<iostream>
// #include<fstream>
// #include<string>
// #include<cstdlib>
// using namespace std;
// int main() {
// 	ifstream fin;
// 	fin.open("text.txt");
// 	if (fin.is_open() == false){
// 		cerr << "Can't open file. Bye.\n";
// 		exit(EXIT_FAILURE);
// 	}
// 	string item;
// 	int count = 0; 
// 	getline(fin, item, ':');
// 	while (fin) {//while input is good
// 		++count;
// 		cout << count << ": " << item << endl;
// 		getline(fin, item, ':');
// 	}
// 	cout << "Done\n"; 
// 	fin.close();
// 	cin.get();
// 	cin.get();
// 	return 0;
// }
// #include<stdio.h>
// int  main(){
//     printf("Hello ,C!!");
// }
//#include<iostream>
//#include<cstring>
//using namespace std;
//class student{
//    char name[100];
//    int id;
//public:      
//    student(){strcpy(name,"");id=0;}
//    char* getname(){return name;}
//    friend istream& operator>>(istream&input,student &obj);
//    friend ostream& operator<<(ostream&output,student &obj);
//};
//istream& operator>>(istream&input,student &obj){
//	input>>obj.id>>obj.name;
//	return input;
//}
//ostream& operator<<(ostream&output,student &obj){
//	output<<obj.id<<" "<<obj.name;
//	return output;
//}
//class student_array{
//    student *a;
//    int num;
//public:
//    student_array(int i=0){a=new student[i];num=i;}
//    void input(){
//       for(int j=0;j<num;j++) cin>>a[j];
//    }
//    void sort(){
//       for(int i=0;i<num;i++){
//	   	    for(int j=i;j<num;j++){
//    			if(strcmp(a[i].getname(),a[j].getname())>0)swap(a[i],a[j]);
//			}
//	   }
//    }
//    void show(){
//       for(int i=0;i<num;i++)
//           cout<<a[i]<<endl;
//    }
//};
//int main(){
//    int k;
//    cin>>k;
//    student_array m(k);
//    m.input();
//    m.sort();
//    m.show();
//}
//
//#include<iostream>
//#include<cstring>
//using namespace std;
//class building{
//public:
//	building(){};
//	building(char p[],int fl){strcpy(name,p);floor=fl;}
//	virtual ~building(){}
//	virtual void print(){cout<<"name="<<name<<" floors="<<floor;}
//protected:
//	char name[100];
//	int floor;
//};
//class house:virtual public building{
//	int sellprice;
//public:
//	house(int se){ sellprice=se;}
//	void print(){cout<<" sellprice="<<sellprice;} 
//	int getsgetsellprice(){return sellprice;}
//};
//class office :virtual public building{
//	int lendprice;
//public:	
//	office(int le){lendprice=le;}
//	void print(){cout<<" lendprice="<<lendprice<<endl;} 
//	int getlendprice(){return lendprice;}
//};
//class A:virtual public office,virtual public house{
//public:
//	A(char na[],int fl,int se,int le):building(na,fl),house(se),office(le){cout<<"Building house office A"<<endl;}
//	~A(){cout<<"A office house Building";}
//	void print(){
//	building::print();
//	house::print();
//	office::print();
//	} 
//};
//int main(){
//	char n[100];
//	int f,sel,lea;
//	cin>>n>>f>>sel>>lea;
//	building *p=new A(n,f,sel,lea);
//	p->print();
//	delete p;
//	return 0;
//
//}
//
//
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct node{
// int data;
// node *next;
//};
//node * head;
//void create(){ 
//	int i;
//	node *p;
//	cin>>i;
//	while(i!=0){
//		p=new node;
//  		p->data=i;
//  		p->next=head;
//  		head=p;
//  		cin>>i;
// 	}
//}
//int max3(){
//	int step=0,i=0;
//	node*p=head;
//	while(p!=NULL){
//		step++;
//		p=p->next;
//	}
//	int *list=new int[step+1];
//	p=head;
//	while(p!=NULL){
//		list[i]=p->data;
//		i++;
//		p=p->next;
//	}
//	list[i]='\0';
//	sort(list ,list+step+1);
//	int temp=list[step]+list[step-1]+list[step-2];
//	return temp;
//}
//int main(){
// create(); 
// cout<<max3();
// return 0;
//}   �Զ����� 

//#include<iostream>
//using namespace std;
//class Shape{
//public:
//	Shape *next;
//	double x;
//	double y;
//	Shape(double m,double n):x(m),y(n){next=NULL;}
//	virtual coid print()=0;
//};
//class A:public Shape{
//public:
//	double a,b;
//	A(double m,double n):a(m),b(n){}
//	void print(){
//		
//	}
//};
//class B: public Shape{
//public:
//	double r;
//	B (double a, double b ,double c ):
//	void print(){
//	}
//};
//class C: public Shape{
//public:
//	double a,b;
//	void print(){
//	}
//};
//Shape *head;
//void insertnode(Shape *s){
//	Shape *p;
//	if(head==NULL){
//		
//	}
//	else{
//		
//	}
//}
//void deletenode(){
//	
//}
//void showlist(){
//	Shape *p;
//	p=head;
//	while(p!=NULL){
//		p->print();
//		p=p->next;
//	}
//}
//int main(){
//	int order();
//	while(1){
//		cout<<"1����,2����,3����,0�˳�"<<endl;
//		cin>>order;
//		if(order==0)return 0;
//		if(order==1){
//			int n; 
//			cout<<"1 ������,2Բ��,3��Բ"<<endl;
//			cin>>n;
//			if(n==1){
//				Shape*temp;
//				double a,b,c;
//				cin>>a>>b>>c;
//				temp=new B(a,b,c);
//				insertnode(temp);
//			}
//			if(n==2){
//				
//			}
//			if(n==3){
//				
//			}
//			insertnode();
//		}
//		if(order==2)
//		if(order==3)
//	}
//	 
//} 
// #include<unistd.h>
// #include<signal.h>
// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/param.h>
// #include<sys/types.h>
// #include<sys/stat.h>
// #include<time.h>
// void init_daemon(){
//     int pid;
//     int i;
//     pid=fork();
//     if(pid<0) exit(1);
//     else if(pid>0) exit(0);
//     setsid();
//     pid=fork();
//     if(pid>0) exit(0); 
//     else if(pid<0) exit(1);
//     for(i=0;i<NOFILE;i++) close(i);
//     chdir("/tmp");
//     umask(0);
//     return;
// }
// void main(){
//     FILE *fp;
//     time_t t;
//     printf("pid = %d\n", getpid());
//     init_daemon();
//     while(1){
//         sleep(6);
//         fp=fopen("hello2.log","a");
//         if(fp>=0){
//             time(&t);
//             fprintf(fp,"current time is:%s\n",asctime(localtime(&t)));
//             fclose(fp);
//         }
//     }
//     return;
// }

// #include<stdio.h>
// int  main(){
//     printf("Hello ,C!!");
// }

// #include <algorithm>
// #include <iostream>
// using namespace std;
// int a[103][103];
// int b[103][103];  // 前缀和数组，相当于上文的 sum[]
// int main() {
//   int n, m;
//   cin >> n >> m;

//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {
//       cin >> a[i][j];
//       b[i][j] =
//           b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1] + a[i][j];  // 求前缀和
//     }
//   }

//   for(int i=0;i<n;i++){
// 	  for(int j=0;j<m;j++){
// 		  cout<<b[i][j]<<" ";
// 	  }
// 	  cout<<endl;
//   }

//   int ans = 1;

//   int l = 2;
//   while (l <= min(n, m)) {
//     for (int i = l; i <= n; i++) {
//       for (int j = l; j <= m; j++) {
//         if (b[i][j] - b[i - l][j] - b[i][j - l] + b[i - l][j - l] == l * l) {
//           ans = max(ans, l);
//         }
//       }
//     }
//     l++;
//   }

//   cout << ans << endl;
//   return 0;
// }

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const int MaxNum=1000000000;

class TreeNode{
    char NodeData;
    int w, parent, lchild, rchild;
public:
    TreeNode():lchild(NULL),rchild(NULL){};
    TreeNode(char a, int b,int c, int d ,int e):NodeData(a),w(b),parent(c),lchild(d),rchild(e){}
    friend class HuffmanTree;
};

class HuffmanTree {
    int n;//待编符号个数
    int rn;//实际需要编码个数
    TreeNode *Root;//待分配数组
    char *array;//待处理数组
    string code; //总编码
    string CharEdit[129];
    int CharCount[129];//char", . ? : ; " ' ! "
public:
    HuffmanTree(char[]);
    TreeNode *root(){ return Root;}
    void SelectMins(int,int &,int &);
    void Creat(char p[]);
    string Reverse(string);
    void Print();
    void GetCode();
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
    for (int i = 0; i < 129; i++) {
        if (CharCount[i]) rn++;
    }
    int step=0;
    Root=new TreeNode[2*rn-1];
    for (int i = 0;i < 129; i++) {//初始化前需要处理的节点
        if(CharCount[i]){
            Root[step]={ (char)i,CharCount[i],-1,-1,-1};
            step++;
        }
    }
    for(int i=rn;i<rn*2-1;i++){//初始化后续需要添加的节点
        Root[i].parent=-1;
        Root[i].rchild=-1;
        Root[i].lchild=-1;
    }
}
void HuffmanTree::SelectMins(int k, int &s, int &t) {
    int min1, min2;
    min1 = min2 = MaxNum;
    s = t = -1;
    for(int i=0;i<k;i++){
        if(Root[i].parent==-1){
            if(Root[i].w<min1){
                t=s;
                min2=min1;
                s=i;
                min1=Root[i].w;
            }
            else if(Root[i].w<min2){
                t=i;
                min2=Root[i].w;
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
    cout<<"编码为"<<code<<" "<<"长度为:"<<code.size()<<endl;
    ofstream os;
    os.open("./鲁丰华2.txt");
    os<<code;
}

int main(){
    int control;
    char p[100];
    string temp2;
    ifstream os;
    HuffmanTree *temp;
//    cout << "需要加密的字符串:\n";
    os.open("/鲁丰华.txt");
    getline(os,temp2);
    for(int i=0;i<temp2.size();i++){ p[i]=temp2[i];}
    if(os.is_open())
        cout<<"已从文件中读取到数据"<<temp2<<" "<<p<<", 请选择执行的操作:\n";
    else {
        cout << "读取数据失败\n";
        return 0;
    }
    while(1) {
        cout<<"[  1  ].加密\n";
        cout<<"[  2  ].解密\n";
        cout<<"[ -1  ].退出\n";
        cin>>control;

        if(control==-1) return 0;
        if(control==1) {
            HuffmanTree temp(p);
            temp.Creat(p);
            temp.Print();
            temp.GetCode();
        }
        if(control==2){

        }

    }
}