#include <iostream>
using namespace std;

string removedDuplicates(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    string res = "";
    char prev = s[0];
    res += prev;
    for(int i = 1;i<s.length();i++)
    {
        if(s[i] != prev)
        {
            res += s[i];
        }
        prev = s[i];
    }
    return res;
}

int main() {
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
	    string s;
	    cin>>s;
	    cout<<s<<endl;
	    cout<<removedDuplicates(s)<<endl;
	}
	return 0;
}
