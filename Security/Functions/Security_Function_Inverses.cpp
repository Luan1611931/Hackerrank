#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -1;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i)
        b[a[i]] = i;
    for (int i = 1; i <= n; ++i)
        cout << b[i] << endl;
    return 0;
}
