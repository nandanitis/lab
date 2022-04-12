#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int top=-1;
#define size 50
float stack[size];

void push(float data)
{
    if(top==size-1)
    {
        printf("Overflow\n");
        return;
    }
    top++;
    stack[top]=data;
}

float pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return 0;
    }
    float x=stack[top];
    top--;
    return x;
}

int main()
{
    char postfix[50];
    printf("Enter the postfix expression : ");
    scanf("%s",postfix);
    for(int i=0;postfix[i]!='\0';i++)
    {
        char item=postfix[i];
        if(isalpha(item)||isdigit(item))
            push(item-'0');
        else
            {
                float a,b,res;
                if(item=='+'||item=='-'||item=='*'||item=='/'||item=='$'||item=='^')
                {
                b=pop();
                a=pop();
                }
                switch(item)
                {
                    case '+':
                    res=a+b;
                    break;
                    case '-':
                    res=a-b;
                    break;
                    case '*':
                    res=a*b;
                    break;
                    case '/':
                    res=a/b;
                    break;
                    case '$':
                    case '^':
                    res=pow(a,b);
                    break;
                }
                push(res);
            }
    }
    if(top>0||top<0)
    printf("Enter a valid postfix expression\n");
    else
    printf("The answer after evaluvating the postfix expression is : %0.2f",stack[top]);
    return 0;
}