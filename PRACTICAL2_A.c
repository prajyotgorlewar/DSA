#include <stdio.h>
#include <string.h>

struct STACK
{
    char S[100];
    int top;
};

void push(struct STACK *s1, char element)
{
    if (s1->top == 100 - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s1->top++;
        s1->S[s1->top] = element;
        printf("%c pushed\n", element);
    }
}

char pop(struct STACK *s1)
{
    if (s1->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        char ele = s1->S[s1->top];
        s1->top--;
        return ele;
    }
}

int peek(struct STACK s1)
{
    if (s1.top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    else
    {
        return s1.S[s1.top];
    }
}

int isEmpty(struct STACK s1)
{
    return s1.top == -1;
}

int size(struct STACK s1)
{
    return s1.top + 1;
}

int main()
{
    struct STACK s1;
    s1.top = -1;
    int CHSE;
    while (1)
    {
        printf("Enter '1' to PUSH, '2' to POP, '3' to PEEK, '4' for isEmpty, and '5' for size: ");
        scanf("%d", &CHSE);

        if (CHSE == 1)
        {
            char a;
            printf("Enter character to push: ");
            scanf(" %c", &a); // Use %c to read a single character
            push(&s1, a);
        }
        else if (CHSE == 2)
        {
            char result = pop(&s1);
            if (result != -1)
                printf("%c popped\n", result);
        }
        else if (CHSE == 3)
        {
            int result = peek(s1);
            if (result != -1)
                printf("Peek element is : %c\n", result);
        }
        else if (CHSE == 4)
        {
            if (isEmpty(s1))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
        }
        else if (CHSE == 5)
        {
            int stackSize = size(s1);
            printf("Stack size is %d\n", stackSize);
        }
    }
    return 0;
}
