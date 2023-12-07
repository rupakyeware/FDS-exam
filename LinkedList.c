#include <stdio.h>
#include <stdlib.h>

struct node{
    int prn;
    char name[20];
    struct node *next;
};

void sort(struct node *head);
int length(struct node *head);
void create(struct node *head);
void display(struct node *head);
void reverse(struct node *head);
void insert(struct node *head, int pos);
void delete(struct node *head, int pos);
void merge(struct node *head, struct node *head2);

int main(){
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    int choice, insert_pos, delete_pos;
    while(1){
        printf("Option mneu\n1. Input\n2. Display\n3. Length\n4. Insert\n5. Delete\n6. Reverse\n7. Sort\n8. Merge\n 9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            length(head);
            break;
        case 4:
            printf("Enter the position to insert: ");
            scanf("%d", &insert_pos);
            insert(head, insert_pos);
            break;
        case 5:
            printf("Enter the position to delete: ");
            scanf("%d", &delete_pos);
            delete(head, delete_pos);
            break;
        case 6:
            reverse(head);
            break;
        case 7:
            sort(head);
            break;
        case 8:
            printf("Enter the second linked list\n");
            struct node *head2;
            head2 = (struct node *)malloc(sizeof(struct node));
            create(head2);
            merge(head, head2);
            break;
        case 9:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    
    
}

void create(struct node *head)
{
    char choice = 'Y';
    struct node *current = head;
    while (choice == 'Y' || choice == 'y')
    {
        printf("Want to create a new node? (Y/n) ");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n')
        {
            break;
        }
        struct node *new;
        new = (struct node *)malloc(sizeof(struct node));
        new->next = NULL;
        printf("Enter PRN: ");
        scanf("%d", &new->prn);
        printf("Enter name: ");
        scanf("%s", new->name);
        current->next = new;
        current = new;
    };
}

void display(struct node *head){
    struct node *current = head->next;
    printf("----------------------------------\n");
    printf("|   PRN   | Name |    Designation   |\n");
    printf("----------------------------------\n");
    if(current == head->next){
        printf("|  %d  |  %s  |  President  |\n", current->prn, current->name);
    }
    current = current->next;
    while(current->next != NULL){
        printf("|  %d  |  %s  |  Member  |\n", current->prn, current->name);
        current = current->next;
    }
    if(current->next == NULL){
        printf("|  %d  |  %s  |  Secretary  |\n", current->prn, current->name);
    }
    printf("----------------------------------\n");
}

int length(struct node *head){
    int length = 0;
    struct node *current = head->next;
    while(current != NULL){
        current = current->next;
        length++;
    }
    printf("----------------------------------\n");
    printf("Length of the linked list is %d\n", length);
    printf("----------------------------------\n");
    return length;
}

void insert(struct node *head, int pos){
    struct node *current = head;
    struct node *new;
    int len = length(head), i=1;
    if(pos > len+1){
        printf("Invalid position\n");
        return;
    }
    new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;
    printf("Enter PRN: ");
    scanf("%d", &new->prn);
    printf("Enter name: ");
    scanf("%s", new->name);
    while (current != NULL && i < pos){
        current = current->next;
        i++;
     }
    new->next = current->next;
    current->next = new;
}

void delete(struct node *head, int pos){
    struct node *current = head;
    struct node *temp;
    int len = length(head), counter=1;
    if(pos > len){
        printf("Invalid position\n");
        return;
    }
    while (counter < pos - 1){
        current = current->next;
        counter++;
    }
    temp = current->next;
    current->next = temp->next;
    free(temp);
}

void reverse(struct node *head){
    struct node *current = head->next;
    struct node *prev = NULL, *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    head->next = prev;
    display(head);
}

void sort(struct node *head){
    int len = length(head);
    for (int i = 1; i <= len; i++)
    {
        struct node *prev = head;
        struct node *current = head->next;
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
    display(head);
}

void merge(struct node * head, struct node *head2){
    sort(head);
    sort(head2);
    struct node *current = head;
    int flag;
    //compare the first node of both the linked list and set flag accordingly
    if(head->next->prn > head2->next->prn){
        flag = 1;
    }
    else{
        flag = 0;
    }
    while(head2->next != NULL && head->next != NULL) {
        if(flag == 1){
            if(head->next->prn > head2->next->prn){
                struct node *temp = head2->next;
                head2->next = temp->next;
                temp->next = head->next;
                head->next = temp;
            }
            head = head->next;
        }
        else{
            if(head->next->prn < head2->next->prn){
                struct node *temp = head2->next;
                head2->next = temp->next;
                temp->next = head->next;
                head->next = temp;
            }
            head = head->next;
        }
    }
    
}