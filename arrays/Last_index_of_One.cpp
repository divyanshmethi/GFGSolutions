#include <iostream>
using namespace std;

int main() {
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
	    string s;
	    cin>>s;
	    bool found = false;
	    for(int i = s.length() - 1;i>=0;i--)
	    {
	        if(s[i]=='1')
	        {
	            cout<<i<<endl;
	            found = true;
	            break;
	        }
	    }
	    if(!found)
	    {
	        cout<<-1<<endl;
	    }
	}
	return 0;
}
