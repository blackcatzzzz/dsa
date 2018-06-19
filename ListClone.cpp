#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return pHead;
		// 1.复制各节点值，next指针链接
		map<RandomListNode*, RandomListNode*> mapOld2New;
		RandomListNode* newHead = NULL;
		RandomListNode* pOld = pHead;
		newHead = new RandomListNode(pOld->label);
		RandomListNode* pNew = newHead;
		mapOld2New.insert(pair<RandomListNode*, RandomListNode*>(pOld, pNew));
		while (pOld = pOld->next)
		{
			pNew->next = new RandomListNode(pOld->label);
			pNew = pNew->next;
			mapOld2New.insert(pair<RandomListNode*, RandomListNode*>(pOld, pNew));
		}

		// 2.复制random
		pOld = pHead;
		pNew = newHead;
		while (pOld)
		{
			pNew->random = mapOld2New[pOld->random];
			pOld = pOld->next;
			pNew = pNew->next;
		}

		return newHead;
	}
};

// 2018.6.16
class Solution1 {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		RandomListNode* old = pHead;
		RandomListNode* newHead = new RandomListNode(old->label);
		map<RandomListNode*, RandomListNode*> old2New;
		//old2New.insert(pair<RandomListNode*, RandomListNode*>(old, newHead));
		old2New[old] = newHead;
		old = old->next;
		RandomListNode* cur = newHead;
		while (old)
		{
			cur->next = new RandomListNode(old->label);
			cur = cur->next;
			//old2New.insert(pair<RandomListNode*, RandomListNode*>(old, cur));
			old2New[old] = cur;
			old = old->next;
		}

		old = pHead;
		RandomListNode* random = NULL;
		while (old)
		{
			cur = old2New[old];
			random = old2New[old->random];
			cur->random = random;
			old = old->next;
		}

		return newHead;
	}
};

int main()
{
	return 0;
}