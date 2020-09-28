/*
234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include "common.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast)
            slow = slow->next;

        ListNode* h2 = reverse(slow);
        ListNode* h1 = head;
        while(h1 && h2){
            if(h1->val != h2->val)
                return false;
            
            h1 = h1->next;
            h2 = h2->next;
        }

        return true;
    }

private:
    ListNode* reverse(ListNode* node){
        if(!node)
            return nullptr;
        ListNode* cur = node;
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

}