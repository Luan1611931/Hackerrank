#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solve(vector<int> a)
{
    int n = a.size(), m = n - 1;
    string result = "YES";
    
    for (int i = 1; i <= m; ++i)
        if (a[a[i]] != i)
        {
            result = "NO";
            break;
        }
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << solve(a) << endl;
    return 0;
}
