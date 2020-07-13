#include <iostream>
using namespace std;

int main() {
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
	    for(int i = 0;i<size/k;i++)
	    {
	        int start = i*k;
	        int end = (i + 1) * k - 1;
	        int temp;
	        while(start < end)
	        {
	            swap(A[start],A[end]);
	            start++;end--;
	        }
	    }
	   // cout<<"After iteration ";
	   // for(int i = 0;i<size;i++)
	   // {
	   //     cout<<A[i]<<" ";
	   // }
	   // cout<<endl;
	    int start = size - size%k;
	    int end = size-1;
	    while(start < end)
	    {
	        swap(A[start],A[end]);
	        end--;
	        start++;
	    }
	    for(int i = 0;i<size;i++)
	    {
	        cout<<A[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
