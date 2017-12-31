/******************************************
*	二叉树的各种遍历算法,包括递归与迭代版本
*	@date 2017/12/31
*	@auther cat zhang
*******************************************/
#include "stdafx.h"
#include <stdio.h>
#include <typeinfo> 
#include <queue>
#include <stack>

#define IsParent(p, x) (p->lc == x || p->rc == x)
#define IsLeaf(x) ((x->lc == NULL) && (x->rc == NULL))
#define HasRChild(x) (x->rc)

using namespace std;

template <typename T>
struct BinNode
{
	T data;
	BinNode* lc;
	BinNode* rc;
	BinNode(T x) : data(x), lc(NULL), rc(NULL){}

	BinNode* insertAsLChild(const T &e);
	BinNode* insertAsRChild(const T &e);
};

template <typename T> BinNode<T> * BinNode<T>::insertAsLChild(const T &e)
{
	return lc = new BinNode<T>(e);
}

template <typename T> BinNode<T> * BinNode<T>::insertAsRChild(const T &e)
{
	return rc = new BinNode<T>(e);
}

/*********递归 begin**************/
template <typename T, typename VST>
void travPreOrder_R(BinNode<T>* x, VST visit)
{
	if (!x)
		return;
	visit(x->data);
	travPreOrder_R(x->lc, visit);
	travPreOrder_R(x->rc, visit);
}

template <typename T, typename VST>
void travInOrder_R(BinNode<T>* x, VST visit)
{
	if (!x)
		return;
	travInOrder_R(x->lc, visit);
	visit(x->data);
	travInOrder_R(x->rc, visit);
}

template <typename T, typename VST>
void travPostOrder_R(BinNode<T>* x, VST visit)
{
	if (!x)
		return;
	travPostOrder_R(x->lc, visit);
	travPostOrder_R(x->rc, visit);
	visit(x->data);
}
/*********递归 end**************/


/*********迭代**************/

// 二叉树先序遍历(迭代版#1)
template <typename T, typename VST>
void travPreOrder_I1(BinNode<T> * x, VST visit)
{
	if (!x) return;

	stack<BinNode<T>*> stackBN;
	stackBN.push(x);

	while (!stackBN.empty())
	{
		BinNode<T>* x = stackBN.top();
		visit(x->data);
		stackBN.pop();

		if (x->rc)
			stackBN.push(x->rc);
		if (x->lc)
			stackBN.push(x->lc);
	}
}

// 二叉树先序遍历(迭代版#2)
template <typename T, typename VST>
void travPreOrder_I2(BinNode<T> * x, VST visit)
{
	if (!x) return;

	stack<BinNode<T>*> stackBN;
	stackBN.push(x);

	while (!stackBN.empty())
	{
		BinNode<T> * x = stackBN.top();
		stackBN.pop();
		while (x)
		{
			visit(x->data); //访问当前节点
			stackBN.push(x->rc); // 右孩子入栈暂存（可优化：通过判断，避免空的右孩子入栈）
			x = x->lc; //沿左分支深入一层
		}
	}
}

// 二叉树中序遍历算法（迭代版）
template <typename T, typename VST>
void travInOrder_I(BinNode<T>* x, VST visit)
{
	if (!x) return;
	stack<BinNode<T> *> stackBN;
	
	while (true)
	{
		//当前节点入栈后随即向左侧分支深入，迭代直到无左孩子
		while (x)
		{
			stackBN.push(x);
			x = x->lc;
		}

		if (stackBN.empty()) break; //直至所有节点处理完毕

		//弹出栈顶节点并访问之
		x = stackBN.top();
		visit(x->data);
		stackBN.pop();

		x = x->rc; //转向右子树
	}
}

// 二叉树后序遍历算法（迭代版#1）（思路与清华教科书相同）
template <typename T, typename VST>
void travPostOrder_I1(BinNode<T> * x, VST visit)
{
	if (!x) return;
	stack<BinNode<T>*> stackBN;
	stackBN.push(x);

	while (!stackBN.empty())
	{
		if (!IsParent(stackBN.top(), x)) //若栈顶非当前节点之父（则必为其右兄）,此时需
		{
			//在以其右兄为根之子树中，找到HLVFL(最高左侧可见叶节点)
			while (x = stackBN.top())
			{
				if (x->lc)
				{
					if (x->rc)
					{
						stackBN.push(x->rc);
					}
					stackBN.push(x->lc);
				}
				else if (x->rc)
					stackBN.push(x->rc);
				else
					break;
			}
		}

		x = stackBN.top();
		visit(x->data);
		stackBN.pop();
	}
}

// 二叉树后序遍历算法（迭代版#2）参考 https://www.cnblogs.com/rain-lei/p/3705680.html
template <typename T, typename VST>
void travPostOrder_I2(BinNode<T>* x, VST visit)
{
	if (!x) return;
	stack<BinNode<T>*> stackBN;
	stackBN.push(x);

	while (!stackBN.empty())
	{
		// 与迭代版#1相比，迭代版多出无谓的比较,因为找最高左侧可见叶节点的会经过连续的入栈操作，不必每次比较
		if (IsLeaf(stackBN.top()) || (x == stackBN.top()->lc && !HasRChild(stackBN.top()))
			|| (x == stackBN.top()->rc) )
		{
			x = stackBN.top();
			visit(x->data);
			stackBN.pop();
		}
		else
		{
			x = stackBN.top();
			if (x->rc)
				stackBN.push(x->rc);
			if (x->lc)
				stackBN.push(x->lc);
		}
	}
}

/*********迭代**************/

// 层次遍历
template <typename T, typename VST>
void travLevel(BinNode<T> * x, VST visit)
{
	if (!x) return;
	queue<BinNode<T> *> q;
	q.push(x);
	while (!q.empty())
	{
		BinNode<T>* x = q.front();
		visit(x->data);
		q.pop();
		if (x->lc)
			q.push(x->lc);

		if (x->rc)
			q.push(x->rc);
	}
}

template <typename T> void printBinNodeData(T const & e)
{
	if (typeid(e) == typeid(int))
	{
		printf("%d ", e);
	}
	else if (typeid(e) == typeid(char))
	{
		printf("%c ", e);
	}
	else if (typeid(e) == typeid(char *))
	{
		printf("%s ", e);
	}
}

int main()
{
	//create test BinTree
	BinNode<int>* root = new BinNode<int>(1);
	root->insertAsLChild(2)->insertAsLChild(4)->insertAsRChild(7);
	BinNode<int>* n3 = root->insertAsRChild(3);
	n3->insertAsLChild(5);
	n3->insertAsRChild(6)->insertAsLChild(8);

	printf("travPreOrder_R:\n");
	travPreOrder_R(root, printBinNodeData<int>);

	printf("\n\n");
	printf("travInOrder_R:\n");
	travInOrder_R(root, printBinNodeData<int>);

	printf("\n\n");
	printf("travInOrder_I:\n");
	travInOrder_I(root, printBinNodeData<int>);
	
	printf("\n");
	printf("\ntravPostOrder_R:\n");
	travPostOrder_R(root, printBinNodeData<int>);

	printf("\n\n");
	printf("travPostOrder_I1:\n");
	travPostOrder_I1(root, printBinNodeData<int>);

	printf("\n\n");
	printf("travPostOrder_I2:\n");
	travPostOrder_I2(root, printBinNodeData<int>);

	printf("\n");
	printf("\ntravLevel:\n");
	travLevel(root, printBinNodeData<int>);

	printf("\n\n");
	printf("travPreOrder_I1:\n");
	travPreOrder_I1(root, printBinNodeData<int>);

	printf("\n\n");
	printf("travPreOrder_I2:\n");
	travPreOrder_I2(root, printBinNodeData<int>);
	
	getchar();
	return 0;
}

