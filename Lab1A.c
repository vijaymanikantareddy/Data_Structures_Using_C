#include<stdio.h>
void linear_search(int val,int n,int arr[*]);		//non-recursive function
int linear_search_re(int val,int n,int arr[*]);		//recursive function
void main()
{
	int n,i,val,pos;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the value to search: ");
	scanf("%d",&val);
	linear_search(val,n,arr);
	pos=linear_search_re(val,n,arr);
	if(pos!=0)
		printf("\nelement %d is found at position %d using recursive function",val,pos);
	else 
		printf("\nelement %d does not found using recursive function",val);
}
void linear_search(int val,int n,int arr[n])	//Non-recursive function
{
	int i,found=0,pos=-1;
	for(i=0;i<n;i++)
	{
		if(arr[i]==val)
		{
			found=1;
			pos=i;
			printf("\nelement %d is found at position %d using non-recursive function",val,i+1);
			break;
		}
	}
	if(found==0)
		printf("\nelement %d does not found using non-recursive function",val);
}
int linear_search_re(int val,int n,int arr[n])	  //Recursive function
{
	if(n>0)
	{
		if(arr[n-1]==val)
			return n;
		else
			return linear_search_re(val,n-1,arr);	
	}
}
