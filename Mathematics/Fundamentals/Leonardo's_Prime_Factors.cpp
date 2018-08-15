#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the primeCount function below.
 */
bool is_prime(long n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else 
    {
        int X = (int)ceil(sqrt(n));
        for (int i = 2; i <= X; ++i)
            if (n % i == 0)
                return false;
        return true;
    }
}

int primeCount(long long n) {
    /*
     * Write your code here.
     */
    long long P = 1;
    int S = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (is_prime(i))
        {
            P = P * i;
            if (P < n)
            {
                S++;
                long long t = n / P;
                if (t <= i)
                    break;
            }
            else if (P == n)
            {
                S++;
                break;
            }
            else
                break;
        }
    }
    return S;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = primeCount(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
