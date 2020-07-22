
/*
503. Next Greater Element II
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

#include "common.h"

class Solution{
public:
    // 栈顶元素是当前栈中最小的元素， 栈顶元素与当前元素比较，遇到“较大数”即找到目标并出栈（让栈下面的数成为栈顶来继续比较)，遇到“较小数”则入栈
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> monoStack;
        
        for(int i = 0; i < 2 * n; i++){
            while(!monoStack.empty() && nums[monoStack.top()] < nums[i % n]){
                res[monoStack.top()] = nums[i % n];
                monoStack.pop();
            }

            monoStack.push(i % n);
        }
        return res;
    }
};

int main(){
    vector<int> nums{5,3,1,2,4};
    Solution S;
    printVector(S.nextGreaterElements(nums));
}