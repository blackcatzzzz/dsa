/*
1299. Replace Elements with Greatest Element on Right Side
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

#include "common.h"

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        for(int i = arr.size() - 1; i >= 0; i--){
            if(arr[i] > max || i == arr.size() - 1){
                swap(arr[i], max);
            }else{
                 arr[i] = max;
            }
        }

        return arr;
    }
};

void main(){
    Solution S;
    vector<int> arr = {17,18,5,4,6,1};
    printVector(S.replaceElements(arr));
}