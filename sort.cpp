#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <sys/types.h>
#include "vector"
#include <windows.h>
// #include <unistd.h>
using namespace std;
#define ArrNum(x) sizeof(x)/sizeof(x[0])

#define MAX 255
void Qsort(int a[], int iLow, int iHigh){
	if(iLow < iHigh){
		int key = a[iLow];
		int iStart = iLow;
		int iEnd = iHigh;
		while(iStart < iEnd){
			while(iEnd > iStart && a[iEnd] > key)
				iEnd--;
			if(iStart < iEnd){
				// a[iStart] = a[iEnd];
				// iStart++;
				a[iStart++] = a[iEnd];
			}
			while(iStart < iEnd && a[iStart] < key)
				iStart++;
			if(iStart < iEnd){
				// a[iEnd] = a[iStart];
				// iEnd --;
				a[iEnd--] = a[iStart];
			}
		}
		a[iStart] = key;
		Qsort(a, iLow, iStart-1);
		Qsort(a, iStart+1, iHigh);
	}
}

void BobbleSort(int a[],int Sum){
	// printf("BobbleSort Sum=%d\n",Sum);
	for(int i=0;i < Sum; i++){
		for(int y=0; y<Sum-i-1; y++){
			if (a[y] > a[y+1]){
				int iT = a[y];
				a[y] = a[y+1];
				a[y + 1] = iT; 
			}
		}
	}
}

void SelectSort(int a[],int Sum){
	int minIndex,iT;
	for(int i=0; i<Sum; i++){
		minIndex = i;
		for(int j=i+1; j<Sum; j++){
			if (a[j] < a[minIndex]){
				minIndex = j;
			};
		};
		iT = a[i];
		a[i] = a[minIndex];
		a[minIndex] = iT;
	}
}

void InsertSort(int a[], int Length){
	for(int i=1; i<Length; i++){
		int tIndex = i -1;
		int tValue = a[i];
		while(tIndex >=0 && a[tIndex] < tValue){
			a[tIndex + 1] = a[tIndex];
			tIndex--;
		};
		a[++tIndex] = tValue;
	};
};

void ShellSort(int a[],int Length){
	for(int iGap=Length>>1; iGap>0; iGap >>= 1){
		for(int j=iGap; j<Length; j+=iGap){
			int iIndex = j - iGap;
			int iValue = a[j];
			while(iIndex >=0 && a[iIndex]<iValue){
				a[iIndex + iGap] = a[iIndex];
				iIndex -= iGap;
			};
			a[iIndex + iGap] = iValue;
		};
	};
};

void MergeArray(int a[],int iStart,int iMid,int iEnd, int c[]){
	int i,j,iE,jE,iC;
	i = iStart;
	iE = iMid;
	j = iMid + 1;
	jE = iEnd;
	iC = 0;
	while(i <= iE && j <= jE){
		if(a[i] > a[j])
			c[iC++] = a[i++];
		else
			c[iC++] = a[j++];
	}

	while(i <= iE)
		c[iC++] = a[i++];
	while(j <= jE)
		c[iC++] = a[j++];
	for(i=0; i< iC; i++)
		a[iStart + i] = c[i];
}

void _MergeSort(int a[],int iStart,int iEnd,int b[]){
	if (iStart < iEnd){
		int iMid = (iStart + iEnd) >> 1;
		_MergeSort(a, iStart, iMid, b);
		_MergeSort(a, iMid + 1, iEnd, b);
		MergeArray(a, iStart, iMid, iEnd, b);
	}
}

bool MergeSort(int a[],int Length){
	int *b = new int[Length];
	if(b == NULL) return false;
	_MergeSort(a,0,Length,b);
	delete[] b;
	return true;
}

void QuickSort(int a[],int iStart,int iEnd){
	// printf("Start iStart:%d,iEnd:%d\n",iStart,iEnd);
	if (iEnd <= iStart) return;
	int key = a[iStart];
	int iS = iStart;
	int iE = iEnd;
	printf("Start key:%d,iS:%d,iE:%d\n",key,iS,iE);
	while (iS < iE){
		while(iE > iS && a[iE]>key)
			--iE;
		a[iS] = a[iE];
		while(iE > iS && a[iS]<key)
			++iS;
		a[iE] = a[iS];
	}
	a[iS] = key;
	// printf("End key:%d,iS:%d,iE:%d\n",key,iS,iE);
	QuickSort(a, iStart, iS-1);
	QuickSort(a, iS+1, iEnd);
}

////////////Heap////////////
void Swap(int a[],int i,int j){
	a[i] = a[i] ^ a[j];
	a[j] = a[i] ^ a[j];
	a[i] = a[i] ^ a[j];
}

void ReviceNode(int a[], int i, int length){
	int iLeft = (i << 1) + 1;
	int iRight = (i << 1) + 2;
	int iMax = i;
	if(iLeft <= length && a[iLeft] > a[iMax]) iMax = iLeft;
	if(iRight <= length && a[iRight] > a[iMax]) iMax = iRight;
	if(iMax != i){
		Swap(a, iMax, i);
	}
}

void BuildMaxHeap(int a[], int length){
	int lastTNode = length >> 1;
	while(lastTNode >= 0){
		ReviceNode(a, lastTNode--, length);
	}
}

void HeapSort(int a[], int length){
	for(int i=length; i>=1; i--){
		BuildMaxHeap(a, i);
		Swap(a, 0, i);	
	}
};

////////////Count////////////
void CountSort(int a[],int length,int iMax){
	int* p = (int*)calloc(iMax+1,sizeof(int));
	for(int i=0;i<length;i++)
		p[a[i]]++;

	int iT = 0;
	for(int i=0;i<iMax+1;i++)
		//cout << p[i] << " ";
		while(p[i]-- > 0)
			a[iT++]=i;

	delete p;
}
////////////Buket////////////
int BucketNum = 10;
struct BucketNode{
	BucketNode(int i=0):value(i),Next(NULL){}
	int value;
	BucketNode* Next;	
};

void BucketSort(int a[],int length){
	BucketNode* PBucketArray = new BucketNode[10];
	for(int i=0;i<length;i++){
		int index = a[i] % BucketNum;
		if (PBucketArray[index].value==0) 
			PBucketArray[index] = BucketNode(a[i]);
		else{
			BucketNode* PBucketNode = new BucketNode(a[i]);
			BucketNode* PBucketNode1 = PBucketArray[index].Next;
			while(PBucketNode1 && PBucketNode1->Next)
				PBucketNode1 = PBucketNode1->Next;
			if(PBucketNode1)
				PBucketNode1->Next = PBucketNode;
			else
				PBucketArray[index].Next = PBucketNode;
		}
	};

	for(int j=0; j<BucketNum; j++){
		BucketNode* pBucketNode= PBucketArray[j].Next;
		while(pBucketNode){
			PBucketArray[j].Next = pBucketNode->Next;
			cout << pBucketNode->value << ",";
			delete pBucketNode;
			pBucketNode = PBucketArray[j].Next;
		}
		cout << PBucketArray[j].value << ",";

		cout << ";\n";
	}
		 

	delete[] PBucketArray;
};



void PrintArray(int a[],int length){
	cout << "\n";
    for(int i = 0; i < length; i++)
        cout << "i:"<<i<<",value:"<<a[i] << ";";
    cout << "\n";
};
////////////List////////////
void PrintList(BucketNode* Head){
	BucketNode* pHead = Head;
	while( pHead){
		cout<< pHead->value <<",";
		pHead = pHead->Next;
	};
	cout << ";\n";
};

void FreeList(BucketNode* Head){
	BucketNode* pHead = Head;
	while(pHead && pHead ->Next){
		BucketNode* pNode = pHead ->Next;
		pHead ->Next = pNode ->Next;
		delete pNode;
	}
	if(pHead) delete pHead;
}

BucketNode* ReverseList(BucketNode* Head){
	if(!Head) return Head;
	BucketNode* pHead = Head;
	BucketNode* pNode = pHead->Next;
	pHead->Next = NULL;
	while(pNode){
		BucketNode* pTNode = pNode->Next;
		pNode ->Next = pHead;
		pHead = pNode;
		pNode = pTNode;
	};
	return pHead;
}
// *************find*************
int BinSearch(int a[],int iLength,int Value){
	int iLow=0;
	int iHigh=iLength-1;
	int iMid;
	int iCount = 0;
	while(iLow <= iHigh){
		iCount++;
		iMid = (iLow + iHigh)>>1;
		printf("iMid=%d,iCount:%d,iLow:%d,iHigh:%d\n",iMid,iCount,iLow,iHigh);
		Sleep(1000);
		if (a[iMid] == Value)
			return iMid;
		else if(a[iMid] > Value)
			iHigh = iMid -1;
		else
			iLow = iMid +1;

	}
	return -1;
}


int main(void){
    // int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    // Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    int b[] = {57, 68, 59, 52, 72, 28, 96, 33, 24, 18, 238};
    BobbleSort(b,ArrNum(b));
    // SelectSort(b,ArrNum(b));
    // InsertSort(b, ArrNum(b));
    // ShellSort(b, ArrNum(b));
    // MergeSort(b, ArrNum(b)-1);
    // QuickSort(b, 0, ArrNum(b)-1);
    // HeapSort(b, ArrNum(b)-1);
    // CountSort(b, ArrNum(b), 100);
    // BucketSort(b, ArrNum(b));
    // PrintArray(b, ArrNum(b));
    // 基排
    // BucketNode* PBucketNode = new BucketNode(0);
    // BucketNode* PBucketNode1 = PBucketNode;
    // for(int i=1; i<BucketNum; i++){
    // 	BucketNode* TPBucketNode = new BucketNode(i);
    // 	PBucketNode1 ->Next = TPBucketNode;
    // 	PBucketNode1 = TPBucketNode;
    // }
    // PrintList(PBucketNode);
    // PBucketNode = ReverseList(PBucketNode);
    // PrintList(PBucketNode);
    // FreeList(PBucketNode);
    PrintArray(b,ArrNum(b));
    int iTemp = 100;
    printf("BinSearch Value:%d,Index:%d",iTemp,BinSearch(b,ArrNum(b),iTemp));
    return 0;
}