#include <stdio.h>
#include <stdlib.h>
struct node
{
int player_id;
struct node *next;
};

void main()
{
	struct node *start, *ptr, *new_node;
	int n, k, i, count;
	printf("\n Enter the number of players : ");
	scanf("%d", &n);
	printf("\n Enter the value of k (every kth player gets eliminated): ");
	scanf("%d", &k);
	
	// Create circular linked list containing all the players
	start = (struct node*)malloc(sizeof(struct node));
	start->player_id = 1;
	ptr = start;
	for (i = 2; i <= n; i++)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		ptr->next = new_node;
		new_node->player_id = i;
		new_node->next=start;
		ptr=new_node;
	}
	
	for (count = n; count > 1; count--)
	{
		for (i = 0; i < k - 1; ++i)
 			ptr = ptr->next;
 		ptr->next = ptr->next->next; // Remove the eliminated player from the circular linked list
	}
	printf("\n The Winner is Player %d", ptr->player_id);

}
