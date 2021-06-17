#include <stdio.h>
int top=-1;

void push(int MAX, int stack[*]);
int pop(int MAX, int stack[*]);
void peek(int MAX, int stack[*]);
void display(int MAX, int stack[*]);
void isEmpty(int MAX, int stack[*]);
void isFull(int MAX, int stack[*]);

void main( ) 
{
	int val, option,MAX;
	printf("enter the size of stack: ");
	scanf("%d",&MAX);
	int stack[MAX];
	do
	{
		printf("\n *****MAIN MENU*****");
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Peek");
		printf("\n 4. Display");
		printf("\n 5. To check the stack is Empty");
		printf("\n 6. To check the stack is Full");
		printf("\n 7. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			push(MAX, stack);
			break;
		case 2:
			val = pop(MAX, stack);
			if(val != -1)
				printf("\n The value deleted from stack is: %d", val);
			break;
		case 3:
			peek(MAX, stack);
			break;
		case 4:
			display(MAX, stack);
			break;
		case 5:
			isEmpty(MAX, stack);
			break;
		case 6:
			isFull(MAX, stack);
			break;		
		default:
			printf("enter correct option!!!");	
 		}
	}while(option != 7);
}


void push(int MAX, int stack[MAX])
{
	int val;
	printf("\n Enter the number to be pushed on stack: ");
	scanf("%d", &val);
	if(top == MAX-1)
		printf("\n STACK OVERFLOW");
	else
	{
		top++;
		stack[top] = val;
	}
}

int pop(int MAX, int stack[MAX])
{
	int val;
	if(top == -1)
	{
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else
	{
		val = stack[top];
		top--;
		return val;
	}
}

void peek(int MAX, int stack[MAX])
{
	if(top == -1)
	{
		printf("\n STACK IS EMPTY");
	}	
	else
		printf("\n The value stored at top of stack is: %d", stack[top]);
}

void display(int MAX, int stack[MAX])
{
	int i;
	if(top == -1)
		printf("\n STACK IS EMPTY");
	else
	{
		for(i=0;i<=top;i++)
			printf("\t %d",stack[i]); 
	}
}

void isEmpty(int MAX, int stack[MAX])
{
	if(top == -1)
		printf("Stack is empty");
	else 
		printf("Stack is not empty");	
}

void isFull(int MAX, int stack[MAX])
{
	if(top == MAX-1)
		printf("\n the stack is Full");
	else
		printf("\n the stack is not Full");
}
