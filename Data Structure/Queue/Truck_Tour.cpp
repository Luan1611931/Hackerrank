#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the truckTour function below.
 */
typedef __int64_t chorong;

struct petrol_pump
{
    int petrol;
    int distance;
};

int truckTour(vector<petrol_pump> petrol_pumps) {
    int n = petrol_pumps.size();
    chorong T = 0;
    int x = 0, t = 0, result = -1;
    bool h = true;
    while (h)
    {
        chorong S = 0;
        t = x;
        while (S >= 0)
        {
            if (x == n)
            {
                h = false;
                break;
            }
            S = S + petrol_pumps[x].petrol - petrol_pumps[x].distance;
            x++;
        }
        T = T + S;
    }
    if (T >= 0)
        result = t;
    return result;
}

int main(){
    int N;
    cin >> N;
    vector<petrol_pump> petrol_pumps(N);
    for (int i = 0; i < N; ++i)
        cin >> petrol_pumps[i].petrol >> petrol_pumps[i].distance;
    int index = truckTour(petrol_pumps);
    cout << index << endl;
    return 0;
}