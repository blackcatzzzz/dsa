/*
109. Convert Sorted List to Binary Search Tree
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [0]
Output: [0]
Example 4:

Input: head = [1,3]
Output: [3,1]
 

Constraints:

The numner of nodes in head is in the range [0, 2 * 10^4].
-10^5 <= Node.val <= 10^5
*/

#include "common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }

private:
    TreeNode* helper(ListNode* left, ListNode* right){
        if(left == right)
            return nullptr;
        ListNode* mid = getMedian(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = helper(left, mid);
        root->right = helper(mid->next, right);
        return root;
    }

    ListNode* getMedian(ListNode* left, ListNode* right){
        ListNode* slow = left;
        ListNode* fast = left;
        while(fast != right && fast->next != right){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLen(head);
        return buildTree(head, 0, len - 1);
    }

private:
    TreeNode* buildTree(ListNode*& head, int lo, int hi){
        if(lo > hi)
            return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* left = buildTree(head, lo, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = buildTree(head, mid + 1, hi);
        return root;
    }

    int getLen(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }

        return len;
    }
};

int main(){

}