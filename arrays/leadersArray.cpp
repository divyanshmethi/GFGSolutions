#include<iostream>
#include<vector>
using namespace std;

void findLeaders(int* A,int size)
{
	vector<int> res;
	if(size==0)
	{
		return;
	}
	res.push_back(A[size-1]);
	int maxSoFar = A[size - 1];
	for(int i = size - 2;i>=0;i--)
	{
		maxSoFar = max(A[i],maxSoFar);
		if(A[i] == maxSoFar)
		{
			res.push_back(A[i]);
		}
	}
	for(int i = res.size() - 1;i>=0;i--)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
		int size;
		cin>>size;
		int A[size];
		for(int i = 0;i<size;i++)
		{
			cin>>A[i];
		}
		findLeaders(A,size);
	}
}
