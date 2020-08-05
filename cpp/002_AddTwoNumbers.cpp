
/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* pre = new ListNode(-1);
        ListNode* cur = pre;
        while(l1 || l2){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            sum = n1 + n2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        if(carry)
            cur->next = new ListNode(1);

        return pre->next;
    }
};

int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* c1 = l1;
    c1 = c1->next = new ListNode(2);
    // c1 = c1->next = new ListNode(3);

    ListNode* l2 = new ListNode(4);
    ListNode* c2 = l2;
    c2 = c2->next = new ListNode(5);
    c2 = c2->next = new ListNode(6);

    Solution S;
    printList(S.addTwoNumbers(l1, l2));
}