// leetcode23.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"vector"
using namespace std;
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
void sortTheHeap(vector<ListNode*>&heap, int m, int K) {
	if (m > K / 2)
		return;
	ListNode *temp = NULL;
	if (m * 2 == K) {
		if (heap[m - 1]->val > heap[m * 2 - 1]->val) {
			temp = heap[m * 2 - 1];
			heap[m * 2 - 1] = heap[m - 1];
			heap[m - 1] = temp;
		}//�����û���Ҷ��ӵ�����£�����ӱ��Լ�С
	}//���û���Ҷ���
	else {
		if (heap[2 * m - 1]->val < heap[2 * m]->val) {
			if (heap[m - 1]->val > heap[2 * m - 1]->val) {
				temp = heap[2 * m - 1];
				heap[2 * m - 1] = heap[m - 1];
				heap[m - 1] = temp;
				sortTheHeap(heap, 2 * m, K);
			}//�������ӱ��Ҷ���С�������,�Լ������������
		}//�������ӱ��Ҷ���С
		else if (heap[m - 1]->val > heap[2 * m]->val) {
			temp = heap[2 * m];
			heap[2 * m] = heap[m - 1];
			heap[m - 1] = temp;
			sortTheHeap(heap, 2 * m + 1, K);
		}//����Ҷ��ӱ������С������£��Լ������Ҷ���
	}
}
void buildTheHeap(vector<ListNode*>&heap, int K) {
	for (int i = K / 2; i > 0; i--)
		sortTheHeap(heap, i, K);
}
ListNode maxNode(2147483647);
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *point;//���յõ��Ľ���Ľ��
		int flag = 0;//������ʶ�Ƿ��н��û�н���
		int K = lists.size();
		vector<ListNode*> heap;//�����
		for (auto cur = lists.begin(); cur != lists.end(); cur++) {
			if (*cur) 
				heap.push_back(*cur);//����һ�ֵ�Ԫ�����η��ڻ������	
			else {
				heap.push_back(&maxNode);
				flag++;
			}
		}
		if (flag==K)
			return NULL;
		buildTheHeap(heap, K);
		point = heap[0];
		ListNode *cur = point;
		while (true) {
			if (heap[0]->next)
				heap[0] = heap[0]->next;
			else {
				heap[0] = &maxNode;
				flag++;
				if (flag == K)
					break;
			}
			sortTheHeap(heap, 1, K);
			cur->next = heap[0];
			cur = cur->next;
		}
		return point;
	}
};
int main()
{
	return 0;
}

