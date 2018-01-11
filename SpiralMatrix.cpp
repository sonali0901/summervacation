#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int  n,m;
	cin>>n>>m;
	int mat[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}
	int tr=0, br=n-1, lc=0,rc=m-1;
	while(tr<=br||lc<=rc){
		for(int i=lc;i<=rc;i++)
		{
			cout<<mat[tr][i]<<" ";
		}
		tr++;
		for(int i=tr;i<=br;i++)
		{
			cout<<mat[i][rc]<<" ";
		}
		rc--;
		for(int i=rc;i>=lc;i--)
		{
			cout<<mat[br][i]<<" ";
		}
		br--;
		for(int i=br;i>=tr;i--)
		{
			cout<<mat[i][lc]<<" ";
		}
		lc++;
		
	}
	return 0;
}
