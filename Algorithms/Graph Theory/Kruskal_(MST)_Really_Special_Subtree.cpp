#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Edge
{
	int x, y, wt;
	bool operator>(const Edge& e)
	{
		if (wt > e.wt)
			return true;
		else if (wt < e.wt)
			return false;
		else
		{
			if (x + y + wt > e.x + e.y + e.wt)
				return true;
			else
				return false;
		}
	}
	bool operator<(const Edge& e)
	{
		if (wt < e.wt)
			return true;
		else if (wt > e.wt)
			return false;
		else
		{
			if (x + y + wt < e.x + e.y + e.wt)
				return true;
			else
				return false;
		}
	}
	bool operator>=(const Edge &e)
	{
		return !(*this < e);
	}
	bool operator<=(const Edge &e)
	{
		return !(*this > e);
	}
};

struct Vertex
{
	bool isMarked;
	vector<int> adjVertex;
	Vertex()
	{
		isMarked = false;
	}
};

void Reset(vector<Vertex> &V)
{
	vector<Vertex>::iterator temp;
	for (temp = V.begin(); temp != V.end(); ++temp)
		temp->isMarked = false;
}

bool Find(vector<int> v, int Y)
{
	vector<int>::iterator temp;
	for (temp = v.begin(); temp != v.end(); ++temp)
		if (*temp == Y)
			return true;
	return false;
}

bool Check(vector<Vertex> &v, int X, int Y)
{
	v[X].isMarked = true;
	if (Find(v[X].adjVertex, Y))
		return true;
	else
	{
		vector<int>::iterator temp1;
		for (temp1 = v[X].adjVertex.begin(); temp1 != v[X].adjVertex.end(); ++temp1)
		{
			int ver = *temp1;
			if (!v[ver].isMarked)
				if (Check(v, ver, Y))
					return true;
		}
		return false;
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	Edge *Edges = new Edge[M];
	for (int i = 0; i < M; ++i)
	{
		cin >> Edges[i].x >> Edges[i].y >> Edges[i].wt;
		Edges[i].x--;
		Edges[i].y--;
	}
	sort(Edges, Edges + M);
	vector<bool> vertexs(N, false);
	vector<Vertex> Vertexs(N);
	int i = 0, n = 0;
	long long S = 0;
	while (n < N - 1)
	{
		int X = Edges[i].x, Y = Edges[i].y;
		if (vertexs[X] && vertexs[Y])
		{
			Reset(Vertexs);
			if (!Check(Vertexs, X, Y))
			{
				S += Edges[i].wt;
				n++;
				Vertexs[X].adjVertex.push_back(Y);
				Vertexs[Y].adjVertex.push_back(X);
			}
		}
		else
		{
			vertexs[X] = vertexs[Y] = true;
			Vertexs[X].adjVertex.push_back(Y);
			Vertexs[Y].adjVertex.push_back(X);
			n++;
			S += Edges[i].wt;
		}
		i++;
	}
	cout << S << endl;
	delete[] Edges;
	return 0;
}
