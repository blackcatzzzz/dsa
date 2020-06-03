//Source: https://leetcode.com/problems/binary-tree-inorder-traversal/

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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* root, vector<int>& res){
        if(root == nullptr)
            return;

        traverse(root->left, res);
        res.push_back(root->val);
        traverse(root->right, res);
    }
};

// Iterative solution using stack
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stackTN;
        TreeNode* x = root;
        while(x || !stackTN.empty()){
            while(x){
                stackTN.push(x);
                x = x->left;
            }

            x = stackTN.top();
            res.push_back(x->val);
            stackTN.pop();

            x = x->right;
        }
        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution1 s;
    vector<int> res = s.inorderTraversal(root);
    printVector(res);
}