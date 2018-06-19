#include <iostream>
#include <algorithm>

using namespace std;

/*
* 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
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
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return isBalanced_Recursion(pRoot, depth);
	}

private:
	bool isBalanced_Recursion(TreeNode* x, int & depth)
	{
		if (x == NULL)
		{
			depth = 0;
			return true;
		}

		int leftDepth, rightDepth;
		if (isBalanced_Recursion(x->left, leftDepth)
			&& isBalanced_Recursion(x->right, rightDepth))
		{
			int diff = leftDepth - rightDepth;
			if (-1 <= diff && diff <= 1)
			{
				depth = max(leftDepth, rightDepth) + 1;
				return true;
			}
		}

		return false;
	}
};

// 2018.6.19
class Solution1 {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return isBalanced_Recursion(pRoot, depth);
	}

private:
	bool isBalanced_Recursion(TreeNode* x, int & depth)
	{
		if (x == NULL)
			return true;

		int leftDepth = 0, rightDepth = 0;
		bool left = isBalanced_Recursion(x->left, leftDepth);
		bool right = isBalanced_Recursion(x->right, rightDepth);

		if (!left || !right)
			return false;

		if (abs(leftDepth - rightDepth) > 1)
			return false;

		depth = max(leftDepth, rightDepth) + 1;

		return true;
	}
};

int main()
{
	return 0;
}