/******************************************
*	�������ĸ��ֱ����㷨,�����ݹ�������汾
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

/*********�ݹ� begin**************/
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
/*********�ݹ� end**************/


/*********����**************/

// �������������(������#1)
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

// �������������(������#2)
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
			visit(x->data); //���ʵ�ǰ�ڵ�
			stackBN.push(x->rc); // �Һ�����ջ�ݴ棨���Ż���ͨ���жϣ�����յ��Һ�����ջ��
			x = x->lc; //�����֧����һ��
		}
	}
}

// ��������������㷨�������棩
template <typename T, typename VST>
void travInOrder_I(BinNode<T>* x, VST visit)
{
	if (!x) return;
	stack<BinNode<T> *> stackBN;
	
	while (true)
	{
		//��ǰ�ڵ���ջ���漴������֧���룬����ֱ��������
		while (x)
		{
			stackBN.push(x);
			x = x->lc;
		}

		if (stackBN.empty()) break; //ֱ�����нڵ㴦�����

		//����ջ���ڵ㲢����֮
		x = stackBN.top();
		visit(x->data);
		stackBN.pop();

		x = x->rc; //ת��������
	}
}

// ��������������㷨��������#1����˼·���廪�̿�����ͬ��
template <typename T, typename VST>
void travPostOrder_I1(BinNode<T> * x, VST visit)
{
	if (!x) return;
	stack<BinNode<T>*> stackBN;
	stackBN.push(x);

	while (!stackBN.empty())
	{
		if (!IsParent(stackBN.top(), x)) //��ջ���ǵ�ǰ�ڵ�֮�������Ϊ�����֣�,��ʱ��
		{
			//����������Ϊ��֮�����У��ҵ�HLVFL(������ɼ�Ҷ�ڵ�)
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

// ��������������㷨��������#2���ο� https://www.cnblogs.com/rain-lei/p/3705680.html
template <typename T, typename VST>
void travPostOrder_I2(BinNode<T>* x, VST visit)
{
	if (!x) return;
	stack<BinNode<T>*> stackBN;
	stackBN.push(x);

	while (!stackBN.empty())
	{
		// �������#1��ȣ�����������ν�ıȽ�,��Ϊ��������ɼ�Ҷ�ڵ�Ļᾭ����������ջ����������ÿ�αȽ�
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

/*********����**************/

// ��α���
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

