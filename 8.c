#include <stdio.h>
#include <stdlib.h>

struct node
{ 
    struct node *prev; 
    int data; 
    struct node *next; 
};
int count=0; 
struct node *head=NULL;

void insert_beg() 
{ 
    int a; 
    struct node *temp=head; 
    printf("Enter element\n"); 
    scanf("%d",&a); 
    struct node *new=(struct node *)malloc(sizeof(struct node)); 
    new->data=a; 
    count++; 
    if(head==NULL) 
    { 
        new->next=new->prev=NULL; 
        head=new; 
        return; 
    }
    else 
    { 
        new->next=head; 
        head->prev=new; 
        new->prev=NULL; 
        head=new; 
    }
}

void insert_before() 
{ 
    int c,d; 
    struct node *temp,*cur; 
    printf("Enter element\n"); 
    scanf("%d",&c); 
    printf("Enter before which element\n"); 
    scanf("%d",&d); 
    struct node *new=(struct node *)malloc(sizeof(struct node)); 
    new->data=c; 
    count++; 
    if(head==NULL)
    { 
        new->next=new->prev=NULL; 
        head=new; return; 
    }
    if(head->data==d) 
    { 
        new->next=head; 
        head->prev=new; 
        new->prev=NULL; 
        head=new; 
    } 
    temp=head; 
    while(temp!=NULL && temp->data<d) 
    { 
        cur=temp; 
        temp=temp->next; 
    } 
    cur->next=new; 
    new->prev=cur; 
    new->next=temp; 
    temp->prev=new; 
}

void display() 
{ 
    struct node *temp=head; 
    while(temp!=NULL) 
    { 
        printf("%d->",temp->data); 
        temp=temp->next; 
    } 
    printf("NULL");
}

void delete_middle() 
{ 
    struct node *temp=head,*old; 
    int i,mid; mid=count/2;
    if(count%2==0) 
    { 
        for(i=1;i<mid;i++) 
        { 
            old=temp; temp=temp->next; 
        } 
    } 
    else
    { 
        for(i=1;i<=mid;i++)
        { 
            old=temp; temp=temp->next; 
        } 
    } 
    old->next=temp->next; 
    temp->next->prev=old; 
    free(temp); 
}

int main() 
{ 
    int g; 
    while(1) 
    { 
        printf("\nEnter 1 to insert beg\nEnter 2 to insert end\nEnter 3 to insert before a value\nEnter 4 to display\nEnter 5 to exit\n"); 
        scanf("%d",&g); 
        switch(g) 
        { 
            case 1: insert_beg(); 
            break; 

            case 2: insert_end();
            break;
             
            case 3:insert_before(); 
            break; 
            
            case 4: display(); 
            break; 
            
            case 5: exit(0); 
            break; 
            
            case 6: delete_beg(); 
            break; 
            
            case 7: delete_end(); 
            break; 
            
            case 8: delete_middle(); 
            break; 
            
            default: printf("Wrong choice\n"); 
            break; 
            } 
        } 
    return 0; 
}