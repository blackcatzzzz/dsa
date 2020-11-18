
/*
99. Recover Binary Search Tree
You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* x = root;
        TreeNode* pred = nullptr;
        TreeNode* p = nullptr, *q = nullptr;
        while(true){
            while(x){
                stk.push(x);
                x = x->left;
            }

            if(stk.empty())
                break;

            x = stk.top();
            stk.pop();
            if(pred != nullptr && pred->val > x->val){
                q = x;
                if(p == nullptr)
                    p = pred;
                else
                    break;
            }

            pred = x;
            x = x->right;
        }

        swap(p, q);

        return;
    }

private:
    void swap(TreeNode* p, TreeNode* q){
        int tmp = p->val;
        p->val = q->val;
        q->val = tmp;
    }

};

int main(){
    Solution S;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    S.recoverTree(root);
}