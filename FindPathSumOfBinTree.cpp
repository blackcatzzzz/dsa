#include <vector>

using namespace std;


/*
* 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
* 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return vector<vector<int>>();
		vector<vector<int>> vecRes;
		vector<int> vecPath;
		int sum = 0;
		findPathCore(root, expectNumber, vecRes, vecPath, sum);
		return vecRes;
	}

private:
	void findPathCore(TreeNode * x, int expectNumber, vector<vector<int>> &vecRes,
		vector<int> &vecPath, int &sum)
	{
		if (x == NULL)
			return;

		sum += x->val;
		vecPath.push_back(x->val);
		bool isLeaf = (x->left == NULL) && (x->right == NULL);
		if (sum == expectNumber && isLeaf)
		{
			vecRes.push_back(vecPath);
		}

		if (x->left)
			findPathCore(x->left, expectNumber, vecRes, vecPath, sum);
		if (x->right)
			findPathCore(x->right, expectNumber, vecRes, vecPath, sum);

		sum -= x->val;
		vecPath.pop_back();
		return;
	}
};

// 2018.6.16
class Solution1 {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return vector<vector<int>>();
		vector<vector<int>> vecRes;
		vector<int> vecPath;
		int sum = 0;
		findPathCore(root, expectNumber, vecRes, vecPath, sum);
		return vecRes;
	}

private:
	void findPathCore(TreeNode * x, int expectNumber, vector<vector<int>> &vecRes,
		vector<int> &vecPath, int &sum)
	{
		vecPath.push_back(x->val);
		sum += x->val;

		if (!x->left && !x->right && sum == expectNumber)
			vecRes.push_back(vecPath);

		if (x->left)
			findPathCore(x->left, expectNumber, vecRes, vecPath, sum);

		if (x->right)
			findPathCore(x->right, expectNumber, vecRes, vecPath, sum);

		sum -= x->val;
		vecPath.pop_back();
	}
};

int main()
{
	return 0;
}