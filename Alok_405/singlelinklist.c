#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n);
void insertNode(struct Node **head, int data, int position);
void deleteNode(struct Node **head, int key);
void traverseList(struct Node *head);

int main() {
    struct Node *head = NULL;
    int n, choice, data, position, key;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    head = createList(n);

    do {
        printf("\n1. Insert  2. Delete  3. Traverse  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertNode(&head, data, position);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;

            case 3:
                traverseList(head);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Enter a number between 1 and 4.\n");
        }

    } while (choice != 4);

    return 0;
}

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (!head) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

void insertNode(struct Node **head, int data, int position) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Node with data %d inserted at position %d.\n", data, position);
}

void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head, *prev = NULL;

    if (temp && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with data %d deleted.\n", key);
        return;
    }

    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

void traverseList(struct Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
