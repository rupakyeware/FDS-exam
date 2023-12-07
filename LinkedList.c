#include <stdio.h>
#include <stdlib.h>


struct node 
{
	int prn;
	char name[20];
	struct node *next;
};

void accept(struct node *);
void add(struct node *);
void addp(struct node *, int);
void display(struct node *);
void delete(struct node *, int);
int length(struct node *);
void reverse(struct node *);
void sort(struct node *);

int main() 
{
	struct node *head;
	head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	printf("\nEnter your choice-");
	while(1)
	{
		printf("\n1. Display\n2. Add\n3. Delete\n4. Insert\n5. Length\n6. Reverse\n7. Sort\n8. Merge\n9. Exit\nChoice: ");
		int choice;
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				display(head);
				break;

			case 2:
				add(head);
				display(head);
				break;

			case 3:	
				printf("\nInsert position to delete: ");
				int pos;
				scanf("%d", &pos);
				delete(head, pos);
				display(head);
				break;

			case 4: 
				printf("\nInsert position to insert at: ");
				scanf("%d", &pos);
				addp(head, pos);
				display(head);
				break;

			case 5:	{ 
				int count;
				count = length(head);
				printf("\nLength of the linked list is: %d", count);
				display(head);
				break;
				}

			case 6:
				reverse(head);
				display(head);
			
			case 7:
				sort(head);
				display(head);

			case 8:
				merge(

			case 9:
				return 0;

			default:
				break;
		}
	}
}

void accept(struct node *n)
{
	printf("\n\nEnter details for the new node-");
	printf("\nEnter name: ");	scanf("%s", &n->name);
	printf("\nEnter prn: ");	scanf("%d", &n->prn);
}

void add(struct node *h) 
{
	struct node *current = h;
	while(current->next != NULL)
	{
		current = current->next;
	}
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	accept(new);
	current->next = new;
	new->next = NULL;
}

void addp(struct node *h, int pos)
{
	struct node *current = h;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	accept(new);
	int count = 1;
	while(count < pos)
	{	
		current = current->next;
		count++;
	}
	struct node *temp = current->next;
	current->next = new;
	new->next = temp;
}

void display(struct node *h)
{
	struct node *current = h->next;
	printf("\n|\t\tPRN\t\tNAME\t\tROLE\t\t|");
	printf("\n__________________________________________________________________");
	while (current != NULL)
	{
		if (current == h->next)
		{
			printf("\n\t\t%d\t\t%s\t\tPRESIDENT\t\t", current->prn, current->name);

		}
		else if(current->next == NULL)
		{
			printf("\n\t\t%d\t\t%s\t\tSECRETARY\t\t", current->prn, current->name);
		}
		else
		{
			printf("\n\t\t%d\t\t%s\t\tMember\t\t", current->prn, current->name);
		}
		current = current->next; 
		
	}
}

void delete(struct node *h, int pos)
{
	struct node *current = h;
	int count = 1;
	while(count < pos - 1)
	{	
		current = current->next;
		count++;
	}
	struct node *temp = current->next;
	current->next = temp->next;
	free(temp);
	
}

int length(struct node *h)
{
	struct node *current = h;
	int count = 0;
	while(current->next != NULL)
	{
		current = current->next;
		count++;
	}
	
	return count;
}

void reverse(struct node *h)
{
	struct node *current = h->next;
	struct node *prev = NULL;
	struct node *next = NULL;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;	
		current = next;	
	}
	h->next = prev;
}

void sort(struct node *h)
{
	int len = length(h);
    	for (int i = 1; i <= len; i++)
    	{
        	struct node *prev = h;
        	struct node *current = h->next;
        	for (int j = 1; j < len - i + 1; j++)
        	{
            		struct node *temp = current->next;
           		if (current->prn > temp->prn)
            		{	
                		prev->next = temp;
                		current->next = temp->next;
                		temp->next = current;
                		prev = temp;
            		}
            		else
            		{
                		prev = current;
                		current = current->next;
            		}
        	}
    	}
}