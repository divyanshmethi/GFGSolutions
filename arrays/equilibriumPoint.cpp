#include<iostream>
#include<vector>
using namespace std;


int findEquilPoint(int* A,int size)
{
	vector<int> left(size,0);
	vector<int> right(size,0);
	left[0] = 0;
	right[size - 1] = 0;
	for(int i = 1;i<size;i++)
	{
		left[i] = left[i - 1] + A[i - 1];
	}
	for(int i = size-2;i>=0;i--)
	{
		right[i] = right[i+1] + A[i+1];
	}
	for(int i = 0;i<size;i++)
	{
		if(left[i] == right[i])
		{
			return i + 1;
		}
	}
	return -1;
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
		cout<<findEquilPoint(A,size)<<endl;
	}
}
