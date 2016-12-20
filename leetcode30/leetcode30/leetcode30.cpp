// leetcode30.cpp : 定义控制台应用程序的入口点。
//sdf

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	unordered_map<string, int> hash_map;
	vector<int> findSubstring(string s, vector<string>& words) {
		int flag = -1;
		vector<int> res;
		auto a = words.begin();
		for (; a != words.end(); a++) {
			if (!hash_map.count(*a))
				hash_map.insert(pair<string, int>(*a, 1));
			else
				hash_map[*a]++;
		}
		unordered_map<string, int> temp_map = hash_map;
		int length = words[0].length();
		int i = 0;
		int j = 0;
		int flag2=0;
		string b;
		for (; i < s.length();) {
			i = flag+1;
			flag = i;
			j = 0;
			while (i+length<s.length()+1) {
				b = s.substr(i, length);
				if (hash_map[b]>0) {//如果map中存在而且还有余量
					j++;
					i += length;
					hash_map[b]--;
					if (j == words.size()) {//如果已经找到了所有的元素
						res.push_back(flag);
						hash_map = temp_map;
						break;
					}
				}
				else {//如果发现有一个元素在map中不存在
					hash_map = temp_map;
					break;
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution a;
	string b("barfoofoobarthefoobarman");
	vector<string> c;
	c.push_back("foo");
	c.push_back("bar");
	c.push_back("the");
	cout << c.size();
	vector<int> d=a.findSubstring(b, c);
	cout << d[0] << endl;
	cout << d[1];
	for (int j = 0; j < 100000; j++)
		cout << "sdf";
	return 0;
}

