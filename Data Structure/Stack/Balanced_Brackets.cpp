#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
bool Soan(char c, char d)
{
    if (c == '(' && d == ')')
        return true;
    if (c == '[' && d == ']')
        return true;
    if (c == '{' && d == '}')
        return true;
    return false;
}

string isBalanced(string s) {
    stack<char> t;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            t.push(s[i]);
        else
        {
            if (t.empty())
                return "NO";
            char c = t.top();
            t.pop();
            if(!Soan(c, s[i]))
                return "NO";
        }
    }
    if(t.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
