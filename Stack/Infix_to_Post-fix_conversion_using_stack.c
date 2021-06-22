//C program to convert infix expression to postfix expression
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char stack[], char);
char pop(char stack[]);

void infixtopostfix(char source[], char target[]);
int getpriority(char);

void main()
{
	char infix[100],postfix[100];
	printf("\n enter any Infix expression: ");
	gets(infix);
	infixtopostfix(infix,postfix);
	printf("\n the postfix expression is: ");
	puts(postfix);
}

void infixtopostfix(char source[], char target[])
{
	int i=0, j=0;
	char temp;
	strcat(source,")");
	push(stack, '(');
	while(source[i]!='\0')
	{
		if(source[i]=='(')
		{
			push(stack,source[i]);
			i++;
		}
		else if(isdigit(source[i]) || isalpha(source[i]))
		{
			target[j]=source[i];
			i++;
			j++;
		}
		else if(source[i]==')')
		{
			while((top!=-1)&&(stack[top]!='('))
			{
				target[j]=pop(stack);
				j++;
			}
			if(top == -1)
			{
				printf("\n Incorrect expression");
				exit(0);
			}
			temp=pop(stack);
			i++;
		}
		else if(source[i] == '+'|| source[i]=='-' || source[i]=='/' || source[i]=='*' || source[i]=='%' )
		{
			while((top != -1)&&(stack[top] !='(' ) &&(getpriority(stack[top]) > getpriority(source[i])))
			{
				target[j]=pop(stack);
				j++;
			}
			push(stack,source[i]);
			i++;
		}
		else
		{
			printf("\n incorrect expression");
			exit(0);
		}
	}
	
	while(top != -1&& stack[top]!='(')
	{
		target[j]=pop(stack);
		j++;
	}
	target[j]='\0';
	
}

void push(char stack[], char val)
{
	if(top==MAX-1)
		printf("\n OVERFLOW");
	else
	{
		top++;
		stack[top]=val;
	}
}

char pop(char stack[])
{
	char val;
	if(top== -1)
		printf("\n UNDERFLOw");
	else
	{
		val=stack[top];
		top--;
		
	}
	return val;
}

int getpriority(char opr)
{
	if(opr == '/' || opr == '*' || opr == '%')
		return 1;
	else if(opr == '+' || opr == '-')
		return 0;
}
