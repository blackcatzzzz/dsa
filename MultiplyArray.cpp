#include <vector>

using namespace std;
/*
* 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
* 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		if (A.size() <= 1)
			return vector<int>();

		vector<int> vecB(A.size());

		// C[i] = A[0]*A[1]*……*A[i-1]
		vecB[0] = 1;
		for (int i = 1; i < A.size(); ++i)
		{
			vecB[i] = vecB[i - 1] * A[i - 1];
		}

		// D[i] = A[i + 1] * ……*A[n - 1]
		// B[i] = C[i] * D[i]
		int d = 1; // D[n - 1]
		for (int i = A.size() - 2; i >= 0; --i)
		{
			d *= A[i + 1];
			vecB[i] *= d;
		}

		return vecB;
	}
};

int main()
{
	return 0;
}