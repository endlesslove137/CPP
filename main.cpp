#include <vector>
#include <iostream>
#include <hash_map>
#include <iomanip>
#include "common.h"
#define pi 
using namespace std;


void test(const int& v1,const int& v2){
	cout<<"%d,%d\n"<< v1<<v2;
};

class cTest{
	public:
		void echo(){ 
			cout<<"*ip:%d\n"<<*ip;
			c = 3;
		};
		int* ip;
		cTest(int i);
		cTest();
		~cTest(){
			delete ip;
			ip = NULL;
		};
		static void test2() { cout<<"test2\n";};
		static int c;
};

cTest::cTest(int i=0){
	ip = new int(i);
};
cTest::cTest(){
	ip = new int(1);
}


struct point{
	int x;
	int y;
} p1;

int cTest::c = 2;
int a;

char* GetMemory(void){
	char p[] = "helloworld";
	cout<<"%d\n"<<p;
	return p;
}

void printhaha(){
    static char haha[] = "haha";
    cout<<"hello "<<haha<<endl;
    haha[0] = haha[0]+1;
}

typedef char i8;

int main()   
{ 	
	// cTest test1;
	cTest test2();
	// test2.echo();

    return 0;
};



