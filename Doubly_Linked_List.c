#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *back;
    int data;
    struct Node *forward;
};

struct Node *head = NULL, *temp, *newNode, *next, *prev; // Declaring Pointers

// Createing first node or list
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

    printf("Do you want to continue: ");
    scanf(" %c", &ch); // Note: Space before %c is mandatory

    while (ch == 'Y' || ch == 'y')
    {
        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->forward = NULL;
        newNode->back = NULL;
        temp->forward = newNode;
        newNode->back = temp;
        temp = newNode;

        printf("Do you want to continue: ");
        scanf(" %c", &ch);
    }
}

// To View The List
void display()
{
    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else
    {
        printf("Linked List: \n");

        temp = head;
        do
        {
            printf("%d <-> ", temp->data);
            temp = temp->forward;
        } while (temp->forward != NULL);
        printf("%d\n", temp->data);
    }
}

void rev_display()
{
    if (head == NULL)
    {
        printf("List not Found or Created");
    }
    else
    {
        printf("Reverse Display: \n");

        temp = head;

        do
        {
            temp = temp->forward;
        } while (temp->forward != NULL);

        do
        {
            printf("%d <-> ", temp->data);
            temp = temp->back;
        } while (temp->back != NULL);
        printf("%d\n", temp->data);
    }
}

// Inserting Node before the firsted Created node
void insert_first()
{
    int val;

    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else
    {
        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->forward = NULL;
        newNode->back = NULL;

        newNode->forward = head;
        head->back = newNode;
        head = newNode;

        printf("%d is Inserted.\n", val);
    }
}

// Inserting somewhere in middle of the List
void insert_middle()
{
    int val;
    int i = 1;
    int pos;

    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else
    {
        display(); // Show The List To See The Postion Of The Node To Delete

        printf("Enter the position: ");
        scanf("%d", &pos);

        if (pos == 1) // If the user is fullish to choose first postion
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

// Inserting a Node at the end of List
void insert_end()
{
    int val;

    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else
    {
        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->forward = NULL;
        newNode->back = NULL;

        temp = head;

        do
        {
            temp = temp->forward;
        } while (temp->forward != NULL);

        temp->forward = newNode;
        newNode->back = temp;

        printf("%d is Inserted.\n", val);
    }
}

// Deleting the first Node
void delete_first()
{
    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else if (head->forward == NULL) // If the List has Only One Node
    {
        printf("%d Removed.\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {

        temp = head;
        head = temp->forward;
        head->back = NULL;
        printf("%d Removed.\n", temp->data);
        free(temp);
    }
}

// Deleting a specific Positioned Node
void delete_middle()
{
    int pos;
    int i = 1;

    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else
    {
        display(); // Show The List To See The Postion Of The Node To Delete

        printf("Enter the position: ");
        scanf("%d", &pos);

        if (pos == 1) // If the person is Fullish to choose middle option to delete first
        {
            temp = head;
            head = temp->forward;
            head->back = NULL;
            printf("%d Removed.\n", temp->data);
            free(temp);
        }
        else
        {
            next = head;

            while (i < pos)
            {
                prev = next;
                next = next->forward;
                i++;
            }
            temp = next->forward;
            temp->back = prev;
            prev->forward = temp;

            printf("%d Removed.\n", next->data);

            free(next);
        }
    }
}

// To delete the Last Node
void delete_end()
{
    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else if (head->forward == NULL) // If the List has Only One Node
    {
        free(head);
        head = NULL;
    }
    else
    {
        next = head;
        do
        {
            prev = next;
            next = next->forward;
        } while (next->forward != NULL);

        prev->forward = NULL;
        printf("%d Removed.\n", next->data);
        free(next);
    }
}

// To Count How Many Nodes Are Present
void count()
{
    int count = 0;
    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else
    {
        temp = head;
        do
        {
            count++;
            temp = temp->forward;
        } while (temp != NULL);

        printf("%d Elements Are Present.\n", count);
    }
}

// To Check Whether A Specific Node Is Present
void search()
{
    int find;
    int i = 0;
    if (head == NULL)
    {
        printf("List not Found or Created.\n");
    }
    else
    {
        printf("Enter the Value to search: ");
        scanf("%d", &find);

        temp = head;

        do
        {
            if (temp->data == find)
            {
                i = 1;
                break;
            }

            temp = temp->forward;
        } while (temp != NULL);

        if (i == 1)
        {
            printf("%d Found.\n", find);
        }
        else
        {
            printf("%d Not Found.\n", find);
        }
    }
}

// Main Menu
int main()
{
    int choice;
    do
    {
        printf("\n-----Doubly Linked List-----\n");
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