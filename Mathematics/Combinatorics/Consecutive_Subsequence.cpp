#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef __int64_t soan;

soan solve(vector<int> a, int k)
{
    vector<vector<int>> b(k);
    
    soan sum = 0, count = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        sum += a[i];
        int d = sum % k;
        if (d == 0)
            count++;
        count += b[d].size();
        b[d].push_back(i);
    }
    
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T;
    cin >> T;
    for (int i_c = 0; i_c < T; ++i_c)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        soan result = solve(a, k);
        cout << result << endl;
    }
    return 0;
}
