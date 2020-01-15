#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert();
void delete();
void display();

void main()
{
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");

        int i;
        scanf("%d", &i);

        if (i == 1) insert();
        if (i == 2) delete();
        if (i == 3) display();
        if (i == 4) return;
    }
}

void insert()
{
    if ((rear == MAX - 1 && front == 0) || (front == rear + 1))
    {
        printf("Queue overflow!\n");
        return;
    }

    if (front == -1) front = rear = 0;
    else if (rear == MAX - 1) rear = 0;
    else rear++;

    printf("Enter the value to be added: ");
    scanf("%d", &queue[rear]);
}

void delete()
{
    if (front == -1)
    {
        printf("Queue underflow!\n");
        return;
    }

    printf("%d deleted from the queue!\n", queue[front]);

    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}
