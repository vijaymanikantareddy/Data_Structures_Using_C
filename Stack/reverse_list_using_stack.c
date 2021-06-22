// reverse a list using stack
#include <stdio.h>
int stk[10];
int top=-1;

int pop();
void push(int);

void main()
{
	int val, n, i,
	arr[10];
	printf("\n Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array : ");
	for(i=0;i<n;i++)
 		scanf("%d", &arr[i]);
 	//pushing an array elements to stack
	for(i=0;i<n;i++)
 		push(arr[i]);
 	//popping elements from stack to array
	for(i=0;i<n;i++)
	{
 		val = pop();
 		arr[i] = val;
	}
	printf("\n Elements after reversing a list: ");
	for(i=0;i<n;i++)
 		printf("\t %d", arr[i]);
}

void push(int val)
{
	stk[++top] = val;
}

int pop()
{
	return(stk[top--]);
}
