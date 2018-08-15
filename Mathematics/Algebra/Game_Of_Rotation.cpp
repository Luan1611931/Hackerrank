#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef __int64_t soan;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin >>N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    soan T = 0;
    for (int i = 0; i < N; ++i)
        T = T + a[i];
    soan X = 0, PMEAN = 0;
    for (int i = 0; i < N; ++i)
        X = X + (i + 1) * (soan)a[i];
    PMEAN = X;
    for (int i = N - 1; i >= 1; --i)
    {
        X = X - (soan)N * a[i];
        X += T;
        if (X > PMEAN)
            PMEAN = X;
    }
    cout << PMEAN << endl;
    return 0;
}
