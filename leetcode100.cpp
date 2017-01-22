// leetcode100.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int flag = 1;
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p != NULL&&q != NULL) {
			if (p->val != q->val)
				return false;
			else {
				if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
					return true;
				return false;
			}
		}
		else if (!(p == NULL&&q == NULL))
			return false;
		else
			return true;
	}
};
int main()
{
	return 0;
}

