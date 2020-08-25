/*
61. Rotate List
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

#include "common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) 
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * cur = dummy;
        int len = 0;
        while(cur->next){
            len++;
            cur = cur->next;
        }

        ListNode* tail = cur;

        int step = k % len;
        if(step == 0)
            return head;

        step = len - step - 1;
        ListNode* newTail = head;
        while(step--)
            newTail = newTail->next;

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
};

int main(){
    ListNode* head = new ListNode(0);
    ListNode* cur = head->next = new ListNode(1);
    cur = cur->next = new ListNode(2);
    Solution S;
    printList(S.rotateRight(head, 2));
}