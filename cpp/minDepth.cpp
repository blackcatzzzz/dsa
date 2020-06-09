//Source:https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/

/*
111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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

// https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/bfs-kuang-jia
// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        // root 本身就是一层，depth 初始化为 1
        int depth = 1;

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* x = q.front();
                q.pop();

                if(x->left == nullptr && x->right == nullptr)
                    return depth;
                
                if(x->left)
                    q.push(x->left);

                if(x->right)
                    q.push(x->right);
            }

            depth++;
        }

        return depth;
    }
};