/*
119. Pascal's Triangle II
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 40
*/

#include "common.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        for(int i = 0; i < rowIndex + 1; i++){
            for(int j = i; j >= 0; j--){
                if(i == 0 || j == 0 || j == i)
                    res[j] = 1;
                else
                    res[j] = res[j] + res[j - 1];
            }
        }

        return res;
    }
};

int main(){
    Solution S;
    printVector(S.getRow(5));
}