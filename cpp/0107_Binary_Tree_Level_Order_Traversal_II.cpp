/*
107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

#include "common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 或者将结果保存在stack中,最后从stack弹出
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        helper(q);
        return res;
    }

private:
    void helper(queue<TreeNode*>& q){
        if(q.empty())
            return;
        int count = q.size();
        vector<int> nodes;
        while(count--){
            TreeNode* x = q.front();
            q.pop();
            nodes.push_back(x->val);
            if(x->left)
                q.push(x->left);

            if(x->right)
                q.push(x->right);
        }

        helper(q);
        res.push_back(nodes);
    }

private:
    vector<vector<int>> res;
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution S;
    printVectors(S.levelOrderBottom(root));
}