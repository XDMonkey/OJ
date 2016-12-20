// leetcode24.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
void modifyTheNode(ListNode* point) {
	ListNode *nextTwoNode = point->next->next;
	ListNode *temp;
	if (nextTwoNode) {//如果下个序列的第一个结点存在
		if (nextTwoNode->next) {//如果下个序列的第二个节点也存在
			point->next->next = point;
			point->next = nextTwoNode->next;
			modifyTheNode(nextTwoNode);
		}
   		else {//如果下个序列的第二个节点不存在
			point->next->next = point;
			point->next = nextTwoNode;
		}
	}
	else {
		point->next->next = point;//这一句写了就超时
		point->next = NULL;//这个非常重要，要避免形成环形		
	}
}
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* temp;
		if (!head)
			return NULL;
		if (!head->next)
			return head;
		else {
			temp = head->next;
			modifyTheNode(head);
			return temp;
		}
	}
};

int main()
{
	Solution t;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode *pa = &a;
	ListNode *pb = &b;
	ListNode *pc = &c;
	ListNode *pd = &d;
	pa->next = pb;
	pb->next = pc;
	pc->next = pd;
	t.swapPairs(pa);
	return 0;
}

