/* C program that implement Queue (its operations) using arrays. */
#include<stdio.h>
#include<stdbool.h>


int front=-1, rear=-1;

void enqueue(int n, int arr[*]);
int dequeue(int n, int arr[*]);
int peek(int n, int arr[*]);
bool isEmpty(int n, int arr[*]);
bool isFull(int n, int arr[*]);
void display(int n, int arr[*]);

void main()
{
	int option,val,MAX;
	printf("enter the size of array: ");
	scanf("%d",&MAX);
	int queue[MAX];
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
				enqueue(MAX, queue);
				break;
			case 2:
				val=dequeue(MAX, queue);
				if(val != -1)
					printf("\n the number deleted is : %d",val);
				break;
			case 3:
				val=peek(MAX, queue);	
				if(val != -1)
					printf("\n the first value in queue is : %d",queue[val]);
				break;
			case 4:
				x=isEmpty(MAX, queue);
				if(x==true)
					printf("\n the queue is empty");
				else
					printf("\n the queue is not empty");
				break;
			case 5:
				x=isFull(MAX, queue);
				if(x==true)
					printf("\n the queue is Full");
				else
					printf("\n the queue is not Full");
				break;
			case 6:
				display(MAX, queue);
				break;
			default:
				printf("enter correct option!");
		}
	}while(option !=7);
}
//this function is used to insert an element into queue.
void enqueue(int MAX, int queue[MAX])
{
	int num;
	printf("\n enter the number to be inserted in the queue: ");
	scanf("%d",&num);
	if((rear== MAX-1 && front == 0) || front == rear+1)
		printf("\n Overflow");
	else if(front == -1 && rear == -1)
		front = rear = 0;
	else if(  front !=0 && rear ==MAX-1)
		rear=0;
	else	
		rear++;
	queue[rear]=num;	
}

// this function is used to delete an element from a queue.
int dequeue(int MAX, int queue[MAX])
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
int peek(int MAX, int queue[MAX])
{
	if(front == -1 || rear == -1)
	{
		printf("\n queue is empty");
		return -1;
	}
	else
		return front;
}

//this function is used to check the queue is empty or not.
bool isEmpty(int MAX, int queue[MAX])
{
	if(front==-1 || rear == -1)
		return true;
	else 
		return false;	
}

// this function is used to check the queue is full or not.
bool isFull(int MAX, int queue[MAX])
{
	if((rear== MAX-1 && front == 0) || front == rear+1)
		return true;
	else
		return false;
}

// this function is used to display the element of the queue
void display(int MAX, int queue[MAX])
{
	int i;
	if(front==-1 || rear == -1)
		printf("\n queue is empty");
	else
	{
		if( front < rear)
		{
			for(i=front; i<= rear; i++)
				printf("%d \t",queue[i]);
		}
		else 
		{
			for(i = front ; i <= MAX-1 ; i++)
				printf("%d\t",queue[i]);
			for(i=0 ; i <= rear ; i++)
				printf("%d\t",queue[i]);	
		}
	}
}
