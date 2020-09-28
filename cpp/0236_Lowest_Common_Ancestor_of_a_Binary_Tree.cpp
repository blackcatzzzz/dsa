/*
236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        getPath(root, p, path1);
        getPath(root, q, path2);
        TreeNode* ancestor = root;
        for(int i = 0; i < path1.size() && i < path2.size(); i++){
            if(path1[i] == path2[i])
                ancestor = path1[i];
            else
                break;
        }

        return ancestor;
    }

private:
    bool getPath(TreeNode* root, TreeNode* x, vector<TreeNode*>& path){
        if(!root)
            return false;

        path.push_back(root);
        if(root->val == x->val)
            return true;

        if(getPath(root->left, x, path) || getPath(root->right, x, path))
            return true;
        path.pop_back(); 

        return false;      
    }
};

int main(){
    Solution S;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    cout << S.lowestCommonAncestor(root, root->left, root->left->right->right)->val;
}