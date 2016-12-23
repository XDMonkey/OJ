// leetcode39.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> ans;
		vector<vector<int>> res;
		DFS(0, 0, target, candidates, ans, res);
		return res;
	}

	void DFS(int start, int sum, int target, vector<int> &candidates, vector<int> &ans, vector<vector<int>> &res) {
		if (sum == target)
			res.push_back(ans);
		else if (sum > target)
			return;
		else {
			for (int i = start; i < candidates.size(); i++) {
				ans.push_back(candidates[i]);
				DFS(i, candidates[i] + sum, target, candidates, ans, res);
				ans.pop_back();
			}
		}
	}
};
int main()
{
	Solution a;
	vector<int> b{ 2,3,6,7 };
	a.combinationSum(b, 7);
	return 0;
}

