#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *add;
};

struct Node *top = NULL, *temp, *newNode;

void push()
{
    int val;
    printf("Enter the Value: ");
    scanf("%d", &val);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->add = NULL;
    newNode->add = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
        printf("Stack is empty!\n");
    else
    {
        printf("Popped: %d\n", top->data);
        temp = top;
        top = temp->add;
        free(temp);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->add;
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n---------------------\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Dispaly\n");
        printf("4.Exit\n");
        printf("---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
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
            printf("Invalid! Try Again!\n");
            break;
        }
    } while (ch != 4);

    return 0;
}