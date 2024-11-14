#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode()
{
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    Node *newNode = createNode(data);

    printf("Enter left child of %d:\n", data);
    newNode->left = insertNode();

    printf("Enter right child of %d:\n", data);
    newNode->right = insertNode();

    return newNode;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    Node *root = NULL;

    printf("Create the binary tree:\n");
    root = insertNode();

    int choice;

    do
    {
        printf("\nChoose traversal method:\n");
        printf("1. Preorder Traversal\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        switch (choice)
        {
        case 1:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 2:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    freeTree(root);
    return 0;
}
