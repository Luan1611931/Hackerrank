#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
typedef __int64_t soan;

int MOD = 1000000007;

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int y = my_pow(a, b / 2);
    if (b % 2 == 0)
        return ((soan)y * y) % MOD;
    else
        return (((soan)y * y) % MOD) * a % MOD;
}

int solve(vector<int> a) {
    int n = a.size();
    int n_even = 0, n_odd;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0)
            n_even++;
    n_odd = n - n_even;
    if (n_even == 0 && n_odd <= 1)
        return 0;
    else if (n_even == 0)
        return my_pow(2, n_odd - 1) - 1;
    else if (n_odd <= 1)
        return my_pow(2, n_even) - 1;
    else
        return my_pow(2, n - 1) - 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    int result = solve(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
