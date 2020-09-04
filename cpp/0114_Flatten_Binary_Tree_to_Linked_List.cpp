/*
114. Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

#include "common.h"

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
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> S;
        TreeNode* dummy = new TreeNode(0, nullptr, root);
        S.push(root);
        TreeNode* pre = dummy;
        while (!S.empty()){
            TreeNode* curr = S.top();
            S.pop();
            pre->left = nullptr;
            pre->right = curr;
            if(curr->right)
                S.push(curr->right);
            if(curr->left)
                S.push(curr->left);
            pre = curr;
        }

        delete dummy;
        dummy = nullptr;
    }
};

int main(){

}