/*
146. LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2);// capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

#include "common.h"


class LRUCache{
private:
    struct ListNode{
        int key;
        int value;
        ListNode* pre;
        ListNode* next;
        ListNode(int k = -1, int v = -1):key(k),value(v),pre(nullptr),next(nullptr){}
    };
    

public:
	LRUCache(int capacity):_capacity(capacity),_size(0){
        _head = new ListNode();
        _tail = new ListNode();
        _head->next = _tail;
        _tail->pre = _head;
	}

	int get(int key){
        if(_k2n.find(key) == _k2n.end())
            return -1;
        ListNode* n = _k2n[key];
        remove(n);
        addToHead(n);
        return n->value;
	}

	void put(int key, int value){
        if(_k2n.find(key) == _k2n.end()){
            if(_capacity == _size){
                ListNode* delNode = _tail->pre;
                remove(delNode);
                _k2n.erase(delNode->key);
                delete delNode;
                --_size;
            }
            ListNode* newNode = new ListNode(key, value);
            _k2n[key] = newNode;
            addToHead(newNode);
            ++_size;
        }else{
            ListNode* n = _k2n[key];
            n->value = value;
            remove(n);
            addToHead(n);
        }
	}

private:
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

private:
    ListNode* _head;
    ListNode* _tail;
    int _capacity;
    int _size;
    unordered_map<int, ListNode*> _k2n;
};

int main(){
	LRUCache lruCache(2);
	lruCache.put(1, 1);
	lruCache.put(2, 2);
	cout << "get(1):" << lruCache.get(1) << endl;
	lruCache.put(3, 3);
    cout << "get(2):" << lruCache.get(2) << endl;
	lruCache.put(4, 4);
    cout << "get(1):" << lruCache.get(1) << endl;
    cout << "get(3):" << lruCache.get(3) << endl;
    cout << "get(4):" << lruCache.get(4) << endl;
}