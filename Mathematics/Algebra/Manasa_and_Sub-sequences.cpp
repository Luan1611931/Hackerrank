#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
typedef __int64_t soan;

int MOD = 1000000007;

vector<int> mod(int a, int n)
{
    soan P = 1;
    vector<int> mods(n);
    for (int i = 0; i < n; ++i)
    {
        mods[i] = P;
        P = (P * a) % MOD;
    }
    return mods;
}

int solve(string s) {
    int n = s.size();
    vector<int> mod_11 = mod(11, n), mod_2 = mod(2, n);
    soan T = 0;
    for (int i = 0; i < n; ++i)
    {
        int k = s[i] - '0';
        soan Q = ((soan)mod_11[n - 1 - i] * mod_2[i]) % MOD;
        Q = (Q * k) % MOD;
        T = (T + Q) % MOD;
    }
    return T % MOD;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = solve(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
