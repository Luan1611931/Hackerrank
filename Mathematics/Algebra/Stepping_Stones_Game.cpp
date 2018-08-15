#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
string convert(int t)
{
    string x = "";
    while (t > 0)
    {
        int d = t % 10;
        t = t / 10;
        char a = '0' + d;
        x = a + x;
    }
    return x;
}

string solve(long long n) {
    unsigned long long N = 2 * n;
    int t = (int)floor(sqrt(N));
    string result;
    if (N % t == 0 && N % (t + 1) == 0)
        result = "Go On Bob " + convert(t);
    else
        result = "Better Luck Next Time ";
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
