#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string message, cipher;
    int e;
    cin >> message >> e;
    for (int i = 0; i < message.size(); ++i)
    {
        int x = (int)message[i] - '0';
        x = (x + e) % 10;
        char y = x + '0';
        cipher.push_back(y);
    }
    cout << cipher << endl;
    return 0;
}
