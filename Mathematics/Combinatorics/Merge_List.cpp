#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int MOD = 1000000007;

typedef __int64_t soan;

void Construction(vector<vector<int>> &Pascal_Triangle, int size)
{
    for (int i = 0; i < size; ++i)
    {
        vector<int> a(i + 1);
        Pascal_Triangle[i] = a;
    }
    Pascal_Triangle[0][0] = 1;
    for (int i = 0; i < size; ++i)
    {
        Pascal_Triangle[i][0] = Pascal_Triangle[i][i] = 1;
        for (int j = 1; j <= i / 2; ++j)
            Pascal_Triangle[i][j] = Pascal_Triangle[i][i - j] = ((soan)Pascal_Triangle[i - 1][j] + Pascal_Triangle[i - 1][j - 1]) % MOD;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);
        
        vector<vector<int>> Pascal_Triangle(n + m + 1);

        Construction(Pascal_Triangle, n + m + 1);
        
        int result = Pascal_Triangle[n + m][n];

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
