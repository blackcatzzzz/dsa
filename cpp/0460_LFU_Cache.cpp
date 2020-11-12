/*
460. LFU Cache
Design and implement a data structure for Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Sets or inserts the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be evicted.
Notice that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.

Follow up:
Could you do both operations in O(1) time complexity?

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
LFUCache lFUCache = new LFUCache(2);
lFUCache.put(1, 1);
lFUCache.put(2, 2);
lFUCache.get(1);      // return 1
lFUCache.put(3, 3);   // evicts key 2
lFUCache.get(2);      // return -1 (not found)
lFUCache.get(3);      // return 3
lFUCache.put(4, 4);   // evicts key 1.
lFUCache.get(1);      // return -1 (not found)
lFUCache.get(3);      // return 3
lFUCache.get(4);      // return 4

 

Constraints:

0 <= capacity, key, value <= 104
At most 105 calls will be made to get and put.
*/

#include "common.h"

class LFUCache {
public:
    LFUCache(int capacity):capacity(capacity), minFreq(0) {

    }
    
    int get(int key) {
        auto it = key_table.find(key);
        if(it == key_table.end())
            return -1;
        
        list<Node>::iterator node = it->second;
        int freq = node->freq, value = node->value;
        freq_table[freq].erase(node);

        if(freq_table[minFreq].size() == 0){
            freq_table.erase(minFreq);
            if(minFreq == freq)
                minFreq++;
        }

        freq_table[freq + 1].push_front(Node(key, value, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return value;
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;
        auto it = key_table.find(key);
        if(it == key_table.end()){
            if(capacity == key_table.size()){
                Node node = freq_table[minFreq].back();
                key_table.erase(node.key);
                freq_table[minFreq].pop_back();
                if(freq_table[minFreq].size() == 0){
                    freq_table.erase(minFreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minFreq = 1;
        }else{
            list<Node>::iterator node = it->second;
            int freq = node->freq;
            freq_table[freq].erase(node);

            if(freq_table[minFreq].size() == 0){
                freq_table.erase(minFreq);
                if(minFreq == freq)
                    minFreq++;
            }

            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();        
        }
    }

private:
    struct Node {
        int key;
        int value;
        int freq;

        Node(int key, int val, int freq):key(key),value(val), freq(freq){}
    };

    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
    int minFreq, capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LFUCache lFUCache(2);
    lFUCache.put(1, 1);
    lFUCache.put(2, 2);
    lFUCache.get(1);      // return 1
    lFUCache.put(3, 3);   // evicts key 2
    lFUCache.get(2);      // return -1 (not found)
    lFUCache.get(3);      // return 3
    lFUCache.put(4, 4);   // evicts key 1.
    lFUCache.get(1);      // return -1 (not found)
    lFUCache.get(3);      // return 3
    lFUCache.get(4);      // return 4
}