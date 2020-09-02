/*
103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        vector<int> nodes;
        bool fromRight = true;
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        stack1.push(root);
        while(!stack1.empty() || !stack2.empty()){
            TreeNode* x = nullptr;
            if(fromRight){
                x = stack1.top();
                stack1.pop();
                nodes.push_back(x->val);
                if(x->left)
                    stack2.push(x->left);
                if(x->right)
                    stack2.push(x->right);
            }else{
                x = stack2.top();
                stack2.pop();
                nodes.push_back(x->val);
                if(x->right)
                    stack1.push(x->right);
                if(x->left)
                    stack1.push(x->left);
            }

            if(fromRight && stack1.empty() || !fromRight && stack2.empty()){
                res.push_back(nodes);
                nodes.clear();
                fromRight = !fromRight;
            }
        }

        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution S;
    printVectors(S.zigzagLevelOrder(root));
}