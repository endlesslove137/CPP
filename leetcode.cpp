#include <vector>
#include <iostream>
#include <hash_map>
#include "common.h"
#include <string.h>

using namespace std;



////////////twoSum////////////
	// int a[]={3,2,4}; 
	// vector<int> vi(a,a+ArrayNum(a));
	// vector<int> vtemp =twoSum(vi,6);
	// PrintVector(vtemp);
	// vtemp = twoSum2(vi,5);
	// PrintVector(vtemp);
vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> temp;
		for(int i1=0;i1<nums.size();i1++){
			if (!temp.empty()) break;
			for(int i2=i1+1;i2<nums.size();i2++){

				// cout<<nums.at(i1)<<";";
				if(nums.at(i1) + nums.at(i2) == target){
					temp.push_back(i1);
					temp.push_back(i2);
					break;
				};
			}	
		};		
		return temp;		
};


vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> temp;
		hash_map<int,int> hM;
		hash_map<int,int>::iterator it_HM;
		for(int i1=0;i1<nums.size();i1++){
			int iT = target - nums.at(i1);
			it_HM = hM.find(iT);
			if (it_HM != hM.end()){
				temp.push_back(it_HM->second);
				temp.push_back(i1);
			}
			else{
				hM.insert(make_pair(nums.at(i1), i1));
			}	
		};		
		return temp;		
};

////////////addTwoNumbers////////////
///	int a[]={2,4,3},b[]={5,6,4};
// ListNode* ll1 = CreateList(a,ArrayNum(a));
// ListNode* ll2 = CreateList(b,ArrayNum(b));
// ListNode* l3 = addTwoNumbers(ll1,ll2);
// PrintList(ll1);
// PrintList(ll2);
// PrintList(l3);
// 
// 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode l3(0); 
		ListNode *preNode = &l3;
		int addNumber = 0;
		ListNode *b1 = l1, *b2 = l2;
		while(b1!=NULL || b2!=NULL || addNumber>0)//当l1和l2不为空或者addNumber>0任意一个条件成立
		{
			ListNode *node = new ListNode(0);//临时的结构体指针
			int val1 = b1 ? b1->val : 0;//如果b1不为空，val1=b1->val,否则为空
			int val2 = b2 ? b2->val : 0;//如果b2不为空，val2=b2->val,否则为空
			b1 = b1 ? b1->next : NULL;//如果b1不为空，b1指向下一个链表节点,否则为空
			b2 = b2 ? b2->next: NULL;//如果b1不为空，b1指向下一个链表节点,否则为空
			node->val = (val1 + val2 + addNumber) % 10; //余数
			addNumber = (val1 + val2 + addNumber) / 10;	//整数
			preNode->next = node;
			preNode = node;
		}
		return l3.next;
};

// 给定一个字符串，找出不含有重复字符的最长子串的长度。
// 例如，在”abcabcbb”中，其无重复字符的最长子字符串是”abc”，其长度为 3。
// 对于，”bbbbb”，其无重复字符的最长子字符串为”b”，长度为1
int lengthOfLongestSubstring(string s) {
	int result = 0;
	if(s.length()>0){
		int aLength = s.length() + 1;
		char* pCT = new char[aLength];
		char* pT = pCT; 
		char* pCM = new char[257];
		strcpy(pCT,s.c_str());
		int iMax=aLength;
		while(iMax >1){
			iMax = 0;
			while(*pT){
				pCM[*pT] += 1; 
				iMax = pCM[*pT]>iMax ? pCM[*pT] : iMax;
				pT++;
			}
			if (iMax > 1){
				*(pCT+(aLength-iMax)) = '0';
				aLength = sizeof(pCT);
			}else{
				result = sizeof(pCT);
			}
			pT = pCT;
		}

		delete[] pCT;
		delete[] pCM;
	}
    return result;
}

int main()   
{   
	string s("zmm is godd");
	printf("%d\n",lengthOfLongestSubstring(s));

	return 0;
};



