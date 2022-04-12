#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev,*next;
};

struct node *start=NULL;

void insert_beg()
{
    int x;
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted:\t");
    scanf("%d",&x);
    if(start==NULL)
    {
        p->info=x;
        p->next=NULL;
        p->prev=NULL;
        start=p;
    }
    else
    {
        p->info=x;
        p->next=start;
        p->prev=NULL;
        start->prev=p;
        start=p;
    }
}

void insert_beg(int x)   //parameterized func for insert_before,same as insert_beg()
{   
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        p->info=x;
        p->next=NULL;
        p->prev=NULL;
        start=p;
    }
    else
    {
        p->info=x;
        p->next=start;
        p->prev=NULL;
        start->prev=p;
        start=p;
    }
}

void insert_end()
{
    int x;
    struct node *p,*temp=start;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted:\t");
    scanf("%d",&x);
    if(start==NULL)
    {
        p->info=x;
        p->next=NULL;
        p->prev=NULL;
        start=p;
    }
    else if(start->next==NULL)
    {
        p->info=x;
        p->prev=start;
        p->next=NULL;
        start->next=p;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        p->info=x;
        p->prev=temp;
        p->next=NULL;
        temp->next=p;
    }
}

void delete_beg()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("Empty list\n");
    }
    else if(start->next==NULL)
    {
        printf("Deleted element is %d\n",start->info);
        start=NULL;
    }
    else
    {
        temp=start;
        start=temp->next;
        printf("Deleted element is %d\n",temp->info);
        free(temp);
    }
}

void delete_end()
{
    struct node *temp=start,*follow;
    if(start==NULL)
    {
        printf("Empty list\n");
    }
    else if(start->next==NULL)
    {
        printf("Deleted element is %d\n",start->info);
        start=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            follow=temp;
            temp=temp->next;
        }
        printf("Deleted element is %d\n",temp->info);
        follow->next=NULL;
        free(temp);
        
    }
}

void display()
{
    struct node *temp=start;
    if(start==NULL)
    {
        printf("Empty dll\n");
    }
    else
    {
        printf("The elements are:\nNULL");
        while(temp!=NULL)
        {
            printf(" <-- %d --> ",temp->info);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

void insert_before()
{
    int x,key;
    struct node *temp=start,*follow=NULL,*p;
    printf("Enter element to be inserted:\t");
    scanf("%d",&x);
    printf("Enter key before which to be inserted:\t");
    scanf("%d",&key);
    p=(struct node *)malloc(sizeof(struct node));
    p->info=x;
    while(temp->info!=key)
    {
        follow=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Element not found\n");
    }
    else if(start->info==key)
    {
        insert_beg(x);
    }
    else
    {
        temp->prev=p;
        p->prev=follow;
        follow->next=p;
        p->next=temp;
    }



}

void delete_middlenode()
{
    struct node *temp1=start;
    int count=0;
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        count++;
    }

    if(count%2!=0)
    {
        struct node* temp2=start,*follow;
        int count2=1;
        while(count2!=(count/2)+1)
        {
            follow=temp2;
            temp2=temp2->next;
            count2++;
        }
        printf("Deleted element is %d\n",temp2->info);
        follow->next=temp2->next;
        temp2->next->prev=follow;
        free(temp2);
    }

    else
    {
        struct node* temp2=start,*follow;
        int count2=1;
        while(count2!=(count/2))
        {
            follow=temp2;
            temp2=temp2->next;
            count2++;
        }
        printf("Deleted element is %d\n",temp2->info);
        follow->next=temp2->next;
        temp2->next->prev=follow;
        free(temp2);
    }
}

void reverse()
{
    struct node *curr=start,*follow=NULL,*index=NULL;
    while(curr!=NULL)
    {
        index=curr->next;
        curr->prev=index;
        curr->next=follow;
        follow=curr;
        curr=index;
    }
    start=follow;
}

// void reverse() {
//     struct node *curr=start,*follow=start;
//     while(curr!=NULL)
//     {
//         follow=curr->prev;
//         curr->prev=curr->next;
//         curr->next=follow;
//         curr=curr->prev;
//     }
//     start=follow->prev;

// }

void sortedInsert() 
{
    int x;
    printf("Enter element to be inserted in sorted manner:\n");
    scanf("%d",&x);
    struct node* temp=start,*follow=NULL,*p;
    p=(struct node *)malloc(sizeof(struct node));
    int flag=1;

    if(start==NULL)
    {
        p->info=x;
        p->next=NULL;
        p->prev=NULL;
        start=p;
        return ;
    }

    while(temp->next!=NULL)
    {
        follow=temp;
        temp=temp->next;
        if(x>=follow->info && x<=temp->info)
        {
            flag=0;   
            break;
        }
    }

    if(x<=start->info)
    {
        p->info=x;
        p->next=start;
        p->prev=NULL;
        start->prev=p;
        start=p;
    }

    else if(flag==0)
    {
        p->info=x;
        p->prev=follow;
        follow->next=p;
        p->next=temp;
        temp->prev=p;
    }

    else
    {
        p->info=x;
        temp->next=p;
        p->prev=temp;
        p->next=NULL;
    }


}

int main()
{
    while(1)
    {
        int c;
        printf("1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Display\n");
        printf("4.Delete at beginning\n");
        printf("5.Delete at end\n");
        printf("6.Insert before a key\n");
        printf("7.Delete middle node\n");
        printf("8.Reverse\n");
        printf("9.Insertion sort\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:insert_beg();
            break;
            case 2:insert_end();
            break;
            case 3:display();
            break;
            case 4:delete_beg();
            break;
            case 5:delete_end();
            break;
            case 6:insert_before();
            break;
            case 7:delete_middlenode();
            break;
            case 8:reverse();
            break;
            case 9:sortedInsert();
            break;
            default:exit(0);
        }
    }
}



