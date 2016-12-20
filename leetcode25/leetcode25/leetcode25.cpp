// leetcode25.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {};
};
void recursion(ListNode *head, int k, int i) {
	while (i != k - 1) 
		recursion(head->next, k, ++i);
	head->next->next = head;
}
void reverse(ListNode *head, int k) {
	ListNode *nextLastNode = head;
	ListNode *beforeTemp;
	for (int i = 1; i <= k; i++)
		nextLastNode = nextLastNode->next;//到下个序列的第一个
	ListNode *nextFirstNode = nextLastNode;
	ListNode *temp = NULL;
	for (int i = 1; i <= k; i++) {
		if (!nextFirstNode) {
			recursion(head, k, 1);
			head->next = nextLastNode;//破环
			return;//下一个是不齐的，修改到上一个就可以了
		}
		temp = nextFirstNode;
		nextFirstNode = nextFirstNode->next;
	}
	recursion(head, k, 1);//将它们全部逆序
	head->next = temp;
	reverse(nextLastNode, k);		//递归调用函数
}
class Solution {
public:
	ListNode* reverseKGroup(ListNode *head, int k) {
		ListNode *temp = head;
		ListNode *temp2 = NULL;
		int flag = 1;//用来标识首轮的长度是否够K
		for (int i = 1; i <= k; i++) {
			if (!temp) {
				flag = 0;
				break;
			}
			if (i == k)
				temp2 = temp;
			else
			temp = temp->next;
		}
		if (k == 1 || !flag)
			return head;
		else {
			reverse(head, k);
			return temp2;
		}
	}
};
int main()
{
	ListNode a(1);
	ListNode b(2);
	//ListNode c(5);
	//ListNode d(6);
	ListNode *pa = &a;
	ListNode *pb = &b;
//	ListNode *pc = &c;
//	ListNode *pd = &d;
	pa->next = pb;
	//pb->next = pc;
	//pc->next = pd;
	Solution f;
	f.reverseKGroup(pa, 3);
	return 0;
}

