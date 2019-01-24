#include <iostream>
#include <stdio.h>

using namespace std;
#define ArrayNum(a) sizeof(a)/sizeof(a[0])
#define SwapValue(A,a,b) A[a] = A[a] ^ A[b]; A[b] = A[a] ^ A[b]; A[a] = A[a] ^ A[b];
#define SwapIValue(A,a,b) int si=A[a]; A[a]=A[b]; A[b]=si;
static int ALength;

template<typename T>
void SwapByType(T A[],int x,int y){
	T iT=A[x];
	A[x] = A[y];
	A[y] = iT;
};

void PrintArray(int A[],int Length){
	cout <<"\n";
	for(int i=0;i<Length;i++){
		cout << A[i] <<",";
	}
	cout <<"\n";
}

void PrintArray(int A[],int Start,int End){
	cout <<"\n";
	for(int i=Start;i<=End;i++){
		cout << A[i] <<",";
	}
	cout <<"\n";
}

void Swap(int A[],int a,int b,bool asc=true){
	if (a !=b){
		if(asc && A[a]>A[b]){
			SwapValue(A,a,b);
		}else if(!asc && A[a]<A[b]){
			SwapValue(A,a,b);
		};
	}
}

void BobbleSort(int a[],int Length){
	for(int i=0;i<Length;i++){
		for(int j=0;j<Length-i-1;j++){
			Swap(a,j,j+1);
		}
	}
}


void QuickSort(int A[],int Start,int End){
	static int Length = End - Start + 1;
	if(Start < End){
		int iS = Start;
		int iE = End;
		int key = A[iS];
		while(iS < iE){
			while(iS < iE && A[iE] >= key)
				iE--;
			A[iS] = A[iE];
			while(iS < iE && A[iS] < key)
				iS++;
			A[iE] = A[iS];
		}
		A[iS] = key;
		// PrintArray(A,Length);
		QuickSort(A, Start, iS-1);
		QuickSort(A, iS+1, End);
	}else return;
};

void SelectSort(int A[],int Length){
	int MinIndex;
	for(int i=0;i<Length-1;i++){
		MinIndex = i;
		for(int j=i+1;j<Length;j++){
			if (A[j] < A[MinIndex]){
				MinIndex = j;
			};
		};
		Swap(A,i,MinIndex);
	}
}

void InsertSort(int A[],int Length){
	for(int i=1;i<Length;i++){
		int Perindex = i-1;
		int key = A[i];
		while(Perindex>=0 && A[Perindex]>key){
			A[Perindex+1] = A[Perindex];
			Perindex--;
		};
		A[Perindex+1] = key;
	};
}

void MergeArray(int A[],int Start,int Mid,int End,int B[]){
	// printf("Start=%d,Mid=%d,End=%d",Start,Mid,End);
	int iS1 = Start;
	int iE1 = Mid;
	int iS2 = Mid + 1;	
	int iE2 = End;
	int iCount = 0;
	while(iS1<=iE1 && iS2<=iE2){
		if(A[iS1]<A[iS2])
			B[iCount++]=A[iS1++];
		else
			B[iCount++]=A[iS2++];
	}
	while(iS1<=iE1) B[iCount++]=A[iS1++];
	while(iS2<=iE2) B[iCount++]=A[iS2++];
	for(int i=0;i<iCount;i++){
		A[Start++]=B[i];
	};
}

void __MergeSort(int A[],int Start,int End,int B[]){
	if(Start < End){
		int iMid = (Start + End)>>1;
		__MergeSort(A,Start,iMid,B);
		__MergeSort(A,iMid+1,End,B);
		MergeArray(A,Start,iMid,End,B);
		// PrintArray(A,Start,End);
	};
}

void MergeSort(int A[],int Length){
	int* B= new int[Length];
	__MergeSort(A,0,Length-1,B);
	delete[] B;
}

void ShellSort(int A[],int Length){
	int iGap = Length>>1;
	while(iGap){
		printf("iGap:%d\n",iGap);
		for(int i=iGap;i<Length;i+=iGap){
			int Perindex = i - iGap;
			int key = A[i];
			while(Perindex>=0 && A[Perindex]>key){
				A[Perindex+iGap]=A[Perindex];
				Perindex-=iGap;
			};
			A[Perindex+iGap] = key;
		}
		iGap = iGap >> 1;
		PrintArray(A,ALength);
	};
}


void CountSort(int A[],int Length){
	int tSize = sizeof(int)*Length;
	int* aTemp = (int*)malloc(tSize);
	int iLength = Length;
	memset(aTemp,-1,tSize);
	for(int i=0;i<Length;i++){
		int iT = A[i];
		printf("iT:%d aTemp:%d\n",iT,aTemp);
		if (iT > iLength){
			int nSize = (iT+1)*sizeof(int);
			int* p1 = (int*)realloc(aTemp,nSize);
			if(p1){
				aTemp = p1;
				memset(aTemp + tSize/sizeof(int),-1,nSize-tSize);
				tSize = nSize;
				iLength = iT+1;
			}
		}
		if (aTemp[iT]==-1) aTemp[iT]=1;
		else aTemp[iT]+=1;
	}
	int iTemp = 0;
	for(int i=0;i<tSize/sizeof(int);i++){
		if (aTemp[i] != -1)
			while(aTemp[i]--)
				A[iTemp++] = i;
	}
	free(aTemp);
}

// *************HeapSort*************
// 以0为起点 Length为数组长度 最后一个非叶结点Length/2-1
void RePaireNode(int A[],int Index,int MaxIndex){
	int Left = (Index<<1)+1;
	int Right = Left + 1;
	int Max = Index;
	if(Left<=MaxIndex && A[Left]>A[Max]) Max=Left;
	if(Right<=MaxIndex && A[Right]>A[Max]) Max=Right;
	printf("RePaireNode Index:%d,MaxIndex=%d",Index,MaxIndex);
	PrintArray(A,MaxIndex+1);
	// SwapIValue(A,Index,Max);
	SwapByType<int>(A,Index,Max);
}

void BuildHeap(int A[],int Length){
	int LTNode = (Length>>1)-1;
	printf("BuildHeap LTNode:%d\n",LTNode);
	while(LTNode>=0){
		RePaireNode(A,LTNode--,Length-1);
	};
	PrintArray(A,Length);
}

void HeapSort(int A[],int Length){
	for(int i=Length-1;i>=1;i--){
		BuildHeap(A,i+1);
		// SwapIValue(A,0,i);
		SwapByType<int>(A,0,i);
	};
}




// char a1[5];
// char a2[5]="zmm";
// StrCopy(a1,a2);
// printf("%s\n",a1);
char* StrCopy(char* Dest,char* Src){
	if (!(Dest && Src)) return NULL;
	char* Result = Dest;
	while((*Dest++ = *Src++) != '\0');
	return Result;
}

char* StrCpy1(char* Dest, char* Src){
	if (!(Dest && Src)) return NULL;
	char* Result = Dest;
	while((*Dest++ = *Src) != '\0');
	return Result;
}

template <typename T>
T Add(T x,T y){
	return  x+y;
}

int (*IAdd)(int a,int b);

void test(int* a, int* b){
	*a = *b * *a;
	a = new int(3);
}

struct STest{
	int id;
} s2;




int main(){
	// int A[] = {34,45,12,35,38,34,9,1};
	// int A[] = {3,2,1,0};
	// printf("Ori Arry:");
	// PrintArray(A,ArrayNum(A));
	// ALength = ArrayNum(A);
	// BobbleSort(A,ArrayNum(A));
	// QuickSort(A,0,ArrayNum(A)-1);
	// SelectSort(A,ArrayNum(A));
	// MergeSort(A,ArrayNum(A));
	// InsertSort(A,ArrayNum(A));
	// ShellSort(A,ArrayNum(A));
	// CountSort(A,ArrayNum(A));
	// HeapSort(A,ArrayNum(A));
	// printf("After Sort:");
	// PrintArray(A,ArrayNum(A));
	// enum aa{a=5,b,c} bb;
	// bb = (enum aa)5;

	// IAdd = Add;
	// printf("%d",IAdd(3,4));
	char c1[4] = "abc",*p;
	p = "dcb";


	return 0;
}


