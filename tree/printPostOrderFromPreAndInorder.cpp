#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int preIndex = 0;
void printPostOrderUtil(int* in,int* pre,map<int,int> m,int start,int end)
{
	if(start > end)
	{
		return;
	}
	int index = m[pre[preIndex++]];
	printPostOrderUtil(in,pre,m,start,index-1);
	printPostOrderUtil(in,pre,m,index+1,end);
	cout<<in[index]<<" ";
}

void printPostOrder(int* in,int* pre,int size)
{
	map<int,int> m;
	for(int i = 0;i<size;i++)
	{
		m[in[i]] = i;
	}
	printPostOrderUtil(in,pre,m,0,size-1);
}

int main()
{
	int in[] = { 4, 2, 5, 1, 3, 6 }; 
    int pre[] = { 1, 2, 4, 5, 3, 6 }; 
    int n = sizeof(in) / sizeof(in[0]); 
    cout << "Postorder traversal " << endl; 
    printPostOrder(in, pre, n); 
    return 0;
}
