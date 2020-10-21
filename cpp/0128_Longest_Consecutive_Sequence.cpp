/*
128. Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

#include "common.h"

// union find set O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) 
            return 0;

        for(auto& num : nums){
            uf[num] = num;
            cnt[num] = 1;
        }
            
        int ans = 1;
        for(auto& num : nums){
            if(num != INT_MAX && uf.count(num + 1))
                ans = max(ans, unionSet(num , num + 1));
        }

        return ans;
    }

private:
    unordered_map<int, int> uf, cnt;

    int find(int p){
        int root = p;
        while(root != uf[root])
            root = uf[root];

        while(uf[p] != p){
            int cur = p;
            p = uf[p];
            uf[cur] = root;
        }

        return root;
    }

    int unionSet(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);

        if(rootP == rootQ)
            return cnt[rootP];
        
        // p < q
        uf[q] = rootP;
        cnt[rootP] += cnt[rootQ];

        return cnt[rootP];
    }
};

// O(N)
class Solution_Hash {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(auto& num : nums)
            nums_set.insert(num);

        int ans = 0;
        for(auto& num : nums){
            if(nums_set.count(num - 1))
                continue;
            
            int r = num;
            while(nums_set.count(r + 1))
                r++;

            ans = max(ans, r - num + 1);
        }

        return ans;
    }
};

int main(){

}