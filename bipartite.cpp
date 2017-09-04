#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int v=0;

struct graph{
	int v;
	list <int> *adj;
};
struct graph *create(int v){
	struct graph *g = new graph();
	g->v=v;
	g->adj = new list<int>[v];
	return g;
}
bool ispos(struct graph *g, int color[], int v)
{
	queue<int> q;
	
	for(int i=0;i<v;i++)
	{
		if(color[i]==-1)
		{
			q.push(i);
			color[i]=1;
			while(!q.empty())
			{
				int temp = q.front();
				//cout<<temp<< "."<<endl;
				q.pop();
				for(auto j=g->adj[temp].begin();j!=g->adj[temp].end();j++)
				{
					//cout<<color[*j]<<endl;
					if(color[*j]==-1)
					{
						color[*j] = color[temp]^1;
						q.push(*j);
					}
					else if(color[*j]==color[temp])
						return false;
				}
			}
		}

	}
	for(int i=0;i<v;i++)
	cout<<color[i]<<" ";
	cout<<endl;
	return true;
}
int main() {
	cin>>v;
	struct graph *g = create(v);
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			int temp;
			cin>>temp;
			if(temp==1)
			g->adj[i].push_back(j);
		}
	}
	int color[v];
	for(int i=0;i<v;i++)
	color[i] = -1;
	cout<<ispos(g, color,v);
	return 0;
}
