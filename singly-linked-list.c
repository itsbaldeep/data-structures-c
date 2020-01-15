#include <stdio.h>
#include <stdlib.h>
#ifndef NULL
#define NULL 0
#endif

typedef struct node
{
    int data;
    struct node* next;
} list;

void insert_beg(int);
void insert_end(int);
void delete_beg();
void delete_end();
void traverse();

list *head;

void main()
{
    int i;
    while (1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Remove from beginning\n");
        printf("4. Remove from end\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        scanf("%d", &i);
        
        if (i == 1)
        {
            int val;
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            insert_beg(val);
        }
        if (i == 2)
        {
            int val;
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            insert_end(val);
        }
        if (i == 3) delete_beg();
        if (i == 4) delete_end();
        if (i == 5) traverse();
        if (i == 6) break;
    }
}

void insert_beg(int value)
{
    if (head == NULL)
    {
        head = (list*) malloc(sizeof(list));
        head->data = value;
        head->next = NULL;
    }
    else
    {
        list *temp = (list*) malloc(sizeof(list));
        temp->data = value;
        temp->next = head;
        head = temp;
    }
}

void insert_end(int value)
{
    if (head == NULL)
    {
        head = (list*) malloc(sizeof(list));
        head->data = value;
        head->next = NULL;
    }
    else
    {
        list* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = (list*) malloc(sizeof(list));
        temp->next->data = value;
        temp->next->next = NULL;
    }
}

void delete_beg()
{
    if (head == NULL)
    {
        printf("Nothing to delete!\n");
        return;
    }
    list* temp = head->next;
    free(head);
    head = temp;
}

void delete_end()
{
    if (head == NULL)
    {
        printf("Nothing to delete!\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    list* temp1 = head;
    list* temp2;

    while (temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    
    temp2->next = NULL;
    free(temp1);
}

void traverse()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    list* temp = head;
    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf(" \n");
}
