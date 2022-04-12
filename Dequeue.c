#include <stdio.h>
#include <conio.h>
#define MAX 10
int deque[MAX];
int left=-1,right=-1;
void input_deque(void);
void output_deque(void);
void insert_left(void);
void insert_right(void);
void delete_left(void);
void delete_right(void);
void display(void);
int main()
{
    int option;
    printf("\n *****MAIN MENU*****");
    printf("\n 1.Input restricted deque");
    printf("\n 2.Output restricted deque");
    printf("Enter your option : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        input_deque();
        break;
        case 2:
        output_deque();
        break;
    }
    return 0;
}
void input_deque()
{
    int option;
    do
    {
        printf("\n INPUT RESTRICTED DEQUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Delete from left");
        printf("\n 3.Delete from right");
        printf("\n 4.Display");
        printf("\n 5.Quit");
        printf("\n Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            insert_right();
            break;
            case 2:
            delete_left();
            break;
            case 3:
            delete_right();
            break;
            case 4:
            display();
            break;
        }
    }while(option!=5);
}
void output_deque()
{
    int option;
    do
    {
        printf("OUTPUT RESTRICTED DEQUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Insert at left");
        printf("\n 3.Delete from left");
        printf("\n 4.Display");
        printf("\n 5.Quit");
        printf("\n Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            insert_right();
            break;
            case 2:
            insert_left();
            break;
            case 3:
            delete_left();
            break;
            case 4:
            display();
            break;
        }
    }while(option!=5);
}
void insert_right()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if(left==(right+1)%MAX)
    {
        printf("\n OVERFLOW");
    }
    else if(left==-1) /* if queue is initially empty */
    {
        left = 0;
        right = 0;
        deque[right] = val;
    }
    else
    {
        right=(right+1)%MAX;
        deque[right] = val;
    }
    
}
void insert_left()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if(left==(right+1)%MAX)
    {
        printf("\n Overflow");
    }
    else if(left==-1)/*If queue is initially empty*/
    {
        left = 0;
        right = 0;
        deque[left] = val;
    }
    else
    {
        left=(left+1)%MAX;
        deque[left] = val;
    }
    
}
void delete_left()
{
    if(left==-1)
    {
        printf("\n UNDERFLOW");
    }
    else if(left == right) /*Queue has only one element */
    {
        printf("\n The deleted element is : %d", deque[left]);
        left=-1;
        right=-1;
    }
    else
    {
        printf("\n The deleted element is : %d", deque[left]);
        left=(left+1)%MAX;
    }
}
void delete_right()
{
    if(left==-1)
    {
        printf("\n UNDERFLOW");
    }
    
    else if(left == right) /*queue has only one element*/
    {
        printf("\n The element deleted is : %d", deque[right]);
        left=-1;
        right=-1;
    }
    else
    {
        printf("\n The element deleted is : %d", deque[right]);
        right=(right+1)%MAX;
    }
}
void display()
{
    int i;
    if(left==-1)
    {
        printf("\n QUEUE IS EMPTY");
        return;
    }
    printf("\n The elements of the queue are : ");
    if(left <= right )
    {
        for(i=left;i<=right;i++)
        {
            printf("%d\n",deque[i]);
        }
    }
    else
    {
        for(i=left;i<MAX;i++)
        {
            printf("%d\n", deque[i]);
        }
        for(i=0;i<=right;i++)
        {
            printf("%d\n",deque[i]);
        }
    }
    printf("\n");
}