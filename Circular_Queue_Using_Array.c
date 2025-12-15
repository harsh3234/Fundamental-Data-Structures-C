#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (front == (rear + 1) % SIZE)
    {
        printf("Queue Overflow!...\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = val;
        printf("Enqueued: %d\n", val);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow (Empty)\n");
    }
    else
    {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        int i = front;
        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        printf("\n");
    }
}

int main()
{
    int choice, val;
    do
    {
        printf("\n====== Circular Queue Menu ======\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
