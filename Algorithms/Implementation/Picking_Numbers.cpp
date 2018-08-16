#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pickingNumbers function below.
vector<int> filter(vector<int> a)
{
    vector<int> b(0);
    for (int i = 0; i < a.size(); ++i)
    {
        bool yet = false;
        for (int j = 0; j < b.size(); ++j)
            if (a[i] == b[j])
            {
                yet = true;
                break;
            }
        if (!yet)
            b.push_back(a[i]);
    }  
    return b;
}

int pickingNumbers(vector<int> a) {
    vector<int> b = filter(a);
    int max = -1;
    for (int i = 0; i < b.size(); ++i)
    {
        int num = 0;
        for (int j = 0; j < a.size(); ++j)
            if (b[i] == a[j] || a[j] == b[i] + 1)
                num++;
        if (num > max)
            max = num;
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

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
