/*
257. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }

private:
    void dfs(TreeNode* root, string path){
        if(!root)
            return;

        path += to_string(root->val);

        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }

        path += "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }

private:
    vector<string> ans;
};


int main(){

}