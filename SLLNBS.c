#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head=NULL;
void insert_beg()
{
    int x;
    struct node *new_node;
    new_node=((struct node *)malloc(sizeof(struct node)));
    printf("enter the element to be inserted at the beginning\n");
    scanf("%d",&x);
    if(head==NULL)
    {
        new_node->info=x;
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
    new_node->info=x;
    new_node->next=head;
    head=new_node;
    }
}
void insert_end()
{
    int x;
    struct node *new_node;
    struct node *temp=head;
    new_node=((struct node *)malloc(sizeof(struct node)));
    printf("enter the element to be inserted at the end\n");
    scanf("%d",&x);
    if(head==NULL)
    {
        new_node->info=x;
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        new_node->info=x;
        new_node->next=NULL;
        temp->next=new_node;
    }
}
 void delete_beg()
 {
    struct node *temp;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        temp=head;
        head=temp->next;
        printf("the deleted element is %d\n",temp->info);
        free(temp);
    }
 }
 void delete_end()
 {
    struct node *temp=head;
    struct node *follow=head;
    if(head==NULL)
    {
        printf("no node\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            follow=temp;
            temp=temp->next;
        }
        follow->next=temp->next;
        printf("The deleted element is %d\n",temp->info);
        free(temp);

    }
 }
 void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("no node\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}
 void find()
 {
    int count=0,x;
    struct node *temp=head;
    printf("Enter the element to be found\n");
    scanf("%d",&x);
    if(head==NULL)
    {
        printf("No node\n");
    }
    else
    {
        while(temp->info!=x && temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(temp==NULL)
        {
            printf("element is not found\n");
        }
        else
        {
            printf("the element is found at %d\n",count);
        }

    }
 }
 void insert_before()
 { 
    int x;
    int key;
    struct node *temp=head;
    struct node *follow=head;
    struct node *new_node;
    new_node=((struct node *)malloc(sizeof(struct node)));
    printf("enter the element to be entered\n");
    scanf("%d",&x);
    printf("enter the key before the which the element is to be inserted\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        while(temp->info!=key && temp!=NULL)
        {
            follow =temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("key not found\n");
        }
        else
        {
            new_node->info=x;
            new_node->next=temp;
            follow->next=new_node;
        }
    }
 }
 void insert_after()
 {
    int x;
    int key;
    struct node *temp=head;
    struct node *new_node;
    new_node=((struct node *)malloc(sizeof(struct node)));
    printf("enter the element to be entered\n");
    scanf("%d",&x);
    printf("enter the key after the which the element is to be inserted\n");
    scanf("%d",&key);
    if(head==NULL)
        {
            printf("No node\n");
        }
        else
        {
            while(temp!=NULL && temp->info!=key)
            {
                temp=temp->next;
            }
            if(temp==NULL)
            {
                printf("key not found\n");
            }
            else
            {
                new_node->info=x;
                new_node->next=temp->next;
                temp->next=new_node;
            }
        }
 }
 void delete_before()
 {
    struct node * follow=head;
    struct node * temp=head;
    int key;
    printf("enter the key before the which the element is to be deleted\n");
    scanf("%d",&key);

    if(head==NULL)
    {
        printf("No node\n");
        return;
    }
    if(head->info==key)
    {
        printf("can not be deleted\n");
        return;
    }
    if(head->next->info==key)
    {
        temp=head;
        head=temp->next;
        printf("the deleted element is %d\n",temp->info);
        free(temp);
        return;
    }
    else
    {
        while(temp!=NULL && temp->next->info!=key)
        {
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("key not found\n");
        }
        follow->next=temp->next;
        printf("the deleted element is %d\n",temp->info);
        free(temp);
    }

 }
 void delete_after()
 {
    struct node * temp2=head;
    struct node * temp=head;
    int key;
    printf("enter the key after the which the element is to be deleted\n");
    scanf("%d",&key);

    if(head==NULL)
    {
        printf("No node\n");
        return;
    }

    else
    {
        while(temp!=NULL && temp->info!=key)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("element not found\n");
        }
        else if(temp->next->next==NULL)
        {
            printf("Can not be deleted\n");
        }
        else
        {
            temp2=temp->next;
            temp->next=temp2->next;
            printf("the deleted element is %d\n",temp2->info);
            free(temp2);
        }
    }

}

void sort()
{
    int x;
    struct node *temp=head;
    struct node *index;
    if(head==NULL)
    {
        printf("empty list\n");
    }
    else
    {
        while(temp!=NULL)
         {
             index=temp->next;
             while(index!=NULL)
             {
                 if(temp->info>index->info)
                 {
                 x=temp->info;
                 temp->info=index->info;
                 index->info=x;
                 }
                index=index->next;
             }
            temp=temp->next; 
         }
         
    }
}

int main()
{
    while(1)
    {
        int c;
        printf("1.Insert at beginning\n2.Insert at end\n3.Delete at beginning\n4.Delete at end\n5.Display\n6.Insert before\n7.Insert after\n8.Delete before\n9.Delete after\n10.Find an element\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:insert_beg();
            break;
            case 2:insert_end();
            break;
            case 3:delete_beg();
            break;
            case 4:delete_end();
            break;
            case 5:display();
            break;
            case 6:insert_before();
            break;
            case 7:insert_after();
            break;
            case 8:delete_before();
            break;
            case 9:delete_after();
            break;
            case 10:find();
            break;

        }
    }
    return 0;

}