/*
98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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

// recursion
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool helper(TreeNode* root, long long lower, long long upper){
        if(!root) return true;
        if(root->val <= lower || root->val >= upper) return false;
        return helper(root->left, lower, root->val) 
            && helper(root->right, root->val, upper);
    }
};

// inorder
class Solution_Inorder {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stackTN;
        long long preValue = LLONG_MIN;
        TreeNode* x = root;
        while(x || !stackTN.empty()){
            while(x){
                stackTN.push(x);
                x = x->left;
            }

            x = stackTN.top();
            stackTN.pop();

            if(preValue >= x->val){          
                return false;
            }

            preValue = x->val;
            x = x->right;
        }

        return true;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    Solution_Inorder SI;
    cout << SI.isValidBST(root) << endl;

    Solution S;
    cout << S.isValidBST(root) << endl;
}