#include <iostream>


/*
* LeetCode 82
* JZOffer 57
* ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
* ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
	// �Լ��ⷨ
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;

		ListNode* dummy = new ListNode(0);
		dummy->next = pHead;
		ListNode* prev = dummy; // ǰ��ָ�룬ָ��ɾ�����������һ�������ڵ�(���ظ���)
		ListNode* cur = pHead; // ��ǰָ�룬ָ����ȽϵĽڵ�

		while (cur)
		{
			if (cur->next && cur->val == cur->next->val) // �����ǰ�ڵ�����һ���ڵ����
			{
				cur = cur->next;
				while (cur->next && cur->val == cur->next->val) // cur = cur->next,��ǰָ��������ֱ������һ���ڵ㲻��
					cur = cur->next;
				prev->next = cur->next; // �����м��ظ��Ľڵ�
				cur = cur->next; // ָ����һ�����ȽϽڵ�
			}
			else // ��ǰ�ڵ�����һ���ڵ㲻���
			{
				prev = cur; // prev�����ƣ�ָ��ǰ������ظ��ĵ�
				cur = cur->next; //curָ����һ�����Ƚϵĵ�
			}
		}

		return dummy->next;
	}
};

// LeetCode�ⷨ
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