#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int* items;
    int front;
    int rear;
    int maxSize;
};

struct Deque* createDeque(int size) {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->items = (int*)malloc(size * sizeof(int));
    dq->front = -1;
    dq->rear = -1;
    dq->maxSize = size;
    return dq;
}

int isFull(struct Deque* dq) {
    return ((dq->front == 0 && dq->rear == dq->maxSize - 1) || 
            (dq->front == dq->rear + 1));
}

int isEmpty(struct Deque* dq) {
    return (dq->front == -1);
}

void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->items[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % dq->maxSize;
    }
    printf("\n");
}

void enqueueFront(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Cannot enqueue at front, deque overflow\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = dq->maxSize - 1;
    } else {
        dq->front--;
    }

    dq->items[dq->front] = value;
    printf("Enqueued %d at front\n", value);
    display(dq);
}

void enqueueRear(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Cannot enqueue at rear, deque overflow\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == dq->maxSize - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->items[dq->rear] = value;
    printf("Enqueued %d at rear\n", value);
    display(dq);
}

int dequeueFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Cannot dequeue from front, deque underflow\n");
        return -1;
    }

    int item = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == dq->maxSize - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }

    printf("Dequeued %d from front\n", item);
    display(dq);
    return item;
}

int dequeueRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Cannot dequeue from rear, deque underflow\n");
        return -1;
    }

    int item = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = dq->maxSize - 1;
    } else {
        dq->rear--;
    }

    printf("Dequeued %d from rear\n", item);
    display(dq);
    return item;
}

void menu() {
    printf("\nSelect an option from below\n");
    printf("1. Enqueue at front\n");
    printf("2. Enqueue at rear\n");
    printf("3. Dequeue from front\n");
    printf("4. Dequeue from rear\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int dequeSize;
    printf("Enter the maximum size of the deque: ");
    scanf("%d", &dequeSize);
    struct Deque* dq = createDeque(dequeSize);

    int choice, value;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at front: ");
                scanf("%d", &value);
                enqueueFront(dq, value);
                break;
            case 2:
                printf("Enter value to enqueue at rear: ");
                scanf("%d", &value);
                enqueueRear(dq, value);
                break;
            case 3:
                dequeueFront(dq);
                break;
            case 4:
                dequeueRear(dq);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}