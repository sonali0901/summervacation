#include <iostream>
using namespace std;
void printmatrix(int *mat, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<*(mat+i*n+j)<< " ";
		
		cout<<endl;
	}
}
bool isvalid(int *mat, int row, int col, int n)
{
	bool flag = true;
	//check all before columns and queens walk
	for(int i=row, j=col; i>=0 &&j>=0; i--,j--)
	{
		if(*(mat+i*n+j)==1)
			flag = false;
	}
	for(int i=row, j=col; i<n &&j>=0; i++,j--)
	{
		if(*(mat+i*n+j)==1)
			flag = false;
	}
	for(int j=col; j>=0; j--)
	{
		if(*(mat+row*n+j)==1)
			flag = false;
	}
	return (row>=0 && row<n && col>=0 &&col<n && flag);
}
bool utility(int *mat, int col, int n)
{
	if(col==n)
		return true;
	//for all rows
	for(int i=0;i<n;i++)
	{
		if(isvalid(mat, i, col, n))
		{
			*(mat+i*n+col) = 1;
			if(utility(mat, col+1, n))
				return true;
			else
			*(mat+i*n+col) = 0;
		}
	}
	return false;
}
void SetQueen(int n)
{
	int mat[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			mat[i][j] = 0;
		}
	}
	int col = 0;
	if (utility (mat[0], col, n))
	{
		cout<<"Possible"<<endl;
		printmatrix(mat[0], n);
	}
	else
		cout<<"Not Possible"<<endl;
	
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	SetQueen(n);
	
	return 0;
}
