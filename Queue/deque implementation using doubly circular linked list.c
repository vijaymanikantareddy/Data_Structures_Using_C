/* C program to implement deque (double eneded queue ) by using
	doubly circular linked list */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* prev;
	int data;
	struct node* next;
};

struct node* front= NULL;
struct node* rear= NULL;

void input_deque(void);
void output_deque(void);

struct node* insert_front(struct node *);
struct node* insert_rear(struct node *);
struct node* delete_front(struct node*);
struct node* delete_rear(struct node*);
void display(struct node*);

int main()
{
	int option;
	printf("\n *****MAIN MENU*****");
	printf("\n 1.Input restricted deque");
	printf("\n 2.Output restricted deque");
	printf("\n Enter your option : ");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			input_deque();
			break;
		case 2:
			output_deque();
			break;
	}
	return 0;
}

// this function is used to implement input restricted deque
// where insertion is done only at one end and deletion is done at both ends.
void input_deque()
{
	int option;
	do
	{
		printf("\n\n INPUT RESTRICTED DEQUE");
		printf("\n 1.Insert at right");
		printf("\n 2.Delete from left");
		printf("\n 3.Delete from right");
		printf("\n 4.Display");
		printf("\n 5.Quit");
		printf("\n Enter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				front=insert_rear(front);
				break;
			case 2:
				front=delete_front(front);
				break;
			case 3:
				front = delete_rear(front);
				break;
			case 4:
				display(front);
				break;
		}
	}while(option!=5);
}

// this function is used to implement output restricted deque
// where deletion is done only at one end and insertion is done at both ends.
void output_deque()
{
	int option;
	do
	{
		printf("\n\nOUTPUT RESTRICTED DEQUE");
		printf("\n 1.Insert at right");
		printf("\n 2.Insert at left");
		printf("\n 3.Delete from left");
		printf("\n 4.Display");
		printf("\n 5.Quit");
		printf("\n Enter your option : ");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			front=insert_rear(front);
			break;
		case 2:
			front = insert_front(front);
			break;		
		case 3:
			front=delete_front(front);
			break;
		case 4:
			display(front);
			break;
		}
	}while(option!=5);
}

// this function is used to insert a value at front of the queue.
struct node* insert_front(struct node* front)
{
	int num;
	printf("\n enter a number to insert into queue: ");
	scanf("%d",&num);
	struct node* ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=num;
	if(front == NULL)
	{
		front = ptr;
		rear = ptr;
		ptr->next=front;
		ptr->prev=rear;
	}
	else
	{
		ptr->next=front;
		front->prev=ptr;
		front=ptr;
		front->prev=rear;
		rear->next=front;
	}
	return front;
}

// this function is used to insert a value at rear of the queue.
struct node* insert_rear(struct node* front)
{
	int num;
	printf("\n enter a number to insert into queue: ");
	scanf("%d",&num);
	struct node* ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=num;
	if(front == NULL)
	{
		front = ptr;
		rear = ptr;
		ptr->next=front;
		ptr->prev=rear;
	}
	else
	{
		rear->next=ptr;
		ptr->prev=rear;
		rear=ptr;
		rear->next=front;
		front->prev=rear;
	}
	return front;
}

// this function is used to delete a value from front of the queue.
struct node* delete_front(struct node* fornt)
{
	struct node* ptr=front;
	if(front == NULL)
		printf("\n underflow");
	else
	{
		front=front->next;
		front->prev=rear;
		rear->next=front;
		printf("\n the value being deleted is: %d",ptr->data);
		free(ptr);
	}
	return front;
}

// this function is used to delete a value from rear of the queue.
struct node* delete_rear(struct node* front)
{
	struct node* ptr=rear;
	if(front == NULL)
		printf("\n underflow");
	else
	{
		rear=rear->prev;
		front->prev=rear;
		rear->next=front;
		printf("\n the value being deleted is: %d",ptr->data);
		free(ptr);
	}
	return front;
}

// this function is used to display a queue
void display(struct node* front)
{
	struct node* ptr=front;
	if(ptr == NULL)
		printf("\n QUEUE IS EMPTY");
	else
	{
		printf("\n");
		while(ptr!=rear)
		{
			printf("%d\t", ptr -> data);
			ptr = ptr -> next;
		}
		printf("%d\t", ptr -> data);
	}

}
