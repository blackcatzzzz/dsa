#include <iostream>

/*
* 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
* 要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;

		//travInOrderRecursion(pRootOfTree, &Solution::addToListNode);
		travInOrder(pRootOfTree);

		TreeNode* headOfList = tailListNode;
		while (headOfList->left)
			headOfList = headOfList->left;

		return headOfList;
	}
private:
	// 方法1：不使用visit
	void travInOrder(TreeNode* x)
	{
		if (x->left)
			travInOrder(x->left);

		x->left = tailListNode;
		if (tailListNode)
			tailListNode->right = x;
		tailListNode = x;

		if (x->right)
			travInOrder(x->right);
	}

	// 方法2：使用visit
	template <typename VST>
	void travInOrderRecursion(TreeNode* x, VST visit)
	{
		if (x->left)
			travInOrderRecursion(x->left, visit);
		(this->*visit)(x);
		if (x->right)
			travInOrderRecursion(x->right, visit);
	}

	void addToListNode(TreeNode* x)
	{
		x->left = tailListNode;
		if (tailListNode)
			tailListNode->right = x;
		tailListNode = x;
	}

private:
	TreeNode* tailListNode = NULL;
};

int main()
{

}