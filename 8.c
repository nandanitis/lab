
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
int count=0; 


void display()
{
    printf("\n 1) Insert Element At begining ");
    printf("\n 2) Traverse doubly Linked List");
    printf("\n 3) Insert Before a given value ");
    printf("\n 4) Delete the Middle element ");
    printf("\n  -1 to Exit  ");
}

void insertAtbeg(int number)
{
    struct node *temp = head;
    struct node *fnNode = (struct node *)malloc(sizeof(struct node));
    fnNode->info = number;
    count++;
    if (head == NULL)
    {
        fnNode->prev = fnNode->next = NULL;
        head = fnNode;
        return;
    }
    else
    {
        fnNode->next = head;
        head->prev = fnNode;
        fnNode->prev = NULL;
        head = fnNode;
    }
}

void traverse()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("\n Empty linked list");
        return;
    }
    while (temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->next;
    }
    printf("\n ");
}

void insertBefore(int number, int item)
{
    int flag = 0;
    struct node *fnNode = (struct node *)malloc(sizeof(struct node));
    fnNode->info = item;
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("empty linked list\n");
        return;
    }
    count++;
    if (temp->info == number)
    {
        insertAtbeg(item);
        flag = 1;
        return;
    }
    while (temp != NULL)
    {
        if (temp->info == number)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("\n Element not found");
        return;
    }
    fnNode->prev = temp->prev;
    temp->prev = fnNode;
    fnNode->next = temp;
    fnNode->prev->next = fnNode;

    printf("\n Element has been inserted \n");
}

void deletemid() 
{ 
    struct node *temp=head,*old; 
    int i,mid; mid=count/2;
    if(count%2==0) 
    { 
        for(i=1;i<mid;i++) 
        { 
            old=temp; 
            temp=temp->next; 
        } 
    } 
    else
    { 
        for(i=1;i<=mid;i++)
        { 
            old=temp; 
            temp=temp->next; 
        } 
    } 
    old->next=temp->next; 
    temp->next->prev=old; 
    free(temp); 
}

int main()
{
    int num, option, before;
    display();
    printf(" Your OPTION :  ");
    scanf("%d", &option);
    while (option != -1)
    {
        switch (option)
        {

        case 1:
            printf("\n Enter the Element to insert at Front  : ");
            scanf("%d", &num);
            insertAtbeg(num);
            break;

        case 2:
            printf("\n The elements are = ");
            traverse();
            break;

        case 3:
            printf("\n Enter the element before which it has to be inserted :  ");
            scanf("%d", &before);
            printf("\n Enter the element  to be inserted :  ");
            scanf("%d", &num);
            insertBefore(before, num);
            break;

        case 4:
            deletemid();
            break;

        default:
            printf("\n Wrong option, Please try again ");
        }

        display();
        printf("\n Your OPTION :  ");
        scanf("%d", &option);
    }
    return 0;
}
