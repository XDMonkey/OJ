// leetcode84.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		int **p = new int *[heights.size()];
		int *min = new int[heights.size()];
		for (int i = 0; i < heights.size(); i++) {
			p[i] = new int[heights.size()];
			min[i] = 0;
		}
		for (int i = 0; i < heights.size(); i++) {
			p[0][i] = heights[i];
			if (p[0][i] > min[0])
				min[0] = p[0][i];
		}
		for (int i = 1; i < heights.size(); i++) { //表示的是长度的差
			for (int j = 0; j <= heights.size() - 1 - i; j++) { //表示的是起点
				p[i][j] = p[i - 1][j];
				if (heights[j + i] < p[i - 1][j]) {
					p[i][j] = heights[j + i];
				}
				if (p[i][j] > min[i])
					min[i] = p[i][j];
			}
		}
		int max = 0;
		for (int i = 0; i < heights.size(); i++) {
			if (max < min[i] * (i + 1))
				max = min[i] * (i + 1);
		}
		return max;
	}
};

int main()
{
	Solution a;
	vector<int> c{ 0 };
	cout << a.largestRectangleArea(c);
	return 0;
}

