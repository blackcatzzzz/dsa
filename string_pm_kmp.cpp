/*****************************
*	KMP算法
*	@auther cha zhang
*	@date 2018/1/13
*************************/

#include <cstring>
#include <stdio.h>

// 构建Next表
int * buildNext(char * P)
{
	int m = strlen(P), j = 0;
	int * next = new int[m];
	int t = next[0] = -1;

	while (j < m - 1)
	{
		if (0 > t || P[j] == P[t])
			next[++j] = ++t;
		else
			t = next[t];
	}

	return next;
}

//P：模式串，T：文本串
int match(char * P, char * T)
{
	if (P == NULL || T == NULL)
		return -1;

	int m = strlen(P);
	int n = strlen(T);

	int * next = buildNext(P);

	int i = 0, j = 0;

	while (i < n && j < m)
	{
		if (0 > j || T[i] == P[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}

	if (j == m)
		return i - j;

	return -1;
}

int main()
{
	char * T = "hello world";
	char * P = "i";
	printf("T: %s\n", T);
	printf("P: %s\n", P);
	printf("result: %d", match(P, T));
	getchar();
	return 0;
}