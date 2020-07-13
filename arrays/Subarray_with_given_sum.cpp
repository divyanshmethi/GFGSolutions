#include<iostream>
using namespace std;

void foundSubarray(int* A,int size,int k)
{
	int start = 0, end = 0;
	int sum = 0;
	bool found = false;
	while(end < size)
	{
		if(sum < k)
		{
			sum += A[end];
			end++;
		}
		else if(sum == k)
		{
			found = true;
			break;
		}
		else
		{
			while(sum > k)
			{
				sum -= A[start];
				start++;
			}
		}
	}
	if(found)
	{
		cout<<start + 1<<" "<<end<<endl;
	}
	else
	{
		while(sum > k)
		{
			sum -= A[start];
			start++;
		}
		if(sum==k)
		{
			cout<<start + 1 <<" "<<end<<endl;
		}
		else
		{
			cout<<-1<<endl;
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
		cin>>size>>k;
		int A[size];
		for(int i = 0;i<size;i++)
		{
			cin>>A[i];
		}
		foundSubarray(A,size,k);
	}
}
