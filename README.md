# Data Structures in C

This repository contains a collection of popular data structures implemented in the C programming language. It aims to provide clear and concise implementations of fundamental data structures along with accompanying explanations.

## Table of Contents

- [Introduction](#introduction)
- [Data Structures](#data-structures)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Data structures are essential building blocks in computer science and software development. Understanding data structures allows you to efficiently organize and manipulate data, leading to optimized algorithms and better program performance.

This repository serves as a resource for learning and implementing various data structures in C. Each data structure is implemented with a focus on readability, efficiency, and correctness. Alongside the implementations, you will find detailed explanations and usage examples to help you grasp the concepts and apply them to your own projects.

## Data Structures

The repository currently includes the following data structures:

- **Linked List**: A linear data structure that consists of a sequence of nodes, each containing a value and a reference to the next node.
- **Stack**: A Last-In-First-Out (LIFO) data structure that supports two main operations: push (inserting an element) and pop (removing the most recently added element).
- **Queue**: A First-In-First-Out (FIFO) data structure that supports enqueue (adding an element) and dequeue (removing the least recently added element) operations.
- **Binary Tree**: A hierarchical data structure in which each node has at most two children: left and right.
- **Hash Table**: A data structure that provides fast access to values associated with unique keys using a hash function.

Each data structure is located in its own directory within this repository, containing the C source files and relevant documentation.

## Usage

To use the data structures in your project, you can simply clone this repository and include the necessary files in your C project. Each data structure directory includes separate header and source files, allowing you to include them as needed.

For example, to use the linked list data structure, you can include the following files in your C code:

```c
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};
struct node * start=NULL;
struct node * createll(struct node*, int);
void display(struct node*);
void main()
{
	int option,iter;
	do
    {
    	printf("\n\n***MAIN MENU***");
    	printf("\nenter 1 : To create list.");
    	printf(" \nenter 2 : To display a list.");
    	printf("\nenter 3 : To exit.");
    	printf("\nenter the option :");
    	scanf("%d",&option);
    	switch(option)
    	{
    		case 1:
    			printf("enter the size of list :");
				scanf("%d",&iter);
    			start=createll(start,iter);
    			printf("\n linked list is created");
    			break;
    	    case 2:
			    display(start);
			    break;    
		}
	}while(option != 3);
	
}
struct node * createll(struct node*start, int iter)
{
	struct node*newnode,*ptr;
	int i,n;
	printf("enter %d elements: ",iter);
	for(i=0; i<iter ; i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&n);;
		if(start==NULL)
		{
			start=newnode;
			newnode->data=n;
			newnode->next=NULL;
		}
		else
		{
			ptr=start;
			newnode->data=n;
		   	while(ptr->next!=NULL)
		   		ptr=ptr->next;
		   	ptr->next=newnode;
		   	newnode->next=NULL;
		}
	}
	return start;
}
 void display(struct node*start)
{
	struct node*ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("List does not exist!");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
