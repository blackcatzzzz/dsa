

#include "common.h"

// 异或
int missingNumber(vector<int>& nums){
    int n = nums.size();
    int res = 0;
    res ^= n;
    for(int i = 0; i < n; i++){
        res ^= i ^ nums[i];
    }

    return res;
}

// 等差数列 expect - sum

int main(){
    vector<int> nums{1,4,2,0};
    cout << missingNumber(nums) << endl;
}