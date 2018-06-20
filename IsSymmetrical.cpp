#include <iostream>


/*
* ��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
* ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot)
			return true;

		return isTreeSymmetrical(pRoot->left, pRoot->right);
	}

private:
	bool isTreeSymmetrical(TreeNode* node1, TreeNode* node2)
	{
		if (!node1 && !node2)
			return true;

		if (node1 && !node2)
			return false;

		if (!node1 && node2)
			return false;

		return node1->val == node2->val && isTreeSymmetrical(node1->left, node2->right)
			&& isTreeSymmetrical(node1->right, node2->left);
	}

};

int main()
{
	return 0;
}