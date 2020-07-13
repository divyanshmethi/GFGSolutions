#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(string a,string b)
{
	string ab = a + b;
	string ba = b + a;
	if(ab.compare(ba) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

string largestNumber(string* A,int size)
{
	sort(A,A + size,cmp);
	string res = "";
	for(int i = 0;i<size;i++)
	{
		res += A[i];
	}
	return res;
}

int main() {
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
	    int size;
	    cin>>size;
	    string A[size];
	    for(int i = 0;i<size;i++)
	    {
	        cin>>A[i];
	    }
	    cout<<largestNumber(A,size)<<endl;
	}	
	return 0;
}
