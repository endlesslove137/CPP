#include <stdio.h>

class base{
	static int n;
	public:
		int a;
		static int getn(){return n;};
		base(){++n;};
		// base(int a):a(a){};
		~base(){--n;};
	private:
		int b;
	protected:
		int c;		
};
int base::n = 0;

class sub:private base{
	public:
		int d;
		sub(int a):d(a){
			c=1;
			// b=2;
		};
		~sub(){};
		void test(int a){
			cout<<a;
		};
};

// 类函数指针
// void (sub::*pf)(int);
// sub1.test(1);
// pf = &sub::test;
// (sub1.*pf)(2);

int main()   
{   	
	sub* sub1 = new sub(2);
	// sub1->a=2;
	// cout<<"%d\n"<<sub1->getn();
	delete sub1;
	// cout<<"%d\n"<<sub1->getn();
	return 0;
};



