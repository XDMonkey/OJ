struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Tree {
public:
	int flag = 0;
	int max = 0;
	int min = 0;
	vector<int> rec;
	vector<int> minS;
	vector<int> maxS;
	int getDis(TreeNode* root) {
		int res = 0;
		r
		recursion(root, minS, maxS);
		int length = minS.size() > maxS.size() ? maxS.size() : minS.size();
		int flag1 = 0;
		for (int i = 0; i < length; i++) {
			if (minS[i] != maxS[i]) {
				flag1 = i;
				break;
			}
		}
		int ewai = minS.size() - length == 0 ? maxS.size() - length : minS.size() - length;
		res = (length - flag1)*2 + ewai;
		return res;
	}
	void recursion(TreeNode* root, vector<int> &minS, vector<int> &maxS) {

		if (root->left == NULL&&root->right == NULL) {
			if (!flag) {
				min = max = root->val;
				minS = maxS = rec;
				flag = 1;
			}
			else {
				if (min > root->val) {
					min = root->val;
					minS = rec;
				}
				if (max < root->val) {
					max = root->val;
					maxS = rec;
				}
			}

		}
		if (root->left) {
			rec.emplace_back(0);
			recursion(root->left,minS,maxS);
			rec.pop_back();
		}
		if (root->right) {
			rec.emplace_back(1);
			recursion(root->right,minS,maxS);
			rec.pop_back();
		}
	}
};