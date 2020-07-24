#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;

		ListNode * prev = NULL;
		ListNode * cur = pHead;
		ListNode * temp = NULL;

		while (cur != NULL)
		{
			temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}

		return prev;
	}
};

class Solution_Recursion {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (!pHead || !pHead->next) return pHead;
		ListNode* last = ReverseList(pHead->next);
		pHead->next->next = pHead;
		pHead->next = NULL;

		return last;
	}	
};

int main()
{
	ListNode* cur = nullptr;
	ListNode* head = cur = new ListNode(1);
	cur = cur->next = new ListNode(2);
	cur = cur->next = new ListNode(3);
	printList(head);

	Solution_Recursion SR;
	ListNode* reverseHead = SR.ReverseList(head);
	printList(reverseHead);

	return 0;
}