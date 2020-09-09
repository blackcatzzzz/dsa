#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <string>

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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
 

template<typename T>
 void printVector(vector<T>& arr){
    for(T a : arr)
        cout << a << " ";
    cout << endl;
 }

 template<typename T>
 void printVectors(vector<vector<T>>& arrs){
    for(vector<T>& arr : arrs)
        printVector(arr);
    cout << endl;
 }

 
void printList(ListNode* head){
	while(head){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}