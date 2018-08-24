#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int n = w.size();
    int i = n - 1;
    string result;
    while (i > 0 && w[i] <= w[i - 1])
        i--;
    if (i == 0)
        result = "no answer";
    else
    {
        char x = w[i - 1];
        int j = n - 1;
        while (w[j] <= x)
            j--;
        swap(w[i - 1], w[j]);
        int q = (i + n) / 2;
        for (int k = i; k < q; ++k)
            sap(w[k], w[n - 1 - k + i]);
        result = w;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
