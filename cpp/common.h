#include <vector>
#include<algorithm>
#include<iostream>
#include<stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 void printVector(vector<int>& arr){
    for(int a : arr)
        cout << a << " ";
    cout << endl;
 }