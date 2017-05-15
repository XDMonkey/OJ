// leetcode104.cpp : 定义控制台应用程序的入口点。
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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int a = maxDepth(root->left);
		int b = maxDepth(root->right);
		return a > b ? a + 1 : b + 1;
	}
};

int main()
{
    return 0;
}

