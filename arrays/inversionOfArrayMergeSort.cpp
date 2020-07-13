#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//long long merge(int* A,int* temp,int left,int mid,int right)
//{
//	int i,j,k;
//	long long inversionCount = 0;
//	i = left;
//	j = mid;
//	k = left;
//	while((i < mid) && j <= right)
//	{
//		if(A[i] <= A[j])
//		{
//			temp[k++] = A[i++];
//		}
//		else
//		{
//			temp[k++] = A[j++];
//			inversionCount += (mid - i);
//		}
//	}
//	while(i < mid)
//	{
//		temp[k++] = A[i++];
//	}
//	while(j <= right)
//	{
//		temp[k++] = A[j++];
//	}
//	for(i = left;i<=right;i++)
//	{
//		A[i] = temp[i];
//	}
//	return inversionCount;
//}
//
//long long _mergeSort(int* A,int* temp,int left,int right)
//{
//    long long inv_count = 0,mid;
//    if(left < right)
//    {
//        mid = (left + right) / 2;
//        inv_count += _mergeSort(A,temp,left,mid);
//        inv_count += _mergeSort(A,temp,mid+1,right);
//        inv_count += merge(A,temp,left,mid+1,right);
//    }
//    return inv_count;
//}
//
//long long countInversions(int* A,int n)
//{
//	int temp[n];
//	return _mergeSort(A,temp,0,n-1);
//}

int _merge(int* A,int* temp,int left,int mid,int right)
{
	int i = left,j = mid,k = left;
	int inversionCount = 0;
	while(i <= mid - 1 && j <= right)
	{
		if(A[i] < A[j])
		{
			temp[k++] = A[i++];
		}
		else
		{
			temp[k++] = A[j++];
			inversionCount += (mid - i);
		}
	}
	while( i<= mid - 1)
	{
		temp[k++] = A[i++];
	}
	while(j <= right)
	{
		temp[k++] = A[j++];
	}
	for(i = left;i<=right;i++)
	{
		A[i] = temp[i];
	}
	return inversionCount;
}

int _mergeSort(int* A,int* temp,int left,int right)
{
	int inversionCount = 0;
	int mid;
	if(left < right)
	{
		mid = (left + right)/2;
		inversionCount += _mergeSort(A,temp,left,mid);
		inversionCount += _mergeSort(A,temp,mid+1,right);
		inversionCount += _merge(A,temp,left,mid+1,right);
	}
	return inversionCount;
}

int countInversions(int* A,int n)
{
	int temp[n];
	return _mergeSort(A,temp,0,n-1);
}

int countInversionsUsingSet(int arr[],int n) 
{ 
    multiset<int> set1; 
    set1.insert(arr[0]); 
    int invcount = 0;
    multiset<int>::iterator itset1;
    for (int i=1; i<n; i++) 
    {
        set1.insert(arr[i]); 
        itset1 = set1.upper_bound(arr[i]); 
        invcount += distance(itset1, set1.end()); 
    }
    return invcount; 
} 

int main()
{
	int arr[] = {2,4,1,3,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<countInversionsUsingSet(arr,n)<<endl;
	cout<<countInversions(arr,n)<<endl;
}
