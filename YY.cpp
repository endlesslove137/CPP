//*********For YY*****************
#include <iostream>
#include <cassert>
#include <set>
#include <iterator>
#include "common.h"
#include <algorithm>
#include <stack>
#ifdef __cplusplus
// extern "C"{
#include <vector>
// }
#endif
#define Print(x) cout << x << endl


using namespace std;

void* MemMove(void* Des,void* Src,int Count){
	assert((Des !=NULL) && (Src !=NULL));
	char* TDes = (char*)Des;
	char* TSrc = (char*)Src;
	if(TDes >= TSrc){
		while(Count--) *TDes++ = *TSrc++;
	}
	else{
		TDes += Count - 1;
		TSrc += Count - 1;
		while(Count--) *TDes-- = *TSrc--;
	}	
	return Des;
}

void RemoveDuplicate(int* AR,int Count){
	assert(AR != NULL);
	set<int> tset;
	set<int>::iterator iter;
	while(Count--){
		cout<<"Count:"<<Count<<";";
		tset.insert(*(AR +Count));
	}
	int i=0;
	for(iter=tset.begin(); iter != tset.end(); iter++){
			cout<< *iter;
			AR[i++] = *iter;
	}


}


// 排序数组，奇数在前半部分，按升序排，偶数在后半部分，按降序排
int Compare(int& a, int& b){
	if(a%2==0){
		if(b%2==0)
			return a>b;
		else
			return 0;
	}
	else{
		if ((b%2)==0){
			return 1;
		}else{
			return a<b;
		}
	}
}

// *************HeapSort*************
template <class T>
void SwapArrValue(T a[], int i1,int i2){
	T iT = a[i1];
	a[i1] = a[i2];
	a[i2] = iT;
}

void BuildHeapNode(int a[], int LastNode, int MaxIndex){
	int Max = LastNode;
	int Left = (LastNode<<1) + 1;
	int Right = Left + 1;
	if(Left <= MaxIndex && a[Max] < a[Left]) Max = Left; 
	if(Right <= MaxIndex && a[Max] < a[Right]) Max = Right;
	SwapArrValue<int>(a,LastNode,Max);
}

void BuildHeap(int a[], int Count){
	int LastNode = (Count>>1) -1;
	while (LastNode >= 0){
		BuildHeapNode(a, LastNode--, Count-1);
	}
}

void HeapSort(int a[], int Count){
	for(int i=Count-1; i>=1; i--){
		BuildHeap(a, i+1);
		SwapArrValue<int>(a,0,i);
	}
}

// *************删除链表中的重复元素*************
void DeleteListNode(ListNode* LN){
	if (LN){
		ListNode* Temp = LN;
		ListNode* Pre;
		Pre->next = Temp->next;
		delete Temp;
	}
}

// *************插入结点*************
void InsertListNode(ListNode* LN,ListNode* PInsert){
	if(LN && PInsert){
		PInsert->next = LN->next;
		LN->next = PInsert;
	}
}

// *************反转单向链表*************
ListNode* ReverseList(ListNode* pHead){
	if(pHead && pHead->next){
		ListNode* pPer = pHead;
		ListNode* pCur = pHead->next;
		ListNode* pNext;
		while(pCur){
			pNext = pCur->next;
			pCur->next = pPer;
			pPer = pCur;
			pCur = pNext;
		}
		pHead->next = NULL;
		return pPer;

	}else
	return pHead;
}

// *************环形队列*************

// *************求子数组的最大和*************
int MaxSumInArray(int a[], int Count){
	int Result = -1; 
	int TResult=0;
	for(int i=0; i<Count-1; i++){
		if (TResult<=0){
			TResult = a[i];
		}else{
			TResult += a[i];
		};
		if (Result < TResult) Result = TResult;
	};
	return Result;
};

// *************判断是否链表是否有环*************
bool ListIsLoop(ListNode* Head){
	bool result = false;
	if(Head){
		ListNode* Fast = Head;
		ListNode* Slow = Head;
		while(Fast && Fast->next){
			Fast = Fast->next->next;
			Slow = Slow->next;
			if (Slow==Fast){
				result = true;
				break;
			}
		};		

	}
	return result;
}

// 遍历二叉树（非递归）实现*************2019年03月05日*************
// 前序
void PreTraverse(TreeNode* RootNode){
	if(RootNode){
		cout << RootNode->val;
		PreTraverse(RootNode->Left);
		PreTraverse(RootNode->Right);
	}
}
// 先序非递归
void ProTraverse(TreeNode* RootNode){
	stack<TreeNode*> tStack;
	TreeNode* p = RootNode;
	while(p || !tStack.empty()){
		while(p != NULL){
			cout << p->val;
			tStack.push(p);
			p = p->Left;
		};
		if(!tStack.empty()){
			p = tStack.top();
			tStack.pop();
			p = p->Right;
		};

	}
}

// *************二份查找*************
int Binary_Search(int a[],int iStart,int iEnd,int iValue){
	int Result = -1;
	if(a){
		while(iStart <= iEnd){
			int iMod = (iStart + iEnd) >> 1;
			if (a[iMod]==iValue){
				Result = iMod;
				cout << iValue <<" index is:" <<Result <<";\n";
				break;
			}else{
				if(a[iMod] > iValue)
					iEnd = iMod -1;
				else
					iStart = iMod + 1;
			};
		}
	}
	if(Result==-1) 
		cout << iValue <<" index is:-1;\n";

	return Result;
}

// *************Sort*************
void QuickSort(int a[],int iStart,int iEnd){
	if(a && iStart<iEnd){
		int iFlag = a[iStart];
		int iS1 = iStart;
		int iE1 = iEnd;
		while(iS1 < iE1){
			while(iS1 < iE1 && a[iE1] >= iFlag)
				iE1--;
			a[iS1] = a[iE1];
			while(iS1 < iE1 && a[iS1] < iFlag)
				iS1++;
			a[iE1] = a[iS1];
		}
		a[iE1] = iFlag;
		QuickSort(a,iStart,iE1-1);
		QuickSort(a,iE1+1,iEnd);

	}
}


// *************2019年03月05日*************
// 怎么判断两个链表是否相交？


const int ArrNum = 10;

int main(int agrc, char* argc[]){
	int a[ArrNum] = {1,2,2,1,3,2,3,10,4,5};
	// int b[ArrNum] = {1,2,3};
	// int a[ArrNum] = {3,2,1};
	// RemoveDuplicate(a, 10);
	// PrintArray(b,ArrNum);
	// vector<int> tVector(a,a+10); 
	// sort(tVector.begin(), tVector.end(), Compare);
	// PrintVector(tVector);
	// HeapSort(a, ArrNum);
	// Binary_Search(b,0,2,1);
	QuickSort(a, 0, ArrNum-1);
	PrintArray(a,ArrNum);


	// printf("%d:%d\n",i--,i);
	// printf("%d:%d\n",i,i--);

	return 0;	
}