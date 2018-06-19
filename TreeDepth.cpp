#include <iostream>
#include <algorithm>

using namespace std;

/*
* 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
	int TreeDepth(TreeNode* pRoot)
	{
		return TreeDepth_Recursion(pRoot);
	}

private:
	int TreeDepth_Recursion(TreeNode* x)
	{
		if (x == NULL)
			return 0;
		return max(TreeDepth_Recursion(x->left), TreeDepth_Recursion(x->right)) + 1;
	}
};