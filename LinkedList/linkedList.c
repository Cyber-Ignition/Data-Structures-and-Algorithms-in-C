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
Node* reverse_Node(Node* head);
void search(Node* head, int x);
int count(Node* head);

int main() {
    int opt, opr, x, run = 1;
    Node * head = create_Node();
    printf("Linked-list initialized: ");
    display_Node(head);
    while (run){
        printf("Select your option from below\n\n1-Insert\n2-Delete\n3-Search\n4-Count\n5-Reverse\n\n--->");
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
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &x);
            search(head, x);
            break;
        case 4:
            x = count(head);
            printf("The count of total number of elements is %d\n", x);
            break;
        case 5:
            head = reverse_Node(head);
            printf("The reversed linked-list is:");
            display_Node(head);
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
    head -> link = NULL;
    return head;
}

Node* insert_atend(Node* head){
    Node *temp, *ptr;
    ptr = head;
    while(ptr->link != NULL)
        ptr = ptr->link;
    temp = (Node*)malloc(sizeof(Node*));
    printf("Enter an integer: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    ptr->link = temp;
    return head;
}

Node* insert_atbegin(Node* head){
    Node * new = (Node*)malloc(sizeof(Node*));
    printf("Enter an integer: ");
    scanf("%d", &new->data);
    new->link = head;
    return new;
}

Node* insert_atany(Node* head, int x){
    Node * ptr, *new;
    if (x == 0)
    {
        head = insert_atbegin(head);
        return head;
    }
    int idx = 1;
    ptr = head;
    while (idx != x && ptr->link != NULL)
    {
        idx++;
        ptr = ptr->link;
    }
    if (idx != x)
    {
        printf("Index not found.\n");
        return head;
    }
    new = (Node*)malloc(sizeof(Node*));
    printf("Enter an integer: ");
    scanf("%d", &new->data);
    new->link = ptr->link;
    ptr->link = new;
    return head;
}

Node* delete_atbegin(Node* head){
    Node* ptr = head;
    if (ptr->link == NULL){
        printf("Underflow");
        return NULL;
    }
    ptr ->data = ptr->link->data;
    ptr->link = ptr->link->link;       
    return head;
}

Node* delete_atend(Node* head){
    Node* ptr = head;
    if (ptr->link == NULL){
        printf("Underflow");
        return NULL;
    }
    while (ptr->link->link != NULL)
        ptr = ptr->link; 
    ptr->link = NULL;  
    return head;
}

Node* delete_atany(Node* head, int x){
    Node* ptr = head;
    if (ptr->link == NULL){
        printf("Underflow");
        return NULL;
    }
    if (x == 0)
    {
        head = delete_atbegin(head);
        return head;
    }
    int idx = 0;
    while (idx != x && ptr->link!=NULL)
    {
        idx++;
        ptr = ptr->link;
    }
    if (idx != x)
    {
        printf("Index not found\n");
        return head;
    }
    if (ptr->link == NULL)
    {
        head = delete_atend(head);
        return head;
    }
    ptr->data = ptr->link->data;
    ptr->link = ptr->link->link;
    return head;
}

Node* reverse_Node(Node* head){
    Node* curr = head, *prev = NULL, *next;
    while (curr!=NULL)
    {
        next = curr->link;
        curr -> link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void search(Node* head, int x) {
    Node* ptr = head;
    int found = 0, idx = 0;
    while (!found && ptr->link != NULL)
    {   
        if (ptr->data == x)
        {
            found = 1;
            break;
        }
        idx++;
        ptr = ptr->link;
    }
    if (!found)
    {
        printf("Element was not found\n");
        return;
    }
    printf("Element was found at index %d\n", idx);
}

int count(Node* head){
    Node* ptr = head;
    int idx = 1;
    while (ptr->link!=NULL)
    {   
        idx++;
        ptr = ptr->link;
    }
    return idx;
}

void display_Node(Node* head){
    while(head != NULL){
        printf("%d->", head->data);
        head = head -> link;
    }
    printf("NULL\n");
}
