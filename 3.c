#include <stdio.h>
int top = -1, a[100], size;
void display()
{
    printf("\n 1) Push");
    printf("\n 2) Peek");
    printf("\n 3) Pop");
    printf("\n 4) Display");
    printf("\n -1) To Exit");
    printf("\n Enter Your choice : ");
}
void push(int x)
{
    if (top == (size - 1))
    {
        printf("Overflow \n");
        return;
    }
    top = top + 1;
    a[top] = x;
}
void peek()
{
    if (top == -1)
    {
        printf("Empty list ");
        return;
    }
    printf("\n The top most element is %d", a[top]);
}

void pop()
{
    int temp;
    if (top == -1)
    {
        printf("\n Cannot pop, Underflow");
        return;
    }
    temp = top;
    printf("\n %d is popped out", a[temp]);
    top = top - 1;
}

void displayStack()
{
    if (top == -1)
    {
        printf("\n The stack is empty");
        return;
    }
    printf("\n The Elements are : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", a[i]);
    }
}



int main()
{
    int i, n, choice, number, flag = 0;
    display();
    scanf("%d", &choice);
    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            if (flag == 0)
            {
                printf("\n Enter  size of Stack: ");
                scanf("%d", &size);
                flag = 1;
            }

            printf("\n Enter the Number to Push : ");
            scanf("%d", &number);
            push(number);
            break;
        case 2:
            peek();
            break;
        case 3:
            pop();
            break;
        case 4:
          displayStack();
            break;
        default:
            printf("\n Wrong Choice , Try again ");
        }
        display();
        scanf("%d", &choice);

        if (choice == -1)
        {
            break;
        }
    }
    return 0;
}





//Check for palindorme


#include <stdio.h>
#include<string.h>
#include<ctype.h>
int top = -1;
int count=0;
char a[100],revStr[100];
void push(char x)
{
    if (top == (100 - 1))
    {
        printf("\n Overflow ");
        return;
    }
    top = top + 1;
    a[top] = x;
}

void pop()
{
    int temp;
    if (top == -1)
    {
        printf("\n Cannot pop, Underflow");
        return;
    }
    temp = top;
    printf("%c", a[temp]);
    revStr[count++] = a[temp];
    top = top - 1;
}

int main()
{
    char str[100],item;
    int len;
    printf("Enter the word : ");
    gets(str);
    strlwr(str);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(str[i]);
        
    }
    printf("\nThe Reverse of the string is : ");
    for (int i = 0; i < len; i++)
    {
        pop();
    }
    printf("\n");
    if(strcmp(str, revStr)){
        printf("String is not Palindrome ");
    }
    else{
        printf("String is palindrome");
    }
   
    return 0;
}


//Stack using Linked List
#include<stdlib.h>
#include<stdio.h>
struct node
{
    int info;
    struct node *next;
};
struct node * head=NULL;
int top=-1,size;


void insertbeg(int x)
{
    struct node *newnode, *temp;
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=x;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}
void deletebeg()
{
    
    struct node *temp=head;
    if(head==NULL)
    {
        printf("underflow\n");
        return;
    }   
    
    printf("%d is popped out",temp->info);
    head=head->next;
    free(temp);
}
void traverse()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("underflow\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d-->",temp->info);
        temp=temp->next;
    }

}
void main()
{
    int choice,n,i;
    for(;;)
    {
        printf("\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the number\n");
            scanf("%d",&n);
            insertbeg(n);
            break;
            case 2:
            deletebeg();
            break;
            case 3:
            traverse();
            break;
            default:
            exit(1);
        }
    }
}


//check for valid parenthisis
#include<stdio.h>
#include<string.h>
#define MAX 100

struct stack {
  char stck[MAX];
  int top;
}s;

void push(char item) {
  if (s.top == (MAX - 1))
    printf("Stack is Full\n");

  else {
    s.top = s.top + 1;
    s.stck[s.top] = item;
  }
}

void pop() {
  if (s.top == -1)
    printf("Stack is Empty\n");

  else
    s.top = s.top - 1;
}

int checkPair(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}

int checkBalanced(char expr[], int len){
      
    for (int i = 0; i < len; i++)  
    { 
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')  
        {  
          push(expr[i]); 
        } 
        else
        {
            // exp = {{}}}
            // if you look closely above {{}} will be matched with pair, Thus, stack "Empty"
            //but an extra closing parenthesis like '}' will never be matched
            //so there is no point looking forward
        if (s.top == -1) 
            return 0;
        else if(checkPair(s.stck[s.top],expr[i]))
        {
            pop();
            continue;
        }
        // will only come here if stack is not empty
        // pair wasn't found and it's some closing parenthesis
        //Example : {{}}(]
        return 0;
        }
    }    
    return 1; 
}
int main() {
  char exp[MAX] = "({})[]{}";
  int i = 0;
  s.top = -1;

  int len = strlen(exp);
  checkBalanced(exp, len)?printf("Balanced"): printf("Not Balanced"); 

  return 0;
}


/*  C Program to convert decimal to binary using stack  */

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int isEmpty(int top, int stack_arr[]);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
void DecToBin(int num);

int main()
{
        int num;
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Binary Equivalent is : ");
        DecToBin(num);

        return 0;

}/*End of main()*/

void DecToBin(int num)
{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%2;
                push(rem, &top, stack);
                num/=2;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}


void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}/*End of push()*/

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}/*End of pop()*