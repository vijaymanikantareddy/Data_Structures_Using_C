  
/* This program converts infix expression to prefix expression.
  * This program assume that there are Five operators: (*, /, +, -,^)
  * This program will not work for fractional numbers.
  * Further this program does not check whether infix expression is valid or not in terms of number of operators and operands.*/
#include<stdio.h>
// for exit() function
#include<stdlib.h>
// for isdigit(char ) function
#include<ctype.h>
#include<string.h>
#define SIZE 100

// Global Variable Declaration
char stack[SIZE];
int top = -1;

//Function Declaration
void push(char c);
char pop();
int isoperator(char symbol);
int precedence(char symbol);
void InfixToPrefix(char infix_exp[], char prefix_exp[]);

// main() function begins
void main()
{
	// Declare infix string and prefix string
	char infix[SIZE], prefix[SIZE];
	printf("\n\n Enter Infix expression : ");
	gets(infix);
	// Call to convert
	InfixToPrefix(infix,prefix);
	printf("\n Prefix Expression: ");
	// Print prefix expression
	puts(prefix);
}

void InfixToPrefix(char infix_exp[], char prefix_exp[])
{
	int i, j, k, pos, len;
	char item, x, rev[SIZE];
	// Reverse the infix expression
	pos=0;
	len=strlen(infix_exp);
	for(k=len-1;k>=0;k--)
	{
		rev[pos]=infix_exp[k];
		pos++;
	}
	rev[pos]='\0';
	strcpy(infix_exp,rev);
	// Make Every “ ( ” as “ ) ” and every “ ) ” as “ ( ”
	for(i=0; infix_exp[i]!='\0'; i++)
	{
		if(infix_exp[i] == ')')
		infix_exp[i] = '(';
		else if(infix_exp[i] == '(')
		infix_exp[i] = ')';
	}
	//Convert expression to postfix form.
	// push '(' onto stack
	push('(');
	// add ')' to infix expression
	strcat(infix_exp,")");
	i=0;
	j=0;
	// Initialize before loop
	item=infix_exp[i];
	// Run loop till end of infix expression
	while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
		// Add operand symbol to postfix expression
			prefix_exp[j] = item;
			j++;
		}
		else if(isoperator(item) == 1)
		{
// pop all higher precendence operator and add them to postfix expresion
			x=pop();
			while(isoperator(x) == 1 && precedence(x)>= precedence(item))
			{
				prefix_exp[j] = x;
				j++;
				x = pop();
			}
// push the last pop oprerator symbol onto stack
			push(x);
// push current oprerator symbol onto stack
			push(item);
		}
// if current symbol is ')' then pop and keep popping until '(' encounterd
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				prefix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
// if current symbol is neither operand not '(' nor ')' and nor operator
			printf("\nInvalid infix Expression.\n");
			break;
		}
		i++;
// Go to next symbol of infix expression
		item = infix_exp[i];
	} //End while loop
	if(top > 0)
	printf("\n Invalid infix Expression.");
	prefix_exp[j] = '\0';
// Reverse the prefix expression.
	pos=0;
	len=strlen(prefix_exp);
	for(k=len-1;k>=0;k--)
	{
		rev[pos]=prefix_exp[k];
		pos++;
	}
	rev[pos]='\0';
	strcpy(prefix_exp,rev);
}

// Define push operation
void push(char c)
{
	if(top >= SIZE-1)
		printf("\n Stack Overflow.");
	else
	{
		top++;
		stack[top] = c;
	}
}

// Define pop operation
char pop()
{
	char c;
	c='\0';
	if(top < 0)
		printf("\n Stack Underflow.");
	else
	{
		c = stack[top];
		top--;
	}
return c;
}

// Define function that is used to determine whether any symbol is operator or not
int isoperator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
		return 1;
	else
		return 0;
}

// Define fucntion that is used to assign precendence to operator.
// In this fucntion we assume that higher integer value means higher precendence
int precedence(char symbol)
{
	if(symbol == '^')
		return(5);
	else if(symbol == '/')
		return(4);
	else if(symbol == '*')
		return(3);
	else if(symbol == '+')
		return(2);
	else if(symbol == '-')
		return(1);
	else
		return(0);
}
