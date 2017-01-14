// leetcode56.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include <algorithm>
using namespace std;


struct Interval {
	int start;     int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
	static bool comp(Interval x, Interval y) {
		return x.start < y.start || (x.start == y.start && x.end < y.end);
	}
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		int n = intervals.size();
		if (!n) return ret;
		// 区间排序，第一关键字为区间起点，第二关键字为区间终点
		sort(intervals.begin(), intervals.end(), Solution::comp);

		int nowStart = intervals[0].start, nowEnd = intervals[0].end;
		for (int i = 1; i < n; ++i)
			if (nowEnd >= intervals[i].start) {    // 当前区间与区间i重叠
				if (nowEnd < intervals[i].end)     // 当前区间的末尾小于区间i末尾时，才需要扩张 
					nowEnd = intervals[i].end;
			}
			else {                                 // 当前区间与区间i不重叠，则当前区间不可再扩张
				ret.push_back(Interval(nowStart, nowEnd));    // 记录当前区间
				nowStart = intervals[i].start, nowEnd = intervals[i].end;
			}
			ret.push_back(Interval(nowStart, nowEnd));    // 记录当前区间
			return ret;
	}
};

int main()
{
	return 0;
}

