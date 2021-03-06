#ifndef _common_h
#define _common_h
#include <vector>
#include <set>


using namespace std;

#define ArrayNum(a) sizeof(a)/sizeof(a[0])

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode{
	int val;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(int x):val(x),Left(NULL),Right(NULL){}
};

 int MaxAge=300;
 static void TestFunc(int a){
 	cout<<"TestFunc:%d"<< a;
 };

void PrintVector(vector<int>& vI){
	for(int iS=0; iS<vI.size(); iS++){
		cout <<iS <<":"<< vI.at(iS) << endl;
	};
	cout<<"\n";
};

void PrintList(ListNode* List){
	ListNode* lT = List;
	while(lT){
		cout<<"->%d"<<lT->val;		
		lT = lT->next;
	} 
	cout<<"\n";
}

void PrintArray(int iA[],int number){
	for(int i=0;i<number;i++){
		cout <<i <<":"<< iA[i] << endl;
	}
	cout<<"\n";
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
		// cout<<"i:%d,Value:%d \n"<<i<<a[i];
		Next = Next->next;
	}
	return Head;
}

bool BAllUnique(string str,int iStart,int iEnd){
	set<char> c_set;
	pair<set<char>::iterator, bool> ret;
	int iEnd2 = iEnd>str.length() ? str.length() : iEnd;
	for(int i=iStart; i<iEnd2; i++){
		ret = c_set.insert(str.at(i));
		if (ret.second == false){
			return false;
		};
	};
	return true;
}

char Get1BitNum(int x){
	int result = 0;
	while(x>0){
		++result;
		x = x&(x-1);
	};
	return result;
};

char Get0BitNum(int x){
	int result = 0;
	while(x>0){
		++result;
		x = x|(x+1);
	};
	return result;
};

#endif