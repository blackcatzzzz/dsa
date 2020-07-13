// Source: https://leetcode.com/problems/lru-cache/


// 146. LRU Cache

// Medium

// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// The cache is initialized with a positive capacity.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4


#include "common.h"

class LRUCache
{
private:
	struct ListNode{
		int key;
		int value;
		ListNode* next;
		ListNode* pre;
		ListNode(int k = -1, int v = -1):key(k),value(v),next(nullptr),pre(nullptr){}
	};

	int _capacity;
	int _size;
	map<int, ListNode*> _k2n;
	ListNode* _head;
	ListNode* _tail;

	void remove(ListNode* n){
		n->pre->next = n->next;
		n->next->pre = n->pre;
	}

	void addToHead(ListNode* n){
		n->next = _head->next;
		n->pre = _head;

		_head->next->pre = n;
		_head->next = n;
	}

public:
	LRUCache(int capacity)
		:_capacity(capacity),_size(0){
		_head = new ListNode(); // 哨兵节点
		_tail = new ListNode();

		_head->next = _tail;
		_head->pre = nullptr;

		_tail->pre = _head;
		_tail->next = nullptr;
	}

	int get(int key){
		//if (!_k2n.count(key))
		if(_k2n.find(key) == _k2n.end()){
			return -1;
		}

		ListNode* n = _k2n[key];
		remove(n);
		addToHead(n);
		return n->value;
	}

	void put(int key, int value){
		if (get(key) == -1) {
			if (_capacity == _size) {
				ListNode* n = _tail->pre;
				remove(n);
				_k2n.erase(n->key);
				delete n;
				--_size;
			}

			ListNode* newNode = new ListNode(key, value);
			addToHead(newNode);
			_k2n[key] = newNode;
			++_size;
		}else{
			ListNode * n = _k2n[key];
			remove(n);
			addToHead(n);
			n->value = value;
		}
	}

	void print(){
		ListNode* p = _head->next;

		cout << "========LRU:=========" << endl;
		while (p != _tail){
			cout << p->key << "," << p->value << endl;
			p = p->next;
		}
		cout << endl;
	}
};

// 使用std::list
class LRUCache_L {
    size_t m_capacity;
    unordered_map<int,  list<pair<int, int>>::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
    list<pair<int, int>> m_list;                               //m_list_iter->first: key, m_list_iter->second: value;
public:
    LRUCache_L(size_t capacity):m_capacity(capacity) {
    }
    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) //key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == m_capacity) //reached capacity
        {
           int key_to_del = m_list.back().first; 
           m_list.pop_back();            //remove node in list;
           m_map.erase(key_to_del);      //remove key in map
        }
        m_list.emplace_front(key, value);  //create new node in list
        m_map[key] = m_list.begin();       //create correspondence between key and node
    }
};

int main()
{
	LRUCache lruCache(6);
	lruCache.put(1, 1);
	lruCache.put(2, 2);

	lruCache.print();

	cout << "get(1):" << lruCache.get(1) << endl;

	lruCache.print();

	lruCache.put(3, 3);

	lruCache.print();

	lruCache.put(4, 4);
	lruCache.put(5, 5);
	lruCache.put(6, 6);
	
	lruCache.print();

	lruCache.put(7, 7);
	lruCache.print();

	lruCache.put(1, 11);
	lruCache.print();

	getchar();
	return 0;
}