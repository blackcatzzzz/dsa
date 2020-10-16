/*
239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
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
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include "common.h"

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i < k - 1){
                push(nums[i]);
            }else{
                push(nums[i]);
                ans.push_back(max());
                pop(nums[i - k + 1]);
            }
        }
        return ans;
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
    Solution S;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    printVector(S.maxSlidingWindow(nums, 3));
}