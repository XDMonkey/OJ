// leetcode37.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
	Solution() {
		for (int i = 1; i < 10; i++)
			a.insert(i + '0');
	}
	set<char> a;
	int flag = 0;
	vector<vector<char>> res;
	set<char>  getSuitedNum(vector<vector<char>> board, int row, int col, set<char> b) {
		int rowTemp = row / 3;
		int colTemp = col / 3;
		int rowStart = rowTemp * 3;
		int colStart = colTemp * 3;
		for (int i = 0; i < 9; i++) {
			b.erase(board[row][i]);
			b.erase(board[i][col]);
		}
		for (int i = rowStart; i < rowStart + 3; i++) {
			for (int j = colStart; j < colStart + 3; j++) {
				b.erase(board[i][j]);
			}

		}
		return b;
	}
	void solveSudoku(vector<vector<char>> &board) {
		solveOne(board, 0, 0);
		board = res;
	}
	void solveOne(vector<vector<char>> board, int row, int col) {
		if (!flag) {
			int i = row;
			int j = col;
			while (board[i][j] != '.') {
				while (i >= 8 && j >= 8) {
					res = board;
					flag = 1;
					return;
				}
				if (j == 8) {
					i++;
					j = 0;
				}
				else
					j++;
			}
			set<char> remainingNum = getSuitedNum(board, i, j, a);
			while (remainingNum.begin() != remainingNum.end()) {
				board[i][j] = *remainingNum.begin();
				remainingNum.erase(board[i][j]);
				solveOne(board, i, j);
			}
		}
	}
};

int main()
{
	vector<char > a1{ '.','.','9','7','4','8','.' ,'.' ,'.' };
	vector<char> a2{ '7','.','.' ,'.' ,'.' ,'.' ,'.' ,'.' ,'.' };
	vector<char> a3{ '.','2','.','1','.','9','.','.','.' };
	vector<char> a4{ '.','.','7','.','.','.','2','4','.' };
	vector<char> a5{ '.','6','4','.','1','.','5','9','.' };
	vector<char> a6{ '.','9','8','.','.','.','3','.','.' };
	vector<char> a7{ '.','.','.','8','.','3','.','2','.' };
	vector<char> a8{ '.','.','.','.','.','.','.','.','6' };
	vector<char> a9{ '.','.','.','2','7','5','9','.','.' };
	vector<vector<char>> a;
	a.emplace_back(a1);
	a.emplace_back(a2);
	a.emplace_back(a3);
	a.emplace_back(a4);
	a.emplace_back(a5);
	a.emplace_back(a6);
	a.emplace_back(a7);
	a.emplace_back(a8);
	a.emplace_back(a9);
	Solution b;
	b.solveSudoku(a);
	return 0;
}

