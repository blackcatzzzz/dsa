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
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return {};
        return helper(1, n);
    }

private:
    vector<TreeNode*> helper(int start, int end) {
        if(start > end)
            return {nullptr};

        vector<TreeNode*> allTrees;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftTrees = helper(start, i - 1);
            vector<TreeNode*> rightTrees = helper(i + 1, end);

            for(auto& leftTree : leftTrees){
                for(auto& rightTree : rightTrees){
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = leftTree;
                    currTree->right = rightTree;
                    allTrees.push_back(currTree);
                }
            }
        }

        return allTrees;
    }
};

int main(){

}