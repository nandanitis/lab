#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100
char stack[SIZE];
int top=-1;


void push(char item)
{
    if(top>=SIZE-1)
        printf("\nstack overflow.");
    else
    {
        top++;
        stack[top]=item;
    }
}

char pop()
{
    char item;
    if(top<0)
    {
        printf("Stack underflow:invalid infix\n");
    }
    else
    {
        item=stack[top];
        top--;
        return(item);
    }
}

char peek()
{
    char item;
    if(top<0)
    {
        
        printf("stack underflow:invalid infix\n");
        exit(1);
    }
    else
    {
        item=stack[top];
        return(item);
    }

}

void display()
{
    if(top==-1)
        printf("Empty list\n");
    else
    {
        printf("Stack elements are:\n");
        for(int i=top;i>-1;i--)
            printf("%d\t",stack[i]);
    }
}

int prec(char x)
{
    if(x=='^')
        return(3);
    else if(x=='*'||x=='/')
        return(2);
    else if(x=='+'||x=='-')
        return(1);
    else //if(x=='('||x==')')
        return(0);
}

void InToPost(char infix[],char postfix[])
{
    char item,x,y;
    int i=0,j=0;
    push('#');

    item=infix[i];

    while(item!='\0')
    {
        if(isdigit(item)||isalpha(item))
        {
            postfix[j]=item;
            j++;
        }
        else if(item=='(')
        {
            push('(');
        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix[j]=x;
                j++;
                x=pop();
            }
        }
        else
        {
            y=peek(); //y=topmost element of stack
            while(prec(y)>=prec(item))  //item=scanned element
            {
                x=pop();
                postfix[j]=x;
                j++;
                y=peek();
            }
            push(item);
        }
        i++;
        item=infix[i];

    }

    while(peek()!='#')
    {
        postfix[j]=pop();
        j++;
    }

    postfix[j]='\0';
}

int main() {

    char infix[SIZE],postfix[SIZE];

    printf("Enter infix:\n");
    gets(infix);

    InToPost(infix,postfix);
    printf("Postfix expression:\n");
    puts(postfix);

    return 0;
}

