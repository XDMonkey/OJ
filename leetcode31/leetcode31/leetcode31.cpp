// leetcode31.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		map<int,int> minBigger;

		for (int i = 0; i < 10; i++)
			minBigger[i] = 0;
		auto minBigger_i = minBigger.begin();
		int length = nums.size();
		int temp = 0;
		if (length > 1) {
			int a = length-1;
			while (a>-1) {
				int j = nums[a] + 1;
				while (j < 10) {
					minBigger_i = minBigger.begin();
					advance(minBigger_i, j);
					if ((minBigger_i->second) != 0) {//如果找到了一个，第一个肯定表示的是其所在的行数
						minBigger_i->second--;
						
						minBigger[nums[a]]++;
						nums[a] = minBigger_i->first;
						int a_i = a + 1;
						auto minBigger_i2 = minBigger.begin();
						while (a_i<length) {
							if (minBigger_i2->second > 0) {
								nums[a_i] = minBigger_i2->first;
								minBigger_i2->second--;
								a_i++;
							}
							else
								minBigger_i2++;
						}
						return;
					}
					j++;
				}
				//在这里要将全部的倒转过来，同时更新map数组
				minBigger_i = minBigger.begin();
				advance(minBigger_i, nums[a]);
				minBigger_i->second++;
				a--;
			}

		}
		reverse(nums.begin(), nums.end());
		return;
	}
};
int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	Solution c;
	c.nextPermutation(a);
    return 0;
}

