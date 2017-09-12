#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void find(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	if(l1< l2)
	{
		cout<<"less length"<<endl;
		return;
	}
	else
	{
		unordered_map<char, int> m1,m2;
		for(int i=0;i<l2;i++)
			m2[s2[i]]++;
		int count = 0, start = 0, ans = -1, min_win = INT_MAX;
		for(int i=0;i<l1;i++)
		{
			m1[s1[i]]++;
			
			if(m2[s1[i]]!=0 && m2[s1[i]] >= m1[s1[i]] ) // the char exists and has occured less number of times 
			count++;
			//cout<<s1[i]<<" "<<count<<endl;
			if(count == l2)
			{
				while(m2[s1[start]]==0 || m1[s1[start]] > m2[s1[start]] )
				{
					if( m1[s1[start]] > m2[s1[start]])
						m1[s1[start]]--;
					start++;
				}
				
				int length = i-start+1; // window size
				if(min_win> length)
				{
					min_win = length;
					ans = start;
				}
			}
			
		}
		if(ans==-1)
			cout<<" doesn't exist"<<endl;
		else
		{
			for(int i = ans; i<ans+min_win;i++)
				cout<<s1[i];
			cout<<endl;
		}
			
	}
}
int main() {
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	find(s1, s2);
	
	return 0;
}
