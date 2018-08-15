#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int value(vector<int> L)
{
    long long P = 1;
    for (int i = 0; i < L.size(); ++i)   
        P = P * (L[i] + 1) % 1000000007;
    P = (P - 1) % 1000000007;
    return P;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; ++i)
        cin >> L[i];
    cout << value(L) << endl;
    return 0;
}
