#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, f;
	cin>>n;
	int mat[n][n];
	cin>>f;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	bool find = false;
	int x = 0, y = n-1;
	while(x<n&&y>=0)
	{
		if(mat[x][y]==f)
		{
			find = true;
			break;
		}
		else if(mat[x][y]>f)
		{
			y--;
		}
		else
		{
			x++;
		}
			
	}
	if(find)
		cout<<x<<", "<<y;
	else
		cout<<"Not Found";
	return 0;
	
	/* input
	4
	29
	10 20 30 40 
	15 25 35 45
	27 29 37 48 
	32 33 39 50
	*/
}
