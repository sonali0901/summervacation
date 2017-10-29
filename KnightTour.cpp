#include <iostream>
using namespace std;
bool isvalid(int *mat, int x, int y, int n)
{
	return (x>=0 && x<n && y>=0 && y<n && *(mat+x*n+y)==-1);
}

bool utility(int *mat, int n, int x, int y, int count)
{
	if(count == n*n)
		return true;
    int xarr[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yarr[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	//mat[x][y]=count
	//cout << *(mat+x*n+y)<<endl;

	for(int i=0;i<8;i++)
	{
		int xtemp = x+xarr[i];
		int ytemp = y+yarr[i];
		if(isvalid(mat, xtemp, ytemp, n))
		{
			*(mat+xtemp*n+ytemp) = count;
			
			if(utility(mat, n, xtemp, ytemp, count+1))
				return true;
			else
				*(mat+xtemp*n+ytemp)=-1;
		}
	}
	return false;
}
void printmatrix (int *mat, int n)
{
	for(int i=0;i<n ;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<< *(mat +i*n+j)<<" ";
		}
		cout<<endl;
	}
}
void isPossibleKnight(int n)
{
	int mat[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			mat[i][j]=-1;
		}
	}
	int count = 1;
	mat[0][0] = 0;
	if(utility(mat[0], n,0,0,count))
	{
		cout<<"Is Possible"<<endl;
		printmatrix(mat[0],n);
	}
	else
		cout<<"Not Possible"<<endl;
	
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	isPossibleKnight(n);
	return 0;
}
