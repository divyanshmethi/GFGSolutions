#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findKthElement(int* A,int size,int k)
{
	int low = *min_element(A, A + size);
	int high = *max_element(A, A + size);
	int mid;
	while(low < high)
	{
		mid = (low + high)/2;
		int countLess = 0,countEqual = 0;
		for(int i = 0;i<size;i++)
		{
			if(A[i] < mid)
			{
				countLess++;
			}
			else if(A[i] == mid)
			{
				countEqual++;
			}
		}
		if(countLess < k && (countEqual + countLess) >= k)
		{
			return mid;
		}
		else if(countLess >= k)
		{
			high = mid - 1;
		}
		else if(countLess < k && (countLess + countEqual) < k)
		{
			low = mid + 1;
		}
	}
}

int main()
{
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
		int size,k;
		cin>>size;
		int A[size];
		for(int i = 0;i<size;i++)
		{
			cin>>A[i];
		}
		cin>>k;
	    cout<<findKthElement(A,size,k)<<endl;
	}
}
