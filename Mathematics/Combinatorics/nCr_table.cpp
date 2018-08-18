#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
int MOD = 1000000000;

typedef __int64_t soan;

vector<vector<int>> Pascal_Triangle(1000);

void Construction()
{
    for (int i = 0; i < 1000; ++i)
    {
        vector<int> a(i + 1);
        Pascal_Triangle[i] = a;
    }
    Pascal_Triangle[0][0] = 1;
    for (int i = 0; i < 1000; ++i)
    {
        Pascal_Triangle[i][0] = Pascal_Triangle[i][i] = 1;
        for (int j = 1; j <= i / 2; ++j)
            Pascal_Triangle[i][j] = Pascal_Triangle[i][i - j] = ((soan)Pascal_Triangle[i - 1][j] + Pascal_Triangle[i - 1][j - 1]) % MOD;
    }
}

vector<int> solve(int n) {
    return Pascal_Triangle[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    Construction();
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = solve(n);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
