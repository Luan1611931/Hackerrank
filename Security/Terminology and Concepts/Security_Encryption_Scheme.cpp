#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef __int64_t soan;

soan frac(int n)
{
    if (n == 1)
        return 1;
    return (soan)n * frac(n - 1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    cout << frac(n) << endl;
    return 0;
}
