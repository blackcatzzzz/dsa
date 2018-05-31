#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;


class LFUCache
{
private:
	unordered_map<int, pair<int, int>> m; // key to pair<value,freq>
	unordered_map<int, list<int>::iterator> mIter; //key to list iterator
	unordered_map<int, list<int>> fm; //freq to key list;尾部的key是最近访问过的,头部的是最近没有访问的（待淘汰）
	int cap;
	int size;
	int minFreq;

public:
	LFUCache(int capacity)
	{
		cap = capacity;
		size = 0;
		minFreq = -1;
	}

	int get(int key)
	{
		if (!m.count(key))
			return -1;

		int oldFreq = m[key].second;
		fm[oldFreq].erase(mIter[key]);
		m[key].second++;
		fm[m[key].second].push_back(key);
		mIter[key] = prev(fm[m[key].second].end());

		if (fm[minFreq].size() == 0)
			minFreq++;

		return m[key].first;
	}

	void set(int key, int value)
	{
		if (get(key) == -1) // 未命中
		{
			if (size == cap)
			{
				mIter.erase(fm[minFreq].front());
				m.erase(fm[minFreq].front());
				fm[minFreq].pop_front();
				--size;
			}

			minFreq = 1;
			m[key] = { value, 1 };
			fm[1].push_back(key);
			mIter[key] = prev(fm[1].end());
			++size;
		}
		else
			m[key].first = value;
	}

	void print()
	{
		cout << "======LFUCache:=======" << endl;
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			cout << it->first << "," << it->second.first << "," << it->second.second << endl;
		}
		cout << endl;
	}
};


int main()
{

	LFUCache lfuCache(3);
	lfuCache.set(1, 1);
	lfuCache.set(2, 2);
	lfuCache.set(3, 3);

	lfuCache.print();

	cout << "get(1)" << endl;
	cout << "get(1)" << endl;
	lfuCache.get(1);
	lfuCache.get(1);
	cout << "get(2)" << endl;
	cout << "get(2)" << endl;
	lfuCache.get(2);
	lfuCache.get(2);
	lfuCache.print();

	cout << "get(3)" << endl;
	lfuCache.get(3);
	lfuCache.print();

	cout << "set(4,4)" << endl;
	lfuCache.set(4, 4);
	lfuCache.print();

	cout << "set(4,14)" << endl;
	lfuCache.set(4, 14);
	lfuCache.print();

	getchar();
	return 0;
}