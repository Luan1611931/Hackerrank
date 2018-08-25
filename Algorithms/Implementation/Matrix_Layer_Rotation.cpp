#include <bits/stdc++.h>

using namespace std;

// Complete the matrixRotation function below.
void printM(vector<vector<int>> matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void superSwap(vector<vector<int>> &matrix, int i, vector<int> &a)
{
    int t = 0, m = matrix.size(), n = matrix[0].size();
    for (int j = i; j < n - i; ++j)
    {
        swap(a[t], matrix[i][j]);
        t++;
    }
    for (int j = i + 1; j < m - i; ++j)
    {
        swap(a[t], matrix[j][n - 1 - i]);
        t++;
    }
    for (int j = n - i - 2; j >= i; --j)
    {
        swap(a[t], matrix[m - i - 1][j]);
        t++;
    }
    for (int j = m - i - 2; j > i; --j)
    {
        swap(a[t], matrix[j][i]);
        t++;
    }
}

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size(), n = matrix[0].size();
    int min = (m < n) ? m : n;
    for (int i = 0; i < min / 2; ++i)
    {
        int s = 2 * (m + n - 4 * i) - 4;
        vector<int> a(s, 0), b(s, 0);
        superSwap(matrix, i, a);
        
        for (int j = 0; j < s; ++j)
        {
            int h = (j - r) % s;
            if (h < 0)
                h += s;
            b[h] = a[j];
        }
        superSwap(matrix, i, b);
    }
    printM(matrix);
}

int main()
{
    int m, n, r;
    cin >> m >> n >> r;
    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int k;
            cin >> k;
            matrix[i].push_back(k);
        }
    }

    matrixRotation(matrix, r);

    return 0;
}
