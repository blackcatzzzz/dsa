/*
203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur->next){
            if(cur->next->val != val){
                cur = cur->next;
                continue;
            }else{
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                tmp = nullptr;
            }
        }
        return dummy->next;
    }
};

int main(){

}