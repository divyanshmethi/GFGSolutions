#include <iostream>
using namespace std;

void findDays(int* A,int size)
{
    int i = 0;
    int found = false;
    while(i < size - 1)
    {
        while(i < size - 1 && A[i+1]<=A[i])
        {
            i++;
        }
        if(i == size - 1)
        {
            if(!found)
                cout<<"No Profit";
            return;
        }
        int buy = i++;
        while(i < size && A[i-1]<=A[i])
        {
            i++;
        }
        int sell = i - 1;
        cout<<"("<<buy<<" "<<sell<<") ";
        found = true;
    }
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
        findDays(A,size);
        cout<<endl;
    }
	return 0;
}
