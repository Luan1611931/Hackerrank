#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Lon[100000] = {} , Be[100000] = {}, size1 = 0, size2 = 0, _size = 1;
double median = 0;


void ReheapUp1(int heap[], int pos)
{
    if (pos > 0)
    {
        int parent = (pos - 1)/2;
        if (heap[pos] > heap[parent])
        {
            int tam = heap[parent];
            heap[parent] = heap[pos];
            heap[pos] = tam;
            ReheapUp1(heap, parent);
        }
    }
}

void InsertMaxHeap(int heap[], int value, int &Size)
{
    //last = size - 1
    heap[Size] = value;
    ReheapUp1(heap, Size);
    Size++;
}

void ReheapUp2(int heap[], int pos)
{
    if (pos > 0)
    {
        int parent = (pos - 1)/2;
        if (heap[pos] < heap[parent])
        {
            swap(heap[pos], heap[parent]);
            ReheapUp2(heap, parent);
        }
    }
}


void InsertMinHeap(int heap[], int value, int &Size)
{
    //last = size - 1
    heap[Size] = value;
    ReheapUp2(heap, Size);
    Size++;
}

void ReheapDown3(int heap[], int pos, int last)
{
    int leftC = pos*2 + 1, rightC = pos*2 + 2;
    while (leftC <= last)
    {
        int maxC;
        if (rightC <= last)
            maxC = (heap[leftC] < heap[rightC]) ? leftC : rightC;
        else
            maxC = leftC;
        if (heap[pos] > heap[maxC])
            swap(heap[pos], heap[maxC]);
        else
            break;
        pos = maxC;
        leftC = pos * 2 + 1;
        rightC = leftC + 1;
    }
}

void ReheapDown(int heap[], int pos, int last)
{
    int leftC = pos*2 + 1, rightC = pos*2 + 2;
    while (leftC <= last)
    {
        int maxC;
        if (rightC <= last)
            maxC = (heap[leftC] > heap[rightC]) ? leftC : rightC;
        else
            maxC = leftC;
        if (heap[pos] < heap[maxC])
            swap(heap[pos], heap[maxC]);
        else
            break;
        pos = maxC;
        leftC = pos * 2 + 1;
        rightC = leftC + 1;
    }
}

void Median(int value)
{
    if (_size % 2 == 0)
    {
        int x = (int)median;
        if (x > value)
        {
            InsertMaxHeap(Be, value, size2);
            InsertMinHeap(Lon, x, size1);
        }
        else
        {
            InsertMaxHeap(Be, x, size2);
            InsertMinHeap(Lon, value, size1);
        }
        median = (Lon[0] + Be[0])*1.0/2;
    }
    else
    {
        if (value <= Lon[0] && value >= Be[0])
        {
            median = value * 1.0;
        }
        else if (value < Be[0])
        {
            median = Be[0] * 1.0;
            Be[0] = value;
            ReheapDown(Be, 0, size2 - 1);
        }
        else
        {
            median = Lon[0] * 1.0;
            Lon[0] = value;
            ReheapDown3(Lon, 0, size1 - 1);
        }
    }
    cout << median;
}

int main()
{
    int n, value;
    cin >> n;
    cout << fixed << setprecision(1);
    cin >> value;
    median = value;
    cout << median;
    
    for (int i = 1; i < n; ++i)
    {
        cout << endl;
        cin >> value;
        _size++;
        Median(value);
    }
    return 0;
}