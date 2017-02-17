// leetcode76.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		map<char, int> res;
		map<char, int> rec;
		for (int i = 0; i < t.size(); i++) {
			res[t[i]] ++;
			rec[t[i]] = 0;
		}
		int start_p = 0;
		int end_p = 0;
		int min = s.size() - 1;
		int start = 0;
		int end = 0;
		int flag2 = 0;
		while (end_p != s.size()) {
			if (res.find(s[end_p]) != res.end()) {
				rec[s[end_p]]++;
				int flag = 1;
				for (auto i = res.begin(), j = rec.begin(); i != res.end(); i++, j++) {
					if (i->second > j->second) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					flag2 = 1;
					while (!(res.find(s[start_p]) != res.end() && res[s[start_p]] == rec[s[start_p]])) {
						if (res.find(s[start_p]) != res.end())
							rec[s[start_p]]--;
						start_p++;
					}
					if (end_p - start_p <= min) {
						min = end_p - start_p;
						start = start_p;
						end = end_p;
					}
					rec[s[start_p]]--;
					start_p++;
				}
			}
			end_p++;
		}
		if (flag2)
			return s.substr(start, end - start + 1);
		return string("");
	}
};


int main()
{
	Solution a;
	cout << a.minWindow("ADOBECODEBANC", "ABC");
	return 0;
}

