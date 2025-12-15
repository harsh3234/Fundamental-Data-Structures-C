#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        ++rear;
        queue[rear] = val;
        printf("Enqueued: %d\n", val);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Dequeued: %d\n", queue[front]);
        ++front;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n ", queue[i]);
        }
    }
}

int main()
{
    int choice, val;
    do
    {
        printf("\n----- Menu ------ \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
