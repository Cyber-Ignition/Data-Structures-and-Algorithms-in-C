#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
} Node;

Node * create_Node();
void display_Node(Node * head);
Node* insert_atend(Node* head);
Node* insert_atbegin(Node* head);
Node* insert_atany(Node* head, int x);
Node* delete_atbegin(Node* head);
Node* delete_atend(Node* head);
Node* delete_atany(Node* head, int x);

int main() {
    int opt, opr, x, run = 1;
    Node * head = create_Node();
    printf("Linked-list initialized: ");
    display_Node(head);
    while (run){
        printf("Select your option from below(0 to exit)\n\n1-Insert\n2-Delete\n\n--->");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Select your operation from below\n\n1-Insert at beginning\n2-Insert at end\n3-Insert at any position\n\n--->");
            scanf("%d", &opr);
            switch (opr)
            {
            case 1:
                head = insert_atbegin(head);
                display_Node(head);
                break;
            case 2:
                head = insert_atend(head);
                display_Node(head);
                break;
            case 3:
                printf("Enter the position where you want your element to be inserted: ");
                scanf("%d", &x);
                head = insert_atany(head, x);
                display_Node(head);
                break;
            
            default:
                printf("Invalid option");
                break;
            }
            break;
        case 2:
            printf("Select your operation from below\n\n1-Delete at beginning\n2-Delete at end\n3-Delete at any position\n\n-->");
            scanf("%d", &opr);
            switch (opr)
            {
            case 1:
                head = delete_atbegin(head);
                display_Node(head);
                break;
            case 2:
                head = delete_atend(head);
                display_Node(head);
                break;
            case 3:
                printf("Enter the position which you want to be deleted: ");
                scanf("%d", &x);
                head = delete_atany(head, x);
                display_Node(head);
                break;
            default:
                printf("Invalid option");
                break;
            }
        default:
            break;
        case 0:
            run = 0;
            break;
        }
    }
    return 0;
}

Node* create_Node(){
    Node * head;
    head = (Node*)malloc(sizeof(Node*));
    printf("Enter an integer: ");
    scanf("%d", &head->data);
    head -> link = head;
    return head;
}

Node* insert_atend(Node* tail){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node*));
    printf("Enter an integer: ");
    scanf("%d", &temp->data);
    if (tail == NULL)
    {
        tail = temp;
        temp->link = temp;
    }
    else
    {
        temp->link = tail->link;
        tail->link = temp;
        tail = temp;
    }
    return tail;
}

Node* insert_atbegin(Node* tail){
    Node * new = (Node*)malloc(sizeof(Node*));
    printf("Enter an integer: ");
    scanf("%d", &new->data);
    if (tail == NULL)
    {
        new->link = new;
        return new;
    }
    new->link = tail->link;
    tail->link = new;
    return tail;
}

Node* insert_atany(Node* tail, int x){
    int i;
    Node *temp, *curr;
    if (tail == NULL)
    {
        if (x != 0)
        {
            printf("Position not found\n");
            return tail;
        }
        Node* new = create_Node();
        tail = new;
        tail->link = tail;
        return tail;
    }

    if (x < 0)
    {
        printf("Position cannot be negative");
        return tail;
    }

    temp = (Node*)malloc(sizeof(Node*));
    curr = tail->link;
    if (x == 0)
    {
        printf("Enter an integer: ");
        scanf("%d", &temp->data);
        temp->link = curr;
        tail->link = temp;
        return tail;
    }

    for (i=0; i < x-1; i++)
    {
        curr = curr->link;
        if (curr == tail->link)
        {
            printf("Position not found\n");
            return tail;
        }
    }
    printf("Enter an integer: ");
    scanf("%d", &temp->data);
    temp->link = curr->link;
    curr->link = temp;

    if (curr == tail)
        tail = temp;
    return tail;
}

Node* delete_atbegin(Node* tail){
    Node *head;
    if (tail == NULL)
    {
        printf("Cannot delete, list is empty\n");
        return NULL;
    }
    head = tail->link;
    if (head == tail)
    {
        free(head);
        tail = NULL;
    }
    else
    {
        tail->link = head->link;
        free(head);
    }
    
    return tail;
}

Node* delete_atend(Node* tail){
    Node *head, *curr;
    if (tail == NULL)
    {
        printf("Cannot delete, list is empty\n");
        return NULL;
    }

    head = tail->link;
    if (head == tail)
    {
        free(head);
        tail = NULL;
        return tail;
    }
    curr = head;
    while (curr->link != tail)
        curr = curr->link; 
    curr->link = head;
    free(tail);
    tail = curr;

    return tail;
}

Node* delete_atany(Node* tail, int x){
    int i;
    Node *prev, *curr;
    if (tail == NULL)
    {
        printf("Cannot delete, list is empty\n");
        return NULL;
    }

    curr = tail->link;
    prev = tail;
    if (curr == tail)
    {
        if (x == 0)
        {
            free(curr);
            tail = NULL;
            return tail;
        }
        printf("Cannot delete, position not found\n");
        return tail;
    }

    if (x < 0)
    {
        printf("Position cannot be negative\n");
        return tail;
    }

    for (i=0; i < x; i++)
    {
        prev = curr;
        curr = curr->link;
        if (curr == tail->link)
        {
            printf("Cannot delete, position not found\n");
            return tail;
        }
    }
    prev->link = curr->link;
    if (curr == tail)
        tail = prev;
    free(curr);
    return tail;
}

void display_Node(Node* tail){
    if (tail == NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node *head = tail->link;
    while(1){
        printf("%d->", head->data);
        head = head -> link;
        if (head==tail->link)
            break;
    }
    printf("\n");
}
