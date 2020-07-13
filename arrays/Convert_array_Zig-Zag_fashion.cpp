#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void convertZigZag(int* A,int size)
{
	for(int i = 0;i<size;i++)
	{
		if(i%2==0 && i > 1)
		{
			if(A[i] > A[i-1])
			{
				swap(A[i],A[i-1]);
			}
		}
		else
		{
			if(A[i] < A[i-1])
			{
				swap(A[i],A[i-1]);
			}
		}
	}
	for(int i = 0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main() {
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
	    convertZigZag(A,size);
	}
	return 0;
}
