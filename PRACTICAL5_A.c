#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *Head = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
}

void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        struct Node *current = Head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

struct Node *findNode(struct Node *start, int data)
{
    struct Node *current = start;
    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

void insertBetween(int prevnode, int data)
{
    struct Node *new_node, *temp, *previous;
    int index = 0;
    temp = Head;
    if(Head == NULL)
    {
        printf("Create head node first\n");
    }
    else
    {
        while (temp->next != NULL && index != prevnode)
        {
            previous = temp;
            temp = temp->next;
            index++;
        }
        
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
       
        new_node->prev = previous;
        previous->next = new_node;
       
        new_node->next = temp;
        temp->prev = new_node;
    }
}

void deleteBetween(int position)
{
    if (Head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    if (position == 1)
    {
        struct Node* temp = Head;
        Head = Head->next;
        free(temp);
        printf("Element deleted from position %d!\n", position);
        return;
    }
    
    struct Node *temp = Head, *previous = NULL;
    int count = 1;
    while (temp != NULL && count < position)
    {
        previous = temp;
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL)
    {
        printf("Position %d not found\n", position);
    }
    else
    {
        previous->next = temp->next;
        temp->next->prev = previous;
        
        free(temp);
        printf("Element deleted from position %d!\n", position);
    }
}

void deleteAtBeginning()
{
    if (Head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = Head;
    Head = Head->next;
    if (Head != NULL)
    {
        Head->prev = NULL;
    }
    free(temp);
}

void deleteAtEnd()
{
    if (Head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = Head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    if (current->prev != NULL)
    {
        current->prev->next = NULL;
    }
    else
    {
        Head = NULL;
    }
    free(current);
}

void displayList()
{
    struct Node *current = Head;
    printf("Doubly Linked List: ");
    printf("NULL");
    while (current != NULL)
    {
        printf("<-[%d]->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int search(int element)
{
    struct Node *temp = Head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

void length()
{
    struct Node *temp = Head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    printf("Length of the Doubly Linked list is : %d", len);
}

int main()
{
    int choice, data, position, element,prevnode;

    while (1)
    {
        printf("\nDoubly Linked List:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at the position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at the position\n");
        printf("7. Display list\n");
        printf("8. Search a element\n");
        printf("9. Display length of the List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;

        case 2:
            printf("Enter element: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter the index of the previous node: ");
            scanf("%d", &prevnode);
            insertBetween(prevnode, data);
            break;

        case 4:
            deleteAtBeginning();
            break;

        case 5:
            deleteAtEnd();
            break;

        case 6:
            printf("Enter the position of the node: ");
            scanf("%d", &position);
            deleteBetween(position);
            break;

        case 7:
            displayList();
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
            length();
            break;

        case 0:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
