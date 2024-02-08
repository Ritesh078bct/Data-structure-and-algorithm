#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *root = NULL;

struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insert(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
        printf("inserted left of %d", root->data);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
        printf("inserted right of %d", root->data);
    }
    return root;
}
void create()
{
    char ch;
    int value;
    do
    {
        printf("enter data\n");
        scanf("%d", &value);

        if (root == NULL)
        {
            root = insert(root, value);
            printf("root created\n");
        }
        else
        {
            insert(root, value);
        }
        printf("choose (y/Y) enter more data\n");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{

    create();
    // Perform inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
