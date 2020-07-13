#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printPermutation(string s)
{
	vector<string> v;
	do
	{
		v.push_back(s);
	}while(next_permutation(s.begin(),s.end()));
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	string s;
	for(int o = 0;o<test;o++)
	{
		cin>>s;
		printPermutation(s);
	}
}
