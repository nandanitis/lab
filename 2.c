#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};

struct node *head=NULL;

void display()
{
    printf("\n 1) Insert Element At Rare  ");
    printf("\n 2) Display ");
    printf("\n  -1 to Exit  ");
}

void sortInsert(int number)
{
    struct node *temp=head;
    struct node *fnNode=(struct node*)malloc(sizeof(struct node));
    fnNode->info=number;
    if(temp==NULL || temp->info >= fnNode->info)
    {
        fnNode->next=head;
        head=fnNode;
        return;

    }
    while(temp->next!=NULL && temp->next->info<number)
    {
        temp=temp->next;
    }
    fnNode->next= temp->next;
    temp->next = fnNode;
}

void traverse()
{
    struct node *temp = head;
    if (head == NULL)
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

int main()
{
    int num, number, option;
    display();
    printf("\n Your OPTION :  ");
    scanf("%d", &option);
    while (option != -1)
    {
        switch (option)
        {
        case 1:
            printf("\n Element  : ");
            scanf("%d", &num);
            sortInsert(num);
            break;
        case 2:
            printf("\n The elements are = ");
            traverse();
            break;
        default:
            printf("\n Wrong option, Please try again ");
        }

        display();
        printf("\n Your OPTION :  ");
        scanf("%d", &option);
        if (option == -1)
        {
            printf("Thank You, VISIT AGAIN");
        }
    }
    return 0;
}


void removeDuplicates()
{
    struct node *temp=start,*index;
    while(temp->next!=NULL)
    {
        index=temp->next;
        if(temp->info==index->info)
        {
            temp->next=index->next;
        }
        else
        {
            temp=temp->next;
        }
    }


}

void reversal()
{
    struct node *prevptr = NULL;
    struct node *currtptr = head;
    struct node *nextptr;

    while (currtptr != NULL)
    {
        nextptr = currtptr->next;
        currtptr->next = prevptr;

        prevptr = currtptr;
        currtptr = nextptr;
    }

    head = prevptr;
}


