/*
127. Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

#include "common.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();
        unordered_map<string, vector<string>> allComboDict;
        for(auto word : wordList){
            for(int i = 0; i < len; i++){
                string newWord = word.substr(0, i) + "*" + word.substr(i + 1);
                allComboDict[newWord].push_back(word);
            }
        }

        unordered_map<string, bool> visited;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            pair<string, int> node = q.front();
            q.pop();
            for(int i = 0; i < len; i++){
                string newWord = node.first.substr(0, i) + "*" + node.first.substr(i + 1);
                for(auto adjacentWord : allComboDict[newWord]){
                    if(visited[adjacentWord])
                        continue;
                    visited[adjacentWord] = true;
                    if(adjacentWord == endWord)
                        return node.second + 1;
                    q.push({adjacentWord, node.second + 1});
                }
            }
        }

        return 0;
    }
};

int main(){
    Solution S;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    cout << S.ladderLength(beginWord, endWord, wordList) << endl;
}