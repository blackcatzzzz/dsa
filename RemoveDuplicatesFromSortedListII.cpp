#include <iostream>


/*
* LeetCode 82
* JZOffer 57
* 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
* 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	// 自己解法
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;

		ListNode* dummy = new ListNode(0);
		dummy->next = pHead;
		ListNode* prev = dummy; // 前置指针，指向删除过程中最后一个保留节点(不重复的)
		ListNode* cur = pHead; // 当前指针，指向待比较的节点

		while (cur)
		{
			if (cur->next && cur->val == cur->next->val) // 如果当前节点与下一个节点相等
			{
				cur = cur->next;
				while (cur->next && cur->val == cur->next->val) // cur = cur->next,当前指针往后移直到与下一个节点不等
					cur = cur->next;
				prev->next = cur->next; // 跳过中间重复的节点
				cur = cur->next; // 指向下一个待比较节点
			}
			else // 当前节点与下一个节点不相等
			{
				prev = cur; // prev往后移，指向当前这个不重复的点
				cur = cur->next; //cur指向下一个待比较的点
			}
		}

		return dummy->next;
	}
};

// LeetCode解法
class Solution1 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* cur = dummy;
		int duplicate;
		while (cur->next && cur->next->next) {
			if (cur->next->val == cur->next->next->val) {
				duplicate = cur->next->val;
				while (cur->next && cur->next->val == duplicate) {
					cur->next = cur->next->next;
				}
			}
			else {
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};

int main()
{
	return 0;
}