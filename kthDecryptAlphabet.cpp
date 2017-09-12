#include <bits/stdc++.h>
using namespace std;
char kthcharacter( string s, int k)
{
	bool flag = false;
	string temp = "";
	string no = "";
	string ans="";
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a'&& s[i]<='z'&& !flag)
		{
			temp+=s[i];
			//cout<<temp;
		}
		else if (s[i]>='1' && s[i]<='9')
		{
			no+=s[i];
			flag = true;
		}
		else if (s[i]>='a'&& s[i]<='z'&& flag)
		{
			flag = false;
			int frequency = stoi(no);;
			for(int j=0;j<frequency;j++)
				ans+=temp;
			no="";
			temp="";
			temp+=s[i];
		}
		if(i==s.length()-1 && no!="")
		{
			int frequency = stoi(no);;
			for(int j=0;j<frequency;j++)
				ans+=temp;	
		}
	}
	cout<<ans[k-1];
	return ans[k-1];
}
int main() {
	string s;
	cin>>s;
	int k;
	cin>>k;
	kthcharacter(s, k);
	return 0;
}
