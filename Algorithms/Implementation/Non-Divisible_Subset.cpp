#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the nonDivisibleSubset function below.
int nonDivisibleSubset(int k, vector<int> S) {
    vector<int> mod(k);
    for (int i = 0; i < S.size(); ++i)
        mod[S[i] % k] += 1;
    int X = S.size();
    if (k % 2 == 0)
    {
         for (int i = 1; i < k / 2; ++i)
            if (mod[i] < mod[k - i])
                X -= mod[i];
            else
                X -= mod[k - i];
        if (mod[k / 2] > 0)
            X = X - mod[k / 2] + 1;
    }
    else
    {
         for (int i = 1; i <= k / 2; ++i)
            if (mod[i] < mod[k - i])
                X -= mod[i];
            else
                X -= mod[k - i];
    }
   
    if (mod[0] > 0)
            X = X - mod[0] + 1;
    return X;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string S_temp_temp;
    getline(cin, S_temp_temp);

    vector<string> S_temp = split_string(S_temp_temp);

    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        int S_item = stoi(S_temp[i]);

        S[i] = S_item;
    }

    int result = nonDivisibleSubset(k, S);

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
