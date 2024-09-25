#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int* items;
    int front;
    int rear;
    int maxSize;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->items = (int*)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->maxSize = size;
    return q;
}

int isFull(struct Queue* q) {
    if ((q->rear + 1) % q->maxSize == q->front) {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void display(struct Queue* q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (i = q->front; i != q->rear; i = (i + 1) % 100) {
            printf("%d ", q->items[i]);
        }
        printf("%d\n", q->items[i]);
    }
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Cannot enqueue, queue overflow\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % 100;
        q->items[q->rear] = value;
        printf("Enqueued %d\n", value);
        display(q);
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Cannot dequeue, queue underflow\n");
        return -1;
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % 100;
        }
        printf("Dequeued %d\n", item);
        display(q);
        return item;
    }
}

void menu() {
    printf("\nSelect an option from below\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int queueSize;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &queueSize);
    struct Queue* q = createQueue(queueSize);
    int choice, value;
    printf("Enter an integer to begin: ");
    scanf("%d", &value);
    enqueue(q, value);

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}
