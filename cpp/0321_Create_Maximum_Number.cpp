/*
321. Create Maximum Number
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]
*/

#include "common.h"

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        for(int i = max(0, k - n); i <= min(m, k); i++){
            vector<int> nums1_seq = maxSequence(nums1, i);
            vector<int> nums2_seq = maxSequence(nums2, k - i);
            vector<int> merged_seq = merge(nums1_seq, nums2_seq);
            ans = compare(ans, merged_seq, 0, 0) ? ans : merged_seq;
        }

        return ans;
    }

private:
    vector<int> maxSequence(vector<int>& nums, int k){
        if(k <= 0)
            return {};
        stack<int> stk;
        int n = nums.size() - k;
        for(int i = 0; i < nums.size(); i++){
            while(!stk.empty() && stk.top() < nums[i] && n-- > 0){
                stk.pop();
            }
            stk.push(nums[i]);
        }

        while(stk.size() > k)
            stk.pop();
        vector<int> res(k, 0);
        int pos = k - 1;
        while(!stk.empty()){
            res[pos--] = stk.top();
            stk.pop();
        }

        return res;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] > nums2[j])
                res.push_back(nums1[i++]);
            else if(nums1[i] < nums2[j])
                res.push_back(nums2[j++]);
            else{
                if(compare(nums1, nums2, i + 1, j + 1))
                    res.push_back(nums1[i++]);
                else
                    res.push_back(nums2[j++]);
            }

        }

        while(i < nums1.size())
            res.push_back(nums1[i++]);

        while(j < nums2.size())
            res.push_back(nums2[j++]);

        return res;
    }

    // if nums1 >= nums2 return true (nums1.size() == nums2.size())
    bool compare(vector<int> nums1, vector<int> nums2, int i, int j){
        for(;i < nums1.size() && j < nums2.size(); i++, j++){
            if(nums1[i] == nums2[j])
                continue;

            if(nums1[i] > nums2[j])
                return true;
            else
                return false;      
        }

        return j == nums2.size();
    }
};

int main(){
    vector<int> nums1 = {2,5,6,4,4,0};
    vector<int> nums2 = {7,3,8,0,6,5,7,6,2};
    Solution S;
    printVector(S.maxNumber(nums1, nums2, 15));
}