#include <vector>
#include <iostream>
#include <hash_map>
#include <iomanip>

using namespace std;


void test(int* pI){
	*pI *= 2;
};


int main()   
{   
	// int a[][3]={1,2,3,4,5,6};
	// printf("%d,%d",a[0],&a[0][0]);

	// int x[5]={2,4,6,8,10},*p;
	// int (*pp)[5];
	// p = x;
	// pp = &x;
	// printf("*(p++):%d;*pp:%d;pp:%d;x:%d",*(p++),*pp,pp,x);

	// printf("%-30.4f",45.44);

	int i=1;
	int k=(++i)+(++i);
	i = 1;
	int j=++i + ++i;

	printf("K:%d,i:%d,j:%d",k,i,j);

	return 0;
};



