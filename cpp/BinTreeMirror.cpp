#include <iostream>

/*
	���������Ķ�����������任ΪԴ�������ľ���
	�������� :
	�������ľ����壺Դ������
	8
	/ \
	6   10
	/ \ / \
	5  7 9 11
	���������
	8
	/ \
	10   6
	/ \ / \
	11 9 7  5
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// http://blog.csdn.net/yuzhongchun/article/details/39697729
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL) return;
		if (pRoot->left == NULL && pRoot->right == NULL) return;
		TreeNode* left = pRoot->left;
		TreeNode* right = pRoot->right;
		pRoot->left = right;
		pRoot->right = left;
		Mirror(left);
		Mirror(right);
		return;
	}
};

// 2018.6.16
class Solution1 {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;

		TreeNode* left = pRoot->left;
		TreeNode* right = pRoot->right;
		pRoot->left = right;
		pRoot->right = left;
		Mirror(left);
		Mirror(right);

		return;
	}
};

int main()
{
	return 0;
}