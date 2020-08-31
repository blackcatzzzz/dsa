/*
86. Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while(pre && pre->next){
            if(pre->next->val >= x)
                break;
            pre = pre->next;
        }

        if(!pre || !pre->next)
            return head;

        ListNode* pivot = pre->next;
        // cout << "pivot:" << pivot->val << endl;

        ListNode* lessNodePre = pre;  // 小于pivot节点的前节点指针
        while (lessNodePre && lessNodePre->next){
            if(lessNodePre->next->val < x){
                pre->next = lessNodePre->next;
                lessNodePre->next = lessNodePre->next->next;
                pre->next->next = pivot;

                pre = pre->next;
            }else
                lessNodePre = lessNodePre->next;
        }
        
        return dummy->next;
    }
};
// 3,1,2  3
void test1(){
    Solution S;
    ListNode* head = new ListNode(3);
    ListNode* cur = head;
    cur = cur->next = new ListNode(1);
    cur = cur->next = new ListNode(2);

    printList(S.partition(head, 3));
}


int main(){
    test1();
    Solution S;
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    cur = cur->next = new ListNode(4);
    cur = cur->next = new ListNode(3);
    cur = cur->next = new ListNode(2);
    cur = cur->next = new ListNode(5);
    cur = cur->next = new ListNode(2);

    printList(S.partition(head, 3));
}