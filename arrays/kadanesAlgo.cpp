#include<iostream>
using namespace std;

int kadanes(int* A,int size)
{
	int curr_max = A[0];
	int max_so_far = A[0];
	for(int i = 1;i<size;i++)
	{
		curr_max = max(curr_max + A[i],A[i]);
		max_so_far = max(max_so_far,curr_max);
	}
	return max_so_far;
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
		cout<<kadanes(A,size)<<endl;
	}
}
