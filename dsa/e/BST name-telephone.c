#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[15];
    struct Node *left, *right;
};

struct Node* createNode(const char* name, const char* phone) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

struct Node* insertNode(struct Node* root, const char* name, const char* phone) {
    if (!root) return createNode(name, phone);

    int cmp = strcmp(name, root->name);
    if (cmp < 0) root->left = insertNode(root->left, name, phone);
    else if (cmp > 0) root->right = insertNode(root->right, name, phone);

    return root;
}

struct Node* searchNode(struct Node* root, const char* name) {
    while (root && strcmp(name, root->name) != 0) {
        if (strcmp(name, root->name) < 0) root = root->left;
        else root = root->right;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, const char* name) {
    if (!root) return root;

    int cmp = strcmp(name, root->name);
    if (cmp < 0) root->left = deleteNode(root->left, name);
    else if (cmp > 0) root->right = deleteNode(root->right, name);
    else {
        if (!root->left) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;
        while (temp->left) temp = temp->left;
        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

void printInOrder(struct Node* root) {
    if (root) {
        printInOrder(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        printInOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50], phone[15];

    do {
        printf("\nMenu:\n1. Search\n2. Insert\n3. Delete\n4. Print\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name to search: ");
                scanf("%s", name);
                if (searchNode(root, name)) printf("Found\n");
                else printf("Not Found\n");
                break;

            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                root = insertNode(root, name, phone);
                break;

            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                break;

            case 4:
                printInOrder(root);
                break;

            case 5:
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}
