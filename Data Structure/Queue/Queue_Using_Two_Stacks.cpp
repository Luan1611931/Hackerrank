#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    queue<int> qe;
    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int param;
            cin >> param;
            qe.push(param);
        }
        else if (type == 2)
            qe.pop();
        else
            cout << qe.front() << endl;
    }
    return 0;
}
