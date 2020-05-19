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

int main()
{
	return 0;
}