#include<stdio.h>
int binaryrecur(int n,int arr[*],int beg,int end,int val);
void binarynonrecur(int n,int arr[*],int beg,int end,int val);
void main()
{
	int n,i,val,pos;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements in ascending order: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the value to search: ");
	scanf("%d",&val);
	binarynonrecur(n,arr,0,n-1,val);
	pos=binaryrecur(n,arr,0,n-1,val);
	if(pos!=-1)
		printf("\nelement %d found at %d position using recursion",val,pos+1);
	else
		printf("\nelement %d not found using non recursion",val);		
}
int binaryrecur(int n,int arr[n],int beg,int end,int val)
{
	if(beg<=end)
	{
		int mid=(beg+end)/2;
		if(arr[mid]==val)
			return mid;
		if(arr[mid]>val)
			return binaryrecur(n,arr,beg,mid-1,val);
		else
			return binaryrecur(n,arr,mid+1,end,val);		
	}
	return -1;
}
void binarynonrecur(int n,int arr[n],int beg,int end,int val)
{
	int mid,pos=-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==val)
		{
			pos=mid+1;
			printf("\nelement %d is found at position %d using non recursion",val,pos);
			break;
		}
		else if(arr[mid]>val)
			end=mid-1;
		else
			 beg=mid+1;	
	}
	if(pos==-1)
		printf("\nelement %d does not found in the array using non recursion",val);
}
