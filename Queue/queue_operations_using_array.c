/* C program that implement Queue (its operations) using arrays. */
#include<stdio.h>
#include<stdbool.h>
#define MAX 10

int queue[MAX];
int front=-1, rear=-1;

void enqueue(void);
int dequeue(void);
int peek(void);
bool isEmpty(void);
bool isFull(void);
void display(void);

void main()
{
	int option,val;
	bool x;
	do
	{
		printf("\n\n **** MAIN MENU ****");
		printf("\n 1. Insert an element into queue");
		printf("\n 2. Delete an element from queue");
		printf("\n 3. Peek value of queue");
		printf("\n 4. Is queue empty");
		printf("\n 5. Is queue full");
		printf("\n 6. Display the queue");
		printf("\n 7. EXIT");
		printf("\n Enter your option: ");
		scanf("%d",&option);
		switch(option)
		{ 
			case 1:
				enqueue();
				break;
			case 2:
				val=dequeue();
				if(val != -1)
					printf("\n the number deleted is : %d",val);
				break;
			case 3:
				val=peek();	
				if(val != -1)
					printf("\n the first value in queue is : %d",queue[val]);
				break;
			case 4:
				x=isEmpty();
				if(x==true)
					printf("\n the queue is empty");
				else
					printf("\n the queue is not empty");
				break;
			case 5:
				x=isFull();
				if(x==true)
					printf("\n the queue is Full");
				else
					printf("\n the queue is not Full");
				break;
			case 6:
				display();
				break;
		}
	}while(option > 0 && option <6);
}
//this function is used to insert an element into queue.
void enqueue()
{
	int num;
	printf("\n enter the number to be inserted in the queue: ");
	scanf("%d",&num);
	if(rear== MAX-1)
		printf("\n Overflow");
	else if(front == -1 && rear == -1)
		front = rear = 0;
	else
		rear++;
	queue[rear]=num;	
}

// this function is used to delete an element from a queue.
int dequeue()
{
	int val;
	if(front == -1 || front > rear)
	{
		printf("\n underflow");
		return -1;
	}
	else
	{
		val = queue[front];
		front++;
		if(front > rear)
			front = rear = -1;
		return val;
	}
}

//this function is used to print the front element of the queue
int peek()
{
	if(front == -1 || front > rear)
	{
		printf("\n queue is empty");
		return -1;
	}
	else
		return front;
}

//this function is used to check the queue is empty or not.
bool isEmpty()
{
	if(front==-1 || front > rear)
		return true;
	else 
		return false;	
}

// this function is used to check the queue is full or not.
bool isFull()
{
	if(rear == MAX-1)
		return true;
	else
		return false;
}

// this function is used to display the element of the queue
void display()
{
	int i;
	if(front == -1 || front >rear)
		printf("\n queue is empty");
	else
	{
		for(i=front; i<= rear; i++)
			printf("\n%d \t",queue[i]);
	}
}
