#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertNode(struct Node* head, int data, int position);
struct Node* deleteNode(struct Node* head, int data);
void traverseList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\n*** Doubly Linked List Menu ***\n");
        printf("1. Create Node\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Traverse List\n");
        printf("5. Exit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                head = createNode(data);
                break;

            case 2:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                printf("Enter the position to insert the node: ");
                scanf("%d", &position);
                head = insertNode(head, data, position);
                break;

            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;

            case 4:
                traverseList(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    printf("Node created successfully!\n");
    return newNode;
}

// Function to insert a new node at a given position
struct Node* insertNode(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        printf("Node inserted successfully!\n");
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position to insert!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    printf("Node inserted successfully!\n");
    return head;
}

// Function to delete a node with a given data
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found!\n", data);
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with data %d deleted successfully!\n", data);
    return head;
}

// Function to traverse and print the doubly linked list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("Doubly Linked List is empty!\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
