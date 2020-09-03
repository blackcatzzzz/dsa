/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty() && inorder.size() != postorder.size())
            return nullptr;
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd){
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int i = inStart;
        for(; i <= inEnd; i++)
            if(inorder[i] == rootVal)
                break;

        // if(i > inEnd)
        //     return nullptr;

        int leftLen = i - inStart;
        int rightLen =  inEnd - i;

        if(leftLen)
            root->left = helper(inorder, inStart, i - 1, postorder, postStart, postStart + leftLen - 1);

        if(rightLen)
            root->right = helper(inorder, i + 1, inEnd, postorder, postStart + leftLen, postEnd - 1);

        return root;
    }
};

int main(){
    Solution S;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = S.buildTree(inorder, postorder);
    getchar();
}