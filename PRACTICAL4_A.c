#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *Next;
};
struct node* Head;

void create()
{
    if (Head == NULL)
    {
        printf("Enter Element for Head node: ");
        Head = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &Head->data); 
        Head->Next = NULL;
        printf("Head Created!\n");
    }
    else
    {
        printf("List Exists\n");
    }
}

void insert_end(int element)
{
    struct node *temp, *temp1;
    temp1 = Head;

    if(Head == NULL)
    {
        printf("Call create function\n");
    }
    else
    {
        while (temp1->Next != NULL)
        {
            temp1 = temp1->Next;
        }
    
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = element;
        temp->Next = NULL;
        temp1->Next = temp;
        printf("Element inserted at the end!\n");
    }
}

void insert_begin(int element)
{
    printf("Element inserting at the beginning!\n");
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = element;
    t->Next = Head;
    Head = t;
}

void insert_between(int element, int position)
{
    struct node *temp, *prev, *newnode;
    int count = 1;
    temp = Head;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    
    while (temp != NULL && count < position)
    {
        prev = temp;
        temp = temp->Next;
        count++;
    }

    printf("Element inserted in between!\n");
    prev->Next = newnode;
    newnode->Next = temp;
}

void delete_begin()
{
    if (Head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    struct node* temp = Head;
    Head = Head->Next;
    free(temp);
    printf("Element deleted from the beginning!\n");
}

void delete_end()
{
    if (Head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    if (Head->Next == NULL)
    {
        free(Head);
        Head = NULL;
        printf("Element deleted from the end!\n");
        return;
    }
    
    struct node* temp = Head;
    while (temp->Next->Next != NULL)
    {
        temp = temp->Next;
    }
    
    free(temp->Next);
    temp->Next = NULL;
    printf("Element deleted from the end!\n");
}

void delete_at_position(int position)
{
    if (Head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    if (position == 1)
    {
        struct node* temp = Head;
        Head = Head->Next;
        free(temp);
        printf("Element deleted from position %d!\n", position);
        return;
    }
    
    struct node *temp = Head, *prev = NULL;
    int count = 1;
    while (temp != NULL && count < position)
    {
        prev = temp;
        temp = temp->Next;
        count++;
    }
    
    if (temp == NULL)
    {
        printf("Position %d not found\n", position);
    }
    else
    {
        prev->Next = temp->Next;
        free(temp);
        printf("Element deleted from position %d!\n", position);
    }
}

int search(int element)
{
    struct node* temp = Head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            return position;
        }
        temp = temp->Next;
        position++;
    }
    return -1;
}

int length()
{
    int len = 0;
    struct node* temp = Head;
    while (temp != NULL)
    {
        len++;
        temp = temp->Next;
    }
    return len;
}

void traverse()
{
    struct node* t = Head;
    while (t != NULL)
    {
        printf("Data=%d\n", t->data);
        t = t->Next;
    }
}

int main()
{
    int element, position, choice;
    int stopper = 0;
    printf("LINKED LIST\n");
    while (stopper == 0)
    {
        printf("Choose\n '1' to Create Head\n '2' to add in Begin\n '3' to add in end\n '4' to add in between\n '5' to delete from beginning\n '6' to delete from end\n '7' to delete at position\n '8' to search\n '9' to get length\n '10' to traverse\n '11' to return\n ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                printf("Enter element to add at the beginning: ");
                scanf("%d", &element);
                insert_begin(element);
                break;

            case 3:
                printf("Enter element to add at the end: ");
                scanf("%d", &element);
                insert_end(element);
                break;

            case 4:
                printf("Enter element to add in between: ");
                scanf("%d", &element);
                printf("Enter Position: ");
                scanf("%d", &position);
                insert_between(element, position);
                break;

            case 5:
                delete_begin();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                printf("Enter Position to delete: ");
                scanf("%d", &position);
                delete_at_position(position);
                break;

            case 8:
                printf("Enter Element to search: ");
                scanf("%d", &element);
                int pos = search(element);
                if (pos != -1)
                    printf("Element found at position %d\n", pos);
                else
                    printf("Element not found\n");
                break;

            case 9:
                printf("Length of the list: %d\n", length());
                break;

            case 10:
                printf("Traversing Elements\n");
                traverse();
                break;

            case 11:
                stopper = 1;
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

