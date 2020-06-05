//Source: https://leetcode.com/problems/unique-binary-search-trees-ii/

/*
95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

0 <= n <= 8
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "common.h"

// https://leetcode.wang/leetCode-95-Unique-Binary-Search-TreesII.html
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0)
            return vector<TreeNode*>();
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }

        if(start == end){
            res.push_back(new TreeNode(start));
            return res;
        }

        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftTrees = helper(start, i - 1);
            vector<TreeNode*> rightTrees = helper(i + 1, end);
            for(TreeNode* leftTree: leftTrees){
                for(TreeNode* rightTree: rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};

// 参考: https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31493/Java-Solution-with-DP
// DP offset
class Solution1 {
public:
    vector<TreeNode*> generateTrees(int n) {
        // dp[len] 长度为len的生成树
        vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
        if(n <= 0)
            return dp[0];

        dp[0].push_back(nullptr);
        // 长度从1到n
        for(int len = 1; len <= n; len++){
            for(int i = 1; i <= len; i++){
                vector<TreeNode*> leftTrees = dp[i - 1];
                vector<TreeNode*> rightTrees = dp[len - i];
                for(auto leftTree: leftTrees){
                    for(auto rightTree: rightTrees){
                        TreeNode* root = new TreeNode(i);
                        root->left = leftTree;
                        root->right = clone(rightTree, i);
                        dp[len].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

    TreeNode* clone(TreeNode* node, int offset){
        if(!node)
            return nullptr;
        TreeNode* root = new TreeNode(node->val + offset);
        root->left = clone(node->left, offset);
        root->right = clone(node->right, offset);
        return root;
    }
};

// 参考: https://leetcode.wang/leetCode-95-Unique-Binary-Search-TreesII.html
// 常规DP
class Solution2 {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> vecPre;
        if(n <= 0)
            return vecPre;

        vecPre.push_back(nullptr);
        for(int i = 1; i <= n; i++){
            vector<TreeNode*> vecCur;
            for(auto x:vecPre){
                // 插入根节点
                TreeNode* insert = new TreeNode(i);
                insert->left = x;
                vecCur.push_back(insert);

                //插入到右孩子，右孩子的右孩子...最多找 n 次孩子
                for (int j = 0; j <= n; j++) {
                    TreeNode* tmpRoot = treeCopy(x);
                    TreeNode* right = tmpRoot;    // 待插入的节点的位置（即要插入该节点的右孩子）
                    
                    int k = j;
                    while(k-- > 0 && right){
                        right = right->right;
                    }

                    if(!right)
                        break;
                    
                    //保存当前右孩子的位置的子树作为插入节点的左孩子
                    TreeNode* tmpRight = right->right;
                    TreeNode* insert = new TreeNode(i);
                    right->right = insert;
                    insert->left = tmpRight;
                    vecCur.push_back(tmpRoot);
                }
            }

            vecPre = vecCur;
        }

        return vecPre;
    }

    TreeNode* treeCopy(TreeNode* root){
        if(!root)
            return root;
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = treeCopy(root->left);
        newRoot->right = treeCopy(root->right);
        return newRoot;
    }
};

int main(){
    Solution2 s;
    vector<TreeNode*> res = s.generateTrees(3);
    for(TreeNode* n :res){
        if(!n)
            continue;
        cout << n->val;
        if(n->left)
            cout << " " << n->left->val;
        else
            cout << " #";

        if(n->right)
            cout << " " << n->right->val;
        else
            cout << " #";

        cout << endl;
    }
}