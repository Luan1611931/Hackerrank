#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int T[3][3] = {
    {8, 3, 4},
    {1, 5, 9},
    {6, 7, 2}
};
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void CV(int arr[][3])
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (i < j)
                swap(arr[i][j], arr[j][i]);
}

int Cost(int arr[][3], int brr[][3])
{
    int S = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            S += (int)abs(brr[i][j] - arr[i][j]);
    return S;
}

int MinCost(int arr[][3], int brr[][3])
{
    int Min = Cost(arr, brr);
    //Doi hang
    for (int i = 0; i < 3; ++i)
        swap(arr[0][i], arr[2][i]);
    int t = Cost(arr, brr);
    if (Min > t)
        Min = t;
    //Doi cot
    for (int i = 0; i < 3; ++i)
        swap(arr[i][0], arr[i][2]);
    t = Cost(arr, brr);
    if (Min > t)
        Min = t;
    //Doi hang
    for (int i = 0; i < 3; ++i)
        swap(arr[0][i], arr[2][i]);
    t = Cost(arr, brr);
    if (Min > t)
        Min = t;
    return Min;
}

int formingMagicSquare(vector<vector<int>> s) {
    int brr[3][3] = {};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            brr[i][j] = s[i][j];
    int M1 = MinCost(T, brr);
    CV(T);
    int M2 = MinCost(T, brr);
    if (M1 < M2)
        return M1;
    else
        return M2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
