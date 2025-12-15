#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

// Push function
void push(int);
void push(int val)
{
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
    {
        ++top;
        stack[top] = val;
        printf("Pushed: %d\n", val);
    }
}

// Pop function
void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("Popped: %d\n", stack[top]);
        top--;
    }
}

// Display function
void display()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack (top to bottom):\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice, val;

    do
    {
        printf("\n----- Stack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
