#include <vector>
#include <iostream>
#include <hash_map>
#include <string.h>
#include <set>
#include "common.h"
#include <algorithm>
#include <deque>
#include <string>

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

// lengthOfLongestSubstring
// 给定一个字符串，找出不含有重复字符的最长子串的长度。
// 例如，在”abcabcbb”中，其无重复字符的最长子字符串是”abc”，其长度为 3。
// 对于，”bbbbb”，其无重复字符的最长子字符串为”b”，长度为1
// 给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
// string s("abao");
// printf("%d\n",lengthOfLongestSubstring2(s));
// 暴力法
int lengthOfLongestSubstring(string s) {
	int result = 0;
	int sLen = s.length();
	if(sLen > 0){
		for (int i=0;i<sLen;i++)
			for(int j=i+1; j<=sLen; j++){
				bool BUnique = true;
				set<char> c_set;
				pair<set<char>::iterator, bool> ret;
				for(int iT=i; iT<j; iT++){
					ret = c_set.insert(s.at(iT));
					if (ret.second == false){
						BUnique = false;
						break;
					};
				};
				if (BUnique)
					result = max(result, j-i);					
			}	
	};
    return result;
}
//
int lengthOfLongestSubstring2(string s) {
	int result = 0;
	int sLen = s.length();
	if(sLen > 0){
		int i=0,j=0;
		deque<char> cDeque;
		set<char>::iterator iter;
		while(i<sLen && j<sLen){
			char c1 = s.at(j);
			if(find(cDeque.begin(),cDeque.end(),c1) == cDeque.end()){
				// printf("c1:%c j:%d insert \n",c1,j);
				cDeque.push_back(c1);
				j++;
				result = max(result, j-i);
			}
			else{
				if (!cDeque.empty()){
					char c2 = cDeque.front();
					cDeque.pop_front();
					// printf("c1:%c Repeat Remove:%c \n", c1, c2);
					i++;
				}
			}
		}
	};
    return result;
}


// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
// 请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
// 你可以假设 nums1 和 nums2 均不为空。
// 示例 1: nums1 = [1,3,5] nums2 = [2,4,6] 中位数是 (4 + 3)/2 = 3.5
// nums1中位数是3 nums2中位数是 4 3<4 那么nums1 nums2的中位数 位于num1的右侧 num2的左侧
// 示例 2: nums1 = [1,3,5] nums2 = [2, 4]中位数是 3
// nums1中位数是3 nums2中位数是 3 3=3 那么nums1 nums2的中位数为3
// int a[] = {1,3,5},b[]={2,4,6};
// vector<int> vA(a,a+ArrayNum(a)),vB(b,b+ArrayNum(b));
// printf("%f\n",findMedianSortedArrays(vA,vB));
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> vTemp;
	int i1=nums1.size(),i2=nums2.size(),iMid=0,i=-1;
	bool Bodd= (i1+i2)%2!=0;
	//奇数时 表示中位数下标位置 偶数时iMid iMid-1为下标位置(倒序合并)
	iMid = (i1+i2)/2;
	
	--i1;--i2;
	while(i1 >-1 && i2>-1){
		if (nums1.at(i1)<nums2.at(i2))
			vTemp.push_back(nums2.at(i2--));
		else
			vTemp.push_back(nums1.at(i1--));
		i++;
		if(i==iMid){
			if (Bodd)  return 1.0*vTemp.at(i);	
			else return 1.0*(vTemp.at(i-1) + vTemp.at(i))/2;
		};
	};
	while(i1 >-1){
 		vTemp.push_back(nums1.at(i1--));
		i++;
		if(i==iMid){
			if (Bodd)  return 1.0*vTemp.at(i);	
			else return 1.0*(vTemp.at(i-1) + vTemp.at(i))/2;
		};
	};
	while(i2 >-1){
		vTemp.push_back(nums2.at(i2--));		
		i++;
		if(i==iMid){
			if (Bodd)  return 1.0*vTemp.at(i);	
			else return 1.0*(vTemp.at(i-1) + vTemp.at(i))/2;
		};
	};
	return 0.0;
}


// 给定一个字符串s,找到s中最长的回文子串。你可以假设s的最大长度为1000。 子串的含义是：在原串中连续出现的字符串片段。回文的含义是：正着看和倒着看相同，如abba和yyxyy
// 示例 1： 输入: "babad" 输出: "bab" 注意: "aba"也是一个有效答案。
// 示例 2： 输入: "cbbd" 输出: "bb"
string longestPalindrome(string s)
{
    /*改造字符串*/
    string res="$#";
    for(int i=0;i<s.size();++i)
    {
        res+=s[i];
        res+="#";
    }

    /*数组*/
    vector<int> P(res.size(),0);
    int mi=0,right=0;   //mi为最大回文串对应的中心点，right为该回文串能达到的最右端的值
    int maxLen=0,maxPoint=0;    //maxLen为最大回文串的长度，maxPoint为记录中心点

    for(int i=1;i<res.size();++i)
    {
        P[i]=right>i ?min(P[2*mi-i],right-i):1;     //关键句，文中对这句以详细讲解
        
        while(res[i+P[i]]==res[i-P[i]])
            ++P[i];
        
        if(right<i+P[i])    //超过之前的最右端，则改变中心点和对应的最右端
        {
            right=i+P[i];
            mi=i;
        }

        if(maxLen<P[i])     //更新最大回文串的长度，并记下此时的点
        {
            maxLen=P[i];
            maxPoint=i;
        }
    }
    return s.substr((maxPoint-maxLen)/2,maxLen-1);
}


// 将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：长14/3 = 4..2 列数=4+(3*Row-2) 长12/3=4
// P   A   H   N 
// A P L S I I G
// Y   I   R
// 之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"
// 输入: s = "PAYPALISHIRING", numRows = 3
// 输出: "PAHNAPLSIIGYIR"
// 示例 2:

// 输入: s = "PAYPALISHIRING", numRows = 4 长14/4=3..2
// 输出: "PINALSIGYAHRPI"
// 解释:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
string convert(string s, int numRows) {
	unsigned int sLen = s.size();
	if (sLen <= numRows) return s;
	string* pS = new string[numRows];
	int i=0,j=0,ij=numRows-2;
	while(i<sLen){
		for(j=0; i<sLen && j<numRows; j++) {
			pS[j] += s[i++];
			// printf("pS[%d]:%s--s[%d]:%c;", j, pS[j].c_str(), i-1, s[i-1]);
		}
		for(j=ij; i<sLen && j>0; j--) {
			pS[j] += s[i++];
			// printf("pS[%d]:%s--s[%d]:%c;", j, pS[j].c_str(), i-1, s[i-1]);
		}
	}
	string result="";
	for(i=0;i<numRows;i++){
		result += pS[i];
		// printf("result:%s;pS[%d]:%s",result.c_str(), i, pS[i].c_str());
	}
	delete[] pS;
	return result;
}

// 给定一个 32 位有符号整数，将整数中的数字进行反转。
// 示例 1:输入: 123 输出: 321
// 示例 2:输入: -123 输出: -321
// 示例 3:输入: 120 输出: 21
// 注意:假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
int reverse(int x) {
	int result = x;
	if(x > 0){
		string s1 = to_string(x);
		std::reverse(s1.begin(), s1.end());
		long long lT = atoll(s1.c_str());
		result = lT > INT_MAX? 0:lT;
	}else if(x <0){
		if (x < INT_MIN) return 0;
		int xT = abs(x);
		string s1 = to_string(x);
		std::reverse(s1.begin(), s1.end());
		long long lT = -atoll(s1.c_str());
		result =  lT < INT_MIN? 0:lT;

	}else return x;
	return result;
}

// 实现 atoi，将字符串转为整数。
// 在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
// 字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。
// 当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
// 若函数不能执行有效的转换，返回 0。
// 说明：假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
// 示例 1: 输入: "42" 输出: 42
// 示例 2: 输入: "   -42" 输出: -42
// 	解释: 第一个非空白字符为 '-', 它是一个负号。 我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
// 示例 3: 输入: "4193 with words" 输出: 4193
// 	解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
// 示例 4: 输入: "words and 987" 输出: 0
// 	解释: 第一个非空字符是 'w', 但它不是数字或正、负号。因此无法执行有效的转换。
// 示例 5: 输入: "-91283472332" 输出: -2147483648
// 	解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 因此返回 INT_MIN (−231) 。

int myAtoi(string str) {
	int result = 0;
	int iCount = str.size();
	if(iCount>0){
		for(int i=0;i<iCount;i++){
			
		}
	}
	return result;
    
}


int main()   
{   
	printf("%d\n",reverse(-987654321));
	return 0;
};






