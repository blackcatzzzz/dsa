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

// ע������������(k<=0), (4,{1,2,3})
class Solution1 {
public:
	// ��ָ������K����Ȼ�����ָ��ͬʱ�ߣ���ָ�뵽��NULLʱ(ĩβ�ڵ����һ��λ��)����ָ����ǵ���K�ڵ�λ��
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k <= 0)
			return NULL;

		ListNode* fast = pListHead;
		while (k-- > 0)
		{
			fast = fast->next;
			// ��k���ڽڵ���ʱ��������Чָ�����
			if (!fast)
			{
				// ��fast�ߵ�ĩβ��ʱ��k > 0 �� ����null
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