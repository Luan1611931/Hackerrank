#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
__int64_t solve(vector<int> a) {
    int t1 = 0, t2 = 0, n = a.size();
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
            t1++;
        else if (a[i] == 2)
            t2++;
    }
    __int64_t S1, S2, S3;
    S1 = (__int64_t)t1 * (n - 1);
    if (t2 < 2)
        S2 = 0;
    else
        S2 = ((__int64_t)t2 * (t2 - 1)) / 2;
    S3 = S1 + S2;
    return S3;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int a_count;
        cin >> a_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(a_count);

        for (int i = 0; i < a_count; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        __int64_t result = solve(a);

        fout << result << "\n";
    }

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
