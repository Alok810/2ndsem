#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int front, rear;
    int arr[MAX];
};

void initializeQueue(struct Queue *q);
int isFull(struct Queue *q);
int isEmpty(struct Queue *q);
void enqueue(struct Queue *q, int val);
void dequeue(struct Queue *q);
void traverse(struct Queue *q);

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, value;

    do {
        printf("\n*** Queue Menu ***\n");
        printf("1. Enqueue (Push)\n");
        printf("2. Dequeue (Pop)\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2:
                dequeue(&queue);
                break;

            case 3:
                traverse(&queue);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }

    } while (choice != 4);

    return 0;
}

void initializeQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = val;
        printf("Enqueued: %d\n", val);
    }
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        int removed = q->arr[q->front];
        q->front++;
        printf("Dequeued: %d\n", removed);
    }
}

void traverse(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to traverse.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}