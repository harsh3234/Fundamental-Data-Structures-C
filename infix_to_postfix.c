#include <stdio.h>
#include <conio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

int priority(char *e)
{
    if (*e == '(')
        return 0;
    if (*e == '+' || *e == '-')
        return 1;
    if (*e == '*' || *e == '/')
        return 2;
    if (*e == '^')
        return 3;
    return -1;
}

int main()
{
    char exp[50], *e, x;

    printf("Enter the expresion: ");
    scanf("%s", exp);

    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c", *e);

        else if (*e == '(')
            push(*e);

        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (top != -1 && priority(&stack[top]) >= priority(e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}