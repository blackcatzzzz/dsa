/*
82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (fast && fast->next){
            if(fast->val == fast->next->val){
                int sameVal = fast->val;
                while(fast && fast->val == sameVal){
                    ListNode* tmp = fast;
                    fast = fast->next;
                    delete tmp;
                    tmp = nullptr;
                }
                slow->next = fast;
            }else{
                slow = slow->next;
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};

int main(){

}