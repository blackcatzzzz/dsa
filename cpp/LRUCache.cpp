#include <iostream>
#include <map>

using namespace std;

struct ListNode
{
	int key;
	int value;
	ListNode* next;
	ListNode* pre;
	ListNode(int k = -1, int v = -1):key(k),value(v),next(nullptr),pre(nullptr){}
};

class LRUCache
{
private:
	int _capacity;
	int _size;
	map<int, ListNode*> _k2n;
	ListNode* _head;
	ListNode* _tail;

	void remove(ListNode* n)
	{
		n->pre->next = n->next;
		n->next->pre = n->pre;
	}

	void addToHead(ListNode* n)
	{
		n->next = _head->next;
		n->pre = _head;

		_head->next->pre = n;
		_head->next = n;
		
	}

public:
	LRUCache(int capacity)
		:_capacity(capacity),_size(0)
	{
		_head = new ListNode(); // 哨兵节点
		_tail = new ListNode();

		_head->next = _tail;
		_head->pre = nullptr;

		_tail->pre = _head;
		_tail->next = nullptr;
	}

	int get(int key)
	{
		//if (!_k2n.count(key))
		if(_k2n.find(key) == _k2n.end())
		{
			return -1;
		}

		ListNode* n = _k2n[key];
		remove(n);
		addToHead(n);
		return n->value;
	}

	void set(int key, int value)
	{
		if (get(key) == -1) // 未命中
		{
			if (_capacity == _size)
			{
				ListNode* n = _tail->pre; // 最老的节点
				remove(n);
				_k2n.erase(n->key);
				delete n;
				--_size;
			}

			ListNode* newNode = new ListNode(key, value);
			addToHead(newNode);
			_k2n[key] = newNode;
			++_size;
		}
		else
			_k2n[key]->value = value;
	}

	void print()
	{
		ListNode* p = _head->next;

		cout << "========LRU:=========" << endl;
		while (p != _tail)
		{
			cout << p->key << "," << p->value << endl;
			p = p->next;
		}
		cout << endl;
	}
};

int main()
{
	LRUCache lruCache(6);
	lruCache.set(1, 1);
	lruCache.set(2, 2);

	lruCache.print();

	cout << "get(1):" << lruCache.get(1) << endl;

	lruCache.print();

	lruCache.set(3, 3);

	lruCache.print();

	lruCache.set(4, 4);
	lruCache.set(5, 5);
	lruCache.set(6, 6);
	
	lruCache.print();

	lruCache.set(7, 7);
	lruCache.print();

	lruCache.set(1, 11);
	lruCache.print();

	getchar();
	return 0;
}