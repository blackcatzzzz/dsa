/*
60. Permutation Sequence
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

#include "common.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        _n = n;
        _k = k;
        factorial = vector<int>(n + 1, 1);
        for(int i = 1; i <= n; i++)
            factorial[i] = factorial[i - 1] * i;

        vector<bool> used(n, false);

        dfs(1, used);
        return res;
    }

private:
    void dfs(int index, vector<bool>& used){
        if(res.size() == _n)
            return;

        int cnt = factorial[_n - index];
        for(int i = 1; i <= _n; i++){
            if(used[i - 1])
                continue;

            if(cnt < _k){
                _k -= cnt;
                continue;
            }

            res.push_back(i + '0');
            used[i - 1] = true;
            dfs(index + 1, used);
        }

        return;
    }

private:
    int _k;
    int _n;
    string res;
    vector<int> factorial;
};

int main(){
    Solution S;
    cout << S.getPermutation(3, 6);
}