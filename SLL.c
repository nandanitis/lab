#include <stdio.h>
#include<stdlib.h>
void insert_beg();
void del_beg();
void display();
void insert_end();
void del_end();
void traverse();
void sort();
void insert_sorted();
void traverse_min();
void reversal();
void reverse_printing(struct node *start);
bool isPrime(int x);
void min_max_prime();
void insert_before();
void insert_after();
void delete_before();
void delete_after();
void removeDuplicates();

struct node
{
    int info;
    struct node* next;
};

struct node* start=NULL;

int main()
{
    while(1)
    {
        int c;
        printf("1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Delete at beginning\n");
        printf("4.Delete at end\n");
        printf("5.Display\n");
        printf("6.Traverse\n");
        printf("7.Sort the SLL\n");
        printf("8.Insert in sorted manner\n");
        printf("9.Reverse\n");
        printf("10.Insert before\n");
        printf("11.Insert after\n");
        printf("12.Delete before\n");
        printf("13.Delete after\n");
        printf("14.Remove Duplicates\n");
        printf("15.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            insert_beg();
            break;
            case 2:
            insert_end();
            break;
            case 3:
            del_beg();
            break;
            case 4:
            del_end();
            break;
            case 5:
            display();
            break;
            case 6:
            traverse();
            break;
            case 7:
            sort();
            break;
            case 8:
            insert_sorted();
            break;
            case 9:
            reversal();
            break;
            case 10:
            insert_before();
            break;
            case 11:
            insert_after();
            break;
            case 12:
            delete_before();
            break;
            case 13:
            delete_after();
            break;
            case 14:
            removeDuplicates();
            break;
            default:
            exit(0);
        }
    }



    return 0;
}

void insert_beg()
{
    int x;
    struct node *p;
    printf("Enter the element:\n");
    scanf("%d",&x);
    p=(struct node*)malloc(sizeof(struct node));  
    if(start==NULL)
    {
        p->info=x;
        p->next=NULL;
        start=p;
    }
    else
    {
        p->info=x;
        p->next=start;
        start=p;
    }
}

void del_beg()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("empty list\n");
    }
    else
    {
        start=temp->next;
        printf("The deleted element is:%d\n",temp->info);
        free(temp);
    }
    printf("\n");
}

void display()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        printf("The elements are:\n");
        while(temp!=NULL)
        {
            printf("%d --> ",temp->info);
            temp=temp->next;
        }
    }
    printf("NULL\n");
}

void insert_end()
{
        struct node *p = (struct node*)malloc(sizeof(struct node));
        struct node *temp=start;
        int item;
        printf("Enter element to be inserted:\n");
        scanf("%d",&item);
        if(start == NULL)
        {
            p->info = item;
            p -> next = NULL;
            start = p;
        }
        else
        {
            while (temp->next!= NULL)
            {
                temp = temp -> next;
            }
            p->info = item;
            temp->next = p;
            p->next = NULL;

            
        }
}

void del_end()
{
    struct node *temp,*follow;

    if(start==NULL)
    {
        printf("empty list\n");
    }
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        printf("Deleted element is:%d\n",temp->info);
        free(temp);
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            follow=temp;
            temp=temp->next;

        }
        follow->next=NULL;
        printf("Deleted element is:%d\n",temp->info);
        free(temp);
    }

}

void traverse()
{
    int x;
    int i=1,flag=0;
    struct node* temp=start;
    printf("Enter element to be searched:\n");
    scanf("%d",&x);
    while(temp!=NULL)
    {
        if(temp->info==x)
        {
            printf("Element found at node %d\n",i);
            flag=1;
            break;
        }
        temp=temp->next;
        i++;
    }
    if(flag==0)
        printf("Element not found\n");
}

void insert_sorted()
{
    struct node *temp=start,*follow=NULL;
    int x;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted in sorted sll:\t");
    scanf("%d",&x);
    int flag=1;

    if(start==NULL)
    {
        p->info=x;
        p->next=NULL;
        start=p;
        return ;
    }

    if(x<=start->info)
    {
        p->info=x;
        p->next=start;
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

    if(flag==0)
    {
        p->info=x;
        follow->next=p;
        p->next=temp;
    }

    else
    {
        p->info=x;
        temp->next=p;
        p->next=NULL;
    }
}
void traverse_min()
{
    int min=99999;
    struct node* temp=start;
    if(start==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->info<min)
            min=temp->info;
            temp=temp->next;
        }
        printf("Smallest element %d\n",min);
    }
}

void reversal()
{
    struct node *prev = NULL;
    struct node *current = start;
    struct node *next=NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    start = prev; 
}

void reverse_printing(struct node *start)    //reverse printing without actual reversal
{
    if(start==NULL)
        return ;
    else
    {    
        reverse_printing(start->next);
        printf("%d\t",start->info);
    }
}

void sort()
{
    int x;
    struct node *temp=start,*index;
    if(start==NULL)
    {
        printf("Empty list\n");
        return ;
    }
    else
    {
        while(temp->next!=NULL)            //temp =20
        {
            index=temp->next;        //index= 10
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
        printf("Linked List sorted\n");
    }
}

struct node *mergesort(struct node *a,struct node *b)
{
    struct node *temp=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    if (a->info<=b->info)
    {
        temp=a;
        temp->next=mergesort(a->next, b);
    }
    else
    {
        temp=b;
        temp->next=mergesort(a, b->next);
    }
    return temp;
}

void insert_after()
{
    int key,x;
    struct node *temp=start;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted:\t");
    scanf("%d",&x);
    printf("Enter the key after which the element is to be inserted:\t ");
    scanf("%d",&key);
    if(start==NULL)
    {
        printf("Empty list\n");
        return ;
    }
    while(temp->next!=NULL && temp->info!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
        printf("key  not found\n");
    else
    {
        p->info=x;
        p->next=temp->next;
        temp->next=p;
    }
}

void insert_before()
{
    int key,x;
    struct node *temp=start,*follow;
    struct node *p;
    printf("Enter element to be inserted:\t");
    scanf("%d",&x);
    printf("Enter the key before which the element is to be inserted:\t ");
    scanf("%d",&key);
    if(start==NULL)
    {
        printf("Empty list\n");
        return ;
    }
    if(start->info==key)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->info=x;
        p->next=start;
        start=p;
        return ;
    }
    while(temp!=NULL && temp->info!=key)
    {
        follow=temp;
        temp=temp->next;                               
    }
    if(temp==NULL)
        printf("key not found\n");
    else
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->info=x;
        follow->next=p;
        p->next=temp;
    }   

}

void delete_before()
{
    struct node *follow=NULL,*temp=start;
    int key;
    printf("Enter the key before which the element is to be deleted:\t ");
    scanf("%d",&key);
    if(start==NULL)
    {
        printf("Empty list\n");
        return ;
    }
    if(start->info==key)
    {
        printf("Deletion not possible\n");
        return ;
    }
    if(start->next->info==key)
    {
        start=start->next;
        printf("Deleted element is %d",temp->info);
        free(temp);
        return ;

    }
    while(temp!=NULL && temp->next->info!=key)
    {
        follow=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Key not found\n");
    }
    else
    {
        follow->next=temp->next;
        printf("Deleted element is %d",temp->info);
        free(temp);
    }


}

void delete_after()
{
    struct node *temp2,*temp=start;
    int key;
    printf("Enter the key after which the element is to be deleted:\t ");
    scanf("%d",&key);
    if(start==NULL)
    {
        printf("Empty list\n");
        return ;
    }
    while(temp!=NULL && temp->info!=key)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        printf("Deletion not possible\n");
    }
    else
    {
        temp2=temp->next;
        temp->next=temp2->next;
        printf("Deleted element is %d\n",temp2->info);
        free(temp2);
    }
}

bool isPrime(int x)
{
    int flag=1;
    if(x==1||x==0)
        return 0;
    for(int i=2;i<=x/2;i++)
    {
        if(x%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
        return 0;
    else
        return 1;
}

void min_max_prime()
{
    struct node *temp=start;
    int min=999;
    int max=-999;
    while(temp!=NULL)
    {
        if(temp->info<min && isPrime(temp->info))
        {
            min=temp->info;
        }
        if(temp->info>max && isPrime(temp->info))
        {
            max=temp->info;
        }
        temp=temp->next;
    }
    printf("Max element:%d\n",max);
    printf("Min element:%d\n",min);

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



