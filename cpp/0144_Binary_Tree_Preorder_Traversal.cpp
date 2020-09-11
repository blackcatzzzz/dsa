/*
144. Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* x = root;
        while(x || !stk.empty()){
            while(x){
                res.push_back(x->val);
                if(x->right)
                    stk.push(x->right);
                x = x->left;
            }

            if(stk.empty())
                break;

            x = stk.top();
            stk.pop();
        }

        return res;
    }
};


int main(){

}