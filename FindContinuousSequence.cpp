#include <vector>

using namespace std;

/*
* С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
* ���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
* û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,
* ���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
*
* �������:
* ������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
*/

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum <= 2)
			return vector<vector<int>>();
		vector<vector<int>> vecRes;
		int small = 1;
		int big = 2;
		int curSum = small + big;
		while (small < ((sum + 1) / 2))
		{
			if (curSum == sum)
			{
				vector<int> vecCs;
				for (int i = small; i <= big; ++i)
					vecCs.push_back(i);
				vecRes.push_back(vecCs);
			}

			if (curSum > sum)
			{
				curSum -= small;
				small++;
			}
			else
			{
				++big;
				curSum += big;
			}
		}

		return vecRes;
	}
};


// 2018.6.19
class Solution1 {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum <= 2)
			return vector<vector<int>>();

		vector<vector<int>> vecRes;
		int small = 1, big = 2;
		int curSum = small + big;
		while (small < (sum + 1) / 2)
		{
			if (curSum == sum)
			{
				vector<int> vec;
				for (int i = small; i <= big; ++i)
					vec.push_back(i);
				vecRes.push_back(vec);
				curSum -= small;
				small++;
			}
			else if (curSum < sum)
			{
				big++;
				curSum += big;
			}
			else
			{
				curSum -= small;
				small++;
			}
		}

		return vecRes;
	}
};

int main()
{
	Solution s;
	s.FindContinuousSequence(10);
	return 0;
}