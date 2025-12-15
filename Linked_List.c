#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *add;
};

struct Node *start = NULL, *newNode, *temp, *next, *prev, *arr[100];

void create()
{
    int val;
    char ch;

    printf("Enter the Value: ");
    scanf("%d", &val);
    start = (struct Node *)malloc(sizeof(struct Node));
    start->data = val;
    start->add = NULL;
    temp = start;

    printf("Do you want to continue: ");
    scanf("%d", &ch);
    ch = getchar();

    while (ch == 'Y' || ch == 'y')
    {
        printf("Enter the Value: ");
        scanf("%d", &val);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->add = NULL;
        temp->add = newNode;
        temp = temp->add;

        printf("Do you want to continue: ");
        scanf("%d", &ch);
        ch = getchar();
    }
}

void insert_first()
{
    int val;

    if (start == NULL)
        printf("List not found!\n");
    else
    {
        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->add = NULL;
        newNode->add = start;
        start = newNode;
    }
}

void insert_middle()
{
    int val;
    int pos;
    int i = 1;

    if (start == NULL)
        printf("List not found!\n");
    else
    {
        printf("Enter the positon where you want to insert: ");
        scanf("%d", &pos);

        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->add = NULL;
        next = start;

        while (i < pos)
        {
            prev = next;
            next = next->add;
            i++;
        }
        prev->add = newNode;
        newNode->add = next;
    }
}

void insert_end()
{
    int val;

    if (start == NULL)
        printf("List not found!\n");
    else
    {
        printf("Enter the Value: ");
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->add = NULL;

        temp = start;
        while (temp->add != NULL)
        {
            temp = temp->add;
        }
        temp->add = newNode;
    }
}

void delete_first()
{
    if (start == NULL)
        printf("List not found!\n");
    else
    {
        temp = start;
        start = temp->add;
        free(temp);
    }
}

void delete_middle()
{
    int pos;
    int i = 1;

    if (start == NULL)
        printf("List not found!\n");
    else
    {
        printf("Enter the position you want to delete: ");
        scanf("%d", &pos);
        next = start;
        while (i < pos)
        {
            prev = next;
            next = next->add;
            i++;
        }
        temp = next->add;
        prev->add = temp;
        free(next);
    }
}

void delete_end()
{
    if (start == NULL)
        printf("List not found!\n");
    else
    {
        temp = start;
        while (temp->add != NULL)
        {
            prev = temp;
            temp = temp->add;
        }
        prev->add = NULL;
        free(temp);
    }
}

void count()
{
    int count = 0;
    if (start == NULL)
        printf("List not found!\n");
    else
    {
        temp = start;
        while (temp != NULL)
        {
            count++;
            temp = temp->add;
        }
        printf("%d Nodes are present.\n", count);
    }
}

void search()
{
    int s;
    int f = 0;
    int count = 0;
    if (start == NULL)
        printf("List not found!\n");
    else
    {
        printf("Enter the elemnt you want to seach: ");
        scanf("%d", &s);
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                f = 1;
                count++;
            }
            temp = temp->add;
        }
        if (f == 1)
        {
            printf("%d is present in the list.\n", s);
            printf("%d times present in the list\n", count);
        }
        else
        {
            printf("%d not found in the list.\n", s);
        }
    }
}

void sort()
{
    int t;
    if (start == NULL)
        printf("List is not Found\n");
    else
    {
        prev = start;
        while (prev != NULL)
        {
            next = prev->add;
            while (next != NULL)
            {
                if (next->data < prev->data)
                {
                    t = next->data;
                    next->data = prev->data;
                    prev->data = t;
                }
                next = next->add;
            }
            prev = prev->add;
        }

        temp = start;

        printf("List: ");

        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->add;
        }
        printf("NULL\n");
    }
}

void rev_display()
{
    int i = 0;
    if (start == NULL)
        printf("List not found!\n");
    else
    {
        temp = start;
        while (temp != NULL)
        {
            arr[i] = temp;
            i++;
            temp = temp->add;
        }
        i--;

        printf("List: ");
        while (i >= 0)
        {
            printf("%d->", arr[i]->data);
            i--;
        }
        printf("NULL\n");
    }
}

void display()
{
    char val;
    if (start == NULL)
    {
        printf("List not found!\n");
    }
    else
    {
        printf("Display Options:\n");
        printf("For Original Order(O): \n");
        printf("For Ascending order(A): \n");
        printf("For Decending order(D) :\n");
        scanf("%d", &val);

        if (val == 'O' || val == 'o')
        {

            temp = start;

            printf("List: ");

            while (temp != NULL)
            {
                printf("%d->", temp->data);
                temp = temp->add;
            }
            printf("NULL\n");
        }

        else if (val == 'A' || val == 'a')
        {
            sort();
        }
        else if (val == 'D' || val == 'd')
        {
            rev_display();
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n-----------------------\n");
        printf("1.Create\n");
        printf("2.Insert at beginning\n");
        printf("3.Insert at middle\n");
        printf("4.Insert at last\n");
        printf("5.Delete first\n");
        printf("6.Delete middle\n");
        printf("7.Delete end\n");
        printf("8.Display\n");
        printf("9.Count\n");
        printf("10.Search\n");
        printf("11.Sort\n");
        printf("12.Reverse Display\n");
        printf("13.Exit\n");
        printf("---------------------\n");
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
            sort();
            break;
        case 12:
            rev_display();
            break;
        case 13:
            printf("Exiting program...\n");
            break;
        }
    } while (choice != 13);
    return 0;
}
