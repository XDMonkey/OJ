// leetcode48.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> a = matrix;
		for(int i=0;i<a.size();i++)
			for (int j = 0; j < a.size(); j++) 
				matrix[i][j] = a[a.size() - 1 - j][i];
	
	}
};
int main()
{

    return 0;
}

