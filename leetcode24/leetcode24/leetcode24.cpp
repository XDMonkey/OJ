// leetcode24.cpp : �������̨Ӧ�ó������ڵ㡣
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
	if (nextTwoNode) {//����¸����еĵ�һ��������
		if (nextTwoNode->next) {//����¸����еĵڶ����ڵ�Ҳ����
			point->next->next = point;
			point->next = nextTwoNode->next;
			modifyTheNode(nextTwoNode);
		}
   		else {//����¸����еĵڶ����ڵ㲻����
			point->next->next = point;
			point->next = nextTwoNode;
		}
	}
	else {
		point->next->next = point;//��һ��д�˾ͳ�ʱ
		point->next = NULL;//����ǳ���Ҫ��Ҫ�����γɻ���		
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

