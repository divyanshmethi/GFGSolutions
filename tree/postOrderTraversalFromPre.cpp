#include<iostream>
using namespace std;

void findPostOrderUtil(int* pre,int n,int left,int right,int& preIndex)
{
	//If preIndex = n means, that we have traversed the complete pre array and thus there is no more array element to visit
	//Thus, we can safely return from the function
	if(preIndex==n)
	{
		return;
	}
	//If the value of less than left or greater then right, means it is out of bounds and does not follow Binary Search Tree rule
	if(pre[preIndex] < left || pre[preIndex] > right)
	{
		return;
	}
	//Store the value at preIndex into var value, this would be printed at the end of the function after calls to left and right subtrees
	//preIndex is incremented for the next recursion
	int value = pre[preIndex++];
	//We make a recursive call for the left subtree, where the bounds are from left to value
	findPostOrderUtil(pre,n,left,value,preIndex);
	//We make a recursive call for the right subtree, where the bounds are from value to right
	findPostOrderUtil(pre,n,value,right,preIndex);
	//We finally print out the value, because in post order traversal root is printed at the end after left and right subtrees are done
	cout<<value<<" ";
}

void findPostOrder(int* pre,int n)
{
	int preIndex = 0;
	findPostOrderUtil(pre,n,INT_MIN,INT_MAX,preIndex);
}

int main()
{
	int pre[] = { 40, 30, 35, 80, 100 };
    int n = sizeof(pre) / sizeof(pre[0]);
    cout<<"Post Order Traversal is "<<endl;
    findPostOrder(pre, n);
    cout<<endl;
    return 0;
}
