#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findElement(int* A,int size)
{
	vector<int> left(size);
	left[0] = INT_MIN;
	vector<int> right(size);
	right[size - 1] = INT_MAX;
	for(int i = 1;i<size;i++)
	{
		left[i] = max(left[i-1],A[i-1]);
	}
	for(int i = size - 2;i >= 0;i--)
	{
		right[i] = min(right[i+1],A[i+1]);
	}
	for(int i = 1;i<size-1;i++)
	{
		if(A[i] >= left[i] && A[i] <= right[i])
		{
			return A[i];
		}
	}
	return -1;
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
	    cout<<findElement(A,size)<<endl;
	}
	return 0;
}
