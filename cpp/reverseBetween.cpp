

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
    // Solution(): successor(nullptr){
    // }

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