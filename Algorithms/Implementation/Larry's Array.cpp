#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool process(vector<int> a, int t)
{
    int n = a.size();
    if (n == 2)
        return (a[0] < a[1]) ? true : false;
    vector<int> b;
    int in = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != t)
            b.push_back(a[i]);
        else
            in = i;
    }
    if (in % 2 == 1)
        swap(b[0], b[1]);
    return process(b, t + 1);
}   

string Larry(vector<int> a)
{
    bool res = process(a, 1);
    if (res)
        return "YES";
    else
        return "NO";
}

int main()
{
    int t;
    cin >> t;
    for (int i_t = 0; i_t < t; ++i_t)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j_t = 0; j_t < n; ++j_t)
            cin >> a[j_t];
        string result = Larry(a);
        cout << result << endl;
    }
    return 0;
}