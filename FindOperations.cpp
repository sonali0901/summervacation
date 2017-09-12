#include <bits/stdc++.h>
using namespace std;
int findOperation( int *arr, int n)
{
	int ans = 0;
	while(1)
	{
		bool set = false;
		int count = 0;
		for(int i=0;i<n;i++)
		{
			if(*(arr+i)==0)
			count++;
		}
		if(count == n)
			break;
		for(int i=0;i<n;i++)
		{
			if(*(arr+i)%2!=0)
			{
				*(arr+i)-=1;
				ans++;
			}
			else
			{
				*(arr+i)/=2;
				set = true;
			}
		}
		if(set==true)
		ans++;
	}
	return ans;

}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<findOperation(arr, n);
}
