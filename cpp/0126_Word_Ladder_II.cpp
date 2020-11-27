/*
126. Word Ladder II
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

#include "common.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> path;
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> allComboDict;

        int len = beginWord.size();

        for(auto & word: wordList){
            for(int i = 0; i < len; i++){
                string newWord = word.substr(0, i) + "*" + word.substr(i + 1);
                allComboDict[newWord].push_back(word);
            }
        }

        unordered_map<string, bool> pre_visited;
        unordered_map<string, bool> next_visited;
        queue<pair<string, vector<string>>> q;
        bool find = false;
        pre_visited[beginWord] = true;
        q.push(make_pair(beginWord, vector<string>(1, beginWord)));
        while(!q.empty() && !find){
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                
                for(int i = 0; i < len; i++){
                    string newWord = node.first.substr(0, i) + "*" + node.first.substr(i + 1);
                    vector<string> adjacentWords = allComboDict[newWord];
                    for(auto& adjacentWord : adjacentWords){
                        if(pre_visited[adjacentWord])
                            continue;
                        
                        vector<string> path(node.second);
                        path.push_back(adjacentWord);
                        if(adjacentWord == endWord){
                            ans.push_back(path);
                            find = true;
                            continue;
                        }

                        next_visited[adjacentWord] = true;
                        q.push(make_pair(adjacentWord, path));
                    }
                }
            }

            for(auto it = next_visited.begin(); it != next_visited.end();it++)
                pre_visited[it->first] = it->second;

            next_visited.clear();
        }

        return ans;
    }

};

// find all
class Solution_All {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        _len = beginWord.size();
        _endWord = endWord;

        for(auto & word: wordList){
            for(int i = 0; i < _len; i++){
                string newWord = word.substr(0, i) + "*" + word.substr(i + 1);
                allComboDict[newWord].push_back(word);
            }
        }

        path.push_back(beginWord);
        dfs(beginWord);

        return ans;
    }

private:
    void dfs(const string& beginWord){
        if(beginWord == _endWord){
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < _len; i++){
            string newWord = beginWord.substr(0, i) + "*" + beginWord.substr(i + 1);
            vector<string> adjacentWords = allComboDict[newWord];
            for(auto& adjacentWord : adjacentWords){
                if(visited[adjacentWord])
                    continue;

                path.push_back(adjacentWord);
                visited[adjacentWord] = true;
                dfs(adjacentWord);
                visited[adjacentWord] = false;
                path.pop_back();
            }
        }
    }

private:
    int _len;
    string _endWord;
    vector<string> path;
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> allComboDict;
    unordered_map<string, bool> visited;
};

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution S;
    vector<vector<string>> ans = S.findLadders(beginWord, endWord, wordList);
    printVectors(ans);
}