#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

bool yet = false;
int k;

template <typename T>
string genericToString(const T& t)
{
    ostringstream oss;
    oss << t;
    return oss.str();
}

string super_digit(string P)
{
    if (P.size() == 1 && k == 1)
        return P;
    else 
    {
        long long Sum = 0;
        for (int i = 0; i < P.size(); ++i)
        {
            Sum += P[i] - '0';
        }
        if (!yet)
        {
            Sum *= k;
            k = 1;
            yet = true;
        }
        string Q = genericToString(Sum);
        return super_digit(Q);
    }
}

int main()
{
    string n;
    cin >> n;
    cin >> k;
    cout << super_digit(n);
    return 0;
}