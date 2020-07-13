#include <iostream>
using namespace std;

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
        int one = 0, two = 0, zero = 0;
        for(int i = 0;i<size;i++)
        {
            if(A[i] == 0)
            {
                zero++;
            }
            else if(A[i] == 1)
            {
                one++;
            }
            else if(A[i] == 2)
            {
                two++;
            }
        }
        for(int i = 0;i<zero;i++)
        {
            A[i] = 0;
        }
        for(int i = 0;i<one;i++)
        {
            A[i+zero] = 1;
        }
        for(int i = 0;i<two;i++)
        {
            A[i + zero + one] = 2;
        }
        for(int i = 0;i<size;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
