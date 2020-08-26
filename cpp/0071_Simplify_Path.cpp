/*
71. Simplify Path
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/

#include "common.h"

class Solution {
public:
    string simplifyPath(string path) {
        // 0: last char is char
        // 1: last char is /
        // 2：last char is .
        // 3: last char is ..
        int state = 0;
        string res;
        for(auto c : path){
            if(state == 0){
                if(c == '/'){
                    res.push_back(c);
                    state = 1;
                }else
                    res.push_back(c);
            }else if(state == 1){
                if(c == '/'){
                    continue;
                }else if(c == '.'){
                    state = 2;
                }else{
                    res.push_back(c);
                    state = 0;
                }
            }else if(state == 2){
                if(c == '/'){
                    state = 1;
                }else if(c == '.'){
                    state = 3;
                }else{
                    state = 0;
                    res.push_back('.');
                    res.push_back(c);
                }
            }else{
                if(c == '/'){
                    res.pop_back();
                    while(res.size() && *res.rbegin() != '/')
                        res.pop_back();
                    state = 1;

                    // 回退为空，补'/'
                    if(!res.size())
                        res.push_back('/');
                }else{
                    state = 0;
                    res.push_back('.');
                    res.push_back('.');
                    res.push_back(c);
                }
            }
        }

        // 处理'/' '/a/b/c/..'
        if(state == 3 && res.size() != 1){
            res.pop_back();
            while(res.size() && *res.rbegin() != '/')
                res.pop_back();       
        }

        if(res.size() != 1 && *res.rbegin() == '/')
            res.pop_back();

        return res;
    }
};

int main(){
    string s = "/a//b////c/d//././/..";
    Solution S;

    cout << S.simplifyPath(s);
}