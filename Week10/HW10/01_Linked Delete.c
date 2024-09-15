#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DataNode {
    char* data;
    struct DataNode* next;
}DataNode;
typedef struct SinglyLinkedList{
    unsigned int count;
    DataNode* head;
} SinglyLinkedList;
DataNode* createDataNode(char* data);
SinglyLinkedList* createSinglyLinkedList();
void traverse(SinglyLinkedList* list);
void insert_last(SinglyLinkedList* list, char* data);
void insert_front(SinglyLinkedList* list, char* data); // <-- สร้างตัวนี้
void delete(SinglyLinkedList* list, char* data); // <-- สร้างตัวนี้
int main() {
    SinglyLinkedList* mylist = createSinglyLinkedList();
    int n;
    char condition;
    char data[100]; // Assuming a maximum string length of 99 characters
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c: %[^\n]s", &condition, data); // Read condition and string data

        if (condition == 'F') {
            insert_front(mylist, data);
        } else if (condition == 'L') {
            insert_last(mylist, data);
        } else if (condition == 'D') {
            delete(mylist, data);
        } else {
            printf("Invalid Condition!\n");
        }
    }

    traverse(mylist);
    // Remember to free allocated memory for each node's data
    DataNode* current = mylist->head;
    while (current != NULL) {
        free(current->data);
        DataNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(mylist);
    return 0;
}
DataNode* createDataNode(char* data) {
    DataNode* newNode = (DataNode*) malloc(sizeof(DataNode));
    newNode->data = (char*) malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}
SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* output = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    output->count = 0;
    output->head = NULL;

    return output;
}
void traverse(SinglyLinkedList* list) {
    if (list->count == 0) {
        printf("This is an empty list.\n");
        return;
    }
    DataNode* pointer = list->head;
    while(pointer->next != NULL) {
        printf("%s -> ", pointer->data);
        pointer = pointer->next;
    }
    printf("%s\n", pointer->data);
}
void insert_last(SinglyLinkedList* list, char* data) {
    DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        list->head = pNew;
    } else {
        DataNode* findEnd = list->head;
        while (findEnd->next != NULL) {
            findEnd = findEnd->next;
        }
        findEnd->next = pNew;
    }
    list->count++;
}
void insert_front(SinglyLinkedList* list, char* data) {
    DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        list->head = pNew;
    } else {
        pNew->next = list->head;
        list->head = pNew;
    }
    list->count++;
}
void delete(struct SinglyLinkedList* list, char* data) {
    struct DataNode* current = list->head;
    struct DataNode* previous = NULL;
    if(list->count==0){
        printf("Cannot delete, %s does not exist.\n", data);
        free(current);
        return;
    }
    while (strcmp(current->data, data) != 0 && current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Cannot delete, %s does not exist.\n", data);
        return;
    }
    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current->data);
    free(current);
    list->count--;
}