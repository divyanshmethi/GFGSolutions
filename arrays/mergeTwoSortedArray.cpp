#include<iostream>
using namespace std;

//int nextGap(int gap)
//{
//	if(gap <= 1)
//	{
//		return 0;
//	}
//	return gap/2 + gap%2;
//}
//
//void merge(int* A,int* B,int m,int n)
//{
//	int i,j,gap = m + n;
//	for(gap = nextGap(gap);gap > 0;gap = nextGap(gap))
//	{
//		for(i = 0;i + gap < m;i++)
//		{
//			if(A[i] > A[i + gap])
//			{
//				swap(A[i],A[i + gap]);
//			}
//		}
//		for(j = gap > m ? gap - m:0; i < m && j < n;i++,j++)
//		{
//			if(A[i] > B[j])
//			{
//				swap(A[i],B[j]);
//			}
//		}
//		if(j < n)
//		{
//			for(j = 0;j + gap < n;j++)
//			{
//				if(B[j] > B[j + gap])
//				{
//					swap(B[j],B[j + gap]);
//				}
//			}
//		}
//	}
//}

int nextGap(int gap)
{
	if(gap <= 1)
	{
		return 0;
	}
	return gap / 2 + gap % 2;
}

void merge(int* A,int* B,int m,int n)
{
	int gap = m + n,i,j;
	for(gap = nextGap(gap);gap > 0;gap = nextGap(gap))
	{
		for(i = 0;i + gap < m;i++)
		{
			if(A[i] > A[i + gap])
			{
				swap(A[i],A[i + gap]);
			}
		}
		for(j = (gap > m) ? gap - m : 0;i < m && j < n;i++,j++)
		{
			if(A[i] > B[j])
			{
				swap(A[i],B[j]);
			}
		}
		if(j < n)
		{
			for(j = 0;j + gap < n;j++)
			{
				if(B[j] > B[j + gap])
				{
					swap(B[j],B[j + gap]);
				}
			}
		}
	}
}

int main()
{
	int a1[] = { 10, 27, 38, 43 ,82 }; 
    int a2[] = { 3,9 }; 
    int n = sizeof(a1) / sizeof(int); 
    int m = sizeof(a2) / sizeof(int); 
  
    merge(a1, a2, n, m); 
  
    printf("First Array: "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", a1[i]); 
  
    printf("\nSecond Array: "); 
    for (int i = 0; i < m; i++) 
        printf("%d ", a2[i]); 
    printf("\n"); 
    return 0; 
}
