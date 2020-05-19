#include <vector>

using namespace std;


/*
* ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
* ����������Yes,�������No���������������������������ֶ�������ͬ��
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