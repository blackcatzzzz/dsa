#include <vector>
#include <queue>

using namespace std;

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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (root == NULL) return vector<int>();
		vector<int> vecRes;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode* x = q.front();
			q.pop();
			vecRes.push_back(x->val);
			if (x->left) q.push(x->left);
			if (x->right) q.push(x->right);
		}

		return vecRes;
	}
};

int main()
{
	getchar();
	return 0;
}