#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *ladd;
    int data;
    struct Node *radd;
};

struct Node *root = NULL, *new1;

void create(struct Node *r, struct Node *new1)
{
    if (new1->data == r->data)
        printf("Duplicate Value Not Allowed...\n");

    if (new1->data < r->data)
    {
        if (r->ladd == NULL)
            r->ladd = new1;
        else
            create(r->ladd, new1);
    }

    else if (new1->data > r->data)
    {
        if (r->radd == NULL)
            r->radd = new1;
        else
            create(r->radd, new1);
    }
}

void inorder(struct Node *r)
{
    if (r != NULL)
    {
        inorder(r->ladd);
        printf("%d ", r->data);
        inorder(r->radd);
    }
}

void preorder(struct Node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preorder(r->ladd);
        preorder(r->radd);
    }
}

void postorder(struct Node *r)
{
    if (r != NULL)
    {
        postorder(r->ladd);
        postorder(r->radd);
        printf("%d ", r->data);
    }
}

void search(struct Node *pt, int s)
{
    if (pt == NULL)
    {
        printf("Element Not Found\n");
    }
    else
    {
        if (s < pt->data)
            search(pt->ladd, s);
        if (s > pt->data)
            search(pt->radd, s);
        if (s == pt->data)
            printf("Found!\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--------Tree Menu--------\n");
        printf("1. Create\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7.Exit\n");
        printf("---------------------------\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int val;
            int ch;
            do
            {

                printf("Enter Value: ");
                scanf("%d", &val);
                new1 = (struct Node *)malloc(sizeof(struct Node));
                new1->data = val;
                new1->ladd = new1->radd = NULL;
                if (root == NULL)
                    root = new1;
                else
                    create(root, new1);
                printf("Do you want to continue: ");
                getchar();
                ch = getchar();
            } while (ch == 'Y' || ch == 'y');
            break;
        }

        case 2:
            inorder(root);
            break;

        case 3:
            preorder(root);
            break;

        case 4:
            postorder(root);
            break;

        case 5:
        {
            int s;
            printf("Enter the value to Search: ");
            scanf("%d", &s);
            search(root, s);
            break;
        }

        case 6:
            inorder(root);
            break;

        case 7:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
            break;
        }

    } while (choice != 7);
    return 0;
}
