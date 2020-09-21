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

#include<stdio.h>
int  main(){
    printf("Hello ,C!!");
}