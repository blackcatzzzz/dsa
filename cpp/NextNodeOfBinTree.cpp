#include <iostream>

/*
* ����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
* ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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
		if (x->right) //�����Һ��ӣ���ֱ�Ӻ�̱����������У�����ؾ���
		{
			x = x->right; //��������
			while (x->left) //�����С���Ľڵ�
				x = x->left;
		}
		else
		{
			//����ֱ�Ӻ��Ӧ�ǡ�����ǰ�ڵ���������������е�������ȡ�������ؾ���
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