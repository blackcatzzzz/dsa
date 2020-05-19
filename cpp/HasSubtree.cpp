#include <iostream>


#include <iostream>

/*
* 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;

		bool isLeftSubtree = true;
		bool isRightSubtree = true;
		if (pRoot1->val == pRoot2->val)
		{
			if (pRoot2->left)
				isLeftSubtree = HasSubtree(pRoot1->left, pRoot2->left);
			if (pRoot2->right)
				isRightSubtree = HasSubtree(pRoot1->right, pRoot2->right);

			if (isLeftSubtree && isRightSubtree)
				return true;
			else
				return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
		}
		else
			return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
};

int main()
{
	return 0;
}