#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *addr;
};

struct Node *front = NULL, *rear = NULL, *newNode, *temp;

void enqueue()
{
    int val;
    printf("Enter the element: ");
    scanf("%d", &val);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->addr = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->addr = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", val);
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Dequeued: %d\n", front->data);
        temp = front;
        front = temp->addr;
        free(temp);

        if (front == NULL)
        {
            rear = NULL;
        }
    }
}

void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue: ");
        temp = front;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->addr;
        }
        printf("NULL\n");
    }
}

int main()
{
    int ch;
    do
    {
        printf("\n---------------------\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Dispaly\n");
        printf("4.Exit\n");
        printf("---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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