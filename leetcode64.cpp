// leetcode64(改进版).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int a = grid.size();
		int b = grid[0].size();
		int **p = new int*[a];
		for (int i = 0; i < a; i++)
			p[i] = new int[b];
		p[0][0] = grid[0][0];
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++) {
				if (i || j) {
					if (!i)
						p[i][j] = p[i][j - 1] + grid[i][j];
					else if (!j)
						p[i][j] = p[i - 1][j] + grid[i][j];
					else {
						if (p[i - 1][j] > p[i][j - 1])
							p[i][j] = p[i][j - 1] + grid[i][j];
						else
							p[i][j] = p[i - 1][j] + grid[i][j];
					}
				}
			}
		return p[a - 1][b - 1];
	}
};
int main()
{
	vector<int> a{ 1,1,2 };
	vector<int> b{ 2,3,4 };
	vector<vector<int>> c;
	c.emplace_back(a);
	c.emplace_back(b);
	Solution h;
	h.minPathSum(c);
	return 0;
}

