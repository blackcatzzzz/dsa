#include <cstdio>
//#ifdef unix
//#define LLD "%lld"
//#else
//#define LLD "%I64d"
//#endif 

using namespace std;

// euclidean, copy from dsa course of Tsinghua
__int64 gcdEU(__int64 a, __int64 b) { //assert: 0 <= min(a, b)
	while (true) {
		if (0 == a) return b;
		if (0 == b) return a;
		if (a > b) a %= b;
		else       b %= a;
	}
}

long long gcd_I(long long a, long long b)	//assert: 0 <= min(a, b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long gcd_R(long long a, long long b)	//assert: 0 <= min(a, b)
{
	return b ? gcd_R(b, a % b) : a;
}

int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("gcd_R: %lld\n", gcd_R(a, b));
	printf("gcd_I: %lld", gcd_I(a, b));
	getchar();
	getchar();
    return 0;
}

