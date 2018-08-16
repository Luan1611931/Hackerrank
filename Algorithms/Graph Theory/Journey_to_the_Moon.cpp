#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

vector<int> nums;

struct VerTex
{
	bool isMarked;
	vector<int> adjVertex;
	VerTex()
	{
		isMarked = false;
	}
};

void X(int ver, VerTex *arr, int n)
{
    nums.back() += 1;
	arr[ver].isMarked = true;
	vector<int>::iterator temp1;
	for (temp1 = arr[ver].adjVertex.begin(); temp1 != arr[ver].adjVertex.end(); ++temp1)
	{
		int ver1 = *temp1;
		if (!arr[ver1].isMarked)
			X(ver1, arr, n);
	}
}

long long CountPairs(VerTex *arr, int n)
{
	vector<int>::iterator temp;
    long long result = 0, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!arr[i].isMarked)
		{
            if (nums.size() > 0)
            {
                result += nums.back() * sum;
                sum += nums.back();
            }
            nums.push_back(1);
			arr[i].isMarked = true;
			for (temp = arr[i].adjVertex.begin(); temp != arr[i].adjVertex.end(); ++temp)
			{
				int ver = *temp;
				if (!arr[ver].isMarked)
					X(ver, arr, n);
			}
		}
	}
    result += nums.back() * sum;
    return result;
}

int main()
{ 
    int N, I;
    cin >> N >> I;
    VerTex *pairs = new VerTex[N];
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].adjVertex.push_back(b);
        pairs[b].adjVertex.push_back(a);
    }
 
    long long result = 0;
    
    /** Write code to compute the result using N,I,pairs **/
    result = CountPairs(pairs, N);
    
    cout << result << endl;
    delete[] pairs;
    pairs = NULL;
    return 0;
}
