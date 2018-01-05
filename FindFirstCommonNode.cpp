#include <stack>

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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		return solutionByGetLength(pHead1, pHead2);
	}

private:
	ListNode* solutionByStack(ListNode* pHead1, ListNode* pHead2)
	{
		stack<ListNode*> stack1;
		stack<ListNode*> stack2;
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		while (p1)
		{
			stack1.push(p1);
			p1 = p1->next;
		}

		while (p2)
		{
			stack2.push(p2);
			p2 = p2->next;
		}

		ListNode* firstCommonNode = NULL;
		while (!stack1.empty() && !stack2.empty())
		{
			if (stack1.top() == stack2.top())
			{
				firstCommonNode = stack1.top();
				stack1.pop();
				stack2.pop();
			}
			else
				break;

		}

		return firstCommonNode;
	}

	ListNode* solutionByGetLength(ListNode* pHead1, ListNode* pHead2)
	{
		int len1 = getListLength(pHead1);
		int len2 = getListLength(pHead2);

		ListNode* fast = NULL;
		ListNode* slow = NULL;
		int difLength = 0;

		if (len1 > len2)
		{
			fast = pHead1;
			slow = pHead2;
			difLength = len1 - len2;
		}
		else
		{
			fast = pHead2;
			slow = pHead1;
			difLength = len2 - len1;
		}

		while (difLength-- > 0)
			fast = fast->next;

		while (fast && slow && fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return fast;
	}

	int getListLength(ListNode* head)
	{
		int len = 0;
		while (head)
		{
			len++;
			head = head->next;
		}

		return len;
	}
};

void printList(ListNode* head)
{
	while (head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}


ListNode * addListNode(ListNode* head, int e)
{
	if (head == NULL)
		return head = new ListNode(e);
	ListNode* p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = new ListNode(e);

	return head;
}

ListNode * addNodeFromOtherListNode(ListNode* head, ListNode* head1, int pos)
{
	ListNode* p = head;
	while (p->next != NULL)
		p = p->next;

	ListNode* p1 = head1;
	while (pos-- > 0 && p1)
	{
		p1 = p1->next;
	}

	p->next = p1;

	return head;
}

int main()
{
	ListNode* pHead1 = NULL, *pHead2 = NULL;
	pHead1 = addListNode(pHead1, 1);
	addListNode(pHead1, 2);
	addListNode(pHead1, 3);
	addListNode(pHead1, 4);
	addListNode(pHead1, 5);
	pHead2 = addListNode(pHead2, 6);
	addListNode(pHead2, 7);
	addListNode(pHead2, 8);
	addNodeFromOtherListNode(pHead2, pHead1, 3);
	printList(pHead1);
	printList(pHead2);

	Solution s;
	printList(s.FindFirstCommonNode(pHead1, pHead2));
	getchar();
	return 0;
}

