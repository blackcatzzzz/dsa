/*
143. Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

#include "common.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head, *fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rHead = reverse(slow);
        ListNode* cur = head;
        ListNode* p1 = head->next, *p2 = rHead;
        while(p1 != slow && p2){
            cur->next = p2;
            p2 = p2->next;
            cur->next->next = p1;
            p1 = p1->next;
            cur = cur->next->next;
        }

        if(p2)
            cur->next = p2;
    }

private:
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

int main(){
    Solution S;
    List* l = new List(1);
    // l->add(2)->add(3)->add(4);
    printList(l->getHead());
    S.reorderList(l->getHead());
    printList(l->getHead());
}