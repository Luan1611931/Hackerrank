#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the movingTiles function below.
 */
vector<double> movingTiles(int l, int s1, int s2, vector<long long> queries) {
    /*
     * Write your code here.
     */
    vector<double> res;
    for (int i = 0; i < queries.size(); ++i)
    {
        double t;
        t = sqrt(2) * ((l - sqrt(queries[i])) / abs(s1 - s2));
        res.push_back(t);
    }
    return res;
}

int main()
{

    int l, s1, s2, q;
    cin >> l >> s1 >> s2 >> q;
    vector<long long> queries(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> queries[i];
    }
    vector<double> ts = movingTiles(l, s1, s2, queries);
    for (int i = 0; i < ts.size(); ++i)
        cout << setprecision(4) << fixed << ts[i] << endl;

    return 0;
}