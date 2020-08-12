
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 0) return head;

        ListNode* a = head, *b = head;
        for(int i = 0; i < k; i++){
            if(!b) return head;
            b = b->next;
        }

        ListNode* newHead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }

private:
    // reverse [a,b)
    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode* cur = a;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(cur != b){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};