#include <iostream>
#include <vector>
using namespace std;

struct VerTex
{
	int vertex;
	bool isMarked;
	vector<int> adjVertex;
	VerTex()
	{
		isMarked = false;
	}
};

void X(int ver, VerTex *arr, int n)
{
	arr[ver - 1].isMarked = true;
	vector<int>::iterator temp1;
	for (temp1 = arr[ver - 1].adjVertex.begin(); temp1 != arr[ver - 1].adjVertex.end(); ++temp1)
	{
		int ver1 = *temp1;
		if (!arr[ver1 - 1].isMarked)
			X(ver1, arr, n);
	}
}

int ComponentConnectivity(VerTex *arr, int n)
{
	int num = 0;
	vector<int>::iterator temp;
	for (int i = 0; i < n; ++i)
	{
		if (!arr[i].isMarked)
		{
			num++;
			arr[i].isMarked = true;
			for (temp = arr[i].adjVertex.begin(); temp != arr[i].adjVertex.end(); ++temp)
			{
				int ver = *temp;
				if (!arr[ver - 1].isMarked)
					X(ver, arr, n);
			}
		}
	}
	return num;
}

int main() {
	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++) {
		VerTex *arr = NULL;
		int n;
		int m;
		long x;
		long y;
		cin >> n >> m >> x >> y;
		arr = new VerTex[n];
		
		for (int a1 = 0; a1 < m; a1++) {
			int city_1;
			int city_2;
			cin >> city_1 >> city_2;
			arr[city_1 - 1].adjVertex.push_back(city_2);
			arr[city_2 - 1].adjVertex.push_back(city_1);
		}
		if (x < y)
			cout << n * x << endl;
		else
		{
			int A = ComponentConnectivity(arr, n);
			cout << (n - A) * y + A * x << endl;
		}
		delete[] arr;
		arr = NULL;
	}
	return 0;
}
