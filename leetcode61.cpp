// leetcode61.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return head;
		ListNode* a = head;
		ListNode *tempA = NULL;
		int length = 0;
		while (a != NULL) {
			tempA = a;
			a = a->next;
			length++;

		}
		if (!(k%length))
			return head;
		else
			k = k%length;
		tempA->next = head;
		a = head;
		int lastOne = length - k;
		for (int i = 0; i < lastOne; i++) {
			tempA = a;
			a = a->next;
		}
		tempA->next = NULL;
		return a;
	}
};
int main()
{
	return 0;
}

