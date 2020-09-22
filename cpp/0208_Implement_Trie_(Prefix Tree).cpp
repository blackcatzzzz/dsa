/*
208. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

#include "common.h"

class Trie {

private:
    class TrieNode{
    public:
        TrieNode(){
            links = vector<TrieNode*>(26, nullptr);
            _isEnd = false;
        }

        bool containsKey(char ch){
            return links[ch - 'a'];
        }

        TrieNode* get(char ch){
            return links[ch - 'a'];
        }

        void put(char ch, TrieNode* node){
            links[ch - 'a'] = node;
        }

        void setEnd(){
            _isEnd = true;
        }

        bool isEnd(){
            return _isEnd;
        }

    private:
        vector<TrieNode*> links;
        bool _isEnd;
    };

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(auto& ch : word){
            if(!node->containsKey(ch)){
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node && node->isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchPrefix(prefix);
    }

private:
    TrieNode* searchPrefix(const string& word){
        TrieNode* node = root;
        for(auto& ch: word){
            if(!node->containsKey(ch))
                return nullptr;
            node = node->get(ch);
        }

        return node;
    }

private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;     // returns false
    cout << trie->startsWith("app") << endl; // returns true
    trie->insert("app");   
    cout << trie->search("app") << endl;     // returns true
}