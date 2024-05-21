#include<stdio.h>
#include<stdbool.h>
void Fibonacci()
{
    int m,a,b,c;
    printf("Enter the limit: ");
    scanf("%d",&m);
    a=0,b=1;
    printf("The Fibonacci Series is: ");
    printf("%d %d ",a,b);
    for(int i = 0;i<m-2;i++)
    {
        c=a+b;
        printf(" %d ",c);
        a=b;
        b=c;
    }
}

void printFibonacci(int m)
{
    static int a = 0, b = 1, c;
    if (m > 0)
    {
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
        printFibonacci(m - 1);
    }
}

void Fibonacci_recursion()
{
    int m;
    printf("Enter the limit: ");
    scanf("%d", &m);
    printf("The Fibonacci Series is: ");
    printf("%d %d ", 0, 1);
    printFibonacci(m - 2); 
}

int main()
{
    
    bool flag = true;
    do{
    int ch;
    printf("\nMenu\n");
    printf("1: Fibonacci series without recursion.\n");
    printf("2: Fibonacci series with recursion.\n");
    printf("3: Exit program.\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

    
        switch(ch)
        {
            case 1:
            {
                Fibonacci();
                break;

            }
            case 2:
            {
                Fibonacci_recursion();
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
