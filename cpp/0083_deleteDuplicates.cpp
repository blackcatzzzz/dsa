
/*
83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* slow = head, *fast = head->next;
        while(fast){
            if(slow->val == fast->val){
                ListNode* toDel = fast;
                fast = fast->next;
                delete toDel;
                toDel = nullptr;
            }else{
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            }
        }

        slow->next = nullptr;
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    cur = cur->next = new ListNode(1);
    cur = cur->next = new ListNode(2);
    // cur = cur->next = new ListNode(3);
    // cur = cur->next = new ListNode(3);

    Solution S;
    printList(S.deleteDuplicates(head));
}