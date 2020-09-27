/*
220. Contains Duplicate III
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
 

Constraints:

0 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 104
0 <= t <= 231 - 1
*/

#include "common.h"

class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        for(int i = 0; i < nums.size(); i++){
            auto lo = window.lower_bound((long long)nums[i] - (long long)t);
            if(lo != window.end() && *lo <= (long long)nums[i] + (long long)t)
                return true;

            window.insert(nums[i]);
            if(window.size() > k)
                window.erase(nums[i - k]);
        }

        return false;
    }
};

// bucket
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> window;
        long long w = (long long)t + 1;
        for(int i = 0; i < nums.size(); i++){
            int idx = getID(nums[i], w);
            if(window.count(idx))
                return true;

            if(window.count(idx - 1) && abs((long long)window[idx - 1] - (long long)nums[i]) <= t)
                return true;

            if(window.count(idx + 1) && abs((long long)window[idx + 1] - (long long)nums[i]) <= t)
                return true;

            window[idx] = nums[i];
            if(window.size() > k)
                window.erase(getID(nums[i - k], w));
        }

        return false;
    }

private:
    int getID(long long x, long long w){
        return x > 0 ? x / w : -(-x / w) - 1;
    }
};

int main(){
    cout << -1 / 3 << "\n";
    Solution S;
    vector<int> nums = {1,5,9,1,5,9};
    cout << S.containsNearbyAlmostDuplicate(nums, 2 ,2147483647);
}