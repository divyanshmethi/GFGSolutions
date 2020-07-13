#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//int minPlatforms(int* arr,int *dep,int size)
//{
//	sort(arr,arr + size);
//	sort(dep,dep + size);
//	int i = 1, j = 0;
//	int count = 1,maxCount = 1;
//	while(i < size && j < size)
//	{
//		if(arr[i] <= dep[j])
//		{
//			count++;
//			i++;
//		}
//		else
//		{
//			count--;
//			j++;
//		}
//		maxCount = max(maxCount,count);
//	}
//	return maxCount;
//}
//
//int minPlatformsWithMap(int* arr,int * dep,int size)
//{
//	multimap<int,char> m;
//	for(int i = 0;i<size;i++)
//	{
//		m.insert(make_pair(arr[i],'a'));
//		m.insert(make_pair(dep[i],'d'));
//	}
//	int count = 0,maxCount = 0;
//	for(auto it : m)
//	{
//		if(it.second == 'a')
//		{
//			count++;
//		}
//		else
//		{
//			count--;
//		}
//		maxCount = max(maxCount,count);
//	}
//	return maxCount;
//}
//
//int minPlatformsWithArray(int* arr,int* dep,int size)
//{
//	int freq[2361] = {0};
//	for(int i = 0;i<size;i++)
//	{
//		freq[arr[i]]++;
//		freq[dep[i] + 1]--;
//	}
//	int count = 0;
//	for(int i = 1;i<2361;i++)
//	{
//		freq[i] = freq[i-1] + freq[i];
//		count = max(count,freq[i]);
//	}
//	return count;
//}


int minPlatforms(int* arr,int* dep,int size)
{
	sort(arr,arr + size);
	sort(dep,dep + size);
	int i = 1,j = 0;
	int maxCount = 0,count = 1;
	while(i < size && j < size)
	{
		if(arr[i] < dep[j])
		{
			count++;
			i++;
		}
		else
		{
			count--;
			j++;
		}
		maxCount = max(maxCount,count);
	}
	return maxCount;
}


int minPlatformsWithMap(int* arr,int* dep,int size)
{
	map<int,char> m;
	for(int i = 0;i<size;i++)
	{
		m.insert(make_pair(arr[i],'a'));
		m.insert(make_pair(dep[i],'d'));
	}
	int count = 0,maxCount = 1;
	for(auto it : m)
	{
		if(it.second=='a')
		{
			count++;
		}
		else if(it.second == 'd')
		{
			count--;
		}
		maxCount = max(maxCount,count);
	}
	return maxCount;
}


int minPlatformsWithArray(int* arr,int* dep,int size)
{
	int plat[2361] = {0};
	for(int i = 0;i<size;i++)
	{
		plat[arr[i]]++;
		plat[dep[i] + 1]--;
	}
	int maxCount = 1;
	for(int i = 1;i<2361;i++)
	{
		plat[i] += plat[i-1];
		maxCount = max(maxCount,plat[i]);
	}
	return maxCount;
}


int main()
{
	int arr[] = {900,940,950,1100,1500,1800};
	int dep[] = {910,1200,1120,1130,1900,2000};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<minPlatforms(arr,dep,size)<<endl;
	cout<<minPlatformsWithMap(arr,dep,size)<<endl;
	cout<<minPlatformsWithArray(arr,dep,size)<<endl;
}
