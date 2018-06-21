#include <iostream>
#include <sstream>

using namespace std;

/**
* LeetCode 297. Serialize and Deserialize Binary Tree
* LintCode 7. Binary Tree Serialization
* 剑指Offer 62.
*
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
	char* Serialize(TreeNode *root) {
		ostringstream out;
		serialize(root, out);
		str = out.str();
		//char * s = (char*)(out.str().c_str());
		return (char*)str.c_str();
	}

	TreeNode* Deserialize(char *str) {
		istringstream in(str);
		return deserialize(in);
	}

private:
	void serialize(TreeNode* root, ostringstream& out)
	{
		if (root)
		{
			out << root->val << " ";
			serialize(root->left, out);
			serialize(root->right, out);
		}
		else
			out << "# ";
	}

	TreeNode* deserialize(istringstream& in)
	{
		string s;
		in >> s;

		if (s == "#")
			return nullptr;
		
		TreeNode* root = new TreeNode(stoi(s));
		root->left = deserialize(in);
		root->right = deserialize(in);
		
		return root;
	}

	string str; // 必须成员变量，否则牛客通不过（返回的值char*）
};

void test()
{
	ostringstream oss;
	oss << "123 " << "456 " << "789 ";
	cout << oss.str() << endl;

	istringstream in(oss.str());
	string s;
	while (in >> s)
	{
		cout << s << ',';
	}
}

int main()
{
	//test();
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	Solution s;
	char* str = s.Serialize(root);
	TreeNode* root1 = s.Deserialize(str);
	getchar();
	return 0;
}