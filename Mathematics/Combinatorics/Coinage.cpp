#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int count_num_ways(int n,int A2, int A3)
{
    int x = n / 2, y = n % 2;
    int count = 0;
    while (x >= 0)
    {
        if (x <= A3 && y <= A2)
            count++;
        else if (y > A2)
            break;
        y = y + 2;
        x--;
    }
    return count;
}

int solve(int n, vector<int> coins) {
    if (n == 0)
        return 1;
    int A1, A2, A3;
    A1 = (n / 2 < coins[1]) ? n / 2 : coins[1];
    A2 = (n / 5 < coins[2]) ? n / 5 : coins[2];
    A3 = (n / 10 < coins[3]) ? n / 10 : coins[3];
    int A4 = (n / 5 < (A2 + 2 * A3)) ? n / 5 : (A2 + 2 * A3);
    int num_ways = 0, str = (n % 2 == 0) ? 0 : 1;
    for (int i = str; i <= A4; i += 2)
    {
        int m = (n - 5 * i) / 2;
        if (m <= A1)
            num_ways = num_ways + count_num_ways(i, A2, A3);
    }
            
    int result;
    if (coins[0] == 0)
        result = num_ways;
    else
    {
        coins[0]--;
        result = num_ways + solve(n - 1, coins);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string coins_temp_temp;
        getline(cin, coins_temp_temp);

        vector<string> coins_temp = split_string(coins_temp_temp);

        vector<int> coins(4);

        for (int coins_itr = 0; coins_itr < 4; coins_itr++) {
            int coins_item = stoi(coins_temp[coins_itr]);

            coins[coins_itr] = coins_item;
        }

        int result = solve(n, coins);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
