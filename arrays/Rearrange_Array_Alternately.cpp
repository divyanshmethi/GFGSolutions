#include<iostream>
using namespace std;

//void reArrange(long long* A,long long size)
//{
//	long long maxIndex = size - 1, minIndex = 0;
//	long long maxElement = A[size - 1] + 1;
//	for(int i = 0;i<size;i++)
//	{
//		if(i%2 == 0)
//		{
//			A[i] += (A[maxIndex] % maxElement) * maxElement;
//			maxIndex--;
//		}
//		else
//		{
//			A[i] += (A[minIndex] % maxElement) * maxElement;
//			minIndex++;
//		}
//	}
//	for(long long i = 0;i<size;i++)
//	{
//		A[i] = A[i]/maxElement;
//		cout<<A[i]<<" ";
//	}
//}


void reArrange(long long* A,long long size)
{
	long long minIndex = 0, maxIndex = size - 1;
	long long maxElement = A[size - 1] + 1;
	for(long long i = 0;i<size;i++)
	{
		if(i%2 == 0)
		{
			A[i] += (A[maxIndex] % maxElement) * maxElement;
			maxIndex--;
		}
		else
		{
			A[i] += (A[minIndex] % maxElement) * maxElement;
			minIndex++;
		}
		cout<<A[i]<<" ";
	}
	cout<<endl;
	for(long long i = 0;i<size;i++)
	{
		A[i]/=maxElement;
		cout<<A[i]<<" ";
	}
}

int main()
{
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
		reArrange(A,size);
		cout<<endl;
	}
}
