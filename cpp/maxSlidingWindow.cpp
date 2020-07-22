// https://leetcode-cn.com/problems/sliding-window-maximum/

/*
239. Sliding Window Maximum
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*/

#include "common.h"

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int> res;
        if(nums.size() == 0 || k <= 0) return res;
        for(int i = 0; i < nums.size(); i++){
            if(i < k - 1){
                push(nums[i]);
            }else{
                push(nums[i]);
                res.push_back(max());
                pop(nums[i - k + 1]);
            }
        }

        return res;
    }

private:
    void push(int n){
        while(!dq.empty() && dq.back() < n)
            dq.pop_back();
        dq.push_back(n);
    }

    int max(){
        return dq.front();
    }

    void pop(int n){
        if(!dq.empty() && dq.front() == n)
            dq.pop_front();
    }

private:
    deque<int> dq;
};

int main(){
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    Solution S;
    printVector(S.maxSlidingWindow(nums, 3));
}