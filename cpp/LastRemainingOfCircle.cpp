#include <list>

using namespace std;

/*
* ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�
* HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:
* ����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
* ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,
* ��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,
* �����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��
* ������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)
*/

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1)
			return -1;
		list<int> listNumber;
		for (int i = 0; i < n; ++i)
			listNumber.push_back(i);

		list<int>::iterator it = listNumber.begin();
		while (listNumber.size() > 1)
		{
			for (int i = 0; i < m - 1; ++i)
			{
				++it;
				if (it == listNumber.end())
					it = listNumber.begin();
			}

			it = listNumber.erase(it);
			if (it == listNumber.end())
				it = listNumber.begin();
		}

		return *it;
	}
};

int main()
{
	return 0;
}