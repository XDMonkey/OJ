// leetcode64.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
using namespace std;
class Solution {
public:
	int findMinSum(vector<vector<int>> &grid, int i, int j) {
		if (i+1&&j+1) {
			if ((!i) && (!j)) 
				return grid[0][0];
			else {
				int res = 0;
				if (!i) {
					for (int m = 0; m <= j; m++)
						res += grid[i][m];
					return res;
				}
				else if (!j) {
					res = 0;
					for (int m = 0; m <= i; m++)
						res += grid[m][j];
					return res;
				}
				else {
					if (findMinSum(grid, i - 1, j) > findMinSum(grid, i, j - 1)) 
						return findMinSum(grid, i, j - 1) + grid[i][j];
					else
						return findMinSum(grid, i - 1, j) + grid[i][j];
					}
				}
			}
		}
	int minPathSum(vector<vector<int>>& grid) {
		int a = grid.size()-1;
		int b = grid[0].size()-1;
		return findMinSum(grid, a, b);
	}
};
int main()
{
	vector<int> a{ 1,1,2 };
	vector<int> b{ 2,3,4 };
	vector<vector<int>> c;
	c.emplace_back(a);
	c.emplace_back(b);
	Solution d;
	d.minPathSum(c);
    return 0;
}

