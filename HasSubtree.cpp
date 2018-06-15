#include <iostream>


#include <iostream>

/*
* �������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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