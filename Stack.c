#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100
char stack[MAX];
int top = -1;

void strrev(char *str)
{
    int i = strlen(str) - 1, j = 0;
    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char data)
{
    if (isFull())
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = data;
    }
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
        char data = stack[top];
        top--;
        return data;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%c ", stack[i]);
        }
        printf("\n");
    }
}

int isp(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
};

int icp(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 4;
    }
    else if (ch == '(')
    {
        return 5;
    }
    else
    {
        return 0;
    }
};

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while (isp(stack[top]) >= icp(infix[i]))
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
        }
        i++;
    }
    while (!isEmpty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

int calc(int c1, int c2, char op){
    int ans;
    switch (op){
    case '+':
        ans = c1 + c2;
        break;
    case '-':
        ans = c1 - c2;
        break;
    case '*':
        ans = c1 * c2;
        break;
    case '/':
        ans = c1 / c2;
        break;
    case '^':
        ans = pow(c1, c2);
        break;
    default:
        break;
    }
    return ans;
}
void evaluatePostfix(char postfix[])
{
    int res, z;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isalpha(postfix[i]))
        {
            printf("Enter the value of %c: ", postfix[i]);
            scanf("%d", &z);
            push(z);
        }
        else
        {
            int c1 = pop();
            int c2 = pop();
            res = calc(c2, c1, postfix[i]);
            push(res);
        }
    }
    printf("Result: %d\n", res);
}

int main()
{
    char infix[20], postfix[20], prefix[20];
    int a, b, c, d;
    printf("Enter Postfix algorithm:");
    scanf("%s", postfix);
    evaluatePostfix(postfix);
    return 0;
}
