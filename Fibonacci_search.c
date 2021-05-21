#include<stdio.h>
int min(int x, int y)
{
	return(x<=y?x:y);
}
int fibonacci(int arr[], int x, int n)
{
	int fbm2=0, fbm1=1, fbm=fbm1+fbm2, offset=-1;
	while(fbm<n)
	{
		fbm2=fbm1;
		fbm1=fbm;
		fbm=fbm2+fbm1;
	}
	while(fbm>1)
	{
		int i=min(offset+fbm2,n-1);
		if(arr[i]<x)
		{
			fbm=fbm1;
			fbm1=fbm2;
			fbm2=fbm-fbm1;
			offset=i;
		}
		else if(arr[i]>x)
		{
			fbm=fbm2;
			fbm1=fbm1-fbm2;
			fbm2=fbm-fbm1;
		}
		else return i;
	}
	if(fbm1 && arr[offset+1]==x)
		return offset+1;
	return -1;	
}
void main()
{
	int n,i,x,pos;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements in ascending order: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the value to search: ");
	scanf("%d",&x);
	pos=fibonacci(arr,x,n);
	if(pos!=-1)
		printf("\nelement %d found at %d position",x,pos+1);
	else
		printf("\nelement %d not found",x);		
}
