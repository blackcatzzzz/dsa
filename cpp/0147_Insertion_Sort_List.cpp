/*
147. Insertion Sort List
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* sortedTail = head;
        ListNode* curr = head->next;
        while(curr){
            if(curr->val < sortedTail->val){
                ListNode* insertPos = dummy;
                while(insertPos->next->val < curr->val)
                    insertPos = insertPos->next;
                sortedTail->next = curr->next;

                curr->next = insertPos->next;
                insertPos->next = curr;

                curr = sortedTail->next;
            }else{
                sortedTail = curr;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};

class Solution_Recursive {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* sortedHead = insertionSortList(head->next);
        head->next = sortedHead;
        ListNode* newHead = nullptr;
        if(head->val <= sortedHead->val)
            newHead = head;
        else
            newHead = sortedHead;
        
        ListNode* curr = sortedHead;
        ListNode* insertPos = nullptr;
        while(curr && curr->val < head->val){
            insertPos = curr;
            curr = curr->next;
        }

        if(insertPos){
            head->next = insertPos->next;
            insertPos->next = head;
        }
        
        return newHead;
    }
};


int main(){
    Solution S;
    List* l = new List(4);
    l->add(2)->add(1)->add(3);
    printList(S.insertionSortList(l->getHead()));
}