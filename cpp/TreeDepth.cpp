#include <iostream>
#include <algorithm>

using namespace std;

/*
* ����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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