#ifndef _common_h
#define _common_h
#include <vector>


using namespace std;

#define ArrayNum(a) sizeof(a)/sizeof(a[0])

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

 int MaxAge=300;
 static void TestFunc(int a){
 	printf("TestFunc:%d", a);
 };

void PrintVector(vector<int>& vI){
	for(int iS=0; iS<vI.size(); iS++){
		printf("%d,%d; ",iS,vI.at(iS));
	};
	printf("\n");
};

void PrintList(ListNode* List){
	ListNode* lT = List;
	while(lT){
		printf("->%d",lT->val);		
		lT = lT->next;
	} 
	printf("\n");
}

//从数字 x 中取出从向左数 第 i位的值 如 890 向左数第三位 为8
char GetValueByBit(int& x,char i){
	int iT = 1;
	--i;
	while(i--) iT *= 10;
	return x/iT%10;
}

ListNode* CreateList(int a[], int Length){
	ListNode *Head,*Next;
	Head=new ListNode(a[0]);
	Next = Head;
	for(int i=1;i<Length;i++){
		Next->next = new ListNode(a[i]);
		// printf("i:%d,Value:%d \n",i,a[i]);
		Next = Next->next;
	}
	return Head;
}
#endif