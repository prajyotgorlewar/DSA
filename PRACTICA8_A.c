#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* adjacency_list[MAX_VERTICES];
};

struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_VERTICES; ++i)
        graph->adjacency_list[i] = NULL;
    return graph;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void enqueue(struct Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->array[++queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front++;

    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;

    return item;
}

void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;
}

void bfs(struct Graph* graph, int start) {
    struct Queue* queue = createQueue(MAX_VERTICES);
    int visited[MAX_VERTICES] = {0};

    printf("BFS Traversal: ");

    enqueue(queue, start);
    visited[start] = 1;

    while (queue->front != -1) {
        int vertex = dequeue(queue);
        printf("%d ", vertex);

        struct Node* temp = graph->adjacency_list[vertex];
        while (temp) {
            if (!visited[temp->data]) {
                enqueue(queue, temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

void dfsUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjacency_list[vertex];
    while (temp) {
        if (!visited[temp->data])
            dfsUtil(graph, temp->data, visited);
        temp = temp->next;
    }
}

void dfs(struct Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0};

    printf("DFS Traversal: ");
    dfsUtil(graph, start, visited);
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph();

    // Example graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    int choice, start_vertex;

    do {
        printf("\nMenu:\n");
        printf("1. Traverse using BFS\n");
        printf("2. Traverse using DFS\n");
        printf("3. Exit\n");

        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the start vertex for BFS traversal: ");
                scanf("%d", &start_vertex);
                bfs(graph, start_vertex);
                break;
            case 2:
                printf("Enter the start vertex for DFS traversal: ");
                scanf("%d", &start_vertex);
                dfs(graph, start_vertex);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

