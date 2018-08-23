#include <bits/stdc++.h>
using namespace std;

typedef __int64_t soan;

int solve(int a, int b, int c, int d)
{
    int count = 0;
    for (int y = 1; y <= d; ++y)
    {
        soan r = (soan)y * y - (soan)b * y;
        soan f_a_2 = (soan)2 * y * y - (soan)2 * b * y - (soan)a * a;
        if (f_a_2 == 0 && a % 2 == 0)
            count++;
        else if (f_a_2 < 0)
        {
            int m, n = 0;
            if (a % 2 == 0)
                m = n = a / 2;
            else
            {
                m = a / 2;
                n = a / 2 + 1;
            }
            
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int result = solve(a, b, c, d);
        cout << result << endl;
    }
    return 0;
}
