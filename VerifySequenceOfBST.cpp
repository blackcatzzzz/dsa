#include <vector>

using namespace std;


/*
* 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
* 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		return verifySquenceOfBSTCore(sequence, 0, sequence.size() - 1);
	}

private:
	bool verifySquenceOfBSTCore(vector<int> &sequence, int lo, int hi)
	{
		int root = sequence[hi];
		int i = lo;
		for (; i < hi; ++i)
		{
			if (sequence[i] > root)
				break;
		}

		int j = i;
		for (; j < hi; ++j)
		{
			if (sequence[j] < root)
				return false;
		}
		bool left = true, right = true;

		if (i > lo)
			left = verifySquenceOfBSTCore(sequence, lo, i - 1);
		if (i < hi)
			right = verifySquenceOfBSTCore(sequence, i, hi - 1);

		return left && right;
	}
};

// 2018.6.16
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		return verifySquenceOfBSTCore(sequence, 0, sequence.size() - 1);
	}

private:
	bool verifySquenceOfBSTCore(vector<int> &sequence, int lo, int hi)
	{
		if (lo >= hi)
			return true;

		int root = sequence[hi];
		int i = lo;
		for (; i < hi; ++i)
			if (sequence[i] > root)
				break;

		for (int j = i; j < hi; ++j)
			if (sequence[j] < root)
				return false;

		bool left = verifySquenceOfBSTCore(sequence, lo, i - 1);
		bool right = verifySquenceOfBSTCore(sequence, i, hi - 1);

		return left && right;

	}
};

int main()
{
	return 0;
}