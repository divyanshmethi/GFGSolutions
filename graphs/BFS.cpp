#include<iostream>
#include<vector>
using namespace std;

vector <int> bfs(vector<int> g[], int N) {
	vector<bool> visited(N,false);
		
}

int main()
{
	int test;
	cin>>test;
	for(int i = 0;i<test;i++)
	{
		int n,e;
		cin>>n>>e;
		vector<int> adj[n];
		int first,second;
		for(int i = 0;i<e;i++)
		{
			vector<int> temp;
			cin>>first>>second;
			temp.push_back(first);
			temp.push_back(second);
			adj[i] = temp;
		}
		vector<int> res = bfs(adj,n);
		for(int i = 0;i<e;i++)
		{
			cout<<adj[i][0]<<" "<<adj[i][1]<<endl;
		}
	}
}
