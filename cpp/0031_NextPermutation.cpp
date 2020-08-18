/*
31. Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include "common.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        
        if(i == -1){
            reverse(nums, 0, nums.size() - 1);
            return;
        }

        int j = nums.size() - 1;
        while(j > i){
            if(nums[j] > nums[i])
                break;
            j--;
        }

        swap(nums[i], nums[j]);
        reverse(nums, i + 1, nums.size() - 1);
        return;
    }

    void reverse(vector<int>& nums, int i, int j){
        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};

int main(){
    Solution S;
    vector<int> nums{1, 5, 8, 7, 3, 2};
    S.nextPermutation(nums);
    printVector(nums);
}