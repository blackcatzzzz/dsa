/*
215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include "common.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    int quickSelect(vector<int>& nums, int lo, int hi, int index){
        int q = patition(nums, lo, hi);
        if(q == index)
            return nums[q];

        if(index > q)
            return quickSelect(nums, q + 1, hi, index);
        else
            return quickSelect(nums, lo, q - 1, index);
    }

    int patition(vector<int>& nums, int lo, int hi){
        int i = lo, j = hi;
        int pivot = nums[i];
        while(i < j){
            while(i < j && nums[j] >= pivot)
                j--;

            swap(nums[i], nums[j]);

            while(i < j && nums[i] <= pivot)
                i++;

            swap(nums[i], nums[j]);
        }

        return i;
    }
};

int main(){
    Solution S;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << S.findKthLargest(nums, 4);
}