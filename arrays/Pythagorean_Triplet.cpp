#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isTriplet(int* A,int n)
{
    unordered_map<int,int> m;
    for(int i = 0;i<n;i++)
    {
        A[i]*=A[i];
        m[A[i]] = 1;
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = i + 1;j<n;j++)
        {
            if(m[A[i] + A[j]] == 1)
            {
                return true;
            }
        }
    }
    return false;
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
	    if(isTriplet(A,size))
	    {
	        cout<<"Yes";
	    }
	    else
	    {
	        cout<<"No";
	    }
	    cout<<endl;
	}
	
	return 0;
}
