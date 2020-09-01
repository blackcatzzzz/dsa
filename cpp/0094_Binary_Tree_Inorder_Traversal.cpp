/*
94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }

private:
    void inorder(TreeNode* root){
        stack<TreeNode*> stack;
        TreeNode* x = root;
        while(x || !stack.empty()){
            while(x){
                stack.push(x);
                x = x->left;
            }

            TreeNode* node = stack.top();
            stack.pop();
            res.push_back(node->val);

            x = node->right;
        }
    }

    void inorder_recursive(TreeNode* root){
        if(!root)
            return;
        
        inorder_recursive(root->left);
        res.push_back(root->val);
        inorder_recursive(root->right);
    }

private:
    vector<int> res;
};

int main(){
    Solution S;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    printVector(S.inorderTraversal(root));
}