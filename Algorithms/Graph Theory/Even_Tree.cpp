#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct VerTex
{
	bool isMarked;
	vector<int> adjVertex;
	VerTex()
	{
		isMarked = false;
	}
};

int Edge_Removed = 0;

void Reset(VerTex *vertexs, int N)
{
	for (int i = 0; i < N; ++i)
		vertexs[i].isMarked = false;
}

int Count(VerTex *vertexs, int X, vector<int> &b)
{
	//X is root of Tree
	vertexs[X].isMarked = true;
	int S = 1;
	vector<int>::iterator temp;
	for (temp = vertexs[X].adjVertex.begin(); temp != vertexs[X].adjVertex.end(); ++temp)
	{
		int Y = *temp;
		if (!vertexs[Y].isMarked)
			S += Count(vertexs, Y, b);
	}
	b[X] = S;
	return S;
}

void Process(VerTex *vertexs, int X, vector<int> b);
void Process1(VerTex *vertexs, int Y, vector<int> b);

int main()
{
	//ifstream f("a.txt", ios::in);
	int N, M;
	cin >> N >> M;
	VerTex *vertexs = new VerTex[N];
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		vertexs[a].adjVertex.push_back(b);
		vertexs[b].adjVertex.push_back(a);
	}
	vector<int> Num_Node(N);
	Count(vertexs, 0, Num_Node);
	Reset(vertexs, N);
	Process(vertexs, 0, Num_Node);
	cout << Edge_Removed << endl;
	delete[] vertexs;
	vertexs = NULL;
	return 0;
}

void Process1(VerTex *vertexs, int Y, vector<int> b)
{
	vector<int>::iterator temp1;
	vertexs[Y].isMarked = true;
	for (temp1 = vertexs[Y].adjVertex.begin(); temp1 != vertexs[Y].adjVertex.end(); ++temp1)
	{
		int Z = *temp1;
		if (!vertexs[Z].isMarked && b[Z] % 2 == 0)
		{
			Edge_Removed++;
			Process(vertexs, Z, b);
		}
		else if (!vertexs[Z].isMarked)
			Process1(vertexs, Z, b);
	}
}

void Process(VerTex *vertexs, int X, vector<int> b)
{
	vertexs[X].isMarked = true;
	vector<int>::iterator temp;
	for (temp = vertexs[X].adjVertex.begin(); temp != vertexs[X].adjVertex.end(); ++temp)
	{
		int Y = *temp;
		if (!vertexs[Y].isMarked)
		{
			vertexs[Y].isMarked = true;
			if (b[Y] % 2 == 0)
			{
				Edge_Removed++;
				Process(vertexs, Y, b);
			}
			else
				Process1(vertexs, Y, b);
		}
	}
}