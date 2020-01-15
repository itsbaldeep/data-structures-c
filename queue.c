#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

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
    if (rear == MAX - 1)
    {
        printf("Queue overflow!\n");
        return;
    }

    if (front == -1) front = 0;

    int val;
    printf("Enter the value to be added: ");
    scanf("%d", &val);

    rear++;
    queue[rear] = val;
}

void delete()
{
    if (front == -1)
    {
        printf("Queue underflow!\n");
        return;
    }

    printf("%d deleted from the queue!\n", queue[front]);
    front++;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
