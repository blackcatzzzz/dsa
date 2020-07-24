#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



 // Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 

template<typename T>
 void printVector(vector<T>& arr){
    for(T a : arr)
        cout << a << " ";
    cout << endl;
 }

 
void printList(ListNode* head){
	while(head){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}