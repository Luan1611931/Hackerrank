#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
typedef __int64_t luan;

int solve(luan n) {
    int S = 0;
    if (int(n % 2) == 0)
        S = 1;
    else
        S = 5;
    luan P = 1;
    int j = 0;
    bool y = false;
    for (int i = 1; i <= 49; ++i)
    {
        P = (luan)P * 2;
        if (P > n)
        {
            j = i - 1;
            y = true;
            break;
        }
    }
    if (!y)
        j = 49;
    if (j == 0)
        S = (S * 2) % 10;
    else if (j % 5 == 1)
        S = (S * 6) % 10;
    else if (j % 5 == 2)
        S = (S * 2) % 10;
    else if (j % 5 == 3)
        S = (S * 8) % 10;
    else if (j % 5 == 4)
        S = (S * 4) % 10;
    else
        S = 0;
    return S;
}

int main()
{
    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        luan n;
        cin >> n;
        int result = solve(n);

        cout << result << "\n";
    }

    return 0;
}