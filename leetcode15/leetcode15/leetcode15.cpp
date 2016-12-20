// leetcode15.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>&nums)
	{
		vector<vector<int>> res;
		vector<int> threeNums(3);
		int counter = 0;
		auto numsBegin = nums.begin();
		auto numsSecond = nums.begin();
		auto numsThird = nums.begin();
		sort(nums.begin(), nums.end());
		while (numsBegin + 2 != nums.end()) {
			numsSecond = numsBegin + 1;
			numsThird = nums.end() - 1;
			while (numsSecond != numsThird) {
				if (*numsSecond + *numsThird + *numsBegin > 0) {
					numsThird--;

				}
				else if (*numsSecond + *numsThird + *numsBegin < 0) {
					numsSecond++;

				}
				else {
					threeNums[0] = *numsBegin;
					threeNums[1] = *numsSecond;
					threeNums[2] = *numsThird;
					res.push_back(threeNums);
					numsSecond++;
				}
				while (numsSecond != numsThird&&*(numsThird - 1) == *numsThird)
					numsThird--;
			while (numsSecond != numsThird&&*(numsSecond + 1) == *numsSecond)
					numsSecond++;
			}
			
			
			while (numsBegin + 2 != nums.end()&& *(numsBegin + 1) == *numsBegin)			
					numsBegin++;
			numsBegin++;
		}
		return res;
	}
};

int main()
{
	Solution a;
	vector<int> b{ -1,0,1,2,-1,-4 };
	//cout << b[0] << endl;
	for (int i = 0; i < a.threeSum(b).size(); i++)
		for (int j = 0; j < 3; j++) {
			cout << a.threeSum(b)[i][j] << " ";
			cout << endl;
		}
	return 0;
}

