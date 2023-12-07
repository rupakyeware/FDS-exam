#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 10
char stack[MAX];
int top = -1;

void in_post(char[], char[]);
void post_eval(char[]);

int isEmpty()
{
	return top == -1;
}

int isFull()
{
	return top == MAX - 1 ;
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

void push(char ch)
{
	if(isFull())
		printf("\nStack is full!");
	else 
	{
		top++;
		stack[top] = ch;
	}
}

char pop()
{
	if (isEmpty())
		printf("\nStack is empty!");
	else
	{
		char temp = stack[top];
		top--;
		return temp;
	}
}

void in_post(char infix[], char postfix[])
{
	int k = 0, i = 0;
	char tkn = infix[i];
	
	while(tkn != '\0')
	{
		if(isalpha(tkn))
		{
			postfix[k] = infix[i];
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
				while(!isEmpty() && stack[top] != '(')
				{
					postfix[k] = pop();
					k++;
				}
				pop();
			}
			else
			{
				while(!isEmpty() && isp(stack[top]) >= icp(tkn))
				{
					postfix[k] = pop();
					k++;
				}
				push(tkn);
			}
		}
		i++;
		tkn = infix[i];
	}

	if (!isEmpty())
	{
		postfix[k] = pop();
		k++;
	}

	postfix[k] = '\0';
		
	printf("\nPostfix expression- %s", postfix);
}

int calc(int x, int y, char op)
{
	int ans;
	switch(op)
	{
		case '+':
			return ans = x + y;
		case '-':
			return ans = x - y;
		case '*':
			return ans = x * y;
		case '/':
			return ans = x / y;
		case '^':
			return ans = pow(x, y);
	}
}

void post_eval(char postfix[])
{
	int i = 0, tkn = postfix[i], res, val;
	
	while(tkn != '\0')
	{
		if (isalpha(tkn))
		{
			printf("\nEnter the value for %c: ", tkn);
			scanf("%d", &val);
			push(val);
		}
		else
		{
			int a = pop();
			int b = pop();
			res = calc(a, b, tkn);
			push(res);
		}
		i++;
		tkn = postfix[i];
	}

	printf("\nResult is: %d", res);
}

int main()
{
	char infix[MAX];
	char postfix[MAX];
	printf("\nEnter an infix expression: ");
	scanf("%s", &infix);
	in_post(infix, postfix);
	post_eval(postfix);	

	return 0;
}
