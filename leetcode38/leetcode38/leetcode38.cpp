// leetcode38.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int num = 1;
	int length = 0;
	int temp_i = 0;
	int n_i = 1;
	string ini = ("1");
	string recursion(string a, int n) {
		num = 1;

		if (n_i == n) {
			return a;
		}
		n_i++;
		temp_i = 0;
		string temp(100,'c');
		length = a.length();
		for (int i = 0; i < length; i++) {
			if (i + 1 < length&&a[i + 1] != a[i]) {
				temp[temp_i] = char(num+48);
				temp[temp_i + 1] = a[i];
				temp_i+=2;
				num = 1;
			}
			else if (i + 1 == length) {
				temp[temp_i] = char(num+48);
				temp[temp_i + 1] = a[i];
			}
			else
				num++;
		}
		string temp_next = temp.substr(0, temp_i + 2);
	return 	recursion(temp_next, n);
	}
	string countAndSay(int n) {
		return recursion(ini, n);
	}
};
int main()
{
	Solution h;
	cout<<h.countAndSay(4);
	return 0;
}

