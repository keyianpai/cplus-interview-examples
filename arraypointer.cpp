//============================================================================
// Name        : arraypointer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
typedef bool (*fp)(const string,const string);//define func pointer type fp
bool hiBye(const string x,const string y){
	cout<<"x string legth():  "<<x.length()<<endl;//Returns the number of characters in the string, not including any
	  ///  null-termination.
	cout<<x<<"  and  "<<y<<endl;
	return true;
}
void ex1(){// func pointer
	    cout<<"hiBye() return true:"<<hiBye("hi","bye...")<<endl;
	    fp fp = hiBye; //use func pointer type fp defined above
	    fp("wawa","lololo..."); // use func pointer without *
	    (*fp)("wawa","lololo...");//use func pointer with *
		cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	}
void cstylestring(){
	char str1[]={'C','+','+'};//not c style
	char str2[]={'C','+','+','\0'};
	char str3[]="c++";
	//char str3[3]="c++";//initializer-string for array of chars is too long
	char* pstr1=str1;//not c style
	char* pstr2=str2;
	char* pstr3=str3;
	//char* pstr4="nnnnn";//cons char*,warning
	for (int i=0;i<4;++i){
		//str1[i]='p';
		cout<<str1[i]<<' ';
		cout<<str2[i]<<' ';
		cout<<str3[i]<<endl;

		cout<<"pointer to char"<<endl;
		pstr1[i]='s';
		cout<<pstr1[i]<<' ';
		cout<<pstr2[i]<<' ';
		cout<<pstr3[i]<<' ';
		//pstr4[i]='s';//wrong when run
		//cout<<pstr4[i]<<' '<<endl;//why output 'o'????

		cout<<"after pstr1 changed :"<<endl;
		cout<<str1[i]<<endl;

	}
}

int garr[4]; // all zeros
void arrayini(){
	int larr[4];//undefined
	int larr2[4] ={1};// other zeros
	for (int i=0;i<4;++i){
		cout<<garr[i]<<' ';
		cout<<larr[i]<<' ';
		cout<<larr2[i]<<endl;
	}
}
void arrayRef(){
	int arr[3] = {1,2,3};
	//int& b[3];//wrong ,no array of ref
	    //int(& b)[3];//wrong ,should ini
		int (&a)[3]= arr;
		//b=arr;
		for (int i=0;i<3;++i){
		cout<<a[i]<<endl;
		}

 }
void sizeofstrinpara(char str1[],char str2[]){//str1 and str2 degenerate to pointer,
	//cout<<sizeof(str1)<<"  "<<sizeof(str2)<<endl;//sizeof pointer
	//cout<<"strlen():"<<strlen(str1)<<"  "<<strlen(str2)<<endl;

}
void sizeofstr(){
	char str1[]="c++";//add \0 at tail,sizeof 4,strlen 3
	char str2[]={'c','+','+'};//sizeof 3,strlen unknown
	cout<<sizeof(str1)<<"  "<<sizeof(str2)<<endl;
	cout<<"strlen():"<<strlen(str1)<<"  "<<strlen(str2)<<endl;
	cout<<str1<<"jjjj"<<str2<<endl;
	printf("%s\t%s:\n",str1,str2);
	sizeofstrinpara(str1,str2);

}
void arrAdress(){
	int a[2]={2};
	cout<<a<<"  "<<&a<<endl;//same
	cout<<a+1<<"  "<<&a+1<<endl;//+4,+8
	//int(*b)[2]=&a;
	//int* c = &a; // cannot convert 'int (*)[2]' to 'int*' in initialization
}
int funcreta(int a){
	return a;

}
int& funcreta1(int& a){
	return a;

}
void lvalue(){
	int a =1;
	//funcreta(a)=8; //lvalue required as left operand of assignment
	funcreta1(a)=8;
	cout<<a<<endl;
}
void singleInherit(){
	struct B{
	//public:// public is must if B is class, struct default public
		B(void){
			cout<<"B\t";
		}
		~B(void){
			cout<<"~B\t";
		}

	};
	struct C{
			C(void){
				cout<<"C\t";
			}
			~C(void){
				cout<<"~C\t";
			}

		};
	struct D:B{
		D(void){
			cout<<"D\t";
		}
		~D(void){
			cout<<"~D\t";
		}
	private:
		C c;
	};
	D d;
}
void singleInherit2(){
	struct B{
		//public:// public is must if B is class, struct default public
			B(void){
				cout<<"B\t";
			}
			~B(void){
				cout<<"~B\t";
			}
			};
	struct C:B{// without :B: B	(B)C	~C	~B	~B// without B and :_b(b): B	B	C	~C	~B	~B
				C(B& b):_b(b){ // with &  B	B	C	~C	~B	~B	~B
					          // without B	B	C /~B/	~C	~B	~B	~B
					cout<<"C\t";
						}
				~C(void){
					cout<<"~C\t";
						}
	private:
				B _b;

			};
	B b;
	C c(b);

}
int main() {
	//ex1();
	//cstylestring();
	//arrayini();
	//arrayRef();
	//sizeofstr();
	//arrAdress();
	//lvalue();
	//singleInherit();
	singleInherit2();





	return 0;
}
