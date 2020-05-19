#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef enum {
	UPLEFT = 0,
	UP = 1,
	LEFT = -1
} Direct;

int lcsLength(const char * s1, const char * s2)
{
	int m = strlen(s1), n = strlen(s2);
	if (m == 0 || n == 0)
	{
		return 0;
	}

	// ������ά����,����ÿ��ʵ���ĳ���
	int ** c = new int * [m + 1];
	for (int i = 0; i <= m ; i++)
	{
		c[i] = new int [n + 1];
	}

	// ��ʼ������,��0�к͵�0��
	for (int j = 0; j <= n; ++j)
	{
		c[0][j] = 0;
	}

	for (int i = 0; i <= m; ++i)
	{
		c[i][0] = 0;
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
			{
				if (c[i - 1][j] >= c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
				}
				else
				{
					c[i][j] = c[i][j - 1];
				}
			}
		}
	}

	int len = c[m][n];

	//�ͷ�
	for (int i = 0; i <= m; ++i)
	{
		delete[] c[i];
	}

	delete[] c;

	return len;
}

int lcs1(const char * s1, const char * s2, int * c[], int * b[])
{
	int m = strlen(s1), n = strlen(s2);
	if (m == 0 || n == 0)
	{
		return 0;
	}

	// ��ʼ������,��0�к͵�0��
	for (int j = 0; j <= n; ++j)
	{
		c[0][j] = 0;
	}

	for (int i = 0; i <= m; ++i)
	{
		c[i][0] = 0;
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = UPLEFT; // 0 ����
			}
			else
			{
				if (c[i - 1][j] >= c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = UP; // ��
				}
				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = LEFT; // ��
				}
			}
		}
	}

	return c[m][n];
}


int lcs2(const string & s1, const string & s2, vector<vector<int>>& vecDirect)
{
	int m = s1.size(), n = s2.size();

	vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				vecDirect[i][j] = UPLEFT;
			}
			else
			{
				if (c[i - 1][j] >= c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					vecDirect[i][j] = UP;
				}
				else
				{
					c[i][j] = c[i][j - 1];
					vecDirect[i][j] = LEFT;
				}
			}
		}
	}

	return c[m][n];
}

template <typename T>
void printLCS(const char * s1, T b, int i, int j)
{
	if (i == 0 || j == 0)
	{
		return;
	}

	if (b[i][j] == UPLEFT)
	{
		printLCS(s1, b, i - 1, j - 1);
		printf("%c ", s1[i - 1]);
	}
	else if (b[i][j] == UP)
	{
		printLCS(s1, b, i - 1, j);
	}
	else
	{
		printLCS(s1, b, i, j - 1);
	}
}

int main()
{
	const char * s1 = "ABCBDAB";
	const char * s2 = "BDCABA";

	printf("%s\n%s\n", s1, s2);
	printf("==============\n");
	printf("lcsLength,length: %d\n", lcsLength(s1, s2));

	////////////////////////////////////////////////////
	int m = strlen(s1), n = strlen(s2);

	// ������ά����,����ÿ��ʵ���ĳ���
	int ** c = new int *[m + 1];
	for (int i = 0; i <= m; i++)
	{
		c[i] = new int[n + 1];
	}

	int ** b = new int *[m + 1];
	for (int i = 0; i <= m; i++)
	{
		b[i] = new int[n + 1];
	}

	printf("==============\n");
	printf("lcs1,length: %d, lcs:", lcs1(s1, s2, c, b));
	printLCS(s1, b, m, n);
	printf("\n");

	//�ͷ�
	for (int i = 0; i <= m; ++i)
	{
		delete[] c[i];
	}
	delete[] c;

	for (int i = 0; i <= m; ++i)
	{
		delete[] b[i];
	}
	delete[] b;

	/////////////////////////////
	printf("==============\n");

	vector<vector<int>> vecDirect(m + 1, vector<int>(n + 1, 0));
	printf("lcs2,length: %d, lcs:", lcs2(s1, s2, vecDirect));
	printLCS(s1, vecDirect, m, n);
	printf("\n");

	getchar();
    return 0;
}

