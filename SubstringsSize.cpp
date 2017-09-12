#include <bits/stdc++.h>
using namespace std;

int CountSubstrings(string s, int k)
{
	int count=0;
	set<char> set1;
	for(int i=0;i<s.length();i++)
	{
		for(int j=i;j<s.length();j++)
		{
			set1.insert(s[j]);
			if(set1.size()==k)
			{
				count++;
			}
		}
		set1.clear();
	}
	return count;
}
int main() {
	string s;
	cin>>s;
	int k;
	cin>>k;
	cout<<CountSubstrings(s, k)<<endl;
	return 0;
}
