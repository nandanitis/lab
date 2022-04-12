#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void display()
{

    printf("\n 1) Insert Element At Rare  ");
    printf("\n 2) Delete Element at Begining ");
    printf("\n 3) Display ");
    printf("\n  -1 to Exit  ");
}

void insertAtTail(int key)
{
    struct node *temp=head;
    struct node *fnNode = (struct node*)malloc(sizeof(struct node));
    fnNode->data=key;

    if(head==NULL)
    {
        fnNode->next=NULL;
        head=fnNode;
        return;
    }

    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next=fnNode;
    fnNode->next=NULL;
    
}

void delete_beg()
{
    if(head==NULL)
    {
        printf("empty");
        return;
    }
    struct node *temp=head;
    head=head->next;
    free(temp);
    
}

void traverse()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("empty");
        return;
    }
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp= temp->next;
    }
}

int main()
{
    int num, option;
    display();
    printf(" Your OPTION :  ");
    scanf("%d", &option);
    while (option != -1)
    {
        switch (option)
        {

        case 1:
            printf("\n Enter the Element to insert at rare  : ");
            scanf("%d", &num);
            insertAtTail(num);
            break;

        case 2:
            delete_beg();
            break;

        case 3:
            printf("\n The elements are = ");
            traverse();
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



void insertAtbeg(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->next = head;
    head = newnode;
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


void minimum()
{
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("\n Empty Linked List");
        return;
    }
    int small = temp->info;

    while (temp != NULL)
    {
        if (temp->info <= small)
        {
            small = temp->info;
        }
        temp = temp->next;
    }

    printf("\n Smallest element in linked list is %d \n\n", small);
}


