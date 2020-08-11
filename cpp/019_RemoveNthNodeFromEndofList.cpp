/*
19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n <= 0) return head;
        ListNode* fast = head, *slow = head;
        while(n--)
            fast = fast->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        if(fast){
            ListNode* tmp = slow->next;
            slow->next = slow->next->next;
            delete tmp;
            tmp = nullptr;
        }else{
            head = slow->next;
            delete slow;
            slow = nullptr;
        }

        return head;
    }
};

int main(){

}