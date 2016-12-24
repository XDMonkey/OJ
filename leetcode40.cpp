// leetcode40.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	vector<int> ans;
	map<int, int> xx;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		for (int i = 0; i < candidates.size(); i++)
			xx[candidates[i]]++;
		getTheAns(0, target, xx.begin(), xx);
		return res;
	}
	void getTheAns(int sum, int target, map<int, int>::iterator index, map<int, int> &xx) {
		if (sum == target)
			res.emplace_back(ans);
		else if (sum > target)
			return;
		else {
			for (auto i = index; i != xx.end(); i++) {
				for (int j = 1; j <= i->second; j++) {
					for (int k = 1; k <= j; k++)
						ans.emplace_back(i->first);
					auto	m = i;
					getTheAns(sum + j*i->first, target, ++m, xx);
					for (int k = 1; k <= j; k++)
						ans.pop_back();
				}
			}
		}
	}
};
int main()
{
	vector<int> a{ 3,1,3,5,1,1 };
	Solution c;
	c.combinationSum2(a, 8);
	return 0;
}

