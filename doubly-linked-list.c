#include <stdio.h>
#include <stdlib.h>
#ifndef NULL
#define NULL 0
#endif

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
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
        list* node = (list*) malloc(sizeof(list));
        node->data = value;
        node->next = NULL;
        node->prev = NULL;
        head = node;
    }
    else
    {
        list *temp = (list*) malloc(sizeof(list));
        temp->data = value;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }
}

void insert_end(int value)
{
    if (head == NULL)
    {
        list* node = (list*) malloc(sizeof(list));
        node->data = value;
        node->next = NULL;
        node->prev = NULL;
        head = node;
    }
    else
    {
        list *temp = (list*) malloc(sizeof(list));
        temp->data = value;
        temp->next = NULL;

        list *last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = temp;
        temp->prev = last;
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
    }

    list* last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->prev->next = NULL;
    free(last);
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
