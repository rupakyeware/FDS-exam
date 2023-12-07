#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 20

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

int pop()
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

int calc(int c1, int c2, char op) 
{
    int ans;
    switch(op) 
    {
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

        default:;

    }

    return(ans);
}

void evaluate(char post[MAX_SIZE])
{
    int i = 0, z;
    int tkn = post[i];
    
    while(tkn != '\0')
    {
        if(isalpha(tkn) != 0) 
        {
            printf("\nEnter the value of %c: ",tkn);
            scanf("%d", &z);
            push(z);
            i++;
        }
        else 
        {
            int op1 = pop();
            int op2 = pop();
            int ans = calc(op1, op2, tkn);
            push(ans);
            printf("Ans is: %d", ans);
            i++;
        }
    tkn = post[i];
    }

    printf("\nEvaluation is: %d");
    printf("%d", stack[top]);
}

int main()
{
    char post[MAX_SIZE];
    printf("\nEnter the expression- ");
    scanf("%s", post);
    evaluate(post);

    return 0;
}