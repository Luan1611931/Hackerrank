#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q = 0;
    string S;
    stack<string> st;
    st.push(S);
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            string W;
            getline(cin, W);
            W.erase(0, 1);
            S = S + W;
            st.push(S);
        }
        else if (type == 2)
        {
            int k;
            cin >> k;
            int n = S.length();
            S.resize(n - k);
            st.push(S);
        }
        else if (type == 3)
        {
            int k;
            cin >> k;
            cout << S[k - 1] << endl; 
        }
        else
        {
            st.pop();
            S = st.top();
        }
    }
    return 0;
}
