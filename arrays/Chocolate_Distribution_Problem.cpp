#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(long long* A,long long size,long long k)
{
	sort(A,A + size);
	long long minDiff = INT_MAX;
	for(long long i = 0;i<=size - k;i++)
	{
		minDiff = min(minDiff,A[i + k - 1] - A[i]);
	}
	return minDiff;
}

int main() {
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
	    long long size;
	    cin>>size;
	    long long A[size];
	    for(long long i = 0;i<size;i++)
	    {
	        cin>>A[i];
	    }
	    long long k;
	    cin>>k;
	    cout<<findMinDiff(A,size,k)<<endl;
	}
	return 0;
}
