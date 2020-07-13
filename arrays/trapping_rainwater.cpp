#include<iostream>
using namespace std;

int findWater(int* A,int size)
{
	int left = 0,right = size - 1;
	int leftMax = 0,rightMax = 0;
	int water = 0;
	while(left <= right)
	{
		if(A[left] < A[right])
		{
			if(leftMax < A[left])
			{
				leftMax = A[left];
			}
			else
			{
				water += (leftMax - A[left]);
			}
			left++;
		}
		else
		{
			if(rightMax < A[right])
			{
				rightMax = A[right];
			}
			else
			{
				water += (rightMax - A[right]);
			}
			right--;
		}
	}
	return water;
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
		cout<<findWater(A,size)<<endl;
	}
}
