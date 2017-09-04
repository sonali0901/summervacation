#include <bits/stdc++.h>
using namespace std;
struct node{
	int place;
	int steps;
};
void minroll(int n, int move[])
{
	/*for(int i=0;i<n;i++)
	cout<<move[i]<<" ";
	cout<<endl;*/
	bool visited[n];
	for(int i=0;i<n;i++)
	visited[i]=false;
	queue<node> q;
	visited[0]=true;
	struct node nod;
	nod.place=0;
	nod.steps =0;
	q.push(nod);
	while(!q.empty())
	{
		nod = q.front();
		q.pop();
		//cout<<nod.place<<" ";
		if(nod.place==(n-1)){
			break;
		}
		
		for(int i=1;i<=6 && nod.place+i<n;i++)
		{
			if(!visited[nod.place+i])
			{
				node temp;
				temp.steps = nod.steps+1;
				visited[nod.place+i] = true;
				if(move[nod.place+i]!=-1)
				{
					temp.place = move[nod.place+i];
					visited[temp.place] = true;
				}
				else
					temp.place = nod.place+i;
				q.push(temp);
			}
		}
	}
	cout<<nod.steps;
	
}
int main() {
	int n;
	cin>>n;
	int move[n];
	for(int i= 0;i<n;i++)
	move[i] =-1; //stays at same place
	int q;//queries
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int s, e;
		cin>>s>>e;
		move[s]=e;
	}
	minroll(n, move);
	return 0;
}
