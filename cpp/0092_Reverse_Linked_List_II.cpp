/*
92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

#include "common.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while(m > 1){
            head = head->next;
            pre = pre->next;
            m--;
            n--;
        }

        pre->next = reverseN(head, n);
        return dummy->next;
    }

private:
    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            successor = head->next;
            return head;
        }

        ListNode* newHead = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return newHead;
    }

private:
    ListNode* successor = nullptr;
};


class Solution1 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == 1){
            return reverseN(head, n);
        }

        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

public:
    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            successor = head->next;
            return head;
        }

        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
private:
    ListNode* successor = nullptr;
};


int main(){
	ListNode* cur = nullptr;
	ListNode* head = cur = new ListNode(1);
	cur = cur->next = new ListNode(2);
	cur = cur->next = new ListNode(3);
	printList(head);

    Solution S;
    ListNode* newHead = S.reverseBetween(head, 2 , 3);
    // ListNode* newHead = S.reverseN(head, 2);
    printList(newHead);
    return 0;
}