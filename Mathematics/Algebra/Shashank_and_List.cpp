#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
typedef __int64_t Soan;

int t = 1000000007, h = (t - 1) / 2;
int my_pow(long x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return 2;
    int y = my_pow(x / 2);
    Soan P = (Soan)y * y;
    int q = 0;
    if (x % 2 == 0)
        q = int(P % t);
    else
    {
        q = int(P % t);
        P = (Soan)q * 2;
        q = int(P % t);
    }
    return q % t;
}

int solve(vector<long> a) {
    int Q = 1;
    for (int i = 0; i < a.size(); ++i)
    {
        int k = a[i] % h;
        int l = my_pow(k) + 1;
        Soan X = (Soan)Q * l;
        Q = int(X % t);
    }
    return Q - 1;
}

int main()
{
    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int result = solve(a);
    cout << result << endl;
    return 0;
}