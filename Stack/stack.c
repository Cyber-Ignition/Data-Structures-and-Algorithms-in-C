#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to initialize the stack
void create_stack(Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element because stack is empty\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Cannot peek because stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// Function to display the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the stack implementation with a menu
int main() {
    Stack stack;
    create_stack(&stack);

    int choice, value;

    do {
        // Display the menu
        printf("\nSelect your option from below: \n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push operation
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                display(&stack);
                break;
            case 2:
                // Pop operation
                value = pop(&stack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                display(&stack);
                break;
            case 3:
                // Peek operation
                value = peek(&stack);
                if (value != -1)
                    printf("Top element: %d\n", value);
                display(&stack);
                break;
            case 4:
                // Check if stack is empty
                if (isEmpty(&stack))
                    printf("Yes, stack is empty\n");
                else
                    printf("Stack is NOT empty\n");
                break;
            case 5:
                // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
