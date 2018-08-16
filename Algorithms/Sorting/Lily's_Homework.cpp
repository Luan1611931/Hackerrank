#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void Reverse(vector<int> &v)
{
	int _size = v.size();
	for (int i = 0; i < _size / 2; ++i)
		swap(v[i], v[_size - 1 - i]);
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N;
	map<int, int> mymap, mymap2;
	cin >> N;
	vector<int> v(N), v1, _v;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		mymap[v[i]] = i;
	}
	mymap2 = mymap;
	v1 = v; _v = v;
	sort(v1.begin(), v1.end());
	vector<int> v2(v1);
	Reverse(v2);
	int num1 = 0, num2 = 0;
	for (int i = 0; i < N; ++i)
	{
		if (v[i] != v1[i])
		{
			int a = mymap[v1[i]];
			swap(v[i], v[a]);
			mymap[v[a]] = a;
			num1++;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (_v[i] != v2[i])
		{
			int a = mymap2[v2[i]];
			swap(_v[i], _v[a]);
			mymap2[_v[a]] = a;
			num2++;
		}
	}

	cout << ((num1 < num2) ? num1 : num2);
	return 0;
}
