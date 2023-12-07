#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 10

int top = -1;
char stack[MAX_SIZE];

int isFull()
{
    return top == MAX_SIZE - 1;
}

int isEmpty()
{
    return top == -1;
}

void push(char item)
{
    if (isFull())
    {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = item;
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
    {
        char temp = stack[top];
        top--;
        return temp;
    }
}

int icp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 4;
    if (ch == '(')
        return 5;
    else
        return 0;
}

int isp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    else
        return 0;
}

void in_post(char inexp[])
{
    char postexp[MAX_SIZE];
    int k = 0, i = 0;
    char tkn = inexp[i];
    while (tkn != '\0')
    {
        if (isalpha(tkn))
        {
            postexp[k] = inexp[i];
            k++;
        }
        else
        {
            if (tkn == '(')
            {
                push('(');
            }
            else if (tkn == ')')
            {
                while (!isEmpty() && stack[top] != '(')
                {
                    postexp[k] = pop();
                    k++;
                }
                pop();
            }
            else
            {
                while (!isEmpty() && isp(stack[top]) >= icp(tkn))
                {
                    postexp[k] = pop();
                    k++;
                }
                push(tkn);
            }
        }
        i++;
        tkn = inexp[i];
    }

    while (!isEmpty())
    {
        postexp[k] = pop();
        k++;
    }


    printf("Postfix expression: ");
    for (int j = 0; j < k; j++)
    {
        printf("%c", postexp[j]);
    }
    printf("\n");
}

int main()
{
    char infix[MAX_SIZE];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    in_post(infix);

    return 0;
}