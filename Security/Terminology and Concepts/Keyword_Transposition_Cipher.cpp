#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string after_remove_duplicate_character(string keyword)
{
    string ardc_kw;
    for (int i = 0; i < keyword.size(); ++i)
    {
        bool x = true;
        for (int j = 0; j < ardc_kw.size(); ++j)
        {
            if (ardc_kw[j] == keyword[i])
            {
                x = false;
                break;
            }
        }
        if (x)
            ardc_kw.push_back(keyword[i]);
    }
    return ardc_kw;
}

void InsertionSort(vector<string> &a)
{
    int n = a.size();
    for (int i = 1; i < n; ++i)
    {
        int k = i - 1;
        string x = a[i];
        while (k >= 0 && a[k] > x)
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = x;
    }
}

string get_subtitution(string ardc)
{
    vector<bool> T(26, false);
    int n = ardc.size();
    for (int i = 0; i < n; ++i)
    {
        int j = ardc[i] - 'A';
        T[j] = true;
    }
    int m = 26 / n, r = 26 % n;
    m = (r > 0) ? m + 1 : m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        string str(m);
        a[i] = str;
        a[i][0] = ardc[i];
    }
    int k = 0, l = 0, h = n - 1;
    while (k < 26)
    {
        if (!T[k])
        {
            char X = 'A' + k;
            if (h == n - 1)
            {    
                h = 0;
                l++;
            }
            else
                h++;
            a[h][l] = X;
        }
        k++;
    }
    InsertionSort(a);
    string P(26);
    for (int i = r; i < n; ++i)
        a[i].pop_back();
    int w = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0 ; j < a.size(); ++j)
        {
            char Y = a[i][j];
            int y = Y - 'A';
            P[y] = char(w + 'A');
            w++;
        }
    }
    return P;
}

string get_original_message(string subs, string cipher)
{
    string message;
    for (int i = 0; i < cipher.size(); ++i)
    {
        int x = cipher[i] + 'A';
        message.push_back(subs[x]);
    }
    return message;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin >> N;
    for (int i_c = 0; i_c < N; ++i_c)
    {
        string keyword, cipher;
        cin >> keyword >> cipher;
        string ardc = after_remove_duplicate_character(keyword);
        string subs = get_subtitution(ardc);
        string message = get_original_message(subs, cipher);
        cout << message << endl;
    }
    return 0;
}
