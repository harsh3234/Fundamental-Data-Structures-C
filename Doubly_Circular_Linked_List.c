#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *back;
    int data;
    struct Node *forward;
};

struct Node *head = NULL, *temp, *newNode, *next, *prev; // Declaring Pointers

void create()
{
    int val;
    char ch;

    printf("Enter the Value: ");
    scanf("%d", &val);

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = val;
    head->forward = NULL;
    head->back = NULL;
    temp = head;

    head->forward = head;
    head->back = head;

    printf("Do you want to Continue: ");
    scanf(" %c", &ch);

    while (ch == 'Y' || ch == 'y')
    {
        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->forward = NULL;
        newNode->back = NULL;

        newNode->forward = head;
        newNode->back = temp;
        temp->forward = newNode;
        head->back = newNode;

        temp = newNode;

        printf("Do you want to Continue: ");
        scnaf(" %c", &ch);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else
    {
    }
}

void insert_first()
{
    int val;

    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else
    {
        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;

        printf("%d Inserterd.\n", val);

        temp = head->back;

        newNode->forward = head;
        newNode->back = temp;
        temp->forward = newNode;
        head->back = newNode;
        head = newNode;
    }
}

void insert_middle()
{
    int val;
    int i = 1;
    int pos;

    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else if (head->forward == head && head->back == head)
    {
        printf("There is only One Node Present.\n");
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", pos);

        if (pos == 1)
        {
            insert_first();
        }
        else
        {
            printf("Enter the Value: ");
            scanf("%d", &val);

            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = val;
            newNode->forward = NULL;
            newNode->back = NULL;

            next = head;

            while (i < pos)
            {
                prev = next;
                next = next->forward;
                i++;
            }
            prev->forward = newNode;
            next->back = newNode;
            newNode->forward = next;
            newNode->back = prev;
            printf("%d is Inserted.\n", val);
        }
    }
}

void insert_last()
{
    int val;

    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else
    {
        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;

        printf("%d Inserterd.\n", val);

        temp = head->back;

        temp->forward = newNode;
        newNode->back = temp;
        newNode->forward = head;
        head->back = newNode;
    }
}

void delete_first()
{
    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else
    {
    }
}

void count()
{
    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else
    {
    }
}

void search()
{
    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else
    {
    }
}

void delete_middle()
{
    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else
    {
    }
}

void delete_last()
{
    if (head == NULL)
    {
        printf("List Not Found or Created.\n");
    }
    else
    {
    }
}

// Main Menu
int main()
{
    int choice;
    do
    {
        printf("\n-----Doubly Circular Linked List-----\n");
        printf("1. Create\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at middle\n");
        printf("4. Insert at end\n");
        printf("5. Delete first\n");
        printf("6. Delete middle\n");
        printf("7. Delete end\n");
        printf("8. Display\n");
        printf("9. Reverse Display\n");
        printf("10. Count\n");
        printf("11. Search\n");
        printf("12. Exit\n");
        printf("---------------------------\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_first();
            break;
        case 3:
            insert_middle();
            break;
        case 4:
            insert_last();
            break;
        case 5:
            delete_first();
            break;
        case 6:
            delete_middle();
            break;
        case 7:
            delete_last();
            break;
        case 8:
            display();
            break;
        case 9:
            rev_display();
            break;
        case 10:
            count();
            break;
        case 11:
            search();
            break;
        case 12:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 12);

    return 0;
}