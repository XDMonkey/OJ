// leetcode31.cpp : �������̨Ӧ�ó������ڵ㡣
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
					if ((minBigger_i->second) != 0) {//����ҵ���һ������һ���϶���ʾ���������ڵ�����
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
				//������Ҫ��ȫ���ĵ�ת������ͬʱ����map����
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

