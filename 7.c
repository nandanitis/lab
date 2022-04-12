#include <stdio.h>
int front = -1, rear = -1;
#define MAX 5
int Q[MAX];

void insert(int item)
{
    if ( (front == 0 && rear == MAX - 1) || (front == rear + 1) )
    {
        printf("\n Overflow ");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    Q[rear] = item;
}

void delete1()
{
    int item;
    if (front == -1)
    {
        printf("\n Underflow ");
        return;
    }
    item = Q[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("\n No elements ");
        return;
    }
    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%d ->", Q[i]);
    }
    printf("g %d  Front=%d Rear=%d \n", Q[rear], front, rear);
}

int main()
{
    int choice, num;
    while (1)
    {
        printf(" \n 1 to insert \n2 to delete \n 3To display \nYour Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter your number : ");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            delete1();
            printf("Deleted successfully ");
            break;
        case 3:
            display();
            break;
        }
    }
}