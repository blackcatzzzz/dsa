#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// old
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0)
			return NULL;

		return constructCore(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}

private:
	TreeNode* constructCore(vector<int> &pre, int preLo, int preHi, vector<int> &vin, int inLo, int inHi)
	{
		if (preLo > preHi || inLo > inHi)
			return NULL;

		int rootVal = pre[preLo];
		TreeNode* root = new TreeNode(rootVal);
		int rootIndex = inLo;
		for (; rootVal != vin[rootIndex] && rootIndex <= inHi; ++rootIndex);

		int leftLen = rootIndex - inLo;
		int rightLen = inHi - rootIndex;
		if (leftLen >= 0)
		{
			root->left = constructCore(pre, preLo + 1, preLo + leftLen, vin, inLo, rootIndex - 1);
		}

		if (rightLen >= 0)
		{
			root->right = constructCore(pre, preLo + leftLen + 1, preHi, vin, rootIndex + 1, inHi);
		}

		return root;
	}
};

// 2018.6.14
class Solution1 {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0)
			return NULL;

		return reConstructCore(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}

private:
	// [lo,hi]
	TreeNode* reConstructCore(vector<int>& pre, int preLo, int preHi, vector<int>& vin, int vinLo, int vinHi)
	{
		// 必须加
		if (preLo > preHi || vinLo > vinHi)
			return NULL;

		int rootVal = pre[preLo];

		int i = vinLo;
		for (; i <= vinHi; ++i)
			if (vin[i] == rootVal)
				break;

		TreeNode* root = new TreeNode(rootVal);

		// 在中序序列中找到
		if (i <= vinHi)
		{
			int leftLen = i - vinLo; // 左子树长度
			int rightLen = vinHi - i; // 右子树长度

			if (leftLen > 0)
				root->left = reConstructCore(pre, preLo + 1, preLo + leftLen, vin, vinLo, i - 1);
			if (right > 0)
				root->right = reConstructCore(pre, preLo + leftLen + 1, preHi, vin, i + 1, vinHi);
		}

		return root;
	}
};

int main()
{
	getchar();
	return 0;
}