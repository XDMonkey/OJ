class Solution {
public:
	bool posIsRight(vector<string> &a, int i, int j, int n) {
		for (int m = 0; m < i; m++) {
			if (a[m][j] == 'Q')
				return false;
			if (i + j - m < n&&a[m][i + j - m] == 'Q')
				return false;
			if (j - i + m > -1 && a[m][j - i + m] == 'Q')
				return false;
		}
		return true;
	}
    int totalNQueens(int n) {
        int i = 0;
		int res=0;
		vector<string> a(n, string(n, '.'));
		vector<int> queenPos(n, -1);
		while (i > -1) {
			if (i > n - 1) {
				res++;
				i--;
			}
			if (queenPos[i] > -1)
				a[i][queenPos[i]] = '.';
			while (!posIsRight(a, i, ++queenPos[i], n) && queenPos[i]<n) {
			}
			if (queenPos[i] >= n) {
				queenPos[i] = -1;
				i--;
			}
			else {
				a[i][queenPos[i]] = 'Q';
				i++;
			}
		}
		return res;
    }
};