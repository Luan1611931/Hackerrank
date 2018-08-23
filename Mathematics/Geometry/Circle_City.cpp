#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
typedef __int64_t soan;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (a % b == 0)
        return b;
    int r = a % b;
    return gcd(b, r);
}

bool is_square(int m)
{
    if (m < 0)
        return false;
    if (m == 0 || m == 1)
        return true;
    int t = (int)sqrt((double)m);
    if (m / t == t && m % t == 0)
        return true;
    return false;
}

string solve(int d, int k) {

    while (d % 4 == 0)
        d = d / 4;
    int r, count = 0, i = 1, u = d / 2;

    while (true)
    {
        soan q = (soan)i * i;
        if(q <= (soan)u)
        {
            int v = d - i * i;
            if (is_square(v))
                count++;
        }
        else
            break;
        i++;
    }
    count = count * 8;
    if(is_square(d))
        count += 4;
    string f;
    if (k < count)
        f = "impossible";
    else
        f = "possible";
    return f;
}

int main()
{

    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int d, k;
        cin >> d >> k;
        string result = solve(d, k);
        cout << result << "\n";
    }

    return 0;
}