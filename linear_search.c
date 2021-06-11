#include<stdio.h>
void linear_search(int val,int n,int arr[*]);		//non-recursive function
int linear_search_re(int val,int n,int arr[*]);		//recursive function
void main()
{
	int n,i,val,pos,option;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the value to search: ");
	scanf("%d",&val);
	printf("enter 1 for Non-Recursive Function \n");
	printf("enter 2 for Recursive Function\n ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
	    {
	       	linear_search(val,n,arr);
	       	break;
	    }
	    case 2:
	    {
	        pos=linear_search_re(val,n,arr);
	        if(pos!=0)
		        printf("\nelement %d is found at position %d using Recursive function",val,pos);
	        else 
	        	printf("\nelement %d does not found using Recursive function",val);
	        break;	
	    }
	    default:
	        printf("enter correct option! ");
	}
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
			printf("\nelement %d is found at position %d using Non-Recursive function",val,i+1);
			break;
		}
	}
	if(found==0)
		printf("\nelement %d does not found using Non-Recursive function",val);
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
	return 0;
}
