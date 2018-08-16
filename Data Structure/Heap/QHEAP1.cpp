#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void ReheapUp3(int heap[], int pos)
{
    int parent = (pos - 1)/2;
    while (parent >= 0 && heap[pos] < heap[parent])
    {
        swap(heap[pos], heap[parent]);
        pos = parent;
        parent = (pos - 1)/2;
    }
}

void InsertMinHeap(int heap[], int value, int &Size)
{
    //last = size - 1
    heap[Size] = value;
    ReheapUp3(heap, Size);
    Size++;
}

int search(int heap[], int size, int b, int start)
{
    if (b == heap[start])
        return start;
    else if (b > heap[start])
    {
        int l = start * 2 + 1, r = l + 1;
        int vt = 0;
        if (l < size)
        {
            vt = search(heap, size, b, l);
            if (vt >= 0)
                return vt;
            else if(r < size)
                return search(heap, size, b, r);        
        }
        return -1;
    }
    else 
        return -1;
}

void ReheapDown(int heap[], int pos, int last)
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

void BestBuildHeap(int heap[], int Size)
{
    int start = (Size % 2 == 0) ? Size/2 : (Size/2 + 1);
    for (int i = start; i >= 0; --i)
        ReheapDown(heap, i, Size - 1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int heap[100000] = {}, size = 0;
    int Q, a, b;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        cin >> a;
        if (a == 3)
            cout << heap[0] << endl;
        else if (a == 1)
        {
            cin >> b;
            //Chen b vao min heap
            InsertMinHeap(heap, b, size);
        }
        else 
        {
            cin >> b;
            //delete b from heap
            //Tim vi tri
            int vt = search(heap, size, b, 0);
            //Xoa
            for (int i = vt; i < size - 1; ++i)
                heap[i] = heap[i + 1];
            size--;
            //Build heap
            BestBuildHeap(heap, size);
        }
    }
    return 0;
}
