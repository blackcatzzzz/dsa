/*
102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) 
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int curLevelCount = 1;
        int nextLevelCount = 0;
        vector<int> nodes;
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            nodes.push_back(x->val);

            if(x->left){
                q.push(x->left);
                nextLevelCount++;
            }

            if(x->right){
                q.push(x->right);
                nextLevelCount++;
            }

            curLevelCount--;
            if(!curLevelCount){
                res.push_back(nodes);
                nodes.clear();
                curLevelCount = nextLevelCount;
                nextLevelCount = 0;
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) 
            return res;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> nodes;
        while(!q.empty()){
            int count = q.size();
            while(count--){
                TreeNode* x = q.front();
                q.pop();
                nodes.push_back(x->val);

                if(x->left)
                    q.push(x->left);

                if(x->right)
                    q.push(x->right);
            }

            res.push_back(nodes);
            nodes.clear();
        }

        return res;
    }
};

int main(){

}