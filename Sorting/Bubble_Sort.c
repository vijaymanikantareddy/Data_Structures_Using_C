#include<stdio.h>
int main()
{
	int i,n,temp,j;
	printf("enter the number of values: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0 ; i < n-1 ; i++)
	{
		for(j=0 ; j < n-1-i ; j++)
		{
		if(arr[j] > arr[j+1])
		{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
		}
	}
	for(i=0; i<n ;i++)
		printf("%d ",arr[i]);
}	
