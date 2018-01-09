#include <stdio.h>

const int MAXSIZE = 500;

int uset[MAXSIZE];	// �������ݶ���index��ʾ,index��Ϊ����,����Ԫ��Ϊ��parent
int rank[MAXSIZE];	// �ȣ������߶ȵ��Ͻ�

void makeSet(int n)
{
	for (int i = 0; i < n; ++i)
		uset[i] = i;
	for (int i = 0; i < n; ++i)
		rank[i] = 0;
}

// ����·��ѹ����������
int find_UNPC_I(int x)
{
	while (x != uset[x])
	{
		x = uset[x];
	}

	return uset[x];
}

// ����·��ѹ�����ݹ��
int find_UNPC_R(int x)
{
	if (x == uset[x])
		return uset[x];
	return find_UNPC_R(uset[x]);
}

// ·��ѹ�����ݹ��
int find_R(int x)
{
	if (x == uset[x])
		return uset[x];
	return uset[x] = find_R(uset[x]);
}

// ·��ѹ����������
int find_I(int x)
{
	int p = x, temp;
	while (p != uset[p])
		p = uset[p];
	while (x != uset[x])
	{
		temp = uset[x]; // ���游�ڵ�Index
		uset[x] = p;	// ��ǰ�ڵ�ֱ��ָ����ڵ�
		x = temp;		// ת�򸸽ڵ��������
	}
	return x;
}

// ���Ⱥϲ�
void unionSet(int x, int y)
{
	x = find_R(x);
	y = find_R(y);
	if (x == y)
		return;

	if (rank[x] > rank[y])
		uset[y] = x;
	else
	{
		uset[x] = y;
		if (rank[x] == rank[y])
			++rank[y];
	}
}

int getSetCount(int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (uset[i] == i)
			++count;
	}

	return count;
}

void pringArray(int * a, int len)
{
	printf("e: ");
	for (int i = 0; i < len; ++i)
		printf("%d ", i);
	printf("\n");

	printf("p: ");
	for (int i = 0; i < len; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void test1()
{
	uset[0] = 1;
	uset[1] = 3;
	uset[2] = 2;
	uset[3] = 4;
	uset[4] = 2;
	int count = getSetCount(5);
	pringArray(uset, 5);
	printf("setCount: %d", count);
	printf("\n");
}

// n���ˣ� m�Թ�ϵ��rΪ��ϵ���飬�ҳ�����Ȧ����
int friends(int n, int m, int r[][2])
{
	makeSet(n + 1); // 0�ű������ã���1 ~ n
	printf("makeSet: %d\n", n + 1);
	pringArray(uset, n + 1);

	for (int i = 0; i < m; ++i)
		unionSet(r[i][0], r[i][1]);

	return getSetCount(n) - 1; // 0���ų����� - 1��
}

void test_friends()
{
	printf("\n=========test_friends=========\n");
	int n = 5, m = 3;
	int r[][2] = { {1,2}, {2,3}, {4,5} };
	int count = friends(n ,m, r);
	pringArray(uset, n + 1);
	printf("friends: %d", count);
	printf("\n");
}



int main()
{
	test1();
	test_friends();
	getchar();
    return 0;
}

