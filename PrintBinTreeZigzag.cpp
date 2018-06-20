#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
* ��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
* �ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> vecRes;

		if (pRoot == NULL)
			return vecRes;

		stack<TreeNode*> stack[2]; // stack[0]�������㣬stack[1]��ż���㡣���ڵ���������(1)
		int current = 0;
		int next = 1;
		stack[current].push(pRoot);

		vector<int> v;
		while (!stack[0].empty() || !stack[1].empty())
		{
			TreeNode* x = stack[current].top();
			stack[current].pop();

			v.push_back(x->val);

			if (current) // ��ǰ����ż���㣬���²���������
			{
				if (x->right)
					stack[next].push(x->right);
				if (x->left)
					stack[next].push(x->left);
			}
			else
			{
				if (x->left)
					stack[next].push(x->left);
				if (x->right)
					stack[next].push(x->right);
			}

			if (stack[current].empty())
			{
				vecRes.push_back(v);
				v.clear();
				current = 1 - current;
				next = 1 - next;
			}
		}

		return vecRes;

	}

};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	s.Print(root);
	return 0;
}