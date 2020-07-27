
/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

#include "common.h"

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        int left = 0;
        int right = height.size() - 1;

        int l_max = 0, r_max = 0;
        int ans = 0;

        while(left <= right){
            l_max = std::max(l_max, height[left]);
            r_max = std::max(r_max, height[right]);
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

int main(){
    vector<int> heights{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution S;
    cout << S.trap(heights) << endl;
}