#include <iostream>


/*
* һ�������а����������ҳ�������Ļ�����ڽ�㡣
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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead)
			return NULL;

		ListNode* meetingNode = getMeetingNode(pHead);

		if (meetingNode == NULL)
			return NULL;

		int len = getLengthOfLoop(meetingNode);

		return getEntryNodeOfLoop(pHead, len);
	}

private:
	// ����һ���Ȼ�ȡ������len,Ȼ��ahead = pHead����len;
	// behind = pHead �� aheadһ���� ֱ��������
	ListNode* getEntryNodeOfLoop(ListNode* pHead, int len)
	{
		ListNode* ahead = pHead;
		ListNode* behind = pHead;

		while (len-- >0)
			ahead = ahead->next;

		while (ahead != behind)
		{
			ahead = ahead->next;
			behind = behind->next;
		}

		return ahead;
	}

	ListNode* getMeetingNode(ListNode* pHead)
	{
		ListNode* fast = pHead;
		ListNode* slow = pHead;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow)
				return fast;
		}

		return NULL;
	}

	// ��ȡ�����ȣ�����һ
	int getLengthOfLoop(ListNode* meetingNode)
	{
		ListNode* p = meetingNode;
		int len = 0;
		do
		{
			len++;
			p = p->next;
		} while (p != meetingNode);

		return len;
	}

	// ��ȡ�����ȣ�������
	int getLengthOfLoop1(ListNode* meetingNode)
	{
		int len = 0;
		ListNode* fast = meetingNode;
		ListNode* slow = meetingNode;

		do
		{
			++len;
			fast = fast->next->next;
			slow = slow->next;
		} while (fast != slow);

		return len;
	}

};

int main()
{
	return 0;
}