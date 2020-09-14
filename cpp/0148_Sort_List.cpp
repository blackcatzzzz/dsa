/*
148. Sort List
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 

        ListNode* other = slow->next;
        slow->next = nullptr;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(other);
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(h1 && h2){
            if(h1->val <= h2->val){
                curr->next = h1;
                h1 = h1->next;
            }else{
                curr->next = h2;
                h2 = h2->next;
            }

            curr = curr->next;
        }

        curr->next = h1 ? h1 : h2;
        return dummy->next;
    }
};

int main(){
    List* l = new List(4);
    l->add(1)->add(2)->add(3);
    Solution S;
    printList(S.sortList(l->getHead()));
}