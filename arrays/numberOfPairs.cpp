#include<iostream>
#include<algorithm>
using namespace std;
//
//int findCount(int x,int* B,int n,int* ex)
//{
//	if(x==0)
//	{
//		return ex[0];
//	}
//	else if(x==1)
//	{
//		return ex[1];
//	}
//	int* index = upper_bound(B,B+n,x);
//	int count = B + n - index;
//	count += (ex[0] + ex[1]);
//	if(x==2)
//	{
//		count -= (ex[3] + ex[4]);
//	}
//	else if(x==3)
//	{
//		count += (ex[2]);
//	}
//	return count;
//}
//
//int countPairs(int* A,int *B,int m,int n)
//{
//	int exceptions[5] = {0};
//	for(int i = 0;i<n;i++)
//	{
//		if(B[i] < 5)
//		{
//			exceptions[B[i]]++;
//		}
//	}
//	sort(B,B+n);
//	int count = 0;
//	for(int i = 0;i<n;i++)
//	{
//		count += findCount(A[i],B,n,exceptions);
//	}
//	return count;
//}

int countPair(int x,int* B,int n,int* exc)
{
	if(x == 0)
	{
		return 0;
	}
	else if( x == 1)
	{
		return exc[0];
	}
	//Find the first element in B which is greater than x
	int* id = upper_bound(B,B + n,x);
	//All the elements from this element to the end of the array would be greater then x and thus x^ele > ele^x, So add all of them to the count
	int count = B + n - id;
	count += (exc[0] + exc[1]);
	if(x==2)
	{
		count -= (exc[3] + exc[4]);
	}
	else if(x==3)
	{
		count += exc[2];
	}
	return count;
}

int countPairs(int* A,int* B,int m,int n)
{
	int excep[5] = {0};
	for(int i = 0;i<n;i++)
	{
		if(B[i] < 5)
			excep[B[i]]++;
	}
	int totalPairs = 0;
	sort(B , B + n);
	for(int i = 0;i<m;i++)
	{
		totalPairs += countPair(A[i],B,n,excep);
	}
	return totalPairs;
}

int main()
{
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
		int m,n;
		cin>>m>>n;
		int A[m];
		int B[n];
		for(int i = 0;i<m;i++)
		{
			cin>>A[i];
		}
		for(int i = 0;i<n;i++)
		{
			cin>>B[i];
		}
		cout<<countPairs(A,B,m,n)<<endl;
	}
}
