#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> votes = { "john", "johnny", "jackie",
                         "johnny", "john", "jackie",
                         "jamie", "jamie", "john",
                         "johnny", "jamie", "johnny",
                         "john" };
 
	map <string, int> mp;
	int max = -1;
	string ans = "";
	for(int i=0;i<votes.size();i++)
	{
		mp[votes[i]]++;
	}
	for(auto itr = mp.begin(); itr!= mp.end();itr++)
	{
		if(max< itr->second)
		{
			max = itr->second;
			ans = itr->first;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
