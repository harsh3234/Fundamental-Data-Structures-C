#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int val)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow!");
    }
    else
    {
        stack[++top1] = val;
        printf("Pushed in Stack 1: %d\n", val);
    }
}

void push2(int val)
{
    if (top2 - 1 == top1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        stack[--top2] = val;
        printf("Pushed in Stack 2: %d\n", val);
    }
}
void pop1()
{
    if (top1 == -1)
        printf("Stack Underflow!\n");
    else
    {
        printf("Popped from Stack1: %d\n", stack[top1]);
        top1--;
    }
}

void pop2()
{
    if (top2 == SIZE)
        printf("Stack Underflow!\n");
    else
    {
        printf("Popped from Stack 1: %d\n", stack[top2]);
        top2++;
    }
}

void display1()
{
    if (top1 == -1)
        printf("Stack Underflow!\n");
    else
    {
        printf("Stack: ");
        for (int i = top1; i >= 0; i--)
            printf("\n%d", stack[i]);
    }
}

void display2()
{
    if (top2 == SIZE)
        printf("Stack Underflow!\n");
    else
    {
        printf("Stack 2: ");
        for (int i = top2; i < SIZE; i++)
            printf("\n%d", stack[i]);
    }
}

int main()
{
    int ch, val;
    do
    {
        printf("\n-----Stack Menu-----\n");
        printf("1.Push1\n");
        printf("2.Push2\n");
        printf("3.Pop1\n");
        printf("4.Pop2\n");
        printf("5.Display1\n");
        printf("6.Display2\n");
        printf("7.Exit\n");
        printf("---------------------\n");
        printf("Enter your Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value to push in Stack 1: ");
            scanf("%d", &val);
            push1(val);
            break;

        case 2:
            printf("Enter the value to push in Stack 2: ");
            scanf("%d", &val);
            push2(val);
            break;

        case 3:
            pop1();
            break;

        case 4:
            pop2();
            break;

        case 5:
            display1();
            break;

        case 6:
            display2();
            break;
        case 7:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice! Try Again\n");
            break;
        }
    } while (ch != 7);
}
