/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() && preorder.size() != inorder.size())
            return nullptr;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int i = inStart;
        for(; i <= inEnd; i++)
            if(inorder[i] == rootVal)
                break;

        // if(i > inEnd)
        //     return nullptr;

        int leftLen = i - inStart;
        int rightLen = inEnd - i;

        if(leftLen > 0)
            root->left = helper(preorder, preStart + 1, preStart + leftLen, inorder, inStart, i - 1);
        
        if(rightLen > 0)
            root->right = helper(preorder, preStart + leftLen + 1, preEnd, inorder, i + 1, inEnd);

        return root;
    }
};


int main(){
    Solution S;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = S.buildTree(preorder, inorder);
    getchar();
}