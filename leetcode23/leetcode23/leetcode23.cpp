// leetcode23.cpp : 定义控制台应用程序的入口点。
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
		}//如果在没有右儿子的情况下，左儿子比自己小
	}//如果没有右儿子
	else {
		if (heap[2 * m - 1]->val < heap[2 * m]->val) {
			if (heap[m - 1]->val > heap[2 * m - 1]->val) {
				temp = heap[2 * m - 1];
				heap[2 * m - 1] = heap[m - 1];
				heap[m - 1] = temp;
				sortTheHeap(heap, 2 * m, K);
			}//如果左儿子比右儿子小的情况下,自己大于于左儿子
		}//如果左儿子比右儿子小
		else if (heap[m - 1]->val > heap[2 * m]->val) {
			temp = heap[2 * m];
			heap[2 * m] = heap[m - 1];
			heap[m - 1] = temp;
			sortTheHeap(heap, 2 * m + 1, K);
		}//如果右儿子比左儿子小的情况下，自己大于右儿子
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
		ListNode *point;//最终得到的结果的结点
		int flag = 0;//用来标识是否还有结点没有结束
		int K = lists.size();
		vector<ListNode*> heap;//缓冲堆
		for (auto cur = lists.begin(); cur != lists.end(); cur++) {
			if (*cur) 
				heap.push_back(*cur);//将第一轮的元素依次放在缓冲堆上	
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

