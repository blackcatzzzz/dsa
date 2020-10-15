/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

#include "common.h"

// space O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        int l_max = height[0];
        int r_max = height[n - 1];
        int left = 0, right = n - 1;
        int ans = 0;
        while(left <= right){
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);

            if(l_max < r_max){
                ans += l_max - height[left];
                left++;
            }else{
                ans += r_max - height[right];
                right--;
            }
        }

        return ans;
    }
};

// 空间O(N)
class Solution_O_N {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        vector<int> l_max(n, 0), r_max(n, 0);
        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++)
            l_max[i] = max(l_max[i - 1], height[i]);

        for(int i = n - 2; i >= 0; i--)
            r_max[i] = max(r_max[i + 1], height[i]);

        int ans = 0;
        for(int i = 1; i < n - 1; i++)
            ans += min(l_max[i], r_max[i]) - height[i];

        return ans;
    }
};

int main(){

}