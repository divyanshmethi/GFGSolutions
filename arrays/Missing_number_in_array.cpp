#include<iostream>
using namespace std;

int findMissingNumber(int* A,int size)
{
	int xorRes = 1;
	for(int i = 2;i<=size;i++)
	{
		xorRes ^= i;
	}
	for(int i = 0;i<size-1;i++)
	{
		xorRes ^= A[i];
	}
	return xorRes;
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
		for(int i = 0;i<size-1;i++)
		{
			cin>>A[i];
		}
		cout<<findMissingNumber(A,size)<<endl;
	}
}
