// leetcode50.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.empty())
			return vector<vector<string> >();
		int len = strs.size();
		sort(strs.begin(), strs.end());
		vector<vector<string> > ret;
		unordered_map<string, vector<string>> mv;
		for (int i = 0; i < len; i++)
		{
			string str = strs[i];
			sort(str.begin(), str.end());
			mv[str].push_back(strs[i]);
		}
		for (unordered_map<string, vector<string> >::iterator iter = mv.begin(); iter != mv.end(); iter++)
			ret.push_back(iter->second);
		return ret;
	}
};
int main()
{
	return 0;
}

