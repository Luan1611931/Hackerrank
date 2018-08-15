#include <bits/stdc++.h>

using namespace std;

typedef __int64_t soan;

// Complete the solve function below.
int power_up(int k, soan n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return k;
    int y = power_up(k, n / 2);
    int r;
    if (n % 2 == 0)
        r = (y * y) % 100;
    else
        r = ((y * y) % 100) * k % 100;
    return r;
}

int solve(soan k, soan n) {
    vector<int> X(101);
    X[100] = 0;
    X[1] = 1;
    for (int i = 2; i <= 99; ++i)
        X[i] = power_up(i, n);
    soan t1 = k / 100;
    int t2 = int(k % 100);
    int Y = 0;
    for (int i = 1; i <= 100; ++i)
        Y = (Y + X[i]) % 100;
    t1 = t1 * Y;
    Y = int(t1 % 100);
    for (int i = 1; i <= t2; ++i)
        Y = (Y + X[i]) % 100;
    
    return Y;
}

int main()
{

    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        soan k, n;
        cin >> k >> n;
        int result = solve(k, n);
        if (result < 10)
            cout << "0";
        cout << result << "\n";
    }

    return 0;
}
