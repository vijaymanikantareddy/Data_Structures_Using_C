#include<stdio.h>
int main()
{
	int i,j,n,option,pos,val,temp,count=0;
	printf("enter the number of values: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter an array operation: \n");
	printf("1. Inserting an element in array\n");
	printf("2. Deleting an element in array\n");	
	printf("3. Searching an element in array\n");
	printf("4. Sorting elements in Ascending Order in array\n");
	printf("5. Sorting elements in Descending Order in array\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
		{
			printf("\n enter an element to insert into an array: ");
			scanf("%d",&val);
			printf("\n enter the position to insert into an array: "); 
			scanf("%d",&pos);
			for(i=n-1;i>=pos;i--)
				arr[i+1]=arr[i];
			arr[pos]=val;
			n++;
			printf("\nThe elements of an array after inserting new value: \n");
			for(i=0;i<n;i++)
				printf("\t%d",arr[i]);	
			break;
		}
		case 2:
		{
			printf("\n enter the position to delete from an array: ");
			scanf("%d",&pos);
			for(i=pos-1;i<n-1;i++)
				arr[i]=arr[i+1];
			n--;
			printf("\nThe elements of an array after deleting a value: \n");
			for(i=0;i<n;i++)
				printf("\t%d",arr[i]);	
			break;
		}
		case 3:
		{
			printf("\n enter an element to search into an array: ");
			scanf("%d",&val);
			for(i=0;i<n;i++)
			{
				if(arr[i]==val)
				{
					count++;
					printf("\n The value %d is found at position %d",val,i+1);
				}
			}
			if(count==0)
				printf("\n The element %d is not found",val);
			break;	
		}
		case 4:
		{
			for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-1-i;j++)
				{
					if(arr[j]>arr[j+1])
					{
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			}	
			printf("\n The sorted elements in Ascending order in array are: \n");
			for(i=0;i<n;i++)
				printf("\t%d",arr[i]);
			break;	
		}
		case 5:
		{
			for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-1-i;j++)
				{
					if(arr[j]<arr[j+1])
					{
						temp=arr[j+1];
							arr[j+1]=arr[j];
						arr[j]=temp;
					}
				}
			}	
			printf("\n The sorted elements in Ascending order in array are: \n");
			for(i=0;i<n;i++)
				printf("\t%d",arr[i]);
			break;
		}
		default:
			printf("\n Enter the correct option");
	}
}
