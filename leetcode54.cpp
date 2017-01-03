// leetcode54.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int height = matrix.size();
		if (!height)
			return res;
		int width = matrix[0].size();
		if (!width)
			return res;
		int direction = -1;

		if (height == 1) {
			for (int i = 0; i < width; i++)
				res.emplace_back(matrix[0][i]);
			return res;
		}
		if (width == 1) {
			for (int i = 0; i < height; i++)
				res.emplace_back(matrix[i][0]);
			return res;
		}
		else {
			for (int i = 0; i < width; i++)
				res.emplace_back(matrix[0][i]);
			for (int i = 1; i < height; i++)
				res.emplace_back(matrix[i][width - 1]);
			int m = height - 2;
			int n = width - 1;
			height = height - 1;
			width = width - 1;
			while (height || width) {
				direction++;
				switch (direction % 4) {
				case 0: {
					if (!width)
						return res;
					for (int i = 0; i < width; i++)
						res.emplace_back(matrix[m][--n]);
					width--;
					break;
				}
				case 1: {
					if (!height)
						return res;
					for (int i = 0; i < height; i++)
						res.emplace_back(matrix[--m][n]);
					height--;
					break;
				}
				case 2: {
					if (!width)
						return res;
					for (int i = 0; i < width; i++)
						res.emplace_back(matrix[m][++n]);
					width--;
					break;
				}
				case 3: {
					if (!height)
						return res;
					for (int i = 0; i < height; i++)
						res.emplace_back(matrix[++m][n]);
					height--;
					break;
				}
				}
			}
		}
		return res;
	}
};

int main()
{
	vector<vector<int>> a;
	vector<int> a1{ 1,2 };
	vector<int> a2{ 3,4 };
	a.emplace_back(a1);
	a.emplace_back(a2);
	Solution c;
	c.spiralOrder(a);
	return 0;
}

