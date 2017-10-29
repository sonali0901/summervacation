#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
void printmatrix(int *mat, int n, int m, stack<pair<int,int>> &st)
{
	while(!st.empty())
	{
		pair <int,int> p = st.top();
		*(mat + p.first*n+p.second) = 8;
		st.pop();
	}	
		
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<< *(mat+i*n+j)<< " ";
		}
		cout<<endl;
	}
}
bool isvalid(int *mat, int x, int y, int n,int m)
{
	return (x>=0 && x<n && y>=0 && y<m && *(mat+x*n+y)==0);
}
bool utility(int *mat, int n, int m, int x, int y, stack <pair<int,int>> &st)
{
	if( x == n-1 && y==m-1)
		return true;
	int xarr[] = {1,0};
	int yarr[] = {0,1};
	for(int i=0;i<2;i++)
	{
		int xtemp = x+xarr[i];
		int ytemp = y+yarr[i];
		if(isvalid (mat, xtemp, ytemp, n, m))
		{
			st.push(make_pair(xtemp,ytemp));
			if(utility(mat, n, m, xtemp, ytemp, st))
			{
				return true;
			}
			else
				st.pop();
		}
	}
	return false;
}
void Ratsproblem(int *mat, int n, int m)
{
	int x =0;
	int y=0;
	stack <pair<int,int>> st;
	st.push(make_pair(x,y));
	if(utility(mat, n, m, x, y, st))
	{
		cout<<"Possible"<<endl;
		printmatrix(mat, n, m,st);
	}
	else
		cout<<"Not Possible"<<endl;
}
int main() {
	int n,m;
	cin>>n>>m;
	int mat[n][m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}
	Ratsproblem(mat[0],n,m);
	return 0;
}
