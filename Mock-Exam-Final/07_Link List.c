#include "stdio.h"
#include "stdlib.h"
 
typedef struct Node {
    int data;
    struct Node* next; // pointer to the next node
}Node;
 
void insert(Node** head, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;
 
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head; //ให้ไปโหนดท้าย
    while (last->next != NULL) {
        last = last->next; // traverse 
    }
    last->next = newNode; 
}
 
void insertAt(Node** head, int newData, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
 
    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* current = *head;
    for (int i = 0; i < pos - 1; i++) {
        if (current == NULL) {
            free(newNode);
            return;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
 
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
int main() {
    Node* head = NULL;
    int num;
    scanf("%d", &num);
    int list[num];
    int select, info;
    for (int i = 0; i < num; i++){
        scanf("%d", &list[i]);
        insert(&head, list[i]);
    }
    scanf("%d %d", &select, &info);
    insertAt(&head, info, select);
    printList(head);
    return 0;
}