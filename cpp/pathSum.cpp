// Source : https://leetcode.com/problems/path-sum-iii/

/*
437. Path Sum III

Easy

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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

// https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/di-gui-xiang-jie
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0; 
        int pathImLeading = count(root, sum); // 自己为开头的路径数
        int leftPathSum = pathSum(root->left, sum); // 左边路径总数（相信他能算出来）
        int rightPathSum = pathSum(root->right, sum); // 右边路径总数（相信他能算出来）
        return pathImLeading + leftPathSum + rightPathSum;
    }

    int count(TreeNode* node, int sum){
        if(!node) return 0;
        // 我自己能不能独当一面，作为一条单独的路径呢？
        int isMe = node->val == sum ? 1 : 0;
        // 左边的小老弟，你那边能凑几个 sum - node.val 呀？
        int leftCount = count(node->left, sum - node->val);
        // 右边的小老弟，你那边能凑几个 sum - node.val 呀？
        int rightCount = count(node->right, sum - node->val);
        return isMe + leftCount + rightCount; // 我这能凑这么多个
    }
};