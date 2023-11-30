#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
}Node;

Node *create_root(int valueAtRoot){
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    temp->data = valueAtRoot;
    return temp;
}


Node *insert(Node *node, int valueToInsert) {
    if (node == NULL) {
        return create_root(valueToInsert);    
    }

    if (valueToInsert < node->data) {
        node->left = insert(node->left, valueToInsert);
    }
    else {
        node->right = insert(node->right, valueToInsert);
    }

    return node;
}

void inorder(Node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->data);

    // Traverse right
    inorder(root->right);
  }
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d -> ", root->data);
        preorder(root->left);
        preorder(root->right);
    }    
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ", root->data);
    }      
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int breakloop = 0, valueToInsert = 0;
    int reply;

    while (breakloop == 0)
    {
        printf("Enter value to insert: ");
        scanf("%d", &valueToInsert);
        root = insert(root, valueToInsert);
        printf("Continue(0 - yes/1 - no): ");
        scanf("%d", &reply);
        if (reply != 0)
        {
            breakloop = 1;
        }
    }
    
    printf("Tree (inorder): \n");
    inorder(root);
    printf("\nTree (preorder): \n");
    preorder(root);
    printf("\nTree (postorder): \n");
    postorder(root);
    return 0;
}