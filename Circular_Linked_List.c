#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head = NULL, *newNode, *temp, *next, *prev;

void create()
{
    int val;
    char ch;

    printf("Enter the Value: ");
    scanf("%d", &val);

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = val;
    head->link = NULL;
    temp = head;
    head->link = head;

    printf("Do you want to continue: ");
    scanf(" %c", &ch);

    while (ch == 'Y' || ch == 'y')
    {
        printf("Enter the value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->link = NULL;
        temp->link = newNode;
        newNode->link = head;
        temp = newNode;

        printf("Do you want to continue: ");
        scanf(" %c", &ch);
    }
}

void insert_first()
{
    int val;

    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->link = NULL;

        temp = head;

        do
        {
            temp = temp->link;
        } while (temp->link != head);

        temp->link = newNode;
        newNode->link = head;
        head = newNode;
    }
    printf("%d is Inserted.\n", val);
}

void insert_middle()
{
    int val;
    int pos;
    int i = 1;

    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else
    {

        printf("Enter the value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->link = NULL;

        printf("Enter the postion: ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            insert_first();
        }
        else
        {

            next = head;

            while (i < pos)
            {
                prev = next;
                next = next->link;
                i++;
            }
            prev->link = newNode;
            newNode->link = next;
        }
        printf("%d is Inserted.\n", val);
    }
}

void insert_end()
{
    int val;

    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->link = NULL;

        temp = head;

        do
        {
            temp = temp->link;
        } while (temp->link != head);

        temp->link = newNode;
        newNode->link = head;
    }
    printf("%d is Inserted.\n", val);
}

void delete_first()
{
    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else if (head->link == head)
    {
        printf("%d Removed.\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        printf("%d Removed.\n", temp->data);

        do
        {
            temp = temp->link;
        } while (temp->link != head);

        temp->link = head->link;

        temp = head;
        head = head->link;
        free(temp);
    }
}

void delete_middle()
{
    int i = 1;
    int pos;

    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else
    {
        printf("Enter the postion: ");
        scanf("%d", &pos);

        next = head;
        while (i < pos)
        {
            prev = next;
            next = next->link;
            i++;
        }
        prev->link = next->link;

        printf("%d Removed.\n ", next->data);

        free(next);
    }
}

void delete_end()
{
    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else
    {
        next = head;
        while (next->link != head)
        {
            temp = next;
            next = next->link;
        }
        temp->link = head;
        printf("%d Removed.\n", next->data);
        free(next);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else
    {
        printf("Linked List: \n");

        temp = head;

        do
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        } while (temp != head);
    }
}

// this better version
// void display()
// {
//     if (head == NULL)
//     {
//         printf("List not found or created.\n");
//     }
//     else
//     {
//         printf("Linked List: \n");

//         temp = head;

//         do
//         {
//             printf("%d->", temp->data);
//             temp = temp->link;
//         } while (temp->link != head);
//     }
//     printf("%d", temp->data);
// }

void count()
{
    int count = 0;
    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else
    {
        temp = head;

        do
        {
            count++;
            temp = temp->link;
        } while (temp != head);

        printf("%d Elements are Present.\n", count);
    }
}

void search()
{
    int search;
    int i = 0;
    if (head == NULL)
    {
        printf("List not found or created.\n");
    }
    else
    {

        printf("Enter the value you want to Search: ");
        scanf("%d", &search);

        temp = head;

        do
        {
            if (temp->data == search)
            {
                i = 1;
                break;
            }
            temp = temp->link;
        } while (temp != head);

        if (i == 1)
        {
            printf("%d Found.\n", search);
        }
        else
        {
            printf("%d Not Found.\n", search);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n-----------------------\n");
        printf("1. Create\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at middle\n");
        printf("4. Insert at end\n");
        printf("5. Delete first\n");
        printf("6. Delete middle\n");
        printf("7. Delete end\n");
        printf("8. Display\n");
        printf("9. Count\n");
        printf("10. Search\n");
        printf("11. Exit\n");
        printf("-----------------------\n");
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
            insert_end();
            break;
        case 5:
            delete_first();
            break;
        case 6:
            delete_middle();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            display();
            break;
        case 9:
            count();
            break;
        case 10:
            search();
            break;
        case 11:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while (choice != 11);

    return 0;
}
