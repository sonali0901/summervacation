#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isvalid(int *mat, int v, int i, map<int,int> &mp, int n)
{
	for(int j=0;j<n;j++)
	{
		if(*(mat+v*n + j)&&mp.find(j)!=mp.end())//if adjacent
		{
			if(mp[j]==i)
				return false;
		}
	}
	return true;
}
void printmap( map<int, int> &mp)
{
	for(auto it = mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<< " "<<it->second<<endl;
	}
}
bool utility(int *mat, int n, int m, int v, map<int,int> &mp)
{
	if(v==n)
		return true;
	for(int i=0;i<m;i++)
	{
		if(isvalid(mat, v, i, mp, n))
		{
			mp[v] = i;
			if(utility(mat, n, m, v+1,mp))
				return true;
			else
				mp[v] = -1;
		}
	}
	return false;
}
void colorit(int *mat, int n, int m, int v)
{
	map<int,int> mp;
	if(utility (mat, n, m, 0, mp))
	{
		cout<<"Possible"<<endl;
		printmap(mp);
	}
	else
		cout<<"Not possible ";	
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int mat[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	int m;
	cin>>m;
	colorit(mat[0],n,m, 0);
	return 0;
}
