#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top=-1;

void push(int item)
{
    if(top>=SIZE-1)
        printf("\nstack overflow.");
    else
    {
        top++;
        stack[top]=item;
    }
}

int pop()
{
    int item;
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
    return -1;
}

int peek()
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


int result(int a,char c,int b)
{
    switch(c)
    {
        case '+':return(a+b);
        break;
        case '-':return(a-b);
        break;
        case '*':return(a*b);
        break;
        case '/':return(a/b);
        break; 
    }
    return 0;
}

void evaluatePost(char postfix[])
{
    int i=0,b,a,x;
    char item=postfix[i];
    while(item!='\0')      //456+*   4  //push(item-'0')   push('5'-'0') push(53 - 48) 
    {
        if(isdigit(item)||isalpha(item))
        {
            push(item-'0');
        }
        else
        {
            b=pop();
            a=pop();
            x=result(a,item,b);
            push(x);
        }
        i++;
        item=postfix[i];
    }
    x=pop();
    printf("Answer is:%d\t",x);
}
int main()
{
    char postfix[SIZE];
    printf("Enetr expression");
    gets(postfix);
    evaluatePost(postfix); 
    return 0;

}

