// Source : https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban



#include "common.h"

vector<vector<int>> res;

void backtrack(vector<int>& nums, vector<int>& track){
    if(nums.size() == track.size()){
        res.push_back(track);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(find(track.begin(), track.end(), nums[i]) != track.end())
            continue;
        track.push_back(nums[i]);
        backtrack(nums, track);
        track.pop_back();
    }
}

/* 主函数，输入一组不重复的数字，返回它们的全排列 */
vector<vector<int>> permute(vector<int>& nums) {
    // 记录「路径」
    vector<int> track;
    backtrack(nums, track);
    return res;
}

int main(){
    vector<int> nums{1,2,3};
    permute(nums);

    for(vector<int> v: res){
        for(int a:v)
            cout << a << " ";
        cout << endl;
    }
}