// C program to implement parenthesis checker
#include<stdio.h>
#include<string.h>
#define MAX 10

int stack[MAX];
int top=-1;

char push(char);
char pop();

void main()
{
	char arr[20],temp;
	int i, flag=1;
	printf("\n enter an expression");
	scanf("%[^\n]",arr);
	
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i]=='(' || arr[i]== '{' || arr[i]=='[')
			push( arr[i]);
		if(arr[i]==')' || arr[i]== '}' || arr[i]==']')
			if(top == -1)
				flag = 0;
			else
			{
				 temp = pop();
				 if(arr[i]== ')' && (temp == '{'||temp=='['))
				 	flag = 0;
				if(arr[i]== '}' && (temp == '('||temp=='['))
				 	flag = 0;
				if(arr[i]== ']' && (temp == '{'||temp=='('))
				 	flag = 0;
				 
			}
	}
	if(top>=0)
		flag=0;
	
	if(flag==1)
		printf("\n Valid expression");
	else
		printf("\n Invalid expression");
	
}

char push(char val)
{
	if(top == MAX-1)
		printf("\n OVERFLOW");
	else
	{
		top++;
		stack[top]=val;
	}	
}

char pop()
{
	if(top == -1 )
		printf("\n UNDERFLOW");
	else
		return(stack[top--]);
}
