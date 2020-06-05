//Source: https://leetcode.com/problems/unique-binary-search-trees-ii/

/*
95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

0 <= n <= 8
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

// https://leetcode.wang/leetCode-95-Unique-Binary-Search-TreesII.html
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0)
            return vector<TreeNode*>();
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }

        if(start == end){
            res.push_back(new TreeNode(start));
            return res;
        }

        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftTrees = helper(start, i - 1);
            vector<TreeNode*> rightTrees = helper(i + 1, end);
            for(TreeNode* leftTree: leftTrees){
                for(TreeNode* rightTree: rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<TreeNode*> res = s.generateTrees(0);
    for(TreeNode* n :res){
        if(!n)
            continue;
        cout << n->val;
        if(n->left)
            cout << " " << n->left->val;
        else
            cout << " #";

        if(n->right)
            cout << " " << n->right->val;
        else
            cout << " #";

        cout << endl;
    }
}