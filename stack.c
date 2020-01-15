#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack {
    int data[SIZE];
    int top;
};
typedef struct stack Stack;
Stack s;

void push();
void pop();
void display();

void main()
{
    s.top = -1;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        int i;
        scanf("%d", &i);

        if (i == 1) push();
        if (i == 2) pop();
        if (i == 3) display();
        if (i == 4) break;
    }
}

void push()
{
    if (s.top == SIZE - 1)
    {
        printf("Stack is full!\n");
        return;
    }

    int val;
    printf("Enter the value to be pushed: ");
    scanf("%d", &val);

    s.top = s.top + 1;
    s.data[s.top] = val;
}

void pop()
{
    if (s.top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("%d popped successfully!\n", s.data[s.top]);
    s.top = s.top - 1;
}

void display()
{
    if (s.top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    for (int i = s.top; i >= 0; i--)
    {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}
