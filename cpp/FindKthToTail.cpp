#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* pAhead = pListHead;
		for (int i = 0; i < k - 1; ++i)
		{
			if (!(pAhead = pAhead->next))
				return NULL;
		}


		ListNode* pBehind = pListHead;
		while (pAhead = pAhead->next)
			pBehind = pBehind->next;

		return pBehind;
	}
};

// 注意特殊用例，(k<=0), (4,{1,2,3})
class Solution1 {
public:
	// 快指针先走K步，然后快慢指针同时走，快指针到达NULL时(末尾节点后面一个位置)，慢指针就是倒数K节点位置
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k <= 0)
			return NULL;

		ListNode* fast = pListHead;
		while (k-- > 0)
		{
			fast = fast->next;
			// 当k大于节点数时，避免无效指针出错
			if (!fast)
			{
				// 当fast走到末尾后时，k > 0 则 返回null
				if (k > 0)
					return NULL;
				else
					break;
			}
		}

		ListNode* slow = pListHead;
		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow;
	}
};

int main()
{
	Solution1 s1;
	ListNode* head = new ListNode(1);
	ListNode* n2 = head->next = new ListNode(2);
	ListNode* n3 = n2->next = new ListNode(3);
	ListNode* k = s1.FindKthToTail(head, 4);
	getchar();
	return 0;
}