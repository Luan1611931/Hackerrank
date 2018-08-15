#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the lights function below.
 */

long lights(int n) {
    /*
     * Write your code here.
     */
    long P = 1;
    for (int i = 0; i < n; ++i)
        P = (P * 2) % 100000;
    return (P - 1) % 100000;
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

        long result = lights(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
