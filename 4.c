#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;
void push(char item)
{
    if (top >= 100 - 1)
    {
        printf("\n Overflow ");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

char pop()
{
    char item;
    if (top < 0)
    {
        printf("\n Underflow: Invalid expression   ");
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

char peek()
{
    char item;
    if (top < 0)
    {
        printf("\n Underflow : Invalid expression ");
        exit(1);
    }
    else
    {
        item = stack[top];
        return (item);
    }
}

int prec(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '(')
        return 1;
    else
        return 0;
}

// what is precedance of ^

void intopos(char in[], char pos[])
{
    char item, x, y;
    int i = 0, j = 0;
    push('#');
    item = in[i];
    while (item != '\0')
    {
        if (isdigit(item) || isalpha(item))
        {
            pos[j] = item;
            j++;
        }
        else if (item == '(')
        {
            push('(');
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                pos[j] = x;
                j++;
                x = pop();
            }
        }

        else
        {
            y = peek();
            while (prec(y) >= prec(item))
            {
                x = pop();
                pos[j] = x;
                j++;
                y = peek();
            }
            push(item);
        }
        i++;
        item = in[i];
    }
    while (peek() != '#')
    {
        pos[j] = pop();
        j++;
    }

    pos[j] = '\0';
}


void main()
{
    char in[100], pos[100];
    printf("Enter infix :");
    gets(in);
    intopos(in, pos);
    printf("After conversion :");
    puts(pos);
}