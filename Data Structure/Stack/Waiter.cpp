#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the waiter function below.
 */
bool is_prime(int n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    int x = (int)sqrt(n);
    for (int i = 5; i <= x; i += 2)
        if (i % 6 == 1 || i % 6 == 5)
            if (n % i == 0)
                return false;
    return true;
}

vector<int> primes(int n)
{
    vector<int> _primes(1);
    _primes[0] = 2;
    if (n > 1)
    {
        int prime = 3;
        while (_primes.size() < n)
        {
            while(!is_prime(prime))
                prime += 2;
            _primes.push_back(prime);
            prime += 2;
        }
    }
    return _primes;
}

vector<int> waiter(vector<int> number, int q) {
    /*
     * Write your code here.
     */
    vector<int> M = primes(q);
    vector<int> A(number);
    vector<int> C;
    for (int i = 0; i < q; ++i)
    {
        vector<int> B, A1;
        while (!A.empty())
        {
            int y = A.back();
            A.pop_back();
            if (y % M[i] == 0)
                B.push_back(y);
            else
                A1.push_back(y);
        }
        while (!B.empty())
        {
            int z = B.back();
            B.pop_back();
            C.push_back(z);
        }
        A.swap(A1);
    }
    while (!A.empty())
    {
        int z = A.back();
        A.pop_back();
        C.push_back(z);
    }
    return C;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
