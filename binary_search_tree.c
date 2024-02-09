#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *getnode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int value) {
    if (root == NULL) {
        return getnode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
        printf("inserted left of %d\n", root->data);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
        printf("inserted right of %d\n", root->data);
    }
    return root;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            printf("%d is deleted\n", root->data);
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            printf("%d is deleted\n", root->data);
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void create() {
    char ch;
    int value;
    do {
        printf("Enter data: ");
        scanf("%d", &value);

        if (root == NULL) {
            root = insert(root, value);
            printf("Root created\n");
        }
        else {
            insert(root, value);
        }
        printf("Choose (y/Y) to enter more data: ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postOrderTraversal(struct node *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct node *search(struct node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

void display() {
    int ch;
    while (1) {
        system("cls");
        printf("1. Preorder\n2. Postorder\n3. Inorder\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            preorderTraversal(root);
            break;
        case 2:
            postOrderTraversal(root);
            break;
        case 3:
            inorderTraversal(root);
            break;
        default:
            printf("Any other to return\n");
            return;
        }
        getch();
    }
}

void insertNew() {
    int value;
    printf("Enter value to be inserted: ");
    scanf("%d", &value);
    insert(root, value);
}

void deleteNodeUI() {
    int value;
    printf("Enter value to be deleted: ");
    scanf("%d", &value);
    root = deleteNode(root, value);
}

void searchValue() {
    int value;
    printf("Enter value to be searched: ");
    scanf("%d", &value);
    struct node *result = search(root, value);
    if (result != NULL) {
        printf("%d found in the tree\n", value);
    }
    else {
        printf("%d not found in the tree\n", value);
    }
}

int main() {
    int choice;
    create();

    while (1) {
        system("cls");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insertNew();
            break;
        case 2:
            deleteNodeUI();
            break;
        case 3:
            searchValue();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
        getch();
    }

    return 0;
}
