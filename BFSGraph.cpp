#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
public:
	Graph(int v);
	void addEdge(int v, int z);
	void BFS(int s);
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int z)
{
	adj[v].push_back(z);
}

void Graph::BFS(int s)
{
	vector<bool> visited(V);
	for(int i=0;i<V;i++)
		visited[i] = false;
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int element = q.front();
		cout<<element<<" ";
		q.pop();
		for(auto it = adj[element].begin(); it!=adj[element].end();it++)
		{
			if(!visited[*it])
			{
				q.push(*it);
				visited[*it]=true;
			}
		}
	}
}
int main() {
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(2,0);
	g.addEdge(3,3);
	g.BFS(2);
	return 0;
}
