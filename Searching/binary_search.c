#include<stdio.h>
int binaryrecur(int n,int arr[*],int beg,int end,int val);   //Recursive function
void binarynonrecur(int n,int arr[*],int beg,int end,int val);	//Non-Recursive function
void main()
{
	int n,i,val,pos,option;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements in ascending order: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the value to search: ");
	scanf("%d",&val);
	printf("enter 1 for Non-Recursive Function \n");
	printf("enter 2 for Recursive Function\n");
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
	    {
	       	binarynonrecur(n,arr,0,n-1,val);
	       	break;
	    }
	    case 2:
	    {
	       pos=binaryrecur(n,arr,0,n-1,val);
			if(pos!=-1)
				printf("\nelement %d found at %d position using Recursion Function",val,pos+1);
			else
				printf("\nelement %d not found using Recursion Function",val);
	        break;	
	    }
	    default:
	        printf("enter correct option! ");
	}		
}
int binaryrecur(int n,int arr[n],int beg,int end,int val)	//Recursion Function
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
void binarynonrecur(int n,int arr[n],int beg,int end,int val)	//Non-Recursion Function
{
	int mid,pos=-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==val)
		{
			pos=mid+1;
			printf("\nelement %d is found at position %d using Non-Recursion",val,pos);
			break;
		}
		else if(arr[mid]>val)
			end=mid-1;
		else
			 beg=mid+1;	
	}
	if(pos==-1)
		printf("\nelement %d does not found in the array using Non-Recursion",val);
}
