#include <iostream>
#define M 10
#define N 10
using namespace std;

void spiralTraverse(int matrix[M][N],int m,int n)
{
	int i = 0, j = 0, k = m, l = n;
	while(i < k && j < l)
	{
		for(int p = j;p < l;p++)
		{
			cout<<matrix[i][p]<<" ";
		}
		i++;
		for(int p = i;p < k;p++)
		{
			cout<<matrix[p][l-1]<<" ";
		}
		l--;
		if(i < k)
		{
			for(int p = l-1;p>=j;p--)
			{
				cout<<matrix[k-1][p]<<" ";
			}
			k--;
		}
		if(j < l)
		{
			for(int p = k-1;p>=i;p--)
			{
				cout<<matrix[p][j]<<" ";
			}
			j++;
		}
	}
	cout<<endl;
}

int main() {
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
	    int m,n;
	    cin>>m>>n;
	    int A[m][10];
	    for(int i = 0;i<m;i++)
	    {
	    	for(int j = 0;j<n;j++)
	    	{
	    		cin>>A[i][j];
			}
	    }
	    spiralTraverse(A,m,n);
	}
	return 0;
}
