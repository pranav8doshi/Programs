// C Program for Infix to Postfix conversion
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#define MAX 20

char stk[20];
int top = -1;

int isEmpty()
{
	return top == -1;
}

int isFull()
{
	return top == MAX - 1;
}

char peek()
{
	return stk[top];
}

char pop()
{
	if (isEmpty())
		return 0;

	char ch = stk[top];
	top--;
	return (ch);
}

void push(char oper)
{
	if (isFull())
		printf("Stack Full!!!!");

	else
	{
		top++;
		stk[top] = oper;
	}
}

int precedence(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int covertInfixToPostfix(char expr[])
{
	int i, j = 0;
	char post[50];
	for (i = 0; expr[i] != '\0'; i++)
	{

		if (isalnum(expr[i]))
			post[j++] = expr[i];

		else if (expr[i] == '(')
			push(expr[i]);

		else if (expr[i] == ')')
		{
			while (!isEmpty() && peek() != '(')
				post[j++] = pop();
			pop();
		}
		else
		{
			while (!isEmpty() && precedence(expr[i]) <= precedence(peek()))
				post[j++] = pop();
			push(expr[i]);
		}
	}

	// Once all inital expression characters are traversed
	// adding all left elements from stack to exp
	while (!isEmpty())
		post[j++] = pop();

	post[j] = '\0';
	printf("%s", post);
	return 0;
}

int main()
{
    bool flag = true;
    do{
    int ch;
    printf("\nMenu\n");
    printf("1: Enter the infix string.\n");
    printf("2: Convert infix to Postfix.\n");
    printf("3: Exit program.\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    char expression[20];
    
        switch(ch)
        {
            case 1:
            {
                scanf("%s",&expression);
                break;

            }
            case 2:
            {
                covertInfixToPostfix(expression);
                break;
            }
            case 3:
            {
                flag=false;
                break;
            }
            default:
                printf("Invalid choice! /n Please enetr 1 or 2");
        }
        printf("\n");
    }while(flag==true);
    printf("Program ended.");
    return 0;
}
