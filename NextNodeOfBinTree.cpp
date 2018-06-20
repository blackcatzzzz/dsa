#include <iostream>

/*
* 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
* 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;

		TreeLinkNode* x = pNode;
		if (x->right) //若有右孩子，则直接后继必在右子树中，具体地就是
		{
			x = x->right; //右子树中
			while (x->left) //最靠左（最小）的节点
				x = x->left;
		}
		else
		{
			//否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
			while (x->next && x == x->next->right)
				x = x->next;
			x = x->next;
		}

		return x;
	}
};


int main()
{
	return 0;
}