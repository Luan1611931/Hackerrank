#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solve(vector<int> a)
{
    int n = a.size();
    vector<bool> b(n);
    for (int i = 0; i < n; ++i)
        b[i] = false;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0 || a[i] >= n)
            return "NO";
        if (b[a[i]])
            return "NO";
        b[a[i]] = true;
    }
    return "YES";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {    
        cin >> a[i];
        a[i]--;
    }
    cout << solve(a) << endl;
    return 0;
}
