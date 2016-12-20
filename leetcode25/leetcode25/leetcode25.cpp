// leetcode25.cpp : �������̨Ӧ�ó������ڵ㡣
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
		nextLastNode = nextLastNode->next;//���¸����еĵ�һ��
	ListNode *nextFirstNode = nextLastNode;
	ListNode *temp = NULL;
	for (int i = 1; i <= k; i++) {
		if (!nextFirstNode) {
			recursion(head, k, 1);
			head->next = nextLastNode;//�ƻ�
			return;//��һ���ǲ���ģ��޸ĵ���һ���Ϳ�����
		}
		temp = nextFirstNode;
		nextFirstNode = nextFirstNode->next;
	}
	recursion(head, k, 1);//������ȫ������
	head->next = temp;
	reverse(nextLastNode, k);		//�ݹ���ú���
}
class Solution {
public:
	ListNode* reverseKGroup(ListNode *head, int k) {
		ListNode *temp = head;
		ListNode *temp2 = NULL;
		int flag = 1;//������ʶ���ֵĳ����Ƿ�K
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

