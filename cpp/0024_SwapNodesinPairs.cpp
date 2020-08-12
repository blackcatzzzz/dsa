/*
24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

#include "common.h"

class Solution_Recursion {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;
        while(head && head->next){
            ListNode* first = head;
            ListNode* second = head->next;
            
            pre->next = second;
            first->next = second->next;
            second->next = first;
            
            pre = first;
            head = first->next;
        }

        return dummy->next;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    cur = cur->next = new ListNode(2);
    cur = cur->next = new ListNode(3);
    cur = cur->next = new ListNode(4);
    Solution S;
    printList(S.swapPairs(head));
}