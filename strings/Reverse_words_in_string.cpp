#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

string reverseWords(string s)
{
	stringstream ssin(s);
	string temp;
	vector<string> v;
	while(getline(ssin,temp,'.'))
	{
		v.push_back(temp);
	}
	string res = "";
	for(int i = v.size() - 1;i>0;i--)
	{
		res += v[i] + ".";
	}
	res += v[0];
	return res;
}

int main()
{
	int test;
	cin>>test;
	string s;
	for(int o = 0;o<test;o++)
	{
		cin>>s;
		cout<<reverseWords(s)<<endl;
	}
}
