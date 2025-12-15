#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *add;
};

struct Node *front = NULL, *rear = NULL, *temp, *newNode;

void enqueue()
{
    int val;

    printf("Enter the Value: ");
    scanf("%d", &val);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->add = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->add = newNode;
        rear = newNode;
        rear->add = front;
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else if (front == rear)
    {
        printf("Dequeued: %d\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        printf("Dequeued: %d\n", front->data);
        front = front->add;
        free(temp);
        rear->add = front;
    }
}

void display()
{
    if (front == NULL && rear == NULL)
        printf("Queue is Empty!\n");
    else
    {
        printf("Queue: ");
        temp = front;
        do
        {
            printf("%d->", temp->data);
            temp = temp->add;
        } while (temp != front);

        printf("Back to Front\n");
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
        printf("3.Display\n");
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
