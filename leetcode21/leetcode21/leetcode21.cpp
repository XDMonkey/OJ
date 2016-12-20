// leetcode21.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode() :val(0), next(NULL) {}//���캯��д�ĺܺ�
};//��������ṹ��
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode *l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* L1 = l1;
		ListNode* L2 = l2;
		ListNode* cur=new ListNode();
		ListNode* head = cur;
		while (L1&&L2) {
			if (L1->val < L2->val) {
				cur->next = L1;
				L1 = L1 -> next;
			}
			else {
				cur->next= L2;
				L2 = L2->next;
			}
			cur = cur->next;
		}
		if (!L1)
			cur->next = L2;
		else
			cur->next = L1;
		return head->next;
	}
};

int main()
{
	ListNode *p=new ListNode();
	p->val = 3;
	ListNode *q=new ListNode();
	q->val = 2;
	Solution a;
	ListNode *res=a.mergeTwoLists(p, q);
	while (res) {
		cout << res->val<<" ";
		res = res->next;
	}
	return 0;
}

