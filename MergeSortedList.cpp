#include <iostream>


/*
*���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;

		if (pHead2 == NULL)
			return pHead1;

		ListNode* head = NULL;
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		ListNode* cur = NULL;
		
		// ���ҵ�������ͷָ��
		if (p1->val <= p2->val)
		{
			head = cur = p1;
			p1 = p1->next;
		}
		else
		{
			head = cur = p2;
			p2 = p2->next;
		}

		while (p1 && p2)
		{
			if (p1->val <= p2->val)
			{
				cur->next = p1;
				cur = p1;
				p1 = p1->next;
			}
			else
			{
				cur->next = p2;
				cur = p2;
				p2 = p2->next;
			}
		}

		if (p1)
			cur->next = p1;
		if (p2)
			cur->next = p2;

		return head;
	}
};

int main()
{
	return 0;
}