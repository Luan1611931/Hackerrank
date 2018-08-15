#include <bits/stdc++.h>

using namespace std;

vector<string> solve(string s) {
    vector<string> v;
    if (s.empty())
        return v;
    char z = s.back();
    string x;
    x += z;
    s.pop_back();
    v.push_back(x);
    vector<string> t = solve(s);
    for (int i = 0; i < t.size(); ++i)
    {
        string y = x + t[i];
        v.push_back(y);
    }
    if (!t.empty())
        v.insert(v.end(), t.begin(), t.end());
    return v;
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

        string s;
        getline(cin, s);
        sort(s.begin(), s.end(), greater<char>());
        vector<string> result = solve(s);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << "\n";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
