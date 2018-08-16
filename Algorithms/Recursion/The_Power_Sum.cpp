#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define EPS 1E-10
using namespace std;

int X, N;
int num = 0;
double T1, T2;

void Tinh(int m, vector<int> &v)
{
    if (v.size() == m)
    {
        double T = X;
        for (int i = 0; i < m; ++i)
            T = T - pow(v[i], N);

        if (abs(T) < EPS)
            num++;
    }
    else
    {
        int start, stop;
        if (v.empty())
        {
            start = 1;
            stop = int(T1);
        }
        else
        {
            start = v.back() + 1;
            int J = 0, b = v.size();
            for (int j = 0; j < b; ++j)
                J += v[j];
            stop = int((T2 - J)/(m - b));
        }
        for (int j = start; j <= stop; ++j)
        {
            v.push_back(j);
            Tinh(m, v);
            v.pop_back();
        }
    }
}

int main()
{
    cin >> X;
    cin >> N;
    int m = 1, Sum = 1;
    while (Sum < X)
    {
        vector<int> v;
        double f = X*1.0/m;
        T1 = pow(f, (float)1/N);
        T2 = m*pow(f, (float)1/N);
        Tinh(m, v);
        ++m;
        Sum += pow(m, N);
    }
    if (Sum == X)
        ++num;
    cout << num;
    return 0;
}
