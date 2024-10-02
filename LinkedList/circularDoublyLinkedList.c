#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_Node();
void display_Node(Node* tail);
Node* insert_atend(Node* tail);
Node* insert_atbegin(Node* tail);
Node* insert_atany(Node* tail, int x);
Node* delete_atbegin(Node* tail);
Node* delete_atend(Node* tail);
Node* delete_atany(Node* tail, int x);

int main() {
    int opt, opr, x, run = 1;
    Node* tail = create_Node();
    printf("Doubly Circular Linked-list initialized: ");
    display_Node(tail);
    
    while (run) {
        printf("Select your option from below (0 to exit)\n\n1-Insert\n2-Delete\n\n--->");
        scanf("%d", &opt);
        
        switch (opt) {
        case 1:
            printf("Select your operation from below\n\n1-Insert at beginning\n2-Insert at end\n3-Insert at any position\n\n--->");
            scanf("%d", &opr);
            
            switch (opr) {
            case 1:
                tail = insert_atbegin(tail);
                display_Node(tail);
                break;
            case 2:
                tail = insert_atend(tail);
                display_Node(tail);
                break;
            case 3:
                printf("Enter the position where you want your element to be inserted: ");
                scanf("%d", &x);
                tail = insert_atany(tail, x);
                display_Node(tail);
                break;
            default:
                printf("Invalid option");
                break;
            }
            break;
        
        case 2:
            printf("Select your operation from below\n\n1-Delete at beginning\n2-Delete at end\n3-Delete at any position\n\n--->");
            scanf("%d", &opr);
            
            switch (opr) {
            case 1:
                tail = delete_atbegin(tail);
                display_Node(tail);
                break;
            case 2:
                tail = delete_atend(tail);
                display_Node(tail);
                break;
            case 3:
                printf("Enter the position which you want to be deleted: ");
                scanf("%d", &x);
                tail = delete_atany(tail, x);
                display_Node(tail);
                break;
            default:
                printf("Invalid option");
                break;
            }
            break;
        
        case 0:
            run = 0;
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}

Node* create_Node() {
    Node* new = (Node*)malloc(sizeof(Node));
    printf("Enter an integer: ");
    scanf("%d", &new->data);
    new->next = new;
    new->prev = new;
    return new;
}

Node* insert_atend(Node* tail) {
    Node* temp = create_Node();
    if (tail == NULL) {
        return temp;
    }
    temp->next = tail->next;
    temp->prev = tail;
    tail->next->prev = temp;
    tail->next = temp;
    return temp;
}

Node* insert_atbegin(Node* tail) {
    Node* new = create_Node();
    if (tail == NULL) {
        return new;
    }
    new->next = tail->next;
    new->prev = tail;
    tail->next->prev = new;
    tail->next = new;
    return tail;
}

Node* insert_atany(Node* tail, int x) {
    Node* new, *curr;
    int i;

    if (x < 0) {
        printf("Position cannot be negative\n");
        return tail;
    }

    if (tail == NULL && x == 0) {
        return create_Node();
    }

    curr = tail->next;
    if (x == 0) {
        tail = insert_atbegin(tail);
        return tail;
    }

    for (i = 0; i < x - 1; i++) {
        curr = curr->next;
        if (curr == tail->next) {
            printf("Position not found\n");
            return tail;
        }
    }

    new = create_Node();
    new->next = curr->next;
    new->prev = curr;
    curr->next->prev = new;
    curr->next = new;

    if (curr == tail) {
        tail = new;
    }

    return tail;
}

Node* delete_atbegin(Node* tail) {
    if (tail == NULL) {
        printf("Cannot delete, list is empty\n");
        return NULL;
    }

    Node* head = tail->next;
    if (head == tail) {
        free(head);
        return NULL;
    }

    tail->next = head->next;
    head->next->prev = tail;
    free(head);

    return tail;
}

Node* delete_atend(Node* tail) {
    if (tail == NULL) {
        printf("Cannot delete, list is empty\n");
        return NULL;
    }

    Node* head = tail->next;
    if (tail == head) {
        free(tail);
        return NULL;
    }

    tail->prev->next = head;
    head->prev = tail->prev;
    free(tail);

    return head->prev;
}

Node* delete_atany(Node* tail, int x) {
    Node* curr;
    int i;

    if (tail == NULL) {
        printf("Cannot delete, list is empty\n");
        return NULL;
    }

    curr = tail->next;

    if (x < 0) {
        printf("Position cannot be negative\n");
        return tail;
    }

    if (x == 0) {
        return delete_atbegin(tail);
    }

    for (i = 0; i < x; i++) {
        curr = curr->next;
        if (curr == tail->next) {
            printf("Position not found\n");
            return tail;
        }
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    if (curr == tail) {
        tail = curr->prev;
    }

    free(curr);
    return tail;
}

void display_Node(Node* tail) {
    if (tail == NULL) {
        printf("Empty List\n");
        return;
    }
    Node* head = tail->next;
    do {
        printf("%d->", head->data);
        head = head->next;
    } while (head != tail->next);
    printf("\n");
}