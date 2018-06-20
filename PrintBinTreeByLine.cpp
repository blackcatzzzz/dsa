#include <queue>
#include <vector>

using namespace std;

/*
* 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
		if (pRoot == NULL)
			return vector<vector<int>>();

		vector<vector<int>> vecRes;
		queue<TreeNode*> q;
		int toBePrinted = 1;
		int nextLevelNum = 0;
		q.push(pRoot);

		vector<int> vecLine;
		while (!q.empty())
		{
			TreeNode* x = q.front();
			q.pop();
			vecLine.push_back(x->val);
			toBePrinted--;

			if (x->left)
			{
				q.push(x->left);
				nextLevelNum++;
			}

			if (x->right)
			{
				q.push(x->right);
				nextLevelNum++;
			}

			if (toBePrinted == 0)
			{
				vecRes.push_back(vecLine);
				vecLine.clear(); 
				toBePrinted = nextLevelNum;
				nextLevelNum = 0;
			}
		}

		return vecRes;
	}

};

int main()
{
	return 0;
}