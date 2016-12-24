// leetcode42.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	int sum=0;
	void divide(int start, int end, int flag, vector<int> &height) {
		if (end - start <= 1) {
			return;
		}
		int max = 0;
		int maxIndex = -1;
		if (flag == -1) {
			for (int a = end; a > -1; a--) {
				if (height[a] > max&&a != end) {
					max = height[a];
					maxIndex = a;
				}
			}
			if (!max)
				return;
			for (int a = maxIndex + 1; a < end; a++)
				sum += max - height[a];
			divide(start, maxIndex, -1, height);
		}
		else {
			for (int a = start; a < height.size(); a++) {
				if (height[a] > max&&a != start) {
					max = height[a];
					maxIndex = a;
				}
			}
			if (!max)
				return;
			for (int a = maxIndex - 1; a > start; a--)
				sum += max - height[a];
			divide(maxIndex, end, 1, height);
		}
	}
	int trap(vector<int>& height){
		int max = 0;
		int maxIndex = 0;
		for (int a = 0; a < height.size(); a++) {
			if (height[a] > max) {
				max = height[a];
				maxIndex = a;
			}
		}
		divide(0, maxIndex, -1, height);
		divide(maxIndex, height.size() - 1, 1, height);
		return sum;
	}
};
int main()
{
	vector<int> a{8,5,4,1,8,9,3,0,0 };
	Solution b;
	b.trap(a);
	return 0;
}

