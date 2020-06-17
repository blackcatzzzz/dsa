// Source : https://leetcode.com/problems/pancake-sorting/

/*
969. Pancake Sorting

Medium

Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

 

Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
 

Note:

1 <= A.length <= 100
A[i] is a permutation of [1, 2, ..., A.length]
*/

#include "common.h"

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        sort(A, A.size() - 1);
        return res;
    }

    void sort(vector<int>&A, int n){
        // base case
        if(n == 0) return;

        // 寻找最大饼的索引
        int maxCake = A[0];
        int maxCakeIndex = 0;
        for(int i = 1; i <= n; i++){
            if(A[i] > maxCake){
                maxCake = A[i];
                maxCakeIndex = i;
            }
        }

        // 第一次翻转，将最大饼翻到最上面
        reverse(A, 0, maxCakeIndex);
        res.push_back(maxCakeIndex + 1);

        // 第二次翻转，将最大饼翻到最下面
        reverse(A, 0, n);
        res.push_back(n + 1);

        sort(A, n - 1);
    }

    void reverse(vector<int>&A, int i, int j){
        while(i < j){
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }

private:
    vector<int> res;
};

int main(){
    vector<int> A{3,2,4,1};
    Solution S;
    printVector(S.pancakeSort(A));
    getchar();
}