#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
int solve(int n) {
    int result;
    if (n == 1 || n == 2)
        return -1;
    if (n % 2 == 1)
        result = 2;
    else if (n % 4 == 0)
        result = 3;
    else
        result = 4;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
