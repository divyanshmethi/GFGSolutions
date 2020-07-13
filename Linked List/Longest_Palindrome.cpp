#include<iostream>
using namespace std;

string findLongestPalindrome(string s)
{
	int n = s.length();
	if(n==0)
	{
		return "";
	}
	n = 2*n + 1;
	int L[n];
	L[0] = 0;
	L[1] = 1;
	int i = 0;
	int C = 1;	//Store the current palindromic center
	int diff = -1;	//store the difference between center right and current right
	int R = 2;		//Center right	
	int start = -1,end = -1;
	int currentLeft;
	int maxLPSlength = 0;
	int maxLPSCenterPosition = 0;
	for(i = 2;i < n;i++)
	{
		currentLeft = 2*C - i;
		L[i] = 0;
		diff = R - i;
		if(diff > 0)
		{
			L[i] = max(diff,L[currentLeft]);
		}
		while ( ((i + L[i]) < n && (i - L[i]) > 0) &&  
            ( ((i + L[i] + 1) % 2 == 0) ||  
            (s[(i + L[i] + 1)/2] == s[(i - L[i] - 1)/2] ))) 
		{
			L[i]++;
		}
		if(L[i] > maxLPSlength)
		{
			maxLPSlength = L[i];
			maxLPSCenterPosition = i;
		}
		if(i + L[i] > R)
		{
			C = i;
			R = i + L[i];
		}
	}
	start = (maxLPSCenterPosition - maxLPSlength)/2;
    end = start + maxLPSlength - 1;
    return s.substr()
}

int main()
{
	int test;
	cin>>test;
	for(int o = 0;o<test;o++)
	{
		string s;
		cin>>s;
		cout<<findLongestPalindrome(s)<<endl;
	}
}
