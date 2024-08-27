#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
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
            printf("The reversed Linked-list is:");
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
    head -> next = NULL;
    head -> prev = NULL;
    return head;
}

Node* insert_atend(Node* head){
    Node *temp, *ptr;
    temp = create_Node();
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

Node* insert_atbegin(Node* head){
    Node * new = create_Node();
    new->next = head;
    if (head != NULL)
        head->prev = new;
    return new;
}

Node* insert_atany(Node* head, int x){
    int i;
    Node * ptr, *new;
    if (x == 0)
    {
        head = insert_atbegin(head);
        return head;
    }
    ptr = head;
    for (i = 0;  i < x-1 && ptr!=NULL; i++)
        ptr = ptr->next;
    if (ptr == NULL)
    {
        printf("Position not found\n");
        return head;
    }
    new = create_Node();
    new->prev = ptr;
    new->next = ptr->next;
    ptr->next = new;
    if (new->next != NULL)
        new->next->prev = new;
    return head;
}

Node* delete_atbegin(Node* head){
    Node* ptr = head;
    if (head == NULL){
        printf("Cannot delete, list is empty\n");
        return NULL;
    }
    if (head->next == NULL){
        printf("List is empty\n");
        return NULL;
    }
    head = head->next;
    head->prev = NULL;
    free(ptr);  
    return head;
}

Node* delete_atend(Node* head){
    Node* ptr = head;
    if (head == NULL){
        printf("Cannot delete, list is empty\n");
        return NULL;
    }
    if (head->next == NULL){
        printf("List is empty\n");
        return NULL;
    }
    while (ptr->next->next != NULL)
        ptr = ptr->next; 
    ptr->next->prev = NULL;
    free(ptr->next);
    ptr->next = NULL;  
    return head;
}

Node* delete_atany(Node* head, int x){
    int i;
    Node* ptr = head;
    if (head == NULL){
        printf("Cannot delete, list is empty\n");
        return NULL;
    }
    if (head->next == NULL){
        printf("List is empty\n");
        return NULL;
    }
    if (x == 0)
    {
        head = delete_atbegin(head);
        return head;
    }
    for (i=0; i < x; i++)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("Position not found\n");
            return head;
        }
    }
    if (ptr->prev)
        ptr->prev->next = ptr->next;
    if (ptr->next)
        ptr->next->prev = ptr->prev;
    if (head == ptr)
        head = ptr->next;
    free(ptr);
    return head;
}

Node* reverse_Node(Node* head){
    Node* temp;
    if (head == NULL)
        return NULL;
    temp = head->prev;
    head->prev = head->next;
    head->next = temp;

    if (head -> prev == NULL)
        return head;
    return reverse_Node(head->prev);
}

void search(Node* head, int x) {
    Node* ptr = head;
    int found = 0, idx = 0;
    while (!found && ptr != NULL)
    {   
        if (ptr->data == x)
        {
            found = 1;
            break;
        }
        idx++;
        ptr = ptr->next;
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
    while (ptr->next!=NULL)
    {   
        idx++;
        ptr = ptr->next;
    }
    return idx;
}

void display_Node(Node* head){
    while(head != NULL){
        printf("%d->", head->data);
        head = head -> next;
    }
    printf("NULL\n");
}
